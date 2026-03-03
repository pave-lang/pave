#ifndef PAVE_RUN
#define PAVE_RUN

#include <std/DynFn.h>
#include <slice_Object.h>
#include <dynamic_fn/Time.h>
#include <dynamic_fn/Physics.h>

void run(struct DynFn func, struct slice_Object objects, struct Time time, struct Physics physics);

#endif
