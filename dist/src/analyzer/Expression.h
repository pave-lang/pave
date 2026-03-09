#ifndef PAVE_EXPRESSION
#define PAVE_EXPRESSION

#include <analyzer/ExpressionData.h>
#include <analyzer/Type.h>
#include <stdbool.h>

struct Token;
struct Expression;
struct ArenaAllocator;
struct ExpressionData;
struct Type;
struct Context;
struct EnumVariant;
struct GenericMap;
struct Function;
struct Array_Type;
struct Array_InvokeArgument;
struct InvokeArgument;
struct Generics;

#include <stdlib.h>

#line 31 "src/analyzer/Expression.pv"
struct Expression {
    struct Token* token;
    struct ExpressionData data;
    struct Type return_type;
};

#line 38 "src/analyzer/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type);

#line 46 "src/analyzer/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node);

#line 54 "src/analyzer/Expression.pv"
struct EnumVariant* Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token);

#line 74 "src/analyzer/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error);

#line 245 "src/analyzer/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments);

#line 272 "src/analyzer/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map);

#line 290 "src/analyzer/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call);

#line 393 "src/analyzer/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map);

#line 426 "src/analyzer/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map);

#line 440 "src/analyzer/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 450 "src/analyzer/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 459 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics);

#line 499 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics);

#line 613 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics);

#line 672 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics);

#line 699 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 720 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 796 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 887 "src/analyzer/Expression.pv"
struct Expression* Expression__parse_inner(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 971 "src/analyzer/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics);

#line 1334 "src/analyzer/Expression.pv"
bool Expression__is_zero(struct Expression* self);

#line 1341 "src/analyzer/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type);

#endif
