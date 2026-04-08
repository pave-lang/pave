#ifndef PAVE_INCLUDE_CONTEXT
#define PAVE_INCLUDE_CONTEXT

#include <analyzer/c/ParentCpp.h>
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

#line 8 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext {
    struct Include* include;
    struct IncludeContext* parent_context;
    struct HashMap_str_Type* types;
    struct HashMap_str_Type* values;
    struct ParentCpp parent;
};

#line 17 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type);

#line 21 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type);

#line 25 "src/analyzer/c/IncludeContext.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type);

#line 31 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 41 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name);

#line 45 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name);

#line 51 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name);

#line 57 "src/analyzer/c/IncludeContext.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name);

#line 63 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name);

#line 68 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name);

#line 100 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 123 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name);

#line 136 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name);

#line 149 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name);

#line 163 "src/analyzer/c/IncludeContext.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name);

#line 177 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name);

#line 189 "src/analyzer/c/IncludeContext.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
