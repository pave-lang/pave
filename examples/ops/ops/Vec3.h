#ifndef PAVE_VEC3
#define PAVE_VEC3

struct Vec3 {
    float x;
    float y;
    float z;
};

#include <std/trait_Mul_f32_Vec3.h>
#include <ops/Vec3.h>
struct Vec3;

struct Vec3 Vec3__Mul_f32__mul(void* __self, float other);

struct Vec3 Vec3__Mul_Vec3__mul(void* __self, struct Vec3 other);

struct Vec3 Vec3__Add_Vec3__add(void* __self, struct Vec3 other);

extern struct trait_Mul_Vec3_Vec3VTable VEC3__VTABLE__MUL;
extern struct trait_Add_Vec3_Vec3VTable VEC3__VTABLE__ADD;

#endif
