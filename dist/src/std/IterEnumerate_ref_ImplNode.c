#include <stdint.h>

#include <std/IterEnumerate_ref_ImplNode.h>
#include <tuple_usize_ref_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/IterEnumerate_ref_ImplNode.h>

#include <std/IterEnumerate_ref_ImplNode.h>

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_ImplNode__next(struct IterEnumerate_ref_ImplNode* self) {
    #line 59 "src/std/Array.pv"
    if (!Iter_ref_ImplNode__next(&self->iter)) {
        #line 59 "src/std/Array.pv"
        return false;
    }
    #line 60 "src/std/Array.pv"
    self->index += 1;
    #line 61 "src/std/Array.pv"
    return true;
}

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_ImplNode IterEnumerate_ref_ImplNode__value(struct IterEnumerate_ref_ImplNode* self) {
    #line 65 "src/std/Array.pv"
    return (struct tuple_usize_ref_ImplNode) { ._0 = self->index - 1, ._1 = Iter_ref_ImplNode__value(&self->iter) };
}
