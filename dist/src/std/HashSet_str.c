#include <stdio.h>
#include <string.h>

#include <std/ArenaAllocator.h>
#include <stdint.h>
#include <std/Hashed.h>
#include <std/str.h>
#include <std/HashSetBucket_str.h>
#include <stdbool.h>

#include <std/HashSet_str.h>

#line 18 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__new(struct ArenaAllocator* allocator) {
    #line 19 "src/std/HashSet.pv"
    int32_t initial_capacity = 16;
    #line 20 "src/std/HashSet.pv"
    struct HashSet_str self = (struct HashSet_str) { .allocator = allocator };

    #line 24 "src/std/HashSet.pv"
    HashSet_str__resize(&self, initial_capacity);

    #line 26 "src/std/HashSet.pv"
    return self;
}

#line 29 "src/std/HashSet.pv"
void HashSet_str__resize(struct HashSet_str* self, uintptr_t new_capacity) {
    #line 30 "src/std/HashSet.pv"
    self->buckets = ArenaAllocator__Allocator__realloc(self->allocator, self->buckets, new_capacity * sizeof(self->data));
    #line 31 "src/std/HashSet.pv"
    self->data = ArenaAllocator__Allocator__realloc(self->allocator, self->data, new_capacity * sizeof(struct HashSetBucket_str));
    #line 32 "src/std/HashSet.pv"
    self->capacity = new_capacity;
    #line 33 "src/std/HashSet.pv"
    memset(self->buckets, 0, self->capacity * sizeof(self->data));

    #line 35 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(self);
}

#line 38 "src/std/HashSet.pv"
bool HashSet_str__has(struct HashSet_str* self, struct str* value) {
    #line 39 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&(*value));
    #line 40 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 41 "src/std/HashSet.pv"
    struct HashSetBucket_str* current_bucket_node = self->buckets[bucket_index];

    #line 43 "src/std/HashSet.pv"
    while (current_bucket_node != 0) {
        #line 44 "src/std/HashSet.pv"
        if (str__Hash__hash(&current_bucket_node->value) == hash) {
            #line 45 "src/std/HashSet.pv"
            return true;
        }
        #line 47 "src/std/HashSet.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 50 "src/std/HashSet.pv"
    return false;
}

#line 53 "src/std/HashSet.pv"
bool HashSet_str__insert(struct HashSet_str* self, struct str value) {
    #line 54 "src/std/HashSet.pv"
    if (HashSet_str__has(self, &value)) {
        #line 54 "src/std/HashSet.pv"
        return false;
    }

    #line 56 "src/std/HashSet.pv"
    if ((self->length * 100 / self->capacity) > 75) {
        #line 57 "src/std/HashSet.pv"
        HashSet_str__resize(self, self->capacity * 2);
    }

    #line 60 "src/std/HashSet.pv"
    Hashed hash = str__Hash__hash(&value);
    #line 61 "src/std/HashSet.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 62 "src/std/HashSet.pv"
    struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

    #line 64 "src/std/HashSet.pv"
    while (*current_bucket_node != 0) {
        #line 65 "src/std/HashSet.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 68 "src/std/HashSet.pv"
    self->data[self->length] = (struct HashSetBucket_str) { .value = value };
    #line 69 "src/std/HashSet.pv"
    struct HashSetBucket_str* data = self->data + self->length;
    #line 70 "src/std/HashSet.pv"
    self->length += 1;

    #line 72 "src/std/HashSet.pv"
    *current_bucket_node = data;

    #line 74 "src/std/HashSet.pv"
    return true;
}

#line 77 "src/std/HashSet.pv"
void HashSet_str__release(struct HashSet_str* self) {
    #line 78 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->buckets);
    #line 79 "src/std/HashSet.pv"
    ArenaAllocator__Allocator__free(self->allocator, self->data);
    #line 80 "src/std/HashSet.pv"
    self->buckets = 0;
    #line 81 "src/std/HashSet.pv"
    self->data = 0;
    #line 82 "src/std/HashSet.pv"
    self->capacity = 0;
    #line 83 "src/std/HashSet.pv"
    self->length = 0;
}

#line 86 "src/std/HashSet.pv"
void HashSet_str__fill_buckets(struct HashSet_str* self) {
    #line 87 "src/std/HashSet.pv"
    uintptr_t i = 0;
    #line 88 "src/std/HashSet.pv"
    while (i < self->length) {
        #line 89 "src/std/HashSet.pv"
        struct HashSetBucket_str* node = self->data + i;
        #line 90 "src/std/HashSet.pv"
        node->next = 0;
        #line 91 "src/std/HashSet.pv"
        Hashed hash = str__Hash__hash(&(*node).value);
        #line 92 "src/std/HashSet.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 93 "src/std/HashSet.pv"
        struct HashSetBucket_str** current_bucket_node = self->buckets + bucket_index;

        #line 95 "src/std/HashSet.pv"
        while (*current_bucket_node != 0) {
            #line 96 "src/std/HashSet.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 99 "src/std/HashSet.pv"
        *current_bucket_node = node;

        #line 101 "src/std/HashSet.pv"
        i += 1;
    }
}

#line 105 "src/std/HashSet.pv"
struct HashSet_str HashSet_str__clone(struct HashSet_str* self, struct ArenaAllocator* allocator) {
    #line 106 "src/std/HashSet.pv"
    struct HashSet_str other = (struct HashSet_str) {
        .allocator = allocator,
        .buckets = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(self->data)),
        .data = ArenaAllocator__Allocator__alloc(allocator, self->capacity * sizeof(struct HashSetBucket_str)),
        .length = self->length,
        .capacity = self->capacity,
    };

    #line 114 "src/std/HashSet.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashSetBucket_str));

    #line 116 "src/std/HashSet.pv"
    HashSet_str__fill_buckets(&other);

    #line 118 "src/std/HashSet.pv"
    return other;
}
