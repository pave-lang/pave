#if defined(__linux__) && !defined(_DEFAULT_SOURCE)
#define _DEFAULT_SOURCE
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

#include <std/test_ArenaAllocator__allocations_preserve_maximum_alignment.h>
#include <std/test_ArenaAllocator__aliases_share_allocation_ownership.h>
#include <std/test_ArenaAllocator__realloc_preserves_data_and_frees_the_old_allocation.h>
#include <std/test_ArenaAllocator__guarded_allocations_reject_interior_pointers.h>
#include <std/test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert.h>
#include <std/test_ArenaAllocator__destroy_works_through_an_allocator_stored_in_its_own_arena.h>
#include <std/test_HashMap__hash_collisions_compare_keys.h>
#include <std/test_HashMap__an_empty_map_literal_and_its_clone_take_inserts.h>
#include <std/test_HashSet__an_empty_set_literal_takes_inserts.h>
#include <std/test_str__eq___equal_strings.h>
#include <std/test_str__eq___different_content.h>
#include <std/test_str__eq___different_lengths.h>
#include <std/test_str__slice.h>
#include <std/test_str__starts_with.h>
#include <std/test_str__ends_with.h>
#include <std/test_str__contains.h>
#include <std/test_str__trim.h>
#include <std/test_str__trim___no_whitespace.h>
#include <std/test_str__index_of.h>
#include <std/test_str__index_of_last.h>
#include <tests/test_tests__basic_arithmetic.h>
#include <tests/test_tests__string_output.h>

typedef struct { const char* id; const char* name; void (*fn)(void); } PaveTest;

static const PaveTest pave_tests[] = {
    { "test_ArenaAllocator__allocations_preserve_maximum_alignment", "std/ArenaAllocator: allocations preserve maximum alignment", test_ArenaAllocator__allocations_preserve_maximum_alignment },
    { "test_ArenaAllocator__aliases_share_allocation_ownership", "std/ArenaAllocator: aliases share allocation ownership", test_ArenaAllocator__aliases_share_allocation_ownership },
    { "test_ArenaAllocator__realloc_preserves_data_and_frees_the_old_allocation", "std/ArenaAllocator: realloc preserves data and frees the old allocation", test_ArenaAllocator__realloc_preserves_data_and_frees_the_old_allocation },
    { "test_ArenaAllocator__guarded_allocations_reject_interior_pointers", "std/ArenaAllocator: guarded allocations reject interior pointers", test_ArenaAllocator__guarded_allocations_reject_interior_pointers },
    { "test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert", "std/ArenaAllocator: failed initialization cleans up and is inert", test_ArenaAllocator__failed_initialization_cleans_up_and_is_inert },
    { "test_ArenaAllocator__destroy_works_through_an_allocator_stored_in_its_own_arena", "std/ArenaAllocator: destroy works through an allocator stored in its own arena", test_ArenaAllocator__destroy_works_through_an_allocator_stored_in_its_own_arena },
    { "test_HashMap__hash_collisions_compare_keys", "std/HashMap: hash collisions compare keys", test_HashMap__hash_collisions_compare_keys },
    { "test_HashMap__an_empty_map_literal_and_its_clone_take_inserts", "std/HashMap: an empty map literal and its clone take inserts", test_HashMap__an_empty_map_literal_and_its_clone_take_inserts },
    { "test_HashSet__an_empty_set_literal_takes_inserts", "std/HashSet: an empty set literal takes inserts", test_HashSet__an_empty_set_literal_takes_inserts },
    { "test_str__eq___equal_strings", "std/str: eq - equal strings", test_str__eq___equal_strings },
    { "test_str__eq___different_content", "std/str: eq - different content", test_str__eq___different_content },
    { "test_str__eq___different_lengths", "std/str: eq - different lengths", test_str__eq___different_lengths },
    { "test_str__slice", "std/str: slice", test_str__slice },
    { "test_str__starts_with", "std/str: starts_with", test_str__starts_with },
    { "test_str__ends_with", "std/str: ends_with", test_str__ends_with },
    { "test_str__contains", "std/str: contains", test_str__contains },
    { "test_str__trim", "std/str: trim", test_str__trim },
    { "test_str__trim___no_whitespace", "std/str: trim - no whitespace", test_str__trim___no_whitespace },
    { "test_str__index_of", "std/str: index_of", test_str__index_of },
    { "test_str__index_of_last", "std/str: index_of_last", test_str__index_of_last },
    { "test_tests__basic_arithmetic", "tests/tests: basic arithmetic", test_tests__basic_arithmetic },
    { "test_tests__string_output", "tests/tests: string output", test_tests__string_output },
    { 0, 0, 0 }
};
static const int pave_test_count = (int)(sizeof(pave_tests) / sizeof(pave_tests[0])) - 1;

static int pave_test_matches(const PaveTest* test, int exact, int argc, char** argv) {
    int i;
    int filters = 0;
    for (i = 1; i < argc; i++) {
        if (argv[i] == NULL) continue;
        filters++;
        if (exact) {
            if (strcmp(test->id, argv[i]) == 0 || strcmp(test->name, argv[i]) == 0) return 1;
        } else if (strstr(test->name, argv[i]) != NULL) {
            return 1;
        }
    }
    return filters == 0;
}

static void pave_test_print_name(const char* name) {
    for (; *name; name++) {
        if (*name == '#') putchar('\\');
        putchar(*name);
    }
}

static int pave_test_isolated(int index, char* reason, size_t reason_size) {
    fflush(stdout);
    fflush(stderr);
#if defined(_WIN32)
    {
        char path[MAX_PATH];
        char index_arg[16];
        intptr_t status;
        DWORD length = GetModuleFileNameA(NULL, path, MAX_PATH);
        if (length == 0 || length >= MAX_PATH) { snprintf(reason, reason_size, "could not find the test executable"); return 1; }
        snprintf(index_arg, sizeof(index_arg), "%d", index);
        status = _spawnl(_P_WAIT, path, "pave-test", "--run-one", index_arg, NULL);
        if (status == -1) { snprintf(reason, reason_size, "could not start the test process"); return 1; }
        if (status == 0) return 0;
        snprintf(reason, reason_size, "exit code %ld (0x%08lx)", (long)status, (unsigned long)status);
        return 1;
    }
#else
    {
        int status = 0;
        pid_t pid = fork();
        if (pid < 0) { snprintf(reason, reason_size, "could not start the test process"); return 1; }
        if (pid == 0) {
            pave_tests[index].fn();
            fflush(stdout);
            fflush(stderr);
            _exit(0);
        }
        if (waitpid(pid, &status, 0) < 0) { snprintf(reason, reason_size, "could not wait for the test process"); return 1; }
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) return 0;
        if (WIFSIGNALED(status)) snprintf(reason, reason_size, "signal %d", WTERMSIG(status));
        else snprintf(reason, reason_size, "exit code %d", WEXITSTATUS(status));
        return 1;
    }
#endif
}

int main(int argc, char** argv) {
    int i;
    int exact = 0;
    int list = 0;
    int in_process = 0;
    int run_one = -1;
    int selected = 0;
    int filtered = 0;
    int number = 0;
    int passed = 0;
    int failed = 0;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--run-one") == 0 && i + 1 < argc) { run_one = atoi(argv[i + 1]); argv[i] = NULL; argv[++i] = NULL; }
        else if (strcmp(argv[i], "--exact") == 0) { exact = 1; argv[i] = NULL; }
        else if (strcmp(argv[i], "--list") == 0) { list = 1; argv[i] = NULL; }
        else if (strcmp(argv[i], "--in-process") == 0) { in_process = 1; argv[i] = NULL; }
        else if (strcmp(argv[i], "--help") == 0) {
            printf("usage: %s [--exact] [--list] [--in-process] [filter...]\n", argv[0]);
            return 0;
        }
        else filtered = 1;
    }

    if (run_one >= 0) {
        if (run_one >= pave_test_count) return 2;
#if defined(_MSC_VER)
        _set_abort_behavior(0, _CALL_REPORTFAULT);
#endif
        pave_tests[run_one].fn();
        return 0;
    }

    for (i = 0; i < pave_test_count; i++) {
        if (!pave_test_matches(&pave_tests[i], exact, argc, argv)) continue;
        selected++;
        if (list) printf("%s\t%s\n", pave_tests[i].id, pave_tests[i].name);
    }
    if (list) return 0;

#if defined(_WIN32)
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
#endif
    printf("TAP version 13\n1..%d\n", selected);
    for (i = 0; i < pave_test_count; i++) {
        char reason[128];
        int result = 0;
        if (!pave_test_matches(&pave_tests[i], exact, argc, argv)) continue;
        number++;
        reason[0] = 0;
        if (in_process) pave_tests[i].fn();
        else result = pave_test_isolated(i, reason, sizeof(reason));
        if (result == 0) { passed++; printf("ok %d - ", number); }
        else { failed++; printf("not ok %d - ", number); }
        pave_test_print_name(pave_tests[i].name);
        putchar('\n');
        if (result != 0) printf("# %s\n", reason);
        fflush(stdout);
    }

    printf("# %d passed, %d failed\n", passed, failed);
    if (filtered && selected == 0) { printf("# no tests matched\n"); return 1; }
    return failed > 0 ? 1 : 0;
}
