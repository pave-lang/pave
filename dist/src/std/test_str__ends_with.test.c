#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__ends_with.test.h>

#line 1 "src/std/str.pv"
void test_str__ends_with() {
    #line 157 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello world", .length = strlen("hello world") };
    #line 158 "src/std/str.pv"
    if (!str__ends_with(s, "world")) {
        #line 158 "src/std/str.pv"
        abort();
    }
    #line 159 "src/std/str.pv"
    if (str__ends_with(s, "hello")) {
        #line 159 "src/std/str.pv"
        abort();
    }
}
