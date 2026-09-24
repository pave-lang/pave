#include "c_struct_impl_test.h"
#include "assert.h"
#include <PaveCImplAnonymous.h>

#include <PaveCImplAnonymous.h>

#line 26 "src/compiler/CStructImplTest.pv"
PaveCImplAnonymous PaveCImplAnonymous__new(int32_t value) {
    #line 27 "src/compiler/CStructImplTest.pv"
    PaveCImplAnonymous result;
    #line 28 "src/compiler/CStructImplTest.pv"
    result.value = value;
    #line 29 "src/compiler/CStructImplTest.pv"
    return result;
}

#line 32 "src/compiler/CStructImplTest.pv"
int32_t PaveCImplAnonymous__get(PaveCImplAnonymous* self) {
    #line 32 "src/compiler/CStructImplTest.pv"
    return self->value;
}
