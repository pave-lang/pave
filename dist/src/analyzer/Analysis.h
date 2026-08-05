#ifndef PAVE_ANALYSIS
#define PAVE_ANALYSIS

#include <stdbool.h>

#include <std/HashMap_str_bool.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/HashMap_str_Array_SymbolInfo.h>
#include <std/HashMap_str_Array_SignatureInfo.h>
#include <std/HashMap_str_Array_CompletionInfo.h>
#include <std/HashMap_str_Array_MemberCompletionInfo.h>
#include <std/HashMap_str_str.h>

#line 65 "src/analyzer/Analysis.pv"
struct Analysis {
    struct HashMap_str_bool files;
    struct HashMap_str_Array_Diagnostic diagnostics;
    struct HashMap_str_Array_InlayHint inlay_hints;
    struct HashMap_str_Array_SymbolInfo symbol_info;
    struct HashMap_str_Array_SignatureInfo signature_info;
    struct HashMap_str_Array_CompletionInfo completion_info;
    struct HashMap_str_Array_MemberCompletionInfo member_completion_info;
    bool collect_symbols;
    struct HashMap_str_bool parsed_function_files;
    struct HashMap_str_str file_overrides;
};

struct ArenaAllocator;

#line 79 "src/analyzer/Analysis.pv"
struct Analysis Analysis__new(struct ArenaAllocator* allocator);

#line 94 "src/analyzer/Analysis.pv"
void Analysis__print_diagnostics(struct Analysis* self);

#endif
