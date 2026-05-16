#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
#include <std/ArenaBlock.h>
#include <std/ArenaAllocator.h>
#include <std/ArenaOversize.h>
#include <std/ArenaAllocator.h>

#include <std/ArenaAllocator.h>

#line 136 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size) {
    #line 137 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(allocator, block_size, 0);
    #line 138 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 138 "src/std/ArenaAllocator.pv"
        return (struct ArenaAllocator) { .allocator = allocator, .block_size = 0, .last_block = 0, .last_oversize = 0 };
    }

    #line 140 "src/std/ArenaAllocator.pv"
    return (struct ArenaAllocator) {
        .allocator = allocator,
        .block_size = block_size,
        .last_block = block,
        .last_oversize = 0,
    };
}

#line 148 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self) {
    #line 149 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;

    #line 151 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 152 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, self)) {
            #line 153 "src/std/ArenaAllocator.pv"
            ArenaBlock__destroy(block, self->allocator);
            #line 154 "src/std/ArenaAllocator.pv"
            return;
        }

        #line 157 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;
        #line 158 "src/std/ArenaAllocator.pv"
        ArenaBlock__destroy(block, self->allocator);
        #line 159 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 162 "src/std/ArenaAllocator.pv"
    self->block_size = 0;
    #line 163 "src/std/ArenaAllocator.pv"
    self->last_block = 0;
}
#include <analyzer/types/Function.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Function* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Function));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Function));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericMap.h>

#line 166 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct GenericMap* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericMap));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericMap));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Type.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Type* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Type));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Type));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Indirect.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Indirect* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Indirect));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Indirect));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Primitive.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Primitive* ArenaAllocator__store_Primitive(struct ArenaAllocator* self, struct Primitive* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Primitive* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Primitive));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Primitive));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Block.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Block* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Block));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Block));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/AssignmentStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct AssignmentStatement* ArenaAllocator__store_AssignmentStatement(struct ArenaAllocator* self, struct AssignmentStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct AssignmentStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct AssignmentStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct AssignmentStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Token.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Token* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Token));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Token));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericTypedef.h>

#line 166 "src/std/ArenaAllocator.pv"
struct GenericTypedef* ArenaAllocator__store_GenericTypedef(struct ArenaAllocator* self, struct GenericTypedef* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct GenericTypedef* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericTypedef));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericTypedef));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/UnknownC.h>

#line 166 "src/std/ArenaAllocator.pv"
struct UnknownC* ArenaAllocator__store_UnknownC(struct ArenaAllocator* self, struct UnknownC* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct UnknownC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct UnknownC));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct UnknownC));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Sequence.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Sequence* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Sequence));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Sequence));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Tuple.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Tuple* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Tuple));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Tuple));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Generic.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Generic* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Generic));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Generic));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/expression/Expression.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Expression* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Expression));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Expression));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/DeferStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct DeferStatement* ArenaAllocator__store_DeferStatement(struct ArenaAllocator* self, struct DeferStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct DeferStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct DeferStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct DeferStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ForStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct ForStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ForStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ForStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchPattern.h>

#line 166 "src/std/ArenaAllocator.pv"
struct MatchPattern* ArenaAllocator__store_MatchPattern(struct ArenaAllocator* self, struct MatchPattern* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct MatchPattern* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchPattern));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchPattern));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/IfStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct IfStatement* ArenaAllocator__store_IfStatement(struct ArenaAllocator* self, struct IfStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct IfStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IfStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IfStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/LetStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct LetStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct LetStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct LetStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct MatchStatement* ArenaAllocator__store_MatchStatement(struct ArenaAllocator* self, struct MatchStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct MatchStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ReturnStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct ReturnStatement* ArenaAllocator__store_ReturnStatement(struct ArenaAllocator* self, struct ReturnStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct ReturnStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ReturnStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ReturnStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/WhileStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct WhileStatement* ArenaAllocator__store_WhileStatement(struct ArenaAllocator* self, struct WhileStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct WhileStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct WhileStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct WhileStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/YieldStatement.h>

#line 166 "src/std/ArenaAllocator.pv"
struct YieldStatement* ArenaAllocator__store_YieldStatement(struct ArenaAllocator* self, struct YieldStatement* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct YieldStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct YieldStatement));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct YieldStatement));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/ClassCpp.h>

#line 166 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct ClassCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ClassCpp));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ClassCpp));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/EnumC.h>

#line 166 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct EnumC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct EnumC));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct EnumC));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/FunctionC.h>

#line 166 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct FunctionC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct FunctionC));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct FunctionC));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/Include.h>

#line 166 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct Include* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Include));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Include));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/IncludeContext.h>

#line 166 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct IncludeContext* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IncludeContext));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IncludeContext));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/NamespaceCpp.h>

#line 166 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct NamespaceCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct NamespaceCpp));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct NamespaceCpp));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/StructC.h>

#line 166 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct StructC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct StructC));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct StructC));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/TypedefC.h>

#line 166 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC* value) {
    #line 167 "src/std/ArenaAllocator.pv"
    struct TypedefC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct TypedefC));
    #line 168 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 168 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct TypedefC));
    #line 171 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 176 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 177 "src/std/ArenaAllocator.pv"
    if (size > self->block_size / 4) {
        #line 178 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = sizeof(struct ArenaOversize) + size;
        #line 179 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = self->allocator.vtable->alloc(self->allocator.instance, total_size);
        #line 180 "src/std/ArenaAllocator.pv"
        oversize->size = size;
        #line 181 "src/std/ArenaAllocator.pv"
        oversize->prev = self->last_oversize;
        #line 182 "src/std/ArenaAllocator.pv"
        self->last_oversize = oversize;
        #line 183 "src/std/ArenaAllocator.pv"
        return oversize + 1;
    }

    #line 186 "src/std/ArenaAllocator.pv"
    void* ptr = ArenaBlock__alloc(self->last_block, size);
    #line 187 "src/std/ArenaAllocator.pv"
    if (ptr != 0) {
        #line 187 "src/std/ArenaAllocator.pv"
        return ptr;
    }

    #line 189 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(self->allocator, self->block_size, self->last_block);
    #line 190 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 190 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 192 "src/std/ArenaAllocator.pv"
    self->last_block = block;
    #line 193 "src/std/ArenaAllocator.pv"
    return ArenaBlock__alloc(self->last_block, size);
}

#line 196 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 197 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 197 "src/std/ArenaAllocator.pv"
        return ArenaAllocator__Allocator__alloc(self, new_size);
    }

    #line 199 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 200 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 201 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 203 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 204 "src/std/ArenaAllocator.pv"
            uintptr_t old_size = oversize->size;

            #line 206 "src/std/ArenaAllocator.pv"
            void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
            #line 207 "src/std/ArenaAllocator.pv"
            if (new_ptr == 0) {
                #line 207 "src/std/ArenaAllocator.pv"
                return 0;
            }

            #line 209 "src/std/ArenaAllocator.pv"
            if (new_size < old_size) {
                #line 210 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, new_size);
            } else {
                #line 212 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, old_size);
            }

            #line 215 "src/std/ArenaAllocator.pv"
            ArenaAllocator__Allocator__free(self, ptr);

            #line 217 "src/std/ArenaAllocator.pv"
            return new_ptr;
        }

        #line 220 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 223 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* current_block = 0;
    #line 224 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 225 "src/std/ArenaAllocator.pv"
    while (current_block == 0 && block != 0) {
        #line 226 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 227 "src/std/ArenaAllocator.pv"
            void* realloc_ptr = ArenaBlock__realloc(block, ptr, new_size);
            #line 228 "src/std/ArenaAllocator.pv"
            if (realloc_ptr != 0) {
                #line 228 "src/std/ArenaAllocator.pv"
                return realloc_ptr;
            }
            #line 229 "src/std/ArenaAllocator.pv"
            current_block = block;
        }

        #line 232 "src/std/ArenaAllocator.pv"
        block = block->prev;
    }

    #line 235 "src/std/ArenaAllocator.pv"
    if (current_block == 0) {
        #line 236 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No block found to reallocate from\n");
        #line 237 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 240 "src/std/ArenaAllocator.pv"
    uintptr_t old_size = ArenaBlock__size(current_block, ptr);

    #line 242 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
    #line 243 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 243 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 245 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, new_size < old_size ? new_size : old_size);
    #line 246 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(current_block, ptr);

    #line 248 "src/std/ArenaAllocator.pv"
    return new_ptr;
}

#line 251 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 252 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 252 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 254 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 255 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* next = 0;
    #line 256 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 257 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 259 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 260 "src/std/ArenaAllocator.pv"
            if (self->last_oversize == oversize) {
                #line 260 "src/std/ArenaAllocator.pv"
                self->last_oversize = prev;
            }
            #line 261 "src/std/ArenaAllocator.pv"
            if (next != 0) {
                #line 261 "src/std/ArenaAllocator.pv"
                next->prev = prev;
            }

            #line 263 "src/std/ArenaAllocator.pv"
            return self->allocator.vtable->free(self->allocator.instance, oversize);
        }

        #line 266 "src/std/ArenaAllocator.pv"
        next = oversize;
        #line 267 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 270 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 271 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 272 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 274 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 275 "src/std/ArenaAllocator.pv"
            return ArenaBlock__free(block, ptr);
        }

        #line 278 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 281 "src/std/ArenaAllocator.pv"
    return false;
}

struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR = { .alloc = &ArenaAllocator__Allocator__alloc, .realloc = &ArenaAllocator__Allocator__realloc, .free = &ArenaAllocator__Allocator__free };
