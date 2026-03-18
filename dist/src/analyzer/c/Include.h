#ifndef PAVE_INCLUDE
#define PAVE_INCLUDE

#include <stdbool.h>
#include <std/str.h>
#include <std/HashMap_u32_Type.h>
#include <stdint.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_Type.h>

struct Root;
struct str;
struct Type;
struct EnumC;

#include <clang-c/Index.h>
#include <string.h>

#line 9 "src/analyzer/c/Include.pv"
struct Include {
    struct Root* root;
    bool mode_cpp;
    struct str path;
    struct HashMap_u32_Type cxtype_to_type;
    struct HashMap_str_Type typedef_to_type;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 20 "src/analyzer/c/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp);

#line 78 "src/analyzer/c/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name);

#line 84 "src/analyzer/c/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name);

#line 89 "src/analyzer/c/Include.pv"
bool Include__process(struct Include* self);

#line 180 "src/analyzer/c/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type);

#line 261 "src/analyzer/c/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name);

#line 272 "src/analyzer/c/Include.pv"
char* Include__make_string(struct Include* self, CXString s);

#line 279 "src/analyzer/c/Include.pv"
struct str Include__make_str(struct Include* self, CXString s);

#line 286 "src/analyzer/c/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor);

#endif
