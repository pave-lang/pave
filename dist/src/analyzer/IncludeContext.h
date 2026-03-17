#ifndef PAVE_INCLUDE_CONTEXT
#define PAVE_INCLUDE_CONTEXT

#include <analyzer/ParentCpp.h>
#include <stdbool.h>

struct Include;
struct IncludeContext;
struct HashMap_str_Type;
struct str;
struct Type;
struct StructC;
struct EnumC;
struct FunctionC;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 327 "src/analyzer/Include.pv"
struct IncludeContext {
    struct Include* include;
    struct IncludeContext* parent_context;
    struct HashMap_str_Type* types;
    struct HashMap_str_Type* values;
    struct ParentCpp parent;
};

#line 341 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type);

#line 345 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type);

#line 349 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type);

#line 357 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 367 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name);

#line 371 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name);

#line 377 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name);

#line 383 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name);

#line 389 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name);

#line 394 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name);

#line 426 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 449 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name);

#line 462 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name);

#line 475 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name);

#line 489 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name);

#line 503 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name);

#line 515 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
