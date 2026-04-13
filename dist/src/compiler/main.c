#include <stdio.h>
#include <string.h>

#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/Array_ptrc_char.h>
#include <analyzer/Analysis.h>
#include <analyzer/Root.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <compiler/Generator.h>

#include <compiler/main.h>

#line 7 "src/compiler/main.pv"
int32_t main(int32_t argc, char const** argv) {
    int32_t __result;

    #line 8 "src/compiler/main.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 5 * 1024 * 1024);

    #line 11 "src/compiler/main.pv"
    struct Array_ptrc_char args = Array_ptrc_char__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = &allocator });
    #line 12 "src/compiler/main.pv"
    struct Array_ptrc_char clang_args = Array_ptrc_char__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = &allocator });
    #line 13 "src/compiler/main.pv"
    char const* output_folder = 0;
    #line 14 "src/compiler/main.pv"
    bool output_line_directives = true;
    #line 15 "src/compiler/main.pv"
    char const* output_seperator = " ";

    #line 17 "src/compiler/main.pv"
    bool in_clang_args = false;
    #line 18 "src/compiler/main.pv"
    for (int32_t i = 1; i < argc; i++) {
        #line 19 "src/compiler/main.pv"
        if (in_clang_args) {
            #line 20 "src/compiler/main.pv"
            Array_ptrc_char__append(&clang_args, argv[i]);
        } else if (strncmp(argv[i], "-o", 3) == 0) {
            #line 22 "src/compiler/main.pv"
            i += 1;
            #line 23 "src/compiler/main.pv"
            output_folder = argv[i];
        } else if (strncmp(argv[i], "--no-line-directives", 21) == 0) {
            #line 25 "src/compiler/main.pv"
            output_line_directives = false;
        } else if (strncmp(argv[i], "--output-separator=semicolon", 29) == 0) {
            #line 27 "src/compiler/main.pv"
            output_seperator = ";";
        } else if (strncmp(argv[i], "--", 3) == 0) {
            #line 29 "src/compiler/main.pv"
            in_clang_args = true;
        } else if (strncmp(argv[i], "-I", 2) == 0) {
            #line 31 "src/compiler/main.pv"
            Array_ptrc_char__append(&clang_args, argv[i]);
        } else {
            #line 33 "src/compiler/main.pv"
            Array_ptrc_char__append(&args, argv[i]);
        }
    }

    #line 37 "src/compiler/main.pv"
    if (!output_folder || argc < 4) {
        #line 38 "src/compiler/main.pv"
        fprintf(stderr, "Usage: %s ns_name=ns_path -o <output_folder> [--no-line-directives] [--output-new-lines] -- [clang_args]\n", argv[0]);
        #line 39 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 42 "src/compiler/main.pv"
    struct Analysis analysis = Analysis__new(&allocator);
    #line 43 "src/compiler/main.pv"
    struct Root* root = Root__new(&allocator, &args, &clang_args, &analysis);

    #line 45 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 46 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 47 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 50 "src/compiler/main.pv"
    Root__add_use_namespaces(root);
    #line 51 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 52 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 53 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 56 "src/compiler/main.pv"
    Root__fill_namespace(root);
    #line 57 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 58 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 59 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 62 "src/compiler/main.pv"
    Root__prefill_types(root);
    #line 63 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 64 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 65 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 68 "src/compiler/main.pv"
    Root__prefill_types_impl(root);
    #line 69 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 70 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 71 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 74 "src/compiler/main.pv"
    Root__parse_declarations(root);
    #line 75 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 76 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 77 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
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
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 86 "src/compiler/main.pv"
    if (!Generator__generate(&allocator, output_folder, output_line_directives, output_seperator, root)) {
        #line 88 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 91 "src/compiler/main.pv"
    if (analysis.diagnostics.length > 0) {
        #line 92 "src/compiler/main.pv"
        Analysis__print_diagnostics(&analysis);
        #line 93 "src/compiler/main.pv"
        __result = -1;
        ArenaAllocator__destroy(&allocator);
        return __result;
    }

    #line 96 "src/compiler/main.pv"
    __result = 0;
    ArenaAllocator__destroy(&allocator);
    return __result;
}
