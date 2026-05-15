#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_4.h>

#line 1 "src/std/str.pv"
void __pave_test_4() {
    #line 143 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 144 "src/std/str.pv"
    if (!str__starts_with(s, "hello")) {
        #line 144 "src/std/str.pv"
        abort();
    }
    #line 145 "src/std/str.pv"
    if (str__starts_with(s, "world")) {
        #line 145 "src/std/str.pv"
        abort();
    }
}
