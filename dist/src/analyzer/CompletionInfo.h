#ifndef PAVE_COMPLETION_INFO
#define PAVE_COMPLETION_INFO

#include <stdint.h>

#include <analyzer/Range.h>
#include <std/str.h>
#include <analyzer/Position.h>

#line 51 "src/analyzer/Analysis.pv"
struct CompletionInfo {
    struct Range range;
    struct str name;
    struct str type_label;
    uintptr_t kind;
    struct Position definition_position;
};

#endif
