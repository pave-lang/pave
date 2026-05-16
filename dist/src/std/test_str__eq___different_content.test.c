#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__eq___different_content.test.h>

#line 1 "src/std/str.pv"
void test_str__eq___different_content() {
    #line 125 "src/std/str.pv"
    struct str a = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 126 "src/std/str.pv"
    struct str b = (struct str){ .ptr = "world", .length = strlen("world") };
    #line 127 "src/std/str.pv"
    if (str__eq(a, b)) {
        #line 127 "src/std/str.pv"
        abort();
    }
}
