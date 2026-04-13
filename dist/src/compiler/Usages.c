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
#include <analyzer/types/FunctionParent.h>
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
#include <analyzer/types/FunctionType.h>
#include <compiler/FunctionContext.h>
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
#include <analyzer/statement/ReturnStatement.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <analyzer/statement/MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/WhileStatement.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/CppExpression.h>

#include <compiler/Usages.h>

#line 108 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 109 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 111 "src/compiler/Usages.pv"
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

    #line 131 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 131 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 131 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 132 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 133 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 134 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info, info->impls.length));
            #line 135 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 139 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 141 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 142 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 143 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 144 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 146 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 147 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 147 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 147 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 148 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 148 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 148 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 148 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 149 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 149 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 149 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 149 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 150 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 150 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 150 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 150 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 151 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 151 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 151 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 151 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 152 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 152 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 152 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 153 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 153 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 153 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 154 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 157 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 162 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 164 "src/compiler/Usages.pv"
    return self;
}

#line 167 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 168 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 168 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 168 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 169 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 169 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 169 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 170 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 173 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 177 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 178 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 178 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 178 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 179 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 181 "src/compiler/Usages.pv"
        if (func_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, func_info->name->value)) {
            #line 182 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 183 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
            #line 184 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 185 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
        }
    } }

    #line 189 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&module->enums);
    #line 189 "src/compiler/Usages.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 189 "src/compiler/Usages.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 190 "src/compiler/Usages.pv"
        struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info, enum_info->impls.length));

        #line 192 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 193 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
        #line 193 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 193 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 194 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 194 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 194 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 195 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 197 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 200 "src/compiler/Usages.pv"
        if (enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, enum_info->name->value)) {
            #line 201 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 202 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            #line 203 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 204 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
        }
    } }

    #line 208 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&module->structs);
    #line 208 "src/compiler/Usages.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 208 "src/compiler/Usages.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 209 "src/compiler/Usages.pv"
        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info, struct_info->impls.length));

        #line 211 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 212 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
        #line 212 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 212 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 213 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 213 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 213 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 214 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 216 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 219 "src/compiler/Usages.pv"
        if (struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, struct_info->name->value)) {
            #line 220 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 221 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            #line 222 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 223 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
        }
    } }

    #line 227 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&module->traits);
    #line 227 "src/compiler/Usages.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 227 "src/compiler/Usages.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 228 "src/compiler/Usages.pv"
        struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info, 1));

        #line 230 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 230 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 230 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 231 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
        } }

        #line 234 "src/compiler/Usages.pv"
        if (trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, trait_info->name->value)) {
            #line 235 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) {});
            #line 236 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            #line 237 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 238 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
        }
    } }
}

#line 243 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 244 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 245 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 246 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 247 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 248 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;

    #line 250 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 251 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 251 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 252 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 252 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 253 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 253 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 253 "src/compiler/Usages.pv"
            struct GenericMap* type_generic_map = type_deref->function_value._1;
            #line 254 "src/compiler/Usages.pv"
            is_type = func_info->generics.array.length > 0;

            #line 256 "src/compiler/Usages.pv"
            switch (func_info->parent.type) {
                #line 257 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 257 "src/compiler/Usages.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 257 "src/compiler/Usages.pv"
                    uintptr_t impl_index = func_info->parent.struct_value._1;
                    #line 258 "src/compiler/Usages.pv"
                    Usages__add_type(self, &(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = type_generic_map} }, generic_map);
                } break;
            }
        } break;
        #line 262 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 262 "src/compiler/Usages.pv"
            is_trait = true;
        } break;
        #line 263 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 263 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 263 "src/compiler/Usages.pv"
            is_type = Sequence__is_slice(sequence);
        } break;
        #line 264 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 264 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 265 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 265 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 266 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY && usage_context) {
                #line 267 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->cpp_usages, class_info->name, type);
            }
        } break;
        #line 270 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 273 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 273 "src/compiler/Usages.pv"
        return;
    }

    #line 275 "src/compiler/Usages.pv"
    struct String type_name_generic = Naming__get_type_name(&self->root->naming_decl, type_deref, generic_map->self_type, 0);

    #line 277 "src/compiler/Usages.pv"
    if (usage_context) {
        #line 278 "src/compiler/Usages.pv"
        switch (self->usage_mode) {
            #line 279 "src/compiler/Usages.pv"
            case USAGE_MODE__LAYOUT: {
                #line 279 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->layout, String__as_str(&type_name_generic), type_deref);
            } break;
            #line 280 "src/compiler/Usages.pv"
            case USAGE_MODE__SIGNATURE: {
                #line 280 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->signature, String__as_str(&type_name_generic), type_deref);
            } break;
            #line 281 "src/compiler/Usages.pv"
            case USAGE_MODE__BODY: {
                #line 281 "src/compiler/Usages.pv"
                HashMap_str_ref_Type__insert(&usage_context->body, String__as_str(&type_name_generic), type_deref);
            } break;
        }
    }

    #line 285 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref, generic_map->self_type, generic_map);
    #line 286 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 288 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 289 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 290 "src/compiler/Usages.pv"
        return;
    }

    #line 293 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref);
}

#line 296 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 297 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
    #line 298 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap) { .self_type = self_type });

    #line 300 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 300 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 300 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 301 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 301 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 301 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 302 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 307 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 309 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 310 "src/compiler/Usages.pv"
    GenericMap__insert(&generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 311 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 312 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type });
    #line 313 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 315 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, &generic_map);

    #line 317 "src/compiler/Usages.pv"
    if (self->std_namespace) {
        #line 318 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 319 "src/compiler/Usages.pv"
        struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
        #line 320 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, &(struct Array_Type) { .data = &element_reference, .length = 1 });
        #line 321 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, &generic_map);
    }

    #line 324 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 326 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 326 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 326 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 327 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 331 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 332 "src/compiler/Usages.pv"
    struct GenericMap generic_map = GenericMap__new(self->allocator, &(struct Generics) {}, &(struct Array_Type) {});
    #line 333 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
    #line 334 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type });
    #line 335 "src/compiler/Usages.pv"
    generic_map.self_type = ArenaAllocator__store_Type(self->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });

    #line 337 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 339 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 339 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 339 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 340 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, &generic_map);
    } }
}

#line 344 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 345 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 346 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 347 "src/compiler/Usages.pv"
    self->usage_context = &parent_usage->usage_context;

    #line 349 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 349 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 349 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 350 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);
    } }

    #line 353 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
    #line 353 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 353 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 354 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 354 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 354 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 355 "src/compiler/Usages.pv"
            if (func_info->generics.array.length == 0) {
                #line 356 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            }
        } }
    } }
}

#line 362 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 363 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 363 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 363 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 364 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 364 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 364 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 365 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 369 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
    #line 369 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 369 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 370 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 370 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 370 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 371 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }
    } }
}

#line 376 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 377 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 377 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 377 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 378 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }
}

#line 382 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 383 "src/compiler/Usages.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 383 "src/compiler/Usages.pv"
        return;
    }

    #line 385 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 387 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 388 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 389 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 390 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
            #line 391 "src/compiler/Usages.pv"
            self->usage_context = &func_usage->usage_context;
        } break;
        #line 393 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 393 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 393 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 394 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
            #line 395 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
            #line 396 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 398 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index), &func_ptr);
            #line 399 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 401 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 401 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 401 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 402 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(struct_info);
            #line 403 "src/compiler/Usages.pv"
            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
            #line 404 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 406 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 407 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 408 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 410 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 410 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 410 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 411 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(enum_info);
            #line 412 "src/compiler/Usages.pv"
            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
            #line 413 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 415 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 416 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 417 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 419 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 419 "src/compiler/Usages.pv"
            struct Trait* trait_info = func_info->parent.trait_value;
            #line 420 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(trait_info);
            #line 421 "src/compiler/Usages.pv"
            struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
            #line 422 "src/compiler/Usages.pv"
            self->usage_context = &parent_usage->usage_context;

            #line 424 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, 0), &func_ptr);
            #line 425 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 427 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 430 "src/compiler/Usages.pv"
            return;
        } break;
    }

    #line 434 "src/compiler/Usages.pv"
    if (self->std_namespace && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 435 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 436 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, &(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }, &(struct Array_Type) { .data = &func_info->return_type, .length = 1 });
        #line 437 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 440 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 442 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 442 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 442 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 443 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 446 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 448 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 450 "src/compiler/Usages.pv"
    self->usage_context = 0;
    #line 451 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 454 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 455 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 455 "src/compiler/Usages.pv"
        return;
    }

    #line 457 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 457 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 457 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 458 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 459 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 459 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 460 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 462 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 462 "src/compiler/Usages.pv"
                struct LetStatement* statement = statement_iter->data.letstatement_value;
                #line 463 "src/compiler/Usages.pv"
                if (!statement->is_static) {
                    #line 464 "src/compiler/Usages.pv"
                    FunctionContext__add_variable(self->function_context, statement->name->value, statement->type);
                }

                #line 467 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->type, generic_map);

                #line 469 "src/compiler/Usages.pv"
                if (statement->value != 0) {
                    #line 470 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->value, generic_map);
                }
            } break;
            #line 473 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 473 "src/compiler/Usages.pv"
                struct ReturnStatement* statement = statement_iter->data.returnstatement_value;
                #line 474 "src/compiler/Usages.pv"
                if (statement->expression != 0) {
                    #line 475 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->expression, generic_map);
                }
            } break;
            #line 478 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 478 "src/compiler/Usages.pv"
                struct YieldStatement* statement = statement_iter->data.yieldstatement_value;
                #line 479 "src/compiler/Usages.pv"
                self->function_context->coroutine.yield_count += 1;
                #line 480 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
            } break;
            #line 482 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 482 "src/compiler/Usages.pv"
                struct IfStatement* statement = statement_iter->data.ifstatement_value;
                #line 483 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 484 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);

                #line 486 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&statement->else_statements);
                #line 486 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 486 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 487 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 490 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 490 "src/compiler/Usages.pv"
                struct MatchStatement* statement = statement_iter->data.matchstatement_value;
                #line 491 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);

                #line 493 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(&statement->cases);
                #line 493 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 493 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 494 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 497 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 497 "src/compiler/Usages.pv"
                struct WhileStatement* statement = statement_iter->data.whilestatement_value;
                #line 498 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 499 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 501 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 501 "src/compiler/Usages.pv"
                struct ForStatement* statement = statement_iter->data.forstatement_value;
                #line 502 "src/compiler/Usages.pv"
                switch (statement->type.type) {
                    #line 503 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 503 "src/compiler/Usages.pv"
                        struct Expression* start = statement->type.range_value._0;
                        #line 503 "src/compiler/Usages.pv"
                        struct Expression* end = statement->type.range_value._1;
                        #line 504 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 505 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 507 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 507 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.sequence_value;
                        #line 508 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 510 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 510 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.iter_value;
                        #line 511 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                }

                #line 515 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 517 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 517 "src/compiler/Usages.pv"
                struct AssignmentStatement* statement = statement_iter->data.assignmentstatement_value;
                #line 518 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->left, generic_map);
                #line 519 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->right, generic_map);
            } break;
            #line 521 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 521 "src/compiler/Usages.pv"
                struct Expression* statement = statement_iter->data.expressionstatement_value;
                #line 522 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement, generic_map);
            } break;
            #line 524 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 525 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 530 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 531 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 533 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 534 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 535 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 535 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 535 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 536 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 537 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 537 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 537 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 538 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }
        } break;
        #line 541 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 541 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 541 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 542 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 543 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 544 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 544 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 545 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 547 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 547 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 547 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 548 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 549 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 551 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 551 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 552 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 553 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 555 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 555 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 556 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 557 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 559 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 559 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 559 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 560 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 561 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 563 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 563 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 564 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 566 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 566 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 566 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 566 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 567 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 568 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 569 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 571 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 571 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 572 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 573 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 573 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 573 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 574 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 574 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 575 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 577 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 577 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 578 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 582 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 582 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 583 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 585 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0));
            #line 586 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 587 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 587 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 589 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 591 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 592 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 593 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 594 "src/compiler/Usages.pv"
                            usage->impl_dynamic_function = true;
                        } break;
                        #line 596 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 596 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 596 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 597 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 598 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 599 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 600 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 601 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 603 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 603 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 603 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 604 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 605 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 606 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 607 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 608 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 610 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 610 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 610 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 611 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 612 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 613 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 614 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 615 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 617 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 620 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 620 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 621 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 622 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 622 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 623 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 624 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 624 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 625 "src/compiler/Usages.pv"
                                    if (str__eq(trait_info->name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 626 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 627 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 628 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 631 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 634 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 637 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 643 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
    #line 644 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&self->usages);
    #line 644 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 644 "src/compiler/Usages.pv"
        struct Type* usage = Iter_ref_Type__value(&__iter);

        #line 645 "src/compiler/Usages.pv"
        switch (usage->type) {
            #line 646 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 646 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage->struct_value._0;
                #line 646 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->struct_value._1;
                #line 647 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(struct_info);
                #line 648 "src/compiler/Usages.pv"
                struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                #line 649 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 651 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 651 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage->enum_value._0;
                #line 651 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->enum_value._1;
                #line 652 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(enum_info);
                #line 653 "src/compiler/Usages.pv"
                struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);

                #line 655 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 657 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 657 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage->trait_value._0;
                #line 657 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->trait_value._1;
                #line 658 "src/compiler/Usages.pv"
                uintptr_t parent_ptr = (uintptr_t)(trait_info);
                #line 659 "src/compiler/Usages.pv"
                struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
                #line 660 "src/compiler/Usages.pv"
                Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
            } break;
            #line 662 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 662 "src/compiler/Usages.pv"
                struct Function* func_info = usage->function_value._0;
                #line 662 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage->function_value._1;
                #line 663 "src/compiler/Usages.pv"
                if (func_info->type == FUNCTION_TYPE__BUILTIN) {
                    #line 663 "src/compiler/Usages.pv"
                    continue;
                }

                #line 665 "src/compiler/Usages.pv"
                uintptr_t func_ptr = (uintptr_t)(func_info);

                #line 667 "src/compiler/Usages.pv"
                switch (func_info->parent.type) {
                    #line 668 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 669 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                        #line 670 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&usage->generic_maps, generic_map);
                    } break;
                    #line 672 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 672 "src/compiler/Usages.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 672 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.struct_value._1;
                        #line 673 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(struct_info);
                        #line 674 "src/compiler/Usages.pv"
                        struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                        #line 675 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 675 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 677 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 678 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 680 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 682 "src/compiler/Usages.pv"
                    case FUNCTION_PARENT__ENUM: {
                        #line 682 "src/compiler/Usages.pv"
                        struct Enum* enum_info = func_info->parent.enum_value._0;
                        #line 682 "src/compiler/Usages.pv"
                        uintptr_t impl_index = func_info->parent.enum_value._1;
                        #line 683 "src/compiler/Usages.pv"
                        uintptr_t parent_ptr = (uintptr_t)(enum_info);
                        #line 684 "src/compiler/Usages.pv"
                        struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                        #line 685 "src/compiler/Usages.pv"
                        if (parent_usage == 0) {
                            #line 685 "src/compiler/Usages.pv"
                            fprintf(stderr, "Could not find parent usage\n");
                        }

                        #line 687 "src/compiler/Usages.pv"
                        struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                        #line 688 "src/compiler/Usages.pv"
                        struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);

                        #line 690 "src/compiler/Usages.pv"
                        Array_ref_GenericMap__append(&impl_function->generic_maps, generic_map);
                    } break;
                    #line 692 "src/compiler/Usages.pv"
                    default: {
                    } break;
                }
            } break;
            #line 695 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 695 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage->sequence_value;
                #line 696 "src/compiler/Usages.pv"
                Array_Type__append(&self->sequences, sequence->element);
            } break;
            #line 698 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 698 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage->tuple_value;
                #line 699 "src/compiler/Usages.pv"
                Array_ref_Tuple__append(&self->tuples, tuple);
            } break;
            #line 701 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }
}
