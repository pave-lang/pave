#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_9.h>

#line 1 "src/std/str.pv"
void __pave_test_9() {
    #line 171 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 172 "src/std/str.pv"
    if (str__index_of(s, 'l') != 2) {
        #line 172 "src/std/str.pv"
        abort();
    }
    #line 173 "src/std/str.pv"
    if (str__index_of(s, 'z') != -1) {
        #line 173 "src/std/str.pv"
        abort();
    }
}
