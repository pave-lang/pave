#include "c_struct_impl_test.h"
#include "assert.h"
#include <PaveCImplAlias.h>

#include <PaveCImplAlias.h>

#line 16 "src/compiler/CStructImplTest.pv"
PaveCImplAlias PaveCImplAlias__from_alias(int32_t x) {
    #line 17 "src/compiler/CStructImplTest.pv"
    PaveCImplAlias result;
    #line 18 "src/compiler/CStructImplTest.pv"
    result.x = x;
    #line 19 "src/compiler/CStructImplTest.pv"
    return result;
}

#line 22 "src/compiler/CStructImplTest.pv"
int32_t PaveCImplAlias__get(PaveCImplAlias* self) {
    #line 22 "src/compiler/CStructImplTest.pv"
    return self->x;
}
