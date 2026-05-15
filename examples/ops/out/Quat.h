#ifndef PAVE_QUAT
#define PAVE_QUAT

struct Quat {
    float w;
    float x;
    float y;
    float z;
};

#include <ops/Quat.h>
#include <ops/Vec3.h>

struct Quat Quat__Mul_Quat__mul(struct Quat self, struct Quat other);

struct Vec3 Quat__Mul_Vec3__mul(struct Quat self, struct Vec3 other);

struct Quat Quat__Add_Quat__add(struct Quat self, struct Quat other);


#endif
