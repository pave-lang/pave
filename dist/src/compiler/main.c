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
#include <std/Array_str.h>
#include <std/Range_i32.h>
#include <i32.h>
#include <std/str.h>
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
    #line 17 "src/compiler/main.pv"
    struct Array_str game_namespaces = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 19 "src/compiler/main.pv"
    for (int32_t i = 1; i != argc; i < argc ? i++ : i--) {
        #line 20 "src/compiler/main.pv"
        if (i32__Eq_i32__eq(strncmp(argv[i], "-o", 3), 0)) {
            #line 21 "src/compiler/main.pv"
            i += 1;
            #line 22 "src/compiler/main.pv"
            output_folder = argv[i];
        } else if (i32__Eq_i32__eq(strncmp(argv[i], "--no-line-directives", 21), 0)) {
            #line 24 "src/compiler/main.pv"
            output_line_directives = false;
        } else if (i32__Eq_i32__eq(strncmp(argv[i], "--output-separator=semicolon", 29), 0)) {
            #line 26 "src/compiler/main.pv"
            output_seperator = ";";
        } else if (i32__Eq_i32__eq(strncmp(argv[i], "--game-namespace=", 17), 0)) {
            #line 28 "src/compiler/main.pv"
            Array_str__append(&game_namespaces, str__new(argv[i] + 17));
        } else {
            #line 30 "src/compiler/main.pv"
            Array_ptrc_char__append(&args, argv[i]);
        }
    }

    #line 34 "src/compiler/main.pv"
    if (!output_folder || argc < 4) {
        #line 35 "src/compiler/main.pv"
        fprintf(stderr, "Usage: %s ns_name=ns_path -o <output_folder> [-std=<version>] [--no-line-directives] [--output-new-lines] [--game-namespace=<ns::path>]... -- [clang_args]\n", argv[0]);
        #line 36 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 39 "src/compiler/main.pv"
    struct Analysis analysis = Analysis__new(allocator);
    #line 40 "src/compiler/main.pv"
    struct Root* root = Root__new(allocator, &args, &analysis);

    #line 42 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 43 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 44 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 47 "src/compiler/main.pv"
    Root__add_use_namespaces(root);
    #line 48 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 49 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 50 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 53 "src/compiler/main.pv"
    Root__fill_namespace(root);
    #line 54 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 55 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 56 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 59 "src/compiler/main.pv"
    Root__prefill_types(root);
    #line 60 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 61 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 62 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 65 "src/compiler/main.pv"
    Root__prefill_types_impl(root);
    #line 66 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 67 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 68 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 71 "src/compiler/main.pv"
    Root__parse_declarations(root);
    #line 72 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 73 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 74 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 77 "src/compiler/main.pv"
    Root__parse_globals(root);
    #line 78 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 79 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 80 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 83 "src/compiler/main.pv"
    Root__parse_functions(root);
    #line 84 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 85 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 86 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 89 "src/compiler/main.pv"
    if (!Generator__generate(allocator, output_folder, output_line_directives, output_seperator, game_namespaces, root)) {
        #line 91 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 94 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 95 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 96 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(allocator);
        return __result;
    }

    #line 99 "src/compiler/main.pv"
    __result = 0;
    ArenaAllocator__destroy(allocator);
    return __result;
}
