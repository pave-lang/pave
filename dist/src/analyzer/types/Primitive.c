#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/Allocator.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <stdbool.h>
#include <stdint.h>

#include <analyzer/types/Primitive.h>

#line 11 "src/analyzer/types/Primitive.pv"
struct Primitive Primitive__new(struct ArenaAllocator* allocator, char const* name) {
    #line 12 "src/analyzer/types/Primitive.pv"
    return (struct Primitive) {
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}

#line 19 "src/analyzer/types/Primitive.pv"
bool Primitive__is_number(struct Primitive* self) {
    #line 20 "src/analyzer/types/Primitive.pv"
    if (self == 0) {
        #line 20 "src/analyzer/types/Primitive.pv"
        return false;
    }

    #line 22 "src/analyzer/types/Primitive.pv"
    return str__eq(self->name, (struct str){ .ptr = "char", .length = strlen("char") }) || str__eq(self->name, (struct str){ .ptr = "i8", .length = strlen("i8") }) || str__eq(self->name, (struct str){ .ptr = "i16", .length = strlen("i16") }) || str__eq(self->name, (struct str){ .ptr = "i32", .length = strlen("i32") }) || str__eq(self->name, (struct str){ .ptr = "i64", .length = strlen("i64") }) || str__eq(self->name, (struct str){ .ptr = "isize", .length = strlen("isize") }) || str__eq(self->name, (struct str){ .ptr = "u8", .length = strlen("u8") }) || str__eq(self->name, (struct str){ .ptr = "u16", .length = strlen("u16") }) || str__eq(self->name, (struct str){ .ptr = "u32", .length = strlen("u32") }) || str__eq(self->name, (struct str){ .ptr = "u64", .length = strlen("u64") }) || str__eq(self->name, (struct str){ .ptr = "usize", .length = strlen("usize") }) || str__eq(self->name, (struct str){ .ptr = "f32", .length = strlen("f32") }) || str__eq(self->name, (struct str){ .ptr = "f64", .length = strlen("f64") });
}

#line 37 "src/analyzer/types/Primitive.pv"
bool Primitive__is_void(struct Primitive* self) {
    #line 38 "src/analyzer/types/Primitive.pv"
    return self == 0 || str__eq(self->name, (struct str){ .ptr = "void", .length = strlen("void") });
}
