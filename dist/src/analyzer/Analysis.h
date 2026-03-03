#ifndef PAVE_ANALYSIS
#define PAVE_ANALYSIS

#include <std/HashMap_str_bool.h>
#include <std/str.h>
#include <stdbool.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>

struct Analysis;
struct ArenaAllocator;

#include <stdio.h>

#line 35 "src/analyzer/Analysis.pv"
struct Analysis {
    struct HashMap_str_bool files;
    struct HashMap_str_Array_Diagnostic diagnostics;
    struct HashMap_str_Array_InlayHint inlay_hints;
};

#line 42 "src/analyzer/Analysis.pv"
struct Analysis Analysis__new(struct ArenaAllocator* allocator);

#line 50 "src/analyzer/Analysis.pv"
void Analysis__print_diagnostics(struct Analysis* self);

#endif
