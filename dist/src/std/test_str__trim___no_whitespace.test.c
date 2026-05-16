#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__trim___no_whitespace.test.h>

#line 1 "src/std/str.pv"
void test_str__trim___no_whitespace() {
    #line 164 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 165 "src/std/str.pv"
    if (!str__eq(str__trim(s), (struct str){ .ptr = "hello", .length = strlen("hello") })) {
        #line 165 "src/std/str.pv"
        abort();
    }
}
