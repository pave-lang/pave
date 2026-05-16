#include <stdio.h>

#include <compiler/test_FunctionCoroutine__coroutine_fibonacci_test.test.h>
#include <std/test_str__eq___equal_strings.test.h>
#include <std/test_str__eq___different_content.test.h>
#include <std/test_str__eq___different_lengths.test.h>
#include <std/test_str__slice.test.h>
#include <std/test_str__starts_with.test.h>
#include <std/test_str__ends_with.test.h>
#include <std/test_str__contains.test.h>
#include <std/test_str__trim.test.h>
#include <std/test_str__trim___no_whitespace.test.h>
#include <std/test_str__index_of.test.h>
#include <std/test_str__index_of_last.test.h>

int main(void) {
    int passed = 0;
    int failed = 0;

    fputs("[TEST] compiler/FunctionCoroutine: coroutine fibonacci test\n", stdout);
    test_FunctionCoroutine__coroutine_fibonacci_test();
    passed++;

    fputs("[TEST] std/str: eq - equal strings\n", stdout);
    test_str__eq___equal_strings();
    passed++;

    fputs("[TEST] std/str: eq - different content\n", stdout);
    test_str__eq___different_content();
    passed++;

    fputs("[TEST] std/str: eq - different lengths\n", stdout);
    test_str__eq___different_lengths();
    passed++;

    fputs("[TEST] std/str: slice\n", stdout);
    test_str__slice();
    passed++;

    fputs("[TEST] std/str: starts_with\n", stdout);
    test_str__starts_with();
    passed++;

    fputs("[TEST] std/str: ends_with\n", stdout);
    test_str__ends_with();
    passed++;

    fputs("[TEST] std/str: contains\n", stdout);
    test_str__contains();
    passed++;

    fputs("[TEST] std/str: trim\n", stdout);
    test_str__trim();
    passed++;

    fputs("[TEST] std/str: trim - no whitespace\n", stdout);
    test_str__trim___no_whitespace();
    passed++;

    fputs("[TEST] std/str: index_of\n", stdout);
    test_str__index_of();
    passed++;

    fputs("[TEST] std/str: index_of_last\n", stdout);
    test_str__index_of_last();
    passed++;

    printf("[RESULT] %d passed, %d failed\n", passed, failed);
    return failed > 0 ? 1 : 0;
}
