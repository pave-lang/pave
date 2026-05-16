#ifndef PAVE_BLOCK_WRITER
#define PAVE_BLOCK_WRITER

#include <stdbool.h>

struct Generator;

#line 11 "src/compiler/BlockWriter.pv"
struct BlockWriter {
    struct Generator* generator;
};

#include <stdio.h>
#include <compiler/BlockWriter.h>
struct Generator;
struct BlockWriter;
struct Type;
struct EnumVariant;
struct Array_EnumVariantParameter;
struct Expression;
struct Block;
struct GenericMap;
struct Array_DeferStatement;

#line 16 "src/compiler/BlockWriter.pv"
struct BlockWriter BlockWriter__new(struct Generator* generator);

#line 20 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_if_let_enum_variant(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Type* type, struct EnumVariant* enum_variant, struct Array_EnumVariantParameter* parameters, struct Expression* expression, struct Block* body, struct Block* outer_block, struct GenericMap* generics);

#line 100 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_defer_statements(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics);

#line 122 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_block(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets);

#endif
