#ifndef PAVE_PAVE_LOWER_DOG
#define PAVE_PAVE_LOWER_DOG

#include <stdint.h>

#line 28 "src/compiler/LoweringTest.pv"
struct PaveLowerDog {
    int32_t volume;
};

#include <compiler/trait_PaveLowerSpeak.h>

#line 31 "src/compiler/LoweringTest.pv"
int32_t PaveLowerDog__PaveLowerSpeak__speak(void* __self);

extern struct trait_PaveLowerSpeakVTable PAVE_LOWER_DOG__VTABLE__PAVE_LOWER_SPEAK;

#endif
