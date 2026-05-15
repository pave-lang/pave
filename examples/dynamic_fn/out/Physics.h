#ifndef PAVE_PHYSICS
#define PAVE_PHYSICS

struct Physics {
    float gravity;
};

#include <dynamic_fn/Time.h>
struct Physics;
struct Position;

void Physics__apply_physics(struct Physics* self, struct Position* data, struct Time time);
#include <std/trait_Fn.h>
struct Physics__apply_physics__Fn__Instance { struct Physics* self; struct Position* data; struct Time time; };
extern struct trait_FnVTable PHYSICS__APPLY_PHYSICS__VTABLE__DYN_FN;

#endif
