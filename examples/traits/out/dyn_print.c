#include <stdio.h>

#include <traits/Print.h>

#include <traits/dyn_print.h>

void dyn_print(struct Print data) {
    data.vtable->print(data.instance);
}
