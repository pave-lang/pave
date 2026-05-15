#include <stdio.h>

#include <stdio.h>
#include <ops/Vec3.h>
#include <f32.h>
#include <ops/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Vec3 pos = (struct Vec3) { .x = 1.0f, .y = 0.5f, .z = 2.0f };
    struct Vec3 scaled = Vec3__Mul_f32__mul(pos, 2.0f);
    struct Vec3 sum = Vec3__Add_Vec3__add(pos, scaled);
    struct Vec3 hadamard = Vec3__Mul_Vec3__mul(pos, scaled);
    struct Vec3 chained = Vec3__Mul_f32__mul(Vec3__Mul_f32__mul(pos, 2.0f), 2.0f);
    struct Vec3 scalar_mul = f32__Mul_Vec3__mul(2.0f, pos);

    printf("scaled: %.1f %.1f %.1f\n", scaled.x, scaled.y, scaled.z);
    printf("sum: %.1f %.1f %.1f\n", sum.x, sum.y, sum.z);
    printf("hadamard: %.1f %.1f %.1f\n", hadamard.x, hadamard.y, hadamard.z);
    printf("chained: %.1f %.1f %.1f\n", chained.x, chained.y, chained.z);
    printf("scalar_mul: %.1f %.1f %.1f\n", scalar_mul.x, scalar_mul.y, scalar_mul.z);

    return 0;
}
