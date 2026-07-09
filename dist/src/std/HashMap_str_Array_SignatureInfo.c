#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <std/HashMap_str_Array_SignatureInfo.h>
#include <std/HashMapBucket_str_Array_SignatureInfo.h>
#include <std/Hash.h>
#include <std/trait_Hash.h>
#include <std/str.h>
#include <std/Array_SignatureInfo.h>
#include <std/Range_usize.h>
#include <std/HashMapIter_str_Array_SignatureInfo.h>
#include <std/trait_Map_str_Array_SignatureInfo.h>
#include <std/HashMap_str_Array_SignatureInfo.h>

#include <std/HashMap_str_Array_SignatureInfo.h>

#line 35 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__new(struct trait_Allocator allocator) {
    #line 36 "src/std/HashMap.pv"
    return HashMap_str_Array_SignatureInfo__with_capacity(allocator, 16);
}

#line 39 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__with_capacity(struct trait_Allocator allocator, uintptr_t capacity) {
    #line 40 "src/std/HashMap.pv"
    struct HashMap_str_Array_SignatureInfo self = (struct HashMap_str_Array_SignatureInfo) {
        .allocator = allocator,
        .buckets = 0,
        .data = 0,
        .capacity = 0,
        .length = 0,
    };

    #line 48 "src/std/HashMap.pv"
    HashMap_str_Array_SignatureInfo__resize(&self, capacity);

    #line 50 "src/std/HashMap.pv"
    return self;
}

#line 53 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__resize(struct HashMap_str_Array_SignatureInfo* self, uintptr_t new_capacity) {
    #line 54 "src/std/HashMap.pv"
    self->buckets = self->allocator.vtable->fn_realloc(self->allocator.instance, self->buckets, new_capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo*));
    #line 55 "src/std/HashMap.pv"
    self->data = self->allocator.vtable->fn_realloc(self->allocator.instance, self->data, new_capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo));
    #line 56 "src/std/HashMap.pv"
    self->capacity = new_capacity;
    #line 57 "src/std/HashMap.pv"
    HashMap_str_Array_SignatureInfo__fill_buckets(self);
}

#line 60 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__find(struct HashMap_str_Array_SignatureInfo* self, struct str* key) {
    #line 61 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 61 "src/std/HashMap.pv"
        return 0;
    }

    #line 63 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 64 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 65 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* current_bucket_node = self->buckets[bucket_index];

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
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__insert(struct HashMap_str_Array_SignatureInfo* self, struct str key, struct Array_SignatureInfo value) {
    #line 78 "src/std/HashMap.pv"
    struct Array_SignatureInfo* existing_value = HashMap_str_Array_SignatureInfo__find(self, &key);
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
        HashMap_str_Array_SignatureInfo__resize(self, self->capacity * 2);
    }

    #line 88 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&key);
    #line 89 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 90 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo** current_bucket_node = self->buckets + bucket_index;

    #line 92 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* bucket_node = *current_bucket_node;
    #line 93 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 94 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 95 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 98 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_Array_SignatureInfo) { .key = key, .value = value, .next = 0 };
    #line 99 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* data = self->data + self->length;
    #line 100 "src/std/HashMap.pv"
    self->length += 1;

    #line 102 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 104 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 107 "src/std/HashMap.pv"
bool HashMap_str_Array_SignatureInfo__remove(struct HashMap_str_Array_SignatureInfo* self, struct str* key) {
    #line 108 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 108 "src/std/HashMap.pv"
        return false;
    }

    #line 110 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 111 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 112 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* current_bucket_node = self->buckets[bucket_index];

    #line 114 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 115 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 116 "src/std/HashMap.pv"
            struct HashMapBucket_str_Array_SignatureInfo* last = self->data + self->length - 1;
            #line 117 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 117 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 119 "src/std/HashMap.pv"
            self->length -= 1;
            #line 120 "src/std/HashMap.pv"
            HashMap_str_Array_SignatureInfo__fill_buckets(self);

            #line 122 "src/std/HashMap.pv"
            return true;
        }

        #line 125 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 128 "src/std/HashMap.pv"
    return false;
}

#line 131 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__release(struct HashMap_str_Array_SignatureInfo* self) {
    #line 132 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->buckets);
    #line 133 "src/std/HashMap.pv"
    self->allocator.vtable->fn_free(self->allocator.instance, self->data);
    #line 134 "src/std/HashMap.pv"
    self->buckets = 0;
    #line 135 "src/std/HashMap.pv"
    self->data = 0;
    #line 136 "src/std/HashMap.pv"
    self->capacity = 0;
    #line 137 "src/std/HashMap.pv"
    self->length = 0;
}

#line 140 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__fill_buckets(struct HashMap_str_Array_SignatureInfo* self) {
    #line 141 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo*));

    #line 143 "src/std/HashMap.pv"
    for (uintptr_t i = 0; i < self->length; i++) {
        #line 144 "src/std/HashMap.pv"
        struct HashMapBucket_str_Array_SignatureInfo* node = self->data + i;
        #line 145 "src/std/HashMap.pv"
        if (node == 0) {
            #line 145 "src/std/HashMap.pv"
            return;
        }
        #line 146 "src/std/HashMap.pv"
        node->next = 0;
        #line 147 "src/std/HashMap.pv"
        Hash hash = str__Hash__hash(&(*node).key);
        #line 148 "src/std/HashMap.pv"
        uintptr_t bucket_index = hash % self->capacity;
        #line 149 "src/std/HashMap.pv"
        struct HashMapBucket_str_Array_SignatureInfo** current_bucket_node = self->buckets + bucket_index;

        #line 151 "src/std/HashMap.pv"
        struct HashMapBucket_str_Array_SignatureInfo* bucket_node = *current_bucket_node;
        #line 152 "src/std/HashMap.pv"
        while (bucket_node != 0) {
            #line 153 "src/std/HashMap.pv"
            current_bucket_node = &bucket_node->next;
            #line 154 "src/std/HashMap.pv"
            bucket_node = *current_bucket_node;
        }

        #line 157 "src/std/HashMap.pv"
        *current_bucket_node = node;
    }
}

#line 161 "src/std/HashMap.pv"
struct HashMap_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__clone(struct HashMap_str_Array_SignatureInfo* self, struct trait_Allocator allocator) {
    #line 162 "src/std/HashMap.pv"
    struct HashMap_str_Array_SignatureInfo other = (struct HashMap_str_Array_SignatureInfo) {
        .allocator = allocator,
        .buckets = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(self->data)),
        .data = allocator.vtable->fn_alloc(allocator.instance, self->capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo)),
        .length = self->length,
        .capacity = self->capacity,
    };
    #line 169 "src/std/HashMap.pv"
    memcpy(other.data, self->data, self->capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo));
    #line 170 "src/std/HashMap.pv"
    HashMap_str_Array_SignatureInfo__fill_buckets(&other);

    #line 172 "src/std/HashMap.pv"
    return other;
}

#line 175 "src/std/HashMap.pv"
struct HashMapIter_str_Array_SignatureInfo HashMap_str_Array_SignatureInfo__iter(struct HashMap_str_Array_SignatureInfo* self) {
    #line 176 "src/std/HashMap.pv"
    return (struct HashMapIter_str_Array_SignatureInfo) {
        .iter = self->data - 1,
        .end = self->data + self->length,
    };
}

#line 182 "src/std/HashMap.pv"
void HashMap_str_Array_SignatureInfo__clear(struct HashMap_str_Array_SignatureInfo* self) {
    #line 183 "src/std/HashMap.pv"
    memset(self->data, 0, self->capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo));
    #line 184 "src/std/HashMap.pv"
    memset(self->buckets, 0, self->capacity * sizeof(struct HashMapBucket_str_Array_SignatureInfo*));
    #line 185 "src/std/HashMap.pv"
    self->length = 0;
}

#line 191 "src/std/HashMap.pv"
struct HashMapBucket_str_Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Index__index(void* __self) {
    struct HashMap_str_Array_SignatureInfo* self = __self; (void)self;
    #line 192 "src/std/HashMap.pv"
    return self->data;
}

#line 197 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__find(void* __self, struct str* key) {
    struct HashMap_str_Array_SignatureInfo* self = __self; (void)self;
    #line 198 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 198 "src/std/HashMap.pv"
        return 0;
    }

    #line 200 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 201 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 202 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* current_bucket_node = self->buckets[bucket_index];

    #line 204 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 205 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 206 "src/std/HashMap.pv"
            return &current_bucket_node->value;
        }
        #line 208 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 211 "src/std/HashMap.pv"
    return 0;
}

#line 214 "src/std/HashMap.pv"
struct Array_SignatureInfo* HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__insert(void* __self, struct str key, struct Array_SignatureInfo value) {
    struct HashMap_str_Array_SignatureInfo* self = __self; (void)self;
    #line 215 "src/std/HashMap.pv"
    struct Array_SignatureInfo* existing_value = HashMap_str_Array_SignatureInfo__find(self, &key);
    #line 216 "src/std/HashMap.pv"
    if (existing_value != 0) {
        #line 217 "src/std/HashMap.pv"
        *existing_value = value;
        #line 218 "src/std/HashMap.pv"
        return existing_value;
    }

    #line 221 "src/std/HashMap.pv"
    if (self->capacity == 0 || (self->length * 100 / self->capacity) > 75) {
        #line 222 "src/std/HashMap.pv"
        HashMap_str_Array_SignatureInfo__resize(self, self->capacity * 2);
    }

    #line 225 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&key);
    #line 226 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 227 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo** current_bucket_node = self->buckets + bucket_index;

    #line 229 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* bucket_node = *current_bucket_node;
    #line 230 "src/std/HashMap.pv"
    while (bucket_node != 0) {
        #line 231 "src/std/HashMap.pv"
        current_bucket_node = &bucket_node->next;
        #line 232 "src/std/HashMap.pv"
        bucket_node = *current_bucket_node;
    }

    #line 235 "src/std/HashMap.pv"
    self->data[self->length] = (struct HashMapBucket_str_Array_SignatureInfo) { .key = key, .value = value, .next = 0 };
    #line 236 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* data = self->data + self->length;
    #line 237 "src/std/HashMap.pv"
    self->length += 1;

    #line 239 "src/std/HashMap.pv"
    *current_bucket_node = data;

    #line 241 "src/std/HashMap.pv"
    return &(*data).value;
}

#line 244 "src/std/HashMap.pv"
bool HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__remove(void* __self, struct str* key) {
    struct HashMap_str_Array_SignatureInfo* self = __self; (void)self;
    #line 245 "src/std/HashMap.pv"
    if (self->capacity == 0) {
        #line 245 "src/std/HashMap.pv"
        return false;
    }

    #line 247 "src/std/HashMap.pv"
    Hash hash = str__Hash__hash(&(*key));
    #line 248 "src/std/HashMap.pv"
    uintptr_t bucket_index = hash % self->capacity;
    #line 249 "src/std/HashMap.pv"
    struct HashMapBucket_str_Array_SignatureInfo* current_bucket_node = self->buckets[bucket_index];

    #line 251 "src/std/HashMap.pv"
    while (current_bucket_node != 0) {
        #line 252 "src/std/HashMap.pv"
        if (str__Hash__hash(&current_bucket_node->key) == hash) {
            #line 253 "src/std/HashMap.pv"
            struct HashMapBucket_str_Array_SignatureInfo* last = self->data + self->length - 1;
            #line 254 "src/std/HashMap.pv"
            if (current_bucket_node != last) {
                #line 254 "src/std/HashMap.pv"
                *current_bucket_node = *last;
            }

            #line 256 "src/std/HashMap.pv"
            self->length -= 1;
            #line 257 "src/std/HashMap.pv"
            HashMap_str_Array_SignatureInfo__fill_buckets(self);

            #line 259 "src/std/HashMap.pv"
            return true;
        }

        #line 262 "src/std/HashMap.pv"
        current_bucket_node = current_bucket_node->next;
    }

    #line 265 "src/std/HashMap.pv"
    return false;
}

struct trait_Map_str_Array_SignatureInfoVTable HASH_MAP_STR_ARRAY_SIGNATURE_INFO__VTABLE__MAP = { .fn_find = &HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__find, .fn_insert = &HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__insert, .fn_remove = &HashMap_str_Array_SignatureInfo__Map_str_Array_SignatureInfo__remove };
