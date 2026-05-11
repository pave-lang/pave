#ifndef PAVE_IMPL_NODE
#define PAVE_IMPL_NODE

#include <std/str.h>
#line 55 "src/analyzer/Impl.pv"
struct ImplNode {
    enum {
        IMPL_NODE__FUNCTION,
        IMPL_NODE__CONST,
    } type;

    union {
        struct str function_value;
        struct str const_value;
    };
};


#endif
