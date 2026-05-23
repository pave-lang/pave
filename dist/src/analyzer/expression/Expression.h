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
#include <std/str.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/Array_InvokeArgument.h>
struct ArenaAllocator;
struct Token;
struct Type;
struct Expression;
struct Context;
struct Generics;
struct String;
struct Function;
struct Array_Type;
struct Array_InvokeArgument;
struct GenericMap;
struct EnumVariant;

#line 15 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type);

#line 23 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node);

#line 31 "src/analyzer/expression/Expression.pv"
struct str Expression__number_primitive(struct str value);

#line 42 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics);

#line 433 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics);

#line 480 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self);

#line 487 "src/analyzer/expression/Expression.pv"
bool Expression__is_const_expression(struct Expression* self, struct Context* context);

#line 525 "src/analyzer/expression/Expression.pv"
void Expression__append_ident_name(struct Expression* self, struct String* result);

#line 582 "src/analyzer/expression/Expression.pv"
void Expression__append_display_name(struct Expression* self, struct String* result);

#line 629 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast);

#line 759 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics);

#line 9 "src/analyzer/expression/MemberLookup.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token);

#line 55 "src/analyzer/expression/MemberLookup.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error);

#line 6 "src/analyzer/expression/GenericResolve.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments);

#line 58 "src/analyzer/expression/GenericResolve.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map);

#line 7 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call);

#line 147 "src/analyzer/expression/ExpressionValidate.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map);

#line 218 "src/analyzer/expression/ExpressionValidate.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map);

#line 235 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 245 "src/analyzer/expression/ExpressionValidate.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 7 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics);

#line 134 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics);

#line 303 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics);

#line 362 "src/analyzer/expression/ParseTypeExpression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics);

#line 7 "src/analyzer/expression/PostfixExpression.pv"
struct Type* Expression__make_optional_return_type(struct Context* context, struct Token* token, struct Type* type);

#line 26 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_optional_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 44 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 65 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 188 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 287 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 391 "src/analyzer/expression/PostfixExpression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 9 "src/analyzer/expression/BinaryExpression.pv"
bool Expression__build_narrow_path(struct Expression* self, struct String* out);

#line 32 "src/analyzer/expression/BinaryExpression.pv"
struct Type* Expression__detect_null_narrowing(struct Context* context, struct Expression* expr, bool narrow_on_true);

#line 98 "src/analyzer/expression/BinaryExpression.pv"
struct str Expression__narrowed_var_name(struct Context* context, struct Expression* expr, bool narrow_on_true);

#line 155 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics);

#line 243 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_operator_trait_call(struct Context* context, struct Token* token, struct Expression* lhs, struct Type* lhs_type, struct str operator, struct Expression* rhs);

#line 342 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_unary_trait_call(struct Context* context, struct Token* token, struct Expression* operand);

#line 391 "src/analyzer/expression/BinaryExpression.pv"
struct Expression* Expression__find_index_trait_call(struct Context* context, struct Token* token, struct Expression* inner, struct Expression* index_expr);

#line 438 "src/analyzer/expression/BinaryExpression.pv"
uintptr_t Expression__get_precedence(struct Token* token);

#endif
