#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <slice_EnumVariantInfo.h>
#include <std/trait_Enum.h>
#include <std/str.h>
#include <std/EnumVariantInfo.h>
#include <enum/print_dynamic.h>

void print_dynamic(struct trait_Enum value) {
    struct slice_EnumVariantInfo variants = value.vtable->fn_get_variants(value.instance);
    uintptr_t index = value.vtable->fn_get_variant_index(value.instance);
    printf("%.*s\n", variants.data[index].name.length, variants.data[index].name.ptr);
}
