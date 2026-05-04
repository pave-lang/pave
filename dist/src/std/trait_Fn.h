#ifndef PAVE_TRAIT_FN
#define PAVE_TRAIT_FN

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Fn.h>
struct Array_TypeId;

#line 1 "src/std/Fn.pv"
struct trait_FnVTable {
        #line 2 "src/std/Fn.pv"
struct Array_TypeId* (*get_params)(void* __self);
        #line 3 "src/std/Fn.pv"
bool (*set_arg)(void* __self, uintptr_t index, void* value);
        #line 4 "src/std/Fn.pv"
void (*execute)(void* __self);
};

#line 1 "src/std/Fn.pv"
struct trait_Fn {
    const struct trait_FnVTable* vtable;
    void* instance;
};

#endif
