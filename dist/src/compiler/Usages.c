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
#include <std/Array_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Impl.h>
#include <compiler/TypeUsage_TypeImpl.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>
#include <tuple_usize_TypeUsage_TypeImpl.h>
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
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <compiler/TypeUsage_Sequence.h>
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
#include <std/Array_DestructureBinding.h>
#include <std/Iter_ref_DestructureBinding.h>
#include <analyzer/statement/DestructureBinding.h>
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
#include <analyzer/statement/DeferStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/Usages.h>

#include <compiler/Usages.h>

#line 170 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 171 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 173 "src/compiler/Usages.pv"
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
        .type_impls = HashMap_usize_TypeUsage_TypeImpl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .dynamic_impl_functions = HashSet_usize__new(allocator),
        .std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") }),
        .usage_mode = USAGE_MODE__LAYOUT,
        .usage_context = 0,
        .function_context = 0,
        .active_impl_index = 0,
    };

    #line 200 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 200 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 200 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 201 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 202 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 203 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info));
            #line 204 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 208 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 210 "src/compiler/Usages.pv"
    uintptr_t type_impl_i = 0;
    #line 211 "src/compiler/Usages.pv"
    while (type_impl_i < self.root->type_impls.length) {
        #line 212 "src/compiler/Usages.pv"
        struct TypeImpl* type_impl = &self.root->type_impls.data[type_impl_i];
        #line 213 "src/compiler/Usages.pv"
        if (type_impl->impl_info->generics.array.length == 0) {
            #line 214 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_TypeImpl__insert(&self.type_impls, (uintptr_t)(type_impl), TypeUsage_TypeImpl__new(self.allocator, type_impl));
            #line 215 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, type_impl->type);
        }
        #line 217 "src/compiler/Usages.pv"
        type_impl_i += 1;
    }

    #line 220 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 221 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 222 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 223 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 225 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 226 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 226 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 226 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 227 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 227 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 227 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 227 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 228 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 228 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 228 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 228 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 229 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 229 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 229 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 229 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 230 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 230 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 230 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 230 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 231 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 231 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 231 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 232 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 232 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 232 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 233 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 236 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 239 "src/compiler/Usages.pv"
    { struct HashMapIter_usize_TypeUsage_TypeImpl __iter = HashMap_usize_TypeUsage_TypeImpl__iter(&self.type_impls);
    #line 239 "src/compiler/Usages.pv"
    while (HashMapIter_usize_TypeUsage_TypeImpl__next(&__iter)) {
        #line 239 "src/compiler/Usages.pv"
        struct TypeUsage_TypeImpl* usage = &HashMapIter_usize_TypeUsage_TypeImpl__value(&__iter)->_1;

        #line 240 "src/compiler/Usages.pv"
        Usages__process_type_impl(&self, usage->type);
    } }

    #line 243 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 245 "src/compiler/Usages.pv"
    return self;
}

#line 248 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 249 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 249 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 249 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 250 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 250 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 250 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 251 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 254 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 258 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 259 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 259 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 259 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 260 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 262 "src/compiler/Usages.pv"
        struct Token* name = func_info->name;
        #line 263 "src/compiler/Usages.pv"
        if (name == 0 || func_info->generics.array.length != 0) {
            #line 263 "src/compiler/Usages.pv"
            continue;
        }

        #line 265 "src/compiler/Usages.pv"
        if (!HashSet_str__insert(&self->usage_types, name->value)) {
            #line 265 "src/compiler/Usages.pv"
            continue;
        }

        #line 267 "src/compiler/Usages.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 268 "src/compiler/Usages.pv"
        if (generic_map == 0) {
            #line 268 "src/compiler/Usages.pv"
            continue;
        }
        #line 269 "src/compiler/Usages.pv"
        struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} }});
        #line 270 "src/compiler/Usages.pv"
        generic_map->self_type = self_type;
        #line 271 "src/compiler/Usages.pv"
        Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
    } }

    #line 274 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&module->enums);
    #line 274 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 274 "src/compiler/Usages.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 275 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 275 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 275 "src/compiler/Usages.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 276 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info));

            #line 278 "src/compiler/Usages.pv"
            struct Token* name = enum_info->name;
            #line 279 "src/compiler/Usages.pv"
            if (name != 0 && enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, name->value)) {
                #line 280 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 281 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} }});
                #line 282 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 282 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 283 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 288 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&module->structs);
    #line 288 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 288 "src/compiler/Usages.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 289 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 289 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 289 "src/compiler/Usages.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 290 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info));

            #line 292 "src/compiler/Usages.pv"
            struct Token* name = struct_info->name;
            #line 293 "src/compiler/Usages.pv"
            if (name != 0 && struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, name->value)) {
                #line 294 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 295 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} }});
                #line 296 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 296 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 297 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 302 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&module->traits);
    #line 302 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 302 "src/compiler/Usages.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 303 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 303 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 303 "src/compiler/Usages.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 304 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info));

            #line 306 "src/compiler/Usages.pv"
            struct Token* name = trait_info->name;
            #line 307 "src/compiler/Usages.pv"
            if (name != 0 && trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, name->value)) {
                #line 308 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 309 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} }});
                #line 310 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 310 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 311 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            }
        } }
    } }
}

#line 317 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 318 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 319 "src/compiler/Usages.pv"
    if (resolved_type == 0) {
        #line 319 "src/compiler/Usages.pv"
        return;
    }

    #line 321 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 322 "src/compiler/Usages.pv"
    struct Type* type_deref_all = Type__deref_all(resolved_type);
    #line 323 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 324 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 325 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;
    #line 326 "src/compiler/Usages.pv"
    if (usage_context == 0) {
        #line 326 "src/compiler/Usages.pv"
        return;
    }

    #line 328 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 329 "src/compiler/Usages.pv"
        case TYPE__GLOBAL: {
            #line 329 "src/compiler/Usages.pv"
            struct Global* g = type_deref->global_value;
            #line 330 "src/compiler/Usages.pv"
            struct String path = Generator__make_rel_path(self->generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
            #line 331 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__BODY) {
                #line 332 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->body, String__as_str(&path), *type);
            }
            #line 334 "src/compiler/Usages.pv"
            return;
        } break;
        #line 336 "src/compiler/Usages.pv"
        case TYPE__INDIRECT: {
            #line 337 "src/compiler/Usages.pv"
            switch (type_deref_all->type) {
                #line 338 "src/compiler/Usages.pv"
                case TYPE__PRIMITIVE: {
                    #line 338 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = type_deref_all->primitive_value;
                    #line 339 "src/compiler/Usages.pv"
                    if (primitive_info == 0) {
                        #line 339 "src/compiler/Usages.pv"
                        return;
                    }
                    #line 340 "src/compiler/Usages.pv"
                    if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                        #line 341 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
                    } else {
                        #line 343 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
                    }

                    #line 346 "src/compiler/Usages.pv"
                    return;
                } break;
                #line 348 "src/compiler/Usages.pv"
                case TYPE__TRAIT: {
                    #line 348 "src/compiler/Usages.pv"
                    struct Trait* trait_info = type_deref_all->trait_value._0;
                    #line 348 "src/compiler/Usages.pv"
                    is_trait = Trait__has_dynamic_dispatch(trait_info);
                } break;
                #line 349 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 352 "src/compiler/Usages.pv"
        case TYPE__PRIMITIVE: {
            #line 352 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = type_deref->primitive_value;
            #line 353 "src/compiler/Usages.pv"
            if (primitive_info == 0) {
                #line 353 "src/compiler/Usages.pv"
                return;
            }
            #line 354 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                #line 355 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
            } else {
                #line 357 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
            }
        } break;
        #line 360 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 360 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 361 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 361 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 362 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 362 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 362 "src/compiler/Usages.pv"
            struct GenericMap* type_generic_map = type_deref->function_value._1;
            #line 363 "src/compiler/Usages.pv"
            is_type = func_info->type != FUNCTION_TYPE__BUILTIN && func_info->generics.array.length > 0;

            #line 365 "src/compiler/Usages.pv"
            switch (func_info->parent.type) {
                #line 366 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__NONE: {
                    #line 367 "src/compiler/Usages.pv"
                    is_type = (func_info->type == FUNCTION_TYPE__STANDARD || func_info->type == FUNCTION_TYPE__COROUTINE) && func_info->name != 0;
                } break;
                #line 369 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 369 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                    #line 370 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }}, generic_map);
                    #line 371 "src/compiler/Usages.pv"
                    is_type = true;
                } break;
                #line 373 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 373 "src/compiler/Usages.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 374 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 376 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 376 "src/compiler/Usages.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 377 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 379 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TRAIT: {
                    #line 379 "src/compiler/Usages.pv"
                    struct Trait* trait_info = func_info->parent.trait_value;
                    #line 380 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 382 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 382 "src/compiler/Usages.pv"
                    struct Type* type_info = func_info->parent.type_value._0;
                    #line 383 "src/compiler/Usages.pv"
                    Usages__add_type(self, type_info, type_generic_map);
                } break;
            }
        } break;
        #line 387 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 387 "src/compiler/Usages.pv"
            struct Trait* trait_info = type_deref->trait_value._0;
            #line 387 "src/compiler/Usages.pv"
            is_trait = Trait__has_dynamic_dispatch(trait_info);
        } break;
        #line 388 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 388 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 389 "src/compiler/Usages.pv"
            switch (sequence->type.type) {
                #line 390 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 390 "src/compiler/Usages.pv"
                    struct Expression* expression = sequence->type.fixedarray_value;
                    #line 391 "src/compiler/Usages.pv"
                    Usages__process_expression(self, expression, generic_map);
                } break;
                #line 393 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__SLICE: {
                    #line 394 "src/compiler/Usages.pv"
                    is_type = Sequence__is_slice(sequence);
                    #line 395 "src/compiler/Usages.pv"
                    type = Type__deref(type);
                    #line 396 "src/compiler/Usages.pv"
                    resolved_type = type_deref;
                } break;
            }
        } break;
        #line 400 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 400 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 401 "src/compiler/Usages.pv"
        case TYPE__STRUCT_C: {
            #line 401 "src/compiler/Usages.pv"
            struct StructC* struct_c = type_deref->structc_value;
            #line 401 "src/compiler/Usages.pv"
            is_type = !struct_c->include->mode_cpp;
        } break;
        #line 402 "src/compiler/Usages.pv"
        case TYPE__UNION_C: {
            #line 402 "src/compiler/Usages.pv"
            struct StructC* union_c = type_deref->unionc_value;
            #line 402 "src/compiler/Usages.pv"
            is_type = !union_c->include->mode_cpp;
        } break;
        #line 403 "src/compiler/Usages.pv"
        case TYPE__ENUM_C: {
            #line 403 "src/compiler/Usages.pv"
            struct EnumC* enum_c = type_deref->enumc_value;
            #line 403 "src/compiler/Usages.pv"
            is_type = !enum_c->include->mode_cpp;
        } break;
        #line 404 "src/compiler/Usages.pv"
        case TYPE__UNKNOWN_C: {
            #line 404 "src/compiler/Usages.pv"
            struct UnknownC* unknown_c = type_deref->unknownc_value;
            #line 404 "src/compiler/Usages.pv"
            is_type = unknown_c->include != 0;
        } break;
        #line 405 "src/compiler/Usages.pv"
        case TYPE__FUNCTION_C: {
            #line 405 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 406 "src/compiler/Usages.pv"
        case TYPE__TYPEDEF_C: {
            #line 406 "src/compiler/Usages.pv"
            struct TypedefC* typedef_c = type_deref->typedefc_value;
            #line 407 "src/compiler/Usages.pv"
            struct Include* include = typedef_c->include;
            #line 408 "src/compiler/Usages.pv"
            if (include == 0) {
                #line 408 "src/compiler/Usages.pv"
                return;
            }
            #line 409 "src/compiler/Usages.pv"
            is_type = !include->mode_cpp;
        } break;
        #line 411 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 411 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 412 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY) {
                #line 413 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->cpp_usages, class_info->name, *type);
            } else {
                #line 415 "src/compiler/Usages.pv"
                struct Include* include = class_info->include;
                #line 416 "src/compiler/Usages.pv"
                is_type = include->mode_cpp;
            }
        } break;
        #line 419 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 422 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 422 "src/compiler/Usages.pv"
        return;
    }

    #line 424 "src/compiler/Usages.pv"
    struct String type_name_generic = Naming__get_type_name(self->naming_ident, type, generic_map->self_type, generic_map);

    #line 426 "src/compiler/Usages.pv"
    switch (self->usage_mode) {
        #line 427 "src/compiler/Usages.pv"
        case USAGE_MODE__LAYOUT: {
            #line 427 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->layout, String__as_str(&type_name_generic), *type);
        } break;
        #line 428 "src/compiler/Usages.pv"
        case USAGE_MODE__SIGNATURE: {
            #line 428 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->signature, String__as_str(&type_name_generic), *type);
        } break;
        #line 429 "src/compiler/Usages.pv"
        case USAGE_MODE__BODY: {
            #line 429 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->body, String__as_str(&type_name_generic), *type);
        } break;
    }

    #line 432 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 432 "src/compiler/Usages.pv"
        return;
    }

    #line 434 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref_all, generic_map->self_type, generic_map);
    #line 435 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 437 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 438 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 439 "src/compiler/Usages.pv"
        return;
    }

    #line 442 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref_all);
}

#line 445 "src/compiler/Usages.pv"
void Usages__process_impls(struct Usages* self, struct Array_ref_Impl* impls, struct GenericMap* generic_map) {
    #line 446 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 448 "src/compiler/Usages.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 448 "src/compiler/Usages.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 448 "src/compiler/Usages.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 448 "src/compiler/Usages.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 449 "src/compiler/Usages.pv"
        self->active_impl_index = impl_index;

        #line 451 "src/compiler/Usages.pv"
        if (impl_info->has_trait) {
            #line 452 "src/compiler/Usages.pv"
            Usages__add_type(self, &impl_info->trait_type, generic_map);

            #line 454 "src/compiler/Usages.pv"
            if (impl_info->trait_ != 0 && !Trait__has_dynamic_dispatch(impl_info->trait_)) {
                #line 455 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 455 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 455 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 456 "src/compiler/Usages.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 456 "src/compiler/Usages.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 456 "src/compiler/Usages.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 457 "src/compiler/Usages.pv"
                        Usages__add_type(self, &param->type, generic_map);
                    } }
                    #line 459 "src/compiler/Usages.pv"
                    Usages__add_type(self, &func_info->return_type, generic_map);
                } }
            }
        }

        #line 464 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 464 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 464 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 465 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 465 "src/compiler/Usages.pv"
                continue;
            }
            #line 466 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }

        #line 469 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 470 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 471 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 471 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 471 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 471 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 472 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 472 "src/compiler/Usages.pv"
                    continue;
                }
                #line 473 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            } }
        }
    } }

    #line 478 "src/compiler/Usages.pv"
    self->active_impl_index = 0;
}

#line 481 "src/compiler/Usages.pv"
void Usages__process_type_impl(struct Usages* self, struct TypeImpl* type_impl) {
    #line 482 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 483 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, &type_impl->impl_info->generics, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 484 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 485 "src/compiler/Usages.pv"
    if (generic_map == 0) {
        #line 485 "src/compiler/Usages.pv"
        return;
    }
    #line 486 "src/compiler/Usages.pv"
    generic_map->self_type = &type_impl->type;

    #line 488 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(type_impl);
    #line 489 "src/compiler/Usages.pv"
    struct TypeUsage_TypeImpl* parent_usage = HashMap_usize_TypeUsage_TypeImpl__find(&self->type_impls, &parent_ptr);
    #line 490 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 490 "src/compiler/Usages.pv"
        return;
    }

    #line 492 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_TypeImpl__add_usage(parent_usage, generic_map);
    #line 493 "src/compiler/Usages.pv"
    struct Impl* impls_base[1] = {type_impl->impl_info};
    #line 494 "src/compiler/Usages.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 };
    #line 495 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &impls);
    #line 496 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 498 "src/compiler/Usages.pv"
    self->usage_context = usage_context;
    #line 499 "src/compiler/Usages.pv"
    Usages__process_impls(self, &impls, generic_map);

    #line 501 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 504 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 505 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 506 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
    #line 507 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 508 "src/compiler/Usages.pv"
    if (generic_map == 0) {
        #line 508 "src/compiler/Usages.pv"
        return;
    }

    #line 510 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 511 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 512 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 512 "src/compiler/Usages.pv"
        return;
    }

    #line 514 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Primitive__add_usage(parent_usage, generic_map);
    #line 515 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &primitive_info->impls);
    #line 516 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 518 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 520 "src/compiler/Usages.pv"
    Usages__process_impls(self, &primitive_info->impls, generic_map);

    #line 522 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 525 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 526 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 527 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 528 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 529 "src/compiler/Usages.pv"
    if (generic_map == 0) {
        #line 529 "src/compiler/Usages.pv"
        return;
    }
    #line 530 "src/compiler/Usages.pv"
    GenericMap__insert(generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 531 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 532 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type }});
    #line 533 "src/compiler/Usages.pv"
    if (indirect == 0) {
        #line 533 "src/compiler/Usages.pv"
        return;
    }
    #line 534 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    #line 535 "src/compiler/Usages.pv"
    if (generic_map->self_type == 0) {
        #line 535 "src/compiler/Usages.pv"
        return;
    }

    #line 537 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(sequence);
    #line 538 "src/compiler/Usages.pv"
    struct TypeUsage_Sequence* parent_usage = HashMap_usize_TypeUsage_Sequence__find(&self->sequences, &parent_ptr);
    #line 539 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 540 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Sequence__insert(&self->sequences, parent_ptr, TypeUsage_Sequence__new(self->allocator, sequence));
    }
    #line 542 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 542 "src/compiler/Usages.pv"
        return;
    }

    #line 544 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Sequence__add_usage(parent_usage, generic_map);
    #line 545 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 547 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, generic_map);

    #line 549 "src/compiler/Usages.pv"
    if (self->std_namespace != 0) {
        #line 550 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 551 "src/compiler/Usages.pv"
        if (iter_type != 0) {
            #line 552 "src/compiler/Usages.pv"
            struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
            #line 553 "src/compiler/Usages.pv"
            struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, (struct Array_Type[]){(struct Array_Type) { .data = &element_reference, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
            #line 554 "src/compiler/Usages.pv"
            if (sequence_iter != 0) {
                #line 555 "src/compiler/Usages.pv"
                Usages__add_type(self, sequence_iter, generic_map);
            }
        }
    }

    #line 560 "src/compiler/Usages.pv"
    struct TypeImpl* root_hack_type = self->root->hack_type_impl;
    #line 561 "src/compiler/Usages.pv"
    if (root_hack_type != 0) {
        #line 562 "src/compiler/Usages.pv"
        struct Impl* impl_info = root_hack_type->impl_info;

        #line 564 "src/compiler/Usages.pv"
        switch (Type__deref_all(&sequence->element)->type) {
            #line 565 "src/compiler/Usages.pv"
            case TYPE__GENERIC: {
            } break;
            #line 566 "src/compiler/Usages.pv"
            case TYPE__GENERIC_TYPEDEF: {
            } break;
            #line 567 "src/compiler/Usages.pv"
            default: {
                #line 568 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 568 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 568 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 569 "src/compiler/Usages.pv"
                    Usages__process_function(self, func_info, generic_map);
                } }
            } break;
        }
    }

    #line 575 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 578 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 579 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 580 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 581 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 582 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 584 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(tuple);
    #line 585 "src/compiler/Usages.pv"
    struct TypeUsage_Tuple* parent_usage = HashMap_usize_TypeUsage_Tuple__find(&self->tuples, &parent_ptr);
    #line 586 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 586 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Tuple__insert(&self->tuples, parent_ptr, TypeUsage_Tuple__new(self->allocator, tuple));
    }
    #line 587 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 587 "src/compiler/Usages.pv"
        return;
    }

    #line 589 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Tuple__add_usage(parent_usage, generic_map);
    #line 590 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 592 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type }});
    #line 593 "src/compiler/Usages.pv"
    if (generic_map != 0) {
        #line 593 "src/compiler/Usages.pv"
        generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    }

    #line 595 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
    #line 595 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 595 "src/compiler/Usages.pv"
        struct Type* element = Iter_ref_Type__value(&__iter);

        #line 596 "src/compiler/Usages.pv"
        Usages__add_type(self, element, generic_map);
    } }

    #line 599 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 602 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 603 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 604 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 605 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 606 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 606 "src/compiler/Usages.pv"
        return;
    }
    #line 607 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Struct__add_usage(parent_usage, generic_map);
    #line 608 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &struct_info->impls);
    #line 609 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 611 "src/compiler/Usages.pv"
    self->usage_context = usage_context;
    #line 612 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 614 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 614 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 614 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 615 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);

        #line 617 "src/compiler/Usages.pv"
        switch (Type__deref_all(&field->type)->type) {
            #line 618 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 618 "src/compiler/Usages.pv"
                struct Function* param_func_info = Type__deref_all(&field->type)->function_value._0;
                #line 618 "src/compiler/Usages.pv"
                struct GenericMap* param_generic_map = Type__deref_all(&field->type)->function_value._1;
                #line 619 "src/compiler/Usages.pv"
                if (param_generic_map == 0) {
                    #line 619 "src/compiler/Usages.pv"
                    continue;
                }
                #line 620 "src/compiler/Usages.pv"
                struct GenericMap resolved_generic_map = GenericMap__resolve_types(param_generic_map, self->allocator, generic_map);

                #line 622 "src/compiler/Usages.pv"
                { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&param_func_info->parameters);
                #line 622 "src/compiler/Usages.pv"
                while (Iter_ref_Parameter__next(&__iter)) {
                    #line 622 "src/compiler/Usages.pv"
                    struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                    #line 623 "src/compiler/Usages.pv"
                    Usages__add_type(self, &param->type, &resolved_generic_map);
                } }
                #line 625 "src/compiler/Usages.pv"
                Usages__add_type(self, &param_func_info->return_type, &resolved_generic_map);
            } break;
            #line 627 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 627 "src/compiler/Usages.pv"
                struct Sequence* sequence = Type__deref_all(&field->type)->sequence_value;
                #line 628 "src/compiler/Usages.pv"
                if (Sequence__is_fixed_array(sequence)) {
                    #line 629 "src/compiler/Usages.pv"
                    Usages__add_type(self, &sequence->element, generic_map);
                }
            } break;
            #line 632 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }

    #line 636 "src/compiler/Usages.pv"
    Usages__process_impls(self, &struct_info->impls, generic_map);

    #line 638 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 641 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 642 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 643 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 644 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 645 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 645 "src/compiler/Usages.pv"
        return;
    }
    #line 646 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Enum__add_usage(parent_usage, generic_map);
    #line 647 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &enum_info->impls);
    #line 648 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 650 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 652 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 654 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 654 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 654 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 655 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 655 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 655 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 656 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 660 "src/compiler/Usages.pv"
    Usages__process_impls(self, &enum_info->impls, generic_map);

    #line 662 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 665 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 666 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 667 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(trait_info);
    #line 668 "src/compiler/Usages.pv"
    struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
    #line 669 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 669 "src/compiler/Usages.pv"
        return;
    }
    #line 670 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Trait__add_usage(parent_usage, generic_map);
    #line 671 "src/compiler/Usages.pv"
    UsageContext__populate_trait_functions(usage_context, self->allocator, trait_info);

    #line 673 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 675 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 675 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 675 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 676 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }

    #line 679 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 682 "src/compiler/Usages.pv"
bool Usages__usage_context_matches(struct UsageContext* uc, struct Generics* generics, struct GenericMap* generic_map) {
    #line 683 "src/compiler/Usages.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&generics->array);
    #line 683 "src/compiler/Usages.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 683 "src/compiler/Usages.pv"
        struct Generic generic = *Iter_ref_Generic__value(&__iter);

        #line 684 "src/compiler/Usages.pv"
        struct Token* generic_name = generic.name;
        #line 685 "src/compiler/Usages.pv"
        if (generic_name == 0) {
            #line 685 "src/compiler/Usages.pv"
            return false;
        }
        #line 686 "src/compiler/Usages.pv"
        struct Type* parent_v = GenericMap__get(uc->generic_map, generic_name->value);
        #line 687 "src/compiler/Usages.pv"
        struct Type* func_v = GenericMap__get(generic_map, generic_name->value);
        #line 688 "src/compiler/Usages.pv"
        if (parent_v == 0) {
            #line 688 "src/compiler/Usages.pv"
            return false;
        }
        #line 689 "src/compiler/Usages.pv"
        if (func_v == 0) {
            #line 689 "src/compiler/Usages.pv"
            return false;
        }
        #line 690 "src/compiler/Usages.pv"
        struct Type parent_t = *parent_v;
        #line 691 "src/compiler/Usages.pv"
        if (!Type__eq(&parent_t, func_v)) {
            #line 691 "src/compiler/Usages.pv"
            return false;
        }
    } }
    #line 693 "src/compiler/Usages.pv"
    return true;
}

#line 696 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 697 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 698 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 699 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 699 "src/compiler/Usages.pv"
        return 0;
    }
    #line 700 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 701 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 702 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &struct_info->generics, generic_map)) {
            #line 702 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 704 "src/compiler/Usages.pv"
    return 0;
}

#line 707 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 708 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 709 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 710 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 710 "src/compiler/Usages.pv"
        return 0;
    }
    #line 711 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 712 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 713 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &enum_info->generics, generic_map)) {
            #line 713 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 715 "src/compiler/Usages.pv"
    return 0;
}

#line 718 "src/compiler/Usages.pv"
void Usages__mark_any_usage(struct Usages* self, struct Type* type) {
    #line 719 "src/compiler/Usages.pv"
    switch (type->type) {
        #line 720 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 720 "src/compiler/Usages.pv"
            struct Struct* struct_info = type->struct_value._0;
            #line 721 "src/compiler/Usages.pv"
            uintptr_t ptr = (uintptr_t)(struct_info);
            #line 722 "src/compiler/Usages.pv"
            struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
            #line 723 "src/compiler/Usages.pv"
            if (usage != 0) {
                #line 723 "src/compiler/Usages.pv"
                usage->any_usage = true;
            }
        } break;
        #line 725 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 725 "src/compiler/Usages.pv"
            struct Enum* enum_info = type->enum_value._0;
            #line 726 "src/compiler/Usages.pv"
            uintptr_t ptr = (uintptr_t)(enum_info);
            #line 727 "src/compiler/Usages.pv"
            struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &ptr);
            #line 728 "src/compiler/Usages.pv"
            if (usage != 0) {
                #line 728 "src/compiler/Usages.pv"
                usage->any_usage = true;
            }
        } break;
        #line 730 "src/compiler/Usages.pv"
        case TYPE__PRIMITIVE: {
            #line 730 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = type->primitive_value;
            #line 731 "src/compiler/Usages.pv"
            if (primitive_info == 0) {
                #line 731 "src/compiler/Usages.pv"
                return;
            }
            #line 732 "src/compiler/Usages.pv"
            uintptr_t ptr = (uintptr_t)(primitive_info);
            #line 733 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &ptr);
            #line 734 "src/compiler/Usages.pv"
            if (usage != 0) {
                #line 734 "src/compiler/Usages.pv"
                usage->any_usage = true;
            }
        } break;
        #line 736 "src/compiler/Usages.pv"
        default: {
        } break;
    }
}

#line 740 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_primitive(struct Usages* self, struct Primitive* primitive_info, struct GenericMap* generic_map) {
    #line 741 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 742 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 743 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 743 "src/compiler/Usages.pv"
        return 0;
    }
    #line 745 "src/compiler/Usages.pv"
    if (parent_usage->usage_contexts.length > 0) {
        #line 746 "src/compiler/Usages.pv"
        return &parent_usage->usage_contexts.data[0];
    }
    #line 748 "src/compiler/Usages.pv"
    return 0;
}

#line 751 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 752 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 753 "src/compiler/Usages.pv"
    struct UsageContext* parent_usage_context = 0;

    #line 755 "src/compiler/Usages.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 755 "src/compiler/Usages.pv"
        return;
    }

    #line 757 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 759 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 760 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 761 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 762 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 762 "src/compiler/Usages.pv"
                return;
            }
            #line 763 "src/compiler/Usages.pv"
            struct UsageContext* usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 764 "src/compiler/Usages.pv"
            self->usage_context = usage_context;
            #line 765 "src/compiler/Usages.pv"
            self->function_context = &usage_context->function_context;
        } break;
        #line 767 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 767 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 767 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 768 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 769 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 771 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_primitive(self, primitive_info, generic_map);
            }
            #line 773 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 773 "src/compiler/Usages.pv"
                return;
            }

            #line 775 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 776 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 776 "src/compiler/Usages.pv"
                return;
            }
            #line 777 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 778 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 778 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 778 "src/compiler/Usages.pv"
                return;
            }
            #line 779 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 780 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 781 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 783 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 785 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 787 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 787 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 787 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 788 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 789 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 791 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_struct(self, struct_info, generic_map);
            }
            #line 793 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 793 "src/compiler/Usages.pv"
                return;
            }

            #line 795 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 796 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 796 "src/compiler/Usages.pv"
                return;
            }
            #line 797 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 798 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 798 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 798 "src/compiler/Usages.pv"
                return;
            }
            #line 799 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 800 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 801 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 803 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 805 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 807 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 807 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 807 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 808 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 809 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 811 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_enum(self, enum_info, generic_map);
            }
            #line 813 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 813 "src/compiler/Usages.pv"
                return;
            }

            #line 815 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 816 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 816 "src/compiler/Usages.pv"
                return;
            }
            #line 817 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 818 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 818 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 818 "src/compiler/Usages.pv"
                return;
            }
            #line 819 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 820 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 821 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 823 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 825 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 827 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 828 "src/compiler/Usages.pv"
            parent_usage_context = entry_usage_context;
            #line 829 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 829 "src/compiler/Usages.pv"
                return;
            }

            #line 831 "src/compiler/Usages.pv"
            uintptr_t impl_index = self->active_impl_index;
            #line 832 "src/compiler/Usages.pv"
            if (parent_usage_context->impl_functions.length <= impl_index) {
                #line 832 "src/compiler/Usages.pv"
                impl_index = 0;
            }
            #line 833 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 834 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 834 "src/compiler/Usages.pv"
                return;
            }
            #line 835 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 836 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 836 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 836 "src/compiler/Usages.pv"
                return;
            }
            #line 837 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 838 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 839 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 841 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 843 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 845 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 846 "src/compiler/Usages.pv"
            if (entry_usage_context == 0) {
                #line 846 "src/compiler/Usages.pv"
                return;
            }
            #line 847 "src/compiler/Usages.pv"
            entry_usage_context->function_context = FunctionContext__new(self->allocator, func_info, false);
            #line 848 "src/compiler/Usages.pv"
            self->function_context = &entry_usage_context->function_context;
            #line 849 "src/compiler/Usages.pv"
            self->usage_context = entry_usage_context;
        } break;
    }

    #line 853 "src/compiler/Usages.pv"
    struct Namespace* std_namespace = self->std_namespace;
    #line 854 "src/compiler/Usages.pv"
    if (std_namespace != 0 && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 855 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 856 "src/compiler/Usages.pv"
        if (iter_trait != 0) {
            #line 857 "src/compiler/Usages.pv"
            struct Type* sequence_iter = Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }}, (struct Array_Type[]){(struct Array_Type) { .data = &func_info->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
            #line 858 "src/compiler/Usages.pv"
            if (sequence_iter != 0) {
                #line 859 "src/compiler/Usages.pv"
                Usages__add_type(self, sequence_iter, generic_map);
            }
        }
    }

    #line 864 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 866 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 866 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 866 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 867 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 870 "src/compiler/Usages.pv"
    Usages__add_type(self, &func_info->return_type, generic_map);

    #line 872 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 874 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 876 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
    #line 877 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 880 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 881 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 881 "src/compiler/Usages.pv"
        return;
    }

    #line 883 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 883 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 883 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 884 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 885 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 885 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 886 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 888 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 888 "src/compiler/Usages.pv"
                struct LetStatement* statement = statement_iter->data.letstatement_value;
                #line 889 "src/compiler/Usages.pv"
                if (!statement->is_static) {
                    #line 890 "src/compiler/Usages.pv"
                    struct FunctionContext* function_context = self->function_context;
                    #line 891 "src/compiler/Usages.pv"
                    if (function_context == 0) {
                        #line 891 "src/compiler/Usages.pv"
                        return;
                    }
                    #line 892 "src/compiler/Usages.pv"
                    if (statement->name != 0) {
                        #line 893 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, statement->name->value, statement->type);
                    }

                    #line 896 "src/compiler/Usages.pv"
                    { struct Iter_ref_DestructureBinding __iter = Array_DestructureBinding__iter(&statement->destructure);
                    #line 896 "src/compiler/Usages.pv"
                    while (Iter_ref_DestructureBinding__next(&__iter)) {
                        #line 896 "src/compiler/Usages.pv"
                        struct DestructureBinding* binding = Iter_ref_DestructureBinding__value(&__iter);

                        #line 897 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, binding->name->value, binding->type);
                    } }
                }

                #line 901 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->type, generic_map);

                #line 903 "src/compiler/Usages.pv"
                { struct Iter_ref_DestructureBinding __iter = Array_DestructureBinding__iter(&statement->destructure);
                #line 903 "src/compiler/Usages.pv"
                while (Iter_ref_DestructureBinding__next(&__iter)) {
                    #line 903 "src/compiler/Usages.pv"
                    struct DestructureBinding* binding = Iter_ref_DestructureBinding__value(&__iter);

                    #line 904 "src/compiler/Usages.pv"
                    Usages__add_type(self, binding->type, generic_map);
                } }

                #line 907 "src/compiler/Usages.pv"
                if (statement->value != 0) {
                    #line 908 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->value, generic_map);
                }
            } break;
            #line 911 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 911 "src/compiler/Usages.pv"
                struct ReturnStatement* statement = statement_iter->data.returnstatement_value;
                #line 912 "src/compiler/Usages.pv"
                if (statement->expression != 0) {
                    #line 913 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->expression, generic_map);
                }
            } break;
            #line 916 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 916 "src/compiler/Usages.pv"
                struct YieldStatement* statement = statement_iter->data.yieldstatement_value;
                #line 917 "src/compiler/Usages.pv"
                struct FunctionContext* function_context = self->function_context;
                #line 918 "src/compiler/Usages.pv"
                if (function_context == 0) {
                    #line 918 "src/compiler/Usages.pv"
                    return;
                }
                #line 919 "src/compiler/Usages.pv"
                function_context->coroutine.yield_count += 1;
                #line 920 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
            } break;
            #line 922 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 922 "src/compiler/Usages.pv"
                struct IfStatement* statement = statement_iter->data.ifstatement_value;
                #line 923 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 924 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);

                #line 926 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&statement->else_statements);
                #line 926 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 926 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 927 "src/compiler/Usages.pv"
                    if (else_statement->expression != 0) {
                        #line 927 "src/compiler/Usages.pv"
                        Usages__process_expression(self, else_statement->expression, generic_map);
                    }
                    #line 928 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 931 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 931 "src/compiler/Usages.pv"
                struct MatchStatement* statement = statement_iter->data.matchstatement_value;
                #line 932 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);

                #line 934 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(&statement->cases);
                #line 934 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 934 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 935 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 938 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 938 "src/compiler/Usages.pv"
                struct WhileStatement* statement = statement_iter->data.whilestatement_value;
                #line 939 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 940 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 942 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 942 "src/compiler/Usages.pv"
                struct ForStatement* statement = statement_iter->data.forstatement_value;
                #line 943 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 944 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->iter_type, generic_map);
                #line 945 "src/compiler/Usages.pv"
                if (statement->value_type != 0) {
                    #line 946 "src/compiler/Usages.pv"
                    Usages__add_type(self, statement->value_type, generic_map);
                }

                #line 949 "src/compiler/Usages.pv"
                switch (statement->type.type) {
                    #line 950 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 950 "src/compiler/Usages.pv"
                        struct Expression* start = statement->type.range_value._0;
                        #line 950 "src/compiler/Usages.pv"
                        struct Expression* end = statement->type.range_value._1;
                        #line 951 "src/compiler/Usages.pv"
                        struct ForVariable* variable = &statement->variables.data[0];
                        #line 952 "src/compiler/Usages.pv"
                        struct FunctionContext* function_context = self->function_context;
                        #line 953 "src/compiler/Usages.pv"
                        if (function_context == 0) {
                            #line 953 "src/compiler/Usages.pv"
                            return;
                        }
                        #line 954 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, variable->name->value, variable->type);
                        #line 955 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 956 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 958 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 958 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.sequence_value;
                        #line 959 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 961 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 961 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.iter_value;
                        #line 962 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 964 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ERROR: {
                    } break;
                }

                #line 967 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 969 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 969 "src/compiler/Usages.pv"
                struct AssignmentStatement* statement = statement_iter->data.assignmentstatement_value;
                #line 970 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->left, generic_map);
                #line 971 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->right, generic_map);
            } break;
            #line 973 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 973 "src/compiler/Usages.pv"
                struct Expression* statement = statement_iter->data.expressionstatement_value;
                #line 974 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement, generic_map);
            } break;
            #line 976 "src/compiler/Usages.pv"
            case STATEMENT_DATA__DEFER_STATEMENT: {
                #line 976 "src/compiler/Usages.pv"
                struct DeferStatement defer_stmt = statement_iter->data.deferstatement_value;
                #line 977 "src/compiler/Usages.pv"
                switch (defer_stmt.type) {
                    #line 978 "src/compiler/Usages.pv"
                    case DEFER_STATEMENT__EXPRESSION: {
                        #line 978 "src/compiler/Usages.pv"
                        struct Expression* expression = defer_stmt.expression_value;
                        #line 979 "src/compiler/Usages.pv"
                        Usages__process_expression(self, expression, generic_map);
                    } break;
                    #line 981 "src/compiler/Usages.pv"
                    case DEFER_STATEMENT__BLOCK: {
                        #line 981 "src/compiler/Usages.pv"
                        struct Block* block = defer_stmt.block_value;
                        #line 982 "src/compiler/Usages.pv"
                        Usages__process_block(self, block, generic_map);
                    } break;
                }
            } break;
            #line 986 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 987 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 992 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 993 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 995 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 996 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 997 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 997 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 997 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 998 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 999 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 999 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 999 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 1000 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }

            #line 1003 "src/compiler/Usages.pv"
            switch (target->return_type.type) {
                #line 1004 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 1004 "src/compiler/Usages.pv"
                    struct Function* func_info = target->return_type.function_value._0;
                    #line 1005 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 1006 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 1007 "src/compiler/Usages.pv"
                            if (arguments.length > 0) {
                                #line 1008 "src/compiler/Usages.pv"
                                struct Token* func_name = func_info->name;
                                #line 1009 "src/compiler/Usages.pv"
                                struct UsageContext* exact_usage_context = self->usage_context;
                                #line 1010 "src/compiler/Usages.pv"
                                if (func_name != 0 && exact_usage_context != 0) {
                                    #line 1011 "src/compiler/Usages.pv"
                                    struct Function* type_impl_function = Root__find_type_impl_function(self->root, &arguments.data[0].value->return_type, func_name->value, 0);
                                    #line 1012 "src/compiler/Usages.pv"
                                    if (type_impl_function != 0) {
                                        #line 1013 "src/compiler/Usages.pv"
                                        struct GenericMap func_generic_map_val = (struct GenericMap) { .self_type = &arguments.data[0].value->return_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } };
                                        #line 1014 "src/compiler/Usages.pv"
                                        struct GenericMap* func_generic_map = ArenaAllocator__store_GenericMap(self->allocator, &func_generic_map_val);
                                        #line 1015 "src/compiler/Usages.pv"
                                        if (func_generic_map != 0) {
                                            #line 1016 "src/compiler/Usages.pv"
                                            struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = type_impl_function, ._1 = func_generic_map} };
                                            #line 1017 "src/compiler/Usages.pv"
                                            struct String func_type_name = Naming__get_type_name(self->naming_ident, &func_type, func_generic_map->self_type, func_generic_map);
                                            #line 1018 "src/compiler/Usages.pv"
                                            switch (self->usage_mode) {
                                                #line 1019 "src/compiler/Usages.pv"
                                                case USAGE_MODE__LAYOUT: {
                                                    #line 1019 "src/compiler/Usages.pv"
                                                    HashMap_str_Type__insert(&exact_usage_context->layout, String__as_str(&func_type_name), func_type);
                                                } break;
                                                #line 1020 "src/compiler/Usages.pv"
                                                case USAGE_MODE__SIGNATURE: {
                                                    #line 1020 "src/compiler/Usages.pv"
                                                    HashMap_str_Type__insert(&exact_usage_context->signature, String__as_str(&func_type_name), func_type);
                                                } break;
                                                #line 1021 "src/compiler/Usages.pv"
                                                case USAGE_MODE__BODY: {
                                                    #line 1021 "src/compiler/Usages.pv"
                                                    HashMap_str_Type__insert(&exact_usage_context->body, String__as_str(&func_type_name), func_type);
                                                } break;
                                            }
                                        }
                                    }
                                }

                                #line 1027 "src/compiler/Usages.pv"
                                struct Type* type = Type__deref(&arguments.data[0].value->return_type);

                                #line 1029 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 1030 "src/compiler/Usages.pv"
                                    case TYPE__GENERIC: {
                                        #line 1030 "src/compiler/Usages.pv"
                                        struct Generic* generic = type->generic_value;
                                        #line 1031 "src/compiler/Usages.pv"
                                        struct Token* generic_name = generic->name;
                                        #line 1032 "src/compiler/Usages.pv"
                                        if (generic_name == 0) {
                                            #line 1032 "src/compiler/Usages.pv"
                                            return;
                                        }
                                        #line 1033 "src/compiler/Usages.pv"
                                        struct str name = generic_name->value;
                                        #line 1034 "src/compiler/Usages.pv"
                                        struct Type* resolved_type = GenericMap__get(generic_map, name);
                                        #line 1035 "src/compiler/Usages.pv"
                                        if (resolved_type != 0) {
                                            #line 1035 "src/compiler/Usages.pv"
                                            type = resolved_type;
                                        }
                                    } break;
                                    #line 1037 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }

                                #line 1040 "src/compiler/Usages.pv"
                                struct ArenaAllocator* allocator = self->allocator;
                                #line 1041 "src/compiler/Usages.pv"
                                struct UsageContext* usage_context = self->usage_context;
                                #line 1042 "src/compiler/Usages.pv"
                                if (usage_context == 0) {
                                    #line 1042 "src/compiler/Usages.pv"
                                    return;
                                }

                                #line 1044 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 1045 "src/compiler/Usages.pv"
                                    case TYPE__PRIMITIVE: {
                                        #line 1045 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = type->primitive_value;
                                        #line 1046 "src/compiler/Usages.pv"
                                        if (primitive_info == 0) {
                                            #line 1046 "src/compiler/Usages.pv"
                                            return;
                                        }

                                        #line 1048 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 1049 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 1049 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, primitive_info->name, *type);
                                            } break;
                                            #line 1050 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 1050 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, primitive_info->name, *type);
                                            } break;
                                            #line 1051 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 1051 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, primitive_info->name, *type);
                                            } break;
                                        }
                                    } break;
                                    #line 1054 "src/compiler/Usages.pv"
                                    case TYPE__TYPEDEF_C: {
                                        #line 1054 "src/compiler/Usages.pv"
                                        struct TypedefC* typedef_c = type->typedefc_value;
                                        #line 1055 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = ArenaAllocator__store_Primitive(allocator, (struct Primitive[]){(struct Primitive) { .name = typedef_c->name, .traits = (struct HashMap_str_ref_Trait) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .impls = (struct Array_ref_Impl) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
                                        #line 1056 "src/compiler/Usages.pv"
                                        if (primitive_info == 0) {
                                            #line 1056 "src/compiler/Usages.pv"
                                            return;
                                        }

                                        #line 1058 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 1059 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 1059 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 1060 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 1060 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 1061 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 1061 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                        }
                                    } break;
                                    #line 1064 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }
                            }
                        } break;
                        #line 1068 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1071 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 1074 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 1074 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 1074 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 1075 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 1076 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
        } break;
        #line 1077 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 1078 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 1078 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 1079 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1081 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 1081 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 1081 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 1082 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 1083 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 1085 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 1085 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 1086 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 1087 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1089 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 1089 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 1090 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 1091 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1093 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1093 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 1093 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 1094 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 1095 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 1097 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1097 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 1098 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1100 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 1100 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 1100 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 1100 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 1101 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 1102 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 1103 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 1105 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 1105 "src/compiler/Usages.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 1106 "src/compiler/Usages.pv"
            Usages__process_expression(self, value, generic_map);
        } break;
        #line 1108 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1108 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 1109 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 1110 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1110 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1110 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1111 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 1111 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 1112 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 1114 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1114 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1115 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 1119 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1119 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 1120 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 1122 "src/compiler/Usages.pv"
            switch (expression->return_type.type) {
                #line 1123 "src/compiler/Usages.pv"
                case TYPE__INDIRECT: {
                    #line 1123 "src/compiler/Usages.pv"
                    struct Indirect* target_indirect = expression->return_type.indirect_value;
                    #line 1124 "src/compiler/Usages.pv"
                    switch (target_indirect->to.type) {
                        #line 1125 "src/compiler/Usages.pv"
                        case TYPE__TRAIT: {
                            #line 1125 "src/compiler/Usages.pv"
                            struct Trait* target_trait = target_indirect->to.trait_value._0;
                            #line 1126 "src/compiler/Usages.pv"
                            struct Token* target_trait_name = target_trait->name;
                            #line 1127 "src/compiler/Usages.pv"
                            if (target_trait_name != 0 && str__Eq_str__eq(&target_trait_name->value, (struct str){ .ptr = "Any", .length = strlen("Any") })) {
                                #line 1128 "src/compiler/Usages.pv"
                                struct Type* source = Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0);
                                #line 1129 "src/compiler/Usages.pv"
                                if (source != 0) {
                                    #line 1129 "src/compiler/Usages.pv"
                                    Usages__mark_any_usage(self, Type__deref_all(source));
                                }
                            }
                        } break;
                        #line 1132 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1135 "src/compiler/Usages.pv"
                default: {
                } break;
            }

            #line 1138 "src/compiler/Usages.pv"
            switch (expression->return_type.type) {
                #line 1139 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 1139 "src/compiler/Usages.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1140 "src/compiler/Usages.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 1141 "src/compiler/Usages.pv"
                    struct UsageContext* usage_context = self->usage_context;
                    #line 1142 "src/compiler/Usages.pv"
                    if (struct_name != 0 && str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1143 "src/compiler/Usages.pv"
                        if (usage_context != 0) {
                            #line 1144 "src/compiler/Usages.pv"
                            HashSet_str__insert(&usage_context->primitive_code, (struct str){ .ptr = "str", .length = strlen("str") });
                        }
                    }
                } break;
                #line 1148 "src/compiler/Usages.pv"
                default: {
                } break;
            }

            #line 1151 "src/compiler/Usages.pv"
            struct Type* return_type_nullable = Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0);
            #line 1152 "src/compiler/Usages.pv"
            if (return_type_nullable == 0) {
                #line 1152 "src/compiler/Usages.pv"
                return;
            }
            #line 1153 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(return_type_nullable);

            #line 1155 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 1156 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 1156 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 1157 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 1159 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 1160 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 1161 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 1162 "src/compiler/Usages.pv"
                            if (usage == 0) {
                                #line 1162 "src/compiler/Usages.pv"
                                return;
                            }

                            #line 1164 "src/compiler/Usages.pv"
                            if (func_info->generics.array.length == 0) {
                                #line 1165 "src/compiler/Usages.pv"
                                usage->impl_dynamic_function = true;
                            }
                            #line 1167 "src/compiler/Usages.pv"
                            { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
                            #line 1167 "src/compiler/Usages.pv"
                            while (Iter_ref_UsageContext__next(&__iter)) {
                                #line 1167 "src/compiler/Usages.pv"
                                struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                #line 1168 "src/compiler/Usages.pv"
                                uc.impl_dynamic_function = true;
                            } }
                        } break;
                        #line 1171 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 1171 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 1171 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 1172 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 1173 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 1174 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1175 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1176 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1176 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1176 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1177 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1178 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1178 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1180 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1181 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1182 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1183 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1184 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1186 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1186 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1186 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1187 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1192 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1192 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1194 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 1194 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 1194 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 1195 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 1196 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 1197 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1198 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1199 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1199 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1199 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1200 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1201 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1201 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1203 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1204 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1205 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1206 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1207 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1209 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1209 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1209 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1210 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1215 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1215 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1217 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 1217 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 1217 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 1218 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 1219 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 1220 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1221 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1222 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1222 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1222 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1223 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1224 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1224 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1226 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1227 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1228 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1229 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1230 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1232 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1232 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1232 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1233 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1238 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1238 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1240 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1243 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 1243 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 1244 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 1245 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 1245 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 1246 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 1247 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 1247 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 1248 "src/compiler/Usages.pv"
                                    struct Token* name = trait_info->name;
                                    #line 1249 "src/compiler/Usages.pv"
                                    if (name == 0) {
                                        #line 1249 "src/compiler/Usages.pv"
                                        return;
                                    }

                                    #line 1251 "src/compiler/Usages.pv"
                                    if (str__Eq_str__eq(&name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 1252 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 1253 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 1254 "src/compiler/Usages.pv"
                                        if (usage == 0) {
                                            #line 1254 "src/compiler/Usages.pv"
                                            return;
                                        }
                                        #line 1255 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 1258 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 1261 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1264 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 1270 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
}
