#ifndef PAVE_ARENA_ALLOCATOR
#define PAVE_ARENA_ALLOCATOR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>
struct ArenaBlock;
struct ArenaAlloc;

#line 6 "src/std/ArenaAllocator.pv"
struct ArenaAllocator {
    struct trait_Allocator allocator;
    uintptr_t block_size;
    struct ArenaBlock* last_block;
    struct ArenaAlloc* last_alloc;
};

#include <std/trait_Allocator.h>
#include <std/trait_Any.h>
struct ArenaAllocator;

#line 154 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__guarded_backend();

#line 168 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__alignment();

#line 172 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__align_up(uintptr_t value, uintptr_t alignment);

#line 176 "src/std/ArenaAllocator.pv"
struct ArenaAllocator* ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size);

#line 199 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self);
#include <std/ArenaAllocator.h>
struct Function;

#line 220 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function* value);
struct GenericMap;

#line 220 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap* value);
struct Type;

#line 220 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type* value);
struct Indirect;

#line 220 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect* value);
struct Primitive;

#line 220 "src/std/ArenaAllocator.pv"
struct Primitive* ArenaAllocator__store_Primitive(struct ArenaAllocator* self, struct Primitive* value);

#line 220 "src/std/ArenaAllocator.pv"
struct ArenaAllocator** ArenaAllocator__store_ptr_ArenaAllocator(struct ArenaAllocator* self, struct ArenaAllocator** value);
struct Block;

#line 220 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block* value);
struct AssignmentStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct AssignmentStatement* ArenaAllocator__store_AssignmentStatement(struct ArenaAllocator* self, struct AssignmentStatement* value);
struct Scope;

#line 220 "src/std/ArenaAllocator.pv"
struct Scope* ArenaAllocator__store_Scope(struct ArenaAllocator* self, struct Scope* value);
struct Token;

#line 220 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token* value);
struct GenericTypedef;

#line 220 "src/std/ArenaAllocator.pv"
struct GenericTypedef* ArenaAllocator__store_GenericTypedef(struct ArenaAllocator* self, struct GenericTypedef* value);
struct UnknownC;

#line 220 "src/std/ArenaAllocator.pv"
struct UnknownC* ArenaAllocator__store_UnknownC(struct ArenaAllocator* self, struct UnknownC* value);
struct Sequence;

#line 220 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence* value);
struct Tuple;

#line 220 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple* value);
struct Generic;

#line 220 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic* value);
struct Expression;

#line 220 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression* value);
struct ParsedArguments;

#line 220 "src/std/ArenaAllocator.pv"
struct ParsedArguments* ArenaAllocator__store_ParsedArguments(struct ArenaAllocator* self, struct ParsedArguments* value);
struct DeferStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct DeferStatement* ArenaAllocator__store_DeferStatement(struct ArenaAllocator* self, struct DeferStatement* value);
struct ForStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement* value);
struct MatchPattern;

#line 220 "src/std/ArenaAllocator.pv"
struct MatchPattern* ArenaAllocator__store_MatchPattern(struct ArenaAllocator* self, struct MatchPattern* value);
struct IfStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct IfStatement* ArenaAllocator__store_IfStatement(struct ArenaAllocator* self, struct IfStatement* value);
struct LetStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement* value);
struct MatchStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct MatchStatement* ArenaAllocator__store_MatchStatement(struct ArenaAllocator* self, struct MatchStatement* value);
struct PreprocessorIfStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct PreprocessorIfStatement* ArenaAllocator__store_PreprocessorIfStatement(struct ArenaAllocator* self, struct PreprocessorIfStatement* value);
struct ReturnStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct ReturnStatement* ArenaAllocator__store_ReturnStatement(struct ArenaAllocator* self, struct ReturnStatement* value);
struct WhileStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct WhileStatement* ArenaAllocator__store_WhileStatement(struct ArenaAllocator* self, struct WhileStatement* value);
struct YieldStatement;

#line 220 "src/std/ArenaAllocator.pv"
struct YieldStatement* ArenaAllocator__store_YieldStatement(struct ArenaAllocator* self, struct YieldStatement* value);
struct ClassCpp;

#line 220 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp* value);
struct EnumC;

#line 220 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC* value);
struct FunctionC;

#line 220 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC* value);
struct Include;

#line 220 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include* value);
struct IncludeContext;

#line 220 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext* value);
struct NamespaceCpp;

#line 220 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp* value);
struct StructC;

#line 220 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC* value);
struct TypedefC;

#line 220 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC* value);

#line 228 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__store_dyn(struct ArenaAllocator* self, struct trait_Any value);

#line 239 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size);

#line 268 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size);

#line 327 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr);

extern struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR;

#endif
