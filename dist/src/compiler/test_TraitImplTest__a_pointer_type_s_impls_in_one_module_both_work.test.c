#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#include <stdlib.h>
#include <compiler/PaveTestThing.h>
#include <compiler/ptr_PaveTestThing.h>
#include <compiler/test_TraitImplTest__a_pointer_type_s_impls_in_one_module_both_work.test.h>

#line 1 "src/compiler/TraitImplTest.pv"
void test_TraitImplTest__a_pointer_type_s_impls_in_one_module_both_work() {
    #line 33 "src/compiler/TraitImplTest.pv"
    struct PaveTestThing thing = (struct PaveTestThing) { .value = 5 };
    #line 34 "src/compiler/TraitImplTest.pv"
    struct PaveTestThing* pointer = &thing;
    #line 35 "src/compiler/TraitImplTest.pv"
    if (ptr_PaveTestThing__PaveTestNamed__name(pointer) + ptr_PaveTestThing__PaveTestSized__size(pointer) != 3) {
        #line 35 "src/compiler/TraitImplTest.pv"
        abort();
    }
}
