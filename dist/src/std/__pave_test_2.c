#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/__pave_test_2.h>

#line 1 "src/std/str.pv"
void __pave_test_2() {
    #line 131 "src/std/str.pv"
    struct str a = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 132 "src/std/str.pv"
    struct str b = (struct str){ .ptr = "hell", .length = strlen("hell") };
    #line 133 "src/std/str.pv"
    if (str__eq(a, b)) {
        #line 133 "src/std/str.pv"
        abort();
    }
}
