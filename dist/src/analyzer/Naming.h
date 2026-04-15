#ifndef PAVE_NAMING
#define PAVE_NAMING

#include <stdio.h>

struct ArenaAllocator;
struct Naming;
#include <analyzer/NamingType.h>
#include <std/str.h>
#include <std/HashMap_str_str.h>

#line 13 "src/analyzer/Naming.pv"
struct Naming {
    struct ArenaAllocator* allocator;
    enum NamingType type;
    struct str generic_start;
    struct str generic_seperator;
    struct str generic_end;
    struct str pointer_prefix;
    struct str pointer_suffix;
    struct str pointer_const_prefix;
    struct str pointer_const_suffix;
    struct str reference_prefix;
    struct str reference_suffix;
    struct str sequence_slice_prefix;
    struct str sequence_open;
    struct str sequence_fixed_delimiter;
    struct str sequence_close;
    struct str tuple_prefix;
    struct str tuple_open;
    struct str tuple_close;
    struct str enum_generic_type_suffix;
    struct str enum_prefix;
    struct str struct_prefix;
    struct str trait_prefix;
    struct str union_prefix;
    struct str coroutine_instance_prefix;
    struct HashMap_str_str primitives;
    struct Naming* naming_ident;
};
struct ArenaAllocator;
struct Naming;
struct Type;
struct GenericMap;
struct GenericMap;
struct String;
#include <analyzer/Naming.h>
#include <std/String.h>
#include <std/str.h>
#include <analyzer/c/ParentCpp.h>


#line 43 "src/analyzer/Naming.pv"
struct Naming Naming__new_decl(struct ArenaAllocator* allocator);

#line 61 "src/analyzer/Naming.pv"
struct Naming Naming__new_ident(struct ArenaAllocator* allocator);

#line 77 "src/analyzer/Naming.pv"
struct Naming Naming__new_c99(struct ArenaAllocator* allocator, struct Naming* naming_ident);

#line 117 "src/analyzer/Naming.pv"
struct String Naming__get_type_name(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map);

#line 361 "src/analyzer/Naming.pv"
struct String Naming__get_type_decl(struct Naming* self, struct Type* type, struct Type* type_self, struct GenericMap* generics_map);

#line 389 "src/analyzer/Naming.pv"
struct String Naming__get_variable_decl(struct Naming* self, struct str variable_name, struct Type* type, struct Type* type_self, struct GenericMap* generics_map);

#line 421 "src/analyzer/Naming.pv"
void Naming__append_decl_suffix(struct Naming* self, struct String* result, struct Type* type);

#line 439 "src/analyzer/Naming.pv"
void Naming__append_cpp_path(struct Naming* self, struct String* result, struct ParentCpp parent);

#endif
