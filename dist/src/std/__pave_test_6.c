#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_6.h>

#line 1 "src/std/str.pv"
void __pave_test_6() {
    #line 155 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 156 "src/std/str.pv"
    if (!str__contains(s, "lo wo")) {
        #line 156 "src/std/str.pv"
        abort();
    }
    #line 157 "src/std/str.pv"
    if (str__contains(s, "xyz")) {
        #line 157 "src/std/str.pv"
        abort();
    }
}
