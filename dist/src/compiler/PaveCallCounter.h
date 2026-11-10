#ifndef PAVE_PAVE_CALL_COUNTER
#define PAVE_PAVE_CALL_COUNTER

#include <stdint.h>

#line 9 "src/compiler/CallTest.pv"
struct PaveCallCounter {
    int32_t count;
};


#line 12 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__zero();

#line 13 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__twice(int32_t value);

#line 14 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__add(struct PaveCallCounter* self, int32_t value);

#endif
