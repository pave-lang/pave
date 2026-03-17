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

#line 8 "src/analyzer/Include.pv"
struct Include {
    struct Root* root;
    bool mode_cpp;
    struct str path;
    struct HashMap_u32_Type cxtype_to_type;
    struct HashMap_str_Type typedef_to_type;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 19 "src/analyzer/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp);

#line 77 "src/analyzer/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name);

#line 83 "src/analyzer/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name);

#line 88 "src/analyzer/Include.pv"
bool Include__process(struct Include* self);

#line 179 "src/analyzer/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type);

#line 260 "src/analyzer/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name);

#line 271 "src/analyzer/Include.pv"
char* Include__make_string(struct Include* self, CXString s);

#line 278 "src/analyzer/Include.pv"
struct str Include__make_str(struct Include* self, CXString s);

#line 285 "src/analyzer/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor);

#endif
