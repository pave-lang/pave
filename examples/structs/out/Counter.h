#ifndef PAVE_COUNTER
#define PAVE_COUNTER

#include <stdint.h>

struct Counter {
    int32_t value;
    int32_t step;
};


struct Counter Counter__new();

struct Counter Counter__new_with_step(int32_t step);

void Counter__advance(struct Counter* self);

#endif
