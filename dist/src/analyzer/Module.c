#include <stdio.h>

#include <analyzer/Namespace.h>
#include <std/str.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/Analysis.h>
#include <stdint.h>
#include <std/HashMap_str_Primitive.h>
#include <std/Array_NamespacePath.h>
#include <analyzer/NamespacePath.h>
#include <std/trait_Allocator.h>
#include <std/Array_ref_Namespace.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_Enum.h>
#include <analyzer/types/Enum.h>
#include <std/HashMap_str_Struct.h>
#include <analyzer/types/Struct.h>
#include <std/HashMap_str_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/Array_Impl.h>
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/types/Function.h>
#include <std/Array_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <std/HashMap_str_ref_Include.h>
#include <analyzer/c/Include.h>
#include <analyzer/Context.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <stdbool.h>
#include <analyzer/Tokenizer.h>
#include <analyzer/TokenType.h>
#include <std/Iter_ref_NamespacePath.h>
#include <std/Iter_ref_ref_Token.h>
#include <std/Array_ref_Token.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/types/GenericMap.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Enum.h>
#include <std/HashMapIter_str_Enum.h>
#include <tuple_str_Struct.h>
#include <std/HashMapIter_str_Struct.h>
#include <analyzer/types/Generics.h>
#include <tuple_str_Trait.h>
#include <std/HashMapIter_str_Trait.h>
#include <std/HashMap_str_ref_Trait.h>
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
#include <std/Iter_ref_TypeImpl.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <std/Array_Type.h>

#include <analyzer/Module.h>

#line 27 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path) {
    #line 28 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 29 "src/analyzer/Module.pv"
    struct Analysis* analysis = namespace->root->analysis;
    #line 30 "src/analyzer/Module.pv"
    struct Module* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Module));

    #line 32 "src/analyzer/Module.pv"
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
    };

    #line 48 "src/analyzer/Module.pv"
    self->context = Context__new(allocator, (struct str){ .ptr = "", .length = strlen("") }, path, 0, analysis, self);

    #line 50 "src/analyzer/Module.pv"
    return self;
}

#line 53 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self) {
    #line 54 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;
    #line 55 "src/analyzer/Module.pv"
    struct Array_NamespacePath* use_namespaces = &self->use_namespaces;
    #line 56 "src/analyzer/Module.pv"
    struct HashMap_str_Enum* enums = &self->enums;
    #line 57 "src/analyzer/Module.pv"
    struct HashMap_str_Struct* structs = &self->structs;
    #line 58 "src/analyzer/Module.pv"
    struct HashMap_str_Trait* traits = &self->traits;
    #line 59 "src/analyzer/Module.pv"
    struct Array_Impl* impls = &self->impls;
    #line 60 "src/analyzer/Module.pv"
    struct HashMap_str_Function* functions = &self->functions;
    #line 61 "src/analyzer/Module.pv"
    struct Context* context = &self->context;

    #line 63 "src/analyzer/Module.pv"
    self->tokens = Tokenizer__tokenize(allocator, self->path.ptr);
    #line 64 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 65 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;

    #line 67 "src/analyzer/Module.pv"
    bool result = true;

    #line 69 "src/analyzer/Module.pv"
    while (context->pos < context->length && result) {
        #line 70 "src/analyzer/Module.pv"
        struct Token* token = &context->tokens[context->pos];

        #line 72 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "ns")) {
            #line 73 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "ns")) {
                #line 73 "src/analyzer/Module.pv"
                return false;
            }
            #line 74 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 75 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 77 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 78 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 80 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 81 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 84 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 86 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 87 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 89 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 90 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "mod")) {
            #line 94 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "mod")) {
                #line 94 "src/analyzer/Module.pv"
                return false;
            }
            #line 95 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 96 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 98 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 99 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 101 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 102 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 105 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 107 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 108 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 110 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 111 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "use")) {
            #line 115 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "use")) {
                #line 115 "src/analyzer/Module.pv"
                return false;
            }

            #line 117 "src/analyzer/Module.pv"
            struct NamespacePath path = NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 118 "src/analyzer/Module.pv"
            if (!NamespacePath__parse(&path, context)) {
                #line 118 "src/analyzer/Module.pv"
                return false;
            }

            #line 120 "src/analyzer/Module.pv"
            Array_NamespacePath__append(use_namespaces, path);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#cpp")) {
            #line 122 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#cpp")) {
                #line 122 "src/analyzer/Module.pv"
                return false;
            }
            #line 123 "src/analyzer/Module.pv"
            self->mode_cpp = true;
            #line 124 "src/analyzer/Module.pv"
            self->root->mode_cpp = true;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#include")) {
            #line 126 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#include")) {
                #line 126 "src/analyzer/Module.pv"
                return false;
            }

            #line 128 "src/analyzer/Module.pv"
            struct Token* path = Context__expect(context, TOKEN_TYPE__STRING);
            #line 129 "src/analyzer/Module.pv"
            if (path == 0) {
                #line 129 "src/analyzer/Module.pv"
                return false;
            }

            #line 131 "src/analyzer/Module.pv"
            struct HashMap_str_ref_Include* includes = &self->root->includes_c;
            #line 132 "src/analyzer/Module.pv"
            if (self->mode_cpp) {
                #line 132 "src/analyzer/Module.pv"
                includes = &self->root->includes_cpp;
            }

            #line 134 "src/analyzer/Module.pv"
            struct Include** include_ptr = HashMap_str_ref_Include__find(includes, &path->value);
            #line 135 "src/analyzer/Module.pv"
            struct Include* include = 0;
            #line 136 "src/analyzer/Module.pv"
            if (include_ptr != 0) {
                #line 136 "src/analyzer/Module.pv"
                include = *include_ptr;
            }

            #line 138 "src/analyzer/Module.pv"
            if (include == 0) {
                #line 139 "src/analyzer/Module.pv"
                include = Include__new(self->root, path->value, self->mode_cpp);
                #line 140 "src/analyzer/Module.pv"
                Include__process(include);
                #line 141 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(includes, path->value, include);
            }

            #line 144 "src/analyzer/Module.pv"
            if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                #line 145 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(&self->includes, path->value, include);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 148 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 150 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 151 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 153 "src/analyzer/Module.pv"
                HashMap_str_Enum__insert(enums, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 156 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 158 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 159 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 161 "src/analyzer/Module.pv"
                HashMap_str_Struct__insert(structs, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 164 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 166 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 167 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 169 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 172 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 174 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 175 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 177 "src/analyzer/Module.pv"
                HashMap_str_Trait__insert(traits, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 180 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 182 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 183 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 185 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 188 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 190 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 191 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 195 "src/analyzer/Module.pv"
    return result;
}

#line 198 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 199 "src/analyzer/Module.pv"
    bool success = true;

    #line 201 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 201 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 201 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 202 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 205 "src/analyzer/Module.pv"
    return success;
}

#line 208 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 209 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 210 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 211 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 212 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 214 "src/analyzer/Module.pv"
    if (path->root) {
        #line 215 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 217 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 220 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 221 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 222 "src/analyzer/Module.pv"
        return false;
    }

    #line 225 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 225 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 225 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 226 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 227 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 228 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 229 "src/analyzer/Module.pv"
            return false;
        }

        #line 232 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 235 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 237 "src/analyzer/Module.pv"
    return true;
}

#line 240 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 241 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 242 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 243 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap) {});
    #line 244 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr(&(struct Type) { .type = TYPE__SELF }, allocator);

    #line 246 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 246 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 246 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 247 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_info->name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 250 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 250 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 250 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 251 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, enum_info->name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} });
    } }

    #line 254 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 254 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 254 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 255 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__from_generics(allocator, &struct_info->generics));
        #line 256 "src/analyzer/Module.pv"
        generics->self_type = blank_generics->self_type;

        #line 258 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, struct_info->name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} });
    } }

    #line 261 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 261 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 261 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 262 "src/analyzer/Module.pv"
        HashMap_str_ref_Trait__insert(&namespace->traits, trait_info->name->value, trait_info);
    } }

    #line 265 "src/analyzer/Module.pv"
    return true;
}

#line 268 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 269 "src/analyzer/Module.pv"
    bool success = true;

    #line 271 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 271 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 271 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 272 "src/analyzer/Module.pv"
        if (str__eq(namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 273 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 274 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") } });

            #line 276 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") } });

            #line 278 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 279 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 280 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 282 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 283 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 285 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") });
            #line 286 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 287 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 290 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 293 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 294 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 298 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 298 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 298 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 299 "src/analyzer/Module.pv"
        success = Enum__prefill_types(enum_info) && success;
    } }

    #line 302 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 302 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 302 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 303 "src/analyzer/Module.pv"
        success = Struct__prefill_types(struct_info) && success;
    } }

    #line 306 "src/analyzer/Module.pv"
    return success;
}

#line 309 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 310 "src/analyzer/Module.pv"
    bool success = true;
    #line 311 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 313 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 313 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 313 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 314 "src/analyzer/Module.pv"
        success = Impl__prefill_types(impl_info) && success;

        #line 316 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 317 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 317 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 318 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 318 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 319 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 321 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 322 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 324 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 324 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 325 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 325 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, impl_info->trait_->name->value, (struct tuple_ref_Trait_ref_Type) { ._0 = impl_info->trait_, ._1 = &impl_info->trait_type });
                }
                #line 326 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 327 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 328 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 330 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 330 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 331 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 331 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 332 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 334 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 334 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 335 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 336 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 336 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 337 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 339 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 339 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 340 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 341 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 341 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 342 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 344 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 344 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 345 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 346 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 346 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 347 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 349 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 350 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info));
                #line 351 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 353 "src/analyzer/Module.pv"
            default: {
                #line 353 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->token, "TODO: Currently unimplemented");
            } break;
        }
    } }

    #line 357 "src/analyzer/Module.pv"
    return success;
}

#line 360 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 361 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 361 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 361 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 362 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 366 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 366 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 366 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 367 "src/analyzer/Module.pv"
        Enum__fill_variants(enum_info);
    } }

    #line 370 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 370 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 370 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 371 "src/analyzer/Module.pv"
        Struct__fill_types(struct_info);
    } }

    #line 374 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 374 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 374 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 375 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
        #line 376 "src/analyzer/Module.pv"
        Trait__fill_types(trait_info, parent);

        #line 379 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 379 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 379 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 380 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &trait_info->generics);
        } }
    } }

    #line 384 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 384 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 384 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 385 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 385 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 385 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 386 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 390 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 390 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 390 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 391 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 392 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 394 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 394 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 394 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 395 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 399 "src/analyzer/Module.pv"
    return true;
}

#line 402 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 403 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 405 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 405 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 405 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 406 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 407 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 410 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 410 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 410 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 411 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 414 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 414 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 414 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 415 "src/analyzer/Module.pv"
        Trait__parse_functions(trait_info);
    } }

    #line 418 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 418 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 418 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 419 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 422 "src/analyzer/Module.pv"
    return true;
}

#line 425 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name) {
    #line 426 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 427 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 427 "src/analyzer/Module.pv"
        return type;
    }

    #line 429 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name);
    #line 430 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 430 "src/analyzer/Module.pv"
        return type;
    }

    #line 432 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 432 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 432 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 433 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name);
        #line 434 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 434 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 437 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name);
    #line 438 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 438 "src/analyzer/Module.pv"
        return type;
    }

    #line 440 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 440 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 440 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 441 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 442 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 442 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 445 "src/analyzer/Module.pv"
    return 0;
}

#line 448 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name) {
    #line 449 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name);
    #line 450 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 450 "src/analyzer/Module.pv"
        return type;
    }

    #line 452 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name);
    #line 453 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 453 "src/analyzer/Module.pv"
        return type;
    }

    #line 455 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 455 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 455 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 456 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name);
        #line 457 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 457 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 460 "src/analyzer/Module.pv"
    return 0;
}

#line 463 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 464 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 465 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 465 "src/analyzer/Module.pv"
        return type;
    }

    #line 467 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 468 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 468 "src/analyzer/Module.pv"
        return type;
    }

    #line 470 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 470 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 470 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 471 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 472 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 472 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 475 "src/analyzer/Module.pv"
    return 0;
}

#line 478 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 479 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 479 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 479 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 480 "src/analyzer/Module.pv"
        struct Type* type = HashMap_str_Type__find(&include->values, &name);
        #line 481 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 481 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 484 "src/analyzer/Module.pv"
    return 0;
}

#line 487 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 488 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name);
    #line 489 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 492 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 493 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 494 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &name);
}
