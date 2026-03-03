#include <std/Array_Object.h>
#include <dynamic_fn/Object.h>
#include <std/Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <stdint.h>
#include <dynamic_fn/Position.h>
#include <std/Fn.h>
#include <slice_Object.h>
#include <dynamic_fn/Time.h>
#include <dynamic_fn/Physics.h>
#include <dynamic_fn/run.h>

#include <dynamic_fn/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Array_Object objects = Array_Object__new((struct Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    Array_Object__append(&objects, (struct Object) { .position = (struct Position) { .x = 0.0f, .y = 3.0f } });
    Array_Object__append(&objects, (struct Object) { .position = (struct Position) { .x = 2.0f, .y = 1.0f } });
    Array_Object__append(&objects, (struct Object) { .position = (struct Position) { .x = 3.0f, .y = 7.0f } });

    run((struct Fn) { .vtable = &PHYSICS__APPLY_PHYSICS__VTABLE__DYN_FN, .instance = &(struct Physics__apply_physics__Fn__Instance) {} }, Array_Object__as_slice(&objects), (struct Time) { .delta = 0.16f }, (struct Physics) { .gravity = -9.81f });

    return 0;
}
