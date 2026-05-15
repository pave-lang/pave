#include <stdio.h>

#include <stdio.h>
#include <ops/Vec3.h>
#include <f32.h>
#include <ops/Quat.h>
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
    struct Quat rot_y90 = (struct Quat) { .w = 0.7071f, .x = 0.0f, .y = 0.7071f, .z = 0.0f };
    struct Vec3 rotated = Quat__Mul_Vec3__mul(rot_y90, pos);
    struct Vec3 chained_rot = Quat__Mul_Vec3__mul(rot_y90, (Quat__Mul_Vec3__mul(rot_y90, pos)));
    struct Quat double_rot = Quat__Mul_Quat__mul(rot_y90, rot_y90);
    struct Vec3 double_rotated = Quat__Mul_Vec3__mul(double_rot, pos);
    struct Quat quat_sum = Quat__Add_Quat__add(rot_y90, rot_y90);

    printf("rotated (90 around Y): %.2f %.2f %.2f\n", rotated.x, rotated.y, rotated.z);
    printf("chained_rot (180 around Y): %.2f %.2f %.2f\n", chained_rot.x, chained_rot.y, chained_rot.z);
    printf("double_rotated (180 around Y): %.2f %.2f %.2f\n", double_rotated.x, double_rotated.y, double_rotated.z);
    printf("quat_sum: %.2f %.2f %.2f %.2f\n", quat_sum.w, quat_sum.x, quat_sum.y, quat_sum.z);

    return 0;
}
