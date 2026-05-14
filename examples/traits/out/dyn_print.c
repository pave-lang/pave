#include <stdio.h>

#include <traits/trait_Print.h>
#include <traits/dyn_print.h>

void dyn_print(struct trait_Print data) {
    data.vtable->print(data.instance);
}
