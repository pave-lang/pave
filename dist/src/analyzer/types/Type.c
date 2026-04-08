#include <stdio.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/c/TypedefC.h>
#include <std/ArenaAllocator.h>
#include <stdint.h>
#include <stdbool.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Context.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/Enum.h>
#include <std/Array_Type.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Generic.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/Token.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/Module.h>

#include <analyzer/types/Type.h>

#line 105 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 106 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 107 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 107 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 108 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 108 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 109 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 109 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 110 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 110 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 111 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 111 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 112 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 112 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 113 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 113 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 114 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 114 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 115 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::Unknown";
        } break;
        #line 116 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 116 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 117 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 117 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 118 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 118 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 119 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 119 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 120 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 120 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 121 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 121 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
    }
}

#line 129 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 130 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 131 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 131 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 131 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 132 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 135 "src/analyzer/types/Type.pv"
    return self;
}

#line 138 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 139 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 140 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 140 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 140 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 141 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 144 "src/analyzer/types/Type.pv"
    return self;
}

#line 147 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 148 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 149 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 149 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 150 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 151 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 151 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 152 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 153 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 153 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 154 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 154 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 155 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 158 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 161 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 164 "src/analyzer/types/Type.pv"
    return self;
}

#line 167 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 168 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 169 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 169 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 171 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 172 "src/analyzer/types/Type.pv"
    return type;
}

#line 175 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 176 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 177 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 177 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 177 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 178 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 178 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 178 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 179 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 179 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 179 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 180 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 180 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 180 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 181 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 181 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 182 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 185 "src/analyzer/types/Type.pv"
    return 0;
}

#line 188 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 189 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 190 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 190 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 191 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 191 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 192 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 192 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 192 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 193 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 193 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 193 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 194 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 194 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 194 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 194 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 195 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 195 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 195 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 195 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 196 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 196 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 196 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 196 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 197 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 197 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 198 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 198 "src/analyzer/types/Type.pv"
            struct str name = other->unknown_value._0;
            #line 198 "src/analyzer/types/Type.pv"
            struct Array_Type* generics = &other->unknown_value._1;
            #line 198 "src/analyzer/types/Type.pv"
            return Type__eq_unknown(self, name, generics);
        } break;
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 199 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 199 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 200 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 200 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 200 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 201 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 201 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 202 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 202 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 203 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 204 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 204 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 205 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 205 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 205 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 206 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 206 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 206 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 207 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 207 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 207 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 208 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 208 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 208 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 212 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 213 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 214 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 214 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 214 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 215 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 215 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 215 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 216 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 216 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 217 "src/analyzer/types/Type.pv"
        default: {
            #line 217 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 220 "src/analyzer/types/Type.pv"
    return false;
}

#line 223 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 224 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 225 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 225 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 226 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 226 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 227 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 228 "src/analyzer/types/Type.pv"
        default: {
            #line 228 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 231 "src/analyzer/types/Type.pv"
    return false;
}

#line 234 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 253 "src/analyzer/types/Type.pv"
    return true;
}

#line 256 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 257 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 258 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 258 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 259 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || other == 0 || str__eq(primitive_info->name, other->name) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || Primitive__is_void(other);
        } break;
        #line 261 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 261 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 262 "src/analyzer/types/Type.pv"
        default: {
            #line 262 "src/analyzer/types/Type.pv"
            return Primitive__is_void(other);
        } break;
    }
}

#line 266 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 267 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 268 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 268 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 269 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 269 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 270 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 270 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 271 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 272 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 272 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 274 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 276 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 276 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 276 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 277 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 277 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 278 "src/analyzer/types/Type.pv"
        default: {
            #line 278 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 281 "src/analyzer/types/Type.pv"
    return false;
}

#line 284 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 285 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 286 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 286 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 286 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 287 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 287 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 288 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 288 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 289 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 290 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 290 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 292 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 294 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 294 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 295 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 296 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 298 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 298 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 298 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 299 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 299 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 300 "src/analyzer/types/Type.pv"
        default: {
            #line 300 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 303 "src/analyzer/types/Type.pv"
    return false;
}

#line 306 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 307 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 308 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 308 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 308 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 309 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 309 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 310 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 310 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 311 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 312 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 312 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 314 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 316 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 316 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 316 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 317 "src/analyzer/types/Type.pv"
        default: {
            #line 317 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 320 "src/analyzer/types/Type.pv"
    return false;
}

#line 323 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 324 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 325 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 325 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 326 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 326 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 326 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 327 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 327 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 328 "src/analyzer/types/Type.pv"
        default: {
            #line 328 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 331 "src/analyzer/types/Type.pv"
    return false;
}

#line 334 "src/analyzer/types/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 335 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 336 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 336 "src/analyzer/types/Type.pv"
            struct str name = self->unknown_value._0;
            #line 336 "src/analyzer/types/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 337 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 337 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 337 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 338 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 338 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 339 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 339 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 340 "src/analyzer/types/Type.pv"
        default: {
            #line 340 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 343 "src/analyzer/types/Type.pv"
    return false;
}

#line 346 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 347 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 348 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 348 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 349 "src/analyzer/types/Type.pv"
        default: {
            #line 349 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 352 "src/analyzer/types/Type.pv"
    return false;
}

#line 355 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 356 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 357 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 357 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 358 "src/analyzer/types/Type.pv"
        default: {
            #line 358 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 361 "src/analyzer/types/Type.pv"
    return false;
}

#line 364 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 365 "src/analyzer/types/Type.pv"
    return true;
}

#line 376 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 377 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 378 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 378 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 378 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 379 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 379 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 379 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 380 "src/analyzer/types/Type.pv"
        default: {
            #line 380 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 383 "src/analyzer/types/Type.pv"
    return false;
}

#line 386 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 387 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 388 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 388 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 388 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 389 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 389 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 389 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 390 "src/analyzer/types/Type.pv"
        default: {
            #line 390 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 393 "src/analyzer/types/Type.pv"
    return false;
}

#line 396 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 397 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 398 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 398 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 398 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 399 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 399 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 399 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 400 "src/analyzer/types/Type.pv"
        default: {
            #line 400 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 403 "src/analyzer/types/Type.pv"
    return false;
}

#line 406 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 407 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 408 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 408 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 408 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 409 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 409 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 409 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 410 "src/analyzer/types/Type.pv"
        default: {
            #line 410 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 413 "src/analyzer/types/Type.pv"
    return false;
}

#line 416 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 417 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 418 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 418 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 418 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 419 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 419 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 419 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 420 "src/analyzer/types/Type.pv"
        default: {
            #line 420 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 423 "src/analyzer/types/Type.pv"
    return false;
}

#line 426 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 427 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 428 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 428 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 429 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 429 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 429 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 430 "src/analyzer/types/Type.pv"
        default: {
            #line 430 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 433 "src/analyzer/types/Type.pv"
    return false;
}

#line 436 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 437 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 438 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 438 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 438 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 439 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 439 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 439 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 440 "src/analyzer/types/Type.pv"
        default: {
            #line 440 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 443 "src/analyzer/types/Type.pv"
    return false;
}

#line 446 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 447 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 448 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 448 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 449 "src/analyzer/types/Type.pv"
        default: {
            #line 449 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 453 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 454 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 454 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 456 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 457 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 457 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 457 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || Primitive__is_void(primitive_info);
        } break;
        #line 458 "src/analyzer/types/Type.pv"
        default: {
            #line 458 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 462 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 463 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 464 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 464 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 465 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 465 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 466 "src/analyzer/types/Type.pv"
        default: {
            #line 466 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 470 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 471 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 472 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 472 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 473 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 473 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 474 "src/analyzer/types/Type.pv"
        default: {
            #line 474 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 478 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 479 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 480 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 480 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 481 "src/analyzer/types/Type.pv"
        default: {
            #line 481 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 485 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 486 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 487 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 487 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 488 "src/analyzer/types/Type.pv"
        default: {
            #line 488 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 492 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 493 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 494 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 494 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 495 "src/analyzer/types/Type.pv"
        default: {
            #line 495 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 499 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 500 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 501 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 501 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 502 "src/analyzer/types/Type.pv"
        default: {
            #line 502 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 506 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 507 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 508 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 508 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 508 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 509 "src/analyzer/types/Type.pv"
        default: {
            #line 509 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 513 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 514 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 515 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 515 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 517 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 518 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 518 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 518 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 519 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 519 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 520 "src/analyzer/types/Type.pv"
        default: {
            #line 520 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 524 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 525 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 526 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 526 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 528 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 529 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 529 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 529 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 530 "src/analyzer/types/Type.pv"
        default: {
            #line 530 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 534 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 535 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 536 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 536 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 537 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 539 "src/analyzer/types/Type.pv"
        default: {
            #line 539 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 543 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 544 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 545 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 547 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 548 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 548 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 549 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 550 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 550 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 552 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 552 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 553 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 554 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 554 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 555 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 556 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 556 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 558 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 559 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 559 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 559 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 560 "src/analyzer/types/Type.pv"
                default: {
                    #line 560 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 563 "src/analyzer/types/Type.pv"
        default: {
            #line 563 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 566 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 567 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 568 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 568 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 569 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 570 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 570 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 571 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 573 "src/analyzer/types/Type.pv"
                    default: {
                        #line 573 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 576 "src/analyzer/types/Type.pv"
            default: {
                #line 576 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 580 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 581 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 581 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 582 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 583 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 583 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 584 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 584 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 584 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 585 "src/analyzer/types/Type.pv"
                default: {
                    #line 585 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 588 "src/analyzer/types/Type.pv"
        default: {
            #line 588 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 591 "src/analyzer/types/Type.pv"
    return false;
}

#line 594 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 595 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 595 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 597 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 598 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 598 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 599 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 599 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 600 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 601 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 601 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 602 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 602 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 603 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 603 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 604 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 604 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 605 "src/analyzer/types/Type.pv"
        default: {
            #line 605 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 609 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 610 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 611 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 612 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 612 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 613 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 614 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 615 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 615 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 615 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 616 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 616 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 616 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 617 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 617 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 617 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 618 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 619 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 619 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 620 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 620 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 620 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 620 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 620 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 621 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 621 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 622 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 622 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 623 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 623 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 624 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 624 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 625 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 625 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 626 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 626 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 627 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 627 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 628 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 629 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
