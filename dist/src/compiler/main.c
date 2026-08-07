#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/Array_ptrc_char.h>
#include <std/Range_i32.h>
#include <i32.h>
#include <analyzer/Analysis.h>
#include <analyzer/Root.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <compiler/Generator.h>
#include <compiler/main.h>

#line 7 "src/compiler/main.pv"
int32_t main(int32_t argc, char const** argv) {
    int32_t __result;

    #line 8 "src/compiler/main.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 5 * 1024 * 1024);
    #line 9 "src/compiler/main.pv"
    if (allocator_ptr == 0) {
        #line 9 "src/compiler/main.pv"
        return -1;
    }
    #line 10 "src/compiler/main.pv"
    struct ArenaAllocator* allocator = allocator_ptr;
    #line 11 "src/compiler/main.pv"

    #line 13 "src/compiler/main.pv"
    struct Array_ptrc_char args = Array_ptrc_char__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 14 "src/compiler/main.pv"
    char const* output_folder = 0;
    #line 15 "src/compiler/main.pv"
    bool output_line_directives = true;
    #line 16 "src/compiler/main.pv"
    char const* output_seperator = " ";

    #line 18 "src/compiler/main.pv"
    for (int32_t i = 1; i != argc; i < argc ? i++ : i--) {
        #line 19 "src/compiler/main.pv"
        if (i32__Eq_i32__eq(strncmp(argv[i], "-o", 3), 0)) {
            #line 20 "src/compiler/main.pv"
            i += 1;
            #line 21 "src/compiler/main.pv"
            output_folder = argv[i];
        } else if (i32__Eq_i32__eq(strncmp(argv[i], "--no-line-directives", 21), 0)) {
            #line 23 "src/compiler/main.pv"
            output_line_directives = false;
        } else if (i32__Eq_i32__eq(strncmp(argv[i], "--output-separator=semicolon", 29), 0)) {
            #line 25 "src/compiler/main.pv"
            output_seperator = ";";
        } else {
            #line 27 "src/compiler/main.pv"
            Array_ptrc_char__append(&args, argv[i]);
        }
    }

    #line 31 "src/compiler/main.pv"
    if (!output_folder || argc < 4) {
        #line 32 "src/compiler/main.pv"
        fprintf(stderr, "Usage: %s ns_name=ns_path -o <output_folder> [-std=<version>] [--no-line-directives] [--output-new-lines] -- [clang_args]\n", argv[0]);
        #line 33 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 36 "src/compiler/main.pv"
    struct Analysis analysis = Analysis__new(allocator);
    #line 37 "src/compiler/main.pv"
    struct Root* root = Root__new(allocator, &args, &analysis);

    #line 39 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 40 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 41 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 44 "src/compiler/main.pv"
    Root__add_use_namespaces(root);
    #line 45 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 46 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 47 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 50 "src/compiler/main.pv"
    Root__fill_namespace(root);
    #line 51 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 52 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 53 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 56 "src/compiler/main.pv"
    Root__prefill_types(root);
    #line 57 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 58 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 59 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 62 "src/compiler/main.pv"
    Root__prefill_types_impl(root);
    #line 63 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 64 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 65 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 68 "src/compiler/main.pv"
    Root__parse_declarations(root);
    #line 69 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 70 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 71 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 74 "src/compiler/main.pv"
    Root__parse_globals(root);
    #line 75 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 76 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 77 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 80 "src/compiler/main.pv"
    Root__parse_functions(root);
    #line 81 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 82 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 83 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 86 "src/compiler/main.pv"
    if (!Generator__generate(allocator, output_folder, output_line_directives, output_seperator, root)) {
        #line 88 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 91 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 92 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 93 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 96 "src/compiler/main.pv"
    __result = 0;
    ArenaAllocator__destroy(allocator);
    return __result;
}
