#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/Allocator.h>
#include <stdint.h>
#include <std/ArenaBlock.h>
#include <stdbool.h>
#include <analyzer/Function.h>
#include <std/ArenaOversize.h>
#include <analyzer/Type.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Indirect.h>
#include <analyzer/Block.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/Token.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/Sequence.h>
#include <analyzer/Tuple.h>
#include <analyzer/Include.h>
#include <analyzer/IncludeContext.h>
#include <analyzer/TypedefC.h>
#include <analyzer/EnumC.h>
#include <analyzer/StructC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/FunctionC.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/Generic.h>
#include <analyzer/expression/Expression.h>

#include <std/ArenaAllocator.h>

#line 137 "src/std/ArenaAllocator.pv"
struct ArenaAllocator ArenaAllocator__new(struct Allocator allocator, uintptr_t block_size) {
    #line 138 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(allocator, block_size, 0);
    #line 139 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 139 "src/std/ArenaAllocator.pv"
        return (struct ArenaAllocator) {};
    }

    #line 141 "src/std/ArenaAllocator.pv"
    return (struct ArenaAllocator) {
        .allocator = allocator,
        .block_size = block_size,
        .last_block = block,
    };
}

#line 156 "src/std/ArenaAllocator.pv"
void ArenaAllocator__destroy(struct ArenaAllocator* self) {
    #line 157 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;

    #line 159 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 160 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, self)) {
            #line 161 "src/std/ArenaAllocator.pv"
            ArenaBlock__destroy(block, self->allocator);
            #line 162 "src/std/ArenaAllocator.pv"
            return;
        }

        #line 165 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;
        #line 166 "src/std/ArenaAllocator.pv"
        ArenaBlock__destroy(block, self->allocator);
        #line 167 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 170 "src/std/ArenaAllocator.pv"
    self->block_size = 0;
    #line 171 "src/std/ArenaAllocator.pv"
    self->last_block = 0;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Function* ArenaAllocator__store_Function(struct ArenaAllocator* self, struct Function value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Function* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Function));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Function));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Type* ArenaAllocator__store_Type(struct ArenaAllocator* self, struct Type value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Type* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Type));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Type));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct GenericMap* ArenaAllocator__store_GenericMap(struct ArenaAllocator* self, struct GenericMap value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct GenericMap* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct GenericMap));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct GenericMap));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Indirect* ArenaAllocator__store_Indirect(struct ArenaAllocator* self, struct Indirect value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Indirect* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Indirect));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Indirect));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Block* ArenaAllocator__store_Block(struct ArenaAllocator* self, struct Block value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Block* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Block));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Block));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct LetStatement* ArenaAllocator__store_LetStatement(struct ArenaAllocator* self, struct LetStatement value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct LetStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct LetStatement));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct LetStatement));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Token* ArenaAllocator__store_Token(struct ArenaAllocator* self, struct Token value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Token* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Token));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Token));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct ForStatement* ArenaAllocator__store_ForStatement(struct ArenaAllocator* self, struct ForStatement value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct ForStatement* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ForStatement));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct ForStatement));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Sequence* ArenaAllocator__store_Sequence(struct ArenaAllocator* self, struct Sequence value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Sequence* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Sequence));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Sequence));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Tuple* ArenaAllocator__store_Tuple(struct ArenaAllocator* self, struct Tuple value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Tuple* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Tuple));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Tuple));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Include* ArenaAllocator__store_Include(struct ArenaAllocator* self, struct Include value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Include* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Include));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Include));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct IncludeContext* ArenaAllocator__store_IncludeContext(struct ArenaAllocator* self, struct IncludeContext value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct IncludeContext* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct IncludeContext));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct IncludeContext));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct TypedefC* ArenaAllocator__store_TypedefC(struct ArenaAllocator* self, struct TypedefC value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct TypedefC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct TypedefC));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct TypedefC));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct EnumC* ArenaAllocator__store_EnumC(struct ArenaAllocator* self, struct EnumC value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct EnumC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct EnumC));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct EnumC));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct StructC* ArenaAllocator__store_StructC(struct ArenaAllocator* self, struct StructC value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct StructC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct StructC));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct StructC));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct ClassCpp* ArenaAllocator__store_ClassCpp(struct ArenaAllocator* self, struct ClassCpp value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct ClassCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct ClassCpp));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct ClassCpp));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct FunctionC* ArenaAllocator__store_FunctionC(struct ArenaAllocator* self, struct FunctionC value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct FunctionC* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct FunctionC));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct FunctionC));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct NamespaceCpp* ArenaAllocator__store_NamespaceCpp(struct ArenaAllocator* self, struct NamespaceCpp value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct NamespaceCpp* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct NamespaceCpp));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct NamespaceCpp));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Generic* ArenaAllocator__store_Generic(struct ArenaAllocator* self, struct Generic value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Generic* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Generic));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Generic));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 174 "src/std/ArenaAllocator.pv"
struct Expression* ArenaAllocator__store_Expression(struct ArenaAllocator* self, struct Expression value) {
    #line 175 "src/std/ArenaAllocator.pv"
    struct Expression* new_memory = ArenaAllocator__Allocator__alloc(self, sizeof(struct Expression));
    #line 176 "src/std/ArenaAllocator.pv"
    if (new_memory == 0) {
        #line 176 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 178 "src/std/ArenaAllocator.pv"
    memcpy(new_memory, &value, sizeof(struct Expression));
    #line 179 "src/std/ArenaAllocator.pv"
    return new_memory;
}

#line 184 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 185 "src/std/ArenaAllocator.pv"
    if (size > self->block_size / 4) {
        #line 186 "src/std/ArenaAllocator.pv"
        uintptr_t total_size = sizeof(struct ArenaOversize) + size;
        #line 187 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = self->allocator.vtable->alloc(self->allocator.instance, total_size);
        #line 188 "src/std/ArenaAllocator.pv"
        oversize->size = size;
        #line 189 "src/std/ArenaAllocator.pv"
        oversize->prev = self->last_oversize;
        #line 190 "src/std/ArenaAllocator.pv"
        self->last_oversize = oversize;
        #line 191 "src/std/ArenaAllocator.pv"
        return oversize + 1;
    }

    #line 194 "src/std/ArenaAllocator.pv"
    void* ptr = ArenaBlock__alloc(self->last_block, size);
    #line 195 "src/std/ArenaAllocator.pv"
    if (ptr != 0) {
        #line 195 "src/std/ArenaAllocator.pv"
        return ptr;
    }

    #line 197 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = ArenaBlock__new(self->allocator, self->block_size, self->last_block);
    #line 198 "src/std/ArenaAllocator.pv"
    if (block == 0) {
        #line 198 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 200 "src/std/ArenaAllocator.pv"
    self->last_block = block;
    #line 201 "src/std/ArenaAllocator.pv"
    return ArenaBlock__alloc(self->last_block, size);
}

#line 204 "src/std/ArenaAllocator.pv"
void* ArenaAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 205 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 205 "src/std/ArenaAllocator.pv"
        return ArenaAllocator__Allocator__alloc(self, new_size);
    }

    #line 207 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 208 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 209 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 211 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 213 "src/std/ArenaAllocator.pv"
            uintptr_t old_size = oversize->size;

            #line 215 "src/std/ArenaAllocator.pv"
            void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
            #line 216 "src/std/ArenaAllocator.pv"
            if (new_ptr == 0) {
                #line 216 "src/std/ArenaAllocator.pv"
                return 0;
            }

            #line 218 "src/std/ArenaAllocator.pv"
            if (new_size < old_size) {
                #line 219 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, new_size);
            } else {
                #line 221 "src/std/ArenaAllocator.pv"
                memcpy(new_ptr, ptr, old_size);
            }

            #line 224 "src/std/ArenaAllocator.pv"
            ArenaAllocator__Allocator__free(self, ptr);

            #line 226 "src/std/ArenaAllocator.pv"
            return new_ptr;
        }

        #line 229 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 232 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* current_block = 0;
    #line 233 "src/std/ArenaAllocator.pv"
    if (ArenaBlock__is_in_block(self->last_block, ptr)) {
        #line 235 "src/std/ArenaAllocator.pv"
        void* realloc_ptr = ArenaBlock__realloc(self->last_block, ptr, new_size);
        #line 236 "src/std/ArenaAllocator.pv"
        if (realloc_ptr != 0) {
            #line 236 "src/std/ArenaAllocator.pv"
            return realloc_ptr;
        }
        #line 237 "src/std/ArenaAllocator.pv"
        current_block = self->last_block;
    }

    #line 240 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 241 "src/std/ArenaAllocator.pv"
    while (current_block == 0 && block != 0) {
        #line 242 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 244 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 245 "src/std/ArenaAllocator.pv"
            current_block = block;
        }

        #line 248 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 251 "src/std/ArenaAllocator.pv"
    if (current_block == 0) {
        #line 252 "src/std/ArenaAllocator.pv"
        fprintf(stderr, "ArenaAllocator.realloc: No block found to reallocate from\n");
        #line 253 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 256 "src/std/ArenaAllocator.pv"
    uintptr_t old_size = ArenaBlock__size(current_block, ptr);

    #line 260 "src/std/ArenaAllocator.pv"
    void* new_ptr = ArenaAllocator__Allocator__alloc(self, new_size);
    #line 261 "src/std/ArenaAllocator.pv"
    if (new_ptr == 0) {
        #line 261 "src/std/ArenaAllocator.pv"
        return 0;
    }

    #line 263 "src/std/ArenaAllocator.pv"
    if (new_size < old_size) {
        #line 264 "src/std/ArenaAllocator.pv"
        memcpy(new_ptr, ptr, new_size);
    } else {
        #line 266 "src/std/ArenaAllocator.pv"
        memcpy(new_ptr, ptr, old_size);
    }

    #line 269 "src/std/ArenaAllocator.pv"
    ArenaBlock__free(current_block, ptr);

    #line 271 "src/std/ArenaAllocator.pv"
    return new_ptr;
}

#line 274 "src/std/ArenaAllocator.pv"
bool ArenaAllocator__Allocator__free(void* __self, void* ptr) {
    struct ArenaAllocator* self = __self; (void)self;
    #line 275 "src/std/ArenaAllocator.pv"
    if (ptr == 0) {
        #line 275 "src/std/ArenaAllocator.pv"
        return false;
    }

    #line 277 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = self->last_oversize;
    #line 278 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* next = 0;
    #line 279 "src/std/ArenaAllocator.pv"
    while (oversize != 0) {
        #line 280 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* prev = oversize->prev;

        #line 282 "src/std/ArenaAllocator.pv"
        if (ptr == oversize + 1) {
            #line 283 "src/std/ArenaAllocator.pv"
            if (self->last_oversize == oversize) {
                #line 283 "src/std/ArenaAllocator.pv"
                self->last_oversize = prev;
            }
            #line 284 "src/std/ArenaAllocator.pv"
            if (next != 0) {
                #line 284 "src/std/ArenaAllocator.pv"
                next->prev = prev;
            }

            #line 286 "src/std/ArenaAllocator.pv"
            return self->allocator.vtable->free(self->allocator.instance, oversize);
        }

        #line 289 "src/std/ArenaAllocator.pv"
        next = oversize;
        #line 290 "src/std/ArenaAllocator.pv"
        oversize = prev;
    }

    #line 293 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = self->last_block;
    #line 294 "src/std/ArenaAllocator.pv"
    while (block != 0) {
        #line 295 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* prev = block->prev;

        #line 297 "src/std/ArenaAllocator.pv"
        if (ArenaBlock__is_in_block(block, ptr)) {
            #line 298 "src/std/ArenaAllocator.pv"
            return ArenaBlock__free(block, ptr);
        }

        #line 301 "src/std/ArenaAllocator.pv"
        block = prev;
    }

    #line 304 "src/std/ArenaAllocator.pv"
    return false;
}

struct AllocatorVTable ARENA_ALLOCATOR__VTABLE__ALLOCATOR = { .alloc = &ArenaAllocator__Allocator__alloc, .realloc = &ArenaAllocator__Allocator__realloc, .free = &ArenaAllocator__Allocator__free };
