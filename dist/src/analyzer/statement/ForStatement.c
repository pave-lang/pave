#include <std/ArenaAllocator.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <std/trait_Allocator.h>
#include <stdbool.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <std/Iter_ref_ForVariable.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Type.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <std/Array_Type.h>
#include <std/str.h>
#include <analyzer/types/Enum.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Indirect.h>

#include <analyzer/statement/ForStatement.h>

#line 16 "src/analyzer/statement/ForStatement.pv"
struct ForStatement ForStatement__new(struct ArenaAllocator* allocator) {
    #line 17 "src/analyzer/statement/ForStatement.pv"
    return (struct ForStatement) { .variables = Array_ForVariable__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}

#line 20 "src/analyzer/statement/ForStatement.pv"
bool ForStatement__parse_for_variable(struct Context* context, struct Array_ForVariable* variables) {
    #line 21 "src/analyzer/statement/ForStatement.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 22 "src/analyzer/statement/ForStatement.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 23 "src/analyzer/statement/ForStatement.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 25 "src/analyzer/statement/ForStatement.pv"
    if (name == 0) {
        #line 25 "src/analyzer/statement/ForStatement.pv"
        return false;
    }

    #line 27 "src/analyzer/statement/ForStatement.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 29 "src/analyzer/statement/ForStatement.pv"
    return true;
}

#line 32 "src/analyzer/statement/ForStatement.pv"
struct ForStatement* ForStatement__parse(struct Block* parent_block, struct Context* context, struct Generics* generics) {
    #line 33 "src/analyzer/statement/ForStatement.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 35 "src/analyzer/statement/ForStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 35 "src/analyzer/statement/ForStatement.pv"
        return 0;
    }

    #line 37 "src/analyzer/statement/ForStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 38 "src/analyzer/statement/ForStatement.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 39 "src/analyzer/statement/ForStatement.pv"
            if (!ForStatement__parse_for_variable(context, &for_statement.variables)) {
                #line 39 "src/analyzer/statement/ForStatement.pv"
                return 0;
            }

            #line 41 "src/analyzer/statement/ForStatement.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 42 "src/analyzer/statement/ForStatement.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 43 "src/analyzer/statement/ForStatement.pv"
                return 0;
            }
        }

        #line 47 "src/analyzer/statement/ForStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 47 "src/analyzer/statement/ForStatement.pv"
            return 0;
        }
    } else {
        #line 49 "src/analyzer/statement/ForStatement.pv"
        if (!ForStatement__parse_for_variable(context, &for_statement.variables)) {
            #line 49 "src/analyzer/statement/ForStatement.pv"
            return 0;
        }
    }

    #line 52 "src/analyzer/statement/ForStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in")) {
        #line 52 "src/analyzer/statement/ForStatement.pv"
        return 0;
    }

    #line 54 "src/analyzer/statement/ForStatement.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 55 "src/analyzer/statement/ForStatement.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 56 "src/analyzer/statement/ForStatement.pv"
    if (for_statement.expression == 0) {
        #line 56 "src/analyzer/statement/ForStatement.pv"
        return 0;
    }

    #line 58 "src/analyzer/statement/ForStatement.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 60 "src/analyzer/statement/ForStatement.pv"
    bool is_range = false;

    #line 62 "src/analyzer/statement/ForStatement.pv"
    switch (for_statement.expression->data.type) {
        #line 63 "src/analyzer/statement/ForStatement.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 63 "src/analyzer/statement/ForStatement.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 63 "src/analyzer/statement/ForStatement.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 64 "src/analyzer/statement/ForStatement.pv"
            switch (target->return_type.type) {
                #line 65 "src/analyzer/statement/ForStatement.pv"
                case TYPE__ENUM: {
                    #line 65 "src/analyzer/statement/ForStatement.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 65 "src/analyzer/statement/ForStatement.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 66 "src/analyzer/statement/ForStatement.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 67 "src/analyzer/statement/ForStatement.pv"
                        is_range = true;
                        #line 68 "src/analyzer/statement/ForStatement.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 69 "src/analyzer/statement/ForStatement.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 70 "src/analyzer/statement/ForStatement.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 73 "src/analyzer/statement/ForStatement.pv"
                default: {
                } break;
            }
        } break;
        #line 76 "src/analyzer/statement/ForStatement.pv"
        default: {
        } break;
    }

    #line 79 "src/analyzer/statement/ForStatement.pv"
    if (is_range) {
        #line 80 "src/analyzer/statement/ForStatement.pv"
        struct ForVariable variable = for_statement.variables.data[0];
        #line 81 "src/analyzer/statement/ForStatement.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable.type, context->type_self, 0);
        #line 82 "src/analyzer/statement/ForStatement.pv"
        String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
        #line 83 "src/analyzer/statement/ForStatement.pv"
        Context__inlay_hint(context, variable.name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
    } else {
        #line 85 "src/analyzer/statement/ForStatement.pv"
        bool is_sequence = false;
        #line 86 "src/analyzer/statement/ForStatement.pv"
        switch (for_statement.expression->return_type.type) {
            #line 87 "src/analyzer/statement/ForStatement.pv"
            case TYPE__SEQUENCE: {
                #line 87 "src/analyzer/statement/ForStatement.pv"
                struct Sequence* sequence = for_statement.expression->return_type.sequence_value;
                #line 88 "src/analyzer/statement/ForStatement.pv"
                is_sequence = true;
                #line 89 "src/analyzer/statement/ForStatement.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__SEQUENCE, .sequence_value = for_statement.expression };
                #line 90 "src/analyzer/statement/ForStatement.pv"
                for_statement.iter_type = &for_statement.expression->return_type;
                #line 91 "src/analyzer/statement/ForStatement.pv"
                for_statement.value_type = &sequence->element;
            } break;
            #line 93 "src/analyzer/statement/ForStatement.pv"
            case TYPE__INDIRECT: {
                #line 93 "src/analyzer/statement/ForStatement.pv"
                struct Indirect* indirect = for_statement.expression->return_type.indirect_value;
                #line 94 "src/analyzer/statement/ForStatement.pv"
                switch (indirect->to.type) {
                    #line 95 "src/analyzer/statement/ForStatement.pv"
                    case TYPE__SEQUENCE: {
                        #line 95 "src/analyzer/statement/ForStatement.pv"
                        struct Sequence* sequence = indirect->to.sequence_value;
                        #line 96 "src/analyzer/statement/ForStatement.pv"
                        is_sequence = true;
                        #line 97 "src/analyzer/statement/ForStatement.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__SEQUENCE, .sequence_value = for_statement.expression };
                        #line 98 "src/analyzer/statement/ForStatement.pv"
                        for_statement.iter_type = &for_statement.expression->return_type;
                        #line 99 "src/analyzer/statement/ForStatement.pv"
                        for_statement.value_type = &sequence->element;
                    } break;
                    #line 101 "src/analyzer/statement/ForStatement.pv"
                    default: {
                    } break;
                }
            } break;
            #line 104 "src/analyzer/statement/ForStatement.pv"
            default: {
            } break;
        }

        #line 107 "src/analyzer/statement/ForStatement.pv"
        if (!is_sequence) {
            #line 108 "src/analyzer/statement/ForStatement.pv"
            struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
            #line 109 "src/analyzer/statement/ForStatement.pv"
            iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

            #line 111 "src/analyzer/statement/ForStatement.pv"
            struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
            #line 112 "src/analyzer/statement/ForStatement.pv"
            bool iter_member_is_function = false;

            #line 114 "src/analyzer/statement/ForStatement.pv"
            if (iter_member_type != 0) {
                #line 115 "src/analyzer/statement/ForStatement.pv"
                switch (iter_member_type->type) {
                    #line 116 "src/analyzer/statement/ForStatement.pv"
                    case TYPE__FUNCTION: {
                        #line 116 "src/analyzer/statement/ForStatement.pv"
                        iter_member_is_function = true;
                    } break;
                    #line 117 "src/analyzer/statement/ForStatement.pv"
                    default: {
                    } break;
                }
            }

            #line 121 "src/analyzer/statement/ForStatement.pv"
            if (!iter_member_is_function) {
                #line 122 "src/analyzer/statement/ForStatement.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
                #line 123 "src/analyzer/statement/ForStatement.pv"
                for_statement.iter_type = &for_statement.expression->return_type;
            } else {
                #line 125 "src/analyzer/statement/ForStatement.pv"
                struct Array_InvokeArgument args = Array_InvokeArgument__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 126 "src/analyzer/statement/ForStatement.pv"
                Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

                #line 128 "src/analyzer/statement/ForStatement.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
                #line 129 "src/analyzer/statement/ForStatement.pv"
                for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
            }

            #line 132 "src/analyzer/statement/ForStatement.pv"
            struct Token value_member = *iter_member;
            #line 133 "src/analyzer/statement/ForStatement.pv"
            value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

            #line 135 "src/analyzer/statement/ForStatement.pv"
            struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
            #line 136 "src/analyzer/statement/ForStatement.pv"
            if (value_member_type == 0) {
                #line 136 "src/analyzer/statement/ForStatement.pv"
                return 0;
            }
            #line 137 "src/analyzer/statement/ForStatement.pv"
            for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);
        }

        #line 140 "src/analyzer/statement/ForStatement.pv"
        uintptr_t variable_i = 0;
        #line 141 "src/analyzer/statement/ForStatement.pv"
        { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 141 "src/analyzer/statement/ForStatement.pv"
        while (Iter_ref_ForVariable__next(&__iter)) {
            #line 141 "src/analyzer/statement/ForStatement.pv"
            struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

            #line 142 "src/analyzer/statement/ForStatement.pv"
            if (for_statement.variables.length == 1) {
                #line 143 "src/analyzer/statement/ForStatement.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 145 "src/analyzer/statement/ForStatement.pv"
                struct Token value_member = *variable->name;
                #line 146 "src/analyzer/statement/ForStatement.pv"
                struct String value_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 147 "src/analyzer/statement/ForStatement.pv"
                String__append_usize(&value_name, variable_i);
                #line 148 "src/analyzer/statement/ForStatement.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 149 "src/analyzer/statement/ForStatement.pv"
                value_member.value = String__as_str(&value_name);

                #line 151 "src/analyzer/statement/ForStatement.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 154 "src/analyzer/statement/ForStatement.pv"
            if (variable->deref) {
                #line 155 "src/analyzer/statement/ForStatement.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 158 "src/analyzer/statement/ForStatement.pv"
            if (variable->ref) {
                #line 159 "src/analyzer/statement/ForStatement.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 162 "src/analyzer/statement/ForStatement.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 163 "src/analyzer/statement/ForStatement.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 164 "src/analyzer/statement/ForStatement.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 166 "src/analyzer/statement/ForStatement.pv"
            variable_i += 1;
        } }
    }

    #line 170 "src/analyzer/statement/ForStatement.pv"
    Context__push_scope(context, parent_block);

    #line 172 "src/analyzer/statement/ForStatement.pv"
    { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 172 "src/analyzer/statement/ForStatement.pv"
    while (Iter_ref_ForVariable__next(&__iter)) {
        #line 172 "src/analyzer/statement/ForStatement.pv"
        struct ForVariable* variable2 = Iter_ref_ForVariable__value(&__iter);

        #line 173 "src/analyzer/statement/ForStatement.pv"
        if (!Context__set_value(context, variable2->name, variable2->type)) {
            #line 173 "src/analyzer/statement/ForStatement.pv"
            Context__error(context, "set_value");
            #line 173 "src/analyzer/statement/ForStatement.pv"
            return 0;
        }
    } }

    #line 176 "src/analyzer/statement/ForStatement.pv"
    for_statement.block = Block__new_ptr(context);
    #line 177 "src/analyzer/statement/ForStatement.pv"
    for_statement.block->is_loop = true;
    #line 178 "src/analyzer/statement/ForStatement.pv"
    if (!Block__parse(for_statement.block, context, generics, false)) {
        #line 178 "src/analyzer/statement/ForStatement.pv"
        return 0;
    }

    #line 180 "src/analyzer/statement/ForStatement.pv"
    Context__pop_scope(context);

    #line 182 "src/analyzer/statement/ForStatement.pv"
    return ArenaAllocator__store_ForStatement(context->allocator, for_statement);
}
