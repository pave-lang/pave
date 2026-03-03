#include <dynamic_fn/Position.h>
#include <dynamic_fn/Time.h>

#include <dynamic_fn/Physics.h>

void Physics__apply_physics(struct Physics* self, struct Position* data, struct Time time) {
    data->y += time.delta * self->gravity;
}

#include <std/Array_TypeId.h>
struct Array_TypeId* Physics__apply_physics__DynFn__get_params(void* __self) {
    static TypeId type_ids[] = { 6811604471128968318ULL, 9740451013666663182ULL, 5251627053891867748ULL };
    static struct Array_TypeId result = { .data = type_ids, .length = 3 };
    return &result;
}
bool Physics__apply_physics__DynFn__set_arg(void* __self, uintptr_t index, void* value) {
    struct Physics__apply_physics__DynFn__Instance* self = __self;
    switch (index) {
        case 0: self->self = value; return true;
        case 1: self->data = value; return true;
        case 2: self->time = *(struct Time*)value; return true;
    }
    return false;
}
void Physics__apply_physics__DynFn__execute(void* __self) {
    struct Physics__apply_physics__DynFn__Instance* self = __self;
    Physics__apply_physics(self->self, self->data, self->time);
}
struct DynFnVTable PHYSICS__APPLY_PHYSICS__VTABLE__DYN_FN = { .get_params = &Physics__apply_physics__DynFn__get_params, .set_arg = &Physics__apply_physics__DynFn__set_arg, .execute = &Physics__apply_physics__DynFn__execute };
