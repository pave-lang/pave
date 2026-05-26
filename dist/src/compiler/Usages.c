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
#include <analyzer/Token.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
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
#include <analyzer/expression/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/expression/CppExpression.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/Usages.h>

#include <compiler/Usages.h>

#line 167 "src/compiler/Usages.pv"
struct Usages Usages__new(struct Generator* generator) {
    #line 168 "src/compiler/Usages.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 170 "src/compiler/Usages.pv"
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
        .dynamic_impl_functions = HashSet_usize__new(allocator),
        .std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") }),
        .usage_mode = USAGE_MODE__LAYOUT,
        .usage_context = 0,
        .function_context = 0,
        .active_impl_index = 0,
    };

    #line 196 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Primitive __iter = HashMap_str_Primitive__iter(&self.root->primitives);
    #line 196 "src/compiler/Usages.pv"
    while (HashMapIter_str_Primitive__next(&__iter)) {
        #line 196 "src/compiler/Usages.pv"
        struct Primitive* info = &HashMapIter_str_Primitive__value(&__iter)->_1;

        #line 197 "src/compiler/Usages.pv"
        if (info->impls.length > 0) {
            #line 198 "src/compiler/Usages.pv"
            uintptr_t primitive_ptr = (uintptr_t)(info);
            #line 199 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Primitive__insert(&self.primitives, primitive_ptr, TypeUsage_Primitive__new(self.allocator, info));
            #line 200 "src/compiler/Usages.pv"
            Array_Type__append(&self.usages, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = info });
        }
    } }

    #line 204 "src/compiler/Usages.pv"
    Usages__add_namespace(&self, &self.root->children);

    #line 206 "src/compiler/Usages.pv"
    uintptr_t usage_i = 0;
    #line 207 "src/compiler/Usages.pv"
    while (usage_i < self.usages.length) {
        #line 208 "src/compiler/Usages.pv"
        struct Type usage = self.usages.data[usage_i];
        #line 209 "src/compiler/Usages.pv"
        self.usage_mode = USAGE_MODE__LAYOUT;

        #line 211 "src/compiler/Usages.pv"
        switch (usage.type) {
            #line 212 "src/compiler/Usages.pv"
            case TYPE__PRIMITIVE: {
                #line 212 "src/compiler/Usages.pv"
                struct Primitive* primitive_info = usage.primitive_value;
                #line 212 "src/compiler/Usages.pv"
                Usages__process_primitive(&self, primitive_info);
            } break;
            #line 213 "src/compiler/Usages.pv"
            case TYPE__STRUCT: {
                #line 213 "src/compiler/Usages.pv"
                struct Struct* struct_info = usage.struct_value._0;
                #line 213 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.struct_value._1;
                #line 213 "src/compiler/Usages.pv"
                Usages__process_struct(&self, struct_info, generic_map);
            } break;
            #line 214 "src/compiler/Usages.pv"
            case TYPE__ENUM: {
                #line 214 "src/compiler/Usages.pv"
                struct Enum* enum_info = usage.enum_value._0;
                #line 214 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.enum_value._1;
                #line 214 "src/compiler/Usages.pv"
                Usages__process_enum(&self, enum_info, generic_map);
            } break;
            #line 215 "src/compiler/Usages.pv"
            case TYPE__TRAIT: {
                #line 215 "src/compiler/Usages.pv"
                struct Trait* trait_info = usage.trait_value._0;
                #line 215 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.trait_value._1;
                #line 215 "src/compiler/Usages.pv"
                Usages__process_trait(&self, trait_info, generic_map);
            } break;
            #line 216 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 216 "src/compiler/Usages.pv"
                struct Function* func_info = usage.function_value._0;
                #line 216 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = usage.function_value._1;
                #line 216 "src/compiler/Usages.pv"
                Usages__process_function(&self, func_info, generic_map);
            } break;
            #line 217 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 217 "src/compiler/Usages.pv"
                struct Sequence* sequence = usage.sequence_value;
                #line 217 "src/compiler/Usages.pv"
                Usages__process_sequence(&self, sequence);
            } break;
            #line 218 "src/compiler/Usages.pv"
            case TYPE__TUPLE: {
                #line 218 "src/compiler/Usages.pv"
                struct Tuple* tuple = usage.tuple_value;
                #line 218 "src/compiler/Usages.pv"
                Usages__process_tuple(&self, tuple);
            } break;
            #line 219 "src/compiler/Usages.pv"
            default: {
            } break;
        }

        #line 222 "src/compiler/Usages.pv"
        usage_i += 1;
    }

    #line 225 "src/compiler/Usages.pv"
    Usages__normalize(&self);

    #line 227 "src/compiler/Usages.pv"
    return self;
}

#line 230 "src/compiler/Usages.pv"
void Usages__add_namespace(struct Usages* self, struct HashMap_str_ref_Namespace* children) {
    #line 231 "src/compiler/Usages.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 231 "src/compiler/Usages.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 231 "src/compiler/Usages.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 232 "src/compiler/Usages.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 232 "src/compiler/Usages.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 232 "src/compiler/Usages.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 233 "src/compiler/Usages.pv"
            Usages__add_module(self, module);
        } }

        #line 236 "src/compiler/Usages.pv"
        Usages__add_namespace(self, &namespace->children);
    } }
}

#line 240 "src/compiler/Usages.pv"
void Usages__add_module(struct Usages* self, struct Module* module) {
    #line 241 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&module->functions);
    #line 241 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 241 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 242 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->functions, (uintptr_t)(func_info), TypeFunctionUsage__new(self->allocator, func_info));

        #line 244 "src/compiler/Usages.pv"
        struct Token* name = func_info->name;
        #line 245 "src/compiler/Usages.pv"
        if (name == 0 || func_info->generics.array.length != 0) {
            #line 245 "src/compiler/Usages.pv"
            continue;
        }

        #line 247 "src/compiler/Usages.pv"
        if (!HashSet_str__insert(&self->usage_types, name->value)) {
            #line 247 "src/compiler/Usages.pv"
            continue;
        }

        #line 249 "src/compiler/Usages.pv"
        struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
        #line 250 "src/compiler/Usages.pv"
        if (generic_map == 0) {
            #line 250 "src/compiler/Usages.pv"
            continue;
        }
        #line 251 "src/compiler/Usages.pv"
        struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} }});
        #line 252 "src/compiler/Usages.pv"
        generic_map->self_type = self_type;
        #line 253 "src/compiler/Usages.pv"
        Array_Type__append(&self->usages, (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generic_map} });
    } }

    #line 256 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Enum __iter = HashMap_str_Array_ref_Enum__iter(&module->enums);
    #line 256 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Enum__next(&__iter)) {
        #line 256 "src/compiler/Usages.pv"
        struct Array_ref_Enum* enum_arr = &HashMapIter_str_Array_ref_Enum__value(&__iter)->_1;

        #line 257 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Enum __iter = Array_ref_Enum__iter(enum_arr);
        #line 257 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Enum__next(&__iter)) {
            #line 257 "src/compiler/Usages.pv"
            struct Enum* enum_info = *Iter_ref_ref_Enum__value(&__iter);

            #line 258 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Enum__insert(&self->enums, (uintptr_t)(enum_info), TypeUsage_Enum__new(self->allocator, enum_info));

            #line 260 "src/compiler/Usages.pv"
            struct Token* name = enum_info->name;
            #line 261 "src/compiler/Usages.pv"
            if (name != 0 && enum_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, name->value)) {
                #line 262 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 263 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} }});
                #line 264 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 264 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 265 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 270 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Struct __iter = HashMap_str_Array_ref_Struct__iter(&module->structs);
    #line 270 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Struct__next(&__iter)) {
        #line 270 "src/compiler/Usages.pv"
        struct Array_ref_Struct* struct_arr = &HashMapIter_str_Array_ref_Struct__value(&__iter)->_1;

        #line 271 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Struct __iter = Array_ref_Struct__iter(struct_arr);
        #line 271 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Struct__next(&__iter)) {
            #line 271 "src/compiler/Usages.pv"
            struct Struct* struct_info = *Iter_ref_ref_Struct__value(&__iter);

            #line 272 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Struct__insert(&self->structs, (uintptr_t)(struct_info), TypeUsage_Struct__new(self->allocator, struct_info));

            #line 274 "src/compiler/Usages.pv"
            struct Token* name = struct_info->name;
            #line 275 "src/compiler/Usages.pv"
            if (name != 0 && struct_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_types, name->value)) {
                #line 276 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 277 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} }});
                #line 278 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 278 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 279 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = generic_map} });
            }
        } }
    } }

    #line 284 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Array_ref_Trait __iter = HashMap_str_Array_ref_Trait__iter(&module->traits);
    #line 284 "src/compiler/Usages.pv"
    while (HashMapIter_str_Array_ref_Trait__next(&__iter)) {
        #line 284 "src/compiler/Usages.pv"
        struct Array_ref_Trait* trait_arr = &HashMapIter_str_Array_ref_Trait__value(&__iter)->_1;

        #line 285 "src/compiler/Usages.pv"
        { struct Iter_ref_ref_Trait __iter = Array_ref_Trait__iter(trait_arr);
        #line 285 "src/compiler/Usages.pv"
        while (Iter_ref_ref_Trait__next(&__iter)) {
            #line 285 "src/compiler/Usages.pv"
            struct Trait* trait_info = *Iter_ref_ref_Trait__value(&__iter);

            #line 286 "src/compiler/Usages.pv"
            HashMap_usize_TypeUsage_Trait__insert(&self->traits, (uintptr_t)(trait_info), TypeUsage_Trait__new(self->allocator, trait_info));

            #line 288 "src/compiler/Usages.pv"
            struct Token* name = trait_info->name;
            #line 289 "src/compiler/Usages.pv"
            if (name != 0 && trait_info->generics.array.length == 0 && HashSet_str__insert(&self->usage_traits, name->value)) {
                #line 290 "src/compiler/Usages.pv"
                struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
                #line 291 "src/compiler/Usages.pv"
                struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} }});
                #line 292 "src/compiler/Usages.pv"
                if (generic_map != 0) {
                    #line 292 "src/compiler/Usages.pv"
                    generic_map->self_type = self_type;
                }
                #line 293 "src/compiler/Usages.pv"
                Array_Type__append(&self->usages, (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = generic_map} });
            }
        } }
    } }
}

#line 299 "src/compiler/Usages.pv"
void Usages__add_type(struct Usages* self, struct Type* type, struct GenericMap* generic_map) {
    #line 300 "src/compiler/Usages.pv"
    struct Type* resolved_type = Context__resolve_type(self->allocator, type, generic_map, 0);
    #line 301 "src/compiler/Usages.pv"
    if (resolved_type == 0) {
        #line 301 "src/compiler/Usages.pv"
        return;
    }

    #line 303 "src/compiler/Usages.pv"
    struct Type* type_deref = Type__deref(resolved_type);
    #line 304 "src/compiler/Usages.pv"
    struct Type* type_deref_all = Type__deref_all(resolved_type);
    #line 305 "src/compiler/Usages.pv"
    bool is_type = false;
    #line 306 "src/compiler/Usages.pv"
    bool is_trait = false;
    #line 307 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = self->usage_context;
    #line 308 "src/compiler/Usages.pv"
    if (usage_context == 0) {
        #line 308 "src/compiler/Usages.pv"
        return;
    }

    #line 310 "src/compiler/Usages.pv"
    switch (type_deref->type) {
        #line 311 "src/compiler/Usages.pv"
        case TYPE__GLOBAL: {
            #line 311 "src/compiler/Usages.pv"
            struct Global* g = type_deref->global_value;
            #line 312 "src/compiler/Usages.pv"
            struct String path = Generator__make_rel_path(self->generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
            #line 313 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__BODY) {
                #line 314 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->body, String__as_str(&path), *type);
            }
            #line 316 "src/compiler/Usages.pv"
            return;
        } break;
        #line 318 "src/compiler/Usages.pv"
        case TYPE__INDIRECT: {
            #line 319 "src/compiler/Usages.pv"
            switch (type_deref_all->type) {
                #line 320 "src/compiler/Usages.pv"
                case TYPE__PRIMITIVE: {
                    #line 320 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = type_deref_all->primitive_value;
                    #line 321 "src/compiler/Usages.pv"
                    if (primitive_info == 0) {
                        #line 321 "src/compiler/Usages.pv"
                        return;
                    }
                    #line 322 "src/compiler/Usages.pv"
                    if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                        #line 323 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
                    } else {
                        #line 325 "src/compiler/Usages.pv"
                        HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
                    }

                    #line 328 "src/compiler/Usages.pv"
                    return;
                } break;
                #line 330 "src/compiler/Usages.pv"
                case TYPE__TRAIT: {
                    #line 330 "src/compiler/Usages.pv"
                    struct Trait* trait_info = type_deref_all->trait_value._0;
                    #line 330 "src/compiler/Usages.pv"
                    is_trait = Trait__has_dynamic_dispatch(trait_info);
                } break;
                #line 331 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 334 "src/compiler/Usages.pv"
        case TYPE__PRIMITIVE: {
            #line 334 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = type_deref->primitive_value;
            #line 335 "src/compiler/Usages.pv"
            if (primitive_info == 0) {
                #line 335 "src/compiler/Usages.pv"
                return;
            }
            #line 336 "src/compiler/Usages.pv"
            if (self->usage_mode == USAGE_MODE__LAYOUT || self->usage_mode == USAGE_MODE__SIGNATURE) {
                #line 337 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_header, primitive_info->name);
            } else {
                #line 339 "src/compiler/Usages.pv"
                HashSet_str__insert(&usage_context->primitive_code, primitive_info->name);
            }
        } break;
        #line 342 "src/compiler/Usages.pv"
        case TYPE__STRUCT: {
            #line 342 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 343 "src/compiler/Usages.pv"
        case TYPE__ENUM: {
            #line 343 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 344 "src/compiler/Usages.pv"
        case TYPE__FUNCTION: {
            #line 344 "src/compiler/Usages.pv"
            struct Function* func_info = type_deref->function_value._0;
            #line 344 "src/compiler/Usages.pv"
            struct GenericMap* type_generic_map = type_deref->function_value._1;
            #line 345 "src/compiler/Usages.pv"
            is_type = func_info->type != FUNCTION_TYPE__BUILTIN && func_info->generics.array.length > 0;

            #line 347 "src/compiler/Usages.pv"
            switch (func_info->parent.type) {
                #line 348 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__NONE: {
                    #line 349 "src/compiler/Usages.pv"
                    is_type = (func_info->type == FUNCTION_TYPE__STANDARD || func_info->type == FUNCTION_TYPE__COROUTINE) && func_info->name != 0;
                } break;
                #line 351 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__PRIMITIVE: {
                    #line 351 "src/compiler/Usages.pv"
                    struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                    #line 352 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }}, generic_map);
                    #line 353 "src/compiler/Usages.pv"
                    is_type = true;
                } break;
                #line 355 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__STRUCT: {
                    #line 355 "src/compiler/Usages.pv"
                    struct Struct* struct_info = func_info->parent.struct_value._0;
                    #line 356 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__STRUCT, .struct_value = { ._0 = struct_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 358 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__ENUM: {
                    #line 358 "src/compiler/Usages.pv"
                    struct Enum* enum_info = func_info->parent.enum_value._0;
                    #line 359 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__ENUM, .enum_value = { ._0 = enum_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 361 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TRAIT: {
                    #line 361 "src/compiler/Usages.pv"
                    struct Trait* trait_info = func_info->parent.trait_value;
                    #line 362 "src/compiler/Usages.pv"
                    Usages__add_type(self, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = trait_info, ._1 = type_generic_map} }}, generic_map);
                } break;
                #line 364 "src/compiler/Usages.pv"
                case FUNCTION_PARENT__TYPE: {
                    #line 364 "src/compiler/Usages.pv"
                    struct Type* type_info = func_info->parent.type_value._0;
                    #line 365 "src/compiler/Usages.pv"
                    Usages__add_type(self, type_info, type_generic_map);
                } break;
            }
        } break;
        #line 369 "src/compiler/Usages.pv"
        case TYPE__TRAIT: {
            #line 369 "src/compiler/Usages.pv"
            struct Trait* trait_info = type_deref->trait_value._0;
            #line 369 "src/compiler/Usages.pv"
            is_trait = Trait__has_dynamic_dispatch(trait_info);
        } break;
        #line 370 "src/compiler/Usages.pv"
        case TYPE__SEQUENCE: {
            #line 370 "src/compiler/Usages.pv"
            struct Sequence* sequence = type_deref->sequence_value;
            #line 371 "src/compiler/Usages.pv"
            switch (sequence->type.type) {
                #line 372 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__FIXED_ARRAY: {
                    #line 372 "src/compiler/Usages.pv"
                    struct Expression* expression = sequence->type.fixedarray_value;
                    #line 373 "src/compiler/Usages.pv"
                    Usages__process_expression(self, expression, generic_map);
                } break;
                #line 375 "src/compiler/Usages.pv"
                case SEQUENCE_TYPE__SLICE: {
                    #line 376 "src/compiler/Usages.pv"
                    is_type = Sequence__is_slice(sequence);
                    #line 377 "src/compiler/Usages.pv"
                    type = Type__deref(type);
                    #line 378 "src/compiler/Usages.pv"
                    resolved_type = type_deref;
                } break;
            }
        } break;
        #line 382 "src/compiler/Usages.pv"
        case TYPE__TUPLE: {
            #line 382 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 383 "src/compiler/Usages.pv"
        case TYPE__STRUCT_C: {
            #line 383 "src/compiler/Usages.pv"
            struct StructC* struct_c = type_deref->structc_value;
            #line 383 "src/compiler/Usages.pv"
            is_type = !struct_c->include->mode_cpp;
        } break;
        #line 384 "src/compiler/Usages.pv"
        case TYPE__UNION_C: {
            #line 384 "src/compiler/Usages.pv"
            struct StructC* union_c = type_deref->unionc_value;
            #line 384 "src/compiler/Usages.pv"
            is_type = !union_c->include->mode_cpp;
        } break;
        #line 385 "src/compiler/Usages.pv"
        case TYPE__ENUM_C: {
            #line 385 "src/compiler/Usages.pv"
            struct EnumC* enum_c = type_deref->enumc_value;
            #line 385 "src/compiler/Usages.pv"
            is_type = !enum_c->include->mode_cpp;
        } break;
        #line 386 "src/compiler/Usages.pv"
        case TYPE__UNKNOWN_C: {
            #line 386 "src/compiler/Usages.pv"
            struct UnknownC* unknown_c = type_deref->unknownc_value;
            #line 386 "src/compiler/Usages.pv"
            is_type = unknown_c->include != 0;
        } break;
        #line 387 "src/compiler/Usages.pv"
        case TYPE__FUNCTION_C: {
            #line 387 "src/compiler/Usages.pv"
            is_type = true;
        } break;
        #line 388 "src/compiler/Usages.pv"
        case TYPE__TYPEDEF_C: {
            #line 388 "src/compiler/Usages.pv"
            struct TypedefC* typedef_c = type_deref->typedefc_value;
            #line 389 "src/compiler/Usages.pv"
            struct Include* include = typedef_c->include;
            #line 390 "src/compiler/Usages.pv"
            if (include == 0) {
                #line 390 "src/compiler/Usages.pv"
                return;
            }
            #line 391 "src/compiler/Usages.pv"
            is_type = !include->mode_cpp;
        } break;
        #line 393 "src/compiler/Usages.pv"
        case TYPE__CLASS_CPP: {
            #line 393 "src/compiler/Usages.pv"
            struct ClassCpp* class_info = type_deref->classcpp_value;
            #line 394 "src/compiler/Usages.pv"
            if (self->usage_mode != USAGE_MODE__BODY) {
                #line 395 "src/compiler/Usages.pv"
                HashMap_str_Type__insert(&usage_context->cpp_usages, class_info->name, *type);
            } else {
                #line 397 "src/compiler/Usages.pv"
                struct Include* include = class_info->include;
                #line 398 "src/compiler/Usages.pv"
                is_type = include->mode_cpp;
            }
        } break;
        #line 401 "src/compiler/Usages.pv"
        default: {
        } break;
    }

    #line 404 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 404 "src/compiler/Usages.pv"
        return;
    }

    #line 406 "src/compiler/Usages.pv"
    struct String type_name_generic = Naming__get_type_name(self->naming_ident, type, generic_map->self_type, generic_map);

    #line 408 "src/compiler/Usages.pv"
    switch (self->usage_mode) {
        #line 409 "src/compiler/Usages.pv"
        case USAGE_MODE__LAYOUT: {
            #line 409 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->layout, String__as_str(&type_name_generic), *type);
        } break;
        #line 410 "src/compiler/Usages.pv"
        case USAGE_MODE__SIGNATURE: {
            #line 410 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->signature, String__as_str(&type_name_generic), *type);
        } break;
        #line 411 "src/compiler/Usages.pv"
        case USAGE_MODE__BODY: {
            #line 411 "src/compiler/Usages.pv"
            HashMap_str_Type__insert(&usage_context->body, String__as_str(&type_name_generic), *type);
        } break;
    }

    #line 414 "src/compiler/Usages.pv"
    if (!is_type && !is_trait) {
        #line 414 "src/compiler/Usages.pv"
        return;
    }

    #line 416 "src/compiler/Usages.pv"
    struct String type_name = Naming__get_type_name(&self->root->naming_decl, type_deref_all, generic_map->self_type, generic_map);
    #line 417 "src/compiler/Usages.pv"
    struct str type_name_str = String__as_str(&type_name);

    #line 419 "src/compiler/Usages.pv"
    if ((is_type && !HashSet_str__insert(&self->usage_types, type_name_str)) || (is_trait && !HashSet_str__insert(&self->usage_traits, type_name_str))) {
        #line 420 "src/compiler/Usages.pv"
        String__release(&type_name);
        #line 421 "src/compiler/Usages.pv"
        return;
    }

    #line 424 "src/compiler/Usages.pv"
    Array_Type__append(&self->usages, *type_deref_all);
}

#line 427 "src/compiler/Usages.pv"
void Usages__process_impls(struct Usages* self, struct Array_ref_Impl* impls, struct GenericMap* generic_map) {
    #line 428 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 430 "src/compiler/Usages.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 430 "src/compiler/Usages.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 430 "src/compiler/Usages.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 430 "src/compiler/Usages.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 431 "src/compiler/Usages.pv"
        self->active_impl_index = impl_index;

        #line 433 "src/compiler/Usages.pv"
        if (impl_info->has_trait) {
            #line 434 "src/compiler/Usages.pv"
            Usages__add_type(self, &impl_info->trait_type, generic_map);

            #line 436 "src/compiler/Usages.pv"
            if (impl_info->trait_ != 0 && !Trait__has_dynamic_dispatch(impl_info->trait_)) {
                #line 437 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 437 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 437 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 438 "src/compiler/Usages.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 438 "src/compiler/Usages.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 438 "src/compiler/Usages.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 439 "src/compiler/Usages.pv"
                        Usages__add_type(self, &param->type, generic_map);
                    } }
                    #line 441 "src/compiler/Usages.pv"
                    Usages__add_type(self, &func_info->return_type, generic_map);
                } }
            }
        }

        #line 446 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 446 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 446 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 447 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0) {
                #line 447 "src/compiler/Usages.pv"
                continue;
            }
            #line 448 "src/compiler/Usages.pv"
            Usages__process_function(self, func_info, generic_map);
        } }

        #line 451 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 452 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 453 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 453 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 453 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 453 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 454 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 454 "src/compiler/Usages.pv"
                    continue;
                }
                #line 455 "src/compiler/Usages.pv"
                Usages__process_function(self, func_info, generic_map);
            } }
        }
    } }

    #line 460 "src/compiler/Usages.pv"
    self->active_impl_index = 0;
}

#line 463 "src/compiler/Usages.pv"
void Usages__process_primitive(struct Usages* self, struct Primitive* primitive_info) {
    #line 464 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 465 "src/compiler/Usages.pv"
    struct Type* self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info }});
    #line 466 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = self_type, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 467 "src/compiler/Usages.pv"
    if (generic_map == 0) {
        #line 467 "src/compiler/Usages.pv"
        return;
    }

    #line 469 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 470 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 471 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 471 "src/compiler/Usages.pv"
        return;
    }

    #line 473 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Primitive__add_usage(parent_usage, generic_map);
    #line 474 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &primitive_info->impls);
    #line 475 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 477 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 479 "src/compiler/Usages.pv"
    Usages__process_impls(self, &primitive_info->impls, generic_map);

    #line 481 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 484 "src/compiler/Usages.pv"
void Usages__process_sequence(struct Usages* self, struct Sequence* sequence) {
    #line 485 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 486 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 487 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 488 "src/compiler/Usages.pv"
    if (generic_map == 0) {
        #line 488 "src/compiler/Usages.pv"
        return;
    }
    #line 489 "src/compiler/Usages.pv"
    GenericMap__insert(generic_map, (struct str){ .ptr = "T", .length = strlen("T") }, sequence->element);
    #line 490 "src/compiler/Usages.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 491 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = sequence_type }});
    #line 492 "src/compiler/Usages.pv"
    if (indirect == 0) {
        #line 492 "src/compiler/Usages.pv"
        return;
    }
    #line 493 "src/compiler/Usages.pv"
    generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    #line 494 "src/compiler/Usages.pv"
    if (generic_map->self_type == 0) {
        #line 494 "src/compiler/Usages.pv"
        return;
    }

    #line 496 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(sequence);
    #line 497 "src/compiler/Usages.pv"
    struct TypeUsage_Sequence* parent_usage = HashMap_usize_TypeUsage_Sequence__find(&self->sequences, &parent_ptr);
    #line 498 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 499 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Sequence__insert(&self->sequences, parent_ptr, TypeUsage_Sequence__new(self->allocator, sequence));
    }
    #line 501 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 501 "src/compiler/Usages.pv"
        return;
    }

    #line 503 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Sequence__add_usage(parent_usage, generic_map);
    #line 504 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 506 "src/compiler/Usages.pv"
    Usages__add_type(self, &sequence->element, generic_map);

    #line 508 "src/compiler/Usages.pv"
    if (self->std_namespace != 0) {
        #line 509 "src/compiler/Usages.pv"
        struct Type* iter_type = Namespace__find_type(self->std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 510 "src/compiler/Usages.pv"
        if (iter_type != 0) {
            #line 511 "src/compiler/Usages.pv"
            struct Type element_reference = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, sequence->element) };
            #line 512 "src/compiler/Usages.pv"
            struct Type* sequence_iter = Root__make_type_usage(self->root, iter_type, (struct Array_Type[]){(struct Array_Type) { .data = &element_reference, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
            #line 513 "src/compiler/Usages.pv"
            if (sequence_iter != 0) {
                #line 514 "src/compiler/Usages.pv"
                Usages__add_type(self, sequence_iter, generic_map);
            }
        }
    }

    #line 519 "src/compiler/Usages.pv"
    struct TypeImpl* root_hack_type = self->root->hack_type_impl;
    #line 520 "src/compiler/Usages.pv"
    if (root_hack_type != 0) {
        #line 521 "src/compiler/Usages.pv"
        struct Impl* impl_info = root_hack_type->impl_info;

        #line 523 "src/compiler/Usages.pv"
        switch (Type__deref_all(&sequence->element)->type) {
            #line 524 "src/compiler/Usages.pv"
            case TYPE__GENERIC: {
            } break;
            #line 525 "src/compiler/Usages.pv"
            case TYPE__GENERIC_TYPEDEF: {
            } break;
            #line 526 "src/compiler/Usages.pv"
            default: {
                #line 527 "src/compiler/Usages.pv"
                { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
                #line 527 "src/compiler/Usages.pv"
                while (HashMapIter_str_Function__next(&__iter)) {
                    #line 527 "src/compiler/Usages.pv"
                    struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                    #line 528 "src/compiler/Usages.pv"
                    Usages__process_function(self, func_info, generic_map);
                } }
            } break;
        }
    }

    #line 534 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 537 "src/compiler/Usages.pv"
void Usages__process_tuple(struct Usages* self, struct Tuple* tuple) {
    #line 538 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 539 "src/compiler/Usages.pv"
    struct GenericMap generic_map_val = GenericMap__new(self->allocator, (struct Generics[]){(struct Generics) { .parent = 0, .array = (struct Array_Generic) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }}, (struct Array_Type[]){(struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 }});
    #line 540 "src/compiler/Usages.pv"
    struct GenericMap* generic_map = ArenaAllocator__store_GenericMap(self->allocator, &generic_map_val);
    #line 541 "src/compiler/Usages.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 543 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(tuple);
    #line 544 "src/compiler/Usages.pv"
    struct TypeUsage_Tuple* parent_usage = HashMap_usize_TypeUsage_Tuple__find(&self->tuples, &parent_ptr);
    #line 545 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 545 "src/compiler/Usages.pv"
        parent_usage = HashMap_usize_TypeUsage_Tuple__insert(&self->tuples, parent_ptr, TypeUsage_Tuple__new(self->allocator, tuple));
    }
    #line 546 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 546 "src/compiler/Usages.pv"
        return;
    }

    #line 548 "src/compiler/Usages.pv"
    self->usage_context = TypeUsage_Tuple__add_usage(parent_usage, generic_map);
    #line 549 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 551 "src/compiler/Usages.pv"
    struct Indirect* indirect = ArenaAllocator__store_Indirect(self->allocator, (struct Indirect[]){(struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = tuple_type }});
    #line 552 "src/compiler/Usages.pv"
    if (generic_map != 0) {
        #line 552 "src/compiler/Usages.pv"
        generic_map->self_type = ArenaAllocator__store_Type(self->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    }

    #line 554 "src/compiler/Usages.pv"
    { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
    #line 554 "src/compiler/Usages.pv"
    while (Iter_ref_Type__next(&__iter)) {
        #line 554 "src/compiler/Usages.pv"
        struct Type* element = Iter_ref_Type__value(&__iter);

        #line 555 "src/compiler/Usages.pv"
        Usages__add_type(self, element, generic_map);
    } }

    #line 558 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 561 "src/compiler/Usages.pv"
void Usages__process_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 562 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 563 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 564 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 565 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 565 "src/compiler/Usages.pv"
        return;
    }
    #line 566 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Struct__add_usage(parent_usage, generic_map);
    #line 567 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &struct_info->impls);
    #line 568 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 570 "src/compiler/Usages.pv"
    self->usage_context = usage_context;
    #line 571 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 573 "src/compiler/Usages.pv"
    { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
    #line 573 "src/compiler/Usages.pv"
    while (HashMapIter_str_StructField__next(&__iter)) {
        #line 573 "src/compiler/Usages.pv"
        struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

        #line 574 "src/compiler/Usages.pv"
        Usages__add_type(self, &field->type, generic_map);

        #line 576 "src/compiler/Usages.pv"
        switch (Type__deref_all(&field->type)->type) {
            #line 577 "src/compiler/Usages.pv"
            case TYPE__FUNCTION: {
                #line 577 "src/compiler/Usages.pv"
                struct Function* param_func_info = Type__deref_all(&field->type)->function_value._0;
                #line 577 "src/compiler/Usages.pv"
                struct GenericMap* param_generic_map = Type__deref_all(&field->type)->function_value._1;
                #line 578 "src/compiler/Usages.pv"
                if (param_generic_map == 0) {
                    #line 578 "src/compiler/Usages.pv"
                    continue;
                }
                #line 579 "src/compiler/Usages.pv"
                struct GenericMap resolved_generic_map = GenericMap__resolve_types(param_generic_map, self->allocator, generic_map);

                #line 581 "src/compiler/Usages.pv"
                { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&param_func_info->parameters);
                #line 581 "src/compiler/Usages.pv"
                while (Iter_ref_Parameter__next(&__iter)) {
                    #line 581 "src/compiler/Usages.pv"
                    struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                    #line 582 "src/compiler/Usages.pv"
                    Usages__add_type(self, &param->type, &resolved_generic_map);
                } }
                #line 584 "src/compiler/Usages.pv"
                Usages__add_type(self, &param_func_info->return_type, &resolved_generic_map);
            } break;
            #line 586 "src/compiler/Usages.pv"
            case TYPE__SEQUENCE: {
                #line 586 "src/compiler/Usages.pv"
                struct Sequence* sequence = Type__deref_all(&field->type)->sequence_value;
                #line 587 "src/compiler/Usages.pv"
                if (Sequence__is_fixed_array(sequence)) {
                    #line 588 "src/compiler/Usages.pv"
                    Usages__add_type(self, &sequence->element, generic_map);
                }
            } break;
            #line 591 "src/compiler/Usages.pv"
            default: {
            } break;
        }
    } }

    #line 595 "src/compiler/Usages.pv"
    Usages__process_impls(self, &struct_info->impls, generic_map);

    #line 597 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 600 "src/compiler/Usages.pv"
void Usages__process_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 601 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 602 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 603 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 604 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 604 "src/compiler/Usages.pv"
        return;
    }
    #line 605 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Enum__add_usage(parent_usage, generic_map);
    #line 606 "src/compiler/Usages.pv"
    UsageContext__populate_impls(usage_context, self->allocator, &enum_info->impls);
    #line 607 "src/compiler/Usages.pv"
    UsageContext__apply_pending_dynamic_functions(usage_context, &self->dynamic_impl_functions);

    #line 609 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 611 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__LAYOUT;

    #line 613 "src/compiler/Usages.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 613 "src/compiler/Usages.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 613 "src/compiler/Usages.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 614 "src/compiler/Usages.pv"
        { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
        #line 614 "src/compiler/Usages.pv"
        while (Iter_ref_Type__next(&__iter)) {
            #line 614 "src/compiler/Usages.pv"
            struct Type* type = Iter_ref_Type__value(&__iter);

            #line 615 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } }
    } }

    #line 619 "src/compiler/Usages.pv"
    Usages__process_impls(self, &enum_info->impls, generic_map);

    #line 621 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 624 "src/compiler/Usages.pv"
void Usages__process_trait(struct Usages* self, struct Trait* trait_info, struct GenericMap* generic_map) {
    #line 625 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 626 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(trait_info);
    #line 627 "src/compiler/Usages.pv"
    struct TypeUsage_Trait* parent_usage = HashMap_usize_TypeUsage_Trait__find(&self->traits, &parent_ptr);
    #line 628 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 628 "src/compiler/Usages.pv"
        return;
    }
    #line 629 "src/compiler/Usages.pv"
    struct UsageContext* usage_context = TypeUsage_Trait__add_usage(parent_usage, generic_map);
    #line 630 "src/compiler/Usages.pv"
    UsageContext__populate_trait_functions(usage_context, self->allocator, trait_info);

    #line 632 "src/compiler/Usages.pv"
    self->usage_context = usage_context;

    #line 634 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 634 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 634 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 635 "src/compiler/Usages.pv"
        Usages__process_function(self, func_info, generic_map);
    } }

    #line 638 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
}

#line 641 "src/compiler/Usages.pv"
bool Usages__usage_context_matches(struct UsageContext* uc, struct Generics* generics, struct GenericMap* generic_map) {
    #line 642 "src/compiler/Usages.pv"
    { struct Iter_ref_Generic __iter = Array_Generic__iter(&generics->array);
    #line 642 "src/compiler/Usages.pv"
    while (Iter_ref_Generic__next(&__iter)) {
        #line 642 "src/compiler/Usages.pv"
        struct Generic generic = *Iter_ref_Generic__value(&__iter);

        #line 643 "src/compiler/Usages.pv"
        struct Token* generic_name = generic.name;
        #line 644 "src/compiler/Usages.pv"
        if (generic_name == 0) {
            #line 644 "src/compiler/Usages.pv"
            return false;
        }
        #line 645 "src/compiler/Usages.pv"
        struct Type* parent_v = GenericMap__get(uc->generic_map, generic_name->value);
        #line 646 "src/compiler/Usages.pv"
        struct Type* func_v = GenericMap__get(generic_map, generic_name->value);
        #line 647 "src/compiler/Usages.pv"
        if (parent_v == 0) {
            #line 647 "src/compiler/Usages.pv"
            return false;
        }
        #line 648 "src/compiler/Usages.pv"
        if (func_v == 0) {
            #line 648 "src/compiler/Usages.pv"
            return false;
        }
        #line 649 "src/compiler/Usages.pv"
        struct Type parent_t = *parent_v;
        #line 650 "src/compiler/Usages.pv"
        if (!Type__eq(&parent_t, func_v)) {
            #line 650 "src/compiler/Usages.pv"
            return false;
        }
    } }
    #line 652 "src/compiler/Usages.pv"
    return true;
}

#line 655 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_struct(struct Usages* self, struct Struct* struct_info, struct GenericMap* generic_map) {
    #line 656 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(struct_info);
    #line 657 "src/compiler/Usages.pv"
    struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
    #line 658 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 658 "src/compiler/Usages.pv"
        return 0;
    }
    #line 659 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 660 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 661 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &struct_info->generics, generic_map)) {
            #line 661 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 663 "src/compiler/Usages.pv"
    return 0;
}

#line 666 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_enum(struct Usages* self, struct Enum* enum_info, struct GenericMap* generic_map) {
    #line 667 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(enum_info);
    #line 668 "src/compiler/Usages.pv"
    struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
    #line 669 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 669 "src/compiler/Usages.pv"
        return 0;
    }
    #line 670 "src/compiler/Usages.pv"
    for (uintptr_t i = 0; i < parent_usage->usage_contexts.length; i++) {
        #line 671 "src/compiler/Usages.pv"
        struct UsageContext* uc = &parent_usage->usage_contexts.data[i];
        #line 672 "src/compiler/Usages.pv"
        if (Usages__usage_context_matches(uc, &enum_info->generics, generic_map)) {
            #line 672 "src/compiler/Usages.pv"
            return uc;
        }
    }
    #line 674 "src/compiler/Usages.pv"
    return 0;
}

#line 677 "src/compiler/Usages.pv"
struct UsageContext* Usages__find_parent_usage_context_primitive(struct Usages* self, struct Primitive* primitive_info, struct GenericMap* generic_map) {
    #line 678 "src/compiler/Usages.pv"
    uintptr_t parent_ptr = (uintptr_t)(primitive_info);
    #line 679 "src/compiler/Usages.pv"
    struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
    #line 680 "src/compiler/Usages.pv"
    if (parent_usage == 0) {
        #line 680 "src/compiler/Usages.pv"
        return 0;
    }
    #line 682 "src/compiler/Usages.pv"
    if (parent_usage->usage_contexts.length > 0) {
        #line 683 "src/compiler/Usages.pv"
        return &parent_usage->usage_contexts.data[0];
    }
    #line 685 "src/compiler/Usages.pv"
    return 0;
}

#line 688 "src/compiler/Usages.pv"
void Usages__process_function(struct Usages* self, struct Function* func_info, struct GenericMap* generic_map) {
    #line 689 "src/compiler/Usages.pv"
    struct UsageContext* entry_usage_context = self->usage_context;
    #line 690 "src/compiler/Usages.pv"
    struct UsageContext* parent_usage_context = 0;

    #line 692 "src/compiler/Usages.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 692 "src/compiler/Usages.pv"
        return;
    }

    #line 694 "src/compiler/Usages.pv"
    uintptr_t func_ptr = (uintptr_t)(func_info);

    #line 696 "src/compiler/Usages.pv"
    switch (func_info->parent.type) {
        #line 697 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__NONE: {
            #line 698 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
            #line 699 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 699 "src/compiler/Usages.pv"
                return;
            }
            #line 700 "src/compiler/Usages.pv"
            struct UsageContext* usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 701 "src/compiler/Usages.pv"
            self->usage_context = usage_context;
            #line 702 "src/compiler/Usages.pv"
            self->function_context = &usage_context->function_context;
        } break;
        #line 704 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__PRIMITIVE: {
            #line 704 "src/compiler/Usages.pv"
            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
            #line 704 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.primitive_value._1;
            #line 705 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 706 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 708 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_primitive(self, primitive_info, generic_map);
            }
            #line 710 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 710 "src/compiler/Usages.pv"
                return;
            }

            #line 712 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 713 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 713 "src/compiler/Usages.pv"
                return;
            }
            #line 714 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 715 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 715 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 715 "src/compiler/Usages.pv"
                return;
            }
            #line 716 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 717 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 718 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 720 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 722 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 724 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 724 "src/compiler/Usages.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 724 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.struct_value._1;
            #line 725 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 726 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 728 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_struct(self, struct_info, generic_map);
            }
            #line 730 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 730 "src/compiler/Usages.pv"
                return;
            }

            #line 732 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 733 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 733 "src/compiler/Usages.pv"
                return;
            }
            #line 734 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 735 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 735 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 735 "src/compiler/Usages.pv"
                return;
            }
            #line 736 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 737 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 738 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 740 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 742 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 744 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__ENUM: {
            #line 744 "src/compiler/Usages.pv"
            struct Enum* enum_info = func_info->parent.enum_value._0;
            #line 744 "src/compiler/Usages.pv"
            uintptr_t impl_index = func_info->parent.enum_value._1;
            #line 745 "src/compiler/Usages.pv"
            if (entry_usage_context != 0 && entry_usage_context->impl_functions.length > impl_index) {
                #line 746 "src/compiler/Usages.pv"
                parent_usage_context = entry_usage_context;
            } else {
                #line 748 "src/compiler/Usages.pv"
                parent_usage_context = Usages__find_parent_usage_context_enum(self, enum_info, generic_map);
            }
            #line 750 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 750 "src/compiler/Usages.pv"
                return;
            }

            #line 752 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 753 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 753 "src/compiler/Usages.pv"
                return;
            }
            #line 754 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 755 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 755 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 755 "src/compiler/Usages.pv"
                return;
            }
            #line 756 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 757 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 758 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 760 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 762 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 764 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TRAIT: {
            #line 765 "src/compiler/Usages.pv"
            parent_usage_context = entry_usage_context;
            #line 766 "src/compiler/Usages.pv"
            if (parent_usage_context == 0) {
                #line 766 "src/compiler/Usages.pv"
                return;
            }

            #line 768 "src/compiler/Usages.pv"
            uintptr_t impl_index = self->active_impl_index;
            #line 769 "src/compiler/Usages.pv"
            if (parent_usage_context->impl_functions.length <= impl_index) {
                #line 769 "src/compiler/Usages.pv"
                impl_index = 0;
            }
            #line 770 "src/compiler/Usages.pv"
            struct HashMap_usize_TypeFunctionUsage* impl_functions = Array_HashMap_usize_TypeFunctionUsage__get(&parent_usage_context->impl_functions, impl_index);
            #line 771 "src/compiler/Usages.pv"
            if (impl_functions == 0) {
                #line 771 "src/compiler/Usages.pv"
                return;
            }
            #line 772 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* func_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions, &func_ptr);
            #line 773 "src/compiler/Usages.pv"
            if (func_usage == 0) {
                #line 773 "src/compiler/Usages.pv"
                self->usage_context = entry_usage_context;
                #line 773 "src/compiler/Usages.pv"
                return;
            }
            #line 774 "src/compiler/Usages.pv"
            struct UsageContext* function_usage_context = TypeFunctionUsage__add_usage(func_usage, generic_map);
            #line 775 "src/compiler/Usages.pv"
            if (func_info->generics.array.length > 0 || entry_usage_context == 0) {
                #line 776 "src/compiler/Usages.pv"
                self->usage_context = function_usage_context;
            } else {
                #line 778 "src/compiler/Usages.pv"
                self->usage_context = parent_usage_context;
            }
            #line 780 "src/compiler/Usages.pv"
            self->function_context = &function_usage_context->function_context;
        } break;
        #line 782 "src/compiler/Usages.pv"
        case FUNCTION_PARENT__TYPE: {
            #line 783 "src/compiler/Usages.pv"
            if (entry_usage_context == 0) {
                #line 783 "src/compiler/Usages.pv"
                return;
            }
            #line 784 "src/compiler/Usages.pv"
            entry_usage_context->function_context = FunctionContext__new(self->allocator, func_info, false);
            #line 785 "src/compiler/Usages.pv"
            self->function_context = &entry_usage_context->function_context;
            #line 786 "src/compiler/Usages.pv"
            self->usage_context = entry_usage_context;
        } break;
    }

    #line 790 "src/compiler/Usages.pv"
    struct Namespace* std_namespace = self->std_namespace;
    #line 791 "src/compiler/Usages.pv"
    if (std_namespace != 0 && func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 792 "src/compiler/Usages.pv"
        struct Trait* iter_trait = Namespace__find_trait(std_namespace, (struct str){ .ptr = "Iter", .length = strlen("Iter") }, 1);
        #line 793 "src/compiler/Usages.pv"
        if (iter_trait != 0) {
            #line 794 "src/compiler/Usages.pv"
            struct Type* sequence_iter = Root__make_type_usage(self->root, (struct Type[]){(struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = iter_trait, ._1 = 0} }}, (struct Array_Type[]){(struct Array_Type) { .data = &func_info->return_type, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .capacity = 0 }});
            #line 795 "src/compiler/Usages.pv"
            if (sequence_iter != 0) {
                #line 796 "src/compiler/Usages.pv"
                Usages__add_type(self, sequence_iter, generic_map);
            }
        }
    }

    #line 801 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__SIGNATURE;

    #line 803 "src/compiler/Usages.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 803 "src/compiler/Usages.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 803 "src/compiler/Usages.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 804 "src/compiler/Usages.pv"
        Usages__add_type(self, &param->type, generic_map);
    } }

    #line 807 "src/compiler/Usages.pv"
    Usages__add_type(self, &func_info->return_type, generic_map);

    #line 809 "src/compiler/Usages.pv"
    self->usage_mode = USAGE_MODE__BODY;

    #line 811 "src/compiler/Usages.pv"
    Usages__process_block(self, func_info->body, generic_map);

    #line 813 "src/compiler/Usages.pv"
    self->usage_context = entry_usage_context;
    #line 814 "src/compiler/Usages.pv"
    self->function_context = 0;
}

#line 817 "src/compiler/Usages.pv"
void Usages__process_block(struct Usages* self, struct Block* block, struct GenericMap* generic_map) {
    #line 818 "src/compiler/Usages.pv"
    if (block == 0) {
        #line 818 "src/compiler/Usages.pv"
        return;
    }

    #line 820 "src/compiler/Usages.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 820 "src/compiler/Usages.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 820 "src/compiler/Usages.pv"
        struct Statement* statement_iter = Iter_ref_Statement__value(&__iter);

        #line 821 "src/compiler/Usages.pv"
        switch (statement_iter->data.type) {
            #line 822 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 822 "src/compiler/Usages.pv"
                struct Block* child_block = statement_iter->data.blockstatement_value;
                #line 823 "src/compiler/Usages.pv"
                Usages__process_block(self, child_block, generic_map);
            } break;
            #line 825 "src/compiler/Usages.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 825 "src/compiler/Usages.pv"
                struct LetStatement* statement = statement_iter->data.letstatement_value;
                #line 826 "src/compiler/Usages.pv"
                if (!statement->is_static) {
                    #line 827 "src/compiler/Usages.pv"
                    struct FunctionContext* function_context = self->function_context;
                    #line 828 "src/compiler/Usages.pv"
                    if (function_context == 0) {
                        #line 828 "src/compiler/Usages.pv"
                        return;
                    }
                    #line 829 "src/compiler/Usages.pv"
                    if (statement->name != 0) {
                        #line 830 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, statement->name->value, statement->type);
                    }

                    #line 833 "src/compiler/Usages.pv"
                    { struct Iter_ref_DestructureBinding __iter = Array_DestructureBinding__iter(&statement->destructure);
                    #line 833 "src/compiler/Usages.pv"
                    while (Iter_ref_DestructureBinding__next(&__iter)) {
                        #line 833 "src/compiler/Usages.pv"
                        struct DestructureBinding* binding = Iter_ref_DestructureBinding__value(&__iter);

                        #line 834 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, binding->name->value, binding->type);
                    } }
                }

                #line 838 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->type, generic_map);

                #line 840 "src/compiler/Usages.pv"
                { struct Iter_ref_DestructureBinding __iter = Array_DestructureBinding__iter(&statement->destructure);
                #line 840 "src/compiler/Usages.pv"
                while (Iter_ref_DestructureBinding__next(&__iter)) {
                    #line 840 "src/compiler/Usages.pv"
                    struct DestructureBinding* binding = Iter_ref_DestructureBinding__value(&__iter);

                    #line 841 "src/compiler/Usages.pv"
                    Usages__add_type(self, binding->type, generic_map);
                } }

                #line 844 "src/compiler/Usages.pv"
                if (statement->value != 0) {
                    #line 845 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->value, generic_map);
                }
            } break;
            #line 848 "src/compiler/Usages.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 848 "src/compiler/Usages.pv"
                struct ReturnStatement* statement = statement_iter->data.returnstatement_value;
                #line 849 "src/compiler/Usages.pv"
                if (statement->expression != 0) {
                    #line 850 "src/compiler/Usages.pv"
                    Usages__process_expression(self, statement->expression, generic_map);
                }
            } break;
            #line 853 "src/compiler/Usages.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 853 "src/compiler/Usages.pv"
                struct YieldStatement* statement = statement_iter->data.yieldstatement_value;
                #line 854 "src/compiler/Usages.pv"
                struct FunctionContext* function_context = self->function_context;
                #line 855 "src/compiler/Usages.pv"
                if (function_context == 0) {
                    #line 855 "src/compiler/Usages.pv"
                    return;
                }
                #line 856 "src/compiler/Usages.pv"
                function_context->coroutine.yield_count += 1;
                #line 857 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
            } break;
            #line 859 "src/compiler/Usages.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 859 "src/compiler/Usages.pv"
                struct IfStatement* statement = statement_iter->data.ifstatement_value;
                #line 860 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 861 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);

                #line 863 "src/compiler/Usages.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&statement->else_statements);
                #line 863 "src/compiler/Usages.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 863 "src/compiler/Usages.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 864 "src/compiler/Usages.pv"
                    if (else_statement->expression != 0) {
                        #line 864 "src/compiler/Usages.pv"
                        Usages__process_expression(self, else_statement->expression, generic_map);
                    }
                    #line 865 "src/compiler/Usages.pv"
                    Usages__process_block(self, else_statement->block, generic_map);
                } }
            } break;
            #line 868 "src/compiler/Usages.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 868 "src/compiler/Usages.pv"
                struct MatchStatement* statement = statement_iter->data.matchstatement_value;
                #line 869 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);

                #line 871 "src/compiler/Usages.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(&statement->cases);
                #line 871 "src/compiler/Usages.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 871 "src/compiler/Usages.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 872 "src/compiler/Usages.pv"
                    Usages__process_block(self, case_info->body, generic_map);
                } }
            } break;
            #line 875 "src/compiler/Usages.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 875 "src/compiler/Usages.pv"
                struct WhileStatement* statement = statement_iter->data.whilestatement_value;
                #line 876 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 877 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 879 "src/compiler/Usages.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 879 "src/compiler/Usages.pv"
                struct ForStatement* statement = statement_iter->data.forstatement_value;
                #line 880 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->expression, generic_map);
                #line 881 "src/compiler/Usages.pv"
                Usages__add_type(self, statement->iter_type, generic_map);
                #line 882 "src/compiler/Usages.pv"
                if (statement->value_type != 0) {
                    #line 883 "src/compiler/Usages.pv"
                    Usages__add_type(self, statement->value_type, generic_map);
                }

                #line 886 "src/compiler/Usages.pv"
                switch (statement->type.type) {
                    #line 887 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 887 "src/compiler/Usages.pv"
                        struct Expression* start = statement->type.range_value._0;
                        #line 887 "src/compiler/Usages.pv"
                        struct Expression* end = statement->type.range_value._1;
                        #line 888 "src/compiler/Usages.pv"
                        struct ForVariable* variable = &statement->variables.data[0];
                        #line 889 "src/compiler/Usages.pv"
                        struct FunctionContext* function_context = self->function_context;
                        #line 890 "src/compiler/Usages.pv"
                        if (function_context == 0) {
                            #line 890 "src/compiler/Usages.pv"
                            return;
                        }
                        #line 891 "src/compiler/Usages.pv"
                        FunctionContext__add_variable(function_context, variable->name->value, variable->type);
                        #line 892 "src/compiler/Usages.pv"
                        Usages__process_expression(self, start, generic_map);
                        #line 893 "src/compiler/Usages.pv"
                        Usages__process_expression(self, end, generic_map);
                    } break;
                    #line 895 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 895 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.sequence_value;
                        #line 896 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 898 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 898 "src/compiler/Usages.pv"
                        struct Expression* iter_expression = statement->type.iter_value;
                        #line 899 "src/compiler/Usages.pv"
                        Usages__process_expression(self, iter_expression, generic_map);
                    } break;
                    #line 901 "src/compiler/Usages.pv"
                    case FOR_STATEMENT_TYPE__ERROR: {
                    } break;
                }

                #line 904 "src/compiler/Usages.pv"
                Usages__process_block(self, statement->block, generic_map);
            } break;
            #line 906 "src/compiler/Usages.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 906 "src/compiler/Usages.pv"
                struct AssignmentStatement* statement = statement_iter->data.assignmentstatement_value;
                #line 907 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->left, generic_map);
                #line 908 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement->right, generic_map);
            } break;
            #line 910 "src/compiler/Usages.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 910 "src/compiler/Usages.pv"
                struct Expression* statement = statement_iter->data.expressionstatement_value;
                #line 911 "src/compiler/Usages.pv"
                Usages__process_expression(self, statement, generic_map);
            } break;
            #line 913 "src/compiler/Usages.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
            } break;
            #line 914 "src/compiler/Usages.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
            } break;
        }
    } }
}

#line 919 "src/compiler/Usages.pv"
void Usages__process_expression(struct Usages* self, struct Expression* expression, struct GenericMap* generic_map) {
    #line 920 "src/compiler/Usages.pv"
    Usages__add_type(self, &expression->return_type, generic_map);

    #line 922 "src/compiler/Usages.pv"
    switch (expression->data.type) {
        #line 923 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
        } break;
        #line 924 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 924 "src/compiler/Usages.pv"
            struct Expression* target = expression->data.invoke_value._0;
            #line 924 "src/compiler/Usages.pv"
            struct Array_InvokeArgument arguments = expression->data.invoke_value._1;
            #line 925 "src/compiler/Usages.pv"
            Usages__process_expression(self, target, generic_map);
            #line 926 "src/compiler/Usages.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(&arguments);
            #line 926 "src/compiler/Usages.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 926 "src/compiler/Usages.pv"
                struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

                #line 927 "src/compiler/Usages.pv"
                Usages__process_expression(self, arg.value, generic_map);
            } }

            #line 930 "src/compiler/Usages.pv"
            switch (target->return_type.type) {
                #line 931 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 931 "src/compiler/Usages.pv"
                    struct Function* func_info = target->return_type.function_value._0;
                    #line 932 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 933 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 934 "src/compiler/Usages.pv"
                            if (arguments.length > 0) {
                                #line 935 "src/compiler/Usages.pv"
                                struct Type* type = Type__deref(&arguments.data[0].value->return_type);

                                #line 937 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 938 "src/compiler/Usages.pv"
                                    case TYPE__GENERIC: {
                                        #line 938 "src/compiler/Usages.pv"
                                        struct Generic* generic = type->generic_value;
                                        #line 939 "src/compiler/Usages.pv"
                                        struct Token* generic_name = generic->name;
                                        #line 940 "src/compiler/Usages.pv"
                                        if (generic_name == 0) {
                                            #line 940 "src/compiler/Usages.pv"
                                            return;
                                        }
                                        #line 941 "src/compiler/Usages.pv"
                                        struct str name = generic_name->value;
                                        #line 942 "src/compiler/Usages.pv"
                                        struct Type* resolved_type = GenericMap__get(generic_map, name);
                                        #line 943 "src/compiler/Usages.pv"
                                        if (resolved_type != 0) {
                                            #line 943 "src/compiler/Usages.pv"
                                            type = resolved_type;
                                        }
                                    } break;
                                    #line 945 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }

                                #line 948 "src/compiler/Usages.pv"
                                struct ArenaAllocator* allocator = self->allocator;
                                #line 949 "src/compiler/Usages.pv"
                                struct UsageContext* usage_context = self->usage_context;
                                #line 950 "src/compiler/Usages.pv"
                                if (usage_context == 0) {
                                    #line 950 "src/compiler/Usages.pv"
                                    return;
                                }

                                #line 952 "src/compiler/Usages.pv"
                                switch (type->type) {
                                    #line 953 "src/compiler/Usages.pv"
                                    case TYPE__PRIMITIVE: {
                                        #line 953 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = type->primitive_value;
                                        #line 954 "src/compiler/Usages.pv"
                                        if (primitive_info == 0) {
                                            #line 954 "src/compiler/Usages.pv"
                                            return;
                                        }

                                        #line 956 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 957 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 957 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, primitive_info->name, *type);
                                            } break;
                                            #line 958 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 958 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, primitive_info->name, *type);
                                            } break;
                                            #line 959 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 959 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, primitive_info->name, *type);
                                            } break;
                                        }
                                    } break;
                                    #line 962 "src/compiler/Usages.pv"
                                    case TYPE__TYPEDEF_C: {
                                        #line 962 "src/compiler/Usages.pv"
                                        struct TypedefC* typedef_c = type->typedefc_value;
                                        #line 963 "src/compiler/Usages.pv"
                                        struct Primitive* primitive_info = ArenaAllocator__store_Primitive(allocator, (struct Primitive[]){(struct Primitive) { .name = typedef_c->name, .traits = (struct HashMap_str_ref_Trait) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 }, .impls = (struct Array_ref_Impl) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->allocator }, .data = 0, .length = 0, .capacity = 0 } }});
                                        #line 964 "src/compiler/Usages.pv"
                                        if (primitive_info == 0) {
                                            #line 964 "src/compiler/Usages.pv"
                                            return;
                                        }

                                        #line 966 "src/compiler/Usages.pv"
                                        switch (self->usage_mode) {
                                            #line 967 "src/compiler/Usages.pv"
                                            case USAGE_MODE__LAYOUT: {
                                                #line 967 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->layout, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 968 "src/compiler/Usages.pv"
                                            case USAGE_MODE__SIGNATURE: {
                                                #line 968 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->signature, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                            #line 969 "src/compiler/Usages.pv"
                                            case USAGE_MODE__BODY: {
                                                #line 969 "src/compiler/Usages.pv"
                                                HashMap_str_Type__insert(&usage_context->body, typedef_c->name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = primitive_info });
                                            } break;
                                        }
                                    } break;
                                    #line 972 "src/compiler/Usages.pv"
                                    default: {
                                    } break;
                                }
                            }
                        } break;
                        #line 976 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 979 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
        #line 982 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 982 "src/compiler/Usages.pv"
            struct Type* type = expression->data.type_value;
            #line 982 "src/compiler/Usages.pv"
            Usages__add_type(self, type, generic_map);
        } break;
        #line 983 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__LITERAL: {
        } break;
        #line 984 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
        } break;
        #line 985 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__VARIABLE: {
        } break;
        #line 986 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 986 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.unaryexpression_value._1;
            #line 987 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 989 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 989 "src/compiler/Usages.pv"
            struct Expression* left = expression->data.binaryexpression_value._0;
            #line 989 "src/compiler/Usages.pv"
            struct Expression* right = expression->data.binaryexpression_value._2;
            #line 990 "src/compiler/Usages.pv"
            Usages__process_expression(self, left, generic_map);
            #line 991 "src/compiler/Usages.pv"
            Usages__process_expression(self, right, generic_map);
        } break;
        #line 993 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 993 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberstaticexpression_value._0;
            #line 994 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 995 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 997 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 997 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.memberinstanceexpression_value._0;
            #line 998 "src/compiler/Usages.pv"
            Usages__add_type(self, Type__deref(&inner->return_type), generic_map);
            #line 999 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1001 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 1001 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.indexexpression_value._0;
            #line 1001 "src/compiler/Usages.pv"
            struct Expression* index = expression->data.indexexpression_value._1;
            #line 1002 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
            #line 1003 "src/compiler/Usages.pv"
            Usages__process_expression(self, index, generic_map);
        } break;
        #line 1005 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 1005 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.parenthesizedexpression_value;
            #line 1006 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);
        } break;
        #line 1008 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 1008 "src/compiler/Usages.pv"
            struct Expression* cond = expression->data.ifexpression_value._0;
            #line 1008 "src/compiler/Usages.pv"
            struct Expression* a = expression->data.ifexpression_value._1;
            #line 1008 "src/compiler/Usages.pv"
            struct Expression* b = expression->data.ifexpression_value._2;
            #line 1009 "src/compiler/Usages.pv"
            Usages__process_expression(self, cond, generic_map);
            #line 1010 "src/compiler/Usages.pv"
            Usages__process_expression(self, a, generic_map);
            #line 1011 "src/compiler/Usages.pv"
            Usages__process_expression(self, b, generic_map);
        } break;
        #line 1013 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
            #line 1013 "src/compiler/Usages.pv"
            struct Expression* value = expression->data.optionalexpression_value._1;
            #line 1014 "src/compiler/Usages.pv"
            Usages__process_expression(self, value, generic_map);
        } break;
        #line 1016 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 1016 "src/compiler/Usages.pv"
            struct CppExpression cpp_expression = expression->data.cppexpression_value;
            #line 1017 "src/compiler/Usages.pv"
            switch (cpp_expression.type) {
                #line 1018 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 1018 "src/compiler/Usages.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 1018 "src/compiler/Usages.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 1019 "src/compiler/Usages.pv"
                    if (placement != 0) {
                        #line 1019 "src/compiler/Usages.pv"
                        Usages__process_expression(self, placement, generic_map);
                    }
                    #line 1020 "src/compiler/Usages.pv"
                    Usages__process_expression(self, new_expression, generic_map);
                } break;
                #line 1022 "src/compiler/Usages.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 1022 "src/compiler/Usages.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 1023 "src/compiler/Usages.pv"
                    Usages__process_expression(self, delete_expression, generic_map);
                } break;
            }
        } break;
        #line 1027 "src/compiler/Usages.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 1027 "src/compiler/Usages.pv"
            struct Expression* inner = expression->data.implicitcast_value;
            #line 1028 "src/compiler/Usages.pv"
            Usages__process_expression(self, inner, generic_map);

            #line 1030 "src/compiler/Usages.pv"
            switch (expression->return_type.type) {
                #line 1031 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 1031 "src/compiler/Usages.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 1032 "src/compiler/Usages.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 1033 "src/compiler/Usages.pv"
                    struct UsageContext* usage_context = self->usage_context;
                    #line 1034 "src/compiler/Usages.pv"
                    if (struct_name != 0 && str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 1035 "src/compiler/Usages.pv"
                        if (usage_context != 0) {
                            #line 1036 "src/compiler/Usages.pv"
                            HashSet_str__insert(&usage_context->primitive_code, (struct str){ .ptr = "str", .length = strlen("str") });
                        }
                    }
                } break;
                #line 1040 "src/compiler/Usages.pv"
                default: {
                } break;
            }

            #line 1043 "src/compiler/Usages.pv"
            struct Type* return_type_nullable = Context__resolve_type(self->allocator, &inner->return_type, generic_map, 0);
            #line 1044 "src/compiler/Usages.pv"
            if (return_type_nullable == 0) {
                #line 1044 "src/compiler/Usages.pv"
                return;
            }
            #line 1045 "src/compiler/Usages.pv"
            struct Type* return_type = Type__deref(return_type_nullable);

            #line 1047 "src/compiler/Usages.pv"
            switch (return_type->type) {
                #line 1048 "src/compiler/Usages.pv"
                case TYPE__FUNCTION: {
                    #line 1048 "src/compiler/Usages.pv"
                    struct Function* func_info = return_type->function_value._0;
                    #line 1049 "src/compiler/Usages.pv"
                    uintptr_t func_ptr = (uintptr_t)(func_info);

                    #line 1051 "src/compiler/Usages.pv"
                    switch (func_info->parent.type) {
                        #line 1052 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__NONE: {
                            #line 1053 "src/compiler/Usages.pv"
                            struct TypeFunctionUsage* usage = HashMap_usize_TypeFunctionUsage__find(&self->functions, &func_ptr);
                            #line 1054 "src/compiler/Usages.pv"
                            if (usage == 0) {
                                #line 1054 "src/compiler/Usages.pv"
                                return;
                            }

                            #line 1056 "src/compiler/Usages.pv"
                            if (func_info->generics.array.length == 0) {
                                #line 1057 "src/compiler/Usages.pv"
                                usage->impl_dynamic_function = true;
                            }
                            #line 1059 "src/compiler/Usages.pv"
                            { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
                            #line 1059 "src/compiler/Usages.pv"
                            while (Iter_ref_UsageContext__next(&__iter)) {
                                #line 1059 "src/compiler/Usages.pv"
                                struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                #line 1060 "src/compiler/Usages.pv"
                                uc.impl_dynamic_function = true;
                            } }
                        } break;
                        #line 1063 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__PRIMITIVE: {
                            #line 1063 "src/compiler/Usages.pv"
                            struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                            #line 1063 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.primitive_value._1;
                            #line 1064 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(primitive_info);
                            #line 1065 "src/compiler/Usages.pv"
                            struct TypeUsage_Primitive* parent_usage = HashMap_usize_TypeUsage_Primitive__find(&self->primitives, &parent_ptr);
                            #line 1066 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1067 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1068 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1068 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1068 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1069 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1070 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1070 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1072 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1073 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1074 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1075 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1076 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1078 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1078 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1078 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1079 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1084 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1084 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1086 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__STRUCT: {
                            #line 1086 "src/compiler/Usages.pv"
                            struct Struct* struct_info = func_info->parent.struct_value._0;
                            #line 1086 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.struct_value._1;
                            #line 1087 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(struct_info);
                            #line 1088 "src/compiler/Usages.pv"
                            struct TypeUsage_Struct* parent_usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &parent_ptr);
                            #line 1089 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1090 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1091 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1091 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1091 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1092 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1093 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1093 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1095 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1096 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1097 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1098 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1099 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1101 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1101 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1101 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1102 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1107 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1107 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1109 "src/compiler/Usages.pv"
                        case FUNCTION_PARENT__ENUM: {
                            #line 1109 "src/compiler/Usages.pv"
                            struct Enum* enum_info = func_info->parent.enum_value._0;
                            #line 1109 "src/compiler/Usages.pv"
                            uintptr_t impl_index = func_info->parent.enum_value._1;
                            #line 1110 "src/compiler/Usages.pv"
                            uintptr_t parent_ptr = (uintptr_t)(enum_info);
                            #line 1111 "src/compiler/Usages.pv"
                            struct TypeUsage_Enum* parent_usage = HashMap_usize_TypeUsage_Enum__find(&self->enums, &parent_ptr);
                            #line 1112 "src/compiler/Usages.pv"
                            bool marked = false;
                            #line 1113 "src/compiler/Usages.pv"
                            if (parent_usage != 0) {
                                #line 1114 "src/compiler/Usages.pv"
                                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&parent_usage->usage_contexts);
                                #line 1114 "src/compiler/Usages.pv"
                                while (Iter_ref_UsageContext__next(&__iter)) {
                                    #line 1114 "src/compiler/Usages.pv"
                                    struct UsageContext uc = *Iter_ref_UsageContext__value(&__iter);

                                    #line 1115 "src/compiler/Usages.pv"
                                    struct HashMap_usize_TypeFunctionUsage* usage_context_function = Array_HashMap_usize_TypeFunctionUsage__get(&uc.impl_functions, impl_index);
                                    #line 1116 "src/compiler/Usages.pv"
                                    if (usage_context_function == 0) {
                                        #line 1116 "src/compiler/Usages.pv"
                                        continue;
                                    }

                                    #line 1118 "src/compiler/Usages.pv"
                                    struct TypeFunctionUsage* impl_function = HashMap_usize_TypeFunctionUsage__find(usage_context_function, &func_ptr);
                                    #line 1119 "src/compiler/Usages.pv"
                                    if (impl_function != 0) {
                                        #line 1120 "src/compiler/Usages.pv"
                                        marked = true;
                                        #line 1121 "src/compiler/Usages.pv"
                                        if (func_info->generics.array.length == 0) {
                                            #line 1122 "src/compiler/Usages.pv"
                                            impl_function->impl_dynamic_function = true;
                                        }
                                        #line 1124 "src/compiler/Usages.pv"
                                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&impl_function->usage_contexts);
                                        #line 1124 "src/compiler/Usages.pv"
                                        while (Iter_ref_UsageContext__next(&__iter)) {
                                            #line 1124 "src/compiler/Usages.pv"
                                            struct UsageContext func_uc = *Iter_ref_UsageContext__value(&__iter);

                                            #line 1125 "src/compiler/Usages.pv"
                                            func_uc.impl_dynamic_function = true;
                                        } }
                                    }
                                } }
                            }
                            #line 1130 "src/compiler/Usages.pv"
                            if (!marked) {
                                #line 1130 "src/compiler/Usages.pv"
                                HashSet_usize__insert(&self->dynamic_impl_functions, func_ptr);
                            }
                        } break;
                        #line 1132 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1135 "src/compiler/Usages.pv"
                case TYPE__STRUCT: {
                    #line 1135 "src/compiler/Usages.pv"
                    struct Struct* struct_info = return_type->struct_value._0;
                    #line 1136 "src/compiler/Usages.pv"
                    switch (expression->return_type.type) {
                        #line 1137 "src/compiler/Usages.pv"
                        case TYPE__INDIRECT: {
                            #line 1137 "src/compiler/Usages.pv"
                            struct Indirect* indirect = expression->return_type.indirect_value;
                            #line 1138 "src/compiler/Usages.pv"
                            switch (indirect->to.type) {
                                #line 1139 "src/compiler/Usages.pv"
                                case TYPE__TRAIT: {
                                    #line 1139 "src/compiler/Usages.pv"
                                    struct Trait* trait_info = indirect->to.trait_value._0;
                                    #line 1140 "src/compiler/Usages.pv"
                                    struct Token* name = trait_info->name;
                                    #line 1141 "src/compiler/Usages.pv"
                                    if (name == 0) {
                                        #line 1141 "src/compiler/Usages.pv"
                                        return;
                                    }

                                    #line 1143 "src/compiler/Usages.pv"
                                    if (str__Eq_str__eq(&name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                                        #line 1144 "src/compiler/Usages.pv"
                                        uintptr_t ptr = (uintptr_t)(struct_info);
                                        #line 1145 "src/compiler/Usages.pv"
                                        struct TypeUsage_Struct* usage = HashMap_usize_TypeUsage_Struct__find(&self->structs, &ptr);
                                        #line 1146 "src/compiler/Usages.pv"
                                        if (usage == 0) {
                                            #line 1146 "src/compiler/Usages.pv"
                                            return;
                                        }
                                        #line 1147 "src/compiler/Usages.pv"
                                        usage->impl_dynamic_usage = true;
                                    }
                                } break;
                                #line 1150 "src/compiler/Usages.pv"
                                default: {
                                } break;
                            }
                        } break;
                        #line 1153 "src/compiler/Usages.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 1156 "src/compiler/Usages.pv"
                default: {
                } break;
            }
        } break;
    }
}

#line 1162 "src/compiler/Usages.pv"
void Usages__normalize(struct Usages* self) {
}
