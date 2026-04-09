#include <stdio.h>

#include <compiler/Generator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Array_Type.h>
#include <analyzer/types/Type.h>
#include <std/trait_Allocator.h>
#include <std/HashSet_str.h>
#include <std/str.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <stdint.h>
#include <compiler/TypeUsage_Primitive.h>
#include <analyzer/types/Primitive.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/types/Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <analyzer/types/Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/types/Trait.h>
#include <std/Array_ref_Tuple.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/Namespace.h>
#include <tuple_str_Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
#include <std/HashMap_str_Primitive.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <stdbool.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/Array_ref_GenericMap.h>
#include <compiler/UsageMode.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Sequence.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <analyzer/Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <std/HashMap_str_ref_Module.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <std/HashMap_str_Function.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <tuple_str_Enum.h>
#include <std/HashMapIter_str_Enum.h>
#include <std/HashMap_str_Enum.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <tuple_str_Struct.h>
#include <std/HashMapIter_str_Struct.h>
#include <std/HashMap_str_Struct.h>
#include <tuple_str_Trait.h>
#include <std/HashMapIter_str_Trait.h>
#include <std/HashMap_str_Trait.h>
#include <analyzer/Context.h>
#include <compiler/UsageContext.h>
#include <std/HashMap_str_ref_Type.h>
#include <analyzer/c/ClassCpp.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/TypeImpl.h>
#include <analyzer/types/StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/types/EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/Iter_ref_Type.h>
#include <analyzer/types/FunctionParent.h>
#include <compiler/FunctionContext.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <analyzer/Block.h>
#include <analyzer/statement/Statement.h>
#include <std/Iter_ref_Statement.h>
#include <std/Array_Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/expression/Expression.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/CppExpression.h>

#include <compiler/Usages.h>

#line 101 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 102 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 104 "src/compiler/Usages.pv"
    struct Usages self = (struct Usages) {
        .allocator = allocator,
        .generator = generator,
        .root = generator->root,
        .usages = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_types = HashSet_str__new(allocator),
        .usage_traits = HashSet_str__new(allocator),
        .primitives = HashMap_usize_TypeUsage_Primitive__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_usize_TypeUsage_Struct__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_usize_TypeUsage_Enum__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_usize_TypeUsage_Trait__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .sequences = Array_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .tuples = Array_ref_Tuple__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") }),
    };

    #line 124 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 124 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 124 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 125 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 126 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 127 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info, info->impls.length));
            #line 128 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 132 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 134 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 135 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 136 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 137 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 139 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 140 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 140 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 140 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 141 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 141 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 141 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 141 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 142 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 142 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 142 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 142 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 143 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 143 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 143 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 143 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 144 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 144 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 144 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 144 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 145 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 145 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 145 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 146 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 146 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 146 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 147 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 150 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 155 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 157 "src/compiler/Usages.pv"
    return self;
}

#line 160 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 161 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 161 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 161 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 162 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 162 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 162 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 163 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 166 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 170 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 171 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 171 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 171 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 172 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 174 "src/compiler/Usages.pv"
        if (func_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, func_info->name->value)) {
            #line 175 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 176 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
            #line 177 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 178 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
        }
    } }

    #line 182 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&module->enums);
    #line 182 "src/compiler/Usages.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 182 "src/compiler/Usages.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 183 "src/compiler/Usages.pv"
        struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info, enum_info->impls.length));

        #line 185 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 186 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
        #line 186 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 186 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 187 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 187 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 187 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 188 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 190 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 193 "src/compiler/Usages.pv"
        if (enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, enum_info->name->value)) {
            #line 194 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 195 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            #line 196 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 197 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
        }
    } }

    #line 201 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&module->structs);
    #line 201 "src/compiler/Usages.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 201 "src/compiler/Usages.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 202 "src/compiler/Usages.pv"
        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info, struct_info->impls.length));

        #line 204 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 205 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
        #line 205 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 205 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 206 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 206 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 206 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 207 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 209 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 212 "src/compiler/Usages.pv"
        if (struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, struct_info->name->value)) {
            #line 213 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 214 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            #line 215 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 216 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
        }
    } }

    #line 220 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&module->traits);
    #line 220 "src/compiler/Usages.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 220 "src/compiler/Usages.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 221 "src/compiler/Usages.pv"
        struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info, 1));

        #line 223 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 223 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 223 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 224 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
        } }

        #line 227 "src/compiler/Usages.pv"
        if (trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, trait_info->name->value)) {
            #line 228 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 229 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            #line 230 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 231 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
        }
    } }
}

#line 236 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 237 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 238 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 239 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 240 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 241 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;

    #line 243 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 244 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 244 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 245 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 245 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 246 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 246 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 246 "src/compiler/Usages.pv"
            is_type = func_info->generics.array.length > 0;
        } break;
        #line 247 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 247 "src/compiler/Usages.pv"
            is_trait = true;
        } break;
        #line 248 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 248 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 248 "src/compiler/Usages.pv"
            is_type = Sequence__is_slice(sequence);
        } break;
        #line 249 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 249 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 250 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 250 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 251 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY && usage_context) {
                #line 252 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->cpp_usages, class_info->name, type);
            }
        } break;
        #line 255 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 258 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 258 "src/compiler/Usages.pv"
        return;
    }

    #line 260 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref, generic_map->self_type, generic_map);
    #line 261 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 263 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 264 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 265 "src/compiler/Usages.pv"
        return;
    }

    #line 268 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref);
}

#line 271 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 272 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
    #line 273 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) { .self_type = self_type });

    #line 275 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 275 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 275 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 276 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 276 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 276 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 277 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 282 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 284 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 285 "src/compiler/Usages.pv"
    GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 286 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 287 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type });
    #line 288 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 290 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, &generic_map);

    #line 292 "src/compiler/Usages.pv"
    if (self->std_namespace) {
        #line 293 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 294 "src/compiler/Usages.pv"
        struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
        #line 295 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, &(struct Array_Type) { .data = &element_reference, .length = 1 });
        #line 296 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, &generic_map);
    }

    #line 299 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 301 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 301 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 301 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 302 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 306 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 307 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 308 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
    #line 309 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type });
    #line 310 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 312 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 314 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 314 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 314 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 315 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 330 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 331 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 332 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 333 "src/compiler/Usages.pv"
    self->usage_context = &parent_usage->usage_context;

    #line 335 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 335 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 335 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 336 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);
    } }

    #line 339 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
    #line 339 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 339 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 340 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 340 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 340 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 341 "src/compiler/Usages.pv"
            if (func_info->generics.array.length == 0) {
                #line 342 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            }
        } }
    } }
}

#line 348 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 349 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 349 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 349 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 350 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 350 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 350 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 351 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 355 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
    #line 355 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 355 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 356 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 356 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 356 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 357 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 362 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 363 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 363 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 363 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 364 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }
}

#line 368 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 369 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 371 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 372 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 373 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 374 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 376 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 376 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 376 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 377 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
            #line 378 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
            #line 379 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 381 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index), &func_ptr);
            #line 382 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 384 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 384 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 384 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 385 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(struct_info);
            #line 386 "src/compiler/Usages.pv"
            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
            #line 387 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 389 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 390 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 391 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 393 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 393 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 393 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 394 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(enum_info);
            #line 395 "src/compiler/Usages.pv"
            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
            #line 396 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 398 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 399 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 400 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 402 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 402 "src/compiler/Usages.pv"
            struct Trait* trait_info = func_info->parent.trait_value;
            #line 403 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(trait_info);
            #line 404 "src/compiler/Usages.pv"
            struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
            #line 405 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 407 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, 0), &func_ptr);
            #line 408 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 410 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 413 "src/compiler/Usages.pv"
            return;
        } break;
    }

    #line 417 "src/compiler/Usages.pv"
    if (self->std_namespace && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 418 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 419 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, &(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }, &(struct Array_Type) { .data = &func_info->return_type, .length = 1 });
        #line 420 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 423 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 425 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 425 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 425 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 426 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 429 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 431 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 433 "src/compiler/Usages.pv"
    self->usage_context = 0;
    #line 434 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 437 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 438 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 438 "src/compiler/Usages.pv"
        return;
    }

    #line 440 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 440 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 440 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 441 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 442 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 442 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 443 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 445 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 445 "src/compiler/Usages.pv"
                struct LetStatement* let_statement = statement_iter->data.letstatement_value;
                #line 446 "src/compiler/Usages.pv"
                if (!let_statement->is_static) {
                    #line 447 "src/compiler/Usages.pv"
                    FunctionContext__add_variable(self->function_context, let_statement->name->value, let_statement->type);
                }

                #line 450 "src/compiler/Usages.pv"
                Usages__add_type(self, let_statement->type, generic_map);

                #line 452 "src/compiler/Usages.pv"
                if (let_statement->value != 0) {
                    #line 453 "src/compiler/Usages.pv"
                    Usages__process_expression(self, let_statement->value, generic_map);
                }
            } break;
            #line 456 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 456 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.returnstatement_value._0;
                #line 457 "src/compiler/Usages.pv"
                if (expression != 0) {
                    #line 458 "src/compiler/Usages.pv"
                    Usages__process_expression(self, expression, generic_map);
                }
            } break;
            #line 461 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 461 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.yieldstatement_value;
                #line 462 "src/compiler/Usages.pv"
                self->function_context->coroutine.yield_count += 1;
                #line 463 "src/compiler/Usages.pv"
                Usages__process_expression(self, expression, generic_map);
            } break;
            #line 465 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 465 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.ifstatement_value._0;
                #line 465 "src/compiler/Usages.pv"
                struct Block* if_block = statement_iter->data.ifstatement_value._1;
                #line 465 "src/compiler/Usages.pv"
                struct Array_ElseStatement* else_statements = &statement_iter->data.ifstatement_value._2;
                #line 466 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);
                #line 467 "src/compiler/Usages.pv"
                Usages__process_block(self, if_block, generic_map);

                #line 469 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(else_statements);
                #line 469 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 469 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 470 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 473 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 473 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.matchstatement_value._0;
                #line 473 "src/compiler/Usages.pv"
                struct Array_MatchCase* cases = &statement_iter->data.matchstatement_value._1;
                #line 474 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);

                #line 476 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 476 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 476 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 477 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 480 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 480 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.whilestatement_value._0;
                #line 480 "src/compiler/Usages.pv"
                struct Block* while_block = statement_iter->data.whilestatement_value._1;
                #line 481 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);
                #line 482 "src/compiler/Usages.pv"
                Usages__process_block(self, while_block, generic_map);
            } break;
            #line 484 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 484 "src/compiler/Usages.pv"
                struct ForStatement* for_statement = statement_iter->data.forstatement_value;
                #line 485 "src/compiler/Usages.pv"
                switch (for_statement->type.type) {
                    #line 486 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 486 "src/compiler/Usages.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 486 "src/compiler/Usages.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 487 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 488 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 490 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 490 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = for_statement->type.sequence_value;
                        #line 491 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 493 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 493 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 494 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                }

                #line 498 "src/compiler/Usages.pv"
                Usages__process_block(self, for_statement->block, generic_map);
            } break;
            #line 500 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 500 "src/compiler/Usages.pv"
                struct Expression* left = statement_iter->data.assignmentstatement_value._0;
                #line 500 "src/compiler/Usages.pv"
                struct Expression* right = statement_iter->data.assignmentstatement_value._2;
                #line 501 "src/compiler/Usages.pv"
                Usages__process_expression(self, left, generic_map);
                #line 502 "src/compiler/Usages.pv"
                Usages__process_expression(self, right, generic_map);
            } break;
            #line 504 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 504 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.expressionstatement_value;
                #line 505 "src/compiler/Usages.pv"
                Usages__process_expression(self, expression, generic_map);
            } break;
            #line 507 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 508 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 513 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 514 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 516 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 517 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 518 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 518 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 518 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 519 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 520 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 520 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 520 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 521 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }
        } break;
        #line 524 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 524 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 524 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 525 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 526 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 527 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 527 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 528 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 530 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 530 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 530 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 531 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 532 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 534 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 534 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 535 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 536 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 538 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 538 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 539 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 540 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 542 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 542 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 542 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 543 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 544 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 546 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 546 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 547 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 549 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 549 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 549 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 549 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 550 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 551 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 552 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 554 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 554 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 555 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 556 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 556 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 556 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 557 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 557 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 558 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 560 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 560 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 561 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 565 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 565 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 566 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 568 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0));
            #line 569 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 570 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 570 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 572 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 574 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 575 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 576 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 577 "src/compiler/Usages.pv"
                            usage->impl_dynamic_function = true;
                        } break;
                        #line 579 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 579 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 579 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 580 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 581 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 582 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 583 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 584 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 586 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 586 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 586 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 587 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 588 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 589 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 590 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 591 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 593 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 593 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 593 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 594 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 595 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 596 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 597 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 598 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 600 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 603 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 603 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 604 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 605 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 605 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 606 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 607 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 607 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 608 "src/compiler/Usages.pv"
                                    if (str__eq(trait_info->name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 609 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 610 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 611 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 614 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 617 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 620 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 626 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
    #line 627 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&self->usages);
    #line 627 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 627 "src/compiler/Usages.pv"
        struct Type* usage = Iter_ref_Type__value(&__iter);

        #line 628 "src/compiler/Usages.pv"
        switch (usage->type) {
            #line 629 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 629 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage->struct_value._0;
                #line 629 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->struct_value._1;
                #line 630 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(struct_info);
                #line 631 "src/compiler/Usages.pv"
                struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                #line 632 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 634 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 634 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage->enum_value._0;
                #line 634 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->enum_value._1;
                #line 635 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(enum_info);
                #line 636 "src/compiler/Usages.pv"
                struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);

                #line 638 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 640 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 640 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage->trait_value._0;
                #line 640 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->trait_value._1;
                #line 641 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(trait_info);
                #line 642 "src/compiler/Usages.pv"
                struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
                #line 643 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 645 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 645 "src/compiler/Usages.pv"
                struct Function* func_info = usage->function_value._0;
                #line 645 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->function_value._1;
                #line 646 "src/compiler/Usages.pv"
                if (func_info->type == FUNCTION_TYPE__BUILTIN) {
                    #line 646 "src/compiler/Usages.pv"
                    continue;
                }

                #line 648 "src/compiler/Usages.pv"
                uintptr_t func_ptr = (uintptr_t)(func_info);

                #line 650 "src/compiler/Usages.pv"
                switch (func_info->parent.type) {
                    #line 651 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 652 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                        #line 653 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
                    } break;
                    #line 655 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 655 "src/compiler/Usages.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 655 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.struct_value._1;
                        #line 656 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(struct_info);
                        #line 657 "src/compiler/Usages.pv"
                        struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                        #line 658 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 658 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 660 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 661 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 663 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 665 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__ENUM: {
                        #line 665 "src/compiler/Usages.pv"
                        struct Enum* enum_info = func_info->parent.enum_value._0;
                        #line 665 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.enum_value._1;
                        #line 666 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(enum_info);
                        #line 667 "src/compiler/Usages.pv"
                        struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                        #line 668 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 668 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 670 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 671 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 673 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 675 "src/compiler/Usages.pv"
                    default: {
                    } break;
                }
            } break;
            #line 678 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 678 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage->sequence_value;
                #line 679 "src/compiler/Usages.pv"
                Array_Type__append(&self->sequences, sequence->element);
            } break;
            #line 681 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 681 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage->tuple_value;
                #line 682 "src/compiler/Usages.pv"
                Array_ref_Tuple__append(&self->tuples, tuple);
            } break;
            #line 684 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }
}
