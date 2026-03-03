#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/Allocator.h>
#include <stdint.h>
#include <std/ArenaAllocation.h>
#include <stdbool.h>

#include <std/ArenaBlock.h>

#line 26 "src/std/ArenaAllocator.pv"
struct ArenaBlock* ArenaBlock__new(struct Allocator allocator, uintptr_t capacity, struct ArenaBlock* prev) {
    #line 27 "src/std/ArenaAllocator.pv"
    uint8_t* buffer = allocator.vtable->alloc(allocator.instance, capacity);
    #line 28 "src/std/ArenaAllocator.pv"
    if (buffer == 0) {
        #line 29 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaBlock::new: failed to allocate capacity %zu\n", capacity);
        #line 30 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 33 "src/std/ArenaAllocator.pv"
    struct ArenaBlock self = (struct ArenaBlock) { .buffer = buffer, .capacity = capacity, .prev = prev };
    #line 34 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* self_ptr = ArenaBlock__alloc(&self, sizeof(struct ArenaBlock));
    #line 35 "src/std/ArenaAllocator.pv"
    *self_ptr = self;

    #line 37 "src/std/ArenaAllocator.pv"
    return self_ptr;
}

#line 40 "src/std/ArenaAllocator.pv"
void* ArenaBlock__alloc(struct ArenaBlock* self, uintptr_t size) {
    #line 41 "src/std/ArenaAllocator.pv"
    uintptr_t header_size = sizeof(struct ArenaAllocation);

    #line 43 "src/std/ArenaAllocator.pv"
    uintptr_t total_size = header_size + size;

    #line 45 "src/std/ArenaAllocator.pv"
    if (self->offset + total_size > self->capacity) {
        #line 46 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 49 "src/std/ArenaAllocator.pv"
    void* header_ptr = self->buffer + self->offset;
    #line 50 "src/std/ArenaAllocator.pv"
    void* data_ptr = self->buffer + self->offset + header_size;

    #line 52 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = header_ptr;
    #line 53 "src/std/ArenaAllocator.pv"
    header->size = size;
    #line 54 "src/std/ArenaAllocator.pv"
    self->offset += total_size;

    #line 56 "src/std/ArenaAllocator.pv"
    return data_ptr;
}

#line 59 "src/std/ArenaAllocator.pv"
bool ArenaBlock__is_in_block(struct ArenaBlock* self, void* ptr) {
    #line 60 "src/std/ArenaAllocator.pv"
    void* buffer_start = self->buffer;
    #line 61 "src/std/ArenaAllocator.pv"
    void* buffer_end = self->buffer + self->capacity;
    #line 62 "src/std/ArenaAllocator.pv"
    return buffer_start < ptr && ptr < buffer_end;
}

#line 65 "src/std/ArenaAllocator.pv"
uintptr_t ArenaBlock__size(struct ArenaBlock* self, void* ptr) {
    #line 66 "src/std/ArenaAllocator.pv"
    if (!ArenaBlock__is_in_block(self, ptr)) {
        #line 66 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 68 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 69 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 71 "src/std/ArenaAllocator.pv"
    return header->size;
}

#line 74 "src/std/ArenaAllocator.pv"
bool ArenaBlock__free(struct ArenaBlock* self, void* ptr) {
    #line 75 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 75 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 77 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 78 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 80 "src/std/ArenaAllocator.pv"
    uint8_t* data = ptr;

    #line 82 "src/std/ArenaAllocator.pv"
    if (data + header->size == self->buffer + self->offset) {
        #line 83 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = sizeof(struct ArenaAllocation) + header->size;
        #line 84 "src/std/ArenaAllocator.pv"
        self->offset -= total_size;
        #line 85 "src/std/ArenaAllocator.pv"
        memset(header, 0, total_size);
        #line 86 "src/std/ArenaAllocator.pv"
        return 1;
    }

    #line 89 "src/std/ArenaAllocator.pv"
    return 0;
}

#line 92 "src/std/ArenaAllocator.pv"
void ArenaBlock__destroy(struct ArenaBlock* self, struct Allocator allocator) {
    #line 93 "src/std/ArenaAllocator.pv"
    allocator.vtable->free(allocator.instance, self->buffer);
}

#line 96 "src/std/ArenaAllocator.pv"
void* ArenaBlock__realloc(struct ArenaBlock* self, void* ptr, uintptr_t size) {
    #line 97 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 98 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 100 "src/std/ArenaAllocator.pv"
    uint8_t* data = ptr;

    #line 102 "src/std/ArenaAllocator.pv"
    if (size <= header->size) {
        #line 103 "src/std/ArenaAllocator.pv"
        memset(data + size, 0, header->size - size);
        #line 104 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 105 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 108 "src/std/ArenaAllocator.pv"
    if (data + header->size == self->buffer + self->offset) {
        #line 109 "src/std/ArenaAllocator.pv"
        if (self->offset - header->size + size > self->capacity) {
            #line 111 "src/std/ArenaAllocator.pv"
            return 0;
        }

        #line 114 "src/std/ArenaAllocator.pv"
        self->offset = self->offset - header->size + size;
        #line 115 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 116 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 119 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaBlock__alloc(self, size);
    #line 120 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 122 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 125 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, header->size);
    #line 126 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(self, ptr);

    #line 128 "src/std/ArenaAllocator.pv"
    return new_ptr;
}
