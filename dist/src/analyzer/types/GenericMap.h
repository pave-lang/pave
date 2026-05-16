#ifndef PAVE_GENERIC_MAP
#define PAVE_GENERIC_MAP

#include <stdbool.h>

#include <std/Array_Type.h>
#include <std/HashMap_str_usize.h>
struct Type;

#line 4 "src/analyzer/types/GenericMap.pv"
struct GenericMap {
    struct Type* self_type;
    struct Array_Type array;
    struct HashMap_str_usize map;
};

#include <analyzer/types/GenericMap.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
struct ArenaAllocator;
struct Generics;
struct Array_Type;
struct GenericMap;
struct Type;

#line 11 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__new(struct ArenaAllocator* allocator, struct Generics* generics, struct Array_Type* usage_types);

#line 30 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__from_generics(struct ArenaAllocator* allocator, struct Generics* generics);

#line 44 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__clone(struct GenericMap* self, struct ArenaAllocator* allocator);

#line 52 "src/analyzer/types/GenericMap.pv"
bool GenericMap__has(struct GenericMap* self, struct str name);

#line 56 "src/analyzer/types/GenericMap.pv"
bool GenericMap__insert(struct GenericMap* self, struct str name, struct Type type);

#line 65 "src/analyzer/types/GenericMap.pv"
struct Type* GenericMap__get(struct GenericMap* self, struct str name);

#line 74 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__resolve_types(struct GenericMap* self, struct ArenaAllocator* allocator, struct GenericMap* generics);

#endif
