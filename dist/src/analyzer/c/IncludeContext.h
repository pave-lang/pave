#ifndef PAVE_INCLUDE_CONTEXT
#define PAVE_INCLUDE_CONTEXT

#include <stdbool.h>

#include <analyzer/c/ParentCpp.h>
struct Include;
struct IncludeContext;
struct HashMap_str_Type;

#line 8 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext {
    struct Include* include;
    struct IncludeContext* parent_context;
    struct HashMap_str_Type* types;
    struct HashMap_str_Type* values;
    struct ParentCpp parent;
};

#include <clang-c/Index.h>
#include <analyzer/types/Type.h>
struct IncludeContext;
struct Type;
struct StructC;
struct EnumC;
struct FunctionC;

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

#line 46 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name);

#line 52 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name);

#line 58 "src/analyzer/c/IncludeContext.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name);

#line 64 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name);

#line 69 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name);

#line 101 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 124 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name);

#line 137 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name);

#line 150 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name);

#line 164 "src/analyzer/c/IncludeContext.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name);

#line 178 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name);

#line 191 "src/analyzer/c/IncludeContext.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
