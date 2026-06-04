#ifndef PAVE_INCLUDE_WRITER
#define PAVE_INCLUDE_WRITER

#include <stdbool.h>

#include <std/HashSet_str.h>
struct ArenaAllocator;

#line 8 "src/compiler/IncludeWriter.pv"
struct IncludeWriter {
    struct ArenaAllocator* allocator;
    struct HashSet_str c_includes;
    struct HashSet_str includes;
    struct HashSet_str type_declarations;
};

#include <stdio.h>
#include <compiler/IncludeWriter.h>
struct ArenaAllocator;
struct Type;
struct GenericMap;
struct IncludeWriter;
struct Generator;
struct HashMap_str_Type;

#line 16 "src/compiler/IncludeWriter.pv"
struct IncludeWriter IncludeWriter__new(struct ArenaAllocator* allocator);

#line 25 "src/compiler/IncludeWriter.pv"
bool IncludeWriter__has_unresolved_generic(struct Type* type, struct GenericMap* generics_map);

#line 93 "src/compiler/IncludeWriter.pv"
void IncludeWriter__write(struct IncludeWriter* self, FILE* file, struct Generator* generator, struct HashMap_str_Type* types, struct GenericMap* generics, bool deref);

#line 281 "src/compiler/IncludeWriter.pv"
void IncludeWriter__release(struct IncludeWriter* self);

#endif
