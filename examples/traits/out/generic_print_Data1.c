#include <stdio.h>

#include <traits/Data1.h>

#include <traits/generic_print_Data1.h>

void generic_print_Data1(struct Data1* data) {
    Data1__Print__print(data);
}
