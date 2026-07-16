#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <std/HashSet_usize.h>
#include <std/ArenaAllocator.h>
#include <std/HashSetBucket_usize.h>
#include <std/Hash.h>
#include <std/trait_Hash.h>
#include <usize.h>
#include <u64.h>
#include <std/HashSetIter_usize.h>
#include <std/HashSet_usize.h>

#include <std/HashSet_usize.h>

#line 34 "src/std/HashSet.pv"
struct HashSet_usize HashSet_usize__new(struct ArenaAllocator* allocator) {
    #line 35 "src/std/HashSet.pv"
    int32_t initial_capacity = 16;
    #line 36 "src/std/HashSet.pv"
    struct HashSet_usize self = (struct HashSet_usize) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 44 "src/std/HashSet.pv"
    HashSet_usize__resize(&self, initial_capacity);

    #line 46 "src/std/HashSet.pv"
    return self;
}

#line 49 "src/std/HashSet.pv"
void HashSet_usize__resize(struct HashSet_usize* self, uintptr_t new_capacity) {
    #line 50 "src/std/HashSet.pv"
    self->buckets = ArenaAllocator__Allocator__realloc(self->allocator, self->buckets, new_capacity * sizeof(self->data));
    #line 51 "src/std/HashSet.pv"
    self->data = ArenaAllocator__Allocator__realloc(self->allocator, self->data, new_capacity * sizeof(struct HashSetBucket_usize));
    #line 52 "src/std/HashSet.pv"
    self->capacity = new_capacity;
    #line 53 "src/std/HashSet.pv"
    memset(self->buckets, 0, self->capacity * sizeof(self->data));

    #line 55 "src/std/HashSet.pv"
    HashSet_usize__fill_buckets(self);
}

#line 58 "src/std/HashSet.pv"
bool HashSet_usize__has(struct HashSet_usize* self, uintptr_t* value) {
    #line 59 "src/std/HashSet.pv"
    Hash hash = usize__Hash__hash(&(*value));
    #line 60 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 61 "src/std/HashSet.pv"
    struct HashSetBucket_usize* current_bucket_node = self->buckets[bucket_index];

    #line 63 "src/std/HashSet.pv"
    while (current_bucket_node != 0) {
        #line 64 "src/std/HashSet.pv"
        if (u64__Eq_u64__eq(usize__Hash__hash(&current_bucket_node->value), hash)) {
            #line 65 "src/std/HashSet.pv"
            return true;
        }
        #line 67 "src/std/HashSet.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 70 "src/std/HashSet.pv"
    return false;
}

#line 73 "src/std/HashSet.pv"
bool HashSet_usize__insert(struct HashSet_usize* self, uintptr_t value) {
    #line 74 "src/std/HashSet.pv"
    if (HashSet_usize__has(self, &value)) {
        #line 74 "src/std/HashSet.pv"
        return false;
    }

    #line 76 "src/std/HashSet.pv"
    if (self->length * 100 / self->capacity > 75) {
        #line 77 "src/std/HashSet.pv"
        HashSet_usize__resize(self, self->capacity * 2);
    }

    #line 80 "src/std/HashSet.pv"
    Hash hash = usize__Hash__hash(&value);
    #line 81 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 82 "src/std/HashSet.pv"
    struct HashSetBucket_usize** current_bucket_node = self->buckets + bucket_index;

    #line 84 "src/std/HashSet.pv"
    struct HashSetBucket_usize* bucket_node = *current_bucket_node;
    #line 85 "src/std/HashSet.pv"
    while (bucket_node != 0) {
        #line 86 "src/std/HashSet.pv"
        current_bucket_node = &bucket_node->next;
        #line 87 "src/std/HashSet.pv"
        bucket_node = *current_bucket_node;
    }

    #line 90 "src/std/HashSet.pv"
    self->data[self->length] = (struct HashSetBucket_usize) { .value = value, .next = 0 };
    #line 91 "src/std/HashSet.pv"
    struct HashSetBucket_usize* data = self->data + self->length;
    #line 92 "src/std/HashSet.pv"
    self->length += 1;

    #line 94 "src/std/HashSet.pv"
    *current_bucket_node = data;

    #line 96 "src/std/HashSet.pv"
    return true;
}

#line 99 "src/std/HashSet.pv"
void HashSet_usize__release(struct HashSet_usize* self) {
    #line 100 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->buckets);
    #line 101 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->data);
    #line 102 "src/std/HashSet.pv"
    self->buckets = 0;
    #line 103 "src/std/HashSet.pv"
    self->data = 0;
    #line 104 "src/std/HashSet.pv"
    self->capacity = 0;
    #line 105 "src/std/HashSet.pv"
    self->length = 0;
}

#line 108 "src/std/HashSet.pv"
void HashSet_usize__fill_buckets(struct HashSet_usize* self) {
    #line 109 "src/std/HashSet.pv"
    uintptr_t i = 0;
    #line 110 "src/std/HashSet.pv"
    while (i < self->length) {
        #line 111 "src/std/HashSet.pv"
        struct HashSetBucket_usize* node = self->data + i;
        #line 112 "src/std/HashSet.pv"
        if (node == 0) {
            #line 112 "src/std/HashSet.pv"
            return;
        }
        #line 113 "src/std/HashSet.pv"
        node->next = 0;
        #line 114 "src/std/HashSet.pv"
        Hash hash = usize__Hash__hash(&(*node).value);
        #line 115 "src/std/HashSet.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 116 "src/std/HashSet.pv"
        struct HashSetBucket_usize** current_bucket_node = self->buckets + bucket_index;

        #line 118 "src/std/HashSet.pv"
        struct HashSetBucket_usize* bucket_node = *current_bucket_node;
        #line 119 "src/std/HashSet.pv"
        while (bucket_node != 0) {
            #line 120 "src/std/HashSet.pv"
            current_bucket_node = &bucket_node->next;
            #line 121 "src/std/HashSet.pv"
            bucket_node = *current_bucket_node;
        }

        #line 124 "src/std/HashSet.pv"
        *current_bucket_node = node;

        #line 126 "src/std/HashSet.pv"
        i += 1;
    }
}

#line 130 "src/std/HashSet.pv"
struct HashSet_usize HashSet_usize__clone(struct HashSet_usize* self, struct ArenaAllocator* allocator) {
    #line 131 "src/std/HashSet.pv"
    struct HashSet_usize other = (struct HashSet_usize) {
        .allocator = allocator,
        .buckets = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(self->data)),
        .data = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(struct HashSetBucket_usize)),
        .length = self->length,
        .capacity = self->capacity,
    };

    #line 139 "src/std/HashSet.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashSetBucket_usize));

    #line 141 "src/std/HashSet.pv"
    HashSet_usize__fill_buckets(&other);

    #line 143 "src/std/HashSet.pv"
    return other;
}

#line 146 "src/std/HashSet.pv"
struct HashSetIter_usize HashSet_usize__iter(struct HashSet_usize* self) {
    #line 147 "src/std/HashSet.pv"
    return (struct HashSetIter_usize) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}
