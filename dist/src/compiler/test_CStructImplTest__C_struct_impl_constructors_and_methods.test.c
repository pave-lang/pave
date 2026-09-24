#include <stdint.h>
#include <stdbool.h>

#include <c_struct_impl_test.h>
#include <assert.h>

#include <c_struct_impl_test.h>
#include <assert.h>
#include <PaveCImplPoint.h>
#include <i32.h>
#include <PaveCImplAlias.h>
#include <PaveCImplAnonymous.h>
#include <compiler/test_CStructImplTest__C_struct_impl_constructors_and_methods.test.h>

#line 1 "src/compiler/CStructImplTest.pv"
void test_CStructImplTest__C_struct_impl_constructors_and_methods() {
    #line 36 "src/compiler/CStructImplTest.pv"
    struct PaveCImplPoint point = PaveCImplPoint__new(7);
    #line 37 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(point.x, 7));
    #line 38 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(PaveCImplPoint__get(&point), 7));
    #line 39 "src/compiler/CStructImplTest.pv"
    PaveCImplPoint__set(&point, 9);
    #line 40 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(PaveCImplPoint__get(&point), 9));
    #line 41 "src/compiler/CStructImplTest.pv"
    struct PaveCImplPoint* reference = &point;
    #line 42 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(PaveCImplPoint__get(reference), 9));

    #line 44 "src/compiler/CStructImplTest.pv"
    PaveCImplAlias alias = PaveCImplAlias__from_alias(11);
    #line 45 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(alias.x, 11));
    #line 46 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(PaveCImplAlias__get(&alias), 11));

    #line 48 "src/compiler/CStructImplTest.pv"
    PaveCImplAnonymous anonymous = PaveCImplAnonymous__new(17);
    #line 49 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(anonymous.value, 17));
    #line 50 "src/compiler/CStructImplTest.pv"
    assert(i32__Eq_i32__eq(PaveCImplAnonymous__get(&anonymous), 17));
}
