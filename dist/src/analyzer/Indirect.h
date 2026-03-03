#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <analyzer/IndirectType.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>

struct Type;

#include <stdio.h>

#line 11 "src/analyzer/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

#line 17 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_reference(struct Allocator allocator, struct Type to);

#line 23 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_pointer(struct Allocator allocator, struct Type to);

#line 29 "src/analyzer/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct Allocator allocator, struct Type to);

#endif
