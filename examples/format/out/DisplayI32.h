#ifndef PAVE_DISPLAY_I32
#define PAVE_DISPLAY_I32

#include <stdint.h>

struct DisplayI32 {
    int32_t value;
};

#include <std/trait_Format.h>
#include <std/trait_Writer.h>
#include <std/str.h>
struct DisplayI32;

void DisplayI32__Format__format(void* __self, struct trait_Writer out, struct str info);

extern struct trait_FormatVTable DISPLAY_I32__VTABLE__FORMAT;

#endif
