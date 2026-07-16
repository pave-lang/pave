#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <std/ArenaBlock.h>
#include <std/ArenaAllocator.h>
#include <std/ArenaOversize.h>
#include <std/trait_Any.h>
#include <std/ArenaAllocator.h>

#include <std/ArenaAllocator.h>

#line 150 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__alignment() {
    #line 151 "src/std/ArenaAllocator.pv"
    return __BIGGEST_ALIGNMENT__;
}

#line 154 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__align_up(uintptr_t value, uintptr_t alignment) {
    #line 155 "src/std/ArenaAllocator.pv"
    return ((value + alignment - 1) / alignment) * alignment;
}

#line 158 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size) {
    #line 159 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(allocator, block_size, 0);
    #line 160 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 160 "src/std/ArenaAllocator.pv"
        return (struct ArenaAllocator) { .allocator = allocator, .block_size = 0, .last_block = 0, .last_oversize = 0 };
    }

    #line 162 "src/std/ArenaAllocator.pv"
    return (struct ArenaAllocator) {
        .allocator = allocator,
        .block_size = block_size,
        .last_block = block,
        .last_oversize = 0,
    };
}

#line 170 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self) {
    #line 171 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;

    #line 173 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 174 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;
        #line 175 "src/std/ArenaAllocator.pv"
        self->allocator.vtable->fn_free(self->allocator.instance, oversize);
        #line 176 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 179 "src/std/ArenaAllocator.pv"
    self->last_oversize = 0;

    #line 181 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;

    #line 183 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 184 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, self)) {
            #line 185 "src/std/ArenaAllocator.pv"
            ArenaBlock__destroy(block, self->allocator);
            #line 186 "src/std/ArenaAllocator.pv"
            return;
        }

        #line 189 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;
        #line 190 "src/std/ArenaAllocator.pv"
        ArenaBlock__destroy(block, self->allocator);
        #line 191 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 194 "src/std/ArenaAllocator.pv"
    self->block_size = 0;
    #line 195 "src/std/ArenaAllocator.pv"
    self->last_block = 0;
}
#include <analyzer/types/Function.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Function* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Function));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Function));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericMap.h>

#line 198 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct GenericMap* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericMap));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericMap));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Type.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Type* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Type));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Type));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Indirect.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Indirect* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Indirect));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Indirect));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Primitive.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Primitive* ArenaAllocator__store_Primitive(struct ArenaAllocator* self, struct Primitive* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Primitive* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Primitive));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Primitive));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Block.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Block* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Block));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Block));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/AssignmentStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct AssignmentStatement* ArenaAllocator__store_AssignmentStatement(struct ArenaAllocator* self, struct AssignmentStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct AssignmentStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct AssignmentStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct AssignmentStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Scope.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Scope* ArenaAllocator__store_Scope(struct ArenaAllocator* self, struct Scope* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Scope* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Scope));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Scope));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Token.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Token* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Token));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Token));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericTypedef.h>

#line 198 "src/std/ArenaAllocator.pv"
struct GenericTypedef* ArenaAllocator__store_GenericTypedef(struct ArenaAllocator* self, struct GenericTypedef* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct GenericTypedef* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericTypedef));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericTypedef));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/UnknownC.h>

#line 198 "src/std/ArenaAllocator.pv"
struct UnknownC* ArenaAllocator__store_UnknownC(struct ArenaAllocator* self, struct UnknownC* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct UnknownC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct UnknownC));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct UnknownC));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Sequence.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Sequence* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Sequence));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Sequence));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Tuple.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Tuple* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Tuple));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Tuple));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Generic.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Generic* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Generic));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Generic));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/expression/Expression.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Expression* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Expression));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Expression));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/expression/ParsedArguments.h>

#line 198 "src/std/ArenaAllocator.pv"
struct ParsedArguments* ArenaAllocator__store_ParsedArguments(struct ArenaAllocator* self, struct ParsedArguments* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct ParsedArguments* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ParsedArguments));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ParsedArguments));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/DeferStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct DeferStatement* ArenaAllocator__store_DeferStatement(struct ArenaAllocator* self, struct DeferStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct DeferStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct DeferStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct DeferStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ForStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct ForStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ForStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ForStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchPattern.h>

#line 198 "src/std/ArenaAllocator.pv"
struct MatchPattern* ArenaAllocator__store_MatchPattern(struct ArenaAllocator* self, struct MatchPattern* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct MatchPattern* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchPattern));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchPattern));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/IfStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct IfStatement* ArenaAllocator__store_IfStatement(struct ArenaAllocator* self, struct IfStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct IfStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IfStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IfStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/LetStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct LetStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct LetStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct LetStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct MatchStatement* ArenaAllocator__store_MatchStatement(struct ArenaAllocator* self, struct MatchStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct MatchStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/PreprocessorIfStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct PreprocessorIfStatement* ArenaAllocator__store_PreprocessorIfStatement(struct ArenaAllocator* self, struct PreprocessorIfStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct PreprocessorIfStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct PreprocessorIfStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct PreprocessorIfStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ReturnStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct ReturnStatement* ArenaAllocator__store_ReturnStatement(struct ArenaAllocator* self, struct ReturnStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct ReturnStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ReturnStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ReturnStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/WhileStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct WhileStatement* ArenaAllocator__store_WhileStatement(struct ArenaAllocator* self, struct WhileStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct WhileStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct WhileStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct WhileStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/YieldStatement.h>

#line 198 "src/std/ArenaAllocator.pv"
struct YieldStatement* ArenaAllocator__store_YieldStatement(struct ArenaAllocator* self, struct YieldStatement* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct YieldStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct YieldStatement));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct YieldStatement));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/ClassCpp.h>

#line 198 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct ClassCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ClassCpp));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ClassCpp));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/EnumC.h>

#line 198 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct EnumC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct EnumC));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct EnumC));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/FunctionC.h>

#line 198 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct FunctionC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct FunctionC));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct FunctionC));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/Include.h>

#line 198 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct Include* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Include));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Include));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/IncludeContext.h>

#line 198 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct IncludeContext* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IncludeContext));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IncludeContext));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/NamespaceCpp.h>

#line 198 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct NamespaceCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct NamespaceCpp));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct NamespaceCpp));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/StructC.h>

#line 198 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct StructC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct StructC));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct StructC));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/TypedefC.h>

#line 198 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC* value) {
    #line 199 "src/std/ArenaAllocator.pv"
    struct TypedefC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct TypedefC));
    #line 200 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 202 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct TypedefC));
    #line 203 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 206 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__store_dyn(struct ArenaAllocator* self, struct trait_Any value) {
    #line 207 "src/std/ArenaAllocator.pv"
    uintptr_t size = value.vtable->fn_size(value.instance);
    #line 208 "src/std/ArenaAllocator.pv"
    void* new_memory = ArenaAllocator__Allocator__alloc(self, size);
    #line 209 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 209 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 211 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value.instance, size);
    #line 212 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 217 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 218 "src/std/ArenaAllocator.pv"
    if (size > self->block_size / 4) {
        #line 219 "src/std/ArenaAllocator.pv"
        uintptr_t data_offset = ArenaAllocator__align_up(sizeof(struct ArenaOversize), ArenaAllocator__alignment());
        #line 220 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = data_offset + size;
        #line 221 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = self->allocator.vtable->fn_alloc(self->allocator.instance, total_size);
        #line 222 "src/std/ArenaAllocator.pv"
        if (oversize == 0) {
            #line 222 "src/std/ArenaAllocator.pv"
            return 0;
        }
        #line 223 "src/std/ArenaAllocator.pv"
        void* oversize_void = oversize;
        #line 224 "src/std/ArenaAllocator.pv"
        uint8_t* oversize_bytes = oversize_void;
        #line 225 "src/std/ArenaAllocator.pv"
        oversize->size = size;
        #line 226 "src/std/ArenaAllocator.pv"
        oversize->data = oversize_bytes + data_offset;
        #line 227 "src/std/ArenaAllocator.pv"
        oversize->prev = self->last_oversize;
        #line 228 "src/std/ArenaAllocator.pv"
        self->last_oversize = oversize;
        #line 229 "src/std/ArenaAllocator.pv"
        return oversize->data;
    }

    #line 232 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* last_block = self->last_block;
    #line 233 "src/std/ArenaAllocator.pv"
    if (last_block == 0) {
        #line 233 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 235 "src/std/ArenaAllocator.pv"
    void* ptr = ArenaBlock__alloc(last_block, size);
    #line 236 "src/std/ArenaAllocator.pv"
    if (ptr != 0) {
        #line 236 "src/std/ArenaAllocator.pv"
        return ptr;
    }

    #line 238 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(self->allocator, self->block_size, self->last_block);
    #line 239 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 239 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 241 "src/std/ArenaAllocator.pv"
    self->last_block = block;
    #line 242 "src/std/ArenaAllocator.pv"
    return ArenaBlock__alloc(block, size);
}

#line 245 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 246 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 246 "src/std/ArenaAllocator.pv"
        return ArenaAllocator__Allocator__alloc(self, new_size);
    }

    #line 248 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 249 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 250 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 252 "src/std/ArenaAllocator.pv"
        if (ptr == oversize->data) {
            #line 253 "src/std/ArenaAllocator.pv"
            uintptr_t old_size = oversize->size;

            #line 255 "src/std/ArenaAllocator.pv"
            void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
            #line 256 "src/std/ArenaAllocator.pv"
            if (new_ptr == 0) {
                #line 256 "src/std/ArenaAllocator.pv"
                return 0;
            }

            #line 258 "src/std/ArenaAllocator.pv"
            if (new_size < old_size) {
                #line 259 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, new_size);
            } else {
                #line 261 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, old_size);
            }

            #line 264 "src/std/ArenaAllocator.pv"
            ArenaAllocator__Allocator__free(self, ptr);

            #line 266 "src/std/ArenaAllocator.pv"
            return new_ptr;
        }

        #line 269 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 272 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* current_block = 0;
    #line 273 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 274 "src/std/ArenaAllocator.pv"
    while (current_block == 0 && block != 0) {
        #line 275 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 276 "src/std/ArenaAllocator.pv"
            void* realloc_ptr = ArenaBlock__realloc(block, ptr, new_size);
            #line 277 "src/std/ArenaAllocator.pv"
            if (realloc_ptr != 0) {
                #line 277 "src/std/ArenaAllocator.pv"
                return realloc_ptr;
            }
            #line 278 "src/std/ArenaAllocator.pv"
            current_block = block;
        }

        #line 281 "src/std/ArenaAllocator.pv"
        block = block->prev;
    }

    #line 284 "src/std/ArenaAllocator.pv"
    if (current_block == 0) {
        #line 285 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No block found to reallocate from\n");
        #line 286 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 289 "src/std/ArenaAllocator.pv"
    uintptr_t old_size = ArenaBlock__size(current_block, ptr);

    #line 291 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
    #line 292 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 292 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 294 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, new_size < old_size ? new_size : old_size);
    #line 295 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(current_block, ptr);

    #line 297 "src/std/ArenaAllocator.pv"
    return new_ptr;
}

#line 300 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 301 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 301 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 303 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 304 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* next = 0;
    #line 305 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 306 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 308 "src/std/ArenaAllocator.pv"
        if (ptr == oversize->data) {
            #line 309 "src/std/ArenaAllocator.pv"
            if (self->last_oversize == oversize) {
                #line 309 "src/std/ArenaAllocator.pv"
                self->last_oversize = prev;
            }
            #line 310 "src/std/ArenaAllocator.pv"
            if (next != 0) {
                #line 310 "src/std/ArenaAllocator.pv"
                next->prev = prev;
            }

            #line 312 "src/std/ArenaAllocator.pv"
            return self->allocator.vtable->fn_free(self->allocator.instance, oversize);
        }

        #line 315 "src/std/ArenaAllocator.pv"
        next = oversize;
        #line 316 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 319 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 320 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 321 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 323 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 324 "src/std/ArenaAllocator.pv"
            return ArenaBlock__free(block, ptr);
        }

        #line 327 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 330 "src/std/ArenaAllocator.pv"
    return false;
}

struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR = { .fn_alloc = &ArenaAllocator__Allocator__alloc, .fn_realloc = &ArenaAllocator__Allocator__realloc, .fn_free = &ArenaAllocator__Allocator__free };
