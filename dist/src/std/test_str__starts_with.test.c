#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__starts_with.test.h>

#line 1 "src/std/str.pv"
void test_str__starts_with() {
    #line 141 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 142 "src/std/str.pv"
    if (!str__starts_with(s, "hello")) {
        #line 142 "src/std/str.pv"
        abort();
    }
    #line 143 "src/std/str.pv"
    if (str__starts_with(s, "world")) {
        #line 143 "src/std/str.pv"
        abort();
    }
}
