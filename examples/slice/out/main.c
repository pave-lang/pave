#include <stdio.h>
#include <stdlib.h>

#include <slice_f32.h>
#include <slice/print_values.h>
#include <std/Array_f32.h>
#include <std/Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <stdint.h>
#include <slice_void.h>

#include <slice/main.h>

int32_t main(int32_t argc, char const** argv) {
    float values_fixed_array[3] = {0.5f, 1.5f, 2.5f};
    print_values((struct slice_f32) { .data = values_fixed_array, .length = 3 });

    struct Array_f32 values_array = Array_f32__new((struct Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() });
    Array_f32__append(&values_array, 2.5f);
    Array_f32__append(&values_array, 1.5f);
    Array_f32__append(&values_array, 0.5f);
    Array_f32__append(&values_array, 1.0f);
    print_values(Array_f32__as_slice(&values_array));
    Array_f32__release(&values_array);

    void* values_data = malloc(3 * sizeof(float));
    values_data[0] = 1.0f;
    values_data[1] = 0.5f;
    values_data[2] = 3.5f;
    print_values((struct slice_void) { .data = values_data + 0, .length = 3 - 0 });
    free(values_data);

    return 0;
}
