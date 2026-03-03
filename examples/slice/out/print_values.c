#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <std/ArrayIter_ref_f32.h>
#include <slice_f32.h>

#include <slice/print_values.h>

void print_values(struct slice_f32 values) {
    printf("Values: ");

    { struct ArrayIter_ref_f32 __iter = slice_f32__iter(values);
    while (ArrayIter_ref_f32__next(&__iter)) {
        float* value = ArrayIter_ref_f32__value(&__iter);

        printf("%f", value);
    } }

    printf("\n");
}
