#ifndef PAVE_PAVE_CIMPL_POINT
#define PAVE_PAVE_CIMPL_POINT

#include "c_struct_impl_test.h"
#include "assert.h"
#include <stdint.h>


#line 5 "src/compiler/CStructImplTest.pv"
struct PaveCImplPoint PaveCImplPoint__new(int32_t x);
#line 11 "src/compiler/CStructImplTest.pv"
int32_t PaveCImplPoint__get(struct PaveCImplPoint* self);
#line 12 "src/compiler/CStructImplTest.pv"
void PaveCImplPoint__set(struct PaveCImplPoint* self, int32_t x);


#endif
