#ifndef PAVE_TRAIT_ITERATOR
#define PAVE_TRAIT_ITERATOR

#include <stdbool.h>

#include <std/trait_Iterator.h>
#line 1 "src/std/Iterator.pv"
struct trait_IteratorVTable {
    #line 2 "src/std/Iterator.pv"
bool (*next)(void* __self);
};

#line 1 "src/std/Iterator.pv"
struct trait_Iterator {
    const struct trait_IteratorVTable* vtable;
    void* instance;
};

#endif
