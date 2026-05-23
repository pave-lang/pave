#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/String.h>
#include <std/trait_Allocator.h>
#include <std/format.h>
#include <std/trait_Writer.h>
#include <std/str.h>
#include <format/DisplayI32.h>
#include <format/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct GeneralPurposeAllocator* allocator = GeneralPurposeAllocator__default();
    struct String message = String__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    format((struct trait_Writer) { .vtable = &STRING__VTABLE__WRITER, .instance = &message }, (struct str){ .ptr = "blah: {}", .length = strlen("blah: {}") }, (struct slice_ref_trait_Format) { .data = (struct trait_Format[]) {(struct trait_Format) { .vtable = &DISPLAY_I32__VTABLE__FORMAT, .instance = (struct DisplayI32[]) {(struct DisplayI32) { .value = 1 }} }}, .length = 1 });
    printf("%.*s\n", String__len_i32(&message), String__c_str(&message));
    String__clear(&message);

    format((struct trait_Writer) { .vtable = &STRING__VTABLE__WRITER, .instance = &message }, (struct str){ .ptr = "{} + {} = {hex}", .length = strlen("{} + {} = {hex}") }, (struct slice_ref_trait_Format) { .data = (struct trait_Format[]) {(struct trait_Format) { .vtable = &DISPLAY_I32__VTABLE__FORMAT, .instance = (struct DisplayI32[]) {(struct DisplayI32) { .value = 1 }} }, (struct trait_Format) { .vtable = &DISPLAY_I32__VTABLE__FORMAT, .instance = (struct DisplayI32[]) {(struct DisplayI32) { .value = 2 }} }, (struct trait_Format) { .vtable = &DISPLAY_I32__VTABLE__FORMAT, .instance = (struct DisplayI32[]) {(struct DisplayI32) { .value = 3 }} }}, .length = 3 });
    printf("%.*s\n", String__len_i32(&message), String__c_str(&message));
    String__clear(&message);

    struct str escaped = (struct str){ .ptr = "escaped", .length = strlen("escaped") };
    format((struct trait_Writer) { .vtable = &STRING__VTABLE__WRITER, .instance = &message }, (struct str){ .ptr = "{{ {} }}", .length = strlen("{{ {} }}") }, (struct slice_ref_trait_Format) { .data = (struct trait_Format[]) {(struct trait_Format) { .vtable = &STR__VTABLE__FORMAT, .instance = (struct str[]) {escaped} }}, .length = 1 });
    printf("%.*s\n", String__len_i32(&message), String__c_str(&message));
    String__release(&message);

    return 0;
}
