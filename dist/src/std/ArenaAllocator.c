#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <std/ArenaState.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/ArenaBlock.h>
#include <std/ArenaOversize.h>
#include <std/trait_Any.h>
#include <std/ArenaAllocator.h>

#include <std/ArenaAllocator.h>

#line 158 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__guarded_backend() {
    #line 159 "src/std/ArenaAllocator.pv"
    #if defined ( __has_feature )
    #line 160 "src/std/ArenaAllocator.pv"
    #if __has_feature ( address_sanitizer )
    #line 161 "src/std/ArenaAllocator.pv"
    return true;
    #else
    #line 163 "src/std/ArenaAllocator.pv"
    return false;
    #endif
    #elif defined ( __SANITIZE_ADDRESS__ )
    #line 166 "src/std/ArenaAllocator.pv"
    return true;
    #else
    #line 168 "src/std/ArenaAllocator.pv"
    return false;
    #endif
}

#line 172 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__alignment() {
    #line 173 "src/std/ArenaAllocator.pv"
    return __BIGGEST_ALIGNMENT__;
}

#line 176 "src/std/ArenaAllocator.pv"
uintptr_t ArenaAllocator__align_up(uintptr_t value, uintptr_t alignment) {
    #line 177 "src/std/ArenaAllocator.pv"
    return ((value + alignment - 1) / alignment) * alignment;
}

#line 180 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size) {
    #line 181 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct ArenaState));
    #line 182 "src/std/ArenaAllocator.pv"
    if (state == 0) {
        #line 182 "src/std/ArenaAllocator.pv"
        return (struct ArenaAllocator) { .state = 0 };
    }

    #line 184 "src/std/ArenaAllocator.pv"
    *state = (struct ArenaState) {
        .allocator = allocator,
        .block_size = block_size,
        .last_block = 0,
        .last_oversize = 0,
    };

    #line 191 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__guarded_backend()) {
        #line 192 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* block = ArenaBlock__new(allocator, block_size, 0);
        #line 193 "src/std/ArenaAllocator.pv"
        if (block == 0) {
            #line 194 "src/std/ArenaAllocator.pv"
            allocator.vtable->fn_free(allocator.instance, state);
            #line 195 "src/std/ArenaAllocator.pv"
            return (struct ArenaAllocator) { .state = 0 };
        }
        #line 197 "src/std/ArenaAllocator.pv"
        state->last_block = block;
    }

    #line 200 "src/std/ArenaAllocator.pv"
    return (struct ArenaAllocator) { .state = state };
}

#line 203 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self) {
    #line 204 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = self->state;
    #line 205 "src/std/ArenaAllocator.pv"
    if (state == 0) {
        #line 205 "src/std/ArenaAllocator.pv"
        return;
    }
    #line 206 "src/std/ArenaAllocator.pv"
    struct trait_Allocator allocator = state->allocator;

    #line 208 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = state->last_oversize;
    #line 209 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 210 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;
        #line 211 "src/std/ArenaAllocator.pv"
        allocator.vtable->fn_free(allocator.instance, oversize->data);
        #line 212 "src/std/ArenaAllocator.pv"
        allocator.vtable->fn_free(allocator.instance, oversize);
        #line 213 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 216 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = state->last_block;
    #line 217 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 218 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;
        #line 219 "src/std/ArenaAllocator.pv"
        ArenaBlock__destroy(block, allocator);
        #line 220 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 223 "src/std/ArenaAllocator.pv"
    allocator.vtable->fn_free(allocator.instance, state);
}
#include <analyzer/types/Function.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Function* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Function));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Function));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericMap.h>

#line 226 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct GenericMap* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericMap));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericMap));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Type.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Type* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Type));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Type));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Indirect.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Indirect* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Indirect));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Indirect));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Primitive.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Primitive* ArenaAllocator__store_Primitive(struct ArenaAllocator* self, struct Primitive* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Primitive* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Primitive));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Primitive));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 226 "src/std/ArenaAllocator.pv"
struct ArenaAllocator* ArenaAllocator__store_ArenaAllocator(struct ArenaAllocator* self, struct ArenaAllocator* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ArenaAllocator));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ArenaAllocator));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Block.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Block* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Block));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Block));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/AssignmentStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct AssignmentStatement* ArenaAllocator__store_AssignmentStatement(struct ArenaAllocator* self, struct AssignmentStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct AssignmentStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct AssignmentStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct AssignmentStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Scope.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Scope* ArenaAllocator__store_Scope(struct ArenaAllocator* self, struct Scope* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Scope* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Scope));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Scope));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/Token.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Token* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Token));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Token));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/GenericTypedef.h>

#line 226 "src/std/ArenaAllocator.pv"
struct GenericTypedef* ArenaAllocator__store_GenericTypedef(struct ArenaAllocator* self, struct GenericTypedef* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct GenericTypedef* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericTypedef));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct GenericTypedef));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/UnknownC.h>

#line 226 "src/std/ArenaAllocator.pv"
struct UnknownC* ArenaAllocator__store_UnknownC(struct ArenaAllocator* self, struct UnknownC* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct UnknownC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct UnknownC));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct UnknownC));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Sequence.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Sequence* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Sequence));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Sequence));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Tuple.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Tuple* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Tuple));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Tuple));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/types/Generic.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Generic* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Generic));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Generic));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/expression/Expression.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Expression* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Expression));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Expression));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/expression/ParsedArguments.h>

#line 226 "src/std/ArenaAllocator.pv"
struct ParsedArguments* ArenaAllocator__store_ParsedArguments(struct ArenaAllocator* self, struct ParsedArguments* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct ParsedArguments* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ParsedArguments));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ParsedArguments));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/DeferStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct DeferStatement* ArenaAllocator__store_DeferStatement(struct ArenaAllocator* self, struct DeferStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct DeferStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct DeferStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct DeferStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ForStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct ForStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ForStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ForStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchPattern.h>

#line 226 "src/std/ArenaAllocator.pv"
struct MatchPattern* ArenaAllocator__store_MatchPattern(struct ArenaAllocator* self, struct MatchPattern* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct MatchPattern* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchPattern));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchPattern));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/IfStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct IfStatement* ArenaAllocator__store_IfStatement(struct ArenaAllocator* self, struct IfStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct IfStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IfStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IfStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/LetStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct LetStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct LetStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct LetStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/MatchStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct MatchStatement* ArenaAllocator__store_MatchStatement(struct ArenaAllocator* self, struct MatchStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct MatchStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct MatchStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct MatchStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/PreprocessorIfStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct PreprocessorIfStatement* ArenaAllocator__store_PreprocessorIfStatement(struct ArenaAllocator* self, struct PreprocessorIfStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct PreprocessorIfStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct PreprocessorIfStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct PreprocessorIfStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/ReturnStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct ReturnStatement* ArenaAllocator__store_ReturnStatement(struct ArenaAllocator* self, struct ReturnStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct ReturnStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ReturnStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ReturnStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/WhileStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct WhileStatement* ArenaAllocator__store_WhileStatement(struct ArenaAllocator* self, struct WhileStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct WhileStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct WhileStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct WhileStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/statement/YieldStatement.h>

#line 226 "src/std/ArenaAllocator.pv"
struct YieldStatement* ArenaAllocator__store_YieldStatement(struct ArenaAllocator* self, struct YieldStatement* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct YieldStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct YieldStatement));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct YieldStatement));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/ClassCpp.h>

#line 226 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct ClassCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ClassCpp));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct ClassCpp));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/EnumC.h>

#line 226 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct EnumC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct EnumC));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct EnumC));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/FunctionC.h>

#line 226 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct FunctionC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct FunctionC));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct FunctionC));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/Include.h>

#line 226 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct Include* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Include));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct Include));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/IncludeContext.h>

#line 226 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct IncludeContext* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IncludeContext));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct IncludeContext));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/NamespaceCpp.h>

#line 226 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct NamespaceCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct NamespaceCpp));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct NamespaceCpp));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/StructC.h>

#line 226 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct StructC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct StructC));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct StructC));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}
#include <analyzer/c/TypedefC.h>

#line 226 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC* value) {
    #line 227 "src/std/ArenaAllocator.pv"
    struct TypedefC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct TypedefC));
    #line 228 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 228 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 230 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value, sizeof(struct TypedefC));
    #line 231 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 234 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__store_dyn(struct ArenaAllocator* self, struct trait_Any value) {
    #line 235 "src/std/ArenaAllocator.pv"
    uintptr_t size = value.vtable->fn_size(value.instance);
    #line 236 "src/std/ArenaAllocator.pv"
    void* new_memory = ArenaAllocator__Allocator__alloc(self, size);
    #line 237 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 237 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 239 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, value.instance, size);
    #line 240 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 245 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 246 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = self->state;
    #line 247 "src/std/ArenaAllocator.pv"
    if (state == 0) {
        #line 247 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 249 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__guarded_backend() || size > state->block_size / 4) {
        #line 250 "src/std/ArenaAllocator.pv"
        void* data = state->allocator.vtable->fn_alloc(state->allocator.instance, size);
        #line 251 "src/std/ArenaAllocator.pv"
        if (data == 0) {
            #line 251 "src/std/ArenaAllocator.pv"
            return 0;
        }

        #line 253 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = state->allocator.vtable->fn_alloc(state->allocator.instance, sizeof(struct ArenaOversize));
        #line 254 "src/std/ArenaAllocator.pv"
        if (oversize == 0) {
            #line 255 "src/std/ArenaAllocator.pv"
            state->allocator.vtable->fn_free(state->allocator.instance, data);
            #line 256 "src/std/ArenaAllocator.pv"
            return 0;
        }

        #line 259 "src/std/ArenaAllocator.pv"
        *oversize = (struct ArenaOversize) { .data = data, .size = size, .prev = state->last_oversize };
        #line 260 "src/std/ArenaAllocator.pv"
        state->last_oversize = oversize;
        #line 261 "src/std/ArenaAllocator.pv"
        return data;
    }

    #line 264 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* last_block = state->last_block;
    #line 265 "src/std/ArenaAllocator.pv"
    if (last_block == 0) {
        #line 265 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 267 "src/std/ArenaAllocator.pv"
    void* ptr = ArenaBlock__alloc(last_block, size);
    #line 268 "src/std/ArenaAllocator.pv"
    if (ptr != 0) {
        #line 268 "src/std/ArenaAllocator.pv"
        return ptr;
    }

    #line 270 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(state->allocator, state->block_size, state->last_block);
    #line 271 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 271 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 273 "src/std/ArenaAllocator.pv"
    state->last_block = block;
    #line 274 "src/std/ArenaAllocator.pv"
    return ArenaBlock__alloc(block, size);
}

#line 277 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 278 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 278 "src/std/ArenaAllocator.pv"
        return ArenaAllocator__Allocator__alloc(self, new_size);
    }
    #line 279 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = self->state;
    #line 280 "src/std/ArenaAllocator.pv"
    if (state == 0) {
        #line 280 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 282 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = state->last_oversize;
    #line 283 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 284 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 286 "src/std/ArenaAllocator.pv"
        if (ptr == oversize->data) {
            #line 287 "src/std/ArenaAllocator.pv"
            uintptr_t old_size = oversize->size;

            #line 289 "src/std/ArenaAllocator.pv"
            void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
            #line 290 "src/std/ArenaAllocator.pv"
            if (new_ptr == 0) {
                #line 290 "src/std/ArenaAllocator.pv"
                return 0;
            }

            #line 292 "src/std/ArenaAllocator.pv"
            if (new_size < old_size) {
                #line 293 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, new_size);
            } else {
                #line 295 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, old_size);
            }

            #line 298 "src/std/ArenaAllocator.pv"
            ArenaAllocator__Allocator__free(self, ptr);

            #line 300 "src/std/ArenaAllocator.pv"
            return new_ptr;
        }

        #line 303 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 306 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__guarded_backend()) {
        #line 307 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No allocation found to reallocate\n");
        #line 308 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 311 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* current_block = 0;
    #line 312 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = state->last_block;
    #line 313 "src/std/ArenaAllocator.pv"
    while (current_block == 0 && block != 0) {
        #line 314 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 315 "src/std/ArenaAllocator.pv"
            void* realloc_ptr = ArenaBlock__realloc(block, ptr, new_size);
            #line 316 "src/std/ArenaAllocator.pv"
            if (realloc_ptr != 0) {
                #line 316 "src/std/ArenaAllocator.pv"
                return realloc_ptr;
            }
            #line 317 "src/std/ArenaAllocator.pv"
            current_block = block;
        }

        #line 320 "src/std/ArenaAllocator.pv"
        block = block->prev;
    }

    #line 323 "src/std/ArenaAllocator.pv"
    if (current_block == 0) {
        #line 324 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No block found to reallocate from\n");
        #line 325 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 328 "src/std/ArenaAllocator.pv"
    uintptr_t old_size = ArenaBlock__size(current_block, ptr);

    #line 330 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
    #line 331 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 331 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 333 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, new_size < old_size ? new_size : old_size);
    #line 334 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(current_block, ptr);

    #line 336 "src/std/ArenaAllocator.pv"
    return new_ptr;
}

#line 339 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 340 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 340 "src/std/ArenaAllocator.pv"
        return false;
    }
    #line 341 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = self->state;
    #line 342 "src/std/ArenaAllocator.pv"
    if (state == 0) {
        #line 342 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 344 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = state->last_oversize;
    #line 345 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* next = 0;
    #line 346 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 347 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 349 "src/std/ArenaAllocator.pv"
        if (ptr == oversize->data) {
            #line 350 "src/std/ArenaAllocator.pv"
            if (state->last_oversize == oversize) {
                #line 350 "src/std/ArenaAllocator.pv"
                state->last_oversize = prev;
            }
            #line 351 "src/std/ArenaAllocator.pv"
            if (next != 0) {
                #line 351 "src/std/ArenaAllocator.pv"
                next->prev = prev;
            }

            #line 353 "src/std/ArenaAllocator.pv"
            bool result = state->allocator.vtable->fn_free(state->allocator.instance, oversize->data);
            #line 354 "src/std/ArenaAllocator.pv"
            state->allocator.vtable->fn_free(state->allocator.instance, oversize);
            #line 355 "src/std/ArenaAllocator.pv"
            return result;
        }

        #line 358 "src/std/ArenaAllocator.pv"
        next = oversize;
        #line 359 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 362 "src/std/ArenaAllocator.pv"
    if (ArenaAllocator__guarded_backend()) {
        #line 362 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 364 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = state->last_block;
    #line 365 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 366 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 368 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 369 "src/std/ArenaAllocator.pv"
            return ArenaBlock__free(block, ptr);
        }

        #line 372 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 375 "src/std/ArenaAllocator.pv"
    return false;
}

struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR = { .fn_alloc = &ArenaAllocator__Allocator__alloc, .fn_realloc = &ArenaAllocator__Allocator__realloc, .fn_free = &ArenaAllocator__Allocator__free };
