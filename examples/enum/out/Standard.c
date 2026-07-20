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
#include <std/EnumVariantParamInfo.h>
#include <slice_EnumVariantParamInfo.h>
#include <std/EnumVariantKind.h>
struct slice_EnumVariantInfo Standard__Enum__get_variants(void* __self) {
    (void)__self;
    static struct EnumVariantInfo variants[] = { (struct EnumVariantInfo){ .index = 0, .key = (struct str){ .ptr = "One", .length = 3 }, .label = (struct str){ .ptr = "one", .length = sizeof("one") - 1 }, .kind = ENUM_VARIANT_KIND__UNIT, .params = (struct slice_EnumVariantParamInfo){ .data = 0, .length = 0 } }, (struct EnumVariantInfo){ .index = 1, .key = (struct str){ .ptr = "Two", .length = 3 }, .label = (struct str){ .ptr = "Two", .length = 3 }, .kind = ENUM_VARIANT_KIND__UNIT, .params = (struct slice_EnumVariantParamInfo){ .data = 0, .length = 0 } } };
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
void* Standard__Enum__get_param(void* __self, uintptr_t index) {
    (void)__self; (void)index;
    return 0;
}
bool Standard__Enum__set_param(void* __self, uintptr_t index, void* value) {
    (void)__self; (void)index; (void)value;
    return false;
}
struct trait_EnumVTable STANDARD__VTABLE__ENUM = { .fn_get_variants = &Standard__Enum__get_variants, .fn_get_variant_index = &Standard__Enum__get_variant_index, .fn_set_variant = &Standard__Enum__set_variant, .fn_get_param = &Standard__Enum__get_param, .fn_set_param = &Standard__Enum__set_param };
