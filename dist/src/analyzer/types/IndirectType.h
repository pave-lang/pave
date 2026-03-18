#ifndef PAVE_INDIRECT_TYPE
#define PAVE_INDIRECT_TYPE

#include <stdio.h>

#line 6 "src/analyzer/types/Type.pv"
enum IndirectType {
    INDIRECT_TYPE__REFERENCE,
    INDIRECT_TYPE__DYNAMIC_DISPATCH,
    INDIRECT_TYPE__POINTER,
    INDIRECT_TYPE__CONST_POINTER,
};

#endif
