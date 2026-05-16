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
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Type.h>
#include <std/Array_Scope.h>
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
        .enums = HashMap_str_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_str_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_str_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impls = Array_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .type_impls = Array_TypeImpl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .includes = HashMap_str_ref_Include__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .globals = HashMap_str_ref_Global__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .global_types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .tests = Array_TestInfo__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .context = (struct Context) { .allocator = allocator, .base_path = (struct str) { .ptr = 0, .length = 0 }, .path = (struct str) { .ptr = 0, .length = 0 }, .pos = 0, .tokens = 0, .length = 0, .offset = 0, .analysis = 0, .type_self = 0, .pointer_const_char = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 } }, .types = (struct HashMap_str_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .scopes = (struct Array_Scope) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .module = 0, .root = 0, .function = 0 },
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
    struct HashMap_str_Enum* enums = &self->enums;
    #line 71 "src/analyzer/Module.pv"
    struct HashMap_str_Struct* structs = &self->structs;
    #line 72 "src/analyzer/Module.pv"
    struct HashMap_str_Trait* traits = &self->traits;
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
                Include__process(include);
                #line 155 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(includes, path->value, include);
            }

            #line 158 "src/analyzer/Module.pv"
            if (HashMap_str_ref_Include__find(&self->includes, &path->value) == 0) {
                #line 159 "src/analyzer/Module.pv"
                HashMap_str_ref_Include__insert(&self->includes, path->value, include);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "enum")) {
            #line 162 "src/analyzer/Module.pv"
            struct Enum node = Enum__parse(context);

            #line 164 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 165 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 167 "src/analyzer/Module.pv"
                HashMap_str_Enum__insert(enums, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "struct")) {
            #line 170 "src/analyzer/Module.pv"
            struct Struct node = Struct__parse(self);

            #line 172 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 173 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 175 "src/analyzer/Module.pv"
                HashMap_str_Struct__insert(structs, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "impl")) {
            #line 178 "src/analyzer/Module.pv"
            struct Impl node = Impl__parse(context);

            #line 180 "src/analyzer/Module.pv"
            if (node.token_start == node.token_end) {
                #line 181 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 183 "src/analyzer/Module.pv"
                Array_Impl__append(impls, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "trait")) {
            #line 186 "src/analyzer/Module.pv"
            struct Trait node = Trait__parse(self);

            #line 188 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 189 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 191 "src/analyzer/Module.pv"
                HashMap_str_Trait__insert(traits, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "fn") || Token__eq(token, TOKEN_TYPE__KEYWORD, "co")) {
            #line 194 "src/analyzer/Module.pv"
            struct Function node = Function__parse(context);

            #line 196 "src/analyzer/Module.pv"
            if (node.name == 0) {
                #line 197 "src/analyzer/Module.pv"
                result = false;
            } else {
                #line 199 "src/analyzer/Module.pv"
                HashMap_str_Function__insert(functions, node.name->value, node);
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "test")) {
            #line 202 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "test")) {
                #line 202 "src/analyzer/Module.pv"
                return false;
            }

            #line 204 "src/analyzer/Module.pv"
            struct Token* description = Context__expect(context, TOKEN_TYPE__STRING);
            #line 205 "src/analyzer/Module.pv"
            if (description == 0) {
                #line 205 "src/analyzer/Module.pv"
                return false;
            }

            #line 207 "src/analyzer/Module.pv"
            struct String name_str = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 210 "src/analyzer/Module.pv"
            struct String ns_prefix = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
            #line 211 "src/analyzer/Module.pv"
            struct Namespace* cur_ns = self->namespace;
            #line 212 "src/analyzer/Module.pv"
            while (cur_ns->parent != 0) {
                #line 213 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, (struct str){ .ptr = "__", .length = strlen("__") });
                #line 214 "src/analyzer/Module.pv"
                String__prepend(&ns_prefix, cur_ns->name);
                #line 215 "src/analyzer/Module.pv"
                cur_ns = cur_ns->parent;
            }
            #line 217 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "test_", .length = strlen("test_") });
            #line 218 "src/analyzer/Module.pv"
            String__append_string(&name_str, &ns_prefix);
            #line 221 "src/analyzer/Module.pv"
            struct str mod_path = self->path;
            #line 222 "src/analyzer/Module.pv"
            intptr_t last_sep = -1;
            #line 223 "src/analyzer/Module.pv"
            uintptr_t pi = 0;
            #line 224 "src/analyzer/Module.pv"
            while (pi < mod_path.length) {
                #line 225 "src/analyzer/Module.pv"
                char pch = mod_path.ptr[pi];
                #line 226 "src/analyzer/Module.pv"
                if (pch == '/' || pch == '\\') {
                    #line 226 "src/analyzer/Module.pv"
                    last_sep = (intptr_t)(pi);
                }
                #line 227 "src/analyzer/Module.pv"
                pi += 1;
            }
            #line 229 "src/analyzer/Module.pv"
            uintptr_t stem_start = 0;
            #line 230 "src/analyzer/Module.pv"
            if (last_sep >= 0) {
                #line 230 "src/analyzer/Module.pv"
                stem_start = (uintptr_t)(last_sep) + 1;
            }
            #line 231 "src/analyzer/Module.pv"
            uintptr_t stem_end = mod_path.length;
            #line 232 "src/analyzer/Module.pv"
            if (stem_end >= 3 && str__eq(str__slice(mod_path, stem_end - 3, stem_end), (struct str){ .ptr = ".pv", .length = strlen(".pv") })) {
                #line 233 "src/analyzer/Module.pv"
                stem_end = stem_end - 3;
            }
            #line 235 "src/analyzer/Module.pv"
            String__append(&name_str, str__slice(mod_path, stem_start, stem_end));
            #line 236 "src/analyzer/Module.pv"
            String__append(&name_str, (struct str){ .ptr = "__", .length = strlen("__") });
            #line 239 "src/analyzer/Module.pv"
            struct str desc_raw = str__slice(description->value, 1, description->value.length - 1);
            #line 240 "src/analyzer/Module.pv"
            uintptr_t di = 0;
            #line 241 "src/analyzer/Module.pv"
            while (di < desc_raw.length) {
                #line 242 "src/analyzer/Module.pv"
                char dch = desc_raw.ptr[di];
                #line 243 "src/analyzer/Module.pv"
                if ((dch >= 'a' && dch <= 'z') || (dch >= 'A' && dch <= 'Z') || (dch >= '0' && dch <= '9')) {
                    #line 244 "src/analyzer/Module.pv"
                    String__append(&name_str, str__slice(desc_raw, di, di + 1));
                } else {
                    #line 246 "src/analyzer/Module.pv"
                    String__append(&name_str, (struct str){ .ptr = "_", .length = strlen("_") });
                }
                #line 248 "src/analyzer/Module.pv"
                di += 1;
            }

            #line 251 "src/analyzer/Module.pv"
            struct Token name_token_val = (struct Token) {
                .type = TOKEN_TYPE__IDENTIFIER,
                .value = String__as_str(&name_str),
                .start_line = 0,
                .start_column = 0,
                .end_line = 0,
                .end_column = 0,
            };
            #line 259 "src/analyzer/Module.pv"
            struct Token* name_token = ArenaAllocator__store_Token(allocator, &name_token_val);

            #line 261 "src/analyzer/Module.pv"
            if (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
                #line 262 "src/analyzer/Module.pv"
                Context__error_token(context, description, "Expected { after test description");
                #line 263 "src/analyzer/Module.pv"
                return false;
            }

            #line 266 "src/analyzer/Module.pv"
            struct Function node = Function__new(context);
            #line 267 "src/analyzer/Module.pv"
            node.name = name_token;
            #line 268 "src/analyzer/Module.pv"
            node.type = FUNCTION_TYPE__TEST;
            #line 269 "src/analyzer/Module.pv"
            node.declaration_start = context->pos;
            #line 270 "src/analyzer/Module.pv"
            node.declaration_end = context->pos;
            #line 271 "src/analyzer/Module.pv"
            node.token_start = context->pos;

            #line 273 "src/analyzer/Module.pv"
            if (!Context__skip_brackets(context, "{", "}")) {
                #line 273 "src/analyzer/Module.pv"
                return false;
            }
            #line 274 "src/analyzer/Module.pv"
            node.token_end = context->pos;

            #line 276 "src/analyzer/Module.pv"
            Array_TestInfo__append(&self->tests, (struct TestInfo) { .description = description, .func_name = String__as_str(&name_str) });
            #line 277 "src/analyzer/Module.pv"
            HashMap_str_Function__insert(functions, name_token->value, node);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "const") || Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 279 "src/analyzer/Module.pv"
            bool is_const = Token__eq(token, TOKEN_TYPE__KEYWORD, "const");
            #line 280 "src/analyzer/Module.pv"
            Context__next_token(context);
            #line 281 "src/analyzer/Module.pv"
            struct Token* global_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 282 "src/analyzer/Module.pv"
            if (global_name == 0) {
                #line 282 "src/analyzer/Module.pv"
                return false;
            }

            #line 284 "src/analyzer/Module.pv"
            uintptr_t token_start = context->pos;

            #line 286 "src/analyzer/Module.pv"
            while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 287 "src/analyzer/Module.pv"
                Context__next_token(context);
            }
            #line 289 "src/analyzer/Module.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 289 "src/analyzer/Module.pv"
                return false;
            }
            #line 290 "src/analyzer/Module.pv"
            uintptr_t token_end = context->pos;

            #line 292 "src/analyzer/Module.pv"
            struct Global* global = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Global));
            #line 293 "src/analyzer/Module.pv"
            *global = (struct Global) {
                .name = global_name,
                .module = self,
                .token_start = token_start,
                .token_end = token_end,
                .is_const = is_const,
                .type = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
                .value = 0,
            };
            #line 302 "src/analyzer/Module.pv"
            HashMap_str_ref_Global__insert(&self->globals, global_name->value, global);
        } else if (token->type == TOKEN_TYPE__COMMENT) {
            #line 304 "src/analyzer/Module.pv"
            Context__next_token(context);
        } else {
            #line 306 "src/analyzer/Module.pv"
            Context__error_token(context, token, "Unexpected token, expected include, fn, co, impl, struct or trait");
            #line 307 "src/analyzer/Module.pv"
            result = false;
        }
    }

    #line 311 "src/analyzer/Module.pv"
    return result;
}

#line 314 "src/analyzer/Module.pv"
bool Module__add_use_namespaces(struct Module* self) {
    #line 315 "src/analyzer/Module.pv"
    bool success = true;

    #line 317 "src/analyzer/Module.pv"
    { struct Iter_ref_NamespacePath __iter = Array_NamespacePath__iter(&self->use_namespaces);
    #line 317 "src/analyzer/Module.pv"
    while (Iter_ref_NamespacePath__next(&__iter)) {
        #line 317 "src/analyzer/Module.pv"
        struct NamespacePath* path = Iter_ref_NamespacePath__value(&__iter);

        #line 318 "src/analyzer/Module.pv"
        success = Module__add_use_namespace(self, path) && success;
    } }

    #line 321 "src/analyzer/Module.pv"
    return success;
}

#line 324 "src/analyzer/Module.pv"
bool Module__add_use_namespace(struct Module* self, struct NamespacePath* path) {
    #line 325 "src/analyzer/Module.pv"
    struct Iter_ref_ref_Token parts_iter = Array_ref_Token__iter(&path->parts);
    #line 326 "src/analyzer/Module.pv"
    Iter_ref_ref_Token__next(&parts_iter);
    #line 327 "src/analyzer/Module.pv"
    struct Token* first_part = *Iter_ref_ref_Token__value(&parts_iter);
    #line 328 "src/analyzer/Module.pv"
    struct Namespace* namespace = 0;

    #line 330 "src/analyzer/Module.pv"
    if (path->root) {
        #line 331 "src/analyzer/Module.pv"
        namespace = Root__find_namespace(self->root, first_part->value);
    } else {
        #line 333 "src/analyzer/Module.pv"
        namespace = Namespace__find_namespace(self->namespace, first_part->value);
    }

    #line 336 "src/analyzer/Module.pv"
    if (namespace == 0) {
        #line 337 "src/analyzer/Module.pv"
        Context__error_token(&self->context, first_part, "Unable to find namespace");
        #line 338 "src/analyzer/Module.pv"
        return false;
    }

    #line 341 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Token __iter = parts_iter;
    #line 341 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Token__next(&__iter)) {
        #line 341 "src/analyzer/Module.pv"
        struct Token* part = *Iter_ref_ref_Token__value(&__iter);

        #line 342 "src/analyzer/Module.pv"
        struct Namespace** child = HashMap_str_ref_Namespace__find(&namespace->children, &part->value);
        #line 343 "src/analyzer/Module.pv"
        if (child == 0) {
            #line 344 "src/analyzer/Module.pv"
            Context__error_token(&self->context, part, "Unable to find namespace");
            #line 345 "src/analyzer/Module.pv"
            return false;
        }

        #line 348 "src/analyzer/Module.pv"
        namespace = *child;
    } }

    #line 351 "src/analyzer/Module.pv"
    Array_ref_Namespace__append(&self->used_namespaces, namespace);

    #line 353 "src/analyzer/Module.pv"
    return true;
}

#line 356 "src/analyzer/Module.pv"
bool Module__fill_namespace(struct Module* self) {
    #line 357 "src/analyzer/Module.pv"
    struct Namespace* namespace = self->namespace;
    #line 358 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = namespace->root->allocator;
    #line 359 "src/analyzer/Module.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 360 "src/analyzer/Module.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, allocator);

    #line 362 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 362 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 362 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 363 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->functions, func_info->name->value, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = blank_generics} });
    } }

    #line 366 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 366 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 366 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 367 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, enum_info->name->value, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = blank_generics} });
    } }

    #line 370 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 370 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 370 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 371 "src/analyzer/Module.pv"
        struct GenericMap generics_val = GenericMap__from_generics(allocator, &struct_info->generics);
        #line 372 "src/analyzer/Module.pv"
        struct GenericMap* generics = ArenaAllocator__store_GenericMap(allocator, &generics_val);
        #line 373 "src/analyzer/Module.pv"
        generics->self_type = blank_generics->self_type;

        #line 375 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&namespace->types, struct_info->name->value, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generics} });
    } }

    #line 378 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 378 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 378 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 379 "src/analyzer/Module.pv"
        HashMap_str_ref_Trait__insert(&namespace->traits, trait_info->name->value, trait_info);
    } }

    #line 382 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 382 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 382 "src/analyzer/Module.pv"
        struct str name = HashMapIter_str_ref_Global__value(&__iter)->_0;
        #line 382 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 383 "src/analyzer/Module.pv"
        HashMap_str_Type__insert(&self->global_types, name, (struct Type) { .type = TYPE__GLOBAL, .global_value = global });
    } }

    #line 386 "src/analyzer/Module.pv"
    return true;
}

#line 389 "src/analyzer/Module.pv"
bool Module__prefill_types(struct Module* self) {
    #line 390 "src/analyzer/Module.pv"
    bool success = true;

    #line 392 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 392 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 392 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 393 "src/analyzer/Module.pv"
        if (str__eq(namespace->name, (struct str){ .ptr = "std", .length = strlen("std") })) {
            #line 394 "src/analyzer/Module.pv"
            struct Generic t = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 395 "src/analyzer/Module.pv"
            t.name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "T", .length = strlen("T") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 397 "src/analyzer/Module.pv"
            struct Token* param_name = ArenaAllocator__store_Token(self->context.allocator, (struct Token[]){(struct Token) { .type = TOKEN_TYPE__STRING, .value = (struct str){ .ptr = "type", .length = strlen("type") }, .start_line = 0, .start_column = 0, .end_line = 0, .end_column = 0 }});

            #line 399 "src/analyzer/Module.pv"
            struct Array_Generic generics = Array_Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 400 "src/analyzer/Module.pv"
            Array_Generic__append(&generics, t);
            #line 401 "src/analyzer/Module.pv"
            struct Generic* generic_t = Array_Generic__get(&generics, 0);

            #line 403 "src/analyzer/Module.pv"
            struct Array_Parameter params = Array_Parameter__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context.allocator });
            #line 404 "src/analyzer/Module.pv"
            Array_Parameter__append(&params, (struct Parameter) { .name = param_name, .type = (struct Type) { .type = TYPE__GENERIC, .generic_value = generic_t } });

            #line 406 "src/analyzer/Module.pv"
            struct Type* type_id_type = Namespace__find_type(namespace, (struct str){ .ptr = "TypeId", .length = strlen("TypeId") });
            #line 407 "src/analyzer/Module.pv"
            if (type_id_type != 0) {
                #line 408 "src/analyzer/Module.pv"
                Context__insert_builtin_function(&self->context, "typeid", &generics, &params, *type_id_type);
            } else {
                #line 411 "src/analyzer/Module.pv"
                fprintf(stderr, "TypeId type not found in namespace std\n");
            }

            #line 414 "src/analyzer/Module.pv"
            Array_Parameter__release(&params);
            #line 415 "src/analyzer/Module.pv"
            Array_Generic__release(&generics);
        }
    } }

    #line 419 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 419 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 419 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 420 "src/analyzer/Module.pv"
        success = Enum__prefill_types(enum_info) && success;
    } }

    #line 423 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 423 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 423 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 424 "src/analyzer/Module.pv"
        success = Struct__prefill_types(struct_info) && success;
    } }

    #line 427 "src/analyzer/Module.pv"
    return success;
}

#line 430 "src/analyzer/Module.pv"
bool Module__prefill_types_impl(struct Module* self) {
    #line 431 "src/analyzer/Module.pv"
    bool success = true;
    #line 432 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 434 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 434 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 434 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 435 "src/analyzer/Module.pv"
        if (!Impl__prefill_types(impl_info)) {
            #line 436 "src/analyzer/Module.pv"
            success = false;
            #line 437 "src/analyzer/Module.pv"
            continue;
        }

        #line 440 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 441 "src/analyzer/Module.pv"
            case TYPE__ENUM: {
                #line 441 "src/analyzer/Module.pv"
                struct Enum* enum_info = impl_info->type.enum_value._0;
                #line 442 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 442 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&enum_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 443 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&enum_info->impls, impl_info);

                #line 445 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__ENUM, .enum_value = { ._0 = enum_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 446 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 448 "src/analyzer/Module.pv"
            case TYPE__STRUCT: {
                #line 448 "src/analyzer/Module.pv"
                struct Struct* struct_info = impl_info->type.struct_value._0;
                #line 449 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 449 "src/analyzer/Module.pv"
                    HashMap_str_tuple_ref_Trait_ref_Type__insert(&struct_info->traits, impl_info->trait_->name->value, (struct tuple_ref_Trait_ref_Type) { ._0 = impl_info->trait_, ._1 = &impl_info->trait_type });
                }
                #line 450 "src/analyzer/Module.pv"
                uintptr_t impl_index = Array_ref_Impl__append(&struct_info->impls, impl_info);
                #line 451 "src/analyzer/Module.pv"
                struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__STRUCT, .struct_value = { ._0 = struct_info, ._1 = impl_index, ._2 = impl_info->trait_} };
                #line 452 "src/analyzer/Module.pv"
                Impl__fill_types(impl_info, parent);
            } break;
            #line 454 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 454 "src/analyzer/Module.pv"
                struct Primitive* primitive_info = impl_info->type.primitive_value;
                #line 455 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 455 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&primitive_info->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 456 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&primitive_info->impls, impl_info);
            } break;
            #line 458 "src/analyzer/Module.pv"
            case TYPE__STRUCT_C: {
                #line 458 "src/analyzer/Module.pv"
                struct StructC* info = impl_info->type.structc_value;
                #line 459 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 460 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 460 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 461 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 463 "src/analyzer/Module.pv"
            case TYPE__ENUM_C: {
                #line 463 "src/analyzer/Module.pv"
                struct EnumC* info = impl_info->type.enumc_value;
                #line 464 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 465 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 465 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 466 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 468 "src/analyzer/Module.pv"
            case TYPE__TYPEDEF_C: {
                #line 468 "src/analyzer/Module.pv"
                struct TypedefC* info = impl_info->type.typedefc_value;
                #line 469 "src/analyzer/Module.pv"
                struct Primitive* ctype = Root__add_ctype(self->root, info->name.ptr);
                #line 470 "src/analyzer/Module.pv"
                if (impl_info->trait_ != 0) {
                    #line 470 "src/analyzer/Module.pv"
                    HashMap_str_ref_Trait__insert(&ctype->traits, impl_info->trait_->name->value, impl_info->trait_);
                }
                #line 471 "src/analyzer/Module.pv"
                Array_ref_Impl__append(&ctype->impls, impl_info);
            } break;
            #line 473 "src/analyzer/Module.pv"
            case TYPE__INDIRECT: {
                #line 474 "src/analyzer/Module.pv"
                Array_TypeImpl__append(&self->type_impls, TypeImpl__new(allocator, impl_info->type, impl_info));
                #line 475 "src/analyzer/Module.pv"
                self->root->hack_type_impl = Array_TypeImpl__back(&self->type_impls);
            } break;
            #line 477 "src/analyzer/Module.pv"
            default: {
                #line 477 "src/analyzer/Module.pv"
                Context__error_token(&self->context, impl_info->token, "TODO: Currently unimplemented");
            } break;
        }
    } }

    #line 481 "src/analyzer/Module.pv"
    return success;
}

#line 484 "src/analyzer/Module.pv"
bool Module__parse_declarations(struct Module* self) {
    #line 485 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 485 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 485 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 486 "src/analyzer/Module.pv"
        Function__fill_types(func_info, 0);
    } }

    #line 490 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&self->enums);
    #line 490 "src/analyzer/Module.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 490 "src/analyzer/Module.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 491 "src/analyzer/Module.pv"
        Enum__fill_variants(enum_info);
    } }

    #line 494 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&self->structs);
    #line 494 "src/analyzer/Module.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 494 "src/analyzer/Module.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 495 "src/analyzer/Module.pv"
        Struct__fill_types(struct_info);
    } }

    #line 498 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 498 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 498 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 499 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TRAIT, .trait_value = trait_info };
        #line 500 "src/analyzer/Module.pv"
        Trait__fill_types(trait_info, parent);

        #line 503 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 503 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 503 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 504 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &trait_info->generics);
        } }
    } }

    #line 508 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 508 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 508 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 509 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 510 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 510 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 511 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 513 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 513 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 513 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 514 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &impl_info->generics);
        } }
    } }

    #line 518 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 518 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 518 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 519 "src/analyzer/Module.pv"
        struct FunctionParent parent = (struct FunctionParent) { .type = FUNCTION_PARENT__TYPE, .type_value = { ._0 = &type_impl->type, ._1 = 0, ._2 = 0} };
        #line 520 "src/analyzer/Module.pv"
        Impl__fill_types(type_impl->impl_info, parent);

        #line 522 "src/analyzer/Module.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&type_impl->impl_info->functions);
        #line 522 "src/analyzer/Module.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 522 "src/analyzer/Module.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 523 "src/analyzer/Module.pv"
            Function__fill_types(func_info, &type_impl->impl_info->generics);
        } }
    } }

    #line 527 "src/analyzer/Module.pv"
    return true;
}

#line 530 "src/analyzer/Module.pv"
bool Module__parse_globals(struct Module* self) {
    #line 531 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&self->globals);
    #line 531 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Global__next(&__iter)) {
        #line 531 "src/analyzer/Module.pv"
        struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

        #line 532 "src/analyzer/Module.pv"
        Global__parse_types(global);
    } }

    #line 535 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 535 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 535 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 536 "src/analyzer/Module.pv"
        Impl__parse_consts(impl_info);
    } }

    #line 539 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 539 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 539 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 540 "src/analyzer/Module.pv"
        Impl__parse_typedefs(impl_info);
    } }

    #line 543 "src/analyzer/Module.pv"
    return true;
}

#line 546 "src/analyzer/Module.pv"
bool Module__parse_functions(struct Module* self) {
    #line 547 "src/analyzer/Module.pv"
    struct ArenaAllocator* allocator = self->namespace->root->allocator;

    #line 549 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 549 "src/analyzer/Module.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 549 "src/analyzer/Module.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 550 "src/analyzer/Module.pv"
        struct Generics generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 551 "src/analyzer/Module.pv"
        Function__parse_function(func_info, &generics);
    } }

    #line 554 "src/analyzer/Module.pv"
    { struct Iter_ref_Impl __iter = Array_Impl__iter(&self->impls);
    #line 554 "src/analyzer/Module.pv"
    while (Iter_ref_Impl__next(&__iter)) {
        #line 554 "src/analyzer/Module.pv"
        struct Impl* impl_info = Iter_ref_Impl__value(&__iter);

        #line 555 "src/analyzer/Module.pv"
        switch (impl_info->type.type) {
            #line 556 "src/analyzer/Module.pv"
            case TYPE__PRIMITIVE: {
                #line 556 "src/analyzer/Module.pv"
                continue;
            } break;
            #line 557 "src/analyzer/Module.pv"
            default: {
            } break;
        }
        #line 559 "src/analyzer/Module.pv"
        Impl__parse_functions(impl_info);
    } }

    #line 562 "src/analyzer/Module.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&self->traits);
    #line 562 "src/analyzer/Module.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 562 "src/analyzer/Module.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 563 "src/analyzer/Module.pv"
        Trait__parse_functions(trait_info);
    } }

    #line 566 "src/analyzer/Module.pv"
    { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&self->type_impls);
    #line 566 "src/analyzer/Module.pv"
    while (Iter_ref_TypeImpl__next(&__iter)) {
        #line 566 "src/analyzer/Module.pv"
        struct TypeImpl* type_impl = Iter_ref_TypeImpl__value(&__iter);

        #line 567 "src/analyzer/Module.pv"
        Impl__parse_functions(type_impl->impl_info);
    } }

    #line 570 "src/analyzer/Module.pv"
    return true;
}

#line 573 "src/analyzer/Module.pv"
struct Type* Module__find_type(struct Module* self, struct str name) {
    #line 574 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->types, &name);
    #line 575 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 575 "src/analyzer/Module.pv"
        return type;
    }

    #line 577 "src/analyzer/Module.pv"
    type = Namespace__find_type(self->namespace, name);
    #line 578 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 578 "src/analyzer/Module.pv"
        return type;
    }

    #line 580 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 580 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 580 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 581 "src/analyzer/Module.pv"
        type = Namespace__find_type(namespace, name);
        #line 582 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 582 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 585 "src/analyzer/Module.pv"
    type = Root__find_type(self->namespace->root, name);
    #line 586 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 586 "src/analyzer/Module.pv"
        return type;
    }

    #line 588 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 588 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 588 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 589 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->types, &name);
        #line 590 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 590 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 593 "src/analyzer/Module.pv"
    return 0;
}

#line 596 "src/analyzer/Module.pv"
struct Trait* Module__find_trait(struct Module* self, struct str name) {
    #line 597 "src/analyzer/Module.pv"
    struct Trait* type = Root__find_trait(self->namespace->root, name);
    #line 598 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 598 "src/analyzer/Module.pv"
        return type;
    }

    #line 600 "src/analyzer/Module.pv"
    type = Namespace__find_trait(self->namespace, name);
    #line 601 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 601 "src/analyzer/Module.pv"
        return type;
    }

    #line 603 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 603 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 603 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 604 "src/analyzer/Module.pv"
        type = Namespace__find_trait(namespace, name);
        #line 605 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 605 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 608 "src/analyzer/Module.pv"
    return 0;
}

#line 611 "src/analyzer/Module.pv"
struct Type* Module__find_function(struct Module* self, struct str name) {
    #line 612 "src/analyzer/Module.pv"
    struct Type* type = Root__find_function(self->namespace->root, name);
    #line 613 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 613 "src/analyzer/Module.pv"
        return type;
    }

    #line 615 "src/analyzer/Module.pv"
    type = Namespace__find_function(self->namespace, name);
    #line 616 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 616 "src/analyzer/Module.pv"
        return type;
    }

    #line 618 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 618 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 618 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 619 "src/analyzer/Module.pv"
        type = Namespace__find_function(namespace, name);
        #line 620 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 620 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 623 "src/analyzer/Module.pv"
    return 0;
}

#line 626 "src/analyzer/Module.pv"
struct Type* Module__find_value(struct Module* self, struct str name) {
    #line 627 "src/analyzer/Module.pv"
    struct Type* type = HashMap_str_Type__find(&self->global_types, &name);
    #line 628 "src/analyzer/Module.pv"
    if (type != 0) {
        #line 628 "src/analyzer/Module.pv"
        return type;
    }

    #line 630 "src/analyzer/Module.pv"
    { struct Iter_ref_ref_Namespace __iter = Array_ref_Namespace__iter(&self->used_namespaces);
    #line 630 "src/analyzer/Module.pv"
    while (Iter_ref_ref_Namespace__next(&__iter)) {
        #line 630 "src/analyzer/Module.pv"
        struct Namespace* namespace = *Iter_ref_ref_Namespace__value(&__iter);

        #line 631 "src/analyzer/Module.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 631 "src/analyzer/Module.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 631 "src/analyzer/Module.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 632 "src/analyzer/Module.pv"
            type = HashMap_str_Type__find(&module->global_types, &name);
            #line 633 "src/analyzer/Module.pv"
            if (type != 0) {
                #line 633 "src/analyzer/Module.pv"
                return type;
            }
        } }
    } }

    #line 637 "src/analyzer/Module.pv"
    { struct HashMapIter_str_ref_Include __iter = HashMap_str_ref_Include__iter(&self->includes);
    #line 637 "src/analyzer/Module.pv"
    while (HashMapIter_str_ref_Include__next(&__iter)) {
        #line 637 "src/analyzer/Module.pv"
        struct Include* include = HashMapIter_str_ref_Include__value(&__iter)->_1;

        #line 638 "src/analyzer/Module.pv"
        type = HashMap_str_Type__find(&include->values, &name);
        #line 639 "src/analyzer/Module.pv"
        if (type != 0) {
            #line 639 "src/analyzer/Module.pv"
            return type;
        }
    } }

    #line 642 "src/analyzer/Module.pv"
    return 0;
}

#line 645 "src/analyzer/Module.pv"
struct Type* Module__find_make_type(struct Module* self, struct str name, struct Array_Type* usage_types) {
    #line 646 "src/analyzer/Module.pv"
    struct Type* type = Module__find_type(self, name);
    #line 647 "src/analyzer/Module.pv"
    return Root__make_type_usage(self->root, type, usage_types);
}

#line 650 "src/analyzer/Module.pv"
struct Primitive* Module__find_primitive(struct Module* self, struct str name) {
    #line 651 "src/analyzer/Module.pv"
    struct HashMap_str_Primitive* primitives = &self->namespace->root->primitives;
    #line 652 "src/analyzer/Module.pv"
    return HashMap_str_Primitive__find(primitives, &name);
}
