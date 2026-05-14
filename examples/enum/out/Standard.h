#ifndef PAVE_STANDARD
#define PAVE_STANDARD

enum Standard {
    STANDARD__ONE,
    STANDARD__TWO,
};

#include <enum/Standard.h>

void Standard__print(enum Standard* self);

#endif
