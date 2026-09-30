#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <std/ArenaAllocator.h>
#include <std/HashSetBucket_str.h>
#include <usize.h>
#include <std/Hash.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <u64.h>
#include <std/HashSetIter_str.h>
#include <std/HashSet_str.h>

#include <std/HashSet_str.h>

#line 35 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator) {
    #line 36 "src/std/HashSet.pv"
    int32_t initial_capacity = 16;
    #line 37 "src/std/HashSet.pv"
    struct HashSet_str self = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 45 "src/std/HashSet.pv"
    HashSet_str__resize(&self, initial_capacity);

    #line 47 "src/std/HashSet.pv"
    return self;
}

#line 50 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity) {
    #line 51 "src/std/HashSet.pv"
    self->buckets = ArenaAllocator__Allocator__realloc(self->allocator, self->buckets, new_capacity * sizeof(self->data));
    #line 52 "src/std/HashSet.pv"
    self->data = ArenaAllocator__Allocator__realloc(self->allocator, self->data, new_capacity * sizeof(struct HashSetBucket_str));
    #line 53 "src/std/HashSet.pv"
    self->capacity = new_capacity;
    #line 54 "src/std/HashSet.pv"
    memset(self->buckets, 0, self->capacity * sizeof(self->data));

    #line 56 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(self);
}

#line 59 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value) {
    #line 60 "src/std/HashSet.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 60 "src/std/HashSet.pv"
        return false;
    }
    #line 61 "src/std/HashSet.pv"
    Hash hash = str__Hash__hash(&(*value));
    #line 62 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 63 "src/std/HashSet.pv"
    struct HashSetBucket_str* current_bucket_node = self->buckets[bucket_index];

    #line 65 "src/std/HashSet.pv"
    while (current_bucket_node != 0) {
        #line 66 "src/std/HashSet.pv"
        if (u64__Eq_u64__eq(str__Hash__hash(&current_bucket_node->value), hash)) {
            #line 67 "src/std/HashSet.pv"
            return true;
        }
        #line 69 "src/std/HashSet.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 72 "src/std/HashSet.pv"
    return false;
}

#line 75 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value) {
    #line 76 "src/std/HashSet.pv"
    if (HashSet_str__has(self, &value)) {
        #line 76 "src/std/HashSet.pv"
        return false;
    }
    #line 79 "src/std/HashSet.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 80 "src/std/HashSet.pv"
        HashSet_str__resize(self, 16);
    } else if (self->length * 100 / self->capacity > 75) {
        #line 82 "src/std/HashSet.pv"
        HashSet_str__resize(self, self->capacity * 2);
    }

    #line 85 "src/std/HashSet.pv"
    Hash hash = str__Hash__hash(&value);
    #line 86 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 87 "src/std/HashSet.pv"
    struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

    #line 89 "src/std/HashSet.pv"
    struct HashSetBucket_str* bucket_node = *current_bucket_node;
    #line 90 "src/std/HashSet.pv"
    while (bucket_node != 0) {
        #line 91 "src/std/HashSet.pv"
        current_bucket_node = &bucket_node->next;
        #line 92 "src/std/HashSet.pv"
        bucket_node = *current_bucket_node;
    }

    #line 95 "src/std/HashSet.pv"
    self->data[self->length] = (struct HashSetBucket_str) { .value = value, .next = 0 };
    #line 96 "src/std/HashSet.pv"
    struct HashSetBucket_str* data = self->data + self->length;
    #line 97 "src/std/HashSet.pv"
    self->length += 1;

    #line 99 "src/std/HashSet.pv"
    *current_bucket_node = data;

    #line 101 "src/std/HashSet.pv"
    return true;
}

#line 104 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self) {
    #line 105 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->buckets);
    #line 106 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->data);
    #line 107 "src/std/HashSet.pv"
    self->buckets = 0;
    #line 108 "src/std/HashSet.pv"
    self->data = 0;
    #line 109 "src/std/HashSet.pv"
    self->capacity = 0;
    #line 110 "src/std/HashSet.pv"
    self->length = 0;
}

#line 113 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self) {
    #line 114 "src/std/HashSet.pv"
    uintptr_t i = 0;
    #line 115 "src/std/HashSet.pv"
    while (i < self->length) {
        #line 116 "src/std/HashSet.pv"
        struct HashSetBucket_str* node = self->data + i;
        #line 117 "src/std/HashSet.pv"
        if (node == 0) {
            #line 117 "src/std/HashSet.pv"
            return;
        }
        #line 118 "src/std/HashSet.pv"
        node->next = 0;
        #line 119 "src/std/HashSet.pv"
        Hash hash = str__Hash__hash(&(*node).value);
        #line 120 "src/std/HashSet.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 121 "src/std/HashSet.pv"
        struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

        #line 123 "src/std/HashSet.pv"
        struct HashSetBucket_str* bucket_node = *current_bucket_node;
        #line 124 "src/std/HashSet.pv"
        while (bucket_node != 0) {
            #line 125 "src/std/HashSet.pv"
            current_bucket_node = &bucket_node->next;
            #line 126 "src/std/HashSet.pv"
            bucket_node = *current_bucket_node;
        }

        #line 129 "src/std/HashSet.pv"
        *current_bucket_node = node;

        #line 131 "src/std/HashSet.pv"
        i += 1;
    }
}

#line 135 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator) {
    #line 136 "src/std/HashSet.pv"
    struct HashSet_str other = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(self->data)),
        .data = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(struct HashSetBucket_str)),
        .length = self->length,
        .capacity = self->capacity,
    };

    #line 144 "src/std/HashSet.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashSetBucket_str));

    #line 146 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(&other);

    #line 148 "src/std/HashSet.pv"
    return other;
}

#line 151 "src/std/HashSet.pv"
struct HashSetIter_str HashSet_str__iter(struct HashSet_str* self) {
    #line 152 "src/std/HashSet.pv"
    return (struct HashSetIter_str) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}
