#ifndef PAVE_PAIR_I32_REF_VELOCITY
#define PAVE_PAIR_I32_REF_VELOCITY

#include <stdint.h>

struct Velocity;

struct Pair_i32_ref_Velocity {
    int32_t a;
    struct Velocity* b;
};

#endif
