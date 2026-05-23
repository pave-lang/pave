#ifndef PAVE_APPEND_I32
#define PAVE_APPEND_I32

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <std/trait_Writer.h>
#include <std/str.h>
void append_i32(struct trait_Writer out, int32_t value, struct str info);

#endif
