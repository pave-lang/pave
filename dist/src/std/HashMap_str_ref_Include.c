#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <std/HashMapBucket_str_ref_Include.h>
#include <usize.h>
#include <std/Hash.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <u64.h>
#include <analyzer/c/Include.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <std/HashMap_str_ref_Include.h>

#include <std/HashMap_str_ref_Include.h>

#line 36 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__new(struct trait_Allocator allocator) {
    #line 37 "src/std/HashMap.pv"
    return HashMap_str_ref_Include__with_capacity(allocator, 16);
}

#line 40 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__with_capacity(struct trait_Allocator allocator, uintptr_t capacity) {
    #line 41 "src/std/HashMap.pv"
    struct HashMap_str_ref_Include self = (struct HashMap_str_ref_Include) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 49 "src/std/HashMap.pv"
    HashMap_str_ref_Include__resize(&self, capacity);

    #line 51 "src/std/HashMap.pv"
    return self;
}

#line 54 "src/std/HashMap.pv"
void HashMap_str_ref_Include__resize(struct HashMap_str_ref_Include* self, uintptr_t new_capacity) {
    #line 55 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->fn_realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_str_ref_Include*));
    #line 56 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->fn_realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 57 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 58 "src/std/HashMap.pv"
    HashMap_str_ref_Include__fill_buckets(self);
}

#line 61 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__find(struct HashMap_str_ref_Include* self, struct str* key) {
    #line 62 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 62 "src/std/HashMap.pv"
        return 0;
    }

    #line 64 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 65 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 66 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 68 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 69 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(str__Hash__hash(&current_bucket_node->key), hash) && str__Eq_str__eq(current_bucket_node->key, *key)) {
            #line 70 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 72 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 75 "src/std/HashMap.pv"
    return 0;
}

#line 78 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__insert(struct HashMap_str_ref_Include* self, struct str key, struct Include* value) {
    #line 79 "src/std/HashMap.pv"
    struct Include** existing_value = HashMap_str_ref_Include__find(self, &key);
    #line 80 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 81 "src/std/HashMap.pv"
        *existing_value = value;
        #line 82 "src/std/HashMap.pv"
        return existing_value;
    }
    #line 87 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 88 "src/std/HashMap.pv"
        HashMap_str_ref_Include__resize(self, 16);
    } else if ((self->length * 100 / self->capacity) > 75) {
        #line 90 "src/std/HashMap.pv"
        HashMap_str_ref_Include__resize(self, self->capacity * 2);
    }

    #line 93 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&key);
    #line 94 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 95 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include** current_bucket_node = self->buckets + bucket_index;

    #line 97 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* bucket_node = *current_bucket_node;
    #line 98 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 99 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 100 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 103 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_ref_Include) { .key = key, .value = value, .next = 0 };
    #line 104 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* data = self->data + self->length;
    #line 105 "src/std/HashMap.pv"
    self->length += 1;

    #line 107 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 109 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 112 "src/std/HashMap.pv"
bool HashMap_str_ref_Include__remove(struct HashMap_str_ref_Include* self, struct str* key) {
    #line 113 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 113 "src/std/HashMap.pv"
        return false;
    }

    #line 115 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 116 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 117 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 119 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 120 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(str__Hash__hash(&current_bucket_node->key), hash) && str__Eq_str__eq(current_bucket_node->key, *key)) {
            #line 121 "src/std/HashMap.pv"
            struct HashMapBucket_str_ref_Include* last = self->data + self->length - 1;
            #line 122 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 122 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 124 "src/std/HashMap.pv"
            self->length -= 1;
            #line 125 "src/std/HashMap.pv"
            HashMap_str_ref_Include__fill_buckets(self);

            #line 127 "src/std/HashMap.pv"
            return true;
        }

        #line 130 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 133 "src/std/HashMap.pv"
    return false;
}

#line 136 "src/std/HashMap.pv"
void HashMap_str_ref_Include__release(struct HashMap_str_ref_Include* self) {
    #line 137 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->buckets);
    #line 138 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->data);
    #line 139 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 140 "src/std/HashMap.pv"
    self->data = 0;
    #line 141 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 142 "src/std/HashMap.pv"
    self->length = 0;
}

#line 145 "src/std/HashMap.pv"
void HashMap_str_ref_Include__fill_buckets(struct HashMap_str_ref_Include* self) {
    #line 146 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include*));

    #line 148 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i != self->length; i < self->length ? i++ : i--) {
        #line 149 "src/std/HashMap.pv"
        struct HashMapBucket_str_ref_Include* node = self->data + i;
        #line 150 "src/std/HashMap.pv"
        if (node == 0) {
            #line 150 "src/std/HashMap.pv"
            return;
        }
        #line 151 "src/std/HashMap.pv"
        node->next = 0;
        #line 152 "src/std/HashMap.pv"
        Hash hash = str__Hash__hash(&(*node).key);
        #line 153 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 154 "src/std/HashMap.pv"
        struct HashMapBucket_str_ref_Include** current_bucket_node = self->buckets + bucket_index;

        #line 156 "src/std/HashMap.pv"
        struct HashMapBucket_str_ref_Include* bucket_node = *current_bucket_node;
        #line 157 "src/std/HashMap.pv"
        while (bucket_node != 0) {
            #line 158 "src/std/HashMap.pv"
            current_bucket_node = &bucket_node->next;
            #line 159 "src/std/HashMap.pv"
            bucket_node = *current_bucket_node;
        }

        #line 162 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 166 "src/std/HashMap.pv"
struct HashMap_str_ref_Include HashMap_str_ref_Include__clone(struct HashMap_str_ref_Include* self, struct trait_Allocator allocator) {
    #line 167 "src/std/HashMap.pv"
    struct HashMap_str_ref_Include other = (struct HashMap_str_ref_Include) {
        .allocator = allocator,
        .buckets = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_str_ref_Include)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 174 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 175 "src/std/HashMap.pv"
    HashMap_str_ref_Include__fill_buckets(&other);

    #line 177 "src/std/HashMap.pv"
    return other;
}

#line 180 "src/std/HashMap.pv"
struct HashMapIter_str_ref_Include HashMap_str_ref_Include__iter(struct HashMap_str_ref_Include* self) {
    #line 181 "src/std/HashMap.pv"
    return (struct HashMapIter_str_ref_Include) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 187 "src/std/HashMap.pv"
void HashMap_str_ref_Include__clear(struct HashMap_str_ref_Include* self) {
    #line 188 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include));
    #line 189 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_ref_Include*));
    #line 190 "src/std/HashMap.pv"
    self->length = 0;
}

#line 196 "src/std/HashMap.pv"
struct HashMapBucket_str_ref_Include* HashMap_str_ref_Include__Index__index(void* __self) {
    struct HashMap_str_ref_Include* self = __self; (void)self;
    #line 197 "src/std/HashMap.pv"
    return self->data;
}

#line 202 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__Map_str_ref_Include__find(void* __self, struct str* key) {
    struct HashMap_str_ref_Include* self = __self; (void)self;
    #line 203 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 203 "src/std/HashMap.pv"
        return 0;
    }

    #line 205 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 206 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 207 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 209 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 210 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(str__Hash__hash(&current_bucket_node->key), hash) && str__Eq_str__eq(current_bucket_node->key, *key)) {
            #line 211 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 213 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 216 "src/std/HashMap.pv"
    return 0;
}

#line 219 "src/std/HashMap.pv"
struct Include** HashMap_str_ref_Include__Map_str_ref_Include__insert(void* __self, struct str key, struct Include* value) {
    struct HashMap_str_ref_Include* self = __self; (void)self;
    #line 220 "src/std/HashMap.pv"
    struct Include** existing_value = HashMap_str_ref_Include__find(self, &key);
    #line 221 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 222 "src/std/HashMap.pv"
        *existing_value = value;
        #line 223 "src/std/HashMap.pv"
        return existing_value;
    }
    #line 228 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 229 "src/std/HashMap.pv"
        HashMap_str_ref_Include__resize(self, 16);
    } else if ((self->length * 100 / self->capacity) > 75) {
        #line 231 "src/std/HashMap.pv"
        HashMap_str_ref_Include__resize(self, self->capacity * 2);
    }

    #line 234 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&key);
    #line 235 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 236 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include** current_bucket_node = self->buckets + bucket_index;

    #line 238 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* bucket_node = *current_bucket_node;
    #line 239 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 240 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 241 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 244 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_ref_Include) { .key = key, .value = value, .next = 0 };
    #line 245 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* data = self->data + self->length;
    #line 246 "src/std/HashMap.pv"
    self->length += 1;

    #line 248 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 250 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 253 "src/std/HashMap.pv"
bool HashMap_str_ref_Include__Map_str_ref_Include__remove(void* __self, struct str* key) {
    struct HashMap_str_ref_Include* self = __self; (void)self;
    #line 254 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 254 "src/std/HashMap.pv"
        return false;
    }

    #line 256 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 257 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 258 "src/std/HashMap.pv"
    struct HashMapBucket_str_ref_Include* current_bucket_node = self->buckets[bucket_index];

    #line 260 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 261 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(str__Hash__hash(&current_bucket_node->key), hash) && str__Eq_str__eq(current_bucket_node->key, *key)) {
            #line 262 "src/std/HashMap.pv"
            struct HashMapBucket_str_ref_Include* last = self->data + self->length - 1;
            #line 263 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 263 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 265 "src/std/HashMap.pv"
            self->length -= 1;
            #line 266 "src/std/HashMap.pv"
            HashMap_str_ref_Include__fill_buckets(self);

            #line 268 "src/std/HashMap.pv"
            return true;
        }

        #line 271 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 274 "src/std/HashMap.pv"
    return false;
}

struct trait_Map_str_ref_IncludeVTable HASH_MAP_STR_REF_INCLUDE__VTABLE__MAP = { .fn_find = &HashMap_str_ref_Include__Map_str_ref_Include__find, .fn_insert = &HashMap_str_ref_Include__Map_str_ref_Include__insert, .fn_remove = &HashMap_str_ref_Include__Map_str_ref_Include__remove };
