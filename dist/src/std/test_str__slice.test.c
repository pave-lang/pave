#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__slice.test.h>

#line 1 "src/std/str.pv"
void test_str__slice() {
    #line 135 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 136 "src/std/str.pv"
    if (!str__eq(str__slice(s, 6, 11), (struct str){ .ptr = "world", .length = strlen("world") })) {
        #line 136 "src/std/str.pv"
        abort();
    }
    #line 137 "src/std/str.pv"
    if (!str__eq(str__slice(s, 0, 5), (struct str){ .ptr = "hello", .length = strlen("hello") })) {
        #line 137 "src/std/str.pv"
        abort();
    }
}
