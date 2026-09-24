#include "c_struct_impl_test.h"
#include "assert.h"
#include <PaveCImplPoint.h>

#include <PaveCImplPoint.h>

#line 5 "src/compiler/CStructImplTest.pv"
struct PaveCImplPoint PaveCImplPoint__new(int32_t x) {
    #line 6 "src/compiler/CStructImplTest.pv"
    struct PaveCImplPoint result;
    #line 7 "src/compiler/CStructImplTest.pv"
    result.x = x;
    #line 8 "src/compiler/CStructImplTest.pv"
    return result;
}

#line 11 "src/compiler/CStructImplTest.pv"
int32_t PaveCImplPoint__get(struct PaveCImplPoint* self) {
    #line 11 "src/compiler/CStructImplTest.pv"
    return self->x;
}

#line 12 "src/compiler/CStructImplTest.pv"
void PaveCImplPoint__set(struct PaveCImplPoint* self, int32_t x) {
    #line 12 "src/compiler/CStructImplTest.pv"
    self->x = x;
}
