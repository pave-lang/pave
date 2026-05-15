#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_3.h>

#line 1 "src/std/str.pv"
void __pave_test_3() {
    #line 137 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 138 "src/std/str.pv"
    if (!str__eq(str__slice(s, 6, 11), (struct str){ .ptr = "world", .length = strlen("world") })) {
        #line 138 "src/std/str.pv"
        abort();
    }
    #line 139 "src/std/str.pv"
    if (!str__eq(str__slice(s, 0, 5), (struct str){ .ptr = "hello", .length = strlen("hello") })) {
        #line 139 "src/std/str.pv"
        abort();
    }
}
