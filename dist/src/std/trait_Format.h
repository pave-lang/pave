#ifndef PAVE_TRAIT_FORMAT
#define PAVE_TRAIT_FORMAT

#include <std/trait_Writer.h>
#include <std/str.h>

#line 1 "src/std/Format.pv"
struct trait_FormatVTable {
    #line 2 "src/std/Format.pv"
    void (*fn_format)(void* __self, struct trait_Writer out, struct str info);
};

#line 1 "src/std/Format.pv"
struct trait_Format {
    const struct trait_FormatVTable* vtable;
    void* instance;
};

#endif
