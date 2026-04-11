#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/trait_Allocator.h>
#include <stdint.h>
#include <std/ArenaBlock.h>
#include <stdbool.h>
#include <analyzer/types/Function.h>
#include <std/ArenaOversize.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/Block.h>
#include <analyzer/Token.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Generic.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/IncludeContext.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/TypedefC.h>

#include <std/ArenaAllocator.h>

#line 136 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct trait_Allocator allocator, uintptr_t block_size) {
    #line 137 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(allocator, block_size, 0);
    #line 138 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 138 "src/std/ArenaAllocator.pv"
        return (struct ArenaAllocator) {};
    }

    #line 140 "src/std/ArenaAllocator.pv"
    return (struct ArenaAllocator) {
        .allocator = allocator,
        .block_size = block_size,
        .last_block = block,
    };
}

#line 147 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self) {
    #line 148 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;

    #line 150 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 151 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, self)) {
            #line 152 "src/std/ArenaAllocator.pv"
            ArenaBlock__destroy(block, self->allocator);
            #line 153 "src/std/ArenaAllocator.pv"
            return;
        }

        #line 156 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;
        #line 157 "src/std/ArenaAllocator.pv"
        ArenaBlock__destroy(block, self->allocator);
        #line 158 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 161 "src/std/ArenaAllocator.pv"
    self->block_size = 0;
    #line 162 "src/std/ArenaAllocator.pv"
    self->last_block = 0;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Function* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Function));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Function));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Type* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Type));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Type));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct GenericMap* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericMap));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct GenericMap));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Indirect* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Indirect));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Indirect));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Block* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Block));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Block));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Token* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Token));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Token));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct ForStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ForStatement));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct ForStatement));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Sequence* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Sequence));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Sequence));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Tuple* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Tuple));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Tuple));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Generic* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Generic));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Generic));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Expression* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Expression));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Expression));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct LetStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct LetStatement));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct LetStatement));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct ClassCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ClassCpp));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct ClassCpp));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct EnumC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct EnumC));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct EnumC));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct FunctionC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct FunctionC));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct FunctionC));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct Include* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Include));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Include));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct IncludeContext* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IncludeContext));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct IncludeContext));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct NamespaceCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct NamespaceCpp));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct NamespaceCpp));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct StructC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct StructC));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct StructC));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 165 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC value) {
    #line 166 "src/std/ArenaAllocator.pv"
    struct TypedefC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct TypedefC));
    #line 167 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 167 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 169 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct TypedefC));
    #line 170 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 175 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 176 "src/std/ArenaAllocator.pv"
    if (size > self->block_size / 4) {
        #line 177 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = sizeof(struct ArenaOversize) + size;
        #line 178 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = self->allocator.vtable->alloc(self->allocator.instance, total_size);
        #line 179 "src/std/ArenaAllocator.pv"
        oversize->size = size;
        #line 180 "src/std/ArenaAllocator.pv"
        oversize->prev = self->last_oversize;
        #line 181 "src/std/ArenaAllocator.pv"
        self->last_oversize = oversize;
        #line 182 "src/std/ArenaAllocator.pv"
        return oversize + 1;
    }

    #line 185 "src/std/ArenaAllocator.pv"
    void* ptr = ArenaBlock__alloc(self->last_block, size);
    #line 186 "src/std/ArenaAllocator.pv"
    if (ptr != 0) {
        #line 186 "src/std/ArenaAllocator.pv"
        return ptr;
    }

    #line 188 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(self->allocator, self->block_size, self->last_block);
    #line 189 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 189 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 191 "src/std/ArenaAllocator.pv"
    self->last_block = block;
    #line 192 "src/std/ArenaAllocator.pv"
    return ArenaBlock__alloc(self->last_block, size);
}

#line 195 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 196 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 196 "src/std/ArenaAllocator.pv"
        return ArenaAllocator__Allocator__alloc(self, new_size);
    }

    #line 198 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 199 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 200 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 202 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 203 "src/std/ArenaAllocator.pv"
            uintptr_t old_size = oversize->size;

            #line 205 "src/std/ArenaAllocator.pv"
            void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
            #line 206 "src/std/ArenaAllocator.pv"
            if (new_ptr == 0) {
                #line 206 "src/std/ArenaAllocator.pv"
                return 0;
            }

            #line 208 "src/std/ArenaAllocator.pv"
            if (new_size < old_size) {
                #line 209 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, new_size);
            } else {
                #line 211 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, old_size);
            }

            #line 214 "src/std/ArenaAllocator.pv"
            ArenaAllocator__Allocator__free(self, ptr);

            #line 216 "src/std/ArenaAllocator.pv"
            return new_ptr;
        }

        #line 219 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 222 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* current_block = 0;
    #line 223 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 224 "src/std/ArenaAllocator.pv"
    while (current_block == 0 && block != 0) {
        #line 225 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 226 "src/std/ArenaAllocator.pv"
            void* realloc_ptr = ArenaBlock__realloc(block, ptr, new_size);
            #line 227 "src/std/ArenaAllocator.pv"
            if (realloc_ptr != 0) {
                #line 227 "src/std/ArenaAllocator.pv"
                return realloc_ptr;
            }
            #line 228 "src/std/ArenaAllocator.pv"
            current_block = block;
        }

        #line 231 "src/std/ArenaAllocator.pv"
        block = block->prev;
    }

    #line 234 "src/std/ArenaAllocator.pv"
    if (current_block == 0) {
        #line 235 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No block found to reallocate from\n");
        #line 236 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 239 "src/std/ArenaAllocator.pv"
    uintptr_t old_size = ArenaBlock__size(current_block, ptr);

    #line 241 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
    #line 242 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 242 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 244 "src/std/ArenaAllocator.pv"
    memcpy(new_ptr, ptr, new_size < old_size ? new_size : old_size);
    #line 245 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(current_block, ptr);

    #line 247 "src/std/ArenaAllocator.pv"
    return new_ptr;
}

#line 250 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 251 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 251 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 253 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 254 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* next = 0;
    #line 255 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 256 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 258 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 259 "src/std/ArenaAllocator.pv"
            if (self->last_oversize == oversize) {
                #line 259 "src/std/ArenaAllocator.pv"
                self->last_oversize = prev;
            }
            #line 260 "src/std/ArenaAllocator.pv"
            if (next != 0) {
                #line 260 "src/std/ArenaAllocator.pv"
                next->prev = prev;
            }

            #line 262 "src/std/ArenaAllocator.pv"
            return self->allocator.vtable->free(self->allocator.instance, oversize);
        }

        #line 265 "src/std/ArenaAllocator.pv"
        next = oversize;
        #line 266 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 269 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 270 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 271 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 273 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 274 "src/std/ArenaAllocator.pv"
            return ArenaBlock__free(block, ptr);
        }

        #line 277 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 280 "src/std/ArenaAllocator.pv"
    return false;
}

struct trait_AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR = { .alloc = &ArenaAllocator__Allocator__alloc, .realloc = &ArenaAllocator__Allocator__realloc, .free = &ArenaAllocator__Allocator__free };
