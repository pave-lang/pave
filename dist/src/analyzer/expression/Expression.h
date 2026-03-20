#ifndef PAVE_EXPRESSION
#define PAVE_EXPRESSION

#include <analyzer/expression/ExpressionData.h>
#include <analyzer/types/Type.h>
#include <stdbool.h>
#include <stdint.h>

struct Token;
struct Expression;
struct ArenaAllocator;
struct ExpressionData;
struct Type;
struct Context;
struct EnumVariantResult;
struct GenericMap;
struct Function;
struct Array_Type;
struct Array_InvokeArgument;
struct InvokeArgument;
struct EnumVariant;
struct Generics;

#include <stdlib.h>

#line 7 "src/analyzer/expression/Expression.pv"
struct Expression {
    struct Token* token;
    struct ExpressionData data;
    struct Type return_type;
};

#line 14 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make(struct ArenaAllocator* allocator, struct Token* token, struct ExpressionData data, struct Type* return_type);

#line 22 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_next(struct Context* context, struct Expression node);

#line 30 "src/analyzer/expression/Expression.pv"
struct EnumVariantResult Expression__get_enum_variant(struct Context* context, struct Type* type, struct Token* token);

#line 63 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_member_type(struct Context* context, struct Type* type, struct Token* member, bool output_error);

#line 239 "src/analyzer/expression/Expression.pv"
struct GenericMap* Expression__resolve_function_generics(struct Context* context, struct Function* func_info, struct Array_Type* generics, struct Array_InvokeArgument* arguments);

#line 266 "src/analyzer/expression/Expression.pv"
void Expression__resolve_generic_type(struct Context* context, struct Type* param_type, struct Type* arg_type, struct GenericMap* generic_map);

#line 284 "src/analyzer/expression/Expression.pv"
bool Expression__validate_arguments(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map, bool is_member_call);

#line 387 "src/analyzer/expression/Expression.pv"
bool Expression__validate_enum_arguments(struct Context* context, struct Token* token, struct EnumVariant* variant, struct Array_InvokeArgument* arguments, struct GenericMap* generic_map);

#line 420 "src/analyzer/expression/Expression.pv"
struct Type* Expression__get_return_type(struct Context* context, struct Type* type, struct Token* token, struct GenericMap* generic_map);

#line 434 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_type_function_call(struct Context* context, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 444 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__make_member_function_call(struct Context* context, struct Expression* inner, struct Token* token, struct Type* type, struct Array_InvokeArgument arguments, struct GenericMap* generic_map);

#line 453 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_enum(struct Context* context, struct Token* token, struct Type* enum_type, struct Generics* generics);

#line 514 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_struct(struct Context* context, struct Token* token, struct Type* struct_type, struct Generics* generics);

#line 628 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_class(struct Context* context, struct Token* token, struct Expression* parent, struct Generics* generics);

#line 687 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_cpp(struct Context* context, struct Generics* generics);

#line 714 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_type_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 735 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_instance_member_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 811 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_index_expression(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 902 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 984 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_binary(struct Context* context, struct Expression* lhs, uintptr_t min_prec, struct Generics* generics);

#line 1024 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_primary(struct Context* context, struct Generics* generics);

#line 1359 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse(struct Context* context, struct Generics* generics);

#line 1406 "src/analyzer/expression/Expression.pv"
bool Expression__is_zero(struct Expression* self);

#line 1413 "src/analyzer/expression/Expression.pv"
bool Expression__validate_type(struct Expression* self, struct Context* context, struct Type* type, bool apply_implicit_cast);

#line 1459 "src/analyzer/expression/Expression.pv"
uintptr_t Expression__get_precedence(struct Token* token);

#line 1476 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_postfix_chain(struct Context* context, struct Expression* inner, struct Generics* generics);

#line 1487 "src/analyzer/expression/Expression.pv"
struct Expression* Expression__parse_if_expression(struct Context* context, struct Generics* generics);

#endif
