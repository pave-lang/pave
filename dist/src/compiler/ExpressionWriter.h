#ifndef PAVE_EXPRESSION_WRITER
#define PAVE_EXPRESSION_WRITER

#include <stdint.h>
#include <stdbool.h>

struct Generator;

#line 9 "src/compiler/ExpressionWriter.pv"
struct ExpressionWriter {
    struct Generator* generator;
};

#include <stdio.h>
#include <std/str.h>
struct Generator;
struct Expression;
struct Type;
struct GenericMap;
struct Sequence;
struct Array_InvokeArgument;
struct EnumVariant;
struct Function;

#line 14 "src/compiler/ExpressionWriter.pv"
struct ExpressionWriter ExpressionWriter__new(struct Generator* generator);

#line 18 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__make_optional_temp_name(struct ExpressionWriter* self, uintptr_t* count);

#line 26 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression_replacing(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Expression* replace, struct str replacement_name, struct Type* replacement_type, struct GenericMap* generics);

#line 186 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_pure(struct ExpressionWriter* self, struct Expression* expression);

#line 207 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_place(struct ExpressionWriter* self, struct Expression* expression);

#line 221 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__make_temp(struct ExpressionWriter* self, struct Type* type);

#line 228 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_unary_operator(struct ExpressionWriter* self, FILE* file, struct str operator, struct Expression* inner);

#line 248 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression);

#line 259 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression);

#line 270 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count);

#line 300 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics);

#line 329 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference);

#line 352 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 403 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 432 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg);

#line 452 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics);

#line 530 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics);

#line 585 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 642 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 686 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics);

#line 730 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info);

#line 751 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics);

#line 794 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__returns_cpp_reference(struct Type* function);

#line 811 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 822 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke_call(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 1066 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics);

#endif
