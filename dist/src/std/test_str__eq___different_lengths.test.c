#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__eq___different_lengths.test.h>

#line 1 "src/std/str.pv"
void test_str__eq___different_lengths() {
    #line 129 "src/std/str.pv"
    struct str a = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 130 "src/std/str.pv"
    struct str b = (struct str){ .ptr = "hell", .length = strlen("hell") };
    #line 131 "src/std/str.pv"
    if (str__eq(a, b)) {
        #line 131 "src/std/str.pv"
        abort();
    }
}
