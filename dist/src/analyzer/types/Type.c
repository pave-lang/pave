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
#include <analyzer/types/Function.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/str.h>
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
    if (Type__is_unknown(self)) {
        #line 189 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 191 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 192 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 192 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 192 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 193 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 193 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 193 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 194 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 194 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 194 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 195 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 195 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 195 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 196 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 196 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 196 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 196 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 197 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 197 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 197 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 198 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 198 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 198 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 198 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 199 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 199 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 200 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 200 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 201 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 201 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 201 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 202 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 202 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 204 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 204 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 205 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 205 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 205 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 206 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 206 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 206 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 207 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 207 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 207 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 208 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 208 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 208 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 209 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 209 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 209 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 210 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 210 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 210 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 214 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 215 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 216 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 216 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 216 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 217 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 217 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 217 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 218 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 218 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 219 "src/analyzer/types/Type.pv"
        default: {
            #line 219 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 222 "src/analyzer/types/Type.pv"
    return false;
}

#line 225 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 226 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 227 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 227 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 228 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 228 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 228 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 229 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 229 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 230 "src/analyzer/types/Type.pv"
        default: {
            #line 230 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 233 "src/analyzer/types/Type.pv"
    return false;
}

#line 236 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 255 "src/analyzer/types/Type.pv"
    return true;
}

#line 258 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 259 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 260 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 260 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 261 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__eq(primitive_info->name, other->name));
        } break;
        #line 263 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 263 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 264 "src/analyzer/types/Type.pv"
        default: {
            #line 264 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 268 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 269 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 270 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 270 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 270 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 271 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 271 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 272 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 272 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 273 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 274 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 274 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 276 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 278 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 278 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 278 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 279 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 279 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 280 "src/analyzer/types/Type.pv"
        default: {
            #line 280 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 283 "src/analyzer/types/Type.pv"
    return false;
}

#line 286 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 287 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 288 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 288 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 288 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 289 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 289 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 290 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 290 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 291 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 292 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 292 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 294 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 296 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 296 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 297 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 298 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 300 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 300 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 301 "src/analyzer/types/Type.pv"
        default: {
            #line 301 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 304 "src/analyzer/types/Type.pv"
    return false;
}

#line 307 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 308 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 309 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 309 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 309 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 310 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 310 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 311 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 311 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 312 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 313 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 313 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 315 "src/analyzer/types/Type.pv"
            return true;
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
        case TYPE__SELF: {
            #line 326 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 327 "src/analyzer/types/Type.pv"
        default: {
            #line 327 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 330 "src/analyzer/types/Type.pv"
    return false;
}

#line 333 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 334 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 335 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 336 "src/analyzer/types/Type.pv"
        default: {
            #line 336 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 339 "src/analyzer/types/Type.pv"
    return false;
}

#line 342 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 343 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 344 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 344 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 345 "src/analyzer/types/Type.pv"
        default: {
            #line 345 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 348 "src/analyzer/types/Type.pv"
    return false;
}

#line 351 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 352 "src/analyzer/types/Type.pv"
    return true;
}

#line 363 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 364 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 365 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 365 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 365 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 366 "src/analyzer/types/Type.pv"
        default: {
            #line 366 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 369 "src/analyzer/types/Type.pv"
    return false;
}

#line 372 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 373 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 374 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 374 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 374 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 375 "src/analyzer/types/Type.pv"
        default: {
            #line 375 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 378 "src/analyzer/types/Type.pv"
    return false;
}

#line 381 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 382 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 383 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 383 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 383 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 384 "src/analyzer/types/Type.pv"
        default: {
            #line 384 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 387 "src/analyzer/types/Type.pv"
    return false;
}

#line 390 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 391 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 392 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 392 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 392 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 393 "src/analyzer/types/Type.pv"
        default: {
            #line 393 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 396 "src/analyzer/types/Type.pv"
    return false;
}

#line 399 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 400 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 401 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 401 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 401 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 402 "src/analyzer/types/Type.pv"
        default: {
            #line 402 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 405 "src/analyzer/types/Type.pv"
    return false;
}

#line 408 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 409 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 410 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 410 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 410 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 411 "src/analyzer/types/Type.pv"
        default: {
            #line 411 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 414 "src/analyzer/types/Type.pv"
    return false;
}

#line 417 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 418 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 419 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 419 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 419 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
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
bool Type__is_self(struct Type* self) {
    #line 427 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 428 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 429 "src/analyzer/types/Type.pv"
        default: {
            #line 429 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 433 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 434 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 435 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 435 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 435 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 436 "src/analyzer/types/Type.pv"
        default: {
            #line 436 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 440 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 441 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 442 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 442 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 443 "src/analyzer/types/Type.pv"
        default: {
            #line 443 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 447 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 448 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 449 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 449 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 450 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 450 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 451 "src/analyzer/types/Type.pv"
        default: {
            #line 451 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 455 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 456 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 457 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 457 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 458 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 458 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 459 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 459 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 460 "src/analyzer/types/Type.pv"
        default: {
            #line 460 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 464 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 465 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 466 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 466 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 467 "src/analyzer/types/Type.pv"
        default: {
            #line 467 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 471 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 472 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 473 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_tuple(struct Type* self) {
    #line 479 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 480 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
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
bool Type__is_sequence(struct Type* self) {
    #line 486 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 487 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
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
struct Type* Type__deref_1(struct Type* self) {
    #line 493 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 494 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 494 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 494 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 495 "src/analyzer/types/Type.pv"
        default: {
            #line 495 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 499 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 500 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 501 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 501 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 503 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 504 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 504 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 504 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 505 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 505 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 506 "src/analyzer/types/Type.pv"
        default: {
            #line 506 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 510 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 511 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 512 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 512 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 514 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 515 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 515 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 515 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 516 "src/analyzer/types/Type.pv"
        default: {
            #line 516 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 520 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 521 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 522 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 522 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 523 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 525 "src/analyzer/types/Type.pv"
        default: {
            #line 525 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 529 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 530 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 531 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 533 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 534 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 534 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 535 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 536 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 536 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 538 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 538 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 539 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 540 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 540 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 541 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 542 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 542 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 544 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 545 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 545 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 545 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 546 "src/analyzer/types/Type.pv"
                default: {
                    #line 546 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 549 "src/analyzer/types/Type.pv"
        default: {
            #line 549 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 552 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 553 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 554 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 554 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 555 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 556 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 556 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 557 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 559 "src/analyzer/types/Type.pv"
                    default: {
                        #line 559 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 562 "src/analyzer/types/Type.pv"
            default: {
                #line 562 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 566 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 567 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 567 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 568 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 569 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 569 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 570 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 570 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 570 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 571 "src/analyzer/types/Type.pv"
                default: {
                    #line 571 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 574 "src/analyzer/types/Type.pv"
        default: {
            #line 574 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 577 "src/analyzer/types/Type.pv"
    return false;
}

#line 580 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 581 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 581 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 583 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 584 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 584 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 585 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 585 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 586 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 586 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 587 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 587 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 588 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 588 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 589 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 589 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 590 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 590 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 591 "src/analyzer/types/Type.pv"
        default: {
            #line 591 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 595 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 596 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 597 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 597 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 598 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 598 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 599 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 599 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 600 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 601 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 601 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 601 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 602 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 602 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 602 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 603 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 603 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 603 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 604 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 604 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 605 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 605 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 606 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 606 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 606 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 606 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 606 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 607 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 607 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 607 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 608 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 608 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 609 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 609 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 610 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 610 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 611 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 612 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 612 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 613 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 614 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 615 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 615 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
