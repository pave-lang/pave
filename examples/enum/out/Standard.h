#ifndef PAVE_STANDARD
#define PAVE_STANDARD

#include <stdio.h>

enum Standard {
    STANDARD__ONE,
    STANDARD__TWO,
};

void Standard__print(enum Standard* self);

#endif
