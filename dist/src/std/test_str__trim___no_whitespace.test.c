#include <string.h>
#include <stdbool.h>

#include <string.h>
#include <stdlib.h>

#include <stdlib.h>
#include <std/str.h>
#include <std/test_str__trim___no_whitespace.test.h>

#line 1 "src/std/str.pv"
void test_str__trim___no_whitespace() {
    #line 175 "src/std/str.pv"
    struct str s = (struct str){ .ptr = "hello", .length = strlen("hello") };
    #line 176 "src/std/str.pv"
    if (!str__Eq_str__eq((struct str[]){str__trim(s)}, (struct str){ .ptr = "hello", .length = strlen("hello") })) {
        #line 176 "src/std/str.pv"
        abort();
    }
}
