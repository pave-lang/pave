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
#include <analyzer/types/Struct.h>
#include <std/Array_Type.h>
#include <analyzer/types/Enum.h>
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
        case TYPE__INDIRECT: {
            #line 179 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 179 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 180 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 180 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 181 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 184 "src/analyzer/types/Type.pv"
    return 0;
}

#line 187 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 188 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 189 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 189 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 189 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 190 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 190 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 191 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 191 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 192 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 192 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 192 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 193 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 193 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 193 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 193 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
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
        case TYPE__TRAIT: {
            #line 195 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 195 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 195 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 196 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 196 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 196 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 197 "src/analyzer/types/Type.pv"
            struct str name = other->unknown_value._0;
            #line 197 "src/analyzer/types/Type.pv"
            struct Array_Type* generics = &other->unknown_value._1;
            #line 197 "src/analyzer/types/Type.pv"
            return Type__eq_unknown(self, name, generics);
        } break;
        #line 198 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 198 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 198 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 199 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 199 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 200 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 200 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 201 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 201 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 201 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 202 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 202 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 203 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 204 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 204 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 205 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 205 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 205 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 206 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 206 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 206 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 207 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 207 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 207 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 211 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 212 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 213 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 213 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 213 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 214 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 214 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 214 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 215 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 215 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 216 "src/analyzer/types/Type.pv"
        default: {
            #line 216 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 219 "src/analyzer/types/Type.pv"
    return false;
}

#line 222 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 223 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 224 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 224 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 224 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 225 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 225 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 226 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 227 "src/analyzer/types/Type.pv"
        default: {
            #line 227 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 230 "src/analyzer/types/Type.pv"
    return false;
}

#line 233 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 252 "src/analyzer/types/Type.pv"
    return true;
}

#line 255 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 256 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 257 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 257 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 258 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || other == 0 || str__eq(primitive_info->name, other->name) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || Primitive__is_void(other);
        } break;
        #line 260 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 260 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 261 "src/analyzer/types/Type.pv"
        default: {
            #line 261 "src/analyzer/types/Type.pv"
            return Primitive__is_void(other);
        } break;
    }
}

#line 265 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 266 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 267 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 267 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 267 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 268 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 268 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 269 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 269 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 270 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 271 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 271 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 273 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 275 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 275 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 275 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 276 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 276 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 277 "src/analyzer/types/Type.pv"
        default: {
            #line 277 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 280 "src/analyzer/types/Type.pv"
    return false;
}

#line 283 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 284 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 285 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 285 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 285 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 286 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 286 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 287 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 287 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 288 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 289 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 289 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 291 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 293 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 293 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 294 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 295 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 297 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 297 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 297 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 298 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 298 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 299 "src/analyzer/types/Type.pv"
        default: {
            #line 299 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 302 "src/analyzer/types/Type.pv"
    return false;
}

#line 305 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 306 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 307 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 307 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 307 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 308 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 308 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 309 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 309 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 310 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 311 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 311 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 313 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 315 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 315 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 316 "src/analyzer/types/Type.pv"
        default: {
            #line 316 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 319 "src/analyzer/types/Type.pv"
    return false;
}

#line 322 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 323 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 324 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 324 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 324 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 325 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 325 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
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
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 334 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 335 "src/analyzer/types/Type.pv"
            struct str name = self->unknown_value._0;
            #line 335 "src/analyzer/types/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 336 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 336 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 336 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 337 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 337 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 338 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 338 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 339 "src/analyzer/types/Type.pv"
        default: {
            #line 339 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 342 "src/analyzer/types/Type.pv"
    return false;
}

#line 345 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 346 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 347 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 347 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 348 "src/analyzer/types/Type.pv"
        default: {
            #line 348 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 351 "src/analyzer/types/Type.pv"
    return false;
}

#line 354 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 355 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 356 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 356 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 357 "src/analyzer/types/Type.pv"
        default: {
            #line 357 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 360 "src/analyzer/types/Type.pv"
    return false;
}

#line 363 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 364 "src/analyzer/types/Type.pv"
    return true;
}

#line 375 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 376 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 377 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 377 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 377 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 378 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 378 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 378 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 379 "src/analyzer/types/Type.pv"
        default: {
            #line 379 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 382 "src/analyzer/types/Type.pv"
    return false;
}

#line 385 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 386 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 387 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 387 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 387 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 388 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 388 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 388 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 389 "src/analyzer/types/Type.pv"
        default: {
            #line 389 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 392 "src/analyzer/types/Type.pv"
    return false;
}

#line 395 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 396 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 397 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 397 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 397 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 398 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 398 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 398 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 399 "src/analyzer/types/Type.pv"
        default: {
            #line 399 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 402 "src/analyzer/types/Type.pv"
    return false;
}

#line 405 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 406 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 407 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 407 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 407 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 408 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 408 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 408 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 409 "src/analyzer/types/Type.pv"
        default: {
            #line 409 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 412 "src/analyzer/types/Type.pv"
    return false;
}

#line 415 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 416 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 417 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 417 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 417 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 418 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 418 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 418 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 419 "src/analyzer/types/Type.pv"
        default: {
            #line 419 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 422 "src/analyzer/types/Type.pv"
    return false;
}

#line 425 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 426 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 427 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 427 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 427 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 428 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 428 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 429 "src/analyzer/types/Type.pv"
        default: {
            #line 429 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 432 "src/analyzer/types/Type.pv"
    return false;
}

#line 435 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 436 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 437 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 437 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 437 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 438 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 438 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 438 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 439 "src/analyzer/types/Type.pv"
        default: {
            #line 439 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 442 "src/analyzer/types/Type.pv"
    return false;
}

#line 445 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 446 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 446 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 448 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 449 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 449 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 449 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || Primitive__is_void(primitive_info);
        } break;
        #line 450 "src/analyzer/types/Type.pv"
        default: {
            #line 450 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 454 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 455 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 456 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 456 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 457 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 457 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 458 "src/analyzer/types/Type.pv"
        default: {
            #line 458 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 462 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 463 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 464 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 464 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 465 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
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
bool Type__is_indirect(struct Type* self) {
    #line 471 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 472 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 472 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 473 "src/analyzer/types/Type.pv"
        default: {
            #line 473 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 477 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 478 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 479 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 479 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 480 "src/analyzer/types/Type.pv"
        default: {
            #line 480 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 484 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 485 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 486 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 486 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 487 "src/analyzer/types/Type.pv"
        default: {
            #line 487 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 491 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 492 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 493 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 493 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 494 "src/analyzer/types/Type.pv"
        default: {
            #line 494 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 498 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 499 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 500 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 500 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 500 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 501 "src/analyzer/types/Type.pv"
        default: {
            #line 501 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 505 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 506 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 507 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 507 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 509 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 510 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 510 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 510 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 511 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 511 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 512 "src/analyzer/types/Type.pv"
        default: {
            #line 512 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 516 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 517 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 518 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 518 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 520 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 521 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 521 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 521 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 522 "src/analyzer/types/Type.pv"
        default: {
            #line 522 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 526 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 527 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 528 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 528 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 529 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 531 "src/analyzer/types/Type.pv"
        default: {
            #line 531 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 535 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 536 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 537 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 539 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 540 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 540 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 541 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 542 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 542 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 544 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 544 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 545 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 546 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 546 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 547 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 548 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 548 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 550 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 551 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 551 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 551 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 552 "src/analyzer/types/Type.pv"
                default: {
                    #line 552 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 555 "src/analyzer/types/Type.pv"
        default: {
            #line 555 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 558 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 559 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 560 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 560 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 561 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 562 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 562 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 563 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 565 "src/analyzer/types/Type.pv"
                    default: {
                        #line 565 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 568 "src/analyzer/types/Type.pv"
            default: {
                #line 568 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 572 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 573 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 573 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 574 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 575 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 575 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 576 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 576 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 576 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 577 "src/analyzer/types/Type.pv"
                default: {
                    #line 577 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 580 "src/analyzer/types/Type.pv"
        default: {
            #line 580 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 583 "src/analyzer/types/Type.pv"
    return false;
}

#line 586 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 587 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 587 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 589 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 590 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 590 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 591 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 591 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 592 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 592 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 593 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 593 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 594 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 594 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 595 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 595 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 596 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 596 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 597 "src/analyzer/types/Type.pv"
        default: {
            #line 597 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 601 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 602 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 603 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 603 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 604 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 604 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 605 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 605 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 606 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 606 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 607 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 607 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 607 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 608 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 608 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 608 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 609 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 609 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 609 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 610 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 610 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 611 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 612 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 612 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 612 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 612 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 612 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 613 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 613 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 614 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 615 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 615 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 616 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 616 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 617 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 617 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 618 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 619 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 619 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 620 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 620 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 621 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
