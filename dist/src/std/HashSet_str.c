#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <std/HashSet_str.h>
#include <std/ArenaAllocator.h>
#include <std/HashSetBucket_str.h>
#include <std/Hashed.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <std/HashSetIter_str.h>
#include <std/HashSet_str.h>

#include <std/HashSet_str.h>

#line 34 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator) {
    #line 35 "src/std/HashSet.pv"
    int32_t initial_capacity = 16;
    #line 36 "src/std/HashSet.pv"
    struct HashSet_str self = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 44 "src/std/HashSet.pv"
    HashSet_str__resize(&self, initial_capacity);

    #line 46 "src/std/HashSet.pv"
    return self;
}

#line 49 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity) {
    #line 50 "src/std/HashSet.pv"
    self->buckets = ArenaAllocator__Allocator__realloc(self->allocator, self->buckets, new_capacity * sizeof(self->data));
    #line 51 "src/std/HashSet.pv"
    self->data = ArenaAllocator__Allocator__realloc(self->allocator, self->data, new_capacity * sizeof(struct HashSetBucket_str));
    #line 52 "src/std/HashSet.pv"
    self->capacity = new_capacity;
    #line 53 "src/std/HashSet.pv"
    memset(self->buckets, 0, self->capacity * sizeof(self->data));

    #line 55 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(self);
}

#line 58 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value) {
    #line 59 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&(*value));
    #line 60 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 61 "src/std/HashSet.pv"
    struct HashSetBucket_str* current_bucket_node = self->buckets[bucket_index];

    #line 63 "src/std/HashSet.pv"
    while (current_bucket_node != 0) {
        #line 64 "src/std/HashSet.pv"
        if (str__Hash__hash(&current_bucket_node->value) == hash) {
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
bool HashSet_str__insert(struct HashSet_str* self, struct str value) {
    #line 74 "src/std/HashSet.pv"
    if (HashSet_str__has(self, &value)) {
        #line 74 "src/std/HashSet.pv"
        return false;
    }

    #line 76 "src/std/HashSet.pv"
    if (self->length * 100 / self->capacity > 75) {
        #line 77 "src/std/HashSet.pv"
        HashSet_str__resize(self, self->capacity * 2);
    }

    #line 80 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&value);
    #line 81 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 82 "src/std/HashSet.pv"
    struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

    #line 84 "src/std/HashSet.pv"
    while (*current_bucket_node != 0) {
        #line 85 "src/std/HashSet.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 88 "src/std/HashSet.pv"
    self->data[self->length] = (struct HashSetBucket_str) { .value = value, .next = 0 };
    #line 89 "src/std/HashSet.pv"
    struct HashSetBucket_str* data = self->data + self->length;
    #line 90 "src/std/HashSet.pv"
    self->length += 1;

    #line 92 "src/std/HashSet.pv"
    *current_bucket_node = data;

    #line 94 "src/std/HashSet.pv"
    return true;
}

#line 97 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self) {
    #line 98 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->buckets);
    #line 99 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->data);
    #line 100 "src/std/HashSet.pv"
    self->buckets = 0;
    #line 101 "src/std/HashSet.pv"
    self->data = 0;
    #line 102 "src/std/HashSet.pv"
    self->capacity = 0;
    #line 103 "src/std/HashSet.pv"
    self->length = 0;
}

#line 106 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self) {
    #line 107 "src/std/HashSet.pv"
    uintptr_t i = 0;
    #line 108 "src/std/HashSet.pv"
    while (i < self->length) {
        #line 109 "src/std/HashSet.pv"
        struct HashSetBucket_str* node = self->data + i;
        #line 110 "src/std/HashSet.pv"
        node->next = 0;
        #line 111 "src/std/HashSet.pv"
        Hashed hash = str__Hash__hash(&(*node).value);
        #line 112 "src/std/HashSet.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 113 "src/std/HashSet.pv"
        struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

        #line 115 "src/std/HashSet.pv"
        while (*current_bucket_node != 0) {
            #line 116 "src/std/HashSet.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 119 "src/std/HashSet.pv"
        *current_bucket_node = node;

        #line 121 "src/std/HashSet.pv"
        i += 1;
    }
}

#line 125 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator) {
    #line 126 "src/std/HashSet.pv"
    struct HashSet_str other = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(self->data)),
        .data = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(struct HashSetBucket_str)),
        .length = self->length,
        .capacity = self->capacity,
    };

    #line 134 "src/std/HashSet.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashSetBucket_str));

    #line 136 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(&other);

    #line 138 "src/std/HashSet.pv"
    return other;
}

#line 141 "src/std/HashSet.pv"
struct HashSetIter_str HashSet_str__iter(struct HashSet_str* self) {
    #line 142 "src/std/HashSet.pv"
    return (struct HashSetIter_str) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}
