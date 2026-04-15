#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <std/HashMap_str_Enum.h>
#include <std/trait_Allocator.h>
#include <std/HashMapBucket_str_Enum.h>
#include <analyzer/types/Enum.h>
#include <std/Hashed.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_str_Enum.h>
#include <std/HashMap_str_Enum.h>

#include <std/HashMap_str_Enum.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__new(struct trait_Allocator allocator) {
    #line 36 "src/std/HashMap.pv"
    int32_t initial_capacity = 16;
    #line 37 "src/std/HashMap.pv"
    struct HashMap_str_Enum self = (struct HashMap_str_Enum) { .allocator = allocator };

    #line 41 "src/std/HashMap.pv"
    HashMap_str_Enum__resize(&self, initial_capacity);

    #line 43 "src/std/HashMap.pv"
    return self;
}

#line 46 "src/std/HashMap.pv"
void HashMap_str_Enum__resize(struct HashMap_str_Enum* self, uintptr_t new_capacity) {
    #line 47 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_str_Enum*));
    #line 48 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_str_Enum));
    #line 49 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 50 "src/std/HashMap.pv"
    HashMap_str_Enum__fill_buckets(self);
}

#line 53 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__find(struct HashMap_str_Enum* self, struct str* key) {
    #line 54 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 54 "src/std/HashMap.pv"
        return 0;
    }

    #line 56 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&(*key));
    #line 57 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 58 "src/std/HashMap.pv"
    struct HashMapBucket_str_Enum* current_bucket_node = self->buckets[bucket_index];

    #line 60 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 61 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 62 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 64 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 67 "src/std/HashMap.pv"
    return 0;
}

#line 70 "src/std/HashMap.pv"
struct Enum* HashMap_str_Enum__insert(struct HashMap_str_Enum* self, struct str key, struct Enum value) {
    #line 71 "src/std/HashMap.pv"
    struct Enum* existing_value = HashMap_str_Enum__find(self, &key);
    #line 72 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 73 "src/std/HashMap.pv"
        *existing_value = value;
        #line 74 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 77 "src/std/HashMap.pv"
    if (self->capacity == 0 || (self->length * 100 / self->capacity) > 75) {
        #line 78 "src/std/HashMap.pv"
        HashMap_str_Enum__resize(self, self->capacity * 2);
    }

    #line 81 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&key);
    #line 82 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 83 "src/std/HashMap.pv"
    struct HashMapBucket_str_Enum** current_bucket_node = self->buckets + bucket_index;

    #line 85 "src/std/HashMap.pv"
    while (*current_bucket_node != 0) {
        #line 86 "src/std/HashMap.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 89 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_Enum) { .key = key, .value = value };
    #line 90 "src/std/HashMap.pv"
    struct HashMapBucket_str_Enum* data = self->data + self->length;
    #line 91 "src/std/HashMap.pv"
    self->length += 1;

    #line 93 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 95 "src/std/HashMap.pv"
    return &data->value;
}

#line 98 "src/std/HashMap.pv"
bool HashMap_str_Enum__remove(struct HashMap_str_Enum* self, struct str* key) {
    #line 99 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 99 "src/std/HashMap.pv"
        return false;
    }

    #line 101 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&(*key));
    #line 102 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 103 "src/std/HashMap.pv"
    struct HashMapBucket_str_Enum* current_bucket_node = self->buckets[bucket_index];

    #line 105 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 106 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 107 "src/std/HashMap.pv"
            struct HashMapBucket_str_Enum* last = self->data + self->length - 1;
            #line 108 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 108 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 110 "src/std/HashMap.pv"
            self->length -= 1;
            #line 111 "src/std/HashMap.pv"
            HashMap_str_Enum__fill_buckets(self);

            #line 113 "src/std/HashMap.pv"
            return true;
        }

        #line 116 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 119 "src/std/HashMap.pv"
    return false;
}

#line 122 "src/std/HashMap.pv"
void HashMap_str_Enum__release(struct HashMap_str_Enum* self) {
    #line 123 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->buckets);
    #line 124 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->data);
    #line 125 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 126 "src/std/HashMap.pv"
    self->data = 0;
    #line 127 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 128 "src/std/HashMap.pv"
    self->length = 0;
}

#line 131 "src/std/HashMap.pv"
void HashMap_str_Enum__fill_buckets(struct HashMap_str_Enum* self) {
    #line 132 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_Enum*));

    #line 134 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i < self->length; i++) {
        #line 135 "src/std/HashMap.pv"
        struct HashMapBucket_str_Enum* node = self->data + i;
        #line 136 "src/std/HashMap.pv"
        node->next = 0;
        #line 137 "src/std/HashMap.pv"
        Hashed hash = str__Hash__hash(&(*node).key);
        #line 138 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 139 "src/std/HashMap.pv"
        struct HashMapBucket_str_Enum** current_bucket_node = self->buckets + bucket_index;

        #line 141 "src/std/HashMap.pv"
        while (*current_bucket_node != 0) {
            #line 142 "src/std/HashMap.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 145 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 149 "src/std/HashMap.pv"
struct HashMap_str_Enum HashMap_str_Enum__clone(struct HashMap_str_Enum* self, struct trait_Allocator allocator) {
    #line 150 "src/std/HashMap.pv"
    struct HashMap_str_Enum other = (struct HashMap_str_Enum) {
        .allocator = allocator,
        .buckets = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_str_Enum)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 157 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_str_Enum));
    #line 158 "src/std/HashMap.pv"
    HashMap_str_Enum__fill_buckets(&other);

    #line 160 "src/std/HashMap.pv"
    return other;
}

#line 163 "src/std/HashMap.pv"
struct HashMapIter_str_Enum HashMap_str_Enum__iter(struct HashMap_str_Enum* self) {
    #line 164 "src/std/HashMap.pv"
    return (struct HashMapIter_str_Enum) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 170 "src/std/HashMap.pv"
void HashMap_str_Enum__clear(struct HashMap_str_Enum* self) {
    #line 171 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_str_Enum));
    #line 172 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_Enum*));
    #line 173 "src/std/HashMap.pv"
    self->length = 0;
}
