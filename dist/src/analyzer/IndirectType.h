#ifndef PAVE_INDIRECT_TYPE
#define PAVE_INDIRECT_TYPE

#include <stdio.h>

#line 5 "src/analyzer/Type.pv"
enum IndirectType {
    INDIRECT_TYPE__REFERENCE,
    INDIRECT_TYPE__DYNAMIC_DISPATCH,
    INDIRECT_TYPE__POINTER,
    INDIRECT_TYPE__CONST_POINTER,
};

#endif
