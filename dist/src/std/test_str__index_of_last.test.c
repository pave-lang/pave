#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__index_of_last.test.h>

#line 1 "src/std/str.pv"
void test_str__index_of_last() {
    #line 185 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 186 "src/std/str.pv"
    if (str__index_of_last(s, 'l') != 3) {
        #line 186 "src/std/str.pv"
        abort();
    }
    #line 187 "src/std/str.pv"
    if (str__index_of_last(s, 'z') != -1) {
        #line 187 "src/std/str.pv"
        abort();
    }
}
