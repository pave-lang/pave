#ifndef PAVE_PRIMITIVE
#define PAVE_PRIMITIVE

#include <stdbool.h>

#include <std/str.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/Array_ref_Impl.h>

#line 4 "src/analyzer/types/Primitive.pv"
struct Primitive {
    struct str name;
    struct HashMap_str_ref_Trait traits;
    struct Array_ref_Impl impls;
};

#include <analyzer/types/Primitive.h>
struct ArenaAllocator;
struct Primitive;

#line 11 "src/analyzer/types/Primitive.pv"
struct Primitive Primitive__new(struct ArenaAllocator* allocator, char const* name);

#line 19 "src/analyzer/types/Primitive.pv"
bool Primitive__is_number(struct Primitive* self);

#line 35 "src/analyzer/types/Primitive.pv"
bool Primitive__is_void(struct Primitive* self);

#endif
