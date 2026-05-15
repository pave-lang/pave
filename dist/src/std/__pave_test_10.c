#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_10.h>

#line 1 "src/std/str.pv"
void __pave_test_10() {
    #line 177 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 178 "src/std/str.pv"
    if (str__index_of_last(s, 'l') != 3) {
        #line 178 "src/std/str.pv"
        abort();
    }
    #line 179 "src/std/str.pv"
    if (str__index_of_last(s, 'z') != -1) {
        #line 179 "src/std/str.pv"
        abort();
    }
}
