#ifndef PAVE_INCLUDE
#define PAVE_INCLUDE

#include <stdbool.h>
#include <std/str.h>
#include <std/HashMap_u32_Type.h>
#include <stdint.h>
#include <analyzer/Type.h>
#include <std/HashMap_str_Type.h>

struct Root;
struct str;
struct Type;
struct EnumC;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 7 "src/analyzer/Include.pv"
struct Include {
    struct Root* root;
    bool mode_cpp;
    struct str path;
    struct HashMap_u32_Type cxtype_to_type;
    struct HashMap_str_Type typedef_to_type;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 18 "src/analyzer/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp);

#line 76 "src/analyzer/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name);

#line 82 "src/analyzer/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name);

#line 87 "src/analyzer/Include.pv"
bool Include__process(struct Include* self);

#line 178 "src/analyzer/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type);

#line 225 "src/analyzer/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name);

#line 236 "src/analyzer/Include.pv"
char* Include__make_string(struct Include* self, CXString s);

#line 243 "src/analyzer/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor);

#endif
