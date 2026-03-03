#ifndef PAVE_RUN
#define PAVE_RUN

#include <std/Fn.h>
#include <slice_Object.h>
#include <dynamic_fn/Time.h>
#include <dynamic_fn/Physics.h>

void run(struct Fn func, struct slice_Object objects, struct Time time, struct Physics physics);

#endif
