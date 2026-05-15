#ifndef PAVE_RUN
#define PAVE_RUN

#include <stdbool.h>
#include <stdint.h>

#include <std/trait_Fn.h>
#include <slice_Object.h>
#include <dynamic_fn/Time.h>
#include <dynamic_fn/Physics.h>
void run(struct trait_Fn func, struct slice_Object objects, struct Time time, struct Physics physics);

#endif
