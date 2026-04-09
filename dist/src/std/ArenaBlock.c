#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <std/ArenaAllocation.h>
#include <stdbool.h>

#include <std/ArenaBlock.h>

#line 25 "src/std/ArenaAllocator.pv"
struct ArenaBlock* ArenaBlock__new(struct trait_Allocator allocator, uintptr_t capacity, struct ArenaBlock* prev) {
    #line 26 "src/std/ArenaAllocator.pv"
    uint8_t* buffer = allocator.vtable->alloc(allocator.instance, capacity);
    #line 27 "src/std/ArenaAllocator.pv"
    if (buffer == 0) {
        #line 28 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaBlock::new: failed to allocate capacity %zu\n", capacity);
        #line 29 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 32 "src/std/ArenaAllocator.pv"
    struct ArenaBlock self = (struct ArenaBlock) { .buffer = buffer, .capacity = capacity, .prev = prev };
    #line 33 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* self_ptr = ArenaBlock__alloc(&self, sizeof(struct ArenaBlock));
    #line 34 "src/std/ArenaAllocator.pv"
    *self_ptr = self;

    #line 36 "src/std/ArenaAllocator.pv"
    return self_ptr;
}

#line 39 "src/std/ArenaAllocator.pv"
void* ArenaBlock__alloc(struct ArenaBlock* self, uintptr_t size) {
    #line 40 "src/std/ArenaAllocator.pv"
    uintptr_t header_size = sizeof(struct ArenaAllocation);

    #line 42 "src/std/ArenaAllocator.pv"
    uintptr_t total_size = header_size + size;

    #line 44 "src/std/ArenaAllocator.pv"
    if (self->offset + total_size > self->capacity) {
        #line 45 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 48 "src/std/ArenaAllocator.pv"
    void* header_ptr = self->buffer + self->offset;
    #line 49 "src/std/ArenaAllocator.pv"
    void* data_ptr = self->buffer + self->offset + header_size;

    #line 51 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = header_ptr;
    #line 52 "src/std/ArenaAllocator.pv"
    header->size = size;
    #line 53 "src/std/ArenaAllocator.pv"
    self->offset += total_size;

    #line 55 "src/std/ArenaAllocator.pv"
    return data_ptr;
}

#line 58 "src/std/ArenaAllocator.pv"
bool ArenaBlock__is_in_block(struct ArenaBlock* self, void* ptr) {
    #line 59 "src/std/ArenaAllocator.pv"
    void* buffer_start = self->buffer;
    #line 60 "src/std/ArenaAllocator.pv"
    void* buffer_end = self->buffer + self->capacity;
    #line 61 "src/std/ArenaAllocator.pv"
    return buffer_start < ptr && ptr < buffer_end;
}

#line 64 "src/std/ArenaAllocator.pv"
uintptr_t ArenaBlock__size(struct ArenaBlock* self, void* ptr) {
    #line 65 "src/std/ArenaAllocator.pv"
    if (!ArenaBlock__is_in_block(self, ptr)) {
        #line 65 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 67 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 68 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 70 "src/std/ArenaAllocator.pv"
    return header->size;
}

#line 73 "src/std/ArenaAllocator.pv"
bool ArenaBlock__free(struct ArenaBlock* self, void* ptr) {
    #line 74 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 74 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 76 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 77 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 79 "src/std/ArenaAllocator.pv"
    uint8_t* data = ptr;

    #line 81 "src/std/ArenaAllocator.pv"
    if (data + header->size == self->buffer + self->offset) {
        #line 82 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = sizeof(struct ArenaAllocation) + header->size;
        #line 83 "src/std/ArenaAllocator.pv"
        self->offset -= total_size;
        #line 84 "src/std/ArenaAllocator.pv"
        memset(header, 0, total_size);
        #line 85 "src/std/ArenaAllocator.pv"
        return true;
    }

    #line 88 "src/std/ArenaAllocator.pv"
    return false;
}

#line 91 "src/std/ArenaAllocator.pv"
void ArenaBlock__destroy(struct ArenaBlock* self, struct trait_Allocator allocator) {
    #line 92 "src/std/ArenaAllocator.pv"
    allocator.vtable->free(allocator.instance, self->buffer);
}

#line 95 "src/std/ArenaAllocator.pv"
void* ArenaBlock__realloc(struct ArenaBlock* self, void* ptr, uintptr_t size) {
    #line 96 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 97 "src/std/ArenaAllocator.pv"
    header -= 1;

    #line 99 "src/std/ArenaAllocator.pv"
    uint8_t* data = ptr;

    #line 101 "src/std/ArenaAllocator.pv"
    if (size <= header->size) {
        #line 102 "src/std/ArenaAllocator.pv"
        memset(data + size, 0, header->size - size);
        #line 103 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 104 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 107 "src/std/ArenaAllocator.pv"
    if (data + header->size == self->buffer + self->offset) {
        #line 108 "src/std/ArenaAllocator.pv"
        if (self->offset - header->size + size > self->capacity) {
            #line 110 "src/std/ArenaAllocator.pv"
            return 0;
        }

        #line 113 "src/std/ArenaAllocator.pv"
        self->offset = self->offset - header->size + size;
        #line 114 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 115 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 118 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaBlock__alloc(self, size);
    #line 119 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 121 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 124 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, header->size);
    #line 125 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(self, ptr);

    #line 127 "src/std/ArenaAllocator.pv"
    return new_ptr;
}
