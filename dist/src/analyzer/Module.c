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
#include <analyzer/types/Trait.h>
#include <std/Array_ref_Trait.h>
#include <analyzer/types/Function.h>
#include <std/String.h>
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
#include <std/HashMapIter_str_ref_Include.h>
#include <tuple_str_ref_Include.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMap_str_i64.h>
#include <std/HashMap_str_Primitive.h>
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
                if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                    #line 174 "src/analyzer/Module.pv"
                    HashMap_str_ref_Include__insert(&self->includes, path->value, include);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 178 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 180 "src/analyzer/Module.pv"
            struct Token* enum_name = node.name;
            #line 181 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 182 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 184 "src/analyzer/Module.pv"
                struct Enum* enum_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Enum));
                #line 185 "src/analyzer/Module.pv"
                *enum_ptr = node;
                #line 186 "src/analyzer/Module.pv"
                struct Array_ref_Enum* existing = HashMap_str_Array_ref_Enum__find(enums, &enum_name->value);
                #line 187 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 188 "src/analyzer/Module.pv"
                    struct Array_ref_Enum arr = Array_ref_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 189 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(&arr, enum_ptr);
                    #line 190 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Enum__insert(enums, enum_name->value, arr);
                } else {
                    #line 192 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(existing, enum_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 196 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 198 "src/analyzer/Module.pv"
            struct Token* struct_name = node.name;
            #line 199 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 200 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 202 "src/analyzer/Module.pv"
                struct Struct* struct_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Struct));
                #line 203 "src/analyzer/Module.pv"
                *struct_ptr = node;
                #line 204 "src/analyzer/Module.pv"
                struct Array_ref_Struct* existing = HashMap_str_Array_ref_Struct__find(structs, &struct_name->value);
                #line 205 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 206 "src/analyzer/Module.pv"
                    struct Array_ref_Struct arr = Array_ref_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 207 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(&arr, struct_ptr);
                    #line 208 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Struct__insert(structs, struct_name->value, arr);
                } else {
                    #line 210 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(existing, struct_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 214 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 216 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 217 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 219 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 222 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 224 "src/analyzer/Module.pv"
            struct Token* trait_name = node.name;
            #line 225 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 226 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 228 "src/analyzer/Module.pv"
                struct Trait* trait_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Trait));
                #line 229 "src/analyzer/Module.pv"
                *trait_ptr = node;
                #line 230 "src/analyzer/Module.pv"
                struct Array_ref_Trait* existing = HashMap_str_Array_ref_Trait__find(traits, &trait_name->value);
                #line 231 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 232 "src/analyzer/Module.pv"
                    struct Array_ref_Trait arr = Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 233 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(&arr, trait_ptr);
                    #line 234 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Trait__insert(traits, trait_name->value, arr);
                } else {
                    #line 236 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(existing, trait_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 240 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 242 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 243 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 245 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "test")) {
            #line 248 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "test")) {
                #line 248 "src/analyzer/Module.pv"
                return false;
            }

            #line 250 "src/analyzer/Module.pv"
            struct Token* description = Context__expect(context, TOKEN_TYPE__STRING);
            #line 251 "src/analyzer/Module.pv"
            if (description == 0) {
                #line 251 "src/analyzer/Module.pv"
                return false;
            }

            #line 253 "src/analyzer/Module.pv"
            struct String name_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 256 "src/analyzer/Module.pv"
            struct String ns_prefix = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 257 "src/analyzer/Module.pv"
            struct Namespace* cur_ns = self->namespace;
            #line 258 "src/analyzer/Module.pv"
            while (cur_ns != 0 && cur_ns->parent != 0) {
                #line 259 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, (struct str){ .ptr = "__", .length = strlen("__") });
                #line 260 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, cur_ns->name);
                #line 261 "src/analyzer/Module.pv"
                cur_ns = cur_ns->parent;
            }
            #line 263 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "test_", .length = strlen("test_") });
            #line 264 "src/analyzer/Module.pv"
            String__append_string(&name_str, &ns_prefix);
            #line 267 "src/analyzer/Module.pv"
            struct str mod_path = self->path;
            #line 268 "src/analyzer/Module.pv"
            intptr_t last_sep = -1;
            #line 269 "src/analyzer/Module.pv"
            uintptr_t pi = 0;
            #line 270 "src/analyzer/Module.pv"
            while (pi < mod_path.length) {
                #line 271 "src/analyzer/Module.pv"
                char pch = mod_path.ptr[pi];
                #line 272 "src/analyzer/Module.pv"
                if (pch == '/' || pch == '\\') {
                    #line 272 "src/analyzer/Module.pv"
                    last_sep = (intptr_t)(pi);
                }
                #line 273 "src/analyzer/Module.pv"
                pi += 1;
            }
            #line 275 "src/analyzer/Module.pv"
            uintptr_t stem_start = 0;
            #line 276 "src/analyzer/Module.pv"
            if (last_sep >= 0) {
                #line 276 "src/analyzer/Module.pv"
                stem_start = (uintptr_t)(last_sep) + 1;
            }
            #line 277 "src/analyzer/Module.pv"
            uintptr_t stem_end = mod_path.length;
            #line 278 "src/analyzer/Module.pv"
            if (stem_end >= 3 && str__Eq_str__eq((struct str[]){str__slice(mod_path, stem_end - 3, stem_end)}, (struct str){ .ptr = ".pv", .length = strlen(".pv") })) {
                #line 279 "src/analyzer/Module.pv"
                stem_end = stem_end - 3;
            }
            #line 281 "src/analyzer/Module.pv"
            String__append(&name_str, str__slice(mod_path, stem_start, stem_end));
            #line 282 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "__", .length = strlen("__") });
            #line 285 "src/analyzer/Module.pv"
            struct str desc_raw = str__slice(description->value, 1, description->value.length - 1);
            #line 286 "src/analyzer/Module.pv"
            uintptr_t di = 0;
            #line 287 "src/analyzer/Module.pv"
            while (di < desc_raw.length) {
                #line 288 "src/analyzer/Module.pv"
                char dch = desc_raw.ptr[di];
                #line 289 "src/analyzer/Module.pv"
                if ((dch >= 'a' && dch <= 'z') || (dch >= 'A' && dch <= 'Z') || (dch >= '0' && dch <= '9')) {
                    #line 290 "src/analyzer/Module.pv"
                    String__append(&name_str, str__slice(desc_raw, di, di + 1));
                } else {
                    #line 292 "src/analyzer/Module.pv"
                    String__append(&name_str, (struct str){ .ptr = "_", .length = strlen("_") });
                }
                #line 294 "src/analyzer/Module.pv"
                di += 1;
            }

            #line 297 "src/analyzer/Module.pv"
            struct Token name_token_val = (struct Token) {
                .type = TOKEN_TYPE__IDENTIFIER,
                .value = String__as_str(&name_str),
                .start_line = 0,
                .start_column = 0,
                .end_line = 0,
                .end_column = 0,
            };
            #line 305 "src/analyzer/Module.pv"
            struct Token* name_token = ArenaAllocator__store_Token(allocator, &name_token_val);
            #line 306 "src/analyzer/Module.pv"
            if (name_token == 0) {
                #line 306 "src/analyzer/Module.pv"
                return false;
            }

            #line 308 "src/analyzer/Module.pv"
            if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                #line 309 "src/analyzer/Module.pv"
                Context__error_token(context, description, "Expected { after test description");
                #line 310 "src/analyzer/Module.pv"
                return false;
            }

            #line 313 "src/analyzer/Module.pv"
            struct Function node = Function__new(context);
            #line 314 "src/analyzer/Module.pv"
            node.name = name_token;
            #line 315 "src/analyzer/Module.pv"
            node.type = FUNCTION_TYPE__TEST;
            #line 316 "src/analyzer/Module.pv"
            node.declaration_start = context->pos;
            #line 317 "src/analyzer/Module.pv"
            node.declaration_end = context->pos;
            #line 318 "src/analyzer/Module.pv"
            node.token_start = context->pos;

            #line 320 "src/analyzer/Module.pv"
            if (!Context__skip_brackets(context, "{", "}")) {
                #line 320 "src/analyzer/Module.pv"
                return false;
            }
            #line 321 "src/analyzer/Module.pv"
            node.token_end = context->pos;

            #line 323 "src/analyzer/Module.pv"
            Array_TestInfo__append(&self->tests, (struct TestInfo) { .description = description, .func_name = String__as_str(&name_str) });
            #line 324 "src/analyzer/Module.pv"
            HashMap_str_Function__insert(functions, name_token->value, node);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "const") || Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 326 "src/analyzer/Module.pv"
            bool is_const = Token__eq(token, TOKEN_TYPE__KEYWORD, "const");
            #line 327 "src/analyzer/Module.pv"
            Context__next_token(context);
            #line 328 "src/analyzer/Module.pv"
            struct Token* global_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 329 "src/analyzer/Module.pv"
            if (global_name == 0) {
                #line 329 "src/analyzer/Module.pv"
                return false;
            }

            #line 331 "src/analyzer/Module.pv"
            uintptr_t token_start = context->pos;

            #line 333 "src/analyzer/Module.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 334 "src/analyzer/Module.pv"
                Context__next_token(context);
            }
            #line 336 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 336 "src/analyzer/Module.pv"
                return false;
            }
            #line 337 "src/analyzer/Module.pv"
            uintptr_t token_end = context->pos;

            #line 339 "src/analyzer/Module.pv"
            struct Global* global = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Global));
            #line 340 "src/analyzer/Module.pv"
            *global = (struct Global) {
                .name = global_name,
                .module = self,
                .token_start = token_start,
                .token_end = token_end,
                .is_const = is_const,
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
                .value = 0,
            };
            #line 349 "src/analyzer/Module.pv"
            HashMap_str_ref_Global__insert(&self->globals, global_name->value, global);
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 351 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 353 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 354 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 358 "src/analyzer/Module.pv"
    return result;
}

#line 361 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 362 "src/analyzer/Module.pv"
    bool success = true;

    #line 364 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 364 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 364 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 365 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 368 "src/analyzer/Module.pv"
    return success;
}

#line 371 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 372 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 373 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 374 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 375 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 377 "src/analyzer/Module.pv"
    if (path->root) {
        #line 378 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 380 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 383 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 384 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 385 "src/analyzer/Module.pv"
        return false;
    }

    #line 388 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 388 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 388 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 389 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 390 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 391 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 392 "src/analyzer/Module.pv"
            return false;
        }

        #line 395 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 398 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 400 "src/analyzer/Module.pv"
    return true;
}

#line 403 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 404 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 405 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 406 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 407 "src/analyzer/Module.pv"
    if (blank_generics == 0) {
        #line 407 "src/analyzer/Module.pv"
        return false;
    }
    #line 408 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, allocator);

    #line 410 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 410 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 410 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 411 "src/analyzer/Module.pv"
        struct Token* func_name = func_info->name;
        #line 412 "src/analyzer/Module.pv"
        if (func_name == 0) {
            #line 412 "src/analyzer/Module.pv"
            return false;
        }
        #line 413 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 416 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 416 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 416 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 417 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 417 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 417 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 418 "src/analyzer/Module.pv"
            struct Token* enum_name = enum_info->name;
            #line 419 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 419 "src/analyzer/Module.pv"
                return false;
            }
            #line 420 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, enum_name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} })) {
                #line 421 "src/analyzer/Module.pv"
                Context__error_token(&self->context, enum_name, "Duplicate type with this name and generic arity");
                #line 422 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 427 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 427 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 427 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 428 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 428 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 428 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 429 "src/analyzer/Module.pv"
            struct GenericMap generics_val = GenericMap__from_generics(allocator, &struct_info->generics);
            #line 430 "src/analyzer/Module.pv"
            struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, &generics_val);
            #line 431 "src/analyzer/Module.pv"
            if (generics == 0) {
                #line 431 "src/analyzer/Module.pv"
                return false;
            }
            #line 432 "src/analyzer/Module.pv"
            generics->self_type = blank_generics->self_type;

            #line 434 "src/analyzer/Module.pv"
            struct Token* struct_name = struct_info->name;
            #line 435 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 435 "src/analyzer/Module.pv"
                return false;
            }
            #line 436 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, struct_name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} })) {
                #line 437 "src/analyzer/Module.pv"
                Context__error_token(&self->context, struct_name, "Duplicate type with this name and generic arity");
                #line 438 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 443 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 443 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 443 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 444 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 444 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 444 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 445 "src/analyzer/Module.pv"
            struct Token* trait_name = trait_info->name;
            #line 446 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 446 "src/analyzer/Module.pv"
                return false;
            }
            #line 447 "src/analyzer/Module.pv"
            if (!Namespace__add_trait(namespace, trait_name->value, trait_info)) {
                #line 448 "src/analyzer/Module.pv"
                Context__error_token(&self->context, trait_name, "Duplicate trait with this name and generic arity");
                #line 449 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 454 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 454 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 454 "src/analyzer/Module.pv"
        struct str name = HashMapIter_str_ref_Global__value(&__iter)->_0;
        #line 454 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 455 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&self->global_types, name, (struct Type) { .type = TYPE__GLOBAL, .global_value = global });
    } }

    #line 458 "src/analyzer/Module.pv"
    return true;
}

#line 461 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 462 "src/analyzer/Module.pv"
    bool success = true;

    #line 464 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 464 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 464 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 465 "src/analyzer/Module.pv"
        if (str__Eq_str__eq(&namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 466 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 467 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 469 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 471 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 472 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 473 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 475 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 476 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 478 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") }, 0);
            #line 479 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 480 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 483 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 486 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 487 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 491 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 491 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 491 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 492 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 492 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 492 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 493 "src/analyzer/Module.pv"
            success = Enum__prefill_types(enum_info) && success;
        } }
    } }

    #line 497 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 497 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 497 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 498 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 498 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 498 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 499 "src/analyzer/Module.pv"
            success = Struct__prefill_types(struct_info) && success;
        } }
    } }

    #line 503 "src/analyzer/Module.pv"
    return success;
}

#line 506 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 507 "src/analyzer/Module.pv"
    bool success = true;
    #line 508 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 510 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 510 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 510 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 511 "src/analyzer/Module.pv"
        if (!Impl__prefill_types(impl_info)) {
            #line 512 "src/analyzer/Module.pv"
            success = false;
            #line 513 "src/analyzer/Module.pv"
            continue;
        }

        #line 516 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 517 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 517 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 518 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 519 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 519 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 520 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 522 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = trait_info} };
                #line 523 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 525 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 525 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 526 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 527 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 527 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), (struct tuple_ref_Trait_ref_Type) { ._0 = trait_info, ._1 = &impl_info->trait_type });
                }
                #line 528 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 529 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = trait_info} };
                #line 530 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 532 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 532 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 533 "src/analyzer/Module.pv"
                if (primitive_info == 0) {
                    #line 533 "src/analyzer/Module.pv"
                    return false;
                }
                #line 534 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 535 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 536 "src/analyzer/Module.pv"
                    struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
                    #line 537 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, trait_key, trait_info);
                }
                #line 539 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 541 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 541 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 542 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 543 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 544 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 544 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 545 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 547 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 547 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 548 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 549 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 550 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 550 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 551 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 553 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 553 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 554 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 555 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 556 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 556 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 557 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 559 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 560 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info));
                #line 561 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 563 "src/analyzer/Module.pv"
            default: {
                #line 563 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->token, "Impl blocks are not supported for this type");
            } break;
        }
    } }

    #line 567 "src/analyzer/Module.pv"
    return success;
}

#line 570 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 571 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 571 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 571 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 572 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 576 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 576 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 576 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 577 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 577 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 577 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 578 "src/analyzer/Module.pv"
            Enum__fill_variants(enum_info);
        } }
    } }

    #line 582 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 582 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 582 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 583 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 583 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 583 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 584 "src/analyzer/Module.pv"
            Struct__fill_types(struct_info);
        } }
    } }

    #line 588 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 588 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 588 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 589 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 589 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 589 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 590 "src/analyzer/Module.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
            #line 591 "src/analyzer/Module.pv"
            Trait__fill_types(trait_info, parent);

            #line 594 "src/analyzer/Module.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 594 "src/analyzer/Module.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 594 "src/analyzer/Module.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 595 "src/analyzer/Module.pv"
                Function__fill_types(func_info, &trait_info->generics);
            } }
        } }
    } }

    #line 600 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 600 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 600 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 601 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 602 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 602 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 603 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 605 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 605 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 605 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 606 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 610 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 610 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 610 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 611 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 612 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 614 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 614 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 614 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 615 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 619 "src/analyzer/Module.pv"
    return true;
}

#line 622 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self) {
    #line 623 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 623 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 623 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 624 "src/analyzer/Module.pv"
        Global__parse_types(global);
    } }

    #line 627 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 627 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 627 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 628 "src/analyzer/Module.pv"
        Impl__parse_consts(impl_info);
    } }

    #line 631 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 631 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 631 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 632 "src/analyzer/Module.pv"
        Impl__parse_typedefs(impl_info);
    } }

    #line 635 "src/analyzer/Module.pv"
    return true;
}

#line 638 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 639 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 641 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 641 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 641 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 642 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 643 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 646 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 646 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 646 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 647 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 648 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 648 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 649 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 651 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 654 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 654 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 654 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 655 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 655 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 655 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 656 "src/analyzer/Module.pv"
            Trait__parse_functions(trait_info);
        } }
    } }

    #line 660 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 660 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 660 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 661 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 664 "src/analyzer/Module.pv"
    return true;
}

#line 667 "src/analyzer/Module.pv"
bool Module__parse_functions_if_path(struct Module* self, struct str path) {
    #line 668 "src/analyzer/Module.pv"
    if (!str__Eq_str__eq(&self->path, path)) {
        #line 668 "src/analyzer/Module.pv"
        return true;
    }
    #line 669 "src/analyzer/Module.pv"
    return Module__parse_functions(self);
}

#line 672 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name, uintptr_t arity) {
    #line 673 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 674 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 674 "src/analyzer/Module.pv"
        return type;
    }

    #line 676 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name, arity);
    #line 677 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 677 "src/analyzer/Module.pv"
        return type;
    }

    #line 679 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 679 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 679 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 680 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name, arity);
        #line 681 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 681 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 684 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name, arity);
    #line 685 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 685 "src/analyzer/Module.pv"
        return type;
    }

    #line 687 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 687 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 687 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 688 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 689 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 689 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 692 "src/analyzer/Module.pv"
    return 0;
}

#line 695 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name, uintptr_t arity) {
    #line 696 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name, arity);
    #line 697 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 697 "src/analyzer/Module.pv"
        return type;
    }

    #line 699 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name, arity);
    #line 700 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 700 "src/analyzer/Module.pv"
        return type;
    }

    #line 702 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 702 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 702 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 703 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name, arity);
        #line 704 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 704 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 707 "src/analyzer/Module.pv"
    return 0;
}

#line 710 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 711 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 712 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 712 "src/analyzer/Module.pv"
        return type;
    }

    #line 714 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 715 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 715 "src/analyzer/Module.pv"
        return type;
    }

    #line 717 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 717 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 717 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 718 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 719 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 719 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 722 "src/analyzer/Module.pv"
    return 0;
}

#line 725 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 726 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->global_types, &name);
    #line 727 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 727 "src/analyzer/Module.pv"
        return type;
    }

    #line 729 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 729 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 729 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 730 "src/analyzer/Module.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 730 "src/analyzer/Module.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 730 "src/analyzer/Module.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 731 "src/analyzer/Module.pv"
            type = HashMap_str_Type__find(&module->global_types, &name);
            #line 732 "src/analyzer/Module.pv"
            if (type != 0) {
                #line 732 "src/analyzer/Module.pv"
                return type;
            }
        } }
    } }

    #line 736 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 736 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 736 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 737 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->values, &name);
        #line 738 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 738 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 741 "src/analyzer/Module.pv"
    return 0;
}

#line 744 "src/analyzer/Module.pv"
int64_t* Module__find_macro_value(struct Module* self, struct str name) {
    #line 745 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 745 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 745 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 746 "src/analyzer/Module.pv"
        int64_t* value = HashMap_str_i64__find(&include->macro_values, &name);
        #line 747 "src/analyzer/Module.pv"
        if (value != 0) {
            #line 747 "src/analyzer/Module.pv"
            return value;
        }
    } }
    #line 749 "src/analyzer/Module.pv"
    return 0;
}

#line 752 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 753 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name, usage_types->length);
    #line 754 "src/analyzer/Module.pv"
    if (type == 0) {
        #line 754 "src/analyzer/Module.pv"
        return 0;
    }
    #line 755 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 758 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 759 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 760 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &name);
}
