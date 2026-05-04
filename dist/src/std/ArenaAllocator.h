#ifndef PAVE_ARENA_ALLOCATOR
#define PAVE_ARENA_ALLOCATOR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct ArenaBlock;
struct ArenaOversize;

#line 5 "src/std/ArenaAllocator.pv"
struct ArenaAllocator {
    struct trait_Allocator allocator;
    uintptr_t block_size;
    struct ArenaBlock* last_block;
    struct ArenaOversize* last_oversize;
};

#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
struct ArenaAllocator;

#line 136 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size);

#line 147 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self);
struct Function;

#line 165 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function* value);
struct GenericMap;

#line 165 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap* value);
struct Type;

#line 165 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type* value);
struct Indirect;

#line 165 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect* value);
struct Primitive;

#line 165 "src/std/ArenaAllocator.pv"
struct Primitive* ArenaAllocator__store_Primitive(struct ArenaAllocator* self, struct Primitive* value);
struct Block;

#line 165 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block* value);
struct AssignmentStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct AssignmentStatement* ArenaAllocator__store_AssignmentStatement(struct ArenaAllocator* self, struct AssignmentStatement* value);
struct Token;

#line 165 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token* value);
struct UnknownC;

#line 165 "src/std/ArenaAllocator.pv"
struct UnknownC* ArenaAllocator__store_UnknownC(struct ArenaAllocator* self, struct UnknownC* value);
struct Sequence;

#line 165 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence* value);
struct Tuple;

#line 165 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple* value);
struct Generic;

#line 165 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic* value);
struct Expression;

#line 165 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression* value);
struct DeferStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct DeferStatement* ArenaAllocator__store_DeferStatement(struct ArenaAllocator* self, struct DeferStatement* value);
struct ForStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement* value);
struct IfStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct IfStatement* ArenaAllocator__store_IfStatement(struct ArenaAllocator* self, struct IfStatement* value);
struct LetStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement* value);
struct MatchStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct MatchStatement* ArenaAllocator__store_MatchStatement(struct ArenaAllocator* self, struct MatchStatement* value);
struct ReturnStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct ReturnStatement* ArenaAllocator__store_ReturnStatement(struct ArenaAllocator* self, struct ReturnStatement* value);
struct WhileStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct WhileStatement* ArenaAllocator__store_WhileStatement(struct ArenaAllocator* self, struct WhileStatement* value);
struct YieldStatement;

#line 165 "src/std/ArenaAllocator.pv"
struct YieldStatement* ArenaAllocator__store_YieldStatement(struct ArenaAllocator* self, struct YieldStatement* value);
struct ClassCpp;

#line 165 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp* value);
struct EnumC;

#line 165 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC* value);
struct FunctionC;

#line 165 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC* value);
struct Include;

#line 165 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include* value);
struct IncludeContext;

#line 165 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext* value);
struct NamespaceCpp;

#line 165 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp* value);
struct StructC;

#line 165 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC* value);
struct TypedefC;

#line 165 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC* value);

#line 175 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size);

#line 195 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size);

#line 250 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr);

extern struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR;

#endif
