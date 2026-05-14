#ifndef PAVE_EXPRESSION
#define PAVE_EXPRESSION

#include <stdbool.h>
#include <stdint.h>

#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/Type.h>
struct Token;

#line 8 "src/analyzer/expression/Expression.pv"
struct Expression {
    struct Token* token;
    struct ExpressionData data;
    struct Type return_type;
};

#include <analyzer/expression/ExpressionData.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/Array_InvokeArgument.h>
#include <std/str.h>
struct ArenaAllocator;
struct Token;
struct Type;
struct Expression;
struct Context;
struct Function;
struct Array_Type;
struct Array_InvokeArgument;
struct GenericMap;
struct EnumVariant;
struct Generics;

#line 15 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type);

#line 23 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node);

#line 31 "src/analyzer/expression/Expression.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token);

#line 69 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error);

#line 267 "src/analyzer/expression/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments);

#line 316 "src/analyzer/expression/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map);

#line 334 "src/analyzer/expression/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call);

#line 444 "src/analyzer/expression/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map);

#line 477 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map);

#line 494 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 504 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 513 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics);

#line 607 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics);

#line 729 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics);

#line 788 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics);

#line 815 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 836 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 912 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 1004 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 1105 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics);

#line 1157 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__find_operator_trait_call(struct Context* context, struct Token* token, struct Expression* lhs, struct Type* lhs_type, struct str operator, struct Expression* rhs);

#line 1208 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value);

#line 1219 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics);

#line 1556 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics);

#line 1603 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self);

#line 1610 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast);

#line 1698 "src/analyzer/expression/Expression.pv"
uintptr_t Expression__get_precedence(struct Token* token);

#line 1715 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 1732 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics);

#endif
