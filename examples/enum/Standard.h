#ifndef PAVE_STANDARD
#define PAVE_STANDARD

enum Standard {
    STANDARD__ONE,
    STANDARD__TWO,
};

#include <enum/Standard.h>

void Standard__print(enum Standard* self);
#include <std/trait_Enum.h>
extern struct trait_EnumVTable STANDARD__VTABLE__ENUM;

#endif
