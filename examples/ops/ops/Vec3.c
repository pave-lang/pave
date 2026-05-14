#include <stdio.h>

#include <ops/Vec3.h>
#include <std/trait_Mul_Vec3_Vec3.h>
#include <std/trait_Add_Vec3_Vec3.h>
#include <ops/Vec3.h>

#include <ops/Vec3.h>

struct Vec3 Vec3__Mul_f32__mul(void* __self, float other) {
    struct Vec3* self = __self; (void)self;
    return (struct Vec3) { .x = self->x * other, .y = self->y * other, .z = self->z * other };
}

struct Vec3 Vec3__Mul_Vec3__mul(void* __self, struct Vec3 other) {
    struct Vec3* self = __self; (void)self;
    return (struct Vec3) { .x = self->x * other.x, .y = self->y * other.y, .z = self->z * other.z };
}

struct Vec3 Vec3__Add_Vec3__add(void* __self, struct Vec3 other) {
    struct Vec3* self = __self; (void)self;
    return (struct Vec3) { .x = self->x + other.x, .y = self->y + other.y, .z = self->z + other.z };
}

struct trait_Mul_Vec3_Vec3VTable VEC3__VTABLE__MUL = { .mul = &Vec3__Mul_Vec3__mul };
struct trait_Add_Vec3_Vec3VTable VEC3__VTABLE__ADD = { .add = &Vec3__Add_Vec3__add };
