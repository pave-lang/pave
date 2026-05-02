#include <stdint.h>
#include <string.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/c/TypedefC.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Context.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Function.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Range_usize.h>
#include <analyzer/Token.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/Module.h>
#include <analyzer/types/Type.h>

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
        case TYPE__UNKNOWN_C: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
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
struct Type* Type__deref_all(struct Type* self) {
    #line 139 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 140 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 140 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 140 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 141 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 144 "src/analyzer/types/Type.pv"
    return self;
}

#line 147 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 148 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 149 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 149 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 149 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 150 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 153 "src/analyzer/types/Type.pv"
    return self;
}

#line 156 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 157 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 158 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 158 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 159 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 160 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 160 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 161 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 162 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 162 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 163 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 163 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 164 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 167 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 170 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 173 "src/analyzer/types/Type.pv"
    return self;
}

#line 176 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 177 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 178 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 178 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 180 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 181 "src/analyzer/types/Type.pv"
    return type;
}

#line 184 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 185 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 186 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 186 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 186 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 187 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 187 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 187 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 188 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 188 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 188 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 189 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 189 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 189 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 190 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 194 "src/analyzer/types/Type.pv"
    return 0;
}

#line 197 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 198 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 198 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 200 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 201 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 201 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 201 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 202 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 202 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 203 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 204 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 204 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 205 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 205 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 205 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 205 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 206 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 206 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 206 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 206 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 207 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 207 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 207 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 207 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 208 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 208 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 208 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 209 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 209 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 210 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 210 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 210 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 211 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 211 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 211 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 212 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 212 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 213 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 213 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 213 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 214 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 214 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 214 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 215 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 215 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 215 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 216 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 216 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 216 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 217 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 217 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 217 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 218 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 218 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 218 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 219 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 219 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 219 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 223 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 224 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 225 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 225 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 226 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 226 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
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
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 235 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 236 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 236 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 236 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 237 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 237 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 237 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 238 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 238 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 239 "src/analyzer/types/Type.pv"
        default: {
            #line 239 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 242 "src/analyzer/types/Type.pv"
    return false;
}

#line 245 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 264 "src/analyzer/types/Type.pv"
    return true;
}

#line 267 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 268 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 269 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 269 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 270 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__eq(primitive_info->name, other->name));
        } break;
        #line 272 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 272 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 273 "src/analyzer/types/Type.pv"
        default: {
            #line 273 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 277 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 278 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 279 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 279 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 279 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 280 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 280 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 281 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 281 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 282 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 283 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 283 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 285 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 287 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 287 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 287 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 288 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 288 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 289 "src/analyzer/types/Type.pv"
        default: {
            #line 289 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 292 "src/analyzer/types/Type.pv"
    return false;
}

#line 295 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 296 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 297 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 297 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 297 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 298 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 298 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 299 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 299 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 300 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 301 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 301 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 303 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 305 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 305 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 306 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 307 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 309 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 309 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 310 "src/analyzer/types/Type.pv"
        default: {
            #line 310 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 313 "src/analyzer/types/Type.pv"
    return false;
}

#line 316 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 317 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 318 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 318 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 318 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 319 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 319 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 320 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 320 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 321 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 322 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 322 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 324 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 326 "src/analyzer/types/Type.pv"
        default: {
            #line 326 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 329 "src/analyzer/types/Type.pv"
    return false;
}

#line 332 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 333 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 334 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 334 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 334 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 343 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 344 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 352 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 353 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 353 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 354 "src/analyzer/types/Type.pv"
        default: {
            #line 354 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 357 "src/analyzer/types/Type.pv"
    return false;
}

#line 360 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 361 "src/analyzer/types/Type.pv"
    return true;
}

#line 372 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 373 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 374 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 374 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 374 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 375 "src/analyzer/types/Type.pv"
        default: {
            #line 375 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 378 "src/analyzer/types/Type.pv"
    return false;
}

#line 381 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 382 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 383 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 383 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 383 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
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
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 391 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 392 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 392 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 392 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
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
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 400 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 401 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 401 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 401 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
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
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 409 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 410 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 410 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 410 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
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
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 418 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 419 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 419 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 419 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
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
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 427 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 428 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 428 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
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
bool Type__is_self(struct Type* self) {
    #line 436 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 437 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 437 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 438 "src/analyzer/types/Type.pv"
        default: {
            #line 438 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 442 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 443 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 444 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 444 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 444 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 445 "src/analyzer/types/Type.pv"
        default: {
            #line 445 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 449 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 450 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 451 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 451 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 452 "src/analyzer/types/Type.pv"
        default: {
            #line 452 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 456 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 457 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 458 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 458 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 459 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
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
bool Type__is_function(struct Type* self) {
    #line 465 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 466 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 466 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 467 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 467 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 468 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 468 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 469 "src/analyzer/types/Type.pv"
        default: {
            #line 469 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 473 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 474 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 475 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 475 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 476 "src/analyzer/types/Type.pv"
        default: {
            #line 476 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 480 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 481 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 482 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 482 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 483 "src/analyzer/types/Type.pv"
        default: {
            #line 483 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 487 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 488 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 489 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 489 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 490 "src/analyzer/types/Type.pv"
        default: {
            #line 490 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 494 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 495 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 496 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 496 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 497 "src/analyzer/types/Type.pv"
        default: {
            #line 497 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 501 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 502 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 503 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 503 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 503 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 504 "src/analyzer/types/Type.pv"
        default: {
            #line 504 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 508 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 509 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 510 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 510 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 510 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 511 "src/analyzer/types/Type.pv"
        default: {
            #line 511 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 515 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 516 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 517 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 517 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 519 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 520 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 520 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 520 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 521 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 521 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 522 "src/analyzer/types/Type.pv"
        default: {
            #line 522 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 526 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 527 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 528 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 528 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 530 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 531 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 531 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 531 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 532 "src/analyzer/types/Type.pv"
        default: {
            #line 532 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 536 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 537 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 538 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 538 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 539 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 541 "src/analyzer/types/Type.pv"
        default: {
            #line 541 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 545 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 546 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 547 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 549 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 550 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 550 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 551 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 552 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 552 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 554 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 554 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 555 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 556 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 556 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 557 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 558 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 558 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 560 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 561 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 561 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 561 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 562 "src/analyzer/types/Type.pv"
                default: {
                    #line 562 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 565 "src/analyzer/types/Type.pv"
        default: {
            #line 565 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 568 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 569 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 570 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 570 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 571 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 572 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 572 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 573 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 575 "src/analyzer/types/Type.pv"
                    default: {
                        #line 575 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 578 "src/analyzer/types/Type.pv"
            default: {
                #line 578 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 582 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 583 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 583 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 584 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 585 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 585 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 586 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 586 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 586 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 587 "src/analyzer/types/Type.pv"
                default: {
                    #line 587 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 590 "src/analyzer/types/Type.pv"
        default: {
            #line 590 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 593 "src/analyzer/types/Type.pv"
    return false;
}

#line 596 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 597 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 597 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 599 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 600 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 601 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 601 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 602 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 602 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 603 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 603 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 604 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 604 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 605 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 605 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 606 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 606 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 607 "src/analyzer/types/Type.pv"
        default: {
            #line 607 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 611 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 612 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 613 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 614 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 615 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 615 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 616 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 616 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 617 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 617 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 617 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 618 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 618 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 619 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 619 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 619 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 620 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 620 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 621 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 622 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 622 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 622 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 622 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 622 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 623 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 623 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 623 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 624 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 624 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 625 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 625 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 626 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 626 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 627 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 627 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 628 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 629 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 630 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 630 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 631 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 631 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
