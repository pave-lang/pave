#ifndef PAVE_TRAIT_MAP_STR_ARRAY_INLAY_HINT
#define PAVE_TRAIT_MAP_STR_ARRAY_INLAY_HINT

#include <stdbool.h>

#include <std/trait_Map_str_Array_InlayHint.h>
#include <std/str.h>
#include <std/Array_InlayHint.h>
struct str;
struct Array_InlayHint;

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_InlayHintVTable {
    #line 2 "src/std/Map.pv"
    struct Array_InlayHint* (*fn_find)(void* __self, struct str* key);
    #line 3 "src/std/Map.pv"
    struct Array_InlayHint* (*fn_insert)(void* __self, struct str key, struct Array_InlayHint value);
    #line 4 "src/std/Map.pv"
    bool (*fn_remove)(void* __self, struct str* key);
};

#line 1 "src/std/Map.pv"
struct trait_Map_str_Array_InlayHint {
    const struct trait_Map_str_Array_InlayHintVTable* vtable;
    void* instance;
};

#endif
