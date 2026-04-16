#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>

#include <stdio.h>
#include <analyzer/Analysis.h>
#include <std/HashMap_str_bool.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_Array_Diagnostic.h>
#include <std/HashMap_str_Array_InlayHint.h>
#include <std/HashMapIter_str_Array_Diagnostic.h>
#include <tuple_str_Array_Diagnostic.h>
#include <std/Array_Diagnostic.h>
#include <std/Iter_ref_Diagnostic.h>
#include <analyzer/Diagnostic.h>
#include <std/str.h>
#include <analyzer/Position.h>
#include <analyzer/Range.h>
#include <analyzer/Analysis.h>

#include <analyzer/Analysis.h>

#line 42 "src/analyzer/Analysis.pv"
struct Analysis Analysis__new(struct ArenaAllocator* allocator) {
    #line 43 "src/analyzer/Analysis.pv"
    return (struct Analysis) {
        .files = HashMap_str_bool__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .diagnostics = HashMap_str_Array_Diagnostic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .inlay_hints = HashMap_str_Array_InlayHint__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };
}

#line 50 "src/analyzer/Analysis.pv"
void Analysis__print_diagnostics(struct Analysis* self) {
    #line 51 "src/analyzer/Analysis.pv"
    { struct HashMapIter_str_Array_Diagnostic __iter = HashMap_str_Array_Diagnostic__iter(&self->diagnostics);
    #line 51 "src/analyzer/Analysis.pv"
    while (HashMapIter_str_Array_Diagnostic__next(&__iter)) {
        #line 51 "src/analyzer/Analysis.pv"
        struct str filename = HashMapIter_str_Array_Diagnostic__value(&__iter)->_0;
        #line 51 "src/analyzer/Analysis.pv"
        struct Array_Diagnostic* diagnostics = &HashMapIter_str_Array_Diagnostic__value(&__iter)->_1;

        #line 52 "src/analyzer/Analysis.pv"
        { struct Iter_ref_Diagnostic __iter = Array_Diagnostic__iter(diagnostics);
        #line 52 "src/analyzer/Analysis.pv"
        while (Iter_ref_Diagnostic__next(&__iter)) {
            #line 52 "src/analyzer/Analysis.pv"
            struct Diagnostic* diagnostic = Iter_ref_Diagnostic__value(&__iter);

            #line 53 "src/analyzer/Analysis.pv"
            int32_t filename_length = filename.length;
            #line 54 "src/analyzer/Analysis.pv"
            int32_t message_length = diagnostic->message.length;

            #line 56 "src/analyzer/Analysis.pv"
            fprintf(stderr, "%.*s:%zu:%zu %.*s", filename_length, filename.ptr, diagnostic->range.start.line + 1, diagnostic->range.start.character + 1, message_length, diagnostic->message.ptr);

            #line 58 "src/analyzer/Analysis.pv"
            if (diagnostic->code.length > 0) {
                #line 59 "src/analyzer/Analysis.pv"
                int32_t code_length = diagnostic->code.length;
                #line 60 "src/analyzer/Analysis.pv"
                fprintf(stderr, " %.*s", code_length, diagnostic->code.ptr);
            }

            #line 63 "src/analyzer/Analysis.pv"
            fprintf(stderr, "\n");
        } }
    } }
}
