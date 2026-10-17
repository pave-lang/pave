#include <stdlib.h>

#include <compiler/trait_PaveTestHandler_i32.h>
#include <compiler/PaveTestCounter.h>

#include <compiler/PaveTestCounter.h>

#line 16 "src/compiler/TraitImplTest.pv"
int32_t PaveTestCounter__PaveTestHandler_i32__handle(void* __self, int32_t* value) {
    struct PaveTestCounter* self = __self; (void)self;
    #line 16 "src/compiler/TraitImplTest.pv"
    self->count += *value;
    #line 16 "src/compiler/TraitImplTest.pv"
    return self->count;
}

#line 10 "src/compiler/TraitImplTest.pv"
int32_t PaveTestCounter__PaveTestHandler_i32__doubled(void* __self, int32_t* value) {
    struct PaveTestCounter* self = __self; (void)self;
    #line 10 "src/compiler/TraitImplTest.pv"
    return PaveTestCounter__PaveTestHandler_i32__handle(self, value) * 2;
}

struct trait_PaveTestHandler_i32VTable PAVE_TEST_COUNTER__VTABLE__PAVE_TEST_HANDLER = { .fn_handle = &PaveTestCounter__PaveTestHandler_i32__handle, .fn_doubled = &PaveTestCounter__PaveTestHandler_i32__doubled };
