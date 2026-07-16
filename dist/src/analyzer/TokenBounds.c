#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

#include <analyzer/TokenBounds.h>
#include <analyzer/Token.h>
#include <usize.h>
#include <analyzer/TokenBounds.h>

#include <analyzer/TokenBounds.h>

#line 44 "src/analyzer/Token.pv"
struct TokenBounds TokenBounds__new(struct Token* first, struct Token* last) {
    #line 45 "src/analyzer/Token.pv"
    return (struct TokenBounds) { .first = first, .last = last };
}

#line 48 "src/analyzer/Token.pv"
void TokenBounds__include(struct TokenBounds* self, struct TokenBounds bounds) {
    #line 49 "src/analyzer/Token.pv"
    if (bounds.first->start_line < self->first->start_line || (usize__Eq_usize__eq(bounds.first->start_line, self->first->start_line) && bounds.first->start_column < self->first->start_column)) {
        #line 50 "src/analyzer/Token.pv"
        self->first = bounds.first;
    }

    #line 53 "src/analyzer/Token.pv"
    if (bounds.last->end_line > self->last->end_line || (usize__Eq_usize__eq(bounds.last->end_line, self->last->end_line) && bounds.last->end_column > self->last->end_column)) {
        #line 54 "src/analyzer/Token.pv"
        self->last = bounds.last;
    }
}
