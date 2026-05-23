#include <stdint.h>
#include <stdbool.h>

#include <std/str.h>
#include <std/trait_Writer.h>
#include <slice_ref_trait_Format.h>
#include <std/trait_Format.h>
#include <std/format.h>

#line 5 "src/std/Format.pv"
void format(struct trait_Writer out, struct str fmt, struct slice_ref_trait_Format parts) {
    #line 6 "src/std/Format.pv"
    uintptr_t part_i = 0;
    #line 7 "src/std/Format.pv"
    uintptr_t i = 0;

    #line 9 "src/std/Format.pv"
    while (i < fmt.length) {
        #line 10 "src/std/Format.pv"
        uintptr_t start = i;

        #line 12 "src/std/Format.pv"
        while (i < fmt.length && fmt.ptr[i] != '{' && fmt.ptr[i] != '}') {
            #line 13 "src/std/Format.pv"
            i += 1;
        }

        #line 16 "src/std/Format.pv"
        if (start < i) {
            #line 17 "src/std/Format.pv"
            out.vtable->fn_write(out.instance, str__slice(fmt, start, i));
        }

        #line 20 "src/std/Format.pv"
        if (i >= fmt.length) {
            #line 21 "src/std/Format.pv"
            return;
        }

        #line 24 "src/std/Format.pv"
        if (fmt.ptr[i] == '}') {
            #line 25 "src/std/Format.pv"
            if (i + 1 < fmt.length && fmt.ptr[i + 1] == '}') {
                #line 26 "src/std/Format.pv"
                out.vtable->fn_write_char(out.instance, '}');
                #line 27 "src/std/Format.pv"
                i += 2;
            } else {
                #line 29 "src/std/Format.pv"
                out.vtable->fn_write_char(out.instance, fmt.ptr[i]);
                #line 30 "src/std/Format.pv"
                i += 1;
            }

            #line 33 "src/std/Format.pv"
            continue;
        }

        #line 36 "src/std/Format.pv"
        if (i + 1 < fmt.length && fmt.ptr[i + 1] == '{') {
            #line 37 "src/std/Format.pv"
            out.vtable->fn_write_char(out.instance, '{');
            #line 38 "src/std/Format.pv"
            i += 2;
            #line 39 "src/std/Format.pv"
            continue;
        }

        #line 42 "src/std/Format.pv"
        uintptr_t end = i + 1;

        #line 44 "src/std/Format.pv"
        while (end < fmt.length && fmt.ptr[end] != '}') {
            #line 45 "src/std/Format.pv"
            end += 1;
        }

        #line 48 "src/std/Format.pv"
        if (end >= fmt.length) {
            #line 49 "src/std/Format.pv"
            out.vtable->fn_write_char(out.instance, fmt.ptr[i]);
            #line 50 "src/std/Format.pv"
            i += 1;
            #line 51 "src/std/Format.pv"
            continue;
        }

        #line 54 "src/std/Format.pv"
        struct str info = str__slice(fmt, i + 1, end);

        #line 56 "src/std/Format.pv"
        if (part_i < parts.length) {
            #line 57 "src/std/Format.pv"
            parts.data[part_i].vtable->fn_format(parts.data[part_i].instance, out, info);
            #line 58 "src/std/Format.pv"
            part_i += 1;
        } else {
            #line 60 "src/std/Format.pv"
            out.vtable->fn_write_char(out.instance, '{');
            #line 61 "src/std/Format.pv"
            out.vtable->fn_write(out.instance, info);
            #line 62 "src/std/Format.pv"
            out.vtable->fn_write_char(out.instance, '}');
        }

        #line 65 "src/std/Format.pv"
        i = end + 1;
    }
}
