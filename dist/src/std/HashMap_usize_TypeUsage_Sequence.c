#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>
#include <std/HashMapBucket_usize_TypeUsage_Sequence.h>
#include <std/Hashed.h>
#include <std/trait_Hash.h>
#include <usize.h>
#include <compiler/TypeUsage_Sequence.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_usize_TypeUsage_Sequence.h>
#include <std/HashMap_usize_TypeUsage_Sequence.h>

#include <std/HashMap_usize_TypeUsage_Sequence.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__new(struct trait_Allocator allocator) {
    #line 36 "src/std/HashMap.pv"
    int32_t initial_capacity = 16;
    #line 37 "src/std/HashMap.pv"
    struct HashMap_usize_TypeUsage_Sequence self = (struct HashMap_usize_TypeUsage_Sequence) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 45 "src/std/HashMap.pv"
    HashMap_usize_TypeUsage_Sequence__resize(&self, initial_capacity);

    #line 47 "src/std/HashMap.pv"
    return self;
}

#line 50 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__resize(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t new_capacity) {
    #line 51 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence*));
    #line 52 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence));
    #line 53 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 54 "src/std/HashMap.pv"
    HashMap_usize_TypeUsage_Sequence__fill_buckets(self);
}

#line 57 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__find(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key) {
    #line 58 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 58 "src/std/HashMap.pv"
        return 0;
    }

    #line 60 "src/std/HashMap.pv"
    Hashed hash = usize__Hash__hash(&(*key));
    #line 61 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 62 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeUsage_Sequence* current_bucket_node = self->buckets[bucket_index];

    #line 64 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 65 "src/std/HashMap.pv"
        if (usize__Hash__hash(&current_bucket_node->key) == hash) {
            #line 66 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 68 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 71 "src/std/HashMap.pv"
    return 0;
}

#line 74 "src/std/HashMap.pv"
struct TypeUsage_Sequence* HashMap_usize_TypeUsage_Sequence__insert(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t key, struct TypeUsage_Sequence value) {
    #line 75 "src/std/HashMap.pv"
    struct TypeUsage_Sequence* existing_value = HashMap_usize_TypeUsage_Sequence__find(self, &key);
    #line 76 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 77 "src/std/HashMap.pv"
        *existing_value = value;
        #line 78 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 81 "src/std/HashMap.pv"
    if (self->capacity == 0 || (self->length * 100 / self->capacity) > 75) {
        #line 82 "src/std/HashMap.pv"
        HashMap_usize_TypeUsage_Sequence__resize(self, self->capacity * 2);
    }

    #line 85 "src/std/HashMap.pv"
    Hashed hash = usize__Hash__hash(&key);
    #line 86 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 87 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeUsage_Sequence** current_bucket_node = self->buckets + bucket_index;

    #line 89 "src/std/HashMap.pv"
    while (*current_bucket_node != 0) {
        #line 90 "src/std/HashMap.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 93 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_usize_TypeUsage_Sequence) { .key = key, .value = value, .next = 0 };
    #line 94 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeUsage_Sequence* data = self->data + self->length;
    #line 95 "src/std/HashMap.pv"
    self->length += 1;

    #line 97 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 99 "src/std/HashMap.pv"
    return &data->value;
}

#line 102 "src/std/HashMap.pv"
bool HashMap_usize_TypeUsage_Sequence__remove(struct HashMap_usize_TypeUsage_Sequence* self, uintptr_t* key) {
    #line 103 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 103 "src/std/HashMap.pv"
        return false;
    }

    #line 105 "src/std/HashMap.pv"
    Hashed hash = usize__Hash__hash(&(*key));
    #line 106 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 107 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeUsage_Sequence* current_bucket_node = self->buckets[bucket_index];

    #line 109 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 110 "src/std/HashMap.pv"
        if (usize__Hash__hash(&current_bucket_node->key) == hash) {
            #line 111 "src/std/HashMap.pv"
            struct HashMapBucket_usize_TypeUsage_Sequence* last = self->data + self->length - 1;
            #line 112 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 112 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 114 "src/std/HashMap.pv"
            self->length -= 1;
            #line 115 "src/std/HashMap.pv"
            HashMap_usize_TypeUsage_Sequence__fill_buckets(self);

            #line 117 "src/std/HashMap.pv"
            return true;
        }

        #line 120 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 123 "src/std/HashMap.pv"
    return false;
}

#line 126 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__release(struct HashMap_usize_TypeUsage_Sequence* self) {
    #line 127 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->buckets);
    #line 128 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->data);
    #line 129 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 130 "src/std/HashMap.pv"
    self->data = 0;
    #line 131 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 132 "src/std/HashMap.pv"
    self->length = 0;
}

#line 135 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__fill_buckets(struct HashMap_usize_TypeUsage_Sequence* self) {
    #line 136 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence*));

    #line 138 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i < self->length; i++) {
        #line 139 "src/std/HashMap.pv"
        struct HashMapBucket_usize_TypeUsage_Sequence* node = self->data + i;
        #line 140 "src/std/HashMap.pv"
        node->next = 0;
        #line 141 "src/std/HashMap.pv"
        Hashed hash = usize__Hash__hash(&(*node).key);
        #line 142 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 143 "src/std/HashMap.pv"
        struct HashMapBucket_usize_TypeUsage_Sequence** current_bucket_node = self->buckets + bucket_index;

        #line 145 "src/std/HashMap.pv"
        while (*current_bucket_node != 0) {
            #line 146 "src/std/HashMap.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 149 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 153 "src/std/HashMap.pv"
struct HashMap_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__clone(struct HashMap_usize_TypeUsage_Sequence* self, struct trait_Allocator allocator) {
    #line 154 "src/std/HashMap.pv"
    struct HashMap_usize_TypeUsage_Sequence other = (struct HashMap_usize_TypeUsage_Sequence) {
        .allocator = allocator,
        .buckets = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 161 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence));
    #line 162 "src/std/HashMap.pv"
    HashMap_usize_TypeUsage_Sequence__fill_buckets(&other);

    #line 164 "src/std/HashMap.pv"
    return other;
}

#line 167 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeUsage_Sequence HashMap_usize_TypeUsage_Sequence__iter(struct HashMap_usize_TypeUsage_Sequence* self) {
    #line 168 "src/std/HashMap.pv"
    return (struct HashMapIter_usize_TypeUsage_Sequence) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 174 "src/std/HashMap.pv"
void HashMap_usize_TypeUsage_Sequence__clear(struct HashMap_usize_TypeUsage_Sequence* self) {
    #line 175 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence));
    #line 176 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeUsage_Sequence*));
    #line 177 "src/std/HashMap.pv"
    self->length = 0;
}
