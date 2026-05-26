#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__index_of.test.h>

#line 1 "src/std/str.pv"
void test_str__index_of() {
    #line 180 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 181 "src/std/str.pv"
    if (str__index_of(s, 'l') != 2) {
        #line 181 "src/std/str.pv"
        abort();
    }
    #line 182 "src/std/str.pv"
    if (str__index_of(s, 'z') != -1) {
        #line 182 "src/std/str.pv"
        abort();
    }
}
