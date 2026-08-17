#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/Namespace.h>
#include <analyzer/Analysis.h>
#include <std/trait_Allocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <std/Array_Scope.h>
#include <std/HashMap_str_str.h>
#include <analyzer/Tokenizer.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <analyzer/NamespacePath.h>
#include <analyzer/c/Include.h>
#include <analyzer/types/Enum.h>
#include <std/Array_ref_Enum.h>
#include <analyzer/types/Struct.h>
#include <std/Array_ref_Struct.h>
#include <analyzer/Impl.h>
#include <usize.h>
#include <analyzer/types/Trait.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Function.h>
#include <std/String.h>
#include <char.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/TestInfo.h>
#include <analyzer/types/Global.h>
#include <std/Iter_ref_NamespacePath.h>
#include <std/Iter_ref_ref_Token.h>
#include <std/Array_ref_Token.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/types/GenericMap.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_usize.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Array_ref_Enum.h>
#include <tuple_str_Array_ref_Enum.h>
#include <std/Iter_ref_ref_Enum.h>
#include <std/HashMapIter_str_Array_ref_Struct.h>
#include <tuple_str_Array_ref_Struct.h>
#include <std/Iter_ref_ref_Struct.h>
#include <analyzer/types/Generics.h>
#include <std/HashMapIter_str_Array_ref_Trait.h>
#include <tuple_str_Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
#include <std/HashMapIter_str_ref_Global.h>
#include <tuple_str_ref_Global.h>
#include <std/Iter_ref_ref_Namespace.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Impl.h>
#include <std/HashMap_str_ref_Trait.h>
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
#include <std/Iter_ref_TestInfo.h>
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMap_str_i64.h>
#include <analyzer/Module.h>

#include <analyzer/Module.h>

#line 35 "src/analyzer/Module.pv"
struct Module* Module__new(struct Namespace* namespace, struct str path) {
    #line 36 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 37 "src/analyzer/Module.pv"
    struct Analysis* analysis = namespace->root->analysis;
    #line 38 "src/analyzer/Module.pv"
    struct Module* self = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Module));

    #line 40 "src/analyzer/Module.pv"
    *self = (struct Module) {
        .root = namespace->root,
        .namespace = namespace,
        .path = path,
        .use_namespaces = Array_NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .used_namespaces = Array_ref_Namespace__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_str_Array_ref_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_str_Array_ref_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impls = Array_TypeImpl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes = HashMap_str_ref_Include__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .globals = HashMap_str_ref_Global__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .global_types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .tests = Array_TestInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .context = (struct Context) { .allocator = allocator, .base_path = (struct str) { .ptr = 0, .length = 0 }, .path = (struct str) { .ptr = 0, .length = 0 }, .pos = 0, .tokens = 0, .length = 0, .offset = 0, .analysis = analysis, .type_self = 0, .type_char = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 }, .pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }, .types = (struct HashMap_str_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .scopes = (struct Array_Scope) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .module = (struct Module*)(0), .root = (struct Root*)(0), .function = 0 },
        .tokens = (struct Array_Token) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 },
        .mode_cpp = false,
    };

    #line 62 "src/analyzer/Module.pv"
    self->context = Context__new(allocator, (struct str){ .ptr = "", .length = strlen("") }, path, 0, analysis, self);

    #line 64 "src/analyzer/Module.pv"
    return self;
}

#line 67 "src/analyzer/Module.pv"
bool Module__parse(struct Module* self) {
    #line 68 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;
    #line 69 "src/analyzer/Module.pv"
    struct Array_NamespacePath* use_namespaces = &self->use_namespaces;
    #line 70 "src/analyzer/Module.pv"
    struct HashMap_str_Array_ref_Enum* enums = &self->enums;
    #line 71 "src/analyzer/Module.pv"
    struct HashMap_str_Array_ref_Struct* structs = &self->structs;
    #line 72 "src/analyzer/Module.pv"
    struct HashMap_str_Array_ref_Trait* traits = &self->traits;
    #line 73 "src/analyzer/Module.pv"
    struct Array_Impl* impls = &self->impls;
    #line 74 "src/analyzer/Module.pv"
    struct HashMap_str_Function* functions = &self->functions;
    #line 75 "src/analyzer/Module.pv"
    struct Context* context = &self->context;

    #line 77 "src/analyzer/Module.pv"
    struct str* file_override = HashMap_str_str__find(&self->context.analysis->file_overrides, &self->path);
    #line 78 "src/analyzer/Module.pv"
    if (file_override == 0) {
        #line 79 "src/analyzer/Module.pv"
        self->tokens = Tokenizer__tokenize(allocator, self->path.ptr);
    } else {
        #line 81 "src/analyzer/Module.pv"
        self->tokens = Tokenizer__tokenize_data(allocator, *file_override);
    }
    #line 83 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 84 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;

    #line 86 "src/analyzer/Module.pv"
    bool result = true;

    #line 88 "src/analyzer/Module.pv"
    while (context->pos < context->length && result) {
        #line 89 "src/analyzer/Module.pv"
        struct Token* token = &context->tokens[context->pos];

        #line 91 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "ns")) {
            #line 92 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "ns")) {
                #line 92 "src/analyzer/Module.pv"
                return false;
            }
            #line 93 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 94 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 96 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 97 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 99 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 100 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 103 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 105 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 106 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 108 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 109 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "mod")) {
            #line 113 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "mod")) {
                #line 113 "src/analyzer/Module.pv"
                return false;
            }
            #line 114 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 115 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 117 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 118 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 120 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 121 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 124 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 126 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 127 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 129 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 130 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "use")) {
            #line 134 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "use")) {
                #line 134 "src/analyzer/Module.pv"
                return false;
            }

            #line 136 "src/analyzer/Module.pv"
            struct NamespacePath path = NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 137 "src/analyzer/Module.pv"
            if (!NamespacePath__parse(&path, context)) {
                #line 137 "src/analyzer/Module.pv"
                return false;
            }

            #line 139 "src/analyzer/Module.pv"
            Array_NamespacePath__append(use_namespaces, path);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#cpp")) {
            #line 141 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#cpp")) {
                #line 141 "src/analyzer/Module.pv"
                return false;
            }
            #line 142 "src/analyzer/Module.pv"
            self->mode_cpp = true;
            #line 143 "src/analyzer/Module.pv"
            self->root->mode_cpp = true;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#include")) {
            #line 145 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#include")) {
                #line 145 "src/analyzer/Module.pv"
                return false;
            }

            #line 147 "src/analyzer/Module.pv"
            struct Token* path = Context__expect(context, TOKEN_TYPE__STRING);
            #line 148 "src/analyzer/Module.pv"
            if (path == 0) {
                #line 148 "src/analyzer/Module.pv"
                return false;
            }

            #line 150 "src/analyzer/Module.pv"
            struct HashMap_str_ref_Include* includes = &self->root->includes_c;
            #line 151 "src/analyzer/Module.pv"
            if (self->mode_cpp) {
                #line 151 "src/analyzer/Module.pv"
                includes = &self->root->includes_cpp;
            }

            #line 153 "src/analyzer/Module.pv"
            struct Include** include_ptr = HashMap_str_ref_Include__find(includes, &path->value);
            #line 154 "src/analyzer/Module.pv"
            struct Include* include = 0;
            #line 155 "src/analyzer/Module.pv"
            if (include_ptr != 0) {
                #line 155 "src/analyzer/Module.pv"
                include = *include_ptr;
            }

            #line 157 "src/analyzer/Module.pv"
            if (include == 0) {
                #line 158 "src/analyzer/Module.pv"
                include = Include__new(self->root, path->value, self->mode_cpp);
                #line 159 "src/analyzer/Module.pv"
                if (include == 0 || !Include__process(include)) {
                    #line 160 "src/analyzer/Module.pv"
                    struct str error = path->value;

                    #line 162 "src/analyzer/Module.pv"
                    if (include != 0 && include->error.length > 0) {
                        #line 163 "src/analyzer/Module.pv"
                        Context__error_token(context, path, include->error.ptr);
                    } else {
                        #line 165 "src/analyzer/Module.pv"
                        Context__error_token_value(context, path, "Failed to process include", error);
                    }

                    #line 168 "src/analyzer/Module.pv"
                    include = 0;
                }
            }

            #line 172 "src/analyzer/Module.pv"
            if (include != 0) {
                #line 173 "src/analyzer/Module.pv"
                if (include_ptr == 0) {
                    #line 174 "src/analyzer/Module.pv"
                    HashMap_str_ref_Include__insert(includes, path->value, include);
                }

                #line 177 "src/analyzer/Module.pv"
                if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                    #line 178 "src/analyzer/Module.pv"
                    HashMap_str_ref_Include__insert(&self->includes, path->value, include);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 182 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 184 "src/analyzer/Module.pv"
            struct Token* enum_name = node.name;
            #line 185 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 186 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 188 "src/analyzer/Module.pv"
                struct Enum* enum_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Enum));
                #line 189 "src/analyzer/Module.pv"
                *enum_ptr = node;
                #line 190 "src/analyzer/Module.pv"
                struct Array_ref_Enum* existing = HashMap_str_Array_ref_Enum__find(enums, &enum_name->value);
                #line 191 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 192 "src/analyzer/Module.pv"
                    struct Array_ref_Enum arr = Array_ref_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 193 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(&arr, enum_ptr);
                    #line 194 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Enum__insert(enums, enum_name->value, arr);
                } else {
                    #line 196 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(existing, enum_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 200 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 202 "src/analyzer/Module.pv"
            struct Token* struct_name = node.name;
            #line 203 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 204 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 206 "src/analyzer/Module.pv"
                struct Struct* struct_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Struct));
                #line 207 "src/analyzer/Module.pv"
                *struct_ptr = node;
                #line 208 "src/analyzer/Module.pv"
                struct Array_ref_Struct* existing = HashMap_str_Array_ref_Struct__find(structs, &struct_name->value);
                #line 209 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 210 "src/analyzer/Module.pv"
                    struct Array_ref_Struct arr = Array_ref_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 211 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(&arr, struct_ptr);
                    #line 212 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Struct__insert(structs, struct_name->value, arr);
                } else {
                    #line 214 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(existing, struct_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 218 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 220 "src/analyzer/Module.pv"
            if (usize__Eq_usize__eq(node.token_start, node.token_end)) {
                #line 221 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 223 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 226 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 228 "src/analyzer/Module.pv"
            struct Token* trait_name = node.name;
            #line 229 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 230 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 232 "src/analyzer/Module.pv"
                struct Trait* trait_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Trait));
                #line 233 "src/analyzer/Module.pv"
                *trait_ptr = node;
                #line 234 "src/analyzer/Module.pv"
                struct Array_ref_Trait* existing = HashMap_str_Array_ref_Trait__find(traits, &trait_name->value);
                #line 235 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 236 "src/analyzer/Module.pv"
                    struct Array_ref_Trait arr = Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 237 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(&arr, trait_ptr);
                    #line 238 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Trait__insert(traits, trait_name->value, arr);
                } else {
                    #line 240 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(existing, trait_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 244 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 246 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 247 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 249 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "test")) {
            #line 252 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "test")) {
                #line 252 "src/analyzer/Module.pv"
                return false;
            }

            #line 254 "src/analyzer/Module.pv"
            struct Token* description = Context__expect(context, TOKEN_TYPE__STRING);
            #line 255 "src/analyzer/Module.pv"
            if (description == 0) {
                #line 255 "src/analyzer/Module.pv"
                return false;
            }

            #line 257 "src/analyzer/Module.pv"
            struct String name_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 260 "src/analyzer/Module.pv"
            struct String ns_prefix = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 261 "src/analyzer/Module.pv"
            struct Namespace* cur_ns = self->namespace;
            #line 262 "src/analyzer/Module.pv"
            while (cur_ns != 0 && cur_ns->parent != 0) {
                #line 263 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, (struct str){ .ptr = "__", .length = strlen("__") });
                #line 264 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, cur_ns->name);
                #line 265 "src/analyzer/Module.pv"
                cur_ns = cur_ns->parent;
            }
            #line 267 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "test_", .length = strlen("test_") });
            #line 268 "src/analyzer/Module.pv"
            String__append_string(&name_str, &ns_prefix);
            #line 271 "src/analyzer/Module.pv"
            struct str mod_path = self->path;
            #line 272 "src/analyzer/Module.pv"
            intptr_t last_sep = -1;
            #line 273 "src/analyzer/Module.pv"
            uintptr_t pi = 0;
            #line 274 "src/analyzer/Module.pv"
            while (pi < mod_path.length) {
                #line 275 "src/analyzer/Module.pv"
                char pch = mod_path.ptr[pi];
                #line 276 "src/analyzer/Module.pv"
                if (char__Eq_char__eq(pch, '/') || char__Eq_char__eq(pch, '\\')) {
                    #line 276 "src/analyzer/Module.pv"
                    last_sep = (intptr_t)(pi);
                }
                #line 277 "src/analyzer/Module.pv"
                pi += 1;
            }
            #line 279 "src/analyzer/Module.pv"
            uintptr_t stem_start = 0;
            #line 280 "src/analyzer/Module.pv"
            if (last_sep >= 0) {
                #line 280 "src/analyzer/Module.pv"
                stem_start = (uintptr_t)(last_sep) + 1;
            }
            #line 281 "src/analyzer/Module.pv"
            uintptr_t stem_end = mod_path.length;
            #line 282 "src/analyzer/Module.pv"
            if (stem_end >= 3 && str__Eq_str__eq(str__slice(mod_path, stem_end - 3, stem_end), (struct str){ .ptr = ".pv", .length = strlen(".pv") })) {
                #line 283 "src/analyzer/Module.pv"
                stem_end = stem_end - 3;
            }
            #line 285 "src/analyzer/Module.pv"
            String__append(&name_str, str__slice(mod_path, stem_start, stem_end));
            #line 286 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "__", .length = strlen("__") });
            #line 289 "src/analyzer/Module.pv"
            struct str desc_raw = str__slice(description->value, 1, description->value.length - 1);
            #line 290 "src/analyzer/Module.pv"
            uintptr_t di = 0;
            #line 291 "src/analyzer/Module.pv"
            while (di < desc_raw.length) {
                #line 292 "src/analyzer/Module.pv"
                char dch = desc_raw.ptr[di];
                #line 293 "src/analyzer/Module.pv"
                if ((dch >= 'a' && dch <= 'z') || (dch >= 'A' && dch <= 'Z') || (dch >= '0' && dch <= '9')) {
                    #line 294 "src/analyzer/Module.pv"
                    String__append(&name_str, str__slice(desc_raw, di, di + 1));
                } else {
                    #line 296 "src/analyzer/Module.pv"
                    String__append(&name_str, (struct str){ .ptr = "_", .length = strlen("_") });
                }
                #line 298 "src/analyzer/Module.pv"
                di += 1;
            }

            #line 301 "src/analyzer/Module.pv"
            struct Token name_token_val = (struct Token) {
                .type = TOKEN_TYPE__IDENTIFIER,
                .value = String__as_str(&name_str),
                .start_line = 0,
                .start_column = 0,
                .end_line = 0,
                .end_column = 0,
            };
            #line 309 "src/analyzer/Module.pv"
            struct Token* name_token = ArenaAllocator__store_Token(allocator, &name_token_val);
            #line 310 "src/analyzer/Module.pv"
            if (name_token == 0) {
                #line 310 "src/analyzer/Module.pv"
                return false;
            }

            #line 312 "src/analyzer/Module.pv"
            if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                #line 313 "src/analyzer/Module.pv"
                Context__error_token(context, description, "Expected { after test description");
                #line 314 "src/analyzer/Module.pv"
                return false;
            }

            #line 317 "src/analyzer/Module.pv"
            struct Function node = Function__new(context);
            #line 318 "src/analyzer/Module.pv"
            node.name = name_token;
            #line 319 "src/analyzer/Module.pv"
            node.type = FUNCTION_TYPE__TEST;
            #line 320 "src/analyzer/Module.pv"
            node.declaration_start = context->pos;
            #line 321 "src/analyzer/Module.pv"
            node.declaration_end = context->pos;
            #line 322 "src/analyzer/Module.pv"
            node.token_start = context->pos;

            #line 324 "src/analyzer/Module.pv"
            if (!Context__skip_brackets(context, "{", "}")) {
                #line 324 "src/analyzer/Module.pv"
                return false;
            }
            #line 325 "src/analyzer/Module.pv"
            node.token_end = context->pos;

            #line 327 "src/analyzer/Module.pv"
            Array_TestInfo__append(&self->tests, (struct TestInfo) { .description = description, .func_name = String__as_str(&name_str) });
            #line 328 "src/analyzer/Module.pv"
            HashMap_str_Function__insert(functions, name_token->value, node);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "const") || Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 330 "src/analyzer/Module.pv"
            bool is_const = Token__eq(token, TOKEN_TYPE__KEYWORD, "const");
            #line 331 "src/analyzer/Module.pv"
            Context__next_token(context);
            #line 332 "src/analyzer/Module.pv"
            struct Token* global_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 333 "src/analyzer/Module.pv"
            if (global_name == 0) {
                #line 333 "src/analyzer/Module.pv"
                return false;
            }

            #line 335 "src/analyzer/Module.pv"
            uintptr_t token_start = context->pos;

            #line 337 "src/analyzer/Module.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 338 "src/analyzer/Module.pv"
                Context__next_token(context);
            }
            #line 340 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 340 "src/analyzer/Module.pv"
                return false;
            }
            #line 341 "src/analyzer/Module.pv"
            uintptr_t token_end = context->pos;

            #line 343 "src/analyzer/Module.pv"
            struct Global* global = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Global));
            #line 344 "src/analyzer/Module.pv"
            *global = (struct Global) {
                .name = global_name,
                .module = self,
                .token_start = token_start,
                .token_end = token_end,
                .is_const = is_const,
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
                .value = 0,
            };
            #line 353 "src/analyzer/Module.pv"
            HashMap_str_ref_Global__insert(&self->globals, global_name->value, global);
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 355 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 357 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 358 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 362 "src/analyzer/Module.pv"
    return result;
}

#line 365 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 366 "src/analyzer/Module.pv"
    bool success = true;

    #line 368 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 368 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 368 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 369 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 372 "src/analyzer/Module.pv"
    return success;
}

#line 375 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 376 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 377 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 378 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 379 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 381 "src/analyzer/Module.pv"
    if (path->root) {
        #line 382 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 384 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 387 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 388 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 389 "src/analyzer/Module.pv"
        return false;
    }

    #line 392 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 392 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 392 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 393 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 394 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 395 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 396 "src/analyzer/Module.pv"
            return false;
        }

        #line 399 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 402 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 404 "src/analyzer/Module.pv"
    return true;
}

#line 407 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 408 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 409 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 410 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 411 "src/analyzer/Module.pv"
    if (blank_generics == 0) {
        #line 411 "src/analyzer/Module.pv"
        return false;
    }
    #line 412 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, allocator);

    #line 414 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 414 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 414 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 415 "src/analyzer/Module.pv"
        struct Token* func_name = func_info->name;
        #line 416 "src/analyzer/Module.pv"
        if (func_name == 0) {
            #line 416 "src/analyzer/Module.pv"
            return false;
        }
        #line 417 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 420 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 420 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 420 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 421 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 421 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 421 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 422 "src/analyzer/Module.pv"
            struct Token* enum_name = enum_info->name;
            #line 423 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 423 "src/analyzer/Module.pv"
                return false;
            }
            #line 424 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, enum_name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} })) {
                #line 425 "src/analyzer/Module.pv"
                Context__error_token(&self->context, enum_name, "Duplicate type with this name and generic arity");
                #line 426 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 431 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 431 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 431 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 432 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 432 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 432 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 433 "src/analyzer/Module.pv"
            struct GenericMap generics_val = GenericMap__from_generics(allocator, &struct_info->generics);
            #line 434 "src/analyzer/Module.pv"
            struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, &generics_val);
            #line 435 "src/analyzer/Module.pv"
            if (generics == 0) {
                #line 435 "src/analyzer/Module.pv"
                return false;
            }
            #line 436 "src/analyzer/Module.pv"
            generics->self_type = blank_generics->self_type;

            #line 438 "src/analyzer/Module.pv"
            struct Token* struct_name = struct_info->name;
            #line 439 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 439 "src/analyzer/Module.pv"
                return false;
            }
            #line 440 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, struct_name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} })) {
                #line 441 "src/analyzer/Module.pv"
                Context__error_token(&self->context, struct_name, "Duplicate type with this name and generic arity");
                #line 442 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 447 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 447 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 447 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 448 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 448 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 448 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 449 "src/analyzer/Module.pv"
            struct Token* trait_name = trait_info->name;
            #line 450 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 450 "src/analyzer/Module.pv"
                return false;
            }
            #line 451 "src/analyzer/Module.pv"
            if (!Namespace__add_trait(namespace, trait_name->value, trait_info)) {
                #line 452 "src/analyzer/Module.pv"
                Context__error_token(&self->context, trait_name, "Duplicate trait with this name and generic arity");
                #line 453 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 458 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 458 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 458 "src/analyzer/Module.pv"
        struct str name = HashMapIter_str_ref_Global__value(&__iter)->_0;
        #line 458 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 459 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&self->global_types, name, (struct Type) { .type = TYPE__GLOBAL, .global_value = global });
    } }

    #line 462 "src/analyzer/Module.pv"
    return true;
}

#line 465 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 466 "src/analyzer/Module.pv"
    bool success = true;

    #line 468 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 468 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 468 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 469 "src/analyzer/Module.pv"
        if (str__Eq_str__eq(namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 470 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 471 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 473 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 475 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 476 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 477 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 479 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 480 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 482 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") }, 0);
            #line 483 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 484 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 487 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }
        }
    } }

    #line 496 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 496 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 496 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 497 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 497 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 497 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 498 "src/analyzer/Module.pv"
            success = Enum__prefill_types(enum_info) && success;
        } }
    } }

    #line 502 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 502 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 502 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 503 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 503 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 503 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 504 "src/analyzer/Module.pv"
            success = Struct__prefill_types(struct_info) && success;
        } }
    } }

    #line 508 "src/analyzer/Module.pv"
    return success;
}

#line 511 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 512 "src/analyzer/Module.pv"
    bool success = true;
    #line 513 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 515 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 515 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 515 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 516 "src/analyzer/Module.pv"
        if (!Impl__prefill_types(impl_info)) {
            #line 517 "src/analyzer/Module.pv"
            success = false;
            #line 518 "src/analyzer/Module.pv"
            continue;
        }

        #line 521 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 522 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 522 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 523 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 524 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 524 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 525 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 527 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = trait_info} };
                #line 528 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 530 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 530 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 531 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 532 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 532 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), (struct tuple_ref_Trait_ref_Type) { ._0 = trait_info, ._1 = &impl_info->trait_type });
                }
                #line 533 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 534 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = trait_info} };
                #line 535 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 537 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 537 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 538 "src/analyzer/Module.pv"
                if (primitive_info == 0) {
                    #line 538 "src/analyzer/Module.pv"
                    return false;
                }
                #line 539 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 540 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 541 "src/analyzer/Module.pv"
                    struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
                    #line 542 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, trait_key, trait_info);
                }
                #line 544 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 546 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 546 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 547 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 548 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 549 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 549 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 550 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 552 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 552 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 553 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 554 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 555 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 555 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 556 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 558 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 558 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 559 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 560 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 561 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 561 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 562 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 564 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 565 "src/analyzer/Module.pv"
                uintptr_t impl_index = Root__add_type_impl(self->root, impl_info->type, impl_info);
                #line 566 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info, impl_index));
                #line 567 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 569 "src/analyzer/Module.pv"
            default: {
                #line 570 "src/analyzer/Module.pv"
                uintptr_t impl_index = Root__add_type_impl(self->root, impl_info->type, impl_info);
                #line 571 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info, impl_index));
            } break;
        }
    } }

    #line 576 "src/analyzer/Module.pv"
    return success;
}

#line 579 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 580 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 580 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 580 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 581 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 585 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 585 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 585 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 586 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 586 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 586 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 587 "src/analyzer/Module.pv"
            Enum__fill_variants(enum_info);
        } }
    } }

    #line 591 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 591 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 591 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 592 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 592 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 592 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 593 "src/analyzer/Module.pv"
            Struct__fill_types(struct_info);
        } }
    } }

    #line 597 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 597 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 597 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 598 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 598 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 598 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 599 "src/analyzer/Module.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
            #line 600 "src/analyzer/Module.pv"
            Trait__fill_types(trait_info, parent);

            #line 603 "src/analyzer/Module.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 603 "src/analyzer/Module.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 603 "src/analyzer/Module.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 604 "src/analyzer/Module.pv"
                Function__fill_types(func_info, &trait_info->generics);
            } }
        } }
    } }

    #line 609 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 609 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 609 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 610 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 611 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 611 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 612 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 614 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 614 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 614 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 615 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 619 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 619 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 619 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 620 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = type_impl->impl_index, ._2 = type_impl->impl_info->trait_} };
        #line 621 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 623 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 623 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 623 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 624 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 628 "src/analyzer/Module.pv"
    return true;
}

#line 631 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self) {
    #line 632 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 632 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 632 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 633 "src/analyzer/Module.pv"
        Global__parse_types(global);
    } }

    #line 636 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 636 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 636 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 637 "src/analyzer/Module.pv"
        Impl__parse_consts(impl_info);
    } }

    #line 640 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 640 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 640 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 641 "src/analyzer/Module.pv"
        Impl__parse_typedefs(impl_info);
    } }

    #line 644 "src/analyzer/Module.pv"
    return true;
}

#line 647 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 648 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 650 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 650 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 650 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 651 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 652 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 655 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 655 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 655 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 656 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 657 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 657 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 658 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 660 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 663 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 663 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 663 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 664 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 664 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 664 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 665 "src/analyzer/Module.pv"
            Trait__parse_functions(trait_info);
        } }
    } }

    #line 669 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 669 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 669 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 670 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 673 "src/analyzer/Module.pv"
    return true;
}

#line 676 "src/analyzer/Module.pv"
bool Module__parse_functions_if_path(struct Module* self, struct str path) {
    #line 677 "src/analyzer/Module.pv"
    if (!str__Eq_str__eq(self->path, path)) {
        #line 677 "src/analyzer/Module.pv"
        return false;
    }
    #line 678 "src/analyzer/Module.pv"
    return Module__parse_functions(self);
}

#line 682 "src/analyzer/Module.pv"
uint64_t Module__compute_declaration_fingerprint(struct Array_Token* tokens) {
    #line 683 "src/analyzer/Module.pv"
    uintptr_t len = tokens->length;
    #line 684 "src/analyzer/Module.pv"
    uint64_t fnv_prime = 1099511628211u;
    #line 685 "src/analyzer/Module.pv"
    uint64_t hash = 14695981039346656037u;
    #line 686 "src/analyzer/Module.pv"
    uintptr_t pos = 0;

    #line 688 "src/analyzer/Module.pv"
    while (pos < len) {
        #line 689 "src/analyzer/Module.pv"
        struct Token* token = &tokens->data[pos];

        #line 691 "src/analyzer/Module.pv"
        bool is_fn = Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co");
        #line 692 "src/analyzer/Module.pv"
        bool is_test = Token__eq(token, TOKEN_TYPE__KEYWORD, "test");

        #line 694 "src/analyzer/Module.pv"
        if (is_fn || is_test) {
            #line 695 "src/analyzer/Module.pv"
            while (pos < len) {
                #line 696 "src/analyzer/Module.pv"
                struct Token* t = &tokens->data[pos];
                #line 697 "src/analyzer/Module.pv"
                if (Token__eq(t, TOKEN_TYPE__SYMBOL, "{")) {
                    #line 698 "src/analyzer/Module.pv"
                    uintptr_t depth = 1;
                    #line 699 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 700 "src/analyzer/Module.pv"
                    while (pos < len && depth > 0) {
                        #line 701 "src/analyzer/Module.pv"
                        if (Token__eq(&tokens->data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                            #line 701 "src/analyzer/Module.pv"
                            depth += 1;
                        } else if (Token__eq(&tokens->data[pos], TOKEN_TYPE__SYMBOL, "}")) {
                            #line 702 "src/analyzer/Module.pv"
                            depth -= 1;
                        }
                        #line 703 "src/analyzer/Module.pv"
                        pos += 1;
                    }
                    #line 705 "src/analyzer/Module.pv"
                    break;
                }
                #line 707 "src/analyzer/Module.pv"
                struct str v = t->value;
                #line 708 "src/analyzer/Module.pv"
                uintptr_t i = 0;
                #line 709 "src/analyzer/Module.pv"
                while (i < v.length) {
                    #line 710 "src/analyzer/Module.pv"
                    hash = hash ^ v.ptr[i];
                    #line 711 "src/analyzer/Module.pv"
                    hash = hash * fnv_prime;
                    #line 712 "src/analyzer/Module.pv"
                    i += 1;
                }
                #line 714 "src/analyzer/Module.pv"
                pos += 1;
            }
            #line 716 "src/analyzer/Module.pv"
            continue;
        }

        #line 719 "src/analyzer/Module.pv"
        struct str v = token->value;
        #line 720 "src/analyzer/Module.pv"
        uintptr_t i = 0;
        #line 721 "src/analyzer/Module.pv"
        while (i < v.length) {
            #line 722 "src/analyzer/Module.pv"
            hash = hash ^ v.ptr[i];
            #line 723 "src/analyzer/Module.pv"
            hash = hash * fnv_prime;
            #line 724 "src/analyzer/Module.pv"
            i += 1;
        }
        #line 726 "src/analyzer/Module.pv"
        pos += 1;
    }

    #line 729 "src/analyzer/Module.pv"
    return hash;
}

#line 735 "src/analyzer/Module.pv"
uint64_t Module__declaration_fingerprint(struct Module* self) {
    #line 736 "src/analyzer/Module.pv"
    return Module__compute_declaration_fingerprint(&self->tokens);
}

#line 742 "src/analyzer/Module.pv"
void Module__retokenize_for_bodies(struct Module* self) {
    #line 743 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;
    #line 744 "src/analyzer/Module.pv"
    struct str* file_override = HashMap_str_str__find(&self->context.analysis->file_overrides, &self->path);
    #line 745 "src/analyzer/Module.pv"
    if (file_override == 0) {
        #line 745 "src/analyzer/Module.pv"
        return;
    }

    #line 747 "src/analyzer/Module.pv"
    self->tokens = Tokenizer__tokenize_data(allocator, *file_override);
    #line 748 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 749 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;
    #line 754 "src/analyzer/Module.pv"
    uintptr_t pos = 0;
    #line 755 "src/analyzer/Module.pv"
    uintptr_t len = self->tokens.length;

    #line 757 "src/analyzer/Module.pv"
    while (pos < len) {
        #line 758 "src/analyzer/Module.pv"
        struct Token* token = &self->tokens.data[pos];

        #line 760 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 761 "src/analyzer/Module.pv"
            pos += 1;
            #line 762 "src/analyzer/Module.pv"
            if (pos >= len) {
                #line 762 "src/analyzer/Module.pv"
                break;
            }

            #line 764 "src/analyzer/Module.pv"
            struct str name = self->tokens.data[pos].value;
            #line 765 "src/analyzer/Module.pv"
            pos += 1;
            #line 768 "src/analyzer/Module.pv"
            while (pos < len && !Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{") && !Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, ";")) {
                #line 769 "src/analyzer/Module.pv"
                pos += 1;
            }

            #line 772 "src/analyzer/Module.pv"
            if (pos < len && Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, ";")) {
                #line 774 "src/analyzer/Module.pv"
                pos += 1;
                #line 775 "src/analyzer/Module.pv"
                continue;
            }

            #line 778 "src/analyzer/Module.pv"
            if (pos >= len) {
                #line 778 "src/analyzer/Module.pv"
                break;
            }

            #line 780 "src/analyzer/Module.pv"
            uintptr_t token_start = pos;
            #line 781 "src/analyzer/Module.pv"
            uintptr_t depth = 1;
            #line 782 "src/analyzer/Module.pv"
            pos += 1;
            #line 783 "src/analyzer/Module.pv"
            while (pos < len && depth > 0) {
                #line 784 "src/analyzer/Module.pv"
                if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                    #line 784 "src/analyzer/Module.pv"
                    depth += 1;
                } else if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "}")) {
                    #line 785 "src/analyzer/Module.pv"
                    depth -= 1;
                }
                #line 786 "src/analyzer/Module.pv"
                pos += 1;
            }
            #line 788 "src/analyzer/Module.pv"
            uintptr_t token_end = pos;
            #line 791 "src/analyzer/Module.pv"
            Module__update_function_tokens(self, name, token_start, token_end);
            #line 792 "src/analyzer/Module.pv"
            continue;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl") || Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 794 "src/analyzer/Module.pv"
            pos += 1;
            #line 797 "src/analyzer/Module.pv"
            while (pos < len && !Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                #line 798 "src/analyzer/Module.pv"
                pos += 1;
            }
            #line 800 "src/analyzer/Module.pv"
            if (pos >= len) {
                #line 800 "src/analyzer/Module.pv"
                break;
            }
            #line 801 "src/analyzer/Module.pv"
            pos += 1;
            #line 804 "src/analyzer/Module.pv"
            uintptr_t block_depth = 1;
            #line 805 "src/analyzer/Module.pv"
            while (pos < len && block_depth > 0) {
                #line 806 "src/analyzer/Module.pv"
                struct Token* inner = &self->tokens.data[pos];

                #line 808 "src/analyzer/Module.pv"
                if (Token__eq(inner, TOKEN_TYPE__SYMBOL, "}")) {
                    #line 809 "src/analyzer/Module.pv"
                    block_depth -= 1;
                    #line 810 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 811 "src/analyzer/Module.pv"
                    continue;
                }

                #line 814 "src/analyzer/Module.pv"
                if (Token__eq(inner, TOKEN_TYPE__SYMBOL, "{")) {
                    #line 815 "src/analyzer/Module.pv"
                    block_depth += 1;
                    #line 816 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 817 "src/analyzer/Module.pv"
                    continue;
                }

                #line 820 "src/analyzer/Module.pv"
                if (Token__eq(inner, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(inner, TOKEN_TYPE__KEYWORD, "co")) {
                    #line 821 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 822 "src/analyzer/Module.pv"
                    if (pos >= len) {
                        #line 822 "src/analyzer/Module.pv"
                        break;
                    }

                    #line 824 "src/analyzer/Module.pv"
                    struct str method_name = self->tokens.data[pos].value;
                    #line 825 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 828 "src/analyzer/Module.pv"
                    while (pos < len && !Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{") && !Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, ";")) {
                        #line 829 "src/analyzer/Module.pv"
                        pos += 1;
                    }

                    #line 832 "src/analyzer/Module.pv"
                    if (pos < len && Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, ";")) {
                        #line 833 "src/analyzer/Module.pv"
                        pos += 1;
                        #line 834 "src/analyzer/Module.pv"
                        continue;
                    }

                    #line 837 "src/analyzer/Module.pv"
                    if (pos >= len) {
                        #line 837 "src/analyzer/Module.pv"
                        break;
                    }

                    #line 839 "src/analyzer/Module.pv"
                    uintptr_t fn_token_start = pos;
                    #line 840 "src/analyzer/Module.pv"
                    uintptr_t fn_depth = 1;
                    #line 841 "src/analyzer/Module.pv"
                    pos += 1;
                    #line 842 "src/analyzer/Module.pv"
                    while (pos < len && fn_depth > 0) {
                        #line 843 "src/analyzer/Module.pv"
                        if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                            #line 843 "src/analyzer/Module.pv"
                            fn_depth += 1;
                        } else if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "}")) {
                            #line 844 "src/analyzer/Module.pv"
                            fn_depth -= 1;
                        }
                        #line 845 "src/analyzer/Module.pv"
                        pos += 1;
                    }
                    #line 847 "src/analyzer/Module.pv"
                    uintptr_t fn_token_end = pos;

                    #line 849 "src/analyzer/Module.pv"
                    Module__update_function_tokens(self, method_name, fn_token_start, fn_token_end);
                    #line 850 "src/analyzer/Module.pv"
                    continue;
                }

                #line 853 "src/analyzer/Module.pv"
                pos += 1;
            }
            #line 855 "src/analyzer/Module.pv"
            continue;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "test")) {
            #line 857 "src/analyzer/Module.pv"
            pos += 1;
            #line 858 "src/analyzer/Module.pv"
            if (pos >= len) {
                #line 858 "src/analyzer/Module.pv"
                break;
            }
            #line 860 "src/analyzer/Module.pv"
            pos += 1;
            #line 861 "src/analyzer/Module.pv"
            if (pos >= len) {
                #line 861 "src/analyzer/Module.pv"
                break;
            }

            #line 863 "src/analyzer/Module.pv"
            if (!Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                #line 864 "src/analyzer/Module.pv"
                continue;
            }

            #line 867 "src/analyzer/Module.pv"
            uintptr_t test_token_start = pos;
            #line 868 "src/analyzer/Module.pv"
            uintptr_t depth = 1;
            #line 869 "src/analyzer/Module.pv"
            pos += 1;
            #line 870 "src/analyzer/Module.pv"
            while (pos < len && depth > 0) {
                #line 871 "src/analyzer/Module.pv"
                if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "{")) {
                    #line 871 "src/analyzer/Module.pv"
                    depth += 1;
                } else if (Token__eq(&self->tokens.data[pos], TOKEN_TYPE__SYMBOL, "}")) {
                    #line 872 "src/analyzer/Module.pv"
                    depth -= 1;
                }
                #line 873 "src/analyzer/Module.pv"
                pos += 1;
            }
            #line 875 "src/analyzer/Module.pv"
            uintptr_t test_token_end = pos;
            #line 880 "src/analyzer/Module.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&self->tests);
            #line 880 "src/analyzer/Module.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 880 "src/analyzer/Module.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 881 "src/analyzer/Module.pv"
                struct Function* func = HashMap_str_Function__find(&self->functions, &test_info->func_name);
                #line 882 "src/analyzer/Module.pv"
                if (func != 0) {
                    #line 883 "src/analyzer/Module.pv"
                    if (func->token_start != test_token_start || func->token_end != test_token_end) {
                        #line 884 "src/analyzer/Module.pv"
                        func->token_start = test_token_start;
                        #line 885 "src/analyzer/Module.pv"
                        func->token_end = test_token_end;
                        #line 886 "src/analyzer/Module.pv"
                        break;
                    }
                }
            } }
            #line 890 "src/analyzer/Module.pv"
            continue;
        }

        #line 893 "src/analyzer/Module.pv"
        pos += 1;
    }
}

#line 897 "src/analyzer/Module.pv"
void Module__update_function_tokens(struct Module* self, struct str name, uintptr_t token_start, uintptr_t token_end) {
    #line 899 "src/analyzer/Module.pv"
    struct Function* func = HashMap_str_Function__find(&self->functions, &name);
    #line 900 "src/analyzer/Module.pv"
    if (func != 0) {
        #line 901 "src/analyzer/Module.pv"
        func->token_start = token_start;
        #line 902 "src/analyzer/Module.pv"
        func->token_end = token_end;
        #line 903 "src/analyzer/Module.pv"
        return;
    }
    #line 907 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 907 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 907 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 908 "src/analyzer/Module.pv"
        struct Function* impl_func = HashMap_str_Function__find(&impl_info->functions, &name);
        #line 909 "src/analyzer/Module.pv"
        if (impl_func != 0) {
            #line 910 "src/analyzer/Module.pv"
            impl_func->token_start = token_start;
            #line 911 "src/analyzer/Module.pv"
            impl_func->token_end = token_end;
            #line 912 "src/analyzer/Module.pv"
            return;
        }
    } }
}

#line 917 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name, uintptr_t arity) {
    #line 918 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 919 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 919 "src/analyzer/Module.pv"
        return type;
    }

    #line 921 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name, arity);
    #line 922 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 922 "src/analyzer/Module.pv"
        return type;
    }

    #line 924 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 924 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 924 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 925 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name, arity);
        #line 926 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 926 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 929 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name, arity);
    #line 930 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 930 "src/analyzer/Module.pv"
        return type;
    }

    #line 932 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 932 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 932 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 933 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 934 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 934 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 937 "src/analyzer/Module.pv"
    return 0;
}

#line 940 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name, uintptr_t arity) {
    #line 941 "src/analyzer/Module.pv"
    struct Trait* type = Namespace__find_trait(self->namespace, name, arity);
    #line 942 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 942 "src/analyzer/Module.pv"
        return type;
    }

    #line 944 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 944 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 944 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 945 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name, arity);
        #line 946 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 946 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 949 "src/analyzer/Module.pv"
    return 0;
}

#line 952 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 953 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 954 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 954 "src/analyzer/Module.pv"
        return type;
    }

    #line 956 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 957 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 957 "src/analyzer/Module.pv"
        return type;
    }

    #line 959 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 959 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 959 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 960 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 961 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 961 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 964 "src/analyzer/Module.pv"
    return 0;
}

#line 967 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 968 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->global_types, &name);
    #line 969 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 969 "src/analyzer/Module.pv"
        return type;
    }

    #line 971 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 971 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 971 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 972 "src/analyzer/Module.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 972 "src/analyzer/Module.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 972 "src/analyzer/Module.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 973 "src/analyzer/Module.pv"
            type = HashMap_str_Type__find(&module->global_types, &name);
            #line 974 "src/analyzer/Module.pv"
            if (type != 0) {
                #line 974 "src/analyzer/Module.pv"
                return type;
            }
        } }
    } }

    #line 978 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 978 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 978 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 979 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->values, &name);
        #line 980 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 980 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 983 "src/analyzer/Module.pv"
    return 0;
}

#line 986 "src/analyzer/Module.pv"
int64_t* Module__find_macro_value(struct Module* self, struct str name) {
    #line 987 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 987 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 987 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 988 "src/analyzer/Module.pv"
        int64_t* value = HashMap_str_i64__find(&include->macro_values, &name);
        #line 989 "src/analyzer/Module.pv"
        if (value != 0) {
            #line 989 "src/analyzer/Module.pv"
            return value;
        }
    } }
    #line 991 "src/analyzer/Module.pv"
    return 0;
}

#line 994 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 995 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name, usage_types->length);
    #line 996 "src/analyzer/Module.pv"
    if (type == 0) {
        #line 996 "src/analyzer/Module.pv"
        return 0;
    }
    #line 997 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 1000 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 1001 "src/analyzer/Module.pv"
    return Root__find_primitive(self->namespace->root, name);
}
