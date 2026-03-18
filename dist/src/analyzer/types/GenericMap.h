#ifndef PAVE_GENERIC_MAP
#define PAVE_GENERIC_MAP

#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <stdbool.h>

struct Type;
struct ArenaAllocator;
struct Generics;
struct Array_Type;
struct str;
struct GenericMap;

#line 4 "src/analyzer/types/GenericMap.pv"
struct GenericMap {
    struct Type* self_type;
    struct Array_Type array;
    struct HashMap_str_usize map;
};

#line 11 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__new(struct ArenaAllocator* allocator, struct Generics* generics, struct Array_Type* usage_types);

#line 29 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__from_generics(struct ArenaAllocator* allocator, struct Generics* generics);

#line 42 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__clone(struct GenericMap* self, struct ArenaAllocator* allocator);

#line 50 "src/analyzer/types/GenericMap.pv"
bool GenericMap__has(struct GenericMap* self, struct str name);

#line 54 "src/analyzer/types/GenericMap.pv"
bool GenericMap__insert(struct GenericMap* self, struct str name, struct Type type);

#line 63 "src/analyzer/types/GenericMap.pv"
struct Type* GenericMap__get(struct GenericMap* self, struct str name);

#line 72 "src/analyzer/types/GenericMap.pv"
struct GenericMap GenericMap__resolve_types(struct GenericMap* self, struct ArenaAllocator* allocator, struct GenericMap* generics);

#endif
