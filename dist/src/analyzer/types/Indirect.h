#ifndef PAVE_INDIRECT
#define PAVE_INDIRECT

#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>

#line 16 "src/analyzer/types/Type.pv"
struct Indirect {
    enum IndirectType type;
    struct Type to;
};

#include <std/trait_Allocator.h>
#include <analyzer/types/Type.h>
struct Indirect;

#line 22 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_reference(struct trait_Allocator allocator, struct Type to);

#line 28 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch(struct trait_Allocator allocator, struct Type to);

#line 34 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_dynamic_dispatch_pointer(struct trait_Allocator allocator, struct Type to);

#line 40 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_pointer(struct trait_Allocator allocator, struct Type to);

#line 46 "src/analyzer/types/Type.pv"
struct Indirect* Indirect__new_const_pointer(struct trait_Allocator allocator, struct Type to);

#endif
