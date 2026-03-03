#ifndef PAVE_DYN_FN
#define PAVE_DYN_FN

#include <stdint.h>
#include <stdbool.h>

struct Array_TypeId;
typedef uint64_t TypeId;

#line 1 "src/std/DynFn.pv"
struct DynFnVTable {
    #line 2 "src/std/DynFn.pv"
struct Array_TypeId* (*get_params)(void* __self);
    #line 3 "src/std/DynFn.pv"
bool (*set_arg)(void* __self, uintptr_t index, void* value);
    #line 4 "src/std/DynFn.pv"
void (*execute)(void* __self);
};

#line 1 "src/std/DynFn.pv"
struct DynFn {
    const struct DynFnVTable* vtable;
    void* instance;
};

#endif
