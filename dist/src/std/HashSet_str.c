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
    struct HashSet_str self = (struct HashSet_str) { .allocator = allocator };

    #line 40 "src/std/HashSet.pv"
    HashSet_str__resize(&self, initial_capacity);

    #line 42 "src/std/HashSet.pv"
    return self;
}

#line 45 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity) {
    #line 46 "src/std/HashSet.pv"
    self->buckets = ArenaAllocator__Allocator__realloc(self->allocator, self->buckets, new_capacity * sizeof(self->data));
    #line 47 "src/std/HashSet.pv"
    self->data = ArenaAllocator__Allocator__realloc(self->allocator, self->data, new_capacity * sizeof(struct HashSetBucket_str));
    #line 48 "src/std/HashSet.pv"
    self->capacity = new_capacity;
    #line 49 "src/std/HashSet.pv"
    memset(self->buckets, 0, self->capacity * sizeof(self->data));

    #line 51 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(self);
}

#line 54 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value) {
    #line 55 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&(*value));
    #line 56 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 57 "src/std/HashSet.pv"
    struct HashSetBucket_str* current_bucket_node = self->buckets[bucket_index];

    #line 59 "src/std/HashSet.pv"
    while (current_bucket_node != 0) {
        #line 60 "src/std/HashSet.pv"
        if (str__Hash__hash(&current_bucket_node->value) == hash) {
            #line 61 "src/std/HashSet.pv"
            return true;
        }
        #line 63 "src/std/HashSet.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 66 "src/std/HashSet.pv"
    return false;
}

#line 69 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value) {
    #line 70 "src/std/HashSet.pv"
    if (HashSet_str__has(self, &value)) {
        #line 70 "src/std/HashSet.pv"
        return false;
    }

    #line 72 "src/std/HashSet.pv"
    if (self->length * 100 / self->capacity > 75) {
        #line 73 "src/std/HashSet.pv"
        HashSet_str__resize(self, self->capacity * 2);
    }

    #line 76 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&value);
    #line 77 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 78 "src/std/HashSet.pv"
    struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

    #line 80 "src/std/HashSet.pv"
    while (*current_bucket_node != 0) {
        #line 81 "src/std/HashSet.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 84 "src/std/HashSet.pv"
    self->data[self->length] = (struct HashSetBucket_str) { .value = value };
    #line 85 "src/std/HashSet.pv"
    struct HashSetBucket_str* data = self->data + self->length;
    #line 86 "src/std/HashSet.pv"
    self->length += 1;

    #line 88 "src/std/HashSet.pv"
    *current_bucket_node = data;

    #line 90 "src/std/HashSet.pv"
    return true;
}

#line 93 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self) {
    #line 94 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->buckets);
    #line 95 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->data);
    #line 96 "src/std/HashSet.pv"
    self->buckets = 0;
    #line 97 "src/std/HashSet.pv"
    self->data = 0;
    #line 98 "src/std/HashSet.pv"
    self->capacity = 0;
    #line 99 "src/std/HashSet.pv"
    self->length = 0;
}

#line 102 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self) {
    #line 103 "src/std/HashSet.pv"
    uintptr_t i = 0;
    #line 104 "src/std/HashSet.pv"
    while (i < self->length) {
        #line 105 "src/std/HashSet.pv"
        struct HashSetBucket_str* node = self->data + i;
        #line 106 "src/std/HashSet.pv"
        node->next = 0;
        #line 107 "src/std/HashSet.pv"
        Hashed hash = str__Hash__hash(&(*node).value);
        #line 108 "src/std/HashSet.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 109 "src/std/HashSet.pv"
        struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

        #line 111 "src/std/HashSet.pv"
        while (*current_bucket_node != 0) {
            #line 112 "src/std/HashSet.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 115 "src/std/HashSet.pv"
        *current_bucket_node = node;

        #line 117 "src/std/HashSet.pv"
        i += 1;
    }
}

#line 121 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator) {
    #line 122 "src/std/HashSet.pv"
    struct HashSet_str other = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(self->data)),
        .data = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(struct HashSetBucket_str)),
        .length = self->length,
        .capacity = self->capacity,
    };

    #line 130 "src/std/HashSet.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashSetBucket_str));

    #line 132 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(&other);

    #line 134 "src/std/HashSet.pv"
    return other;
}

#line 137 "src/std/HashSet.pv"
struct HashSetIter_str HashSet_str__iter(struct HashSet_str* self) {
    #line 138 "src/std/HashSet.pv"
    return (struct HashSetIter_str) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}
