#include <stdlib.h>
#include <string.h>

#include <std/Allocator.h>
#include <stdint.h>
#include <slice_InvokeArgument.h>
#include <analyzer/InvokeArgument.h>
#include <stdbool.h>
#include <std/ArrayIter_ref_InvokeArgument.h>

#include <std/Array_InvokeArgument.h>

#line 77 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new(struct Allocator allocator) {
    #line 78 "src/std/Array.pv"
    return (struct Array_InvokeArgument) { .allocator = allocator };
}

#line 81 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new_with_length(struct Allocator allocator, uintptr_t length) {
    #line 82 "src/std/Array.pv"
    struct Array_InvokeArgument self = (struct Array_InvokeArgument) { .allocator = allocator };
    #line 83 "src/std/Array.pv"
    Array_InvokeArgument__reserve(&self, length);
    #line 84 "src/std/Array.pv"
    self.length = length;
    #line 85 "src/std/Array.pv"
    return self;
}

#line 88 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__new_with_capacity(struct Allocator allocator, uintptr_t length) {
    #line 89 "src/std/Array.pv"
    struct Array_InvokeArgument self = (struct Array_InvokeArgument) { .allocator = allocator };
    #line 90 "src/std/Array.pv"
    Array_InvokeArgument__reserve(&self, length);
    #line 91 "src/std/Array.pv"
    return self;
}

#line 94 "src/std/Array.pv"
void Array_InvokeArgument__reserve(struct Array_InvokeArgument* self, uintptr_t capacity) {
    #line 95 "src/std/Array.pv"
    if (self->capacity > capacity) {
        #line 96 "src/std/Array.pv"
        return;
    }

    #line 99 "src/std/Array.pv"
    self->data = self->allocator.vtable->realloc(self->allocator.instance, self->data, capacity * sizeof(struct InvokeArgument));
    #line 100 "src/std/Array.pv"
    self->capacity = capacity;
}

#line 103 "src/std/Array.pv"
struct InvokeArgument* Array_InvokeArgument__get(struct Array_InvokeArgument* self, uintptr_t index) {
    #line 104 "src/std/Array.pv"
    if (index >= self->length) {
        #line 104 "src/std/Array.pv"
        return 0;
    }
    #line 105 "src/std/Array.pv"
    return self->data + index;
}

#line 108 "src/std/Array.pv"
uintptr_t Array_InvokeArgument__append(struct Array_InvokeArgument* self, struct InvokeArgument value) {
    #line 109 "src/std/Array.pv"
    if (self->capacity <= self->length + 1) {
        #line 110 "src/std/Array.pv"
        uintptr_t additional_capacity = self->capacity;

        #line 112 "src/std/Array.pv"
        if (additional_capacity < 5) {
            #line 113 "src/std/Array.pv"
            additional_capacity = 5;
        }

        #line 116 "src/std/Array.pv"
        Array_InvokeArgument__reserve(self, self->capacity + additional_capacity);
    }

    #line 119 "src/std/Array.pv"
    self->data[self->length] = value;
    #line 120 "src/std/Array.pv"
    self->length += 1;

    #line 122 "src/std/Array.pv"
    return self->length - 1;
}

#line 125 "src/std/Array.pv"
uintptr_t Array_InvokeArgument__prepend(struct Array_InvokeArgument* self, struct InvokeArgument value) {
    #line 126 "src/std/Array.pv"
    if (self->capacity <= self->length + 1) {
        #line 127 "src/std/Array.pv"
        uintptr_t additional_capacity = self->capacity;

        #line 129 "src/std/Array.pv"
        if (additional_capacity < 5) {
            #line 130 "src/std/Array.pv"
            additional_capacity = 5;
        }

        #line 133 "src/std/Array.pv"
        Array_InvokeArgument__reserve(self, self->capacity + additional_capacity);
    }

    #line 136 "src/std/Array.pv"
    memmove(self->data + 1, self->data, self->length * sizeof(struct InvokeArgument));
    #line 137 "src/std/Array.pv"
    self->data[0] = value;
    #line 138 "src/std/Array.pv"
    self->length += 1;

    #line 140 "src/std/Array.pv"
    return 0;
}

#line 143 "src/std/Array.pv"
bool Array_InvokeArgument__remove_back(struct Array_InvokeArgument* self) {
    #line 144 "src/std/Array.pv"
    if (self->length == 0) {
        #line 145 "src/std/Array.pv"
        return false;
    }

    #line 148 "src/std/Array.pv"
    self->length -= 1;
    #line 149 "src/std/Array.pv"
    memset(self->data + self->length, 0, sizeof(struct InvokeArgument));

    #line 151 "src/std/Array.pv"
    return true;
}

#line 154 "src/std/Array.pv"
struct InvokeArgument* Array_InvokeArgument__back(struct Array_InvokeArgument* self) {
    #line 155 "src/std/Array.pv"
    if (self->length == 0) {
        #line 155 "src/std/Array.pv"
        return 0;
    }

    #line 157 "src/std/Array.pv"
    return &self->data[self->length - 1];
}

#line 160 "src/std/Array.pv"
void Array_InvokeArgument__clear(struct Array_InvokeArgument* self) {
    #line 161 "src/std/Array.pv"
    memset(self->data, 0, self->length * sizeof(struct InvokeArgument));
    #line 162 "src/std/Array.pv"
    self->length = 0;
}

#line 165 "src/std/Array.pv"
void Array_InvokeArgument__release(struct Array_InvokeArgument* self) {
    #line 166 "src/std/Array.pv"
    self->allocator.vtable->free(self->allocator.instance, self->data);
    #line 167 "src/std/Array.pv"
    self->data = 0;
    #line 168 "src/std/Array.pv"
    self->length = 0;
    #line 169 "src/std/Array.pv"
    self->capacity = 0;
}

#line 172 "src/std/Array.pv"
struct Array_InvokeArgument Array_InvokeArgument__clone(struct Array_InvokeArgument* self, struct Allocator allocator) {
    #line 173 "src/std/Array.pv"
    struct InvokeArgument* data = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(struct InvokeArgument));
    #line 174 "src/std/Array.pv"
    memcpy(data, self->data, self->length * sizeof(struct InvokeArgument));

    #line 176 "src/std/Array.pv"
    return (struct Array_InvokeArgument) {
        .allocator = allocator,
        .data = data,
        .length = self->length,
        .capacity = self->capacity,
    };
}

#line 184 "src/std/Array.pv"
struct ArrayIter_ref_InvokeArgument Array_InvokeArgument__iter(struct Array_InvokeArgument* self) {
    #line 186 "src/std/Array.pv"
    return ArrayIter_ref_InvokeArgument__new((void*)(self->data), (void*)(self->data + self->length));
}

#line 189 "src/std/Array.pv"
struct slice_InvokeArgument Array_InvokeArgument__as_slice(struct Array_InvokeArgument* self) {
    #line 190 "src/std/Array.pv"
    return (struct slice_InvokeArgument) { .data = self->data + 0, .length = self->length - 0 };
}
