#include <stdbool.h>
#include <stdint.h>

#include <std/Array_TypeId.h>
#include <std/trait_Fn.h>
#include <slice_Object.h>
#include <dynamic_fn/Object.h>
#include <std/IterEnumerate_ref_TypeId.h>
#include <std/Iter_ref_TypeId.h>
#include <tuple_usize_ref_TypeId.h>
#include <std/TypeId.h>
#include <dynamic_fn/Physics.h>
#include <dynamic_fn/Time.h>
#include <dynamic_fn/Position.h>
#include <dynamic_fn/run.h>

void run(struct trait_Fn func, struct slice_Object objects, struct Time time, struct Physics physics) {
    struct Array_TypeId* params = func.vtable->get_params(func.instance);

    for (size_t __iter = 0; __iter < objects.length; __iter++) {
        struct Object obj = objects.data[__iter];

        { struct IterEnumerate_ref_TypeId __iter = Iter_ref_TypeId__enumerate(Array_TypeId__iter(params));
        while (IterEnumerate_ref_TypeId__next(&__iter)) {
            uintptr_t i = IterEnumerate_ref_TypeId__value(&__iter)._0;
            TypeId param = *IterEnumerate_ref_TypeId__value(&__iter)._1;

            if (param == 1569699411331758434ULL) {
                func.vtable->set_arg(func.instance, i, &physics);
            } else if (param == 5251627053891867748ULL) {
                func.vtable->set_arg(func.instance, i, &time);
            } else if (param == 9740451013666663182ULL) {
                func.vtable->set_arg(func.instance, i, &obj.position);
            }
        } }

        func.vtable->execute(func.instance);
    }
}
