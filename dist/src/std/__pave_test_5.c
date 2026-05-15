#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_5.h>

#line 1 "src/std/str.pv"
void __pave_test_5() {
    #line 149 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 150 "src/std/str.pv"
    if (!str__ends_with(s, "world")) {
        #line 150 "src/std/str.pv"
        abort();
    }
    #line 151 "src/std/str.pv"
    if (str__ends_with(s, "hello")) {
        #line 151 "src/std/str.pv"
        abort();
    }
}
