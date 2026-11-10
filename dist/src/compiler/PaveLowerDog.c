#include <stdlib.h>

#include <compiler/PaveLowerDog.h>

#include <compiler/PaveLowerDog.h>

#line 31 "src/compiler/LoweringTest.pv"
int32_t PaveLowerDog__PaveLowerSpeak__speak(void* __self) {
    struct PaveLowerDog* self = __self; (void)self;
    #line 31 "src/compiler/LoweringTest.pv"
    return self->volume;
}

struct trait_PaveLowerSpeakVTable PAVE_LOWER_DOG__VTABLE__PAVE_LOWER_SPEAK = { .fn_speak = &PaveLowerDog__PaveLowerSpeak__speak };
