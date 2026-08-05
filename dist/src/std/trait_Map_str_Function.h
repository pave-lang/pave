#ifndef PAVE_TRAIT_MAP_STR_FUNCTION
#define PAVE_TRAIT_MAP_STR_FUNCTION

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/types/Function.h>
struct str;
struct Function;

#line 1 "src/std/Map.pv"
struct trait_Map_str_FunctionVTable {
    #line 2 "src/std/Map.pv"
    struct Function* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Function* (*fn_insert)(void* __self, struct str key, struct Function value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Function {
    const struct trait_Map_str_FunctionVTable* vtable;
    void* instance;
};

#endif
