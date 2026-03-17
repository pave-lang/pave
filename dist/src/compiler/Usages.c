#include <stdio.h>

#include <compiler/Generator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/Array_Type.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>
#include <std/HashSet_str.h>
#include <std/str.h>
#include <std/HashMap_usize_TypeUsage_Primitive.h>
#include <stdint.h>
#include <compiler/TypeUsage_Primitive.h>
#include <analyzer/Primitive.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/Struct.h>
#include <std/HashMap_usize_TypeUsage_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <analyzer/Enum.h>
#include <std/HashMap_usize_TypeUsage_Trait.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/Trait.h>
#include <std/Array_ref_Tuple.h>
#include <analyzer/Tuple.h>
#include <tuple_str_Primitive.h>
#include <std/HashMapIter_str_Primitive.h>
#include <std/HashMap_str_Primitive.h>
#include <std/Array_ref_Impl.h>
#include <analyzer/Impl.h>
#include <stdbool.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/Namespace.h>
#include <analyzer/FunctionType.h>
#include <compiler/UsageMode.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Function.h>
#include <analyzer/Sequence.h>
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
#include <analyzer/Generic.h>
#include <analyzer/Generics.h>
#include <analyzer/Token.h>
#include <tuple_str_Enum.h>
#include <std/HashMapIter_str_Enum.h>
#include <std/HashMap_str_Enum.h>
#include <std/ArrayIter_ref_ref_Impl.h>
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
#include <analyzer/ClassCpp.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Indirect.h>
#include <analyzer/IndirectType.h>
#include <analyzer/TypeImpl.h>
#include <analyzer/StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/ArrayIter_ref_Type.h>
#include <analyzer/FunctionParent.h>
#include <compiler/FunctionContext.h>
#include <analyzer/Parameter.h>
#include <std/ArrayIter_ref_Parameter.h>
#include <std/Array_Parameter.h>
#include <analyzer/Block.h>
#include <analyzer/statement/Statement.h>
#include <std/ArrayIter_ref_Statement.h>
#include <std/Array_Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/Expression.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/ArrayIter_ref_ElseStatement.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/MatchCase.h>
#include <std/ArrayIter_ref_MatchCase.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/ExpressionData.h>
#include <analyzer/InvokeArgument.h>
#include <std/ArrayIter_ref_InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/CppExpression.h>
#include <std/Array_ref_GenericMap.h>

#include <compiler/Usages.h>

#line 97 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 98 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 100 "src/compiler/Usages.pv"
    struct Usages self = (struct Usages) {
        .allocator = allocator,
        .generator = generator,
        .root = generator->root,
        .usages = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .usage_types = HashSet_str__new(allocator),
        .usage_traits = HashSet_str__new(allocator),
        .primitives = HashMap_usize_TypeUsage_Primitive__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .functions = HashMap_usize_TypeFunctionUsage__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .structs = HashMap_usize_TypeUsage_Struct__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .enums = HashMap_usize_TypeUsage_Enum__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .traits = HashMap_usize_TypeUsage_Trait__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .sequences = Array_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .tuples = Array_ref_Tuple__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
    };

    #line 118 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 118 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 118 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 119 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 120 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 121 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info, info->impls.length));
            #line 122 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 126 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 128 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 129 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 130 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 131 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 133 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 134 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 134 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 134 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 135 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 135 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 135 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 135 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 136 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 136 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 136 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 136 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 137 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 137 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 137 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 137 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 138 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 138 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 138 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 138 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 139 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 139 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 139 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 140 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 140 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 140 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 141 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 144 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 149 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 151 "src/compiler/Usages.pv"
    return self;
}

#line 154 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 155 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 155 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 155 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 156 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 156 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 156 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 157 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 160 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 164 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 165 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 165 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 165 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 166 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 168 "src/compiler/Usages.pv"
        if ((func_info->generics.array.length == 0) && HashSet_str__insert(&self->usage_types, func_info->name->value)) {
            #line 169 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 170 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
            #line 171 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 172 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
        }
    } }

    #line 176 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&module->enums);
    #line 176 "src/compiler/Usages.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 176 "src/compiler/Usages.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 177 "src/compiler/Usages.pv"
        struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info, enum_info->impls.length));

        #line 179 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 180 "src/compiler/Usages.pv"
        { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
        #line 180 "src/compiler/Usages.pv"
        while (ArrayIter_ref_ref_Impl__next(&__iter)) {
            #line 180 "src/compiler/Usages.pv"
            struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

            #line 181 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 181 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 181 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 182 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 184 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 187 "src/compiler/Usages.pv"
        if ((enum_info->generics.array.length == 0) && HashSet_str__insert(&self->usage_types, enum_info->name->value)) {
            #line 188 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 189 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            #line 190 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 191 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
        }
    } }

    #line 195 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&module->structs);
    #line 195 "src/compiler/Usages.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 195 "src/compiler/Usages.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 196 "src/compiler/Usages.pv"
        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info, struct_info->impls.length));

        #line 198 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 199 "src/compiler/Usages.pv"
        { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
        #line 199 "src/compiler/Usages.pv"
        while (ArrayIter_ref_ref_Impl__next(&__iter)) {
            #line 199 "src/compiler/Usages.pv"
            struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

            #line 200 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 200 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 200 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 201 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 203 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 206 "src/compiler/Usages.pv"
        if ((struct_info->generics.array.length == 0) && HashSet_str__insert(&self->usage_types, struct_info->name->value)) {
            #line 207 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 208 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            #line 209 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 210 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
        }
    } }

    #line 214 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&module->traits);
    #line 214 "src/compiler/Usages.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 214 "src/compiler/Usages.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 215 "src/compiler/Usages.pv"
        struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info, 1));

        #line 217 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 217 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 217 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 218 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
        } }

        #line 221 "src/compiler/Usages.pv"
        if ((trait_info->generics.array.length == 0) && HashSet_str__insert(&self->usage_traits, trait_info->name->value)) {
            #line 222 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 223 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            #line 224 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 225 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
        }
    } }
}

#line 230 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 231 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 232 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 233 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 234 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 235 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;

    #line 237 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 238 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 238 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 239 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 239 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 240 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 240 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 240 "src/compiler/Usages.pv"
            is_type = func_info->generics.array.length > 0;
        } break;
        #line 241 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 241 "src/compiler/Usages.pv"
            is_trait = true;
        } break;
        #line 242 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 242 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 242 "src/compiler/Usages.pv"
            is_type = Sequence__is_slice(sequence);
        } break;
        #line 243 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 243 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 244 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 244 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 245 "src/compiler/Usages.pv"
            if ((self->usage_mode != USAGE_MODE__BODY) && usage_context) {
                #line 246 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->cpp_usages, class_info->name, type);
            }
        } break;
        #line 249 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 252 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 252 "src/compiler/Usages.pv"
        return;
    }

    #line 254 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref, generic_map->self_type, generic_map);
    #line 255 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 257 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 258 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 259 "src/compiler/Usages.pv"
        return;
    }

    #line 262 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref);
}

#line 265 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 266 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
    #line 267 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) { .self_type = self_type });

    #line 269 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 269 "src/compiler/Usages.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 269 "src/compiler/Usages.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 270 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 270 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 270 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 271 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 276 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 278 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 279 "src/compiler/Usages.pv"
    GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 280 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 281 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type });
    #line 282 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 284 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 286 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 286 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 286 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 287 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 291 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 292 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 293 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
    #line 294 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type });
    #line 295 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 297 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 299 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 299 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 299 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 300 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 315 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 316 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 317 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 318 "src/compiler/Usages.pv"
    self->usage_context = &parent_usage->usage_context;

    #line 320 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 320 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 320 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 321 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);
    } }

    #line 324 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
    #line 324 "src/compiler/Usages.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 324 "src/compiler/Usages.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 325 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 325 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 325 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 326 "src/compiler/Usages.pv"
            if (func_info->generics.array.length == 0) {
                #line 327 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            }
        } }
    } }
}

#line 333 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 334 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 334 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 334 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 335 "src/compiler/Usages.pv"
        { struct ArrayIter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 335 "src/compiler/Usages.pv"
        while (ArrayIter_ref_Type__next(&__iter)) {
            #line 335 "src/compiler/Usages.pv"
            struct Type* type = ArrayIter_ref_Type__value(&__iter);

            #line 336 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 340 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
    #line 340 "src/compiler/Usages.pv"
    while (ArrayIter_ref_ref_Impl__next(&__iter)) {
        #line 340 "src/compiler/Usages.pv"
        struct Impl* impl_info = *ArrayIter_ref_ref_Impl__value(&__iter);

        #line 341 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 341 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 341 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 342 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 347 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 348 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 348 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 348 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 349 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }
}

#line 353 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 354 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 356 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 357 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 358 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 359 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 361 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 361 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 361 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 362 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
            #line 363 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
            #line 364 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 366 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index), &func_ptr);
            #line 367 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 369 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 369 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 369 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 370 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(struct_info);
            #line 371 "src/compiler/Usages.pv"
            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
            #line 372 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 374 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 375 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 376 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 378 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 378 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 378 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 379 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(enum_info);
            #line 380 "src/compiler/Usages.pv"
            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
            #line 381 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 383 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 384 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 385 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 387 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 387 "src/compiler/Usages.pv"
            struct Trait* trait_info = func_info->parent.trait_value;
            #line 388 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(trait_info);
            #line 389 "src/compiler/Usages.pv"
            struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
            #line 390 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 392 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, 0), &func_ptr);
            #line 393 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 395 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 398 "src/compiler/Usages.pv"
            return;
        } break;
    }

    #line 402 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 404 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 404 "src/compiler/Usages.pv"
    while (ArrayIter_ref_Parameter__next(&__iter)) {
        #line 404 "src/compiler/Usages.pv"
        struct Parameter* param = ArrayIter_ref_Parameter__value(&__iter);

        #line 405 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 408 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 410 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 412 "src/compiler/Usages.pv"
    self->usage_context = 0;
    #line 413 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 416 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 417 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 417 "src/compiler/Usages.pv"
        return;
    }

    #line 419 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 419 "src/compiler/Usages.pv"
    while (ArrayIter_ref_Statement__next(&__iter)) {
        #line 419 "src/compiler/Usages.pv"
        struct Statement* statement_iter = ArrayIter_ref_Statement__value(&__iter);

        #line 420 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 421 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 421 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 422 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 424 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 424 "src/compiler/Usages.pv"
                struct LetStatement* let_statement = statement_iter->data.letstatement_value;
                #line 425 "src/compiler/Usages.pv"
                if (!let_statement->is_static) {
                    #line 426 "src/compiler/Usages.pv"
                    FunctionContext__add_variable(self->function_context, let_statement->name->value, let_statement->type);
                }

                #line 429 "src/compiler/Usages.pv"
                Usages__add_type(self, let_statement->type, generic_map);

                #line 431 "src/compiler/Usages.pv"
                if (let_statement->value != 0) {
                    #line 432 "src/compiler/Usages.pv"
                    Usages__process_expression(self, let_statement->value, generic_map);
                }
            } break;
            #line 435 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 435 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.returnstatement_value._0;
                #line 436 "src/compiler/Usages.pv"
                if (expression != 0) {
                    #line 437 "src/compiler/Usages.pv"
                    Usages__process_expression(self, expression, generic_map);
                }
            } break;
            #line 440 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 440 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.yieldstatement_value;
                #line 441 "src/compiler/Usages.pv"
                self->function_context->coroutine.yield_count += 1;
                #line 442 "src/compiler/Usages.pv"
                Usages__process_expression(self, expression, generic_map);
            } break;
            #line 444 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 444 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.ifstatement_value._0;
                #line 444 "src/compiler/Usages.pv"
                struct Block* if_block = statement_iter->data.ifstatement_value._1;
                #line 444 "src/compiler/Usages.pv"
                struct Array_ElseStatement* else_statements = &statement_iter->data.ifstatement_value._2;
                #line 445 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);
                #line 446 "src/compiler/Usages.pv"
                Usages__process_block(self, if_block, generic_map);

                #line 448 "src/compiler/Usages.pv"
                { struct ArrayIter_ref_ElseStatement __iter = Array_ElseStatement__iter(else_statements);
                #line 448 "src/compiler/Usages.pv"
                while (ArrayIter_ref_ElseStatement__next(&__iter)) {
                    #line 448 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = ArrayIter_ref_ElseStatement__value(&__iter);

                    #line 449 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 452 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 452 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.matchstatement_value._0;
                #line 452 "src/compiler/Usages.pv"
                struct Array_MatchCase* cases = &statement_iter->data.matchstatement_value._1;
                #line 453 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);

                #line 455 "src/compiler/Usages.pv"
                { struct ArrayIter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 455 "src/compiler/Usages.pv"
                while (ArrayIter_ref_MatchCase__next(&__iter)) {
                    #line 455 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = ArrayIter_ref_MatchCase__value(&__iter);

                    #line 456 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 459 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 459 "src/compiler/Usages.pv"
                struct Expression* condition = statement_iter->data.whilestatement_value._0;
                #line 459 "src/compiler/Usages.pv"
                struct Block* while_block = statement_iter->data.whilestatement_value._1;
                #line 460 "src/compiler/Usages.pv"
                Usages__process_expression(self, condition, generic_map);
                #line 461 "src/compiler/Usages.pv"
                Usages__process_block(self, while_block, generic_map);
            } break;
            #line 463 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 463 "src/compiler/Usages.pv"
                struct ForStatement* for_statement = statement_iter->data.forstatement_value;
                #line 464 "src/compiler/Usages.pv"
                switch (for_statement->type.type) {
                    #line 465 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 465 "src/compiler/Usages.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 465 "src/compiler/Usages.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 466 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 467 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 469 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 469 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 470 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                }

                #line 474 "src/compiler/Usages.pv"
                Usages__process_block(self, for_statement->block, generic_map);
            } break;
            #line 476 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 476 "src/compiler/Usages.pv"
                struct Expression* left = statement_iter->data.assignmentstatement_value._0;
                #line 476 "src/compiler/Usages.pv"
                struct Expression* right = statement_iter->data.assignmentstatement_value._2;
                #line 477 "src/compiler/Usages.pv"
                Usages__process_expression(self, left, generic_map);
                #line 478 "src/compiler/Usages.pv"
                Usages__process_expression(self, right, generic_map);
            } break;
            #line 480 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 480 "src/compiler/Usages.pv"
                struct Expression* expression = statement_iter->data.expressionstatement_value;
                #line 481 "src/compiler/Usages.pv"
                Usages__process_expression(self, expression, generic_map);
            } break;
            #line 483 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 484 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 489 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 490 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 492 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 493 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 494 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 494 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 494 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 495 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 496 "src/compiler/Usages.pv"
            { struct ArrayIter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 496 "src/compiler/Usages.pv"
            while (ArrayIter_ref_InvokeArgument__next(&__iter)) {
                #line 496 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *ArrayIter_ref_InvokeArgument__value(&__iter);

                #line 497 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }
        } break;
        #line 500 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 500 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 500 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 501 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 502 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 503 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 503 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 504 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 506 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 506 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 506 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 507 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 508 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 510 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 510 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 511 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 512 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 514 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 514 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 515 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 516 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 518 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 518 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 518 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 519 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 520 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 522 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 522 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 523 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 525 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 525 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 526 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 527 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 527 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 527 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 528 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 528 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 529 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 531 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 531 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 532 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 536 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 536 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 537 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 539 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0));
            #line 540 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 541 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 541 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 543 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 545 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 546 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 547 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 548 "src/compiler/Usages.pv"
                            usage->impl_dynamic_function = true;
                        } break;
                        #line 550 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 550 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 550 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 551 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 552 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 553 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 554 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 555 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 557 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 557 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 557 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 558 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 559 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 560 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 561 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 562 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 564 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 564 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 564 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 565 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 566 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 567 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 568 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 569 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 571 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 574 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 574 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 575 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 576 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 576 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 577 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 578 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 578 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 579 "src/compiler/Usages.pv"
                                    if (str__eq(trait_info->name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 580 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 581 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 582 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 585 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 588 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 591 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 597 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
    #line 598 "src/compiler/Usages.pv"
    { struct ArrayIter_ref_Type __iter = Array_Type__iter(&self->usages);
    #line 598 "src/compiler/Usages.pv"
    while (ArrayIter_ref_Type__next(&__iter)) {
        #line 598 "src/compiler/Usages.pv"
        struct Type* usage = ArrayIter_ref_Type__value(&__iter);

        #line 599 "src/compiler/Usages.pv"
        switch (usage->type) {
            #line 600 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 600 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage->struct_value._0;
                #line 600 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->struct_value._1;
                #line 601 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(struct_info);
                #line 602 "src/compiler/Usages.pv"
                struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                #line 603 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 605 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 605 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage->enum_value._0;
                #line 605 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->enum_value._1;
                #line 606 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(enum_info);
                #line 607 "src/compiler/Usages.pv"
                struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);

                #line 609 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 611 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 611 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage->trait_value._0;
                #line 611 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->trait_value._1;
                #line 612 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(trait_info);
                #line 613 "src/compiler/Usages.pv"
                struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
                #line 614 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 616 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 616 "src/compiler/Usages.pv"
                struct Function* func_info = usage->function_value._0;
                #line 616 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->function_value._1;
                #line 617 "src/compiler/Usages.pv"
                if (func_info->type == FUNCTION_TYPE__BUILTIN) {
                    #line 617 "src/compiler/Usages.pv"
                    continue;
                }

                #line 619 "src/compiler/Usages.pv"
                uintptr_t func_ptr = (uintptr_t)(func_info);

                #line 621 "src/compiler/Usages.pv"
                switch (func_info->parent.type) {
                    #line 622 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 623 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                        #line 624 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
                    } break;
                    #line 626 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 626 "src/compiler/Usages.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 626 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.struct_value._1;
                        #line 627 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(struct_info);
                        #line 628 "src/compiler/Usages.pv"
                        struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                        #line 629 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 629 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 631 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 632 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 634 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 636 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__ENUM: {
                        #line 636 "src/compiler/Usages.pv"
                        struct Enum* enum_info = func_info->parent.enum_value._0;
                        #line 636 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.enum_value._1;
                        #line 637 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(enum_info);
                        #line 638 "src/compiler/Usages.pv"
                        struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                        #line 639 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 639 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 641 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 642 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 644 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 646 "src/compiler/Usages.pv"
                    default: {
                    } break;
                }
            } break;
            #line 649 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 649 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage->sequence_value;
                #line 650 "src/compiler/Usages.pv"
                Array_Type__append(&self->sequences, sequence->element);
            } break;
            #line 652 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 652 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage->tuple_value;
                #line 653 "src/compiler/Usages.pv"
                Array_ref_Tuple__append(&self->tuples, tuple);
            } break;
            #line 655 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }
}
