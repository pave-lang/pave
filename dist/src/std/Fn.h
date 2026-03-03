#ifndef PAVE_FN
#define PAVE_FN

#include <stdint.h>
#include <stdbool.h>

struct Array_TypeId;
typedef uint64_t TypeId;

#line 1 "src/std/Fn.pv"
struct FnVTable {
    #line 2 "src/std/Fn.pv"
struct Array_TypeId* (*get_params)(void* __self);
    #line 3 "src/std/Fn.pv"
bool (*set_arg)(void* __self, uintptr_t index, void* value);
    #line 4 "src/std/Fn.pv"
void (*execute)(void* __self);
};

#line 1 "src/std/Fn.pv"
struct Fn {
    const struct FnVTable* vtable;
    void* instance;
};

#endif
