#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMapBucket_str_ref_Include.h>
#include <std/Hashed.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <analyzer/c/Include.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <std/HashMap_str_ref_Include.h>

#include <std/HashMap_str_ref_Include.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__new(struct trait_Allocator allocator) {
    #line 36 "src/std/HashMap.pv"
    return HashMap_str_ref_Include__with_capacity(allocator, 16);
}

#line 39 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__with_capacity(struct trait_Allocator allocator, uintptr_t capacity) {
    #line 40 "src/std/HashMap.pv"
    struct HashMap_str_ref_Include self = (struct HashMap_str_ref_Include) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 48 "src/std/HashMap.pv"
    HashMap_str_ref_Include__resize(&self, capacity);

    #line 50 "src/std/HashMap.pv"
    return self;
}

#line 53 "src/std/HashMap.pv"
void HashMap_str_ref_Include__resize(struct HashMap_str_ref_Include* self, uintptr_t new_capacity) {
    #line 54 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_str_ref_Include*));
    #line 55 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 56 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 57 "src/std/HashMap.pv"
    HashMap_str_ref_Include__fill_buckets(self);
}

#line 60 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__find(struct HashMap_str_ref_Include* self, struct str* key) {
    #line 61 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 61 "src/std/HashMap.pv"
        return 0;
    }

    #line 63 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&(*key));
    #line 64 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 65 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 67 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 68 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 69 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 71 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 74 "src/std/HashMap.pv"
    return 0;
}

#line 77 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__insert(struct HashMap_str_ref_Include* self, struct str key, struct Include* value) {
    #line 78 "src/std/HashMap.pv"
    struct Include** existing_value = HashMap_str_ref_Include__find(self, &key);
    #line 79 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 80 "src/std/HashMap.pv"
        *existing_value = value;
        #line 81 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 84 "src/std/HashMap.pv"
    if (self->capacity == 0 || (self->length * 100 / self->capacity) > 75) {
        #line 85 "src/std/HashMap.pv"
        HashMap_str_ref_Include__resize(self, self->capacity * 2);
    }

    #line 88 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&key);
    #line 89 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 90 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include** current_bucket_node = self->buckets + bucket_index;

    #line 92 "src/std/HashMap.pv"
    while (*current_bucket_node != 0) {
        #line 93 "src/std/HashMap.pv"
        current_bucket_node = &(*current_bucket_node)->next;
    }

    #line 96 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_ref_Include) { .key = key, .value = value, .next = 0 };
    #line 97 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* data = self->data + self->length;
    #line 98 "src/std/HashMap.pv"
    self->length += 1;

    #line 100 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 102 "src/std/HashMap.pv"
    return &data->value;
}

#line 105 "src/std/HashMap.pv"
bool HashMap_str_ref_Include__remove(struct HashMap_str_ref_Include* self, struct str* key) {
    #line 106 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 106 "src/std/HashMap.pv"
        return false;
    }

    #line 108 "src/std/HashMap.pv"
    Hashed hash = str__Hash__hash(&(*key));
    #line 109 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 110 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 112 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 113 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 114 "src/std/HashMap.pv"
            struct HashMapBucket_str_ref_Include* last = self->data + self->length - 1;
            #line 115 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 115 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 117 "src/std/HashMap.pv"
            self->length -= 1;
            #line 118 "src/std/HashMap.pv"
            HashMap_str_ref_Include__fill_buckets(self);

            #line 120 "src/std/HashMap.pv"
            return true;
        }

        #line 123 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 126 "src/std/HashMap.pv"
    return false;
}

#line 129 "src/std/HashMap.pv"
void HashMap_str_ref_Include__release(struct HashMap_str_ref_Include* self) {
    #line 130 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->buckets);
    #line 131 "src/std/HashMap.pv"
    self->allocator.vtable->free(self->allocator.instance, self->data);
    #line 132 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 133 "src/std/HashMap.pv"
    self->data = 0;
    #line 134 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 135 "src/std/HashMap.pv"
    self->length = 0;
}

#line 138 "src/std/HashMap.pv"
void HashMap_str_ref_Include__fill_buckets(struct HashMap_str_ref_Include* self) {
    #line 139 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include*));

    #line 141 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i < self->length; i++) {
        #line 142 "src/std/HashMap.pv"
        struct HashMapBucket_str_ref_Include* node = self->data + i;
        #line 143 "src/std/HashMap.pv"
        node->next = 0;
        #line 144 "src/std/HashMap.pv"
        Hashed hash = str__Hash__hash(&(*node).key);
        #line 145 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 146 "src/std/HashMap.pv"
        struct HashMapBucket_str_ref_Include** current_bucket_node = self->buckets + bucket_index;

        #line 148 "src/std/HashMap.pv"
        while (*current_bucket_node != 0) {
            #line 149 "src/std/HashMap.pv"
            current_bucket_node = &(*current_bucket_node)->next;
        }

        #line 152 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 156 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__clone(struct HashMap_str_ref_Include* self, struct trait_Allocator allocator) {
    #line 157 "src/std/HashMap.pv"
    struct HashMap_str_ref_Include other = (struct HashMap_str_ref_Include) {
        .allocator = allocator,
        .buckets = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_str_ref_Include)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 164 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 165 "src/std/HashMap.pv"
    HashMap_str_ref_Include__fill_buckets(&other);

    #line 167 "src/std/HashMap.pv"
    return other;
}

#line 170 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include HashMap_str_ref_Include__iter(struct HashMap_str_ref_Include* self) {
    #line 171 "src/std/HashMap.pv"
    return (struct HashMapIter_str_ref_Include) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 177 "src/std/HashMap.pv"
void HashMap_str_ref_Include__clear(struct HashMap_str_ref_Include* self) {
    #line 178 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 179 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include*));
    #line 180 "src/std/HashMap.pv"
    self->length = 0;
}
