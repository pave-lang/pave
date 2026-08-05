#ifndef PAVE_TRAIT_MAP_STR_I64
#define PAVE_TRAIT_MAP_STR_I64

#include <stdint.h>
#include <stdbool.h>

#include <std/str.h>
struct str;

#line 1 "src/std/Map.pv"
struct trait_Map_str_i64VTable {
    #line 2 "src/std/Map.pv"
    int64_t* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    int64_t* (*fn_insert)(void* __self, struct str key, int64_t value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_i64 {
    const struct trait_Map_str_i64VTable* vtable;
    void* instance;
};

#endif
