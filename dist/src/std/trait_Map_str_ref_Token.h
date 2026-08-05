#ifndef PAVE_TRAIT_MAP_STR_REF_TOKEN
#define PAVE_TRAIT_MAP_STR_REF_TOKEN

#include <stdbool.h>

#include <std/str.h>
struct str;
struct Token;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_TokenVTable {
    #line 2 "src/std/Map.pv"
    struct Token** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Token** (*fn_insert)(void* __self, struct str key, struct Token* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_Token {
    const struct trait_Map_str_ref_TokenVTable* vtable;
    void* instance;
};

#endif
