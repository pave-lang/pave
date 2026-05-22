#include <stdint.h>
#include <stdbool.h>

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
#include <compiler/UsageContext.h>

#include <compiler/UsageContext.h>

#line 53 "src/compiler/Usages.pv"
struct UsageContext UsageContext__new(struct ArenaAllocator* allocator, struct GenericMap* generic_map) {
    #line 54 "src/compiler/Usages.pv"
    return (struct UsageContext) {
        .generic_map = generic_map,
        .function_context = FunctionContext__new_const(allocator),
        .primitive_header = HashSet_str__new(allocator),
        .primitive_code = HashSet_str__new(allocator),
        .layout = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .signature = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .body = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .cpp_usages = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }),
        .impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }, .data = 0, .length = 0, .capacity = 0 },
    };
}

#line 67 "src/compiler/Usages.pv"
void UsageContext__populate_impls(struct UsageContext* self, struct ArenaAllocator* allocator, struct Array_ref_Impl* impls) {
    #line 68 "src/compiler/Usages.pv"
    uintptr_t impl_count = impls->length;
    #line 69 "src/compiler/Usages.pv"
    self->impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 70 "src/compiler/Usages.pv"
    Array_HashMap_usize_TypeFunctionUsage__reserve(&self->impl_functions, impl_count);
    #line 71 "src/compiler/Usages.pv"
    self->impl_functions.length = impl_count;

    #line 73 "src/compiler/Usages.pv"
    uintptr_t i = 0;
    #line 74 "src/compiler/Usages.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(impls);
    #line 74 "src/compiler/Usages.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 74 "src/compiler/Usages.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 75 "src/compiler/Usages.pv"
        self->impl_functions.data[i] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
        #line 76 "src/compiler/Usages.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 76 "src/compiler/Usages.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 76 "src/compiler/Usages.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 77 "src/compiler/Usages.pv"
            HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
        } }
        #line 79 "src/compiler/Usages.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 80 "src/compiler/Usages.pv"
        if (trait_info != 0) {
            #line 81 "src/compiler/Usages.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 81 "src/compiler/Usages.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 81 "src/compiler/Usages.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 81 "src/compiler/Usages.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 82 "src/compiler/Usages.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 82 "src/compiler/Usages.pv"
                    continue;
                }
                #line 83 "src/compiler/Usages.pv"
                HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[i], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
            } }
        }
        #line 86 "src/compiler/Usages.pv"
        i += 1;
    } }
}

#line 90 "src/compiler/Usages.pv"
void UsageContext__populate_trait_functions(struct UsageContext* self, struct ArenaAllocator* allocator, struct Trait* trait_info) {
    #line 91 "src/compiler/Usages.pv"
    self->impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 92 "src/compiler/Usages.pv"
    Array_HashMap_usize_TypeFunctionUsage__reserve(&self->impl_functions, 1);
    #line 93 "src/compiler/Usages.pv"
    self->impl_functions.length = 1;
    #line 94 "src/compiler/Usages.pv"
    self->impl_functions.data[0] = HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 96 "src/compiler/Usages.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 96 "src/compiler/Usages.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 96 "src/compiler/Usages.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 97 "src/compiler/Usages.pv"
        HashMap_usize_TypeFunctionUsage__insert(&self->impl_functions.data[0], (uintptr_t)(func_info), TypeFunctionUsage__new(allocator, func_info));
    } }
}
