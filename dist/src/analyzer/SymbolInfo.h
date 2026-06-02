#ifndef PAVE_SYMBOL_INFO
#define PAVE_SYMBOL_INFO

#include <analyzer/Range.h>
#include <std/str.h>
#include <analyzer/Position.h>

#line 35 "src/analyzer/Analysis.pv"
struct SymbolInfo {
    struct Range range;
    struct str type_label;
    struct str definition_path;
    struct Position definition_position;
};

#endif
