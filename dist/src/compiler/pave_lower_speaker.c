#include <stdint.h>

#include <stdlib.h>

#include <compiler/PaveLowerCalls.h>
#include <compiler/trait_PaveLowerSpeak.h>
#include <compiler/PaveLowerDog.h>
#include <compiler/pave_lower_speaker.h>

#line 53 "src/compiler/LoweringTest.pv"
struct trait_PaveLowerSpeak pave_lower_speaker(struct PaveLowerDog* dog, struct PaveLowerCalls* calls) {
    #line 54 "src/compiler/LoweringTest.pv"
    calls->count += 1;
    #line 55 "src/compiler/LoweringTest.pv"
    return (struct trait_PaveLowerSpeak) { .vtable = &PAVE_LOWER_DOG__VTABLE__PAVE_LOWER_SPEAK, .instance = dog };
}
