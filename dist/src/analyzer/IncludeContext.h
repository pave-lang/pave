#ifndef PAVE_INCLUDE_CONTEXT
#define PAVE_INCLUDE_CONTEXT

#include <stdbool.h>

struct Include;
struct IncludeContext;
struct HashMap_str_Type;
struct str;
struct Type;
struct NamespaceCpp;
struct StructC;
struct EnumC;
struct FunctionC;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 318 "src/analyzer/Include.pv"
struct IncludeContext {
    struct Include* include;
    struct IncludeContext* parent;
    struct HashMap_str_Type* types;
    struct HashMap_str_Type* values;
    struct NamespaceCpp* namespace;
};

#line 332 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type);

#line 336 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type);

#line 340 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type);

#line 348 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 358 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name);

#line 362 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name);

#line 368 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name);

#line 374 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name);

#line 380 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name);

#line 385 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name);

#line 418 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor);

#line 441 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name);

#line 454 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name);

#line 467 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name);

#line 481 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name);

#line 495 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name);

#line 507 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
