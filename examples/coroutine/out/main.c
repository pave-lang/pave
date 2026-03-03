#include <stdio.h>

#include <stdint.h>
#include <coroutine/running_total.h>

#include <coroutine/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct running_total totals = (struct running_total) { .steps = 5, .increment = 1.5f };
    { struct running_total __iter = totals;
    while (running_total__next(&__iter)) {
        float total = running_total__value(&__iter);

        printf("Total: %f\n", total);
    } }

    return 0;
}
