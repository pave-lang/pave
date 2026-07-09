#ifndef PAVE_TRAIT_MAP_STR_REF_NAMESPACE
#define PAVE_TRAIT_MAP_STR_REF_NAMESPACE

#include <stdbool.h>

#include <std/trait_Map_str_ref_Namespace.h>
#include <std/str.h>
struct str;
struct Namespace;

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_NamespaceVTable {
    #line 2 "src/std/Map.pv"
    struct Namespace** (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Namespace** (*fn_insert)(void* __self, struct str key, struct Namespace* value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_ref_Namespace {
    const struct trait_Map_str_ref_NamespaceVTable* vtable;
    void* instance;
};

#endif
