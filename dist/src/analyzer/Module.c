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
    self->tokens = Tokenizer__tokenize(allocator, self->path.ptr);
    #line 78 "src/analyzer/Module.pv"
    self->context.tokens = self->tokens.data;
    #line 79 "src/analyzer/Module.pv"
    self->context.length = self->tokens.length;

    #line 81 "src/analyzer/Module.pv"
    bool result = true;

    #line 83 "src/analyzer/Module.pv"
    while (context->pos < context->length && result) {
        #line 84 "src/analyzer/Module.pv"
        struct Token* token = &context->tokens[context->pos];

        #line 86 "src/analyzer/Module.pv"
        if (Token__eq(token, TOKEN_TYPE__KEYWORD, "ns")) {
            #line 87 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "ns")) {
                #line 87 "src/analyzer/Module.pv"
                return false;
            }
            #line 88 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 89 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 91 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 92 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 94 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 95 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 98 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 100 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 101 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 103 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 104 "src/analyzer/Module.pv"
                    result = Namespace__add_namespace_subfolder(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "mod")) {
            #line 108 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "mod")) {
                #line 108 "src/analyzer/Module.pv"
                return false;
            }
            #line 109 "src/analyzer/Module.pv"
            if (Context__check(context, TOKEN_TYPE__STRING)) {
                #line 110 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__STRING);

                #line 112 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 113 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 115 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 116 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, str__slice(name->value, 1, name->value.length - 1));
                }
            } else {
                #line 119 "src/analyzer/Module.pv"
                struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

                #line 121 "src/analyzer/Module.pv"
                if (name == 0) {
                    #line 122 "src/analyzer/Module.pv"
                    result = false;
                } else {
                    #line 124 "src/analyzer/Module.pv"
                    struct Namespace* namespace = self->namespace;
                    #line 125 "src/analyzer/Module.pv"
                    result = Namespace__add_module(namespace, name->value);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "use")) {
            #line 129 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "use")) {
                #line 129 "src/analyzer/Module.pv"
                return false;
            }

            #line 131 "src/analyzer/Module.pv"
            struct NamespacePath path = NamespacePath__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 132 "src/analyzer/Module.pv"
            if (!NamespacePath__parse(&path, context)) {
                #line 132 "src/analyzer/Module.pv"
                return false;
            }

            #line 134 "src/analyzer/Module.pv"
            Array_NamespacePath__append(use_namespaces, path);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#cpp")) {
            #line 136 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#cpp")) {
                #line 136 "src/analyzer/Module.pv"
                return false;
            }
            #line 137 "src/analyzer/Module.pv"
            self->mode_cpp = true;
            #line 138 "src/analyzer/Module.pv"
            self->root->mode_cpp = true;
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "#include")) {
            #line 140 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#include")) {
                #line 140 "src/analyzer/Module.pv"
                return false;
            }

            #line 142 "src/analyzer/Module.pv"
            struct Token* path = Context__expect(context, TOKEN_TYPE__STRING);
            #line 143 "src/analyzer/Module.pv"
            if (path == 0) {
                #line 143 "src/analyzer/Module.pv"
                return false;
            }

            #line 145 "src/analyzer/Module.pv"
            struct HashMap_str_ref_Include* includes = &self->root->includes_c;
            #line 146 "src/analyzer/Module.pv"
            if (self->mode_cpp) {
                #line 146 "src/analyzer/Module.pv"
                includes = &self->root->includes_cpp;
            }

            #line 148 "src/analyzer/Module.pv"
            struct Include** include_ptr = HashMap_str_ref_Include__find(includes, &path->value);
            #line 149 "src/analyzer/Module.pv"
            struct Include* include = 0;
            #line 150 "src/analyzer/Module.pv"
            if (include_ptr != 0) {
                #line 150 "src/analyzer/Module.pv"
                include = *include_ptr;
            }

            #line 152 "src/analyzer/Module.pv"
            if (include == 0) {
                #line 153 "src/analyzer/Module.pv"
                include = Include__new(self->root, path->value, self->mode_cpp);
                #line 154 "src/analyzer/Module.pv"
                if (include == 0) {
                    #line 154 "src/analyzer/Module.pv"
                    return false;
                }
                #line 155 "src/analyzer/Module.pv"
                Include__process(include);
                #line 156 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(includes, path->value, include);
            }

            #line 159 "src/analyzer/Module.pv"
            if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                #line 160 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(&self->includes, path->value, include);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 163 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 165 "src/analyzer/Module.pv"
            struct Token* enum_name = node.name;
            #line 166 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 167 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 169 "src/analyzer/Module.pv"
                struct Enum* enum_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Enum));
                #line 170 "src/analyzer/Module.pv"
                *enum_ptr = node;
                #line 171 "src/analyzer/Module.pv"
                struct Array_ref_Enum* existing = HashMap_str_Array_ref_Enum__find(enums, &enum_name->value);
                #line 172 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 173 "src/analyzer/Module.pv"
                    struct Array_ref_Enum arr = Array_ref_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 174 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(&arr, enum_ptr);
                    #line 175 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Enum__insert(enums, enum_name->value, arr);
                } else {
                    #line 177 "src/analyzer/Module.pv"
                    Array_ref_Enum__append(existing, enum_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 181 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 183 "src/analyzer/Module.pv"
            struct Token* struct_name = node.name;
            #line 184 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 185 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 187 "src/analyzer/Module.pv"
                struct Struct* struct_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Struct));
                #line 188 "src/analyzer/Module.pv"
                *struct_ptr = node;
                #line 189 "src/analyzer/Module.pv"
                struct Array_ref_Struct* existing = HashMap_str_Array_ref_Struct__find(structs, &struct_name->value);
                #line 190 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 191 "src/analyzer/Module.pv"
                    struct Array_ref_Struct arr = Array_ref_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 192 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(&arr, struct_ptr);
                    #line 193 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Struct__insert(structs, struct_name->value, arr);
                } else {
                    #line 195 "src/analyzer/Module.pv"
                    Array_ref_Struct__append(existing, struct_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 199 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 201 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 202 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 204 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 207 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 209 "src/analyzer/Module.pv"
            struct Token* trait_name = node.name;
            #line 210 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 211 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 213 "src/analyzer/Module.pv"
                struct Trait* trait_ptr = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Trait));
                #line 214 "src/analyzer/Module.pv"
                *trait_ptr = node;
                #line 215 "src/analyzer/Module.pv"
                struct Array_ref_Trait* existing = HashMap_str_Array_ref_Trait__find(traits, &trait_name->value);
                #line 216 "src/analyzer/Module.pv"
                if (existing == 0) {
                    #line 217 "src/analyzer/Module.pv"
                    struct Array_ref_Trait arr = Array_ref_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
                    #line 218 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(&arr, trait_ptr);
                    #line 219 "src/analyzer/Module.pv"
                    HashMap_str_Array_ref_Trait__insert(traits, trait_name->value, arr);
                } else {
                    #line 221 "src/analyzer/Module.pv"
                    Array_ref_Trait__append(existing, trait_ptr);
                }
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 225 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 227 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 228 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 230 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "test")) {
            #line 233 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "test")) {
                #line 233 "src/analyzer/Module.pv"
                return false;
            }

            #line 235 "src/analyzer/Module.pv"
            struct Token* description = Context__expect(context, TOKEN_TYPE__STRING);
            #line 236 "src/analyzer/Module.pv"
            if (description == 0) {
                #line 236 "src/analyzer/Module.pv"
                return false;
            }

            #line 238 "src/analyzer/Module.pv"
            struct String name_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 241 "src/analyzer/Module.pv"
            struct String ns_prefix = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 242 "src/analyzer/Module.pv"
            struct Namespace* cur_ns = self->namespace;
            #line 243 "src/analyzer/Module.pv"
            while (cur_ns != 0 && cur_ns->parent != 0) {
                #line 244 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, (struct str){ .ptr = "__", .length = strlen("__") });
                #line 245 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, cur_ns->name);
                #line 246 "src/analyzer/Module.pv"
                cur_ns = cur_ns->parent;
            }
            #line 248 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "test_", .length = strlen("test_") });
            #line 249 "src/analyzer/Module.pv"
            String__append_string(&name_str, &ns_prefix);
            #line 252 "src/analyzer/Module.pv"
            struct str mod_path = self->path;
            #line 253 "src/analyzer/Module.pv"
            intptr_t last_sep = -1;
            #line 254 "src/analyzer/Module.pv"
            uintptr_t pi = 0;
            #line 255 "src/analyzer/Module.pv"
            while (pi < mod_path.length) {
                #line 256 "src/analyzer/Module.pv"
                char pch = mod_path.ptr[pi];
                #line 257 "src/analyzer/Module.pv"
                if (pch == '/' || pch == '\\') {
                    #line 257 "src/analyzer/Module.pv"
                    last_sep = (intptr_t)(pi);
                }
                #line 258 "src/analyzer/Module.pv"
                pi += 1;
            }
            #line 260 "src/analyzer/Module.pv"
            uintptr_t stem_start = 0;
            #line 261 "src/analyzer/Module.pv"
            if (last_sep >= 0) {
                #line 261 "src/analyzer/Module.pv"
                stem_start = (uintptr_t)(last_sep) + 1;
            }
            #line 262 "src/analyzer/Module.pv"
            uintptr_t stem_end = mod_path.length;
            #line 263 "src/analyzer/Module.pv"
            if (stem_end >= 3 && str__Eq_str__eq((struct str[]){str__slice(mod_path, stem_end - 3, stem_end)}, (struct str){ .ptr = ".pv", .length = strlen(".pv") })) {
                #line 264 "src/analyzer/Module.pv"
                stem_end = stem_end - 3;
            }
            #line 266 "src/analyzer/Module.pv"
            String__append(&name_str, str__slice(mod_path, stem_start, stem_end));
            #line 267 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "__", .length = strlen("__") });
            #line 270 "src/analyzer/Module.pv"
            struct str desc_raw = str__slice(description->value, 1, description->value.length - 1);
            #line 271 "src/analyzer/Module.pv"
            uintptr_t di = 0;
            #line 272 "src/analyzer/Module.pv"
            while (di < desc_raw.length) {
                #line 273 "src/analyzer/Module.pv"
                char dch = desc_raw.ptr[di];
                #line 274 "src/analyzer/Module.pv"
                if ((dch >= 'a' && dch <= 'z') || (dch >= 'A' && dch <= 'Z') || (dch >= '0' && dch <= '9')) {
                    #line 275 "src/analyzer/Module.pv"
                    String__append(&name_str, str__slice(desc_raw, di, di + 1));
                } else {
                    #line 277 "src/analyzer/Module.pv"
                    String__append(&name_str, (struct str){ .ptr = "_", .length = strlen("_") });
                }
                #line 279 "src/analyzer/Module.pv"
                di += 1;
            }

            #line 282 "src/analyzer/Module.pv"
            struct Token name_token_val = (struct Token) {
                .type = TOKEN_TYPE__IDENTIFIER,
                .value = String__as_str(&name_str),
                .start_line = 0,
                .start_column = 0,
                .end_line = 0,
                .end_column = 0,
            };
            #line 290 "src/analyzer/Module.pv"
            struct Token* name_token = ArenaAllocator__store_Token(allocator, &name_token_val);
            #line 291 "src/analyzer/Module.pv"
            if (name_token == 0) {
                #line 291 "src/analyzer/Module.pv"
                return false;
            }

            #line 293 "src/analyzer/Module.pv"
            if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                #line 294 "src/analyzer/Module.pv"
                Context__error_token(context, description, "Expected { after test description");
                #line 295 "src/analyzer/Module.pv"
                return false;
            }

            #line 298 "src/analyzer/Module.pv"
            struct Function node = Function__new(context);
            #line 299 "src/analyzer/Module.pv"
            node.name = name_token;
            #line 300 "src/analyzer/Module.pv"
            node.type = FUNCTION_TYPE__TEST;
            #line 301 "src/analyzer/Module.pv"
            node.declaration_start = context->pos;
            #line 302 "src/analyzer/Module.pv"
            node.declaration_end = context->pos;
            #line 303 "src/analyzer/Module.pv"
            node.token_start = context->pos;

            #line 305 "src/analyzer/Module.pv"
            if (!Context__skip_brackets(context, "{", "}")) {
                #line 305 "src/analyzer/Module.pv"
                return false;
            }
            #line 306 "src/analyzer/Module.pv"
            node.token_end = context->pos;

            #line 308 "src/analyzer/Module.pv"
            Array_TestInfo__append(&self->tests, (struct TestInfo) { .description = description, .func_name = String__as_str(&name_str) });
            #line 309 "src/analyzer/Module.pv"
            HashMap_str_Function__insert(functions, name_token->value, node);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "const") || Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 311 "src/analyzer/Module.pv"
            bool is_const = Token__eq(token, TOKEN_TYPE__KEYWORD, "const");
            #line 312 "src/analyzer/Module.pv"
            Context__next_token(context);
            #line 313 "src/analyzer/Module.pv"
            struct Token* global_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 314 "src/analyzer/Module.pv"
            if (global_name == 0) {
                #line 314 "src/analyzer/Module.pv"
                return false;
            }

            #line 316 "src/analyzer/Module.pv"
            uintptr_t token_start = context->pos;

            #line 318 "src/analyzer/Module.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 319 "src/analyzer/Module.pv"
                Context__next_token(context);
            }
            #line 321 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 321 "src/analyzer/Module.pv"
                return false;
            }
            #line 322 "src/analyzer/Module.pv"
            uintptr_t token_end = context->pos;

            #line 324 "src/analyzer/Module.pv"
            struct Global* global = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Global));
            #line 325 "src/analyzer/Module.pv"
            *global = (struct Global) {
                .name = global_name,
                .module = self,
                .token_start = token_start,
                .token_end = token_end,
                .is_const = is_const,
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
                .value = 0,
            };
            #line 334 "src/analyzer/Module.pv"
            HashMap_str_ref_Global__insert(&self->globals, global_name->value, global);
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 336 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 338 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 339 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 343 "src/analyzer/Module.pv"
    return result;
}

#line 346 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 347 "src/analyzer/Module.pv"
    bool success = true;

    #line 349 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 349 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 349 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 350 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 353 "src/analyzer/Module.pv"
    return success;
}

#line 356 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 357 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 358 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 359 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 360 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 362 "src/analyzer/Module.pv"
    if (path->root) {
        #line 363 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 365 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 368 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 369 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 370 "src/analyzer/Module.pv"
        return false;
    }

    #line 373 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 373 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 373 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 374 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 375 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 376 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 377 "src/analyzer/Module.pv"
            return false;
        }

        #line 380 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 383 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 385 "src/analyzer/Module.pv"
    return true;
}

#line 388 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 389 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 390 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 391 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 392 "src/analyzer/Module.pv"
    if (blank_generics == 0) {
        #line 392 "src/analyzer/Module.pv"
        return false;
    }
    #line 393 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, allocator);

    #line 395 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 395 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 395 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 396 "src/analyzer/Module.pv"
        struct Token* func_name = func_info->name;
        #line 397 "src/analyzer/Module.pv"
        if (func_name == 0) {
            #line 397 "src/analyzer/Module.pv"
            return false;
        }
        #line 398 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 401 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 401 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 401 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 402 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 402 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 402 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 403 "src/analyzer/Module.pv"
            struct Token* enum_name = enum_info->name;
            #line 404 "src/analyzer/Module.pv"
            if (enum_name == 0) {
                #line 404 "src/analyzer/Module.pv"
                return false;
            }
            #line 405 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, enum_name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} })) {
                #line 406 "src/analyzer/Module.pv"
                Context__error_token(&self->context, enum_name, "Duplicate type with this name and generic arity");
                #line 407 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 412 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 412 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 412 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 413 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 413 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 413 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 414 "src/analyzer/Module.pv"
            struct GenericMap generics_val = GenericMap__from_generics(allocator, &struct_info->generics);
            #line 415 "src/analyzer/Module.pv"
            struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, &generics_val);
            #line 416 "src/analyzer/Module.pv"
            if (generics == 0) {
                #line 416 "src/analyzer/Module.pv"
                return false;
            }
            #line 417 "src/analyzer/Module.pv"
            generics->self_type = blank_generics->self_type;

            #line 419 "src/analyzer/Module.pv"
            struct Token* struct_name = struct_info->name;
            #line 420 "src/analyzer/Module.pv"
            if (struct_name == 0) {
                #line 420 "src/analyzer/Module.pv"
                return false;
            }
            #line 421 "src/analyzer/Module.pv"
            if (!Namespace__add_type(namespace, struct_name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} })) {
                #line 422 "src/analyzer/Module.pv"
                Context__error_token(&self->context, struct_name, "Duplicate type with this name and generic arity");
                #line 423 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 428 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 428 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 428 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 429 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 429 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 429 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 430 "src/analyzer/Module.pv"
            struct Token* trait_name = trait_info->name;
            #line 431 "src/analyzer/Module.pv"
            if (trait_name == 0) {
                #line 431 "src/analyzer/Module.pv"
                return false;
            }
            #line 432 "src/analyzer/Module.pv"
            if (!Namespace__add_trait(namespace, trait_name->value, trait_info)) {
                #line 433 "src/analyzer/Module.pv"
                Context__error_token(&self->context, trait_name, "Duplicate trait with this name and generic arity");
                #line 434 "src/analyzer/Module.pv"
                return false;
            }
        } }
    } }

    #line 439 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 439 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 439 "src/analyzer/Module.pv"
        struct str name = HashMapIter_str_ref_Global__value(&__iter)->_0;
        #line 439 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 440 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&self->global_types, name, (struct Type) { .type = TYPE__GLOBAL, .global_value = global });
    } }

    #line 443 "src/analyzer/Module.pv"
    return true;
}

#line 446 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 447 "src/analyzer/Module.pv"
    bool success = true;

    #line 449 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 449 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 449 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 450 "src/analyzer/Module.pv"
        if (str__Eq_str__eq(&namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 451 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 452 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 454 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 456 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 457 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 458 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 460 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 461 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 463 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") }, 0);
            #line 464 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 465 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 468 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 471 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 472 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 476 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 476 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 476 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 477 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 477 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 477 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 478 "src/analyzer/Module.pv"
            success = Enum__prefill_types(enum_info) && success;
        } }
    } }

    #line 482 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 482 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 482 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 483 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 483 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 483 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 484 "src/analyzer/Module.pv"
            success = Struct__prefill_types(struct_info) && success;
        } }
    } }

    #line 488 "src/analyzer/Module.pv"
    return success;
}

#line 491 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 492 "src/analyzer/Module.pv"
    bool success = true;
    #line 493 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 495 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 495 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 495 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 496 "src/analyzer/Module.pv"
        if (!Impl__prefill_types(impl_info)) {
            #line 497 "src/analyzer/Module.pv"
            success = false;
            #line 498 "src/analyzer/Module.pv"
            continue;
        }

        #line 501 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 502 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 502 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 503 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 504 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 504 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 505 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 507 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = trait_info} };
                #line 508 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 510 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 510 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 511 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 512 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 512 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), (struct tuple_ref_Trait_ref_Type) { ._0 = trait_info, ._1 = &impl_info->trait_type });
                }
                #line 513 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 514 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = trait_info} };
                #line 515 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 517 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 517 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 518 "src/analyzer/Module.pv"
                if (primitive_info == 0) {
                    #line 518 "src/analyzer/Module.pv"
                    return false;
                }
                #line 519 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 520 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 521 "src/analyzer/Module.pv"
                    struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
                    #line 522 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, trait_key, trait_info);
                }
                #line 524 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 526 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 526 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 527 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 528 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 529 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 529 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 530 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 532 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 532 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 533 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 534 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 535 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 535 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 536 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 538 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 538 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 539 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 540 "src/analyzer/Module.pv"
                struct Trait* trait_info = impl_info->trait_;
                #line 541 "src/analyzer/Module.pv"
                if (trait_info != 0) {
                    #line 541 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator }), trait_info);
                }
                #line 542 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 544 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 545 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info));
                #line 546 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 548 "src/analyzer/Module.pv"
            default: {
                #line 548 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->token, "TODO: Currently unimplemented");
            } break;
        }
    } }

    #line 552 "src/analyzer/Module.pv"
    return success;
}

#line 555 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 556 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 556 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 556 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 557 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 561 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&self->enums);
    #line 561 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 561 "src/analyzer/Module.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 562 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 562 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 562 "src/analyzer/Module.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 563 "src/analyzer/Module.pv"
            Enum__fill_variants(enum_info);
        } }
    } }

    #line 567 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&self->structs);
    #line 567 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 567 "src/analyzer/Module.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 568 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 568 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 568 "src/analyzer/Module.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 569 "src/analyzer/Module.pv"
            Struct__fill_types(struct_info);
        } }
    } }

    #line 573 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 573 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 573 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 574 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 574 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 574 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 575 "src/analyzer/Module.pv"
            struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
            #line 576 "src/analyzer/Module.pv"
            Trait__fill_types(trait_info, parent);

            #line 579 "src/analyzer/Module.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 579 "src/analyzer/Module.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 579 "src/analyzer/Module.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 580 "src/analyzer/Module.pv"
                Function__fill_types(func_info, &trait_info->generics);
            } }
        } }
    } }

    #line 585 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 585 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 585 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 586 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 587 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 587 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 588 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 590 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 590 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 590 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 591 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 595 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 595 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 595 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 596 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 597 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 599 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 599 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 599 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 600 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 604 "src/analyzer/Module.pv"
    return true;
}

#line 607 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self) {
    #line 608 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 608 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 608 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 609 "src/analyzer/Module.pv"
        Global__parse_types(global);
    } }

    #line 612 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 612 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 612 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 613 "src/analyzer/Module.pv"
        Impl__parse_consts(impl_info);
    } }

    #line 616 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 616 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 616 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 617 "src/analyzer/Module.pv"
        Impl__parse_typedefs(impl_info);
    } }

    #line 620 "src/analyzer/Module.pv"
    return true;
}

#line 623 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 624 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 626 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 626 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 626 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 627 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 628 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 631 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 631 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 631 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 632 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 633 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 633 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 634 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 636 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 639 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&self->traits);
    #line 639 "src/analyzer/Module.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 639 "src/analyzer/Module.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 640 "src/analyzer/Module.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 640 "src/analyzer/Module.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 640 "src/analyzer/Module.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 641 "src/analyzer/Module.pv"
            Trait__parse_functions(trait_info);
        } }
    } }

    #line 645 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 645 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 645 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 646 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 649 "src/analyzer/Module.pv"
    return true;
}

#line 652 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name, uintptr_t arity) {
    #line 653 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 654 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 654 "src/analyzer/Module.pv"
        return type;
    }

    #line 656 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name, arity);
    #line 657 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 657 "src/analyzer/Module.pv"
        return type;
    }

    #line 659 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 659 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 659 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 660 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name, arity);
        #line 661 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 661 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 664 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name, arity);
    #line 665 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 665 "src/analyzer/Module.pv"
        return type;
    }

    #line 667 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 667 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 667 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 668 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 669 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 669 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 672 "src/analyzer/Module.pv"
    return 0;
}

#line 675 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name, uintptr_t arity) {
    #line 676 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name, arity);
    #line 677 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 677 "src/analyzer/Module.pv"
        return type;
    }

    #line 679 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name, arity);
    #line 680 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 680 "src/analyzer/Module.pv"
        return type;
    }

    #line 682 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 682 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 682 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 683 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name, arity);
        #line 684 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 684 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 687 "src/analyzer/Module.pv"
    return 0;
}

#line 690 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 691 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 692 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 692 "src/analyzer/Module.pv"
        return type;
    }

    #line 694 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 695 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 695 "src/analyzer/Module.pv"
        return type;
    }

    #line 697 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 697 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 697 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 698 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 699 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 699 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 702 "src/analyzer/Module.pv"
    return 0;
}

#line 705 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 706 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->global_types, &name);
    #line 707 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 707 "src/analyzer/Module.pv"
        return type;
    }

    #line 709 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 709 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 709 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 710 "src/analyzer/Module.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 710 "src/analyzer/Module.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 710 "src/analyzer/Module.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 711 "src/analyzer/Module.pv"
            type = HashMap_str_Type__find(&module->global_types, &name);
            #line 712 "src/analyzer/Module.pv"
            if (type != 0) {
                #line 712 "src/analyzer/Module.pv"
                return type;
            }
        } }
    } }

    #line 716 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 716 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 716 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 717 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->values, &name);
        #line 718 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 718 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 721 "src/analyzer/Module.pv"
    return 0;
}

#line 724 "src/analyzer/Module.pv"
int64_t* Module__find_macro_value(struct Module* self, struct str name) {
    #line 725 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 725 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 725 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 726 "src/analyzer/Module.pv"
        int64_t* value = HashMap_str_i64__find(&include->macro_values, &name);
        #line 727 "src/analyzer/Module.pv"
        if (value != 0) {
            #line 727 "src/analyzer/Module.pv"
            return value;
        }
    } }
    #line 729 "src/analyzer/Module.pv"
    return 0;
}

#line 732 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 733 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name, usage_types->length);
    #line 734 "src/analyzer/Module.pv"
    if (type == 0) {
        #line 734 "src/analyzer/Module.pv"
        return 0;
    }
    #line 735 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 738 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 739 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 740 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &name);
}
