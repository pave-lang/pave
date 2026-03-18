#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>

struct Type;

#include <stdio.h>

#line 13 "src/analyzer/types/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

#line 19 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to);

#line 25 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct Allocator allocator, struct Type to);

#line 31 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to);

#line 37 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to);

#endif
