#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/Namespace.h>
#include <analyzer/Analysis.h>
#include <analyzer/Module.h>
#include <std/trait_Allocator.h>
#include <analyzer/Tokenizer.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <analyzer/NamespacePath.h>
#include <analyzer/c/Include.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Struct.h>
#include <analyzer/Impl.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Global.h>
#include <std/Iter_ref_NamespacePath.h>
#include <std/Iter_ref_ref_Token.h>
#include <std/Array_ref_Token.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Type.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Enum.h>
#include <tuple_str_Enum.h>
#include <std/HashMapIter_str_Struct.h>
#include <tuple_str_Struct.h>
#include <analyzer/types/Generics.h>
#include <std/HashMapIter_str_Trait.h>
#include <tuple_str_Trait.h>
#include <std/HashMap_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Global.h>
#include <tuple_str_ref_Global.h>
#include <std/Iter_ref_ref_Namespace.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/FunctionParent.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/TypeImpl.h>
#include <std/Iter_ref_TypeImpl.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/Module.h>

#include <analyzer/Module.h>

#line 29 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path) {
    #line 30 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 31 "src/analyzer/Module.pv"
    struct Analysis* analysis = namespace->root->analysis;
    #line 32 "src/analyzer/Module.pv"
    struct Module* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Module));

    #line 34 "src/analyzer/Module.pv"
    *self = (struct Module) {
        .root = namespace->root,
        .namespace = namespace,
        .path = path,
        .use_namespaces = Array_NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .used_namespaces = Array_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_str_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_str_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impls = Array_TypeImpl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes = HashMap_str_ref_Include__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .globals = HashMap_str_ref_Global__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .global_types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 52 "src/analyzer/Module.pv"
    self->context = Context__new(allocator, (struct str){ .ptr = "", .length = strlen("") }, path, 0, analysis, self);

    #line 54 "src/analyzer/Module.pv"
    return self;
}

#line 57 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self) {
    #line 58 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;
    #line 59 "src/analyzer/Module.pv"
    struct Array_NamespacePath* use_namespaces = &self->use_namespaces;
    #line 60 "src/analyzer/Module.pv"
    struct HashMap_str_Enum* enums = &self->enums;
    #line 61 "src/analyzer/Module.pv"
    struct HashMap_str_Struct* structs = &self->structs;
    #line 62 "src/analyzer/Module.pv"
    struct HashMap_str_Trait* traits = &self->traits;
    #line 63 "src/analyzer/Module.pv"
    struct Array_Impl* impls = &self->impls;
    #line 64 "src/analyzer/Module.pv"
    struct HashMap_str_Function* functions = &self->functions;
    #line 65 "src/analyzer/Module.pv"
    struct Context* context = &self->context;

    #line 67 "src/analyzer/Module.pv"
    self->tokens = Tokenizer__tokenize(allocator, self->path.ptr);
    #line 68 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 69 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;

    #line 71 "src/analyzer/Module.pv"
    bool result = true;

    #line 73 "src/analyzer/Module.pv"
    while (context->pos < context->length && result) {
        #line 74 "src/analyzer/Module.pv"
        struct Token* token = &context->tokens[context->pos];

        #line 76 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "ns")) {
            #line 77 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "ns")) {
                #line 77 "src/analyzer/Module.pv"
                return false;
            }
            #line 78 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 79 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 81 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 82 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 84 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 85 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 88 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 90 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 91 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 93 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 94 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "mod")) {
            #line 98 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "mod")) {
                #line 98 "src/analyzer/Module.pv"
                return false;
            }
            #line 99 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 100 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 102 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 103 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 105 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 106 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 109 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 111 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 112 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 114 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 115 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "use")) {
            #line 119 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "use")) {
                #line 119 "src/analyzer/Module.pv"
                return false;
            }

            #line 121 "src/analyzer/Module.pv"
            struct NamespacePath path = NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 122 "src/analyzer/Module.pv"
            if (!NamespacePath__parse(&path, context)) {
                #line 122 "src/analyzer/Module.pv"
                return false;
            }

            #line 124 "src/analyzer/Module.pv"
            Array_NamespacePath__append(use_namespaces, path);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#cpp")) {
            #line 126 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#cpp")) {
                #line 126 "src/analyzer/Module.pv"
                return false;
            }
            #line 127 "src/analyzer/Module.pv"
            self->mode_cpp = true;
            #line 128 "src/analyzer/Module.pv"
            self->root->mode_cpp = true;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#include")) {
            #line 130 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#include")) {
                #line 130 "src/analyzer/Module.pv"
                return false;
            }

            #line 132 "src/analyzer/Module.pv"
            struct Token* path = Context__expect(context, TOKEN_TYPE__STRING);
            #line 133 "src/analyzer/Module.pv"
            if (path == 0) {
                #line 133 "src/analyzer/Module.pv"
                return false;
            }

            #line 135 "src/analyzer/Module.pv"
            struct HashMap_str_ref_Include* includes = &self->root->includes_c;
            #line 136 "src/analyzer/Module.pv"
            if (self->mode_cpp) {
                #line 136 "src/analyzer/Module.pv"
                includes = &self->root->includes_cpp;
            }

            #line 138 "src/analyzer/Module.pv"
            struct Include** include_ptr = HashMap_str_ref_Include__find(includes, &path->value);
            #line 139 "src/analyzer/Module.pv"
            struct Include* include = 0;
            #line 140 "src/analyzer/Module.pv"
            if (include_ptr != 0) {
                #line 140 "src/analyzer/Module.pv"
                include = *include_ptr;
            }

            #line 142 "src/analyzer/Module.pv"
            if (include == 0) {
                #line 143 "src/analyzer/Module.pv"
                include = Include__new(self->root, path->value, self->mode_cpp);
                #line 144 "src/analyzer/Module.pv"
                Include__process(include);
                #line 145 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(includes, path->value, include);
            }

            #line 148 "src/analyzer/Module.pv"
            if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                #line 149 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(&self->includes, path->value, include);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 152 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 154 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 155 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 157 "src/analyzer/Module.pv"
                HashMap_str_Enum__insert(enums, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 160 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 162 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 163 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 165 "src/analyzer/Module.pv"
                HashMap_str_Struct__insert(structs, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 168 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 170 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 171 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 173 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 176 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 178 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 179 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 181 "src/analyzer/Module.pv"
                HashMap_str_Trait__insert(traits, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 184 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 186 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 187 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 189 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "const") || Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 192 "src/analyzer/Module.pv"
            bool is_const = Token__eq(token, TOKEN_TYPE__KEYWORD, "const");
            #line 193 "src/analyzer/Module.pv"
            Context__next_token(context);
            #line 194 "src/analyzer/Module.pv"
            struct Token* global_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 195 "src/analyzer/Module.pv"
            if (global_name == 0) {
                #line 195 "src/analyzer/Module.pv"
                return false;
            }

            #line 197 "src/analyzer/Module.pv"
            uintptr_t token_start = context->pos;

            #line 199 "src/analyzer/Module.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 200 "src/analyzer/Module.pv"
                Context__next_token(context);
            }
            #line 202 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 202 "src/analyzer/Module.pv"
                return false;
            }
            #line 203 "src/analyzer/Module.pv"
            uintptr_t token_end = context->pos;

            #line 205 "src/analyzer/Module.pv"
            struct Global* global = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Global));
            #line 206 "src/analyzer/Module.pv"
            *global = (struct Global) {
                .name = global_name,
                .module = self,
                .token_start = token_start,
                .token_end = token_end,
                .is_const = is_const,
            };
            #line 213 "src/analyzer/Module.pv"
            HashMap_str_ref_Global__insert(&self->globals, global_name->value, global);
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 215 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 217 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 218 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 222 "src/analyzer/Module.pv"
    return result;
}

#line 225 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 226 "src/analyzer/Module.pv"
    bool success = true;

    #line 228 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 228 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 228 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 229 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 232 "src/analyzer/Module.pv"
    return success;
}

#line 235 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 236 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 237 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 238 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 239 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 241 "src/analyzer/Module.pv"
    if (path->root) {
        #line 242 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 244 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 247 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 248 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 249 "src/analyzer/Module.pv"
        return false;
    }

    #line 252 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 252 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 252 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 253 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 254 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 255 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 256 "src/analyzer/Module.pv"
            return false;
        }

        #line 259 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 262 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 264 "src/analyzer/Module.pv"
    return true;
}

#line 267 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 268 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 269 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 270 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, &(struct GenericMap) {});
    #line 271 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr(&(struct Type) { .type = TYPE__SELF }, allocator);

    #line 273 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 273 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 273 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 274 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_info->name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 277 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 277 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 277 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 278 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, enum_info->name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} });
    } }

    #line 281 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 281 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 281 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 282 "src/analyzer/Module.pv"
        struct GenericMap generics_val = GenericMap__from_generics(allocator, &struct_info->generics);
        #line 283 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, &generics_val);
        #line 284 "src/analyzer/Module.pv"
        generics->self_type = blank_generics->self_type;

        #line 286 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, struct_info->name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} });
    } }

    #line 289 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 289 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 289 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 290 "src/analyzer/Module.pv"
        HashMap_str_ref_Trait__insert(&namespace->traits, trait_info->name->value, trait_info);
    } }

    #line 293 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 293 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 293 "src/analyzer/Module.pv"
        struct str name = HashMapIter_str_ref_Global__value(&__iter)->_0;
        #line 293 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 294 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&self->global_types, name, (struct Type) { .type = TYPE__GLOBAL, .global_value = global });
    } }

    #line 297 "src/analyzer/Module.pv"
    return true;
}

#line 300 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 301 "src/analyzer/Module.pv"
    bool success = true;

    #line 303 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 303 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 303 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 304 "src/analyzer/Module.pv"
        if (str__eq(namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 305 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 306 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, &(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") } });

            #line 308 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, &(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") } });

            #line 310 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 311 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 312 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 314 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 315 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 317 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") });
            #line 318 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 319 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 322 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 325 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 326 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 330 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 330 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 330 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 331 "src/analyzer/Module.pv"
        success = Enum__prefill_types(enum_info) && success;
    } }

    #line 334 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 334 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 334 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 335 "src/analyzer/Module.pv"
        success = Struct__prefill_types(struct_info) && success;
    } }

    #line 338 "src/analyzer/Module.pv"
    return success;
}

#line 341 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 342 "src/analyzer/Module.pv"
    bool success = true;
    #line 343 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 345 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 345 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 345 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 346 "src/analyzer/Module.pv"
        success = Impl__prefill_types(impl_info) && success;

        #line 348 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 349 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 349 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 350 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 350 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 351 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 353 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 354 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 356 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 356 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 357 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 357 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, impl_info->trait_->name->value, (struct tuple_ref_Trait_ref_Type) { ._0 = impl_info->trait_, ._1 = &impl_info->trait_type });
                }
                #line 358 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 359 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 360 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 362 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 362 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 363 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 363 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 364 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 366 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 366 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 367 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 368 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 368 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 369 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 371 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 371 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 372 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 373 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 373 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 374 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 376 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 376 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 377 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 378 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 378 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 379 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 381 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 382 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info));
                #line 383 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 385 "src/analyzer/Module.pv"
            default: {
                #line 385 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->token, "TODO: Currently unimplemented");
            } break;
        }
    } }

    #line 389 "src/analyzer/Module.pv"
    return success;
}

#line 392 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 393 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 393 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 393 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 394 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 398 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 398 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 398 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 399 "src/analyzer/Module.pv"
        Enum__fill_variants(enum_info);
    } }

    #line 402 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 402 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 402 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 403 "src/analyzer/Module.pv"
        Struct__fill_types(struct_info);
    } }

    #line 406 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 406 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 406 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 407 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
        #line 408 "src/analyzer/Module.pv"
        Trait__fill_types(trait_info, parent);

        #line 411 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 411 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 411 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 412 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &trait_info->generics);
        } }
    } }

    #line 416 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 416 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 416 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 417 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 417 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 417 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 418 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 422 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 422 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 422 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 423 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 424 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 426 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 426 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 426 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 427 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 431 "src/analyzer/Module.pv"
    return true;
}

#line 434 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self) {
    #line 435 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 435 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 435 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 436 "src/analyzer/Module.pv"
        Global__parse_types(global);
    } }

    #line 439 "src/analyzer/Module.pv"
    return true;
}

#line 442 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 443 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 445 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 445 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 445 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 446 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 447 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 450 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 450 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 450 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 451 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 454 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 454 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 454 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 455 "src/analyzer/Module.pv"
        Trait__parse_functions(trait_info);
    } }

    #line 458 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 458 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 458 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 459 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 462 "src/analyzer/Module.pv"
    return true;
}

#line 465 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name) {
    #line 466 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 467 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 467 "src/analyzer/Module.pv"
        return type;
    }

    #line 469 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name);
    #line 470 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 470 "src/analyzer/Module.pv"
        return type;
    }

    #line 472 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 472 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 472 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 473 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name);
        #line 474 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 474 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 477 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name);
    #line 478 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 478 "src/analyzer/Module.pv"
        return type;
    }

    #line 480 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 480 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 480 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 481 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 482 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 482 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 485 "src/analyzer/Module.pv"
    return 0;
}

#line 488 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name) {
    #line 489 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name);
    #line 490 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 490 "src/analyzer/Module.pv"
        return type;
    }

    #line 492 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name);
    #line 493 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 493 "src/analyzer/Module.pv"
        return type;
    }

    #line 495 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 495 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 495 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 496 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name);
        #line 497 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 497 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 500 "src/analyzer/Module.pv"
    return 0;
}

#line 503 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 504 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 505 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 505 "src/analyzer/Module.pv"
        return type;
    }

    #line 507 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 508 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 508 "src/analyzer/Module.pv"
        return type;
    }

    #line 510 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 510 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 510 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 511 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 512 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 512 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 515 "src/analyzer/Module.pv"
    return 0;
}

#line 518 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 519 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->global_types, &name);
    #line 520 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 520 "src/analyzer/Module.pv"
        return type;
    }

    #line 522 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 522 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 522 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 523 "src/analyzer/Module.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 523 "src/analyzer/Module.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 523 "src/analyzer/Module.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 524 "src/analyzer/Module.pv"
            type = HashMap_str_Type__find(&module->global_types, &name);
            #line 525 "src/analyzer/Module.pv"
            if (type != 0) {
                #line 525 "src/analyzer/Module.pv"
                return type;
            }
        } }
    } }

    #line 529 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 529 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 529 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 530 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->values, &name);
        #line 531 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 531 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 534 "src/analyzer/Module.pv"
    return 0;
}

#line 537 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 538 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name);
    #line 539 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 542 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 543 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 544 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &name);
}
