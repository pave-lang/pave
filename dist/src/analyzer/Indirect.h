#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <analyzer/IndirectType.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

struct Type;

#include <stdio.h>

#line 12 "src/analyzer/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

#line 18 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to);

#line 24 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct Allocator allocator, struct Type to);

#line 30 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to);

#line 36 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to);

#endif
