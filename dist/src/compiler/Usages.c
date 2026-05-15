#include <string.h>
#include <stdbool.h>
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
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/Impl.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <analyzer/types/Function.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <analyzer/Module.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <std/HashMap_str_Enum.h>
#include <std/HashMapIter_str_Enum.h>
#include <tuple_str_Enum.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/HashMap_str_Struct.h>
#include <std/HashMapIter_str_Struct.h>
#include <tuple_str_Struct.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/HashMap_str_Trait.h>
#include <std/HashMapIter_str_Trait.h>
#include <tuple_str_Trait.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/Context.h>
#include <compiler/UsageContext.h>
#include <std/String.h>
#include <analyzer/types/Global.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/ClassCpp.h>
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
#include <compiler/FunctionContext.h>
#include <analyzer/Block.h>
#include <std/Array_Statement.h>
#include <std/Iter_ref_Statement.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/expression/Expression.h>
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
#include <analyzer/types/Generic.h>
#include <analyzer/expression/CppExpression.h>
#include <compiler/Usages.h>

#include <compiler/Usages.h>

#line 125 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 126 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 128 "src/compiler/Usages.pv"
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
    };

    #line 149 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 149 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 149 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 150 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 151 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 152 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* usage = HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info, info->impls.length));
            #line 153 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });

            #line 155 "src/compiler/Usages.pv"
            uintptr_t i = 0;
            #line 156 "src/compiler/Usages.pv"
            { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&info->impls);
            #line 156 "src/compiler/Usages.pv"
            while (Iter_ref_ref_Impl__next(&__iter)) {
                #line 156 "src/compiler/Usages.pv"
                struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                #line 157 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 157 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 157 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 158 "src/compiler/Usages.pv"
                    HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self.allocator, func_info));
                } }
                #line 160 "src/compiler/Usages.pv"
                i += 1;
            } }
        }
    } }

    #line 165 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 167 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 168 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 169 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 170 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 172 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 173 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 173 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 173 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 174 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 174 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 174 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 174 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 175 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 175 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 175 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 175 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 176 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 176 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 176 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 176 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 177 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 177 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 177 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 177 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 178 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 178 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 178 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 179 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 179 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 179 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 180 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 183 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 186 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 188 "src/compiler/Usages.pv"
    return self;
}

#line 191 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 192 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 192 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 192 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 193 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 193 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 193 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 194 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 197 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 201 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 202 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 202 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 202 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 203 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 205 "src/compiler/Usages.pv"
        if (func_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, func_info->name->value)) {
            #line 206 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) {}});
            #line 207 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} }});
            #line 208 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 209 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
        }
    } }

    #line 213 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Enum __iter = HashMap_str_Enum__iter(&module->enums);
    #line 213 "src/compiler/Usages.pv"
    while (HashMapIter_str_Enum__next(&__iter)) {
        #line 213 "src/compiler/Usages.pv"
        struct Enum* enum_info = &HashMapIter_str_Enum__value(&__iter)->_1;

        #line 214 "src/compiler/Usages.pv"
        struct TypeUsage_Enum* usage = HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info, enum_info->impls.length));

        #line 216 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 217 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
        #line 217 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 217 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 218 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 218 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 218 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 219 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 221 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 224 "src/compiler/Usages.pv"
        if (enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, enum_info->name->value)) {
            #line 225 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) {}});
            #line 226 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} }});
            #line 227 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 228 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
        }
    } }

    #line 232 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Struct __iter = HashMap_str_Struct__iter(&module->structs);
    #line 232 "src/compiler/Usages.pv"
    while (HashMapIter_str_Struct__next(&__iter)) {
        #line 232 "src/compiler/Usages.pv"
        struct Struct* struct_info = &HashMapIter_str_Struct__value(&__iter)->_1;

        #line 233 "src/compiler/Usages.pv"
        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info, struct_info->impls.length));

        #line 235 "src/compiler/Usages.pv"
        uintptr_t i = 0;
        #line 236 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
        #line 236 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Impl__next(&__iter)) {
            #line 236 "src/compiler/Usages.pv"
            struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

            #line 237 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
            #line 237 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 237 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 238 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
            } }
            #line 240 "src/compiler/Usages.pv"
            i += 1;
        } }

        #line 243 "src/compiler/Usages.pv"
        if (struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, struct_info->name->value)) {
            #line 244 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) {}});
            #line 245 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} }});
            #line 246 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 247 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
        }
    } }

    #line 251 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Trait __iter = HashMap_str_Trait__iter(&module->traits);
    #line 251 "src/compiler/Usages.pv"
    while (HashMapIter_str_Trait__next(&__iter)) {
        #line 251 "src/compiler/Usages.pv"
        struct Trait* trait_info = &HashMapIter_str_Trait__value(&__iter)->_1;

        #line 252 "src/compiler/Usages.pv"
        struct TypeUsage_Trait* usage = HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info, 1));

        #line 254 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 254 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 254 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 255 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&usage->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));
        } }

        #line 258 "src/compiler/Usages.pv"
        if (trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, trait_info->name->value)) {
            #line 259 "src/compiler/Usages.pv"
            struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) {}});
            #line 260 "src/compiler/Usages.pv"
            struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} }});
            #line 261 "src/compiler/Usages.pv"
            generic_map->self_type = self_type;
            #line 262 "src/compiler/Usages.pv"
            Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
        }
    } }
}

#line 267 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 268 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 269 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 270 "src/compiler/Usages.pv"
    struct Type* type_deref_all = Type__deref_all(resolved_type);
    #line 271 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 272 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 273 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;

    #line 275 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 276 "src/compiler/Usages.pv"
        case TYPE__GLOBAL: {
            #line 276 "src/compiler/Usages.pv"
            struct Global* g = type_deref->global_value;
            #line 277 "src/compiler/Usages.pv"
            struct String path = Generator__make_rel_path(self->generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
            #line 278 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__BODY) {
                #line 279 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->body, String__as_str(&path), *type);
            }
            #line 281 "src/compiler/Usages.pv"
            return;
        } break;
        #line 283 "src/compiler/Usages.pv"
        case TYPE__INDIRECT: {
            #line 284 "src/compiler/Usages.pv"
            switch (type_deref_all->type) {
                #line 285 "src/compiler/Usages.pv"
                case TYPE__PRIMITIVE: {
                    #line 285 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = type_deref_all->primitive_value;
                    #line 286 "src/compiler/Usages.pv"
                    if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                        #line 287 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
                    } else {
                        #line 289 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
                    }

                    #line 292 "src/compiler/Usages.pv"
                    return;
                } break;
                #line 294 "src/compiler/Usages.pv"
                case TYPE__TRAIT: {
                    #line 294 "src/compiler/Usages.pv"
                    struct Trait* trait_info = type_deref_all->trait_value._0;
                    #line 294 "src/compiler/Usages.pv"
                    is_trait = Trait__has_dynamic_dispatch(trait_info);
                } break;
                #line 295 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 298 "src/compiler/Usages.pv"
        case TYPE__PRIMITIVE: {
            #line 298 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = type_deref->primitive_value;
            #line 299 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                #line 300 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
            } else {
                #line 302 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
            }
        } break;
        #line 305 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 305 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 306 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 306 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 307 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 307 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 307 "src/compiler/Usages.pv"
            struct GenericMap* type_generic_map = type_deref->function_value._1;
            #line 308 "src/compiler/Usages.pv"
            is_type = func_info->type != FUNCTION_TYPE__BUILTIN && func_info->generics.array.length > 0;

            #line 310 "src/compiler/Usages.pv"
            switch (func_info->parent.type) {
                #line 311 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__NONE: {
                    #line 312 "src/compiler/Usages.pv"
                    is_type = (func_info->type == FUNCTION_TYPE__STANDARD || func_info->type == FUNCTION_TYPE__COROUTINE) && func_info->name != 0;
                } break;
                #line 314 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 314 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                    #line 315 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }}, generic_map);
                    #line 316 "src/compiler/Usages.pv"
                    is_type = true;
                } break;
                #line 318 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 318 "src/compiler/Usages.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 319 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 321 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 321 "src/compiler/Usages.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 322 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 324 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TRAIT: {
                    #line 324 "src/compiler/Usages.pv"
                    struct Trait* trait_info = func_info->parent.trait_value;
                    #line 325 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 327 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 327 "src/compiler/Usages.pv"
                    struct Type* type_info = func_info->parent.type_value._0;
                    #line 328 "src/compiler/Usages.pv"
                    Usages__add_type(self, type_info, type_generic_map);
                } break;
            }
        } break;
        #line 332 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 332 "src/compiler/Usages.pv"
            struct Trait* trait_info = type_deref->trait_value._0;
            #line 332 "src/compiler/Usages.pv"
            is_trait = Trait__has_dynamic_dispatch(trait_info);
        } break;
        #line 333 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 333 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 334 "src/compiler/Usages.pv"
            is_type = Sequence__is_slice(sequence);
            #line 335 "src/compiler/Usages.pv"
            type = Type__deref(type);
            #line 336 "src/compiler/Usages.pv"
            resolved_type = type_deref;
        } break;
        #line 338 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 338 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 339 "src/compiler/Usages.pv"
        case TYPE__STRUCT_C: {
            #line 339 "src/compiler/Usages.pv"
            struct StructC* struct_c = type_deref->structc_value;
            #line 339 "src/compiler/Usages.pv"
            is_type = !struct_c->include->mode_cpp;
        } break;
        #line 340 "src/compiler/Usages.pv"
        case TYPE__UNION_C: {
            #line 340 "src/compiler/Usages.pv"
            struct StructC* union_c = type_deref->unionc_value;
            #line 340 "src/compiler/Usages.pv"
            is_type = !union_c->include->mode_cpp;
        } break;
        #line 341 "src/compiler/Usages.pv"
        case TYPE__ENUM_C: {
            #line 341 "src/compiler/Usages.pv"
            struct EnumC* enum_c = type_deref->enumc_value;
            #line 341 "src/compiler/Usages.pv"
            is_type = !enum_c->include->mode_cpp;
        } break;
        #line 342 "src/compiler/Usages.pv"
        case TYPE__UNKNOWN_C: {
            #line 342 "src/compiler/Usages.pv"
            struct UnknownC* unknown_c = type_deref->unknownc_value;
            #line 342 "src/compiler/Usages.pv"
            is_type = unknown_c->include != 0;
        } break;
        #line 343 "src/compiler/Usages.pv"
        case TYPE__FUNCTION_C: {
            #line 343 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 344 "src/compiler/Usages.pv"
        case TYPE__TYPEDEF_C: {
            #line 344 "src/compiler/Usages.pv"
            struct TypedefC* typedef_c = type_deref->typedefc_value;
            #line 344 "src/compiler/Usages.pv"
            is_type = !typedef_c->include->mode_cpp;
        } break;
        #line 345 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 345 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 346 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY) {
                #line 347 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->cpp_usages, class_info->name, *type);
            } else {
                #line 349 "src/compiler/Usages.pv"
                is_type = class_info->include->mode_cpp;
            }
        } break;
        #line 352 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 355 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 355 "src/compiler/Usages.pv"
        return;
    }

    #line 357 "src/compiler/Usages.pv"
    struct String type_name_generic = Naming__get_type_name(self->naming_ident, type, generic_map->self_type, generic_map);

    #line 359 "src/compiler/Usages.pv"
    switch (self->usage_mode) {
        #line 360 "src/compiler/Usages.pv"
        case USAGE_MODE__LAYOUT: {
            #line 360 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->layout, String__as_str(&type_name_generic), *type);
        } break;
        #line 361 "src/compiler/Usages.pv"
        case USAGE_MODE__SIGNATURE: {
            #line 361 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->signature, String__as_str(&type_name_generic), *type);
        } break;
        #line 362 "src/compiler/Usages.pv"
        case USAGE_MODE__BODY: {
            #line 362 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->body, String__as_str(&type_name_generic), *type);
        } break;
    }

    #line 365 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 365 "src/compiler/Usages.pv"
        return;
    }

    #line 367 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref_all, generic_map->self_type, generic_map);
    #line 368 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 370 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 371 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 372 "src/compiler/Usages.pv"
        return;
    }

    #line 375 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref_all);
}

#line 378 "src/compiler/Usages.pv"
void Usages__process_impls(struct Usages* self, struct Array_ref_Impl* impls, struct GenericMap* generic_map) {
    #line 379 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 381 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 381 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 381 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 382 "src/compiler/Usages.pv"
        if (impl_info->has_trait) {
            #line 383 "src/compiler/Usages.pv"
            Usages__add_type(self, &impl_info->trait_type, generic_map);

            #line 385 "src/compiler/Usages.pv"
            if (impl_info->trait_ != 0 && !Trait__has_dynamic_dispatch(impl_info->trait_)) {
                #line 386 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 386 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 386 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 387 "src/compiler/Usages.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 387 "src/compiler/Usages.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 387 "src/compiler/Usages.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 388 "src/compiler/Usages.pv"
                        Usages__add_type(self, &param->type, generic_map);
                    } }
                    #line 390 "src/compiler/Usages.pv"
                    Usages__add_type(self, &func_info->return_type, generic_map);
                } }
            }
        }

        #line 395 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 395 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 395 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 396 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 396 "src/compiler/Usages.pv"
                continue;
            }
            #line 397 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }

        #line 400 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 401 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 402 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 402 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 402 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 402 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 403 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 403 "src/compiler/Usages.pv"
                    continue;
                }
                #line 404 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            } }
        }
    } }
}

#line 410 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 411 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
    #line 412 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self_type }});

    #line 414 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 415 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 416 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Primitive__add_usage(parent_usage, generic_map);

    #line 418 "src/compiler/Usages.pv"
    Usages__process_impls(self, &primitive_info->impls, generic_map);

    #line 420 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 423 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 424 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) {}}, (struct Array_Type[]){(struct Array_Type) {}});
    #line 425 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 426 "src/compiler/Usages.pv"
    GenericMap__insert(generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 427 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 428 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type }});
    #line 429 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});

    #line 431 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(sequence);
    #line 432 "src/compiler/Usages.pv"
    struct TypeUsage_Sequence* parent_usage = HashMap_usize_TypeUsage_Sequence__find(&self->sequences, &parent_ptr);
    #line 433 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 434 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Sequence__insert(&self->sequences, parent_ptr, TypeUsage_Sequence__new(self->allocator, sequence, 0));
    }
    #line 436 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Sequence__add_usage(parent_usage, generic_map);

    #line 438 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, generic_map);

    #line 440 "src/compiler/Usages.pv"
    if (self->std_namespace) {
        #line 441 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 442 "src/compiler/Usages.pv"
        struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
        #line 443 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, (struct Array_Type[]){(struct Array_Type) { .data = &element_reference, .length = 1 }});
        #line 444 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 447 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 449 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 449 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 449 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 450 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }
}

#line 454 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 455 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) {}}, (struct Array_Type[]){(struct Array_Type) {}});
    #line 456 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 457 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 459 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(tuple);
    #line 460 "src/compiler/Usages.pv"
    struct TypeUsage_Tuple* parent_usage = HashMap_usize_TypeUsage_Tuple__find(&self->tuples, &parent_ptr);
    #line 461 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 462 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Tuple__insert(&self->tuples, parent_ptr, TypeUsage_Tuple__new(self->allocator, tuple, 0));
    }
    #line 464 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Tuple__add_usage(parent_usage, generic_map);
    #line 465 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 467 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type }});
    #line 468 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});

    #line 470 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
    #line 470 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 470 "src/compiler/Usages.pv"
        struct Type* element = Iter_ref_Type__value(&__iter);

        #line 471 "src/compiler/Usages.pv"
        Usages__add_type(self, element, generic_map);
    } }

    #line 474 "src/compiler/Usages.pv"
    struct Impl* impl_info = self->root->hack_type_impl->impl_info;

    #line 476 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 476 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 476 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 477 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }
}

#line 481 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 482 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 483 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 484 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Struct__add_usage(parent_usage, generic_map);
    #line 485 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 487 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 487 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 487 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 488 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);

        #line 490 "src/compiler/Usages.pv"
        switch (Type__deref_all(&field->type)->type) {
            #line 491 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 491 "src/compiler/Usages.pv"
                struct Function* param_func_info = Type__deref_all(&field->type)->function_value._0;
                #line 491 "src/compiler/Usages.pv"
                struct GenericMap* param_generic_map = Type__deref_all(&field->type)->function_value._1;
                #line 492 "src/compiler/Usages.pv"
                struct GenericMap resolved_generic_map = GenericMap__resolve_types(param_generic_map, self->allocator, generic_map);

                #line 494 "src/compiler/Usages.pv"
                { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&param_func_info->parameters);
                #line 494 "src/compiler/Usages.pv"
                while (Iter_ref_Parameter__next(&__iter)) {
                    #line 494 "src/compiler/Usages.pv"
                    struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                    #line 495 "src/compiler/Usages.pv"
                    Usages__add_type(self, &param->type, &resolved_generic_map);
                } }
                #line 497 "src/compiler/Usages.pv"
                Usages__add_type(self, &param_func_info->return_type, &resolved_generic_map);
            } break;
            #line 499 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 499 "src/compiler/Usages.pv"
                struct Sequence* sequence = Type__deref_all(&field->type)->sequence_value;
                #line 500 "src/compiler/Usages.pv"
                if (Sequence__is_fixed_array(sequence)) {
                    #line 501 "src/compiler/Usages.pv"
                    Usages__add_type(self, &sequence->element, generic_map);
                }
            } break;
            #line 504 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }

    #line 508 "src/compiler/Usages.pv"
    Usages__process_impls(self, &struct_info->impls, generic_map);

    #line 510 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 513 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 514 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 515 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 516 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Enum__add_usage(parent_usage, generic_map);

    #line 518 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 520 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 520 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 520 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 521 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 521 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 521 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 522 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 526 "src/compiler/Usages.pv"
    Usages__process_impls(self, &enum_info->impls, generic_map);

    #line 528 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 531 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 532 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(trait_info);
    #line 533 "src/compiler/Usages.pv"
    struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
    #line 534 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Trait__add_usage(parent_usage, generic_map);

    #line 536 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 536 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 536 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 537 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }

    #line 540 "src/compiler/Usages.pv"
    self->usage_context = 0;
}

#line 543 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 544 "src/compiler/Usages.pv"
    struct UsageContext* parent_usage_context = self->usage_context;

    #line 546 "src/compiler/Usages.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 546 "src/compiler/Usages.pv"
        return;
    }

    #line 548 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 550 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 551 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 552 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 553 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
            #line 554 "src/compiler/Usages.pv"
            self->usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
        } break;
        #line 556 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 556 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 556 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 557 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
            #line 558 "src/compiler/Usages.pv"
            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);

            #line 560 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index), &func_ptr);
            #line 561 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
            #line 562 "src/compiler/Usages.pv"
            self->usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
        } break;
        #line 564 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 564 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 564 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 565 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(struct_info);
            #line 566 "src/compiler/Usages.pv"
            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);

            #line 568 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 569 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 570 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;

            #line 572 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 573 "src/compiler/Usages.pv"
                self->usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            }
        } break;
        #line 576 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 576 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 576 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 577 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(enum_info);
            #line 578 "src/compiler/Usages.pv"
            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);

            #line 580 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
            #line 581 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 582 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;

            #line 584 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 585 "src/compiler/Usages.pv"
                self->usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            }
        } break;
        #line 588 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 588 "src/compiler/Usages.pv"
            struct Trait* trait_info = func_info->parent.trait_value;
            #line 589 "src/compiler/Usages.pv"
            uintptr_t parent_ptr = (uintptr_t)(trait_info);
            #line 590 "src/compiler/Usages.pv"
            struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);

            #line 592 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, 0), &func_ptr);
            #line 593 "src/compiler/Usages.pv"
            self->function_context = &func_usage->function_context;
        } break;
        #line 595 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 596 "src/compiler/Usages.pv"
            return;
        } break;
    }

    #line 600 "src/compiler/Usages.pv"
    if (self->std_namespace && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 601 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        #line 602 "src/compiler/Usages.pv"
        struct Type* sequence_iter = Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }}, (struct Array_Type[]){(struct Array_Type) { .data = &func_info->return_type, .length = 1 }});
        #line 603 "src/compiler/Usages.pv"
        Usages__add_type(self, sequence_iter, generic_map);
    }

    #line 606 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 608 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 608 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 608 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 609 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 612 "src/compiler/Usages.pv"
    Usages__add_type(self, &func_info->return_type, generic_map);

    #line 614 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 616 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 618 "src/compiler/Usages.pv"
    self->usage_context = parent_usage_context;
    #line 619 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 622 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 623 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 623 "src/compiler/Usages.pv"
        return;
    }

    #line 625 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 625 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 625 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 626 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 627 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 627 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 628 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 630 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 630 "src/compiler/Usages.pv"
                struct LetStatement* statement = statement_iter->data.letstatement_value;
                #line 631 "src/compiler/Usages.pv"
                if (!statement->is_static) {
                    #line 632 "src/compiler/Usages.pv"
                    FunctionContext__add_variable(self->function_context, statement->name->value, statement->type);
                }

                #line 635 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->type, generic_map);

                #line 637 "src/compiler/Usages.pv"
                if (statement->value != 0) {
                    #line 638 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->value, generic_map);
                }
            } break;
            #line 641 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 641 "src/compiler/Usages.pv"
                struct ReturnStatement* statement = statement_iter->data.returnstatement_value;
                #line 642 "src/compiler/Usages.pv"
                if (statement->expression != 0) {
                    #line 643 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->expression, generic_map);
                }
            } break;
            #line 646 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 646 "src/compiler/Usages.pv"
                struct YieldStatement* statement = statement_iter->data.yieldstatement_value;
                #line 647 "src/compiler/Usages.pv"
                self->function_context->coroutine.yield_count += 1;
                #line 648 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
            } break;
            #line 650 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 650 "src/compiler/Usages.pv"
                struct IfStatement* statement = statement_iter->data.ifstatement_value;
                #line 651 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 652 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);

                #line 654 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&statement->else_statements);
                #line 654 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 654 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 655 "src/compiler/Usages.pv"
                    if (else_statement->expression) {
                        #line 655 "src/compiler/Usages.pv"
                        Usages__process_expression(self, else_statement->expression, generic_map);
                    }
                    #line 656 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 659 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 659 "src/compiler/Usages.pv"
                struct MatchStatement* statement = statement_iter->data.matchstatement_value;
                #line 660 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);

                #line 662 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(&statement->cases);
                #line 662 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 662 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 663 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 666 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 666 "src/compiler/Usages.pv"
                struct WhileStatement* statement = statement_iter->data.whilestatement_value;
                #line 667 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 668 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 670 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 670 "src/compiler/Usages.pv"
                struct ForStatement* statement = statement_iter->data.forstatement_value;
                #line 671 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 672 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->iter_type, generic_map);
                #line 673 "src/compiler/Usages.pv"
                if (statement->value_type) {
                    #line 674 "src/compiler/Usages.pv"
                    Usages__add_type(self, statement->value_type, generic_map);
                }

                #line 677 "src/compiler/Usages.pv"
                switch (statement->type.type) {
                    #line 678 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 678 "src/compiler/Usages.pv"
                        struct Expression* start = statement->type.range_value._0;
                        #line 678 "src/compiler/Usages.pv"
                        struct Expression* end = statement->type.range_value._1;
                        #line 679 "src/compiler/Usages.pv"
                        struct ForVariable* variable = &statement->variables.data[0];
                        #line 680 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(self->function_context, variable->name->value, variable->type);
                        #line 681 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 682 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 684 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 684 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.sequence_value;
                        #line 685 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 687 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 687 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.iter_value;
                        #line 688 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                }

                #line 692 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 694 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 694 "src/compiler/Usages.pv"
                struct AssignmentStatement* statement = statement_iter->data.assignmentstatement_value;
                #line 695 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->left, generic_map);
                #line 696 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->right, generic_map);
            } break;
            #line 698 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 698 "src/compiler/Usages.pv"
                struct Expression* statement = statement_iter->data.expressionstatement_value;
                #line 699 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement, generic_map);
            } break;
            #line 701 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 702 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 707 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 708 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 710 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 711 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 712 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 712 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 712 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 713 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 714 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 714 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 714 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 715 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }

            #line 718 "src/compiler/Usages.pv"
            switch (target->return_type.type) {
                #line 719 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 719 "src/compiler/Usages.pv"
                    struct Function* func_info = target->return_type.function_value._0;
                    #line 720 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 721 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 722 "src/compiler/Usages.pv"
                            if (arguments.length > 0) {
                                #line 723 "src/compiler/Usages.pv"
                                struct Type* type = Type__deref(&arguments.data[0].value->return_type);

                                #line 725 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 726 "src/compiler/Usages.pv"
                                    case TYPE__GENERIC: {
                                        #line 726 "src/compiler/Usages.pv"
                                        struct Generic* generic = type->generic_value;
                                        #line 727 "src/compiler/Usages.pv"
                                        struct str name = generic->name->value;
                                        #line 728 "src/compiler/Usages.pv"
                                        struct Type* resolved_type = GenericMap__get(generic_map, name);
                                        #line 729 "src/compiler/Usages.pv"
                                        if (resolved_type != 0) {
                                            #line 729 "src/compiler/Usages.pv"
                                            type = resolved_type;
                                        }
                                    } break;
                                    #line 731 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }

                                #line 734 "src/compiler/Usages.pv"
                                struct ArenaAllocator* allocator = self->allocator;
                                #line 735 "src/compiler/Usages.pv"
                                struct UsageContext* usage_context = self->usage_context;

                                #line 737 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 738 "src/compiler/Usages.pv"
                                    case TYPE__PRIMITIVE: {
                                        #line 738 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = type->primitive_value;
                                        #line 739 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 740 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 740 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, primitive_info->name, *type);
                                            } break;
                                            #line 741 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 741 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, primitive_info->name, *type);
                                            } break;
                                            #line 742 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 742 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, primitive_info->name, *type);
                                            } break;
                                        }
                                    } break;
                                    #line 745 "src/compiler/Usages.pv"
                                    case TYPE__TYPEDEF_C: {
                                        #line 745 "src/compiler/Usages.pv"
                                        struct TypedefC* typedef_c = type->typedefc_value;
                                        #line 746 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = ArenaAllocator__store_Primitive(allocator, (struct Primitive[]){(struct Primitive) { .name = typedef_c->name }});
                                        #line 747 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 748 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 748 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 749 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 749 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 750 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 750 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                        }
                                    } break;
                                    #line 753 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }
                            }
                        } break;
                        #line 757 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 760 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 763 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 763 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 763 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 764 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 765 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 766 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 766 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 767 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 769 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 769 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 769 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 770 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 771 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 773 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 773 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 774 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 775 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 777 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 777 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 778 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 779 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 781 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 781 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 781 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 782 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 783 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 785 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 785 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 786 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 788 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 788 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 788 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 788 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 789 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 790 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 791 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 793 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 793 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 794 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 795 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 795 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value._0;
                    #line 795 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value._1;
                    #line 796 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 796 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 797 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 799 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 799 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 800 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 804 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 804 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 805 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 807 "src/compiler/Usages.pv"
            switch (expression->return_type.type) {
                #line 808 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 808 "src/compiler/Usages.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 809 "src/compiler/Usages.pv"
                    if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 810 "src/compiler/Usages.pv"
                        HashSet_str__insert(&self->usage_context->primitive_code, (struct str){ .ptr = "str", .length = strlen("str") });
                    }
                } break;
                #line 813 "src/compiler/Usages.pv"
                default: {
                } break;
            }

            #line 816 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0));
            #line 817 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 818 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 818 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 819 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 821 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 822 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 823 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 824 "src/compiler/Usages.pv"
                            usage->impl_dynamic_function = true;
                        } break;
                        #line 826 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 826 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 826 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 827 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 828 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 829 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 830 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 831 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 833 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 833 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 833 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 834 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 835 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 836 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 837 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 838 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 840 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 840 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 840 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 841 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 842 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 843 "src/compiler/Usages.pv"
                            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage->impl_functions, impl_index);
                            #line 844 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
                            #line 845 "src/compiler/Usages.pv"
                            impl_function->impl_dynamic_function = true;
                        } break;
                        #line 847 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 850 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 850 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 851 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 852 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 852 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 853 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 854 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 854 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 855 "src/compiler/Usages.pv"
                                    if (str__eq(trait_info->name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 856 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 857 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 858 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 861 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 864 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 867 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 873 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
}
