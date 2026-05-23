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
#include <compiler/ExpressionWriter.h>
#include <std/str.h>
struct Generator;
struct ExpressionWriter;
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

#line 127 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__is_safe_to_duplicate(struct ExpressionWriter* self, struct Expression* expression);

#line 138 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__optional_needs_lowering(struct ExpressionWriter* self, struct Expression* expression);

#line 149 "src/compiler/ExpressionWriter.pv"
struct str ExpressionWriter__lower_optional_to_temp(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics, uintptr_t* count);

#line 179 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_optional_assignment(struct ExpressionWriter* self, FILE* file, struct str target_name, struct Type* target_type, struct Expression* expression, struct GenericMap* generics);

#line 208 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference);

#line 217 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics);

#line 263 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics);

#line 341 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics);

#line 396 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 453 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 497 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics);

#line 534 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics);

#line 739 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics);

#endif
