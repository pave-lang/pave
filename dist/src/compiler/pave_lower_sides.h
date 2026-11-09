#ifndef PAVE_PAVE_LOWER_SIDES
#define PAVE_PAVE_LOWER_SIDES

#include <stdint.h>

#include <compiler/PaveLowerShape.h>
struct pave_lower_sides {
    int32_t _state;
    int32_t _value;

    struct PaveLowerShape shape;
    int32_t w;
    int32_t h;
};

#include <std/trait_Iter_i32.h>
int32_t pave_lower_sides__value(void* ctx);
extern struct trait_Iter_i32VTable pave_lower_sides__VTABLE__ITER;
#line 83 "src/compiler/LoweringTest.pv"
bool pave_lower_sides__next(void* _ctx);

#endif
