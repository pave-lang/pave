#include <stdio.h>

#include <traits/Data1.h>
#include <stdint.h>
#include <traits/Data2.h>
#include <traits/Print.h>
#include <traits/dyn_print.h>
#include <traits/generic_print_Data1.h>
#include <traits/generic_print_Data2.h>

#include <traits/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Data1 data1 = (struct Data1) { .a = 2.0f, .b = 1 };
    struct Data2 data2 = (struct Data2) { .a = 5.0f, .b = 2 };

    dyn_print((struct Print) { .vtable = &DATA1__VTABLE__PRINT, .instance = &data1 });
    dyn_print((struct Print) { .vtable = &DATA2__VTABLE__PRINT, .instance = &data2 });

    generic_print_Data1(&data1);
    generic_print_Data2(&data2);
}
