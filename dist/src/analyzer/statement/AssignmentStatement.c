#include <stdint.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/expression/Expression.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Context.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <std/String.h>
#include <std/str.h>
#include <analyzer/statement/AssignmentStatement.h>

#include <analyzer/statement/AssignmentStatement.h>

#line 13 "src/analyzer/statement/AssignmentStatement.pv"
struct Type* AssignmentStatement__make_pointer_type_for_reference_assignment(struct Context* context, struct Type* left_type, struct Expression* right) {
    #line 14 "src/analyzer/statement/AssignmentStatement.pv"
    switch (left_type->type) {
        #line 15 "src/analyzer/statement/AssignmentStatement.pv"
        case TYPE__INDIRECT: {
            #line 15 "src/analyzer/statement/AssignmentStatement.pv"
            struct Indirect* left_indirect = left_type->indirect_value;
            #line 16 "src/analyzer/statement/AssignmentStatement.pv"
            if (left_indirect->type != INDIRECT_TYPE__REFERENCE) {
                #line 16 "src/analyzer/statement/AssignmentStatement.pv"
                return 0;
            }

            #line 18 "src/analyzer/statement/AssignmentStatement.pv"
            switch (right->data.type) {
                #line 19 "src/analyzer/statement/AssignmentStatement.pv"
                case EXPRESSION_DATA__NULL_LITERAL: {
                    #line 20 "src/analyzer/statement/AssignmentStatement.pv"
                    struct Indirect* pointer = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, left_indirect->to);
                    #line 21 "src/analyzer/statement/AssignmentStatement.pv"
                    struct Type pointer_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = pointer };
                    #line 22 "src/analyzer/statement/AssignmentStatement.pv"
                    return ArenaAllocator__store_Type(context->allocator, &pointer_type);
                } break;
                #line 24 "src/analyzer/statement/AssignmentStatement.pv"
                default: {
                } break;
            }

            #line 27 "src/analyzer/statement/AssignmentStatement.pv"
            switch (right->return_type.type) {
                #line 28 "src/analyzer/statement/AssignmentStatement.pv"
                case TYPE__INDIRECT: {
                    #line 28 "src/analyzer/statement/AssignmentStatement.pv"
                    struct Indirect* right_indirect = right->return_type.indirect_value;
                    #line 29 "src/analyzer/statement/AssignmentStatement.pv"
                    if (right_indirect->type != INDIRECT_TYPE__POINTER && right_indirect->type != INDIRECT_TYPE__CONST_POINTER) {
                        #line 30 "src/analyzer/statement/AssignmentStatement.pv"
                        return 0;
                    }
                    #line 32 "src/analyzer/statement/AssignmentStatement.pv"
                    if (!Type__eq(&left_indirect->to, &right_indirect->to)) {
                        #line 32 "src/analyzer/statement/AssignmentStatement.pv"
                        return 0;
                    }
                    #line 33 "src/analyzer/statement/AssignmentStatement.pv"
                    return &right->return_type;
                } break;
                #line 35 "src/analyzer/statement/AssignmentStatement.pv"
                default: {
                } break;
            }
        } break;
        #line 38 "src/analyzer/statement/AssignmentStatement.pv"
        default: {
        } break;
    }

    #line 41 "src/analyzer/statement/AssignmentStatement.pv"
    return 0;
}

#line 44 "src/analyzer/statement/AssignmentStatement.pv"
bool AssignmentStatement__validate_and_update_scope(struct Context* context, struct Expression* left, struct Expression* right) {
    #line 45 "src/analyzer/statement/AssignmentStatement.pv"
    struct Type* pointer_type = AssignmentStatement__make_pointer_type_for_reference_assignment(context, &left->return_type, right);
    #line 46 "src/analyzer/statement/AssignmentStatement.pv"
    if (pointer_type != 0) {
        #line 47 "src/analyzer/statement/AssignmentStatement.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 48 "src/analyzer/statement/AssignmentStatement.pv"
        if (Expression__build_narrow_path(left, &path)) {
            #line 49 "src/analyzer/statement/AssignmentStatement.pv"
            Context__update_value_type(context, String__as_str(&path), pointer_type);
        }
        #line 51 "src/analyzer/statement/AssignmentStatement.pv"
        right->return_type = *pointer_type;
        #line 52 "src/analyzer/statement/AssignmentStatement.pv"
        return true;
    }

    #line 55 "src/analyzer/statement/AssignmentStatement.pv"
    return Expression__validate_type(right, context, &left->return_type, true);
}
