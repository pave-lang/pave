#ifndef PAVE_DISCRIMINATED
#define PAVE_DISCRIMINATED

#include <stdint.h>

struct Discriminated {
    enum {
        DISCRIMINATED__NONE,
        DISCRIMINATED__SINGLE,
        DISCRIMINATED__DUAL,
    } type;

    union {
        int32_t single_value;
        struct { int32_t _0; int32_t _1; } dual_value;
    };
};

struct Discriminated;

void Discriminated__print(struct Discriminated* self);

#endif
