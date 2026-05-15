#include <stdio.h>

#include <ops/Quat.h>
#include <ops/Vec3.h>
#include <ops/Quat.h>

#include <ops/Quat.h>

struct Quat Quat__Mul_Quat__mul(struct Quat self, struct Quat other) {
    return (struct Quat) {
        .w = self.w * other.w - self.x * other.x - self.y * other.y - self.z * other.z,
        .x = self.w * other.x + self.x * other.w + self.y * other.z - self.z * other.y,
        .y = self.w * other.y - self.x * other.z + self.y * other.w + self.z * other.x,
        .z = self.w * other.z + self.x * other.y - self.y * other.x + self.z * other.w,
    };
}

struct Vec3 Quat__Mul_Vec3__mul(struct Quat self, struct Vec3 other) {
    float tx = 2.0f * (self.y * other.z - self.z * other.y);
    float ty = 2.0f * (self.z * other.x - self.x * other.z);
    float tz = 2.0f * (self.x * other.y - self.y * other.x);
    return (struct Vec3) {
        .x = other.x + self.w * tx + self.y * tz - self.z * ty,
        .y = other.y + self.w * ty + self.z * tx - self.x * tz,
        .z = other.z + self.w * tz + self.x * ty - self.y * tx,
    };
}

struct Quat Quat__Add_Quat__add(struct Quat self, struct Quat other) {
    return (struct Quat) { .w = self.w + other.w, .x = self.x + other.x, .y = self.y + other.y, .z = self.z + other.z };
}

