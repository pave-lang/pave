#include <structs/KeyValue_i32_f32.h>
#include <structs/KeyValue_f32_i32.h>
#include <structs/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct KeyValue_i32_f32 a = (struct KeyValue_i32_f32) { .key = 1, .value = 20.0f };

    float key = 0.5f;
    int32_t value = 2;

    struct KeyValue_f32_i32 b = (struct KeyValue_f32_i32) { .key = key, .value = value };

    return 0;
}
