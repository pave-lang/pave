#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__eq___equal_strings.test.h>

#line 1 "src/std/str.pv"
void test_str__eq___equal_strings() {
    #line 119 "src/std/str.pv"
    struct str a = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 120 "src/std/str.pv"
    struct str b = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 121 "src/std/str.pv"
    if (!str__eq(a, b)) {
        #line 121 "src/std/str.pv"
        abort();
    }
}
