#include <analyzer/Root.h>
#include <analyzer/Context.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/FunctionParent.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <std/String.h>
#include <analyzer/types/GenericMap.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Naming.h>

#include <analyzer/Impl.h>

#line 24 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 25 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .token = Context__current(context),
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };

    #line 33 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl")) {
        #line 33 "src/analyzer/Impl.pv"
        return node;
    }

    #line 35 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 36 "src/analyzer/Impl.pv"
    Impl__skip_to_open_brace(&node);
    #line 37 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 38 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 40 "src/analyzer/Impl.pv"
    return node;
}

#line 43 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self) {
    #line 44 "src/analyzer/Impl.pv"
    struct Context* context = self->context;

    #line 46 "src/analyzer/Impl.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 47 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 48 "src/analyzer/Impl.pv"
            self->has_trait = true;
        }

        #line 51 "src/analyzer/Impl.pv"
        Context__next_token(context);
    }

    #line 54 "src/analyzer/Impl.pv"
    return Context__check_value(context, TOKEN_TYPE__SYMBOL, "{");
}

#line 57 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 58 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 59 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 61 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 61 "src/analyzer/Impl.pv"
        return false;
    }

    #line 63 "src/analyzer/Impl.pv"
    if (self->has_trait) {
        #line 64 "src/analyzer/Impl.pv"
        if (!Context__parse_type_trait(context, &self->trait_type, &self->generics)) {
            #line 64 "src/analyzer/Impl.pv"
            return false;
        }

        #line 66 "src/analyzer/Impl.pv"
        switch (self->trait_type.type) {
            #line 67 "src/analyzer/Impl.pv"
            case TYPE__TRAIT: {
                #line 67 "src/analyzer/Impl.pv"
                struct Trait* trait_info = self->trait_type.trait_value._0;
                #line 68 "src/analyzer/Impl.pv"
                self->trait_ = trait_info;
                #line 69 "src/analyzer/Impl.pv"
                self->trait_name = trait_info->name;
            } break;
            #line 71 "src/analyzer/Impl.pv"
            default: {
                #line 72 "src/analyzer/Impl.pv"
                Context__error(context, "Expected trait type in impl declaration");
                #line 73 "src/analyzer/Impl.pv"
                return false;
            } break;
        }

        #line 77 "src/analyzer/Impl.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 77 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 80 "src/analyzer/Impl.pv"
    if (!Context__parse_type(context, &self->type, &self->generics)) {
        #line 80 "src/analyzer/Impl.pv"
        return false;
    }

    #line 82 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 84 "src/analyzer/Impl.pv"
    return true;
}

#line 87 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 88 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 89 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 90 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;

    #line 92 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 92 "src/analyzer/Impl.pv"
        return false;
    }

    #line 94 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 96 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end - 1) {
        #line 97 "src/analyzer/Impl.pv"
        struct Function func_info = Function__parse(context);
        #line 98 "src/analyzer/Impl.pv"
        func_info.parent = parent;
        #line 99 "src/analyzer/Impl.pv"
        if (func_info.name == 0) {
            #line 99 "src/analyzer/Impl.pv"
            return false;
        }

        #line 101 "src/analyzer/Impl.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

        #line 103 "src/analyzer/Impl.pv"
        struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
        #line 104 "src/analyzer/Impl.pv"
        Array_ImplNode__append(nodes, impl_node);

        #line 106 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 109 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 109 "src/analyzer/Impl.pv"
        return false;
    }

    #line 111 "src/analyzer/Impl.pv"
    return true;
}

#line 114 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 115 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 116 "src/analyzer/Impl.pv"
    context->type_self = &self->type;

    #line 118 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 118 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 118 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 119 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 122 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 123 "src/analyzer/Impl.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->trait_->functions);
        #line 123 "src/analyzer/Impl.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 123 "src/analyzer/Impl.pv"
            struct Function* trait_func = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 124 "src/analyzer/Impl.pv"
            bool has_default = trait_func->token_start < trait_func->token_end;

            #line 126 "src/analyzer/Impl.pv"
            struct Function* impl_func = HashMap_str_Function__find(&self->functions, &trait_func->name->value);

            #line 128 "src/analyzer/Impl.pv"
            if (impl_func == 0) {
                #line 129 "src/analyzer/Impl.pv"
                if (!has_default) {
                    #line 130 "src/analyzer/Impl.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                    #line 131 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "Implementation is missing trait function '", .length = strlen("Implementation is missing trait function '") });
                    #line 132 "src/analyzer/Impl.pv"
                    String__append(&message, trait_func->name->value);
                    #line 133 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                    #line 134 "src/analyzer/Impl.pv"
                    Context__error_token(self->context, self->token, String__c_str(&message));
                }
                #line 136 "src/analyzer/Impl.pv"
                continue;
            }

            #line 139 "src/analyzer/Impl.pv"
            struct GenericMap* generic_map = Type__get_generic_map(&self->trait_type, context);

            #line 141 "src/analyzer/Impl.pv"
            if (impl_func->parameters.length != trait_func->parameters.length) {
                #line 142 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 143 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function '", .length = strlen("Implementation of trait function '") });
                #line 144 "src/analyzer/Impl.pv"
                String__append(&message, trait_func->name->value);
                #line 145 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "' has wrong number of parameters", .length = strlen("' has wrong number of parameters") });
                #line 146 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func->name, String__c_str(&message));
            } else {
                #line 148 "src/analyzer/Impl.pv"
                uintptr_t i = 0;
                #line 149 "src/analyzer/Impl.pv"
                while (i < impl_func->parameters.length) {
                    #line 150 "src/analyzer/Impl.pv"
                    struct Parameter* impl_param = Array_Parameter__get(&impl_func->parameters, i);
                    #line 151 "src/analyzer/Impl.pv"
                    struct Parameter* trait_param = Array_Parameter__get(&trait_func->parameters, i);

                    #line 153 "src/analyzer/Impl.pv"
                    struct Type* trait_param_type = &trait_param->type;
                    #line 154 "src/analyzer/Impl.pv"
                    if (!Type__is_self(Type__deref(trait_param_type))) {
                        #line 154 "src/analyzer/Impl.pv"
                        trait_param_type = Context__resolve_type(context->allocator, trait_param_type, generic_map, 0);
                    }

                    #line 156 "src/analyzer/Impl.pv"
                    if (!Type__eq(&impl_param->type, trait_param_type)) {
                        #line 157 "src/analyzer/Impl.pv"
                        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                        #line 158 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = "Parameter ", .length = strlen("Parameter ") });
                        #line 159 "src/analyzer/Impl.pv"
                        String__append(&message, impl_param->name->value);
                        #line 160 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = " has type ", .length = strlen(" has type ") });
                        #line 161 "src/analyzer/Impl.pv"
                        struct String impl_type_name = Naming__get_type_decl(&context->root->naming_decl, &impl_param->type, context->type_self, 0);
                        #line 162 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&impl_type_name));
                        #line 163 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                        #line 164 "src/analyzer/Impl.pv"
                        struct String trait_type_name = Naming__get_type_decl(&context->root->naming_decl, trait_param_type, context->type_self, 0);
                        #line 165 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&trait_type_name));
                        #line 166 "src/analyzer/Impl.pv"
                        Context__error_token(self->context, impl_param->name, String__c_str(&message));
                    }
                    #line 168 "src/analyzer/Impl.pv"
                    i += 1;
                }
            }

            #line 172 "src/analyzer/Impl.pv"
            struct Type* trait_func_return_type = &trait_func->return_type;
            #line 173 "src/analyzer/Impl.pv"
            if (!Type__is_self(Type__deref(trait_func_return_type))) {
                #line 173 "src/analyzer/Impl.pv"
                trait_func_return_type = Context__resolve_type(context->allocator, trait_func_return_type, generic_map, 0);
            }

            #line 175 "src/analyzer/Impl.pv"
            if (!Type__eq(&impl_func->return_type, trait_func_return_type)) {
                #line 176 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 177 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function ", .length = strlen("Implementation of trait function ") });
                #line 178 "src/analyzer/Impl.pv"
                String__append(&message, trait_func->name->value);
                #line 179 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = " has return type ", .length = strlen(" has return type ") });
                #line 180 "src/analyzer/Impl.pv"
                struct String impl_return_name = Naming__get_type_decl(&context->root->naming_decl, &impl_func->return_type, context->type_self, 0);
                #line 181 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&impl_return_name));
                #line 182 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                #line 183 "src/analyzer/Impl.pv"
                struct String trait_return_name = Naming__get_type_decl(&context->root->naming_decl, trait_func_return_type, context->type_self, 0);
                #line 184 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&trait_return_name));
                #line 185 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func->name, String__c_str(&message));
            }
        } }
    }

    #line 190 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 192 "src/analyzer/Impl.pv"
    return true;
}
