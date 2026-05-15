#include <stdio.h>

#include <std/__pave_test_0.h>
#include <std/__pave_test_1.h>
#include <std/__pave_test_2.h>
#include <std/__pave_test_3.h>
#include <std/__pave_test_4.h>
#include <std/__pave_test_5.h>
#include <std/__pave_test_6.h>
#include <std/__pave_test_7.h>
#include <std/__pave_test_8.h>
#include <std/__pave_test_9.h>
#include <std/__pave_test_10.h>

int main(void) {
    int passed = 0;
    int failed = 0;

    fputs("[TEST] eq - equal strings\n", stdout);
    __pave_test_0();
    passed++;

    fputs("[TEST] eq - different content\n", stdout);
    __pave_test_1();
    passed++;

    fputs("[TEST] eq - different lengths\n", stdout);
    __pave_test_2();
    passed++;

    fputs("[TEST] slice\n", stdout);
    __pave_test_3();
    passed++;

    fputs("[TEST] starts_with\n", stdout);
    __pave_test_4();
    passed++;

    fputs("[TEST] ends_with\n", stdout);
    __pave_test_5();
    passed++;

    fputs("[TEST] contains\n", stdout);
    __pave_test_6();
    passed++;

    fputs("[TEST] trim\n", stdout);
    __pave_test_7();
    passed++;

    fputs("[TEST] trim - no whitespace\n", stdout);
    __pave_test_8();
    passed++;

    fputs("[TEST] index_of\n", stdout);
    __pave_test_9();
    passed++;

    fputs("[TEST] index_of_last\n", stdout);
    __pave_test_10();
    passed++;

    printf("[RESULT] %d passed, %d failed\n", passed, failed);
    return failed > 0 ? 1 : 0;
}
