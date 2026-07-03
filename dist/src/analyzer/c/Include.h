#ifndef PAVE_INCLUDE
#define PAVE_INCLUDE

#include <stdbool.h>
#include <stdint.h>

#include <std/str.h>
#include <std/HashMap_u32_Type.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_i64.h>
struct Root;

#line 9 "src/analyzer/c/Include.pv"
struct Include {
    struct Root* root;
    bool mode_cpp;
    struct str path;
    struct HashMap_u32_Type cxtype_to_type;
    struct HashMap_str_Type typedef_to_type;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
    struct HashMap_str_i64 macro_values;
    struct str error;
};

#include <clang-c/Index.h>
#include <std/str.h>
struct Root;
struct Include;
struct Type;
struct EnumC;

#line 22 "src/analyzer/c/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp);

#line 93 "src/analyzer/c/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name);

#line 99 "src/analyzer/c/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name);

#line 104 "src/analyzer/c/Include.pv"
void Include__add_opaque_typedef(struct Include* self, char const* name);

#line 109 "src/analyzer/c/Include.pv"
void Include__add_basic_function(struct Include* self, char const* name);

#line 115 "src/analyzer/c/Include.pv"
bool Include__process(struct Include* self);

#line 217 "src/analyzer/c/Include.pv"
bool Include__report_diagnostics(struct Include* self, CXTranslationUnit unit);

#line 243 "src/analyzer/c/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type);

#line 324 "src/analyzer/c/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name);

#line 335 "src/analyzer/c/Include.pv"
char* Include__make_string(struct Include* self, CXString s);

#line 342 "src/analyzer/c/Include.pv"
struct str Include__make_str(struct Include* self, CXString s);

#line 349 "src/analyzer/c/Include.pv"
bool Include__try_parse_int_macro(struct Include* self, CXCursor cursor, int64_t* out);

#line 437 "src/analyzer/c/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor);

#endif
