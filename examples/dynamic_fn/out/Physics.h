#ifndef PAVE_PHYSICS
#define PAVE_PHYSICS

struct Position;
struct Time;

struct Physics {
    float gravity;
};

void Physics__apply_physics(struct Physics* self, struct Position* data, struct Time time);
#include <std/Fn.h>
struct Physics__apply_physics__Fn__Instance { struct Physics* self; struct Position* data; struct Time time; };
extern struct FnVTable PHYSICS__APPLY_PHYSICS__VTABLE__DYN_FN;

#endif
