#include <stdbool.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <analyzer/Block.h>
#include <std/Array_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <stdint.h>
#include <analyzer/TokenType.h>

#include <analyzer/statement/MatchCase.h>

#line 14 "src/analyzer/statement/MatchCase.pv"
bool MatchCase__parse(struct MatchCase* self, struct Context* context, struct Generics* generics) {
    #line 15 "src/analyzer/statement/MatchCase.pv"
    struct Token* first_match_token = Context__current(context);

    #line 17 "src/analyzer/statement/MatchCase.pv"
    struct Block* block = Block__new_ptr(context);
    #line 18 "src/analyzer/statement/MatchCase.pv"
    Context__push_scope(context, block);

    #line 20 "src/analyzer/statement/MatchCase.pv"
    struct Array_MatchPattern patterns = Array_MatchPattern__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 22 "src/analyzer/statement/MatchCase.pv"
    while (patterns.length == 0 || Context__check_next(context, TOKEN_TYPE__SYMBOL, "|")) {
        #line 23 "src/analyzer/statement/MatchCase.pv"
        struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 24 "src/analyzer/statement/MatchCase.pv"
        if (!MatchPattern__parse(context, generics, &pattern)) {
            #line 24 "src/analyzer/statement/MatchCase.pv"
            Context__pop_scope(context);
            #line 24 "src/analyzer/statement/MatchCase.pv"
            return false;
        }

        #line 26 "src/analyzer/statement/MatchCase.pv"
        Array_MatchPattern__append(&patterns, pattern);
    }

    #line 29 "src/analyzer/statement/MatchCase.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
        #line 29 "src/analyzer/statement/MatchCase.pv"
        Context__pop_scope(context);
        #line 29 "src/analyzer/statement/MatchCase.pv"
        return false;
    }

    #line 31 "src/analyzer/statement/MatchCase.pv"
    if (!Block__parse(block, context, generics, false)) {
        #line 31 "src/analyzer/statement/MatchCase.pv"
        Context__pop_scope(context);
        #line 31 "src/analyzer/statement/MatchCase.pv"
        return false;
    }

    #line 33 "src/analyzer/statement/MatchCase.pv"
    Context__pop_scope(context);

    #line 35 "src/analyzer/statement/MatchCase.pv"
    *self = (struct MatchCase) {
        .first_token = first_match_token,
        .patterns = patterns,
        .body = block,
    };

    #line 41 "src/analyzer/statement/MatchCase.pv"
    return true;
}
