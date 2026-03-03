#ifndef PAVE_DIAGNOSTIC
#define PAVE_DIAGNOSTIC

#include <std/str.h>
#include <analyzer/Range.h>

#include <stdio.h>

#line 15 "src/analyzer/Analysis.pv"
struct Diagnostic {
    struct str message;
    struct str code;
    struct Range range;
};

#endif
