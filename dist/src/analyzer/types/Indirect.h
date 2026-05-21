#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>

#line 15 "src/analyzer/types/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

#include <std/trait_Allocator.h>
#include <analyzer/types/Type.h>
struct Indirect;

#line 21 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to);

#line 27 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to);

#line 33 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to);

#line 39 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to);

#endif
