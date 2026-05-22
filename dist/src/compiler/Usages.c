#include <string.h>
#include <stdint.h>

#include <stdio.h>

#include <std/ArenaAllocator.h>
#include <compiler/Generator.h>
#include <compiler/Usages.h>
#include <analyzer/Root.h>
#include <analyzer/Naming.h>
#include <std/trait_Allocator.h>
#include <analyzer/Namespace.h>
#include <std/str.h>
#include <std/HashMap_str_Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
#include <tuple_str_Primitive.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/types/Primitive.h>
#include <compiler/TypeUsage_Primitive.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <analyzer/Module.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <std/HashMap_str_usize.h>
#include <std/HashMap_str_Array_ref_Enum.h>
#include <std/HashMapIter_str_Array_ref_Enum.h>
#include <tuple_str_Array_ref_Enum.h>
#include <std/Array_ref_Enum.h>
#include <std/Iter_ref_ref_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/HashMap_str_Array_ref_Struct.h>
#include <std/HashMapIter_str_Array_ref_Struct.h>
#include <tuple_str_Array_ref_Struct.h>
#include <std/Array_ref_Struct.h>
#include <std/Iter_ref_ref_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/HashMap_str_Array_ref_Trait.h>
#include <std/HashMapIter_str_Array_ref_Trait.h>
#include <tuple_str_Array_ref_Trait.h>
#include <std/Array_ref_Trait.h>
#include <std/Iter_ref_ref_Trait.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/Context.h>
#include <compiler/UsageContext.h>
#include <std/String.h>
#include <analyzer/types/Global.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/ClassCpp.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <compiler/TypeUsage_Sequence.h>
#include <analyzer/types/TypeImpl.h>
#include <compiler/TypeUsage_Tuple.h>
#include <std/Iter_ref_Type.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <analyzer/types/StructField.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Iter_ref_Generic.h>
#include <analyzer/types/Generic.h>
#include <std/Range_usize.h>
#include <std/Array_UsageContext.h>
#include <compiler/FunctionContext.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <analyzer/Block.h>
#include <std/Array_Statement.h>
#include <std/Iter_ref_Statement.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/statement/ReturnStatement.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <std/Array_ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <std/Array_MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <analyzer/statement/WhileStatement.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForVariable.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/Usages.h>

#include <compiler/Usages.h>

#line 153 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 154 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 156 "src/compiler/Usages.pv"
    struct Usages self = (struct Usages) {
        .allocator = allocator,
        .generator = generator,
        .root = generator->root,
        .naming_ident = &generator->naming_ident,
        .usages = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_types = HashSet_str__new(allocator),
        .usage_traits = HashSet_str__new(allocator),
        .primitives = HashMap_usize_TypeUsage_Primitive__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_usize_TypeUsage_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_usize_TypeUsage_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_usize_TypeUsage_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .sequences = HashMap_usize_TypeUsage_Sequence__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .tuples = HashMap_usize_TypeUsage_Tuple__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") }),
        .usage_mode = USAGE_MODE__LAYOUT,
        .usage_context = 0,
        .function_context = 0,
        .active_impl_index = 0,
    };

    #line 181 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 181 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 181 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 182 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 183 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 184 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info));
            #line 185 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 189 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 191 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 192 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 193 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 194 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 196 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 197 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 197 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 197 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 198 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 198 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 198 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 198 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 199 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 199 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 199 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 199 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 200 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 200 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 200 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 200 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 201 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 201 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 201 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 201 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 202 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 202 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 202 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 203 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 203 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 203 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 204 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 207 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 210 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 212 "src/compiler/Usages.pv"
    return self;
}

#line 215 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 216 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 216 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 216 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 217 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 217 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 217 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 218 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 221 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 225 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 226 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 226 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 226 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 227 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 229 "src/compiler/Usages.pv"
        if (func_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, func_info->name->value)) {
            #line 230 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
            #line 231 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} }});
            #line 232 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 233 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
        }
    } }

    #line 237 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&module->enums);
    #line 237 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 237 "src/compiler/Usages.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 238 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 238 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 238 "src/compiler/Usages.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 239 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info));

            #line 241 "src/compiler/Usages.pv"
            if (enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, enum_info->name->value)) {
                #line 242 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 243 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} }});
                #line 244 "src/compiler/Usages.pv"
                generic_map->self_type = self_type;
                #line 245 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 250 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&module->structs);
    #line 250 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 250 "src/compiler/Usages.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 251 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 251 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 251 "src/compiler/Usages.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 252 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info));

            #line 254 "src/compiler/Usages.pv"
            if (struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, struct_info->name->value)) {
                #line 255 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 256 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} }});
                #line 257 "src/compiler/Usages.pv"
                generic_map->self_type = self_type;
                #line 258 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 263 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&module->traits);
    #line 263 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 263 "src/compiler/Usages.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 264 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 264 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 264 "src/compiler/Usages.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 265 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info));

            #line 267 "src/compiler/Usages.pv"
            if (trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, trait_info->name->value)) {
                #line 268 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 269 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} }});
                #line 270 "src/compiler/Usages.pv"
                generic_map->self_type = self_type;
                #line 271 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            }
        } }
    } }
}

#line 277 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 278 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 279 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 280 "src/compiler/Usages.pv"
    struct Type* type_deref_all = Type__deref_all(resolved_type);
    #line 281 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 282 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 283 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;

    #line 285 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 286 "src/compiler/Usages.pv"
        case TYPE__GLOBAL: {
            #line 286 "src/compiler/Usages.pv"
            struct Global* g = type_deref->global_value;
            #line 287 "src/compiler/Usages.pv"
            struct String path = Generator__make_rel_path(self->generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
            #line 288 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__BODY) {
                #line 289 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->body, String__as_str(&path), *type);
            }
            #line 291 "src/compiler/Usages.pv"
            return;
        } break;
        #line 293 "src/compiler/Usages.pv"
        case TYPE__INDIRECT: {
            #line 294 "src/compiler/Usages.pv"
            switch (type_deref_all->type) {
                #line 295 "src/compiler/Usages.pv"
                case TYPE__PRIMITIVE: {
                    #line 295 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = type_deref_all->primitive_value;
                    #line 296 "src/compiler/Usages.pv"
                    if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                        #line 297 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
                    } else {
                        #line 299 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
                    }

                    #line 302 "src/compiler/Usages.pv"
                    return;
                } break;
                #line 304 "src/compiler/Usages.pv"
                case TYPE__TRAIT: {
                    #line 304 "src/compiler/Usages.pv"
                    struct Trait* trait_info = type_deref_all->trait_value._0;
                    #line 304 "src/compiler/Usages.pv"
                    is_trait = Trait__has_dynamic_dispatch(trait_info);
                } break;
                #line 305 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 308 "src/compiler/Usages.pv"
        case TYPE__PRIMITIVE: {
            #line 308 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = type_deref->primitive_value;
            #line 309 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                #line 310 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
            } else {
                #line 312 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
            }
        } break;
        #line 315 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 315 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 316 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 316 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 317 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 317 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 317 "src/compiler/Usages.pv"
            struct GenericMap* type_generic_map = type_deref->function_value._1;
            #line 318 "src/compiler/Usages.pv"
            is_type = func_info->type != FUNCTION_TYPE__BUILTIN && func_info->generics.array.length > 0;

            #line 320 "src/compiler/Usages.pv"
            switch (func_info->parent.type) {
                #line 321 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__NONE: {
                    #line 322 "src/compiler/Usages.pv"
                    is_type = (func_info->type == FUNCTION_TYPE__STANDARD || func_info->type == FUNCTION_TYPE__COROUTINE) && func_info->name != 0;
                } break;
                #line 324 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 324 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                    #line 325 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }}, generic_map);
                    #line 326 "src/compiler/Usages.pv"
                    is_type = true;
                } break;
                #line 328 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 328 "src/compiler/Usages.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 329 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 331 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 331 "src/compiler/Usages.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 332 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 334 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TRAIT: {
                    #line 334 "src/compiler/Usages.pv"
                    struct Trait* trait_info = func_info->parent.trait_value;
                    #line 335 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 337 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 337 "src/compiler/Usages.pv"
                    struct Type* type_info = func_info->parent.type_value._0;
                    #line 338 "src/compiler/Usages.pv"
                    Usages__add_type(self, type_info, type_generic_map);
                } break;
            }
        } break;
        #line 342 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 342 "src/compiler/Usages.pv"
            struct Trait* trait_info = type_deref->trait_value._0;
            #line 342 "src/compiler/Usages.pv"
            is_trait = Trait__has_dynamic_dispatch(trait_info);
        } break;
        #line 343 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 343 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 344 "src/compiler/Usages.pv"
            switch (sequence->type.type) {
                #line 345 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 345 "src/compiler/Usages.pv"
                    struct Expression* expression = sequence->type.fixedarray_value;
                    #line 346 "src/compiler/Usages.pv"
                    Usages__process_expression(self, expression, generic_map);
                } break;
                #line 348 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__SLICE: {
                    #line 349 "src/compiler/Usages.pv"
                    is_type = Sequence__is_slice(sequence);
                    #line 350 "src/compiler/Usages.pv"
                    type = Type__deref(type);
                    #line 351 "src/compiler/Usages.pv"
                    resolved_type = type_deref;
                } break;
            }
        } break;
        #line 355 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 355 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 356 "src/compiler/Usages.pv"
        case TYPE__STRUCT_C: {
            #line 356 "src/compiler/Usages.pv"
            struct StructC* struct_c = type_deref->structc_value;
            #line 356 "src/compiler/Usages.pv"
            is_type = !struct_c->include->mode_cpp;
        } break;
        #line 357 "src/compiler/Usages.pv"
        case TYPE__UNION_C: {
            #line 357 "src/compiler/Usages.pv"
            struct StructC* union_c = type_deref->unionc_value;
            #line 357 "src/compiler/Usages.pv"
            is_type = !union_c->include->mode_cpp;
        } break;
        #line 358 "src/compiler/Usages.pv"
        case TYPE__ENUM_C: {
            #line 358 "src/compiler/Usages.pv"
            struct EnumC* enum_c = type_deref->enumc_value;
            #line 358 "src/compiler/Usages.pv"
            is_type = !enum_c->include->mode_cpp;
        } break;
        #line 359 "src/compiler/Usages.pv"
        case TYPE__UNKNOWN_C: {
            #line 359 "src/compiler/Usages.pv"
            struct UnknownC* unknown_c = type_deref->unknownc_value;
            #line 359 "src/compiler/Usages.pv"
            is_type = unknown_c->include != 0;
        } break;
        #line 360 "src/compiler/Usages.pv"
        case TYPE__FUNCTION_C: {
            #line 360 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 361 "src/compiler/Usages.pv"
        case TYPE__TYPEDEF_C: {
            #line 361 "src/compiler/Usages.pv"
            struct TypedefC* typedef_c = type_deref->typedefc_value;
            #line 361 "src/compiler/Usages.pv"
            is_type = !typedef_c->include->mode_cpp;
        } break;
        #line 362 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 362 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 363 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY) {
                #line 364 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->cpp_usages, class_info->name, *type);
            } else {
                #line 366 "src/compiler/Usages.pv"
                is_type = class_info->include->mode_cpp;
            }
        } break;
        #line 369 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 372 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 372 "src/compiler/Usages.pv"
        return;
    }

    #line 374 "src/compiler/Usages.pv"
    struct String type_name_generic = Naming__get_type_name(self->naming_ident, type, generic_map->self_type, generic_map);

    #line 376 "src/compiler/Usages.pv"
    switch (self->usage_mode) {
        #line 377 "src/compiler/Usages.pv"
        case USAGE_MODE__LAYOUT: {
            #line 377 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->layout, String__as_str(&type_name_generic), *type);
        } break;
        #line 378 "src/compiler/Usages.pv"
        case USAGE_MODE__SIGNATURE: {
            #line 378 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->signature, String__as_str(&type_name_generic), *type);
        } break;
        #line 379 "src/compiler/Usages.pv"
        case USAGE_MODE__BODY: {
            #line 379 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->body, String__as_str(&type_name_generic), *type);
        } break;
    }

    #line 382 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 382 "src/compiler/Usages.pv"
        return;
    }

    #line 384 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref_all, generic_map->self_type, generic_map);
    #line 385 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 387 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 388 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 389 "src/compiler/Usages.pv"
        return;
    }

    #line 392 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref_all);
}

#line 395 "src/compiler/Usages.pv"
void Usages__process_impls(struct Usages* self, struct Array_ref_Impl* impls, struct GenericMap* generic_map) {
    #line 396 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 398 "src/compiler/Usages.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 398 "src/compiler/Usages.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 398 "src/compiler/Usages.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 398 "src/compiler/Usages.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 399 "src/compiler/Usages.pv"
        self->active_impl_index = impl_index;

        #line 401 "src/compiler/Usages.pv"
        if (impl_info->has_trait) {
            #line 402 "src/compiler/Usages.pv"
            Usages__add_type(self, &impl_info->trait_type, generic_map);

            #line 404 "src/compiler/Usages.pv"
            if (impl_info->trait_ != 0 && !Trait__has_dynamic_dispatch(impl_info->trait_)) {
                #line 405 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 405 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 405 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 406 "src/compiler/Usages.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 406 "src/compiler/Usages.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 406 "src/compiler/Usages.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 407 "src/compiler/Usages.pv"
                        Usages__add_type(self, &param->type, generic_map);
                    } }
                    #line 409 "src/compiler/Usages.pv"
                    Usages__add_type(self, &func_info->return_type, generic_map);
                } }
            }
        }

        #line 414 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 414 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 414 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 415 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 415 "src/compiler/Usages.pv"
                continue;
            }
            #line 416 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }

        #line 419 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 420 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 421 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 421 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 421 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 421 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 422 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 422 "src/compiler/Usages.pv"
                    continue;
                }
                #line 423 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            } }
        }
    } }

    #line 428 "src/compiler/Usages.pv"
    self->active_impl_index = 0;
}

#line 431 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 432 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
    #line 433 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});

    #line 435 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 436 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 437 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Primitive__add_usage(parent_usage, generic_map);
    #line 438 "src/compiler/Usages.pv"
    UsageContext__populate_impls(self->usage_context, self->allocator, &primitive_info->impls);

    #line 440 "src/compiler/Usages.pv"
    Usages__process_impls(self, &primitive_info->impls, generic_map);

    #line 442 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 445 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 446 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 447 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 448 "src/compiler/Usages.pv"
    GenericMap__insert(generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 449 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 450 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type }});
    #line 451 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});

    #line 453 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(sequence);
    #line 454 "src/compiler/Usages.pv"
    struct TypeUsage_Sequence* parent_usage = HashMap_usize_TypeUsage_Sequence__find(&self->sequences, &parent_ptr);
    #line 455 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 456 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Sequence__insert(&self->sequences, parent_ptr, TypeUsage_Sequence__new(self->allocator, sequence));
    }
    #line 458 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Sequence__add_usage(parent_usage, generic_map);

    #line 460 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, generic_map);

    #line 462 "src/compiler/Usages.pv"
    if (self->std_namespace != 0) {
        #line 463 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 464 "src/compiler/Usages.pv"
        struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
        #line 465 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, (struct Array_Type[]){(struct Array_Type) { .data = &element_reference, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
        #line 466 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 469 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 471 "src/compiler/Usages.pv"
    switch (Type__deref_all(&sequence->element)->type) {
        #line 472 "src/compiler/Usages.pv"
        case TYPE__GENERIC: {
        } break;
        #line 473 "src/compiler/Usages.pv"
        case TYPE__GENERIC_TYPEDEF: {
        } break;
        #line 474 "src/compiler/Usages.pv"
        default: {
            #line 475 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 475 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 475 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 476 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            } }
        } break;
    }

    #line 481 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 484 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 485 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 486 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 487 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 489 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(tuple);
    #line 490 "src/compiler/Usages.pv"
    struct TypeUsage_Tuple* parent_usage = HashMap_usize_TypeUsage_Tuple__find(&self->tuples, &parent_ptr);
    #line 491 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 492 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Tuple__insert(&self->tuples, parent_ptr, TypeUsage_Tuple__new(self->allocator, tuple));
    }
    #line 494 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Tuple__add_usage(parent_usage, generic_map);
    #line 495 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 497 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type }});
    #line 498 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});

    #line 500 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
    #line 500 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 500 "src/compiler/Usages.pv"
        struct Type* element = Iter_ref_Type__value(&__iter);

        #line 501 "src/compiler/Usages.pv"
        Usages__add_type(self, element, generic_map);
    } }

    #line 504 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 507 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 508 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 509 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 510 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Struct__add_usage(parent_usage, generic_map);
    #line 511 "src/compiler/Usages.pv"
    UsageContext__populate_impls(self->usage_context, self->allocator, &struct_info->impls);
    #line 512 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 514 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 514 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 514 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 515 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);

        #line 517 "src/compiler/Usages.pv"
        switch (Type__deref_all(&field->type)->type) {
            #line 518 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 518 "src/compiler/Usages.pv"
                struct Function* param_func_info = Type__deref_all(&field->type)->function_value._0;
                #line 518 "src/compiler/Usages.pv"
                struct GenericMap* param_generic_map = Type__deref_all(&field->type)->function_value._1;
                #line 519 "src/compiler/Usages.pv"
                struct GenericMap resolved_generic_map = GenericMap__resolve_types(param_generic_map, self->allocator, generic_map);

                #line 521 "src/compiler/Usages.pv"
                { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&param_func_info->parameters);
                #line 521 "src/compiler/Usages.pv"
                while (Iter_ref_Parameter__next(&__iter)) {
                    #line 521 "src/compiler/Usages.pv"
                    struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                    #line 522 "src/compiler/Usages.pv"
                    Usages__add_type(self, &param->type, &resolved_generic_map);
                } }
                #line 524 "src/compiler/Usages.pv"
                Usages__add_type(self, &param_func_info->return_type, &resolved_generic_map);
            } break;
            #line 526 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 526 "src/compiler/Usages.pv"
                struct Sequence* sequence = Type__deref_all(&field->type)->sequence_value;
                #line 527 "src/compiler/Usages.pv"
                if (Sequence__is_fixed_array(sequence)) {
                    #line 528 "src/compiler/Usages.pv"
                    Usages__add_type(self, &sequence->element, generic_map);
                }
            } break;
            #line 531 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }

    #line 535 "src/compiler/Usages.pv"
    Usages__process_impls(self, &struct_info->impls, generic_map);

    #line 537 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 540 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 541 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 542 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 543 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Enum__add_usage(parent_usage, generic_map);
    #line 544 "src/compiler/Usages.pv"
    UsageContext__populate_impls(self->usage_context, self->allocator, &enum_info->impls);

    #line 546 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 548 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 548 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 548 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 549 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 549 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 549 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 550 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 554 "src/compiler/Usages.pv"
    Usages__process_impls(self, &enum_info->impls, generic_map);

    #line 556 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 559 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 560 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(trait_info);
    #line 561 "src/compiler/Usages.pv"
    struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
    #line 562 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Trait__add_usage(parent_usage, generic_map);
    #line 563 "src/compiler/Usages.pv"
    UsageContext__populate_trait_functions(self->usage_context, self->allocator, trait_info);

    #line 565 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 565 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 565 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 566 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }

    #line 569 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 572 "src/compiler/Usages.pv"
bool Usages__usage_context_matches(struct UsageContext* uc, struct Generics* generics, struct GenericMap* generic_map) {
    #line 573 "src/compiler/Usages.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&generics->array);
    #line 573 "src/compiler/Usages.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 573 "src/compiler/Usages.pv"
        struct Generic generic = *Iter_ref_Generic__value(&__iter);

        #line 574 "src/compiler/Usages.pv"
        struct Type* parent_v = GenericMap__get(uc->generic_map, generic.name->value);
        #line 575 "src/compiler/Usages.pv"
        struct Type* func_v = GenericMap__get(generic_map, generic.name->value);
        #line 576 "src/compiler/Usages.pv"
        if (parent_v == 0 || func_v == 0) {
            #line 576 "src/compiler/Usages.pv"
            return false;
        }
        #line 577 "src/compiler/Usages.pv"
        struct Type parent_t = *parent_v;
        #line 578 "src/compiler/Usages.pv"
        if (!Type__eq(&parent_t, func_v)) {
            #line 578 "src/compiler/Usages.pv"
            return false;
        }
    } }
    #line 580 "src/compiler/Usages.pv"
    return true;
}

#line 583 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 584 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 585 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 586 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 586 "src/compiler/Usages.pv"
        return 0;
    }
    #line 587 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 588 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 589 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &struct_info->generics, generic_map)) {
            #line 589 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 591 "src/compiler/Usages.pv"
    return 0;
}

#line 594 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 595 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 596 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 597 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 597 "src/compiler/Usages.pv"
        return 0;
    }
    #line 598 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 599 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 600 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &enum_info->generics, generic_map)) {
            #line 600 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 602 "src/compiler/Usages.pv"
    return 0;
}

#line 605 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_primitive(struct Usages* self, struct Primitive* primitive_info, struct GenericMap* generic_map) {
    #line 606 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 607 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 608 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 608 "src/compiler/Usages.pv"
        return 0;
    }
    #line 610 "src/compiler/Usages.pv"
    if (parent_usage->usage_contexts.length > 0) {
        #line 611 "src/compiler/Usages.pv"
        return &parent_usage->usage_contexts.data[0];
    }
    #line 613 "src/compiler/Usages.pv"
    return 0;
}

#line 616 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 617 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 618 "src/compiler/Usages.pv"
    struct UsageContext* parent_usage_context = 0;

    #line 620 "src/compiler/Usages.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 620 "src/compiler/Usages.pv"
        return;
    }

    #line 622 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 624 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 625 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 626 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 627 "src/compiler/Usages.pv"
            self->usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 628 "src/compiler/Usages.pv"
            self->function_context = &self->usage_context->function_context;
        } break;
        #line 630 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 630 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 630 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 631 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 632 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 634 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_primitive(self, primitive_info, generic_map);
            }
            #line 636 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 636 "src/compiler/Usages.pv"
                return;
            }

            #line 638 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index), &func_ptr);
            #line 639 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 639 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 639 "src/compiler/Usages.pv"
                return;
            }
            #line 640 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 641 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 642 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 644 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 646 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 648 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 648 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 648 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 649 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 650 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 652 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_struct(self, struct_info, generic_map);
            }
            #line 654 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 654 "src/compiler/Usages.pv"
                return;
            }

            #line 656 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index), &func_ptr);
            #line 657 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 657 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 657 "src/compiler/Usages.pv"
                return;
            }
            #line 658 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 659 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 660 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 662 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 664 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 666 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 666 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 666 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 667 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 668 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 670 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_enum(self, enum_info, generic_map);
            }
            #line 672 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 672 "src/compiler/Usages.pv"
                return;
            }

            #line 674 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index), &func_ptr);
            #line 675 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 675 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 675 "src/compiler/Usages.pv"
                return;
            }
            #line 676 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 677 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 678 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 680 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 682 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 684 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 685 "src/compiler/Usages.pv"
            parent_usage_context = entry_usage_context;
            #line 686 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 686 "src/compiler/Usages.pv"
                return;
            }

            #line 688 "src/compiler/Usages.pv"
            uintptr_t impl_index = self->active_impl_index;
            #line 689 "src/compiler/Usages.pv"
            if (parent_usage_context->impl_functions.length <= impl_index) {
                #line 689 "src/compiler/Usages.pv"
                impl_index = 0;
            }
            #line 690 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index), &func_ptr);
            #line 691 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 691 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 691 "src/compiler/Usages.pv"
                return;
            }
            #line 692 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 693 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 694 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 696 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 698 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 700 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 701 "src/compiler/Usages.pv"
            if (entry_usage_context == 0) {
                #line 701 "src/compiler/Usages.pv"
                return;
            }
            #line 702 "src/compiler/Usages.pv"
            self->usage_context = entry_usage_context;
            #line 703 "src/compiler/Usages.pv"
            self->usage_context->function_context = FunctionContext__new(self->allocator, func_info, false);
            #line 704 "src/compiler/Usages.pv"
            self->function_context = &self->usage_context->function_context;
        } break;
    }

    #line 708 "src/compiler/Usages.pv"
    if (self->std_namespace && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 709 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 710 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }}, (struct Array_Type[]){(struct Array_Type) { .data = &func_info->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
        #line 711 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 714 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 716 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 716 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 716 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 717 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 720 "src/compiler/Usages.pv"
    Usages__add_type(self, &func_info->return_type, generic_map);

    #line 722 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 724 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 726 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
    #line 727 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 730 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 731 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 731 "src/compiler/Usages.pv"
        return;
    }

    #line 733 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 733 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 733 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 734 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 735 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 735 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 736 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 738 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 738 "src/compiler/Usages.pv"
                struct LetStatement* statement = statement_iter->data.letstatement_value;
                #line 739 "src/compiler/Usages.pv"
                if (!statement->is_static) {
                    #line 740 "src/compiler/Usages.pv"
                    FunctionContext__add_variable(self->function_context, statement->name->value, statement->type);
                }

                #line 743 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->type, generic_map);

                #line 745 "src/compiler/Usages.pv"
                if (statement->value != 0) {
                    #line 746 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->value, generic_map);
                }
            } break;
            #line 749 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 749 "src/compiler/Usages.pv"
                struct ReturnStatement* statement = statement_iter->data.returnstatement_value;
                #line 750 "src/compiler/Usages.pv"
                if (statement->expression != 0) {
                    #line 751 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->expression, generic_map);
                }
            } break;
            #line 754 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 754 "src/compiler/Usages.pv"
                struct YieldStatement* statement = statement_iter->data.yieldstatement_value;
                #line 755 "src/compiler/Usages.pv"
                self->function_context->coroutine.yield_count += 1;
                #line 756 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
            } break;
            #line 758 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 758 "src/compiler/Usages.pv"
                struct IfStatement* statement = statement_iter->data.ifstatement_value;
                #line 759 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 760 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);

                #line 762 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&statement->else_statements);
                #line 762 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 762 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 763 "src/compiler/Usages.pv"
                    if (else_statement->expression != 0) {
                        #line 763 "src/compiler/Usages.pv"
                        Usages__process_expression(self, else_statement->expression, generic_map);
                    }
                    #line 764 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 767 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 767 "src/compiler/Usages.pv"
                struct MatchStatement* statement = statement_iter->data.matchstatement_value;
                #line 768 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);

                #line 770 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(&statement->cases);
                #line 770 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 770 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 771 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 774 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 774 "src/compiler/Usages.pv"
                struct WhileStatement* statement = statement_iter->data.whilestatement_value;
                #line 775 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 776 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 778 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 778 "src/compiler/Usages.pv"
                struct ForStatement* statement = statement_iter->data.forstatement_value;
                #line 779 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 780 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->iter_type, generic_map);
                #line 781 "src/compiler/Usages.pv"
                if (statement->value_type != 0) {
                    #line 782 "src/compiler/Usages.pv"
                    Usages__add_type(self, statement->value_type, generic_map);
                }

                #line 785 "src/compiler/Usages.pv"
                switch (statement->type.type) {
                    #line 786 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 786 "src/compiler/Usages.pv"
                        struct Expression* start = statement->type.range_value._0;
                        #line 786 "src/compiler/Usages.pv"
                        struct Expression* end = statement->type.range_value._1;
                        #line 787 "src/compiler/Usages.pv"
                        struct ForVariable* variable = &statement->variables.data[0];
                        #line 788 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(self->function_context, variable->name->value, variable->type);
                        #line 789 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 790 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 792 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 792 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.sequence_value;
                        #line 793 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 795 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 795 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.iter_value;
                        #line 796 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 798 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ERROR: {
                    } break;
                }

                #line 801 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 803 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 803 "src/compiler/Usages.pv"
                struct AssignmentStatement* statement = statement_iter->data.assignmentstatement_value;
                #line 804 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->left, generic_map);
                #line 805 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->right, generic_map);
            } break;
            #line 807 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 807 "src/compiler/Usages.pv"
                struct Expression* statement = statement_iter->data.expressionstatement_value;
                #line 808 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement, generic_map);
            } break;
            #line 810 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 811 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 816 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 817 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 819 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 820 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 821 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 821 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 821 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 822 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 823 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 823 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 823 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 824 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }

            #line 827 "src/compiler/Usages.pv"
            switch (target->return_type.type) {
                #line 828 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 828 "src/compiler/Usages.pv"
                    struct Function* func_info = target->return_type.function_value._0;
                    #line 829 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 830 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 831 "src/compiler/Usages.pv"
                            if (arguments.length > 0) {
                                #line 832 "src/compiler/Usages.pv"
                                struct Type* type = Type__deref(&arguments.data[0].value->return_type);

                                #line 834 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 835 "src/compiler/Usages.pv"
                                    case TYPE__GENERIC: {
                                        #line 835 "src/compiler/Usages.pv"
                                        struct Generic* generic = type->generic_value;
                                        #line 836 "src/compiler/Usages.pv"
                                        struct str name = generic->name->value;
                                        #line 837 "src/compiler/Usages.pv"
                                        struct Type* resolved_type = GenericMap__get(generic_map, name);
                                        #line 838 "src/compiler/Usages.pv"
                                        if (resolved_type != 0) {
                                            #line 838 "src/compiler/Usages.pv"
                                            type = resolved_type;
                                        }
                                    } break;
                                    #line 840 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }

                                #line 843 "src/compiler/Usages.pv"
                                struct ArenaAllocator* allocator = self->allocator;
                                #line 844 "src/compiler/Usages.pv"
                                struct UsageContext* usage_context = self->usage_context;

                                #line 846 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 847 "src/compiler/Usages.pv"
                                    case TYPE__PRIMITIVE: {
                                        #line 847 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = type->primitive_value;
                                        #line 848 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 849 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 849 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, primitive_info->name, *type);
                                            } break;
                                            #line 850 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 850 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, primitive_info->name, *type);
                                            } break;
                                            #line 851 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 851 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, primitive_info->name, *type);
                                            } break;
                                        }
                                    } break;
                                    #line 854 "src/compiler/Usages.pv"
                                    case TYPE__TYPEDEF_C: {
                                        #line 854 "src/compiler/Usages.pv"
                                        struct TypedefC* typedef_c = type->typedefc_value;
                                        #line 855 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = ArenaAllocator__store_Primitive(allocator, (struct Primitive[]){(struct Primitive) { .name = typedef_c->name, .traits = (struct HashMap_str_ref_Trait) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .impls = (struct Array_ref_Impl) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
                                        #line 856 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 857 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 857 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 858 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 858 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 859 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 859 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                        }
                                    } break;
                                    #line 862 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }
                            }
                        } break;
                        #line 866 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 869 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 872 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 872 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 872 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 873 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 874 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
        } break;
        #line 875 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 876 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 876 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 877 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 879 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 879 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 879 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 880 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 881 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 883 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 883 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 884 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 885 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 887 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 887 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 888 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 889 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 891 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 891 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 891 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 892 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 893 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 895 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 895 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 896 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 898 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 898 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 898 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 898 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 899 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 900 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 901 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 903 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 903 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 904 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 905 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 905 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 905 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 906 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 906 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 907 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 909 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 909 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 910 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 914 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 914 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 915 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 917 "src/compiler/Usages.pv"
            switch (expression->return_type.type) {
                #line 918 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 918 "src/compiler/Usages.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 919 "src/compiler/Usages.pv"
                    if (str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 920 "src/compiler/Usages.pv"
                        HashSet_str__insert(&self->usage_context->primitive_code, (struct str){ .ptr = "str", .length = strlen("str") });
                    }
                } break;
                #line 923 "src/compiler/Usages.pv"
                default: {
                } break;
            }

            #line 926 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0));
            #line 927 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 928 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 928 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 929 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 931 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 932 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 933 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 934 "src/compiler/Usages.pv"
                            usage->impl_dynamic_function = true;
                        } break;
                        #line 936 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 936 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 936 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 937 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 938 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 939 "src/compiler/Usages.pv"
                            { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                            #line 939 "src/compiler/Usages.pv"
                            while (Iter_ref_UsageContext__next(&__iter)) {
                                #line 939 "src/compiler/Usages.pv"
                                struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                #line 940 "src/compiler/Usages.pv"
                                struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index), &func_ptr);
                                #line 941 "src/compiler/Usages.pv"
                                if (impl_function != 0) {
                                    #line 941 "src/compiler/Usages.pv"
                                    impl_function->impl_dynamic_function = true;
                                }
                            } }
                        } break;
                        #line 944 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 944 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 944 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 945 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 946 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 947 "src/compiler/Usages.pv"
                            { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                            #line 947 "src/compiler/Usages.pv"
                            while (Iter_ref_UsageContext__next(&__iter)) {
                                #line 947 "src/compiler/Usages.pv"
                                struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                #line 948 "src/compiler/Usages.pv"
                                struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index), &func_ptr);
                                #line 949 "src/compiler/Usages.pv"
                                if (impl_function != 0) {
                                    #line 949 "src/compiler/Usages.pv"
                                    impl_function->impl_dynamic_function = true;
                                }
                            } }
                        } break;
                        #line 952 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 952 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 952 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 953 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 954 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 955 "src/compiler/Usages.pv"
                            { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                            #line 955 "src/compiler/Usages.pv"
                            while (Iter_ref_UsageContext__next(&__iter)) {
                                #line 955 "src/compiler/Usages.pv"
                                struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                #line 956 "src/compiler/Usages.pv"
                                struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index), &func_ptr);
                                #line 957 "src/compiler/Usages.pv"
                                if (impl_function != 0) {
                                    #line 957 "src/compiler/Usages.pv"
                                    impl_function->impl_dynamic_function = true;
                                }
                            } }
                        } break;
                        #line 960 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 963 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 963 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 964 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 965 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 965 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 966 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 967 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 967 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 968 "src/compiler/Usages.pv"
                                    if (str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 969 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 970 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 971 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 974 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 977 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 980 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 986 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
}
