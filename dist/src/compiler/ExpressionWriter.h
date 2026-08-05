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

#line 184 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression);

#line 195 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression);

#line 206 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count);

#line 236 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics);

#line 265 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference);

#line 274 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 325 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_trait_value_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 354 "src/compiler/ExpressionWriter.pv"
struct Type* ExpressionWriter__should_use_trait_value_cast(struct ExpressionWriter* self, struct Type* element_type, struct Expression* arg);

#line 374 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics);

#line 452 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics);

#line 507 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 564 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 608 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics);

#line 652 "src/compiler/ExpressionWriter.pv"
struct Sequence* ExpressionWriter__get_typed_variadic_sequence(struct ExpressionWriter* self, struct Function* func_info);

#line 673 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_typed_variadic_slice(struct ExpressionWriter* self, FILE* file, struct Sequence* sequence, struct Array_InvokeArgument* arguments, uintptr_t start, struct GenericMap* generics);

#line 713 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 937 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics);

#endif
