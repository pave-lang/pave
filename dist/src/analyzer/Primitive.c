#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Trait.h>
#include <std/Allocator.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Primitive.h>

#line 10 "src/analyzer/Primitive.pv"
struct Primitive Primitive__new(struct ArenaAllocator* allocator, char const* name) {
    #line 11 "src/analyzer/Primitive.pv"
    return (struct Primitive) {
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .traits = HashMap_str_ref_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_ref_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}

#line 18 "src/analyzer/Primitive.pv"
bool Primitive__is_number(struct Primitive* self) {
    #line 19 "src/analyzer/Primitive.pv"
    return str__eq(self->name, (struct str){ .ptr = "char", .length = strlen("char") }) || str__eq(self->name, (struct str){ .ptr = "i8", .length = strlen("i8") }) || str__eq(self->name, (struct str){ .ptr = "i16", .length = strlen("i16") }) || str__eq(self->name, (struct str){ .ptr = "i32", .length = strlen("i32") }) || str__eq(self->name, (struct str){ .ptr = "i64", .length = strlen("i64") }) || str__eq(self->name, (struct str){ .ptr = "isize", .length = strlen("isize") }) || str__eq(self->name, (struct str){ .ptr = "u8", .length = strlen("u8") }) || str__eq(self->name, (struct str){ .ptr = "u16", .length = strlen("u16") }) || str__eq(self->name, (struct str){ .ptr = "u32", .length = strlen("u32") }) || str__eq(self->name, (struct str){ .ptr = "u64", .length = strlen("u64") }) || str__eq(self->name, (struct str){ .ptr = "usize", .length = strlen("usize") }) || str__eq(self->name, (struct str){ .ptr = "f32", .length = strlen("f32") }) || str__eq(self->name, (struct str){ .ptr = "f64", .length = strlen("f64") });
}

#line 34 "src/analyzer/Primitive.pv"
bool Primitive__is_void(struct Primitive* self) {
    #line 35 "src/analyzer/Primitive.pv"
    return self == 0 || str__eq(self->name, (struct str){ .ptr = "void", .length = strlen("void") });
}
