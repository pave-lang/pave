#ifndef PAVE_ITERATOR
#define PAVE_ITERATOR

#include <stdbool.h>

#line 1 "src/std/Iterator.pv"
struct IteratorVTable {
    #line 2 "src/std/Iterator.pv"
bool (*next)(void* __self);
};

#line 1 "src/std/Iterator.pv"
struct Iterator {
    const struct IteratorVTable* vtable;
    void* instance;
};

#endif
