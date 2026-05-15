#ifndef PAVE_VEC3
#define PAVE_VEC3

struct Vec3 {
    float x;
    float y;
    float z;
};

#include <ops/Vec3.h>

struct Vec3 Vec3__Mul_f32__mul(struct Vec3 self, float other);

struct Vec3 Vec3__Mul_Vec3__mul(struct Vec3 self, struct Vec3 other);

struct Vec3 Vec3__Add_Vec3__add(struct Vec3 self, struct Vec3 other);


#endif
