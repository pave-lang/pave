#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMapBucket_usize_TypeFunctionUsage.h>
#include <usize.h>
#include <std/Hash.h>
#include <std/trait_Hash.h>
#include <u64.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>

#include <std/HashMap_usize_TypeFunctionUsage.h>

#line 36 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__new(struct trait_Allocator allocator) {
    #line 37 "src/std/HashMap.pv"
    return HashMap_usize_TypeFunctionUsage__with_capacity(allocator, 16);
}

#line 40 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__with_capacity(struct trait_Allocator allocator, uintptr_t capacity) {
    #line 41 "src/std/HashMap.pv"
    struct HashMap_usize_TypeFunctionUsage self = (struct HashMap_usize_TypeFunctionUsage) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 49 "src/std/HashMap.pv"
    HashMap_usize_TypeFunctionUsage__resize(&self, capacity);

    #line 51 "src/std/HashMap.pv"
    return self;
}

#line 54 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__resize(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t new_capacity) {
    #line 55 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->fn_realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage*));
    #line 56 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->fn_realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage));
    #line 57 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 58 "src/std/HashMap.pv"
    HashMap_usize_TypeFunctionUsage__fill_buckets(self);
}

#line 61 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__find(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key) {
    #line 62 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 62 "src/std/HashMap.pv"
        return 0;
    }

    #line 64 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&(*key));
    #line 65 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 66 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* current_bucket_node = self->buckets[bucket_index];

    #line 68 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 69 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(usize__Hash__hash(&current_bucket_node->key), hash) && usize__Eq_usize__eq(current_bucket_node->key, *key)) {
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
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__insert(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t key, struct TypeFunctionUsage value) {
    #line 79 "src/std/HashMap.pv"
    struct TypeFunctionUsage* existing_value = HashMap_usize_TypeFunctionUsage__find(self, &key);
    #line 80 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 81 "src/std/HashMap.pv"
        *existing_value = value;
        #line 82 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 85 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0) || (self->length * 100 / self->capacity) > 75) {
        #line 86 "src/std/HashMap.pv"
        HashMap_usize_TypeFunctionUsage__resize(self, self->capacity * 2);
    }

    #line 89 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&key);
    #line 90 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 91 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage** current_bucket_node = self->buckets + bucket_index;

    #line 93 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* bucket_node = *current_bucket_node;
    #line 94 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 95 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 96 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 99 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_usize_TypeFunctionUsage) { .key = key, .value = value, .next = 0 };
    #line 100 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* data = self->data + self->length;
    #line 101 "src/std/HashMap.pv"
    self->length += 1;

    #line 103 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 105 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 108 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__remove(struct HashMap_usize_TypeFunctionUsage* self, uintptr_t* key) {
    #line 109 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 109 "src/std/HashMap.pv"
        return false;
    }

    #line 111 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&(*key));
    #line 112 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 113 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* current_bucket_node = self->buckets[bucket_index];

    #line 115 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 116 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(usize__Hash__hash(&current_bucket_node->key), hash) && usize__Eq_usize__eq(current_bucket_node->key, *key)) {
            #line 117 "src/std/HashMap.pv"
            struct HashMapBucket_usize_TypeFunctionUsage* last = self->data + self->length - 1;
            #line 118 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 118 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 120 "src/std/HashMap.pv"
            self->length -= 1;
            #line 121 "src/std/HashMap.pv"
            HashMap_usize_TypeFunctionUsage__fill_buckets(self);

            #line 123 "src/std/HashMap.pv"
            return true;
        }

        #line 126 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 129 "src/std/HashMap.pv"
    return false;
}

#line 132 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__release(struct HashMap_usize_TypeFunctionUsage* self) {
    #line 133 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->buckets);
    #line 134 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->data);
    #line 135 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 136 "src/std/HashMap.pv"
    self->data = 0;
    #line 137 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 138 "src/std/HashMap.pv"
    self->length = 0;
}

#line 141 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__fill_buckets(struct HashMap_usize_TypeFunctionUsage* self) {
    #line 142 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage*));

    #line 144 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i != self->length; i < self->length ? i++ : i--) {
        #line 145 "src/std/HashMap.pv"
        struct HashMapBucket_usize_TypeFunctionUsage* node = self->data + i;
        #line 146 "src/std/HashMap.pv"
        if (node == 0) {
            #line 146 "src/std/HashMap.pv"
            return;
        }
        #line 147 "src/std/HashMap.pv"
        node->next = 0;
        #line 148 "src/std/HashMap.pv"
        Hash hash = usize__Hash__hash(&(*node).key);
        #line 149 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 150 "src/std/HashMap.pv"
        struct HashMapBucket_usize_TypeFunctionUsage** current_bucket_node = self->buckets + bucket_index;

        #line 152 "src/std/HashMap.pv"
        struct HashMapBucket_usize_TypeFunctionUsage* bucket_node = *current_bucket_node;
        #line 153 "src/std/HashMap.pv"
        while (bucket_node != 0) {
            #line 154 "src/std/HashMap.pv"
            current_bucket_node = &bucket_node->next;
            #line 155 "src/std/HashMap.pv"
            bucket_node = *current_bucket_node;
        }

        #line 158 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 162 "src/std/HashMap.pv"
struct HashMap_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__clone(struct HashMap_usize_TypeFunctionUsage* self, struct trait_Allocator allocator) {
    #line 163 "src/std/HashMap.pv"
    struct HashMap_usize_TypeFunctionUsage other = (struct HashMap_usize_TypeFunctionUsage) {
        .allocator = allocator,
        .buckets = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 170 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage));
    #line 171 "src/std/HashMap.pv"
    HashMap_usize_TypeFunctionUsage__fill_buckets(&other);

    #line 173 "src/std/HashMap.pv"
    return other;
}

#line 176 "src/std/HashMap.pv"
struct HashMapIter_usize_TypeFunctionUsage HashMap_usize_TypeFunctionUsage__iter(struct HashMap_usize_TypeFunctionUsage* self) {
    #line 177 "src/std/HashMap.pv"
    return (struct HashMapIter_usize_TypeFunctionUsage) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 183 "src/std/HashMap.pv"
void HashMap_usize_TypeFunctionUsage__clear(struct HashMap_usize_TypeFunctionUsage* self) {
    #line 184 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage));
    #line 185 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_usize_TypeFunctionUsage*));
    #line 186 "src/std/HashMap.pv"
    self->length = 0;
}

#line 192 "src/std/HashMap.pv"
struct HashMapBucket_usize_TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Index__index(void* __self) {
    struct HashMap_usize_TypeFunctionUsage* self = __self; (void)self;
    #line 193 "src/std/HashMap.pv"
    return self->data;
}

#line 198 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__find(void* __self, uintptr_t* key) {
    struct HashMap_usize_TypeFunctionUsage* self = __self; (void)self;
    #line 199 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 199 "src/std/HashMap.pv"
        return 0;
    }

    #line 201 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&(*key));
    #line 202 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 203 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* current_bucket_node = self->buckets[bucket_index];

    #line 205 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 206 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(usize__Hash__hash(&current_bucket_node->key), hash) && usize__Eq_usize__eq(current_bucket_node->key, *key)) {
            #line 207 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 209 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 212 "src/std/HashMap.pv"
    return 0;
}

#line 215 "src/std/HashMap.pv"
struct TypeFunctionUsage* HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__insert(void* __self, uintptr_t key, struct TypeFunctionUsage value) {
    struct HashMap_usize_TypeFunctionUsage* self = __self; (void)self;
    #line 216 "src/std/HashMap.pv"
    struct TypeFunctionUsage* existing_value = HashMap_usize_TypeFunctionUsage__find(self, &key);
    #line 217 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 218 "src/std/HashMap.pv"
        *existing_value = value;
        #line 219 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 222 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0) || (self->length * 100 / self->capacity) > 75) {
        #line 223 "src/std/HashMap.pv"
        HashMap_usize_TypeFunctionUsage__resize(self, self->capacity * 2);
    }

    #line 226 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&key);
    #line 227 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 228 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage** current_bucket_node = self->buckets + bucket_index;

    #line 230 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* bucket_node = *current_bucket_node;
    #line 231 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 232 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 233 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 236 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_usize_TypeFunctionUsage) { .key = key, .value = value, .next = 0 };
    #line 237 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* data = self->data + self->length;
    #line 238 "src/std/HashMap.pv"
    self->length += 1;

    #line 240 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 242 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 245 "src/std/HashMap.pv"
bool HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__remove(void* __self, uintptr_t* key) {
    struct HashMap_usize_TypeFunctionUsage* self = __self; (void)self;
    #line 246 "src/std/HashMap.pv"
    if (usize__Eq_usize__eq(self->capacity, 0)) {
        #line 246 "src/std/HashMap.pv"
        return false;
    }

    #line 248 "src/std/HashMap.pv"
    Hash hash = usize__Hash__hash(&(*key));
    #line 249 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 250 "src/std/HashMap.pv"
    struct HashMapBucket_usize_TypeFunctionUsage* current_bucket_node = self->buckets[bucket_index];

    #line 252 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 253 "src/std/HashMap.pv"
        if (u64__Eq_u64__eq(usize__Hash__hash(&current_bucket_node->key), hash) && usize__Eq_usize__eq(current_bucket_node->key, *key)) {
            #line 254 "src/std/HashMap.pv"
            struct HashMapBucket_usize_TypeFunctionUsage* last = self->data + self->length - 1;
            #line 255 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 255 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 257 "src/std/HashMap.pv"
            self->length -= 1;
            #line 258 "src/std/HashMap.pv"
            HashMap_usize_TypeFunctionUsage__fill_buckets(self);

            #line 260 "src/std/HashMap.pv"
            return true;
        }

        #line 263 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 266 "src/std/HashMap.pv"
    return false;
}

struct trait_Map_usize_TypeFunctionUsageVTable HASH_MAP_USIZE_TYPE_FUNCTION_USAGE__VTABLE__MAP = { .fn_find = &HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__find, .fn_insert = &HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__insert, .fn_remove = &HashMap_usize_TypeFunctionUsage__Map_usize_TypeFunctionUsage__remove };
