#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <stdio.h>

#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>

#line 14 "src/analyzer/types/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

struct Indirect;
#include <std/trait_Allocator.h>
#include <analyzer/types/Type.h>

#line 20 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to);

#line 26 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to);

#line 32 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to);

#line 38 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to);

#endif
