#include <stdint.h>
#include <string.h>

#include <analyzer/Impl.h>
#include <analyzer/Context.h>
#include <analyzer/Token.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/types/Trait.h>
#include <std/str.h>
#include <analyzer/ImplNode.h>
#include <analyzer/ImplConst.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionParent.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <tuple_str_ref_ImplConst.h>
#include <std/HashMapIter_str_usize.h>
#include <tuple_str_usize.h>
#include <std/String.h>
#include <analyzer/types/GenericMap.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/Impl.h>

#include <analyzer/Impl.h>

#line 80 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 81 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .token = Context__current(context),
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .consts = HashMap_str_ref_ImplConst__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .typedef_starts = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .typedefs = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
        .token_start = 0,
        .token_end = 0,
        .has_trait = false,
        .trait_ = 0,
        .trait_name = 0,
        .trait_type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
    };

    #line 99 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl")) {
        #line 99 "src/analyzer/Impl.pv"
        return node;
    }

    #line 101 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 102 "src/analyzer/Impl.pv"
    Impl__skip_to_open_brace(&node);
    #line 103 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 104 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 106 "src/analyzer/Impl.pv"
    return node;
}

#line 109 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self) {
    #line 110 "src/analyzer/Impl.pv"
    struct Context* context = self->context;

    #line 112 "src/analyzer/Impl.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 113 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 114 "src/analyzer/Impl.pv"
            self->has_trait = true;
        }

        #line 117 "src/analyzer/Impl.pv"
        Context__next_token(context);
    }

    #line 120 "src/analyzer/Impl.pv"
    return Context__check_value(context, TOKEN_TYPE__SYMBOL, "{");
}

#line 123 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 124 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 125 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 127 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 127 "src/analyzer/Impl.pv"
        return false;
    }

    #line 129 "src/analyzer/Impl.pv"
    if (self->has_trait) {
        #line 130 "src/analyzer/Impl.pv"
        if (!Context__parse_type_trait(context, &self->trait_type, &self->generics)) {
            #line 130 "src/analyzer/Impl.pv"
            return false;
        }

        #line 132 "src/analyzer/Impl.pv"
        switch (self->trait_type.type) {
            #line 133 "src/analyzer/Impl.pv"
            case TYPE__TRAIT: {
                #line 133 "src/analyzer/Impl.pv"
                struct Trait* trait_info = self->trait_type.trait_value._0;
                #line 134 "src/analyzer/Impl.pv"
                self->trait_ = trait_info;
                #line 135 "src/analyzer/Impl.pv"
                self->trait_name = trait_info->name;
            } break;
            #line 137 "src/analyzer/Impl.pv"
            default: {
                #line 138 "src/analyzer/Impl.pv"
                Context__error(context, "Expected trait type in impl declaration");
                #line 139 "src/analyzer/Impl.pv"
                return false;
            } break;
        }

        #line 143 "src/analyzer/Impl.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 143 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 146 "src/analyzer/Impl.pv"
    if (!Context__parse_type(context, &self->type, &self->generics)) {
        #line 146 "src/analyzer/Impl.pv"
        return false;
    }

    #line 148 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 150 "src/analyzer/Impl.pv"
    return true;
}

#line 153 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 154 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 155 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 156 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;
    #line 157 "src/analyzer/Impl.pv"
    struct ArenaAllocator* allocator = context->allocator;

    #line 159 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 159 "src/analyzer/Impl.pv"
        return false;
    }

    #line 161 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 163 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 164 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "typedef")) {
            #line 165 "src/analyzer/Impl.pv"
            Context__next_token(context);
            #line 166 "src/analyzer/Impl.pv"
            struct Token* typedef_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 167 "src/analyzer/Impl.pv"
            if (typedef_name == 0) {
                #line 167 "src/analyzer/Impl.pv"
                return false;
            }
            #line 168 "src/analyzer/Impl.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
                #line 168 "src/analyzer/Impl.pv"
                return false;
            }
            #line 169 "src/analyzer/Impl.pv"
            uintptr_t token_start = context->pos;
            #line 170 "src/analyzer/Impl.pv"
            if (!Context__skip_to_statement_end(context)) {
                #line 170 "src/analyzer/Impl.pv"
                return false;
            }
            #line 171 "src/analyzer/Impl.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 171 "src/analyzer/Impl.pv"
                return false;
            }
            #line 172 "src/analyzer/Impl.pv"
            HashMap_str_usize__insert(&self->typedef_starts, typedef_name->value, token_start);
            #line 173 "src/analyzer/Impl.pv"
            Array_ImplNode__append(nodes, (struct ImplNode) { .type = IMPL_NODE__TYPEDEF, .typedef_value = typedef_name->value });
        } else if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "const")) {
            #line 175 "src/analyzer/Impl.pv"
            Context__next_token(context);
            #line 176 "src/analyzer/Impl.pv"
            struct Token* const_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 177 "src/analyzer/Impl.pv"
            if (const_name == 0) {
                #line 177 "src/analyzer/Impl.pv"
                return false;
            }

            #line 179 "src/analyzer/Impl.pv"
            uintptr_t token_start = context->pos;
            #line 180 "src/analyzer/Impl.pv"
            if (!Context__skip_to_statement_end(context)) {
                #line 180 "src/analyzer/Impl.pv"
                return false;
            }
            #line 181 "src/analyzer/Impl.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 181 "src/analyzer/Impl.pv"
                return false;
            }
            #line 182 "src/analyzer/Impl.pv"
            uintptr_t token_end = context->pos;

            #line 184 "src/analyzer/Impl.pv"
            struct ImplConst* impl_const = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct ImplConst));
            #line 185 "src/analyzer/Impl.pv"
            *impl_const = (struct ImplConst) {
                .name = const_name,
                .context = context,
                .token_start = token_start,
                .token_end = token_end,
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
                .value = 0,
            };
            #line 193 "src/analyzer/Impl.pv"
            HashMap_str_ref_ImplConst__insert(&self->consts, const_name->value, impl_const);

            #line 195 "src/analyzer/Impl.pv"
            struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__CONST, .const_value = const_name->value };
            #line 196 "src/analyzer/Impl.pv"
            Array_ImplNode__append(nodes, impl_node);
        } else {
            #line 198 "src/analyzer/Impl.pv"
            struct Function func_info = Function__parse(context);
            #line 199 "src/analyzer/Impl.pv"
            func_info.parent = parent;
            #line 200 "src/analyzer/Impl.pv"
            if (func_info.name == 0) {
                #line 200 "src/analyzer/Impl.pv"
                return false;
            }

            #line 202 "src/analyzer/Impl.pv"
            HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

            #line 204 "src/analyzer/Impl.pv"
            struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
            #line 205 "src/analyzer/Impl.pv"
            Array_ImplNode__append(nodes, impl_node);
        }

        #line 208 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 211 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 211 "src/analyzer/Impl.pv"
        return false;
    }

    #line 213 "src/analyzer/Impl.pv"
    return true;
}

#line 216 "src/analyzer/Impl.pv"
struct Function* Impl__find_function(struct Impl* self, struct str name) {
    #line 217 "src/analyzer/Impl.pv"
    struct Function* func = HashMap_str_Function__find(&self->functions, &name);
    #line 218 "src/analyzer/Impl.pv"
    if (func != 0) {
        #line 218 "src/analyzer/Impl.pv"
        return func;
    }

    #line 220 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 221 "src/analyzer/Impl.pv"
        return HashMap_str_Function__find(&self->trait_->functions, &name);
    }

    #line 224 "src/analyzer/Impl.pv"
    return 0;
}

#line 227 "src/analyzer/Impl.pv"
bool Impl__parse_consts(struct Impl* self) {
    #line 228 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&self->consts);
    #line 228 "src/analyzer/Impl.pv"
    while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
        #line 228 "src/analyzer/Impl.pv"
        struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

        #line 229 "src/analyzer/Impl.pv"
        if (!ImplConst__parse_types(impl_const)) {
            #line 229 "src/analyzer/Impl.pv"
            return false;
        }
    } }
    #line 231 "src/analyzer/Impl.pv"
    return true;
}

#line 234 "src/analyzer/Impl.pv"
bool Impl__parse_typedefs(struct Impl* self) {
    #line 235 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 236 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&self->typedef_starts);
    #line 236 "src/analyzer/Impl.pv"
    while (HashMapIter_str_usize__next(&__iter)) {
        #line 236 "src/analyzer/Impl.pv"
        struct str name = HashMapIter_str_usize__value(&__iter)->_0;
        #line 236 "src/analyzer/Impl.pv"
        uintptr_t* token_start = &HashMapIter_str_usize__value(&__iter)->_1;

        #line 237 "src/analyzer/Impl.pv"
        context->pos = *token_start;
        #line 238 "src/analyzer/Impl.pv"
        struct Type* typedef_type = Context__parse_type2(context, &self->generics);
        #line 239 "src/analyzer/Impl.pv"
        if (typedef_type == 0) {
            #line 239 "src/analyzer/Impl.pv"
            return false;
        }
        #line 240 "src/analyzer/Impl.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 240 "src/analyzer/Impl.pv"
            return false;
        }
        #line 241 "src/analyzer/Impl.pv"
        HashMap_str_Type__insert(&self->typedefs, name, *typedef_type);
    } }

    #line 244 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 245 "src/analyzer/Impl.pv"
        struct Trait* trait_info = self->trait_;

        #line 247 "src/analyzer/Impl.pv"
        { struct HashMapIter_str_usize __iter = HashMap_str_usize__iter(&trait_info->typedefs);
        #line 247 "src/analyzer/Impl.pv"
        while (HashMapIter_str_usize__next(&__iter)) {
            #line 247 "src/analyzer/Impl.pv"
            struct str name = HashMapIter_str_usize__value(&__iter)->_0;

            #line 248 "src/analyzer/Impl.pv"
            if (HashMap_str_Type__find(&self->typedefs, &name) == 0) {
                #line 249 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 250 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation is missing trait typedef '", .length = strlen("Implementation is missing trait typedef '") });
                #line 251 "src/analyzer/Impl.pv"
                String__append(&message, name);
                #line 252 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                #line 253 "src/analyzer/Impl.pv"
                Context__error_token(self->context, self->token, String__c_str(&message));
            }
        } }

        #line 257 "src/analyzer/Impl.pv"
        if (self->typedefs.length > 0) {
            #line 258 "src/analyzer/Impl.pv"
            switch (self->trait_type.type) {
                #line 259 "src/analyzer/Impl.pv"
                case TYPE__TRAIT: {
                    #line 259 "src/analyzer/Impl.pv"
                    struct Trait* trait_info = self->trait_type.trait_value._0;
                    #line 259 "src/analyzer/Impl.pv"
                    struct GenericMap* generic_map = self->trait_type.trait_value._1;
                    #line 260 "src/analyzer/Impl.pv"
                    if (generic_map == 0) {
                        #line 260 "src/analyzer/Impl.pv"
                        return false;
                    }
                    #line 261 "src/analyzer/Impl.pv"
                    struct GenericMap new_map_val = GenericMap__clone(generic_map, self->context->allocator);
                    #line 262 "src/analyzer/Impl.pv"
                    struct GenericMap* new_map = ArenaAllocator__store_GenericMap(self->context->allocator, &new_map_val);
                    #line 263 "src/analyzer/Impl.pv"
                    if (new_map == 0) {
                        #line 263 "src/analyzer/Impl.pv"
                        return false;
                    }
                    #line 264 "src/analyzer/Impl.pv"
                    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&self->typedefs);
                    #line 264 "src/analyzer/Impl.pv"
                    while (HashMapIter_str_Type__next(&__iter)) {
                        #line 264 "src/analyzer/Impl.pv"
                        struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                        #line 264 "src/analyzer/Impl.pv"
                        struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                        #line 265 "src/analyzer/Impl.pv"
                        GenericMap__insert(new_map, name, *typedef_type);
                    } }
                    #line 267 "src/analyzer/Impl.pv"
                    self->trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = new_map} };
                } break;
                #line 269 "src/analyzer/Impl.pv"
                default: {
                } break;
            }
        }
    }

    #line 274 "src/analyzer/Impl.pv"
    return true;
}

#line 277 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 278 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 279 "src/analyzer/Impl.pv"
    context->type_self = &self->type;

    #line 281 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 281 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 281 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 282 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 285 "src/analyzer/Impl.pv"
    if (self->has_trait && self->trait_ != 0) {
        #line 286 "src/analyzer/Impl.pv"
        struct Trait* trait_info = self->trait_;

        #line 288 "src/analyzer/Impl.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 288 "src/analyzer/Impl.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 288 "src/analyzer/Impl.pv"
            struct Function* trait_func = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 289 "src/analyzer/Impl.pv"
            bool has_default = trait_func->token_start < trait_func->token_end;
            #line 290 "src/analyzer/Impl.pv"
            struct Token* trait_func_name = trait_func->name;
            #line 291 "src/analyzer/Impl.pv"
            if (trait_func_name == 0) {
                #line 291 "src/analyzer/Impl.pv"
                return false;
            }

            #line 293 "src/analyzer/Impl.pv"
            struct Function* impl_func = HashMap_str_Function__find(&self->functions, &trait_func_name->value);

            #line 295 "src/analyzer/Impl.pv"
            if (impl_func == 0) {
                #line 296 "src/analyzer/Impl.pv"
                if (!has_default) {
                    #line 297 "src/analyzer/Impl.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                    #line 298 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "Implementation is missing trait function '", .length = strlen("Implementation is missing trait function '") });
                    #line 299 "src/analyzer/Impl.pv"
                    String__append(&message, trait_func_name->value);
                    #line 300 "src/analyzer/Impl.pv"
                    String__append(&message, (struct str){ .ptr = "'", .length = strlen("'") });
                    #line 301 "src/analyzer/Impl.pv"
                    Context__error_token(self->context, self->token, String__c_str(&message));
                }
                #line 303 "src/analyzer/Impl.pv"
                continue;
            }

            #line 306 "src/analyzer/Impl.pv"
            struct GenericMap* generic_map = Type__get_generic_map(&self->trait_type, context);
            #line 307 "src/analyzer/Impl.pv"
            if (self->typedefs.length > 0) {
                #line 308 "src/analyzer/Impl.pv"
                if (generic_map == 0) {
                    #line 308 "src/analyzer/Impl.pv"
                    return false;
                }
                #line 309 "src/analyzer/Impl.pv"
                struct GenericMap aug_map_val = GenericMap__clone(generic_map, context->allocator);
                #line 310 "src/analyzer/Impl.pv"
                struct GenericMap* aug_map = ArenaAllocator__store_GenericMap(context->allocator, &aug_map_val);
                #line 311 "src/analyzer/Impl.pv"
                if (aug_map == 0) {
                    #line 311 "src/analyzer/Impl.pv"
                    return false;
                }
                #line 312 "src/analyzer/Impl.pv"
                { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&self->typedefs);
                #line 312 "src/analyzer/Impl.pv"
                while (HashMapIter_str_Type__next(&__iter)) {
                    #line 312 "src/analyzer/Impl.pv"
                    struct str name = HashMapIter_str_Type__value(&__iter)->_0;
                    #line 312 "src/analyzer/Impl.pv"
                    struct Type* typedef_type = &HashMapIter_str_Type__value(&__iter)->_1;

                    #line 313 "src/analyzer/Impl.pv"
                    GenericMap__insert(aug_map, name, *typedef_type);
                } }
                #line 315 "src/analyzer/Impl.pv"
                generic_map = aug_map;
            }

            #line 318 "src/analyzer/Impl.pv"
            if (impl_func->parameters.length != trait_func->parameters.length) {
                #line 319 "src/analyzer/Impl.pv"
                struct Token* impl_func_name = impl_func->name;
                #line 320 "src/analyzer/Impl.pv"
                if (impl_func_name == 0) {
                    #line 320 "src/analyzer/Impl.pv"
                    return false;
                }

                #line 322 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 323 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function '", .length = strlen("Implementation of trait function '") });
                #line 324 "src/analyzer/Impl.pv"
                String__append(&message, trait_func_name->value);
                #line 325 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "' has wrong number of parameters", .length = strlen("' has wrong number of parameters") });
                #line 326 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func_name, String__c_str(&message));
            } else {
                #line 328 "src/analyzer/Impl.pv"
                uintptr_t i = 0;
                #line 329 "src/analyzer/Impl.pv"
                while (i < impl_func->parameters.length) {
                    #line 330 "src/analyzer/Impl.pv"
                    struct Parameter* impl_param = Array_Parameter__get(&impl_func->parameters, i);
                    #line 331 "src/analyzer/Impl.pv"
                    struct Parameter* trait_param = Array_Parameter__get(&trait_func->parameters, i);
                    #line 332 "src/analyzer/Impl.pv"
                    if (impl_param == 0 || trait_param == 0) {
                        #line 332 "src/analyzer/Impl.pv"
                        return false;
                    }

                    #line 334 "src/analyzer/Impl.pv"
                    struct Type* trait_param_type = &trait_param->type;
                    #line 335 "src/analyzer/Impl.pv"
                    if (!Type__is_self(Type__deref(trait_param_type))) {
                        #line 335 "src/analyzer/Impl.pv"
                        trait_param_type = Context__resolve_type(context->allocator, trait_param_type, generic_map, 0);
                    }

                    #line 337 "src/analyzer/Impl.pv"
                    if (!Type__eq(&impl_param->type, trait_param_type)) {
                        #line 338 "src/analyzer/Impl.pv"
                        struct Token* impl_param_name = impl_param->name;
                        #line 339 "src/analyzer/Impl.pv"
                        if (impl_param_name == 0) {
                            #line 339 "src/analyzer/Impl.pv"
                            return false;
                        }

                        #line 341 "src/analyzer/Impl.pv"
                        struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                        #line 342 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = "Parameter ", .length = strlen("Parameter ") });
                        #line 343 "src/analyzer/Impl.pv"
                        String__append(&message, impl_param_name->value);
                        #line 344 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = " has type ", .length = strlen(" has type ") });
                        #line 345 "src/analyzer/Impl.pv"
                        struct String impl_type_name = Naming__get_type_decl(&context->root->naming_decl, &impl_param->type, context->type_self, 0);
                        #line 346 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&impl_type_name));
                        #line 347 "src/analyzer/Impl.pv"
                        String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                        #line 348 "src/analyzer/Impl.pv"
                        struct String trait_type_name = Naming__get_type_decl(&context->root->naming_decl, trait_param_type, context->type_self, 0);
                        #line 349 "src/analyzer/Impl.pv"
                        String__append(&message, String__as_str(&trait_type_name));
                        #line 350 "src/analyzer/Impl.pv"
                        Context__error_token(self->context, impl_param_name, String__c_str(&message));
                    }
                    #line 352 "src/analyzer/Impl.pv"
                    i += 1;
                }
            }

            #line 356 "src/analyzer/Impl.pv"
            struct Type* trait_func_return_type = &trait_func->return_type;
            #line 357 "src/analyzer/Impl.pv"
            if (!Type__is_self(Type__deref(trait_func_return_type))) {
                #line 357 "src/analyzer/Impl.pv"
                trait_func_return_type = Context__resolve_type(context->allocator, trait_func_return_type, generic_map, 0);
            }

            #line 359 "src/analyzer/Impl.pv"
            if (!Type__eq(&impl_func->return_type, trait_func_return_type)) {
                #line 360 "src/analyzer/Impl.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 361 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = "Implementation of trait function ", .length = strlen("Implementation of trait function ") });
                #line 362 "src/analyzer/Impl.pv"
                String__append(&message, trait_func_name->value);
                #line 363 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = " has return type ", .length = strlen(" has return type ") });
                #line 364 "src/analyzer/Impl.pv"
                struct String impl_return_name = Naming__get_type_decl(&context->root->naming_decl, &impl_func->return_type, context->type_self, 0);
                #line 365 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&impl_return_name));
                #line 366 "src/analyzer/Impl.pv"
                String__append(&message, (struct str){ .ptr = ", expected ", .length = strlen(", expected ") });
                #line 367 "src/analyzer/Impl.pv"
                struct String trait_return_name = Naming__get_type_decl(&context->root->naming_decl, trait_func_return_type, context->type_self, 0);
                #line 368 "src/analyzer/Impl.pv"
                String__append(&message, String__as_str(&trait_return_name));
                #line 369 "src/analyzer/Impl.pv"
                struct Token* impl_func_name = impl_func->name;
                #line 370 "src/analyzer/Impl.pv"
                if (impl_func_name == 0) {
                    #line 370 "src/analyzer/Impl.pv"
                    return false;
                }
                #line 371 "src/analyzer/Impl.pv"
                Context__error_token(self->context, impl_func_name, String__c_str(&message));
            }
        } }
    }

    #line 376 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 378 "src/analyzer/Impl.pv"
    return true;
}
