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
#include <std/Allocator.h>
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
#include <analyzer/Include.h>
#include <analyzer/Context.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>
#include <stdbool.h>
#include <analyzer/Tokenizer.h>
#include <analyzer/TokenType.h>
#include <std/ArrayIter_ref_NamespacePath.h>
#include <std/ArrayIter_ref_ref_Token.h>
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
#include <std/ArrayIter_ref_ref_Namespace.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/ArrayIter_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/StructC.h>
#include <analyzer/EnumC.h>
#include <analyzer/TypedefC.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/ArrayIter_ref_ref_Impl.h>
#include <analyzer/types/FunctionParent.h>
#include <std/ArrayIter_ref_TypeImpl.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <std/Array_Type.h>

#include <analyzer/Module.h>

#line 26 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path) {
    #line 27 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 28 "src/analyzer/Module.pv"
    struct Analysis* analysis = namespace->root->analysis;
    #line 29 "src/analyzer/Module.pv"
    struct Module* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Module));

    #line 31 "src/analyzer/Module.pv"
    *self = (struct Module) {
        .root = namespace->root,
        .namespace = namespace,
        .path = path,
        .use_namespaces = Array_NamespacePath__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .used_namespaces = Array_ref_Namespace__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_str_Enum__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_str_Struct__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_Impl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Function__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impls = Array_TypeImpl__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes = HashMap_str_ref_Include__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 47 "src/analyzer/Module.pv"
    self->context = Context__new(allocator, (struct str){ .ptr = "", .length = strlen("") }, path, 0, analysis, self);

    #line 49 "src/analyzer/Module.pv"
    return self;
}

#line 52 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self) {
    #line 53 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;
    #line 54 "src/analyzer/Module.pv"
    struct Array_NamespacePath* use_namespaces = &self->use_namespaces;
    #line 55 "src/analyzer/Module.pv"
    struct HashMap_str_Enum* enums = &self->enums;
    #line 56 "src/analyzer/Module.pv"
    struct HashMap_str_Struct* structs = &self->structs;
    #line 57 "src/analyzer/Module.pv"
    struct HashMap_str_Trait* traits = &self->traits;
    #line 58 "src/analyzer/Module.pv"
    struct Array_Impl* impls = &self->impls;
    #line 59 "src/analyzer/Module.pv"
    struct HashMap_str_Function* functions = &self->functions;
    #line 60 "src/analyzer/Module.pv"
    struct Context* context = &self->context;

    #line 62 "src/analyzer/Module.pv"
    self->tokens = Tokenizer__tokenize(allocator, self->path.ptr);
    #line 63 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 64 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;

    #line 66 "src/analyzer/Module.pv"
    bool result = true;

    #line 68 "src/analyzer/Module.pv"
    while ((context->pos < context->length) && result) {
        #line 69 "src/analyzer/Module.pv"
        struct Token* token = &context->tokens[context->pos];

        #line 71 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "ns")) {
            #line 72 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "ns")) {
                #line 72 "src/analyzer/Module.pv"
                return false;
            }
            #line 73 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 74 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 76 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 77 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 79 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 80 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 83 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 85 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 86 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 88 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 89 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "mod")) {
            #line 93 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "mod")) {
                #line 93 "src/analyzer/Module.pv"
                return false;
            }
            #line 94 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 95 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 97 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 98 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 100 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 101 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 104 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 106 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 107 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 109 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 110 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "use")) {
            #line 114 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "use")) {
                #line 114 "src/analyzer/Module.pv"
                return false;
            }

            #line 116 "src/analyzer/Module.pv"
            struct NamespacePath path = NamespacePath__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 117 "src/analyzer/Module.pv"
            if (!NamespacePath__parse(&path, context)) {
                #line 117 "src/analyzer/Module.pv"
                return false;
            }

            #line 119 "src/analyzer/Module.pv"
            Array_NamespacePath__append(use_namespaces, path);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#cpp")) {
            #line 121 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#cpp")) {
                #line 121 "src/analyzer/Module.pv"
                return false;
            }
            #line 122 "src/analyzer/Module.pv"
            self->mode_cpp = true;
            #line 123 "src/analyzer/Module.pv"
            self->root->mode_cpp = true;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#include")) {
            #line 125 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#include")) {
                #line 125 "src/analyzer/Module.pv"
                return false;
            }

            #line 127 "src/analyzer/Module.pv"
            struct Token* path = Context__expect(context, TOKEN_TYPE__STRING);
            #line 128 "src/analyzer/Module.pv"
            if (path == 0) {
                #line 128 "src/analyzer/Module.pv"
                return false;
            }

            #line 130 "src/analyzer/Module.pv"
            struct HashMap_str_ref_Include* includes = &self->root->includes_c;
            #line 131 "src/analyzer/Module.pv"
            if (self->mode_cpp) {
                #line 131 "src/analyzer/Module.pv"
                includes = &self->root->includes_cpp;
            }

            #line 133 "src/analyzer/Module.pv"
            struct Include** include_ptr = HashMap_str_ref_Include__find(includes, &path->value);
            #line 134 "src/analyzer/Module.pv"
            struct Include* include = 0;
            #line 135 "src/analyzer/Module.pv"
            if (include_ptr != 0) {
                #line 135 "src/analyzer/Module.pv"
                include = *include_ptr;
            }

            #line 137 "src/analyzer/Module.pv"
            if (include == 0) {
                #line 138 "src/analyzer/Module.pv"
                include = Include__new(self->root, path->value, self->mode_cpp);
                #line 139 "src/analyzer/Module.pv"
                Include__process(include);
                #line 140 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(includes, path->value, include);
            }

            #line 143 "src/analyzer/Module.pv"
            if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                #line 144 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(&self->includes, path->value, include);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 147 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 149 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 150 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 152 "src/analyzer/Module.pv"
                HashMap_str_Enum__insert(enums, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 155 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 157 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 158 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 160 "src/analyzer/Module.pv"
                HashMap_str_Struct__insert(structs, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 163 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 165 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 166 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 168 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 171 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 173 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 174 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 176 "src/analyzer/Module.pv"
                HashMap_str_Trait__insert(traits, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 179 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 181 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 182 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 184 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 187 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 189 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 190 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 194 "src/analyzer/Module.pv"
    return result;
}

#line 197 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 198 "src/analyzer/Module.pv"
    bool success = true;

    #line 200 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 200 "src/analyzer/Module.pv"
    while (ArrayIter_ref_NamespacePath__next(&__iter)) {
        #line 200 "src/analyzer/Module.pv"
        struct NamespacePath* path = ArrayIter_ref_NamespacePath__value(&__iter);

        #line 201 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 204 "src/analyzer/Module.pv"
    return success;
}

#line 207 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 208 "src/analyzer/Module.pv"
    struct ArrayIter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 209 "src/analyzer/Module.pv"
    ArrayIter_ref_ref_Token__next(&parts_iter);
    #line 210 "src/analyzer/Module.pv"
    struct Token* first_part = *ArrayIter_ref_ref_Token__value(&parts_iter);
    #line 211 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 213 "src/analyzer/Module.pv"
    if (path->root) {
        #line 214 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 216 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 219 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 220 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 221 "src/analyzer/Module.pv"
        return false;
    }

    #line 224 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_ref_Token __iter = parts_iter;
    #line 224 "src/analyzer/Module.pv"
    while (ArrayIter_ref_ref_Token__next(&__iter)) {
        #line 224 "src/analyzer/Module.pv"
        struct Token* part = *ArrayIter_ref_ref_Token__value(&__iter);

        #line 225 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 226 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 227 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 228 "src/analyzer/Module.pv"
            return false;
        }

        #line 231 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 234 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 236 "src/analyzer/Module.pv"
    return true;
}

#line 239 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 240 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 241 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 242 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap) {});
    #line 243 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr(&(struct Type) { .type = TYPE__SELF }, allocator);

    #line 245 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 245 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 245 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 246 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_info->name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 249 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 249 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 249 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 250 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, enum_info->name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} });
    } }

    #line 253 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 253 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 253 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 254 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, GenericMap__from_generics(allocator, &struct_info->generics));
        #line 255 "src/analyzer/Module.pv"
        generics->self_type = blank_generics->self_type;

        #line 257 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, struct_info->name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} });
    } }

    #line 260 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 260 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 260 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 261 "src/analyzer/Module.pv"
        HashMap_str_ref_Trait__insert(&namespace->traits, trait_info->name->value, trait_info);
    } }

    #line 264 "src/analyzer/Module.pv"
    return true;
}

#line 267 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 268 "src/analyzer/Module.pv"
    bool success = true;

    #line 270 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 270 "src/analyzer/Module.pv"
    while (ArrayIter_ref_ref_Namespace__next(&__iter)) {
        #line 270 "src/analyzer/Module.pv"
        struct Namespace* namespace = *ArrayIter_ref_ref_Namespace__value(&__iter);

        #line 271 "src/analyzer/Module.pv"
        if (str__eq(namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 272 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 273 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") } });

            #line 275 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") } });

            #line 277 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 278 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 279 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 281 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 282 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 284 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") });
            #line 285 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 286 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 289 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 292 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 293 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 297 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 297 "src/analyzer/Module.pv"
    while (ArrayIter_ref_Impl__next(&__iter)) {
        #line 297 "src/analyzer/Module.pv"
        struct Impl* impl_info = ArrayIter_ref_Impl__value(&__iter);

        #line 298 "src/analyzer/Module.pv"
        success = Impl__prefill_types(impl_info) && success;
    } }

    #line 301 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 301 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 301 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 302 "src/analyzer/Module.pv"
        success = Enum__prefill_types(enum_info) && success;
    } }

    #line 305 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 305 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 305 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 306 "src/analyzer/Module.pv"
        success = Struct__prefill_types(struct_info) && success;
    } }

    #line 309 "src/analyzer/Module.pv"
    return success;
}

#line 312 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 313 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 315 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 315 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 315 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 316 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 319 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 319 "src/analyzer/Module.pv"
    while (ArrayIter_ref_Impl__next(&__iter)) {
        #line 319 "src/analyzer/Module.pv"
        struct Impl* impl_info = ArrayIter_ref_Impl__value(&__iter);

        #line 320 "src/analyzer/Module.pv"
        if (impl_info->trait_name != 0) {
            #line 321 "src/analyzer/Module.pv"
            impl_info->trait_ = Module__find_trait(self, impl_info->trait_name->value);
            #line 322 "src/analyzer/Module.pv"
            if (impl_info->trait_ == 0) {
                #line 323 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->trait_name, "Could not find trait");
                #line 324 "src/analyzer/Module.pv"
                return false;
            }
        }

        #line 328 "src/analyzer/Module.pv"
        if (impl_info->type == 0) {
            #line 328 "src/analyzer/Module.pv"
            impl_info->type = Module__find_type(self, impl_info->name->value);
        }
        #line 329 "src/analyzer/Module.pv"
        if (impl_info->type == 0) {
            #line 330 "src/analyzer/Module.pv"
            Context__error_token(&self->context, impl_info->name, "Could not find type");
            #line 331 "src/analyzer/Module.pv"
            return false;
        }

        #line 334 "src/analyzer/Module.pv"
        switch (impl_info->type->type) {
            #line 335 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 335 "src/analyzer/Module.pv"
                struct Enum* enum_parent = impl_info->type->enum_value._0;
                #line 336 "src/analyzer/Module.pv"
                impl_info->type_self = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_parent, ._1 = ArenaAllocator__store_GenericMap(allocator, GenericMap__from_generics(allocator, &impl_info->struct_generics))} };

                #line 338 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 338 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_parent->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 339 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&enum_parent->impls, impl_info);
            } break;
            #line 341 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 341 "src/analyzer/Module.pv"
                struct Struct* struct_parent = impl_info->type->struct_value._0;
                #line 342 "src/analyzer/Module.pv"
                impl_info->type_self = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_parent, ._1 = ArenaAllocator__store_GenericMap(allocator, GenericMap__from_generics(allocator, &impl_info->struct_generics))} };

                #line 344 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 344 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&struct_parent->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 345 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&struct_parent->impls, impl_info);
            } break;
            #line 347 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 347 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type->primitive_value;
                #line 348 "src/analyzer/Module.pv"
                impl_info->type_self = *impl_info->type;

                #line 350 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 350 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 351 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 353 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 353 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type->structc_value;
                #line 354 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 355 "src/analyzer/Module.pv"
                impl_info->type_self = *impl_info->type;

                #line 357 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 357 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 358 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 360 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 360 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type->enumc_value;
                #line 361 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 362 "src/analyzer/Module.pv"
                impl_info->type_self = *impl_info->type;

                #line 364 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 364 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 365 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 367 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 367 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type->typedefc_value;
                #line 368 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 369 "src/analyzer/Module.pv"
                impl_info->type_self = *impl_info->type;

                #line 371 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 371 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 372 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 374 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 375 "src/analyzer/Module.pv"
                impl_info->type_self = *impl_info->type;
                #line 376 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, *impl_info->type, impl_info));
                #line 377 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 379 "src/analyzer/Module.pv"
            default: {
                #line 379 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->name, "TODO: Currently unimplemented");
            } break;
        }
    } }

    #line 383 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 383 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 383 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 384 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap) {});
        #line 385 "src/analyzer/Module.pv"
        struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
        #line 386 "src/analyzer/Module.pv"
        generics->self_type = self_type;
        #line 387 "src/analyzer/Module.pv"
        *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generics} };
        #line 388 "src/analyzer/Module.pv"
        enum_info->context->type_self = self_type;

        #line 390 "src/analyzer/Module.pv"
        Enum__fill_variants(enum_info);

        #line 392 "src/analyzer/Module.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
        #line 392 "src/analyzer/Module.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 392 "src/analyzer/Module.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 392 "src/analyzer/Module.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 393 "src/analyzer/Module.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 394 "src/analyzer/Module.pv"
            Impl__fill_types(impl_info, parent);

            #line 396 "src/analyzer/Module.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 396 "src/analyzer/Module.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 396 "src/analyzer/Module.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 397 "src/analyzer/Module.pv"
                Function__fill_types(func_info, &impl_info->impl_generics);
            } }
        } }
    } }

    #line 402 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 402 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 402 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 403 "src/analyzer/Module.pv"
        Struct__fill_types(struct_info);

        #line 405 "src/analyzer/Module.pv"
        { struct IterEnumerate_ref_ref_Impl __iter = ArrayIter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
        #line 405 "src/analyzer/Module.pv"
        while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
            #line 405 "src/analyzer/Module.pv"
            uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
            #line 405 "src/analyzer/Module.pv"
            struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

            #line 406 "src/analyzer/Module.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
            #line 407 "src/analyzer/Module.pv"
            Impl__fill_types(impl_info, parent);

            #line 409 "src/analyzer/Module.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 409 "src/analyzer/Module.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 409 "src/analyzer/Module.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 410 "src/analyzer/Module.pv"
                Function__fill_types(func_info, &impl_info->impl_generics);
            } }
        } }
    } }

    #line 415 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 415 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 415 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 416 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
        #line 417 "src/analyzer/Module.pv"
        Trait__fill_types(trait_info, parent);

        #line 419 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 419 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 419 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 420 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &trait_info->generics);
        } }
    } }

    #line 424 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 424 "src/analyzer/Module.pv"
    while (ArrayIter_ref_TypeImpl__next(&__iter)) {
        #line 424 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = ArrayIter_ref_TypeImpl__value(&__iter);

        #line 425 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 426 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 428 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 428 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 428 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 429 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->impl_generics);
        } }
    } }

    #line 433 "src/analyzer/Module.pv"
    return true;
}

#line 436 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 437 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 439 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 439 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 439 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 440 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 441 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 444 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 444 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 444 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 445 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap) {});
        #line 446 "src/analyzer/Module.pv"
        struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
        #line 447 "src/analyzer/Module.pv"
        generics->self_type = self_type;
        #line 448 "src/analyzer/Module.pv"
        *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generics} };
        #line 449 "src/analyzer/Module.pv"
        enum_info->context->type_self = self_type;

        #line 451 "src/analyzer/Module.pv"
        { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
        #line 451 "src/analyzer/Module.pv"
        while (ArrayIter_ref_ref_Impl__next(&__iter)) {
            #line 451 "src/analyzer/Module.pv"
            struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

            #line 452 "src/analyzer/Module.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 456 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 456 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 456 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 457 "src/analyzer/Module.pv"
        { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
        #line 457 "src/analyzer/Module.pv"
        while (ArrayIter_ref_ref_Impl__next(&__iter)) {
            #line 457 "src/analyzer/Module.pv"
            struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

            #line 458 "src/analyzer/Module.pv"
            Impl__parse_functions(impl_info);
        } }
    } }

    #line 462 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 462 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 462 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 463 "src/analyzer/Module.pv"
        Trait__parse_functions(trait_info);
    } }

    #line 466 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 466 "src/analyzer/Module.pv"
    while (ArrayIter_ref_TypeImpl__next(&__iter)) {
        #line 466 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = ArrayIter_ref_TypeImpl__value(&__iter);

        #line 467 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 470 "src/analyzer/Module.pv"
    return true;
}

#line 473 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name) {
    #line 474 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 475 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 475 "src/analyzer/Module.pv"
        return type;
    }

    #line 477 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name);
    #line 478 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 478 "src/analyzer/Module.pv"
        return type;
    }

    #line 480 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 480 "src/analyzer/Module.pv"
    while (ArrayIter_ref_ref_Namespace__next(&__iter)) {
        #line 480 "src/analyzer/Module.pv"
        struct Namespace* namespace = *ArrayIter_ref_ref_Namespace__value(&__iter);

        #line 481 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name);
        #line 482 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 482 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 485 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name);
    #line 486 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 486 "src/analyzer/Module.pv"
        return type;
    }

    #line 488 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 488 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 488 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 489 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 490 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 490 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 493 "src/analyzer/Module.pv"
    return 0;
}

#line 496 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name) {
    #line 497 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name);
    #line 498 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 498 "src/analyzer/Module.pv"
        return type;
    }

    #line 500 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name);
    #line 501 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 501 "src/analyzer/Module.pv"
        return type;
    }

    #line 503 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 503 "src/analyzer/Module.pv"
    while (ArrayIter_ref_ref_Namespace__next(&__iter)) {
        #line 503 "src/analyzer/Module.pv"
        struct Namespace* namespace = *ArrayIter_ref_ref_Namespace__value(&__iter);

        #line 504 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name);
        #line 505 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 505 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 508 "src/analyzer/Module.pv"
    return 0;
}

#line 511 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 512 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 513 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 513 "src/analyzer/Module.pv"
        return type;
    }

    #line 515 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 516 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 516 "src/analyzer/Module.pv"
        return type;
    }

    #line 518 "src/analyzer/Module.pv"
    { struct ArrayIter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 518 "src/analyzer/Module.pv"
    while (ArrayIter_ref_ref_Namespace__next(&__iter)) {
        #line 518 "src/analyzer/Module.pv"
        struct Namespace* namespace = *ArrayIter_ref_ref_Namespace__value(&__iter);

        #line 519 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 520 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 520 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 523 "src/analyzer/Module.pv"
    return 0;
}

#line 526 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 527 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 527 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 527 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 528 "src/analyzer/Module.pv"
        struct Type* type = HashMap_str_Type__find(&include->values, &name);
        #line 529 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 529 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 532 "src/analyzer/Module.pv"
    return 0;
}

#line 535 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 536 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name);
    #line 537 "src/analyzer/Module.pv"
    return Module__make_type_usage(self, type, usage_types);
}

#line 540 "src/analyzer/Module.pv"
struct Type* Module__make_type_usage(struct Module* self, struct Type* type, struct Array_Type* usage_types) {
    #line 541 "src/analyzer/Module.pv"
    if (type == 0) {
        #line 541 "src/analyzer/Module.pv"
        return 0;
    }
    #line 542 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 544 "src/analyzer/Module.pv"
    switch (type->type) {
        #line 545 "src/analyzer/Module.pv"
        case TYPE__ENUM: {
            #line 545 "src/analyzer/Module.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 546 "src/analyzer/Module.pv"
            struct GenericMap generics = GenericMap__new(allocator, &enum_info->generics, usage_types);
            #line 547 "src/analyzer/Module.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 548 "src/analyzer/Module.pv"
            generics.self_type = self_type;
            #line 549 "src/analyzer/Module.pv"
            *self_type = (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = ArenaAllocator__store_GenericMap(allocator, generics)} };
            #line 550 "src/analyzer/Module.pv"
            return self_type;
        } break;
        #line 552 "src/analyzer/Module.pv"
        case TYPE__STRUCT: {
            #line 552 "src/analyzer/Module.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 553 "src/analyzer/Module.pv"
            struct GenericMap generics = GenericMap__new(allocator, &struct_info->generics, usage_types);
            #line 554 "src/analyzer/Module.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 555 "src/analyzer/Module.pv"
            generics.self_type = self_type;
            #line 556 "src/analyzer/Module.pv"
            *self_type = (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = ArenaAllocator__store_GenericMap(allocator, generics)} };
            #line 557 "src/analyzer/Module.pv"
            return self_type;
        } break;
        #line 559 "src/analyzer/Module.pv"
        case TYPE__TRAIT: {
            #line 559 "src/analyzer/Module.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 560 "src/analyzer/Module.pv"
            struct GenericMap generics = GenericMap__new(allocator, &trait_info->generics, usage_types);
            #line 561 "src/analyzer/Module.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 562 "src/analyzer/Module.pv"
            generics.self_type = self_type;
            #line 563 "src/analyzer/Module.pv"
            *self_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = ArenaAllocator__store_GenericMap(allocator, generics)} };
            #line 564 "src/analyzer/Module.pv"
            return self_type;
        } break;
        #line 566 "src/analyzer/Module.pv"
        case TYPE__FUNCTION: {
            #line 566 "src/analyzer/Module.pv"
            struct Function* function_info = type->function_value._0;
            #line 567 "src/analyzer/Module.pv"
            struct GenericMap generics = GenericMap__new(allocator, &function_info->generics, usage_types);
            #line 568 "src/analyzer/Module.pv"
            struct Type* self_type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
            #line 569 "src/analyzer/Module.pv"
            generics.self_type = self_type;
            #line 570 "src/analyzer/Module.pv"
            *self_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = function_info, ._1 = ArenaAllocator__store_GenericMap(allocator, generics)} };
            #line 571 "src/analyzer/Module.pv"
            return self_type;
        } break;
        #line 573 "src/analyzer/Module.pv"
        default: {
            #line 573 "src/analyzer/Module.pv"
            return type;
        } break;
    }
}

#line 577 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, char const* name) {
    #line 578 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 579 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &(struct str){ .ptr = name, .length = strlen(name) });
}
