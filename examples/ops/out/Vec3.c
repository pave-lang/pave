#include <stdio.h>

#include <ops/Vec3.h>
#include <ops/Vec3.h>

#include <ops/Vec3.h>

struct Vec3 Vec3__Mul_f32__mul(struct Vec3 self, float other) {
    return (struct Vec3) { .x = self.x * other, .y = self.y * other, .z = self.z * other };
}

struct Vec3 Vec3__Mul_Vec3__mul(struct Vec3 self, struct Vec3 other) {
    return (struct Vec3) { .x = self.x * other.x, .y = self.y * other.y, .z = self.z * other.z };
}

struct Vec3 Vec3__Add_Vec3__add(struct Vec3 self, struct Vec3 other) {
    return (struct Vec3) { .x = self.x + other.x, .y = self.y + other.y, .z = self.z + other.z };
}

