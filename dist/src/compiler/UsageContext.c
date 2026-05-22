#include <stdint.h>

#include <stdio.h>

#include <compiler/UsageContext.h>
#include <analyzer/types/GenericMap.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_str_Function.h>
#include <analyzer/Impl.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <compiler/TypeFunctionUsage.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Trait.h>
#include <std/str.h>
#include <std/Iter_ref_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMapIter_usize_TypeFunctionUsage.h>
#include <tuple_usize_TypeFunctionUsage.h>
#include <std/HashSet_usize.h>
#include <compiler/UsageContext.h>

#include <compiler/UsageContext.h>

#line 55 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator, struct GenericMap* generic_map) {
    #line 56 "src/compiler/Usages.pv"
    return (struct UsageContext) {
        .generic_map = generic_map,
        .function_context = FunctionContext__new_const(allocator),
        .impl_dynamic_function = false,
        .primitive_header = HashSet_str__new(allocator),
        .primitive_code = HashSet_str__new(allocator),
        .layout = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .signature = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .body = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .cpp_usages = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 },
    };
}

#line 70 "src/compiler/Usages.pv"
void UsageContext__populate_impls(struct UsageContext* self, struct ArenaAllocator* allocator, struct Array_ref_Impl* impls) {
    #line 71 "src/compiler/Usages.pv"
    uintptr_t impl_count = impls->length;
    #line 72 "src/compiler/Usages.pv"
    self->impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 73 "src/compiler/Usages.pv"
    Array_HashMap_usize_TypeFunctionUsage__reserve(&self->impl_functions, impl_count);
    #line 74 "src/compiler/Usages.pv"
    self->impl_functions.length = impl_count;

    #line 76 "src/compiler/Usages.pv"
    uintptr_t i = 0;
    #line 77 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 77 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 77 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 78 "src/compiler/Usages.pv"
        self->impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 79 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 79 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 79 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 80 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
        } }
        #line 82 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 83 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 84 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 84 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 84 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 84 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 85 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 85 "src/compiler/Usages.pv"
                    continue;
                }
                #line 86 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
            } }
        }
        #line 89 "src/compiler/Usages.pv"
        i += 1;
    } }
}

#line 93 "src/compiler/Usages.pv"
void UsageContext__populate_trait_functions(struct UsageContext* self, struct ArenaAllocator* allocator, struct Trait* trait_info) {
    #line 94 "src/compiler/Usages.pv"
    self->impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 95 "src/compiler/Usages.pv"
    Array_HashMap_usize_TypeFunctionUsage__reserve(&self->impl_functions, 1);
    #line 96 "src/compiler/Usages.pv"
    self->impl_functions.length = 1;
    #line 97 "src/compiler/Usages.pv"
    self->impl_functions.data[0] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 99 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 99 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 99 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 100 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
    } }
}

#line 104 "src/compiler/Usages.pv"
void UsageContext__apply_pending_dynamic_functions(struct UsageContext* self, struct HashSet_usize* dynamic_impl_functions) {
    #line 105 "src/compiler/Usages.pv"
    { struct Iter_ref_HashMap_usize_TypeFunctionUsage __iter = Array_HashMap_usize_TypeFunctionUsage__iter(&self->impl_functions);
    #line 105 "src/compiler/Usages.pv"
    while (Iter_ref_HashMap_usize_TypeFunctionUsage__next(&__iter)) {
        #line 105 "src/compiler/Usages.pv"
        struct HashMap_usize_TypeFunctionUsage impl_functions_for_impl = *Iter_ref_HashMap_usize_TypeFunctionUsage__value(&__iter);

        #line 106 "src/compiler/Usages.pv"
        { struct HashMapIter_usize_TypeFunctionUsage __iter = HashMap_usize_TypeFunctionUsage__iter(&impl_functions_for_impl);
        #line 106 "src/compiler/Usages.pv"
        while (HashMapIter_usize_TypeFunctionUsage__next(&__iter)) {
            #line 106 "src/compiler/Usages.pv"
            uintptr_t func_ptr = HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_0;
            #line 106 "src/compiler/Usages.pv"
            struct TypeFunctionUsage* function_usage = &HashMapIter_usize_TypeFunctionUsage__value(&__iter)->_1;

            #line 107 "src/compiler/Usages.pv"
            if (HashSet_usize__has(dynamic_impl_functions, &func_ptr)) {
                #line 108 "src/compiler/Usages.pv"
                function_usage->impl_dynamic_function = true;
            }
        } }
    } }
}
