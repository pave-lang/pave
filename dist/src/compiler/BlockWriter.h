#ifndef PAVE_BLOCK_WRITER
#define PAVE_BLOCK_WRITER

#include <stdbool.h>
#include <stdint.h>

struct Generator;

#line 12 "src/compiler/BlockWriter.pv"
struct BlockWriter {
    struct Generator* generator;
};

#include <stdio.h>
#include <std/str.h>
struct Generator;
struct Type;
struct GenericMap;
struct Expression;
struct EnumVariant;
struct Array_EnumVariantParameter;
struct Block;
struct Array_DeferStatement;

#line 17 "src/compiler/BlockWriter.pv"
struct BlockWriter BlockWriter__new(struct Generator* generator);

#line 23 "src/compiler/BlockWriter.pv"
void BlockWriter__write_local(struct BlockWriter* self, FILE* file, struct str name, struct Type* type, struct GenericMap* generics);

#line 39 "src/compiler/BlockWriter.pv"
struct Expression* BlockWriter__bind_once(struct BlockWriter* self, FILE* file, struct Expression* expression, bool by_address, struct GenericMap* generics);

#line 64 "src/compiler/BlockWriter.pv"
void BlockWriter__write_break_label(struct BlockWriter* self, FILE* file, uintptr_t label);

#line 71 "src/compiler/BlockWriter.pv"
void BlockWriter__write_pattern_bindings(struct BlockWriter* self, FILE* file, struct Expression* expression, struct EnumVariant* enum_variant, struct Array_EnumVariantParameter* parameters, struct Block* outer_block, struct GenericMap* generics);

#line 125 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_if_let_enum_variant(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Type* type, struct EnumVariant* enum_variant, struct Array_EnumVariantParameter* parameters, struct Expression* expression, struct Block* body, struct Block* outer_block, struct GenericMap* generics);

#line 163 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_defer_statements(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics);

#line 190 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_block(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets);

#endif
