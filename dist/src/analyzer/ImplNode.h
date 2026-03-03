#ifndef PAVE_IMPL_NODE
#define PAVE_IMPL_NODE

#include <std/str.h>

#line 3 "src/analyzer/Impl.pv"
struct ImplNode {
    enum {
        IMPL_NODE__FUNCTION,
    } type;

    struct str function_value;
};

#endif
