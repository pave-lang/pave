#ifndef PAVE_TRAIT_MAP_STR_ARRAY_DIAGNOSTIC
#define PAVE_TRAIT_MAP_STR_ARRAY_DIAGNOSTIC

#include <stdbool.h>

#include <std/trait_Map_str_Array_Diagnostic.h>
#include <std/str.h>
#include <std/Array_Diagnostic.h>
struct str;
struct Array_Diagnostic;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_DiagnosticVTable {
    #line 2 "src/std/Map.pv"
    struct Array_Diagnostic* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_Diagnostic* (*fn_insert)(void* __self, struct str key, struct Array_Diagnostic value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_Diagnostic {
    const struct trait_Map_str_Array_DiagnosticVTable* vtable;
    void* instance;
};

#endif
