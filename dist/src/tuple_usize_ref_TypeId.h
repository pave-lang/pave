#ifndef PAVE_TUPLE_USIZE_REF_TYPE_ID
#define PAVE_TUPLE_USIZE_REF_TYPE_ID

#include <stdint.h>

typedef uint64_t TypeId;
struct tuple_usize_ref_TypeId {
    uintptr_t _0;
    TypeId* _1;
};

#endif
