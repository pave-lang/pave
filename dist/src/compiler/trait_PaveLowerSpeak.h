#ifndef PAVE_TRAIT_PAVE_LOWER_SPEAK
#define PAVE_TRAIT_PAVE_LOWER_SPEAK

#include <stdint.h>


#line 26 "src/compiler/LoweringTest.pv"
struct trait_PaveLowerSpeakVTable {
    #line 26 "src/compiler/LoweringTest.pv"
    int32_t (*fn_speak)(void* __self);
};

#line 26 "src/compiler/LoweringTest.pv"
struct trait_PaveLowerSpeak {
    const struct trait_PaveLowerSpeakVTable* vtable;
    void* instance;
};

#endif
