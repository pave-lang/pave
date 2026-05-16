#include <structs/Counter.h>
#include <structs/Counter.h>

#include <structs/Counter.h>

struct Counter Counter__new() {
    return (struct Counter) {
        .value = 0,
        .step = 1,
    };
}

struct Counter Counter__new_with_step(int32_t step) {
    return (struct Counter) {
        .step = step,
        .value = 0,
    };
}

void Counter__advance(struct Counter* self) {
    self->value += self->step;
}
