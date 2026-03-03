#ifndef PAVE_FOR_STATEMENT_TYPE
#define PAVE_FOR_STATEMENT_TYPE

struct Expression;

#line 26 "src/analyzer/Statement.pv"
struct ForStatementType {
    enum {
        FOR_STATEMENT_TYPE__RANGE,
        FOR_STATEMENT_TYPE__ITER,
    } type;

    union {
        struct { struct Expression* _0; struct Expression* _1; } range_value;
        struct Expression* iter_value;
    };
};

#endif
