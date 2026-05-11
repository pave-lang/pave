#include <stdint.h>
#include <string.h>

#include <analyzer/Impl.h>
#include <analyzer/Context.h>
#include <analyzer/Token.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Trait.h>
#include <analyzer/ImplConst.h>
#include <std/str.h>
#include <analyzer/ImplNode.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionParent.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <tuple_str_ref_ImplConst.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/String.h>
#include <analyzer/types/GenericMap.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/Impl.h>

#include <analyzer/Impl.h>

#line 77 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 78 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .token = Context__current(context),
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .consts = HashMap_str_ref_ImplConst__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };

    #line 87 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl")) {
        #line 87 "src/analyzer/Impl.pv"
        return node;
    }

    #line 89 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 90 "src/analyzer/Impl.pv"
    Impl__skip_to_open_brace(&node);
    #line 91 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 92 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 94 "src/analyzer/Impl.pv"
    return node;
}

#line 97 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self) {
    #line 98 "src/analyzer/Impl.pv"
    struct Context* context = self->context;

    #line 100 "src/analyzer/Impl.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 101 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 102 "src/analyzer/Impl.pv"
            self->has_trait = true;
        }

        #line 105 "src/analyzer/Impl.pv"
        Context__next_token(context);
    }

    #line 108 "src/analyzer/Impl.pv"
    return Context__check_value(context, TOKEN_TYPE__SYMBOL, "{");
}

#line 111 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 112 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 113 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 115 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 115 "src/analyzer/Impl.pv"
        return false;
    }

    #line 117 "src/analyzer/Impl.pv"
    if (self->has_trait) {
        #line 118 "src/analyzer/Impl.pv"
        if (!Context__parse_type_trait(context, &self->trait_type, &self->generics)) {
            #line 118 "src/analyzer/Impl.pv"
            return false;
        }

        #line 120 "src/analyzer/Impl.pv"
        switch (self->trait_type.type) {
            #line 121 "src/analyzer/Impl.pv"
            case TYPE__TRAIT: {
                #line 121 "src/analyzer/Impl.pv"
                struct Trait* trait_info = self->trait_type.trait_value._0;
                #line 122 "src/analyzer/Impl.pv"
                self->trait_ = trait_info;
                #line 123 "src/analyzer/Impl.pv"
                self->trait_name = trait_info->name;
            } break;
            #line 125 "src/analyzer/Impl.pv"
            default: {
                #line 126 "src/analyzer/Impl.pv"
                Context__error(context, "Expected trait type in impl declaration");
                #line 127 "src/analyzer/Impl.pv"
                return false;
            } break;
        }

        #line 131 "src/analyzer/Impl.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 131 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 134 "src/analyzer/Impl.pv"
    if (!Context__parse_type(context, &self->type, &self->generics)) {
        #line 134 "src/analyzer/Impl.pv"
        return false;
    }

    #line 136 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 138 "src/analyzer/Impl.pv"
    return true;
}

#line 141 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 142 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 143 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 144 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;
    #line 145 "src/analyzer/Impl.pv"
    struct ArenaAllocator* allocator = context->allocator;

    #line 147 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 147 "src/analyzer/Impl.pv"
        return false;
    }

    #line 149 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 151 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end - 1) {
        #line 152 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
            #line 153 "src/analyzer/Impl.pv"
            Context__next_token(context);
            #line 154 "src/analyzer/Impl.pv"
            struct Token* const_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 155 "src/analyzer/Impl.pv"
            if (const_name == 0) {
                #line 155 "src/analyzer/Impl.pv"
                return false;
            }

            #line 157 "src/analyzer/Impl.pv"
            uintptr_t token_start = context->pos;
            #line 158 "src/analyzer/Impl.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 159 "src/analyzer/Impl.pv"
                Context__next_token(context);
            }
            #line 161 "src/analyzer/Impl.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 161 "src/analyzer/Impl.pv"
                return false;
            }
            #line 162 "src/analyzer/Impl.pv"
            uintptr_t token_end = context->pos;

            #line 164 "src/analyzer/Impl.pv"
            struct ImplConst* impl_const = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct ImplConst));
            #line 165 "src/analyzer/Impl.pv"
            *impl_const = (struct ImplConst) {
                .name = const_name,
                .context = context,
                .token_start = token_start,
                .token_end = token_end,
            };
            #line 171 "src/analyzer/Impl.pv"
            HashMap_str_ref_ImplConst__insert(&self->consts, const_name->value, impl_const);

            #line 173 "src/analyzer/Impl.pv"
            struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__CONST, .const_value = const_name->value };
            #line 174 "src/analyzer/Impl.pv"
            Array_ImplNode__append(nodes, impl_node);
        } else {
            #line 176 "src/analyzer/Impl.pv"
            struct Function func_info = Function__parse(context);
            #line 177 "src/analyzer/Impl.pv"
            func_info.parent = parent;
            #line 178 "src/analyzer/Impl.pv"
            if (func_info.name == 0) {
                #line 178 "src/analyzer/Impl.pv"
                return false;
            }

            #line 180 "src/analyzer/Impl.pv"
            HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

            #line 182 "src/analyzer/Impl.pv"
            struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
            #line 183 "src/analyzer/Impl.pv"
            Array_ImplNode__append(nodes, impl_node);
        }

        #line 186 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 189 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 189 "src/analyzer/Impl.pv"
        return false;
    }

    #line 191 "src/analyzer/Impl.pv"
    return true;
}

#line 194 "src/analyzer/Impl.pv"
struct Function* Impl__find_function(struct Impl* self, struct str name) {
    #line 195 "src/analyzer/Impl.pv"
    struct Function* func = HashMap_str_Function__find(&self->functions, &name);
    #line 196 "src/analyzer/Impl.pv"
    if (func != 0) {
        #line 196 "src/analyzer/Impl.pv"
        return func;
    }

    #line 198 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 199 "src/analyzer/Impl.pv"
        return HashMap_str_Function__find(&self->trait_->functions, &name);
    }

    #line 202 "src/analyzer/Impl.pv"
    return 0;
}

#line 205 "src/analyzer/Impl.pv"
bool Impl__parse_consts(struct Impl* self) {
    #line 206 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&self->consts);
    #line 206 "src/analyzer/Impl.pv"
    while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
        #line 206 "src/analyzer/Impl.pv"
        struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

        #line 207 "src/analyzer/Impl.pv"
        if (!ImplConst__parse_types(impl_const)) {
            #line 207 "src/analyzer/Impl.pv"
            return false;
        }
    } }
    #line 209 "src/analyzer/Impl.pv"
    return true;
}

#line 212 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 213 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 214 "src/analyzer/Impl.pv"
    context->type_self = &self->type;

    #line 216 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 216 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 216 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 217 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 220 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 221 "src/analyzer/Impl.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->trait_->functions);
        #line 221 "src/analyzer/Impl.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 221 "src/analyzer/Impl.pv"
            struct Function* trait_func = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 222 "src/analyzer/Impl.pv"
            bool has_default = trait_func->token_start < trait_func->token_end;

            #line 224 "src/analyzer/Impl.pv"
            struct Function* impl_func = HashMap_str_Function__find(&self->functions, &trait_func->name->value);

            #line 226 "src/analyzer/Impl.pv"
            if (impl_func == 0) {
                #line 227 "src/analyzer/Impl.pv"
                if (!has_default) {
                    #line 228 "src/analyzer/Impl.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                    #line 229 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "Implementation is missing trait function '", .length = strlen("Implementation is missing trait function '") });
                    #line 230 "src/analyzer/Impl.pv"
                    String__append(&message, trait_func->name->value);
                    #line 231 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                    #line 232 "src/analyzer/Impl.pv"
                    Context__error_token(self->context, self->token, String__c_str(&message));
                }
                #line 234 "src/analyzer/Impl.pv"
                continue;
            }

            #line 237 "src/analyzer/Impl.pv"
            struct GenericMap* generic_map = Type__get_generic_map(&self->trait_type, context);

            #line 239 "src/analyzer/Impl.pv"
            if (impl_func->parameters.length != trait_func->parameters.length) {
                #line 240 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 241 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function '", .length = strlen("Implementation of trait function '") });
                #line 242 "src/analyzer/Impl.pv"
                String__append(&message, trait_func->name->value);
                #line 243 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "' has wrong number of parameters", .length = strlen("' has wrong number of parameters") });
                #line 244 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func->name, String__c_str(&message));
            } else {
                #line 246 "src/analyzer/Impl.pv"
                uintptr_t i = 0;
                #line 247 "src/analyzer/Impl.pv"
                while (i < impl_func->parameters.length) {
                    #line 248 "src/analyzer/Impl.pv"
                    struct Parameter* impl_param = Array_Parameter__get(&impl_func->parameters, i);
                    #line 249 "src/analyzer/Impl.pv"
                    struct Parameter* trait_param = Array_Parameter__get(&trait_func->parameters, i);

                    #line 251 "src/analyzer/Impl.pv"
                    struct Type* trait_param_type = &trait_param->type;
                    #line 252 "src/analyzer/Impl.pv"
                    if (!Type__is_self(Type__deref(trait_param_type))) {
                        #line 252 "src/analyzer/Impl.pv"
                        trait_param_type = Context__resolve_type(context->allocator, trait_param_type, generic_map, 0);
                    }

                    #line 254 "src/analyzer/Impl.pv"
                    if (!Type__eq(&impl_param->type, trait_param_type)) {
                        #line 255 "src/analyzer/Impl.pv"
                        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                        #line 256 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = "Parameter ", .length = strlen("Parameter ") });
                        #line 257 "src/analyzer/Impl.pv"
                        String__append(&message, impl_param->name->value);
                        #line 258 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = " has type ", .length = strlen(" has type ") });
                        #line 259 "src/analyzer/Impl.pv"
                        struct String impl_type_name = Naming__get_type_decl(&context->root->naming_decl, &impl_param->type, context->type_self, 0);
                        #line 260 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&impl_type_name));
                        #line 261 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                        #line 262 "src/analyzer/Impl.pv"
                        struct String trait_type_name = Naming__get_type_decl(&context->root->naming_decl, trait_param_type, context->type_self, 0);
                        #line 263 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&trait_type_name));
                        #line 264 "src/analyzer/Impl.pv"
                        Context__error_token(self->context, impl_param->name, String__c_str(&message));
                    }
                    #line 266 "src/analyzer/Impl.pv"
                    i += 1;
                }
            }

            #line 270 "src/analyzer/Impl.pv"
            struct Type* trait_func_return_type = &trait_func->return_type;
            #line 271 "src/analyzer/Impl.pv"
            if (!Type__is_self(Type__deref(trait_func_return_type))) {
                #line 271 "src/analyzer/Impl.pv"
                trait_func_return_type = Context__resolve_type(context->allocator, trait_func_return_type, generic_map, 0);
            }

            #line 273 "src/analyzer/Impl.pv"
            if (!Type__eq(&impl_func->return_type, trait_func_return_type)) {
                #line 274 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 275 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function ", .length = strlen("Implementation of trait function ") });
                #line 276 "src/analyzer/Impl.pv"
                String__append(&message, trait_func->name->value);
                #line 277 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = " has return type ", .length = strlen(" has return type ") });
                #line 278 "src/analyzer/Impl.pv"
                struct String impl_return_name = Naming__get_type_decl(&context->root->naming_decl, &impl_func->return_type, context->type_self, 0);
                #line 279 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&impl_return_name));
                #line 280 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                #line 281 "src/analyzer/Impl.pv"
                struct String trait_return_name = Naming__get_type_decl(&context->root->naming_decl, trait_func_return_type, context->type_self, 0);
                #line 282 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&trait_return_name));
                #line 283 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func->name, String__c_str(&message));
            }
        } }
    }

    #line 288 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 290 "src/analyzer/Impl.pv"
    return true;
}
