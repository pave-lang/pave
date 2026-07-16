#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__eq___equal_strings.test.h>

#line 1 "src/std/str.pv"
void test_str__eq___equal_strings() {
    #line 127 "src/std/str.pv"
    struct str a = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 128 "src/std/str.pv"
    struct str b = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 129 "src/std/str.pv"
    if (!str__Eq_str__eq(a, b)) {
        #line 129 "src/std/str.pv"
        abort();
    }
}
