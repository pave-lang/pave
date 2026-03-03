#ifndef PAVE_ARENA_ALLOCATOR
#define PAVE_ARENA_ALLOCATOR

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct ArenaBlock;
struct ArenaOversize;
struct Function;
struct Type;
struct GenericMap;
struct Indirect;
struct Block;
struct LetStatement;
struct Token;
struct ForStatement;
struct Sequence;
struct Tuple;
struct Expression;
struct Include;
struct IncludeContext;
struct TypedefC;
struct EnumC;
struct StructC;
struct ClassCpp;
struct FunctionC;
struct NamespaceCpp;
struct Generic;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#line 5 "src/std/ArenaAllocator.pv"
struct ArenaAllocator {
    struct Allocator allocator;
    uintptr_t block_size;
    struct ArenaBlock* last_block;
    struct ArenaOversize* last_oversize;
};

#line 137 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct Allocator allocator, uintptr_t block_size);

#line 156 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self);

#line 174 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function value);

#line 174 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type value);

#line 174 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap value);

#line 174 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect value);

#line 174 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block value);

#line 174 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement value);

#line 174 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token value);

#line 174 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement value);

#line 174 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence value);

#line 174 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple value);

#line 174 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression value);

#line 174 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include value);

#line 174 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext value);

#line 174 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC value);

#line 174 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC value);

#line 174 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC value);

#line 174 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp value);

#line 174 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC value);

#line 174 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp value);

#line 174 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic value);

#line 184 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size);

#line 204 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size);

#line 274 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr);

extern struct AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR;

#endif
