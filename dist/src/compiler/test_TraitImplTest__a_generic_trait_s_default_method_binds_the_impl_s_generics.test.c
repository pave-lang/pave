#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#include <stdlib.h>
#include <compiler/PaveTestCounter.h>
#include <compiler/trait_PaveTestHandler_i32.h>
#include <compiler/test_TraitImplTest__a_generic_trait_s_default_method_binds_the_impl_s_generics.test.h>

#line 1 "src/compiler/TraitImplTest.pv"
void test_TraitImplTest__a_generic_trait_s_default_method_binds_the_impl_s_generics() {
    #line 27 "src/compiler/TraitImplTest.pv"
    struct PaveTestCounter counter = (struct PaveTestCounter) { .count = 0 };
    #line 28 "src/compiler/TraitImplTest.pv"
    int32_t three = 3;
    #line 29 "src/compiler/TraitImplTest.pv"
    if (PaveTestCounter__PaveTestHandler_i32__doubled(&counter, &three) != 6) {
        #line 29 "src/compiler/TraitImplTest.pv"
        abort();
    }
}
