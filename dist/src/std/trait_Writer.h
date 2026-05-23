#ifndef PAVE_TRAIT_WRITER
#define PAVE_TRAIT_WRITER

#include <std/trait_Writer.h>
#include <std/str.h>

#line 1 "src/std/Writer.pv"
struct trait_WriterVTable {
    #line 2 "src/std/Writer.pv"
    void (*fn_write)(void* __self, struct str value);
    #line 3 "src/std/Writer.pv"
    void (*fn_write_char)(void* __self, char value);
};

#line 1 "src/std/Writer.pv"
struct trait_Writer {
    const struct trait_WriterVTable* vtable;
    void* instance;
};

#endif
