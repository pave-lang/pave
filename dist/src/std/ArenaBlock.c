#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <std/trait_Allocator.h>
#include <std/ArenaBlock.h>
#include <std/ArenaAllocation.h>
#include <std/ArenaAllocator.h>
#include <usize.h>
#include <std/ArenaBlock.h>

#include <std/ArenaBlock.h>

#line 27 "src/std/ArenaAllocator.pv"
struct ArenaBlock* ArenaBlock__new(struct trait_Allocator allocator, uintptr_t capacity, struct ArenaBlock* prev) {
    #line 28 "src/std/ArenaAllocator.pv"
    uint8_t* buffer = allocator.vtable->fn_alloc(allocator.instance, capacity);
    #line 29 "src/std/ArenaAllocator.pv"
    if (buffer == 0) {
        #line 30 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaBlock::new: failed to allocate capacity %zu\n", capacity);
        #line 31 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 34 "src/std/ArenaAllocator.pv"
    struct ArenaBlock self = (struct ArenaBlock) { .buffer = buffer, .capacity = capacity, .prev = prev, .offset = 0 };
    #line 35 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* self_ptr = ArenaBlock__alloc(&self, sizeof(struct ArenaBlock));
    #line 36 "src/std/ArenaAllocator.pv"
    *self_ptr = self;

    #line 38 "src/std/ArenaAllocator.pv"
    return self_ptr;
}

#line 41 "src/std/ArenaAllocator.pv"
void* ArenaBlock__alloc(struct ArenaBlock* self, uintptr_t size) {
    #line 42 "src/std/ArenaAllocator.pv"
    uintptr_t header_size = sizeof(struct ArenaAllocation);
    #line 43 "src/std/ArenaAllocator.pv"
    uintptr_t alignment = ArenaAllocator__alignment();
    #line 44 "src/std/ArenaAllocator.pv"
    uintptr_t data_offset = ArenaAllocator__align_up(self->offset + header_size, alignment);
    #line 45 "src/std/ArenaAllocator.pv"
    uintptr_t next_offset = ArenaAllocator__align_up(data_offset + size, alignment);

    #line 47 "src/std/ArenaAllocator.pv"
    if (next_offset > self->capacity) {
        #line 48 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 51 "src/std/ArenaAllocator.pv"
    void* header_ptr = self->buffer + data_offset - header_size;
    #line 52 "src/std/ArenaAllocator.pv"
    void* data_ptr = self->buffer + data_offset;

    #line 54 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = header_ptr;
    #line 55 "src/std/ArenaAllocator.pv"
    header->size = size;
    #line 56 "src/std/ArenaAllocator.pv"
    header->start_offset = self->offset;
    #line 57 "src/std/ArenaAllocator.pv"
    header->end_offset = next_offset;
    #line 58 "src/std/ArenaAllocator.pv"
    self->offset = next_offset;

    #line 60 "src/std/ArenaAllocator.pv"
    return data_ptr;
}

#line 63 "src/std/ArenaAllocator.pv"
bool ArenaBlock__is_in_block(struct ArenaBlock* self, void* ptr) {
    #line 64 "src/std/ArenaAllocator.pv"
    void* buffer_start = self->buffer;
    #line 65 "src/std/ArenaAllocator.pv"
    void* buffer_end = self->buffer + self->capacity;
    #line 66 "src/std/ArenaAllocator.pv"
    return buffer_start < ptr && ptr < buffer_end;
}

#line 69 "src/std/ArenaAllocator.pv"
uintptr_t ArenaBlock__size(struct ArenaBlock* self, void* ptr) {
    #line 70 "src/std/ArenaAllocator.pv"
    if (!ArenaBlock__is_in_block(self, ptr)) {
        #line 70 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 72 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 73 "src/std/ArenaAllocator.pv"
    header -= 1;
    #line 74 "src/std/ArenaAllocator.pv"
    if (header == 0) {
        #line 74 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 76 "src/std/ArenaAllocator.pv"
    return header->size;
}

#line 79 "src/std/ArenaAllocator.pv"
bool ArenaBlock__free(struct ArenaBlock* self, void* ptr) {
    #line 80 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 80 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 82 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 83 "src/std/ArenaAllocator.pv"
    header -= 1;
    #line 84 "src/std/ArenaAllocator.pv"
    if (header == 0) {
        #line 84 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 86 "src/std/ArenaAllocator.pv"
    if (usize__Eq_usize__eq(header->end_offset, self->offset)) {
        #line 87 "src/std/ArenaAllocator.pv"
        uintptr_t old_offset = self->offset;
        #line 88 "src/std/ArenaAllocator.pv"
        self->offset = header->start_offset;
        #line 89 "src/std/ArenaAllocator.pv"
        memset(self->buffer + self->offset, 0, old_offset - self->offset);
        #line 90 "src/std/ArenaAllocator.pv"
        return true;
    }

    #line 93 "src/std/ArenaAllocator.pv"
    return false;
}

#line 96 "src/std/ArenaAllocator.pv"
void ArenaBlock__destroy(struct ArenaBlock* self, struct trait_Allocator allocator) {
    #line 97 "src/std/ArenaAllocator.pv"
    allocator.vtable->fn_free(allocator.instance, self->buffer);
}

#line 100 "src/std/ArenaAllocator.pv"
void* ArenaBlock__realloc(struct ArenaBlock* self, void* ptr, uintptr_t size) {
    #line 101 "src/std/ArenaAllocator.pv"
    struct ArenaAllocation* header = ptr;
    #line 102 "src/std/ArenaAllocator.pv"
    header -= 1;
    #line 103 "src/std/ArenaAllocator.pv"
    if (header == 0) {
        #line 103 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 105 "src/std/ArenaAllocator.pv"
    uint8_t* data = ptr;

    #line 107 "src/std/ArenaAllocator.pv"
    if (size <= header->size) {
        #line 108 "src/std/ArenaAllocator.pv"
        memset(data + size, 0, header->size - size);
        #line 109 "src/std/ArenaAllocator.pv"
        if (usize__Eq_usize__eq(header->end_offset, self->offset)) {
            #line 110 "src/std/ArenaAllocator.pv"
            self->offset = ArenaAllocator__align_up(data - self->buffer + size, ArenaAllocator__alignment());
            #line 111 "src/std/ArenaAllocator.pv"
            header->end_offset = self->offset;
        }
        #line 113 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 114 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 117 "src/std/ArenaAllocator.pv"
    if (usize__Eq_usize__eq(header->end_offset, self->offset)) {
        #line 118 "src/std/ArenaAllocator.pv"
        uintptr_t next_offset = ArenaAllocator__align_up(data - self->buffer + size, ArenaAllocator__alignment());
        #line 119 "src/std/ArenaAllocator.pv"
        if (next_offset > self->capacity) {
            #line 121 "src/std/ArenaAllocator.pv"
            return 0;
        }

        #line 124 "src/std/ArenaAllocator.pv"
        self->offset = next_offset;
        #line 125 "src/std/ArenaAllocator.pv"
        header->size = size;
        #line 126 "src/std/ArenaAllocator.pv"
        header->end_offset = next_offset;
        #line 127 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 130 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaBlock__alloc(self, size);
    #line 131 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 133 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 136 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, header->size);
    #line 137 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(self, ptr);

    #line 139 "src/std/ArenaAllocator.pv"
    return new_ptr;
}
