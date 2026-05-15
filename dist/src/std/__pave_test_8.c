#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_8.h>

#line 1 "src/std/str.pv"
void __pave_test_8() {
    #line 166 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 167 "src/std/str.pv"
    if (!str__eq(str__trim(s), (struct str){ .ptr = "hello", .length = strlen("hello") })) {
        #line 167 "src/std/str.pv"
        abort();
    }
}
