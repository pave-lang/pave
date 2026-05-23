#include <stdio.h>

#include <format/append_i32.h>
#include <std/trait_Writer.h>
#include <format/DisplayI32.h>
#include <std/str.h>
#include <format/DisplayI32.h>

#include <format/DisplayI32.h>

void DisplayI32__Format__format(void* __self, struct trait_Writer out, struct str info) {
    struct DisplayI32* self = __self; (void)self;
    append_i32(out, self->value, info);
}

struct trait_FormatVTable DISPLAY_I32__VTABLE__FORMAT = { .fn_format = &DisplayI32__Format__format };
