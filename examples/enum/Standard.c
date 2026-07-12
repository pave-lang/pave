#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <enum/Standard.h>

#include <enum/Standard.h>

void Standard__print(enum Standard* self) {
    switch (*self) {
        case STANDARD__ONE: {
            printf("one\n");
        } break;
        case STANDARD__TWO: {
            printf("two\n");
        } break;
    }
}

#include <std/EnumVariantInfo.h>
#include <slice_EnumVariantInfo.h>
struct slice_EnumVariantInfo Standard__Enum__get_variants(void* __self) {
    (void)__self;
    static struct EnumVariantInfo variants[] = { (struct EnumVariantInfo){ .index = 0, .name = (struct str){ .ptr = "one", .length = sizeof("one") - 1 } }, (struct EnumVariantInfo){ .index = 1, .name = (struct str){ .ptr = "Two", .length = 3 } } };
    return (struct slice_EnumVariantInfo){ .data = variants, .length = 2 };
}
uintptr_t Standard__Enum__get_variant_index(void* __self) {
    enum Standard* self = __self;
    return (uintptr_t)*self;
}
void Standard__Enum__set_variant(void* __self, uintptr_t index) {
    enum Standard* self = __self;
    *self = index;
}
struct trait_EnumVTable STANDARD__VTABLE__ENUM = { .fn_get_variants = &Standard__Enum__get_variants, .fn_get_variant_index = &Standard__Enum__get_variant_index, .fn_set_variant = &Standard__Enum__set_variant };
