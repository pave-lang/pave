#include <stdint.h>

#include <analyzer/NamespacePath.h>
#include <std/Array_ref_Token.h>
#include <std/trait_Allocator.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/NamespacePath.h>

#include <analyzer/NamespacePath.h>

#line 9 "src/analyzer/NamespacePath.pv"
struct NamespacePath NamespacePath__new(struct trait_Allocator allocator) {
    #line 10 "src/analyzer/NamespacePath.pv"
    return (struct NamespacePath) { .parts = Array_ref_Token__new(allocator) };
}

#line 13 "src/analyzer/NamespacePath.pv"
bool NamespacePath__parse(struct NamespacePath* self, struct Context* context) {
    #line 14 "src/analyzer/NamespacePath.pv"
    self->root = Context__check_next(context, TOKEN_TYPE__SYMBOL, "::");

    #line 16 "src/analyzer/NamespacePath.pv"
    struct Token* part = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 17 "src/analyzer/NamespacePath.pv"
    if (part == 0) {
        #line 17 "src/analyzer/NamespacePath.pv"
        return false;
    }

    #line 19 "src/analyzer/NamespacePath.pv"
    Array_ref_Token__append(&self->parts, part);

    #line 21 "src/analyzer/NamespacePath.pv"
    while (Context__check_next(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 22 "src/analyzer/NamespacePath.pv"
        part = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 23 "src/analyzer/NamespacePath.pv"
        if (part == 0) {
            #line 23 "src/analyzer/NamespacePath.pv"
            return false;
        }
        #line 24 "src/analyzer/NamespacePath.pv"
        Array_ref_Token__append(&self->parts, part);
    }

    #line 27 "src/analyzer/NamespacePath.pv"
    return true;
}
