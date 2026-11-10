#include <stdlib.h>

#include <compiler/PaveCallCounter.h>

#include <compiler/PaveCallCounter.h>

#line 12 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__zero() {
    #line 12 "src/compiler/CallTest.pv"
    return 0;
}

#line 13 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__twice(int32_t value) {
    #line 13 "src/compiler/CallTest.pv"
    return value * 2;
}

#line 14 "src/compiler/CallTest.pv"
int32_t PaveCallCounter__add(struct PaveCallCounter* self, int32_t value) {
    #line 14 "src/compiler/CallTest.pv"
    self->count += value;
    #line 14 "src/compiler/CallTest.pv"
    return self->count;
}
