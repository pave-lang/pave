#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/c/TypedefC.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Context.h>
#include <analyzer/types/Global.h>
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
#include <std/str.h>
#include <std/Range_usize.h>
#include <analyzer/Token.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/Module.h>
#include <analyzer/types/Type.h>

#include <analyzer/types/Type.h>

#line 106 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 107 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 108 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 108 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 109 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 109 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 110 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 110 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 111 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 111 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 112 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 112 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 113 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 113 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 114 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 114 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 115 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 116 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 116 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
        } break;
        #line 117 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 117 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 118 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 118 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 119 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 119 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 120 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 120 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 121 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 121 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 126 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 126 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
        #line 127 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 127 "src/analyzer/types/Type.pv"
            return "Type::Global";
        } break;
    }
}

#line 131 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 132 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 133 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 133 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 133 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 134 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 137 "src/analyzer/types/Type.pv"
    return self;
}

#line 140 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self) {
    #line 141 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 142 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 142 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 142 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 143 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 146 "src/analyzer/types/Type.pv"
    return self;
}

#line 149 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 150 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 151 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 151 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 151 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 152 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 155 "src/analyzer/types/Type.pv"
    return self;
}

#line 158 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 159 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 160 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 160 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 161 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 162 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 162 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 163 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 164 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 164 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 165 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 165 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 166 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 169 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 172 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 175 "src/analyzer/types/Type.pv"
    return self;
}

#line 178 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 179 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 180 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 180 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 182 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 183 "src/analyzer/types/Type.pv"
    return type;
}

#line 186 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 187 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 188 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 188 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 188 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 189 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 189 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 189 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 190 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 190 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 191 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 191 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 192 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 192 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 193 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 196 "src/analyzer/types/Type.pv"
    return 0;
}

#line 199 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 200 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 200 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 202 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 203 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 207 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 208 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 208 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 208 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 209 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 209 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 209 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 210 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 210 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 210 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 211 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 211 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 211 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 212 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 212 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 212 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 212 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 213 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 213 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 213 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 213 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 214 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 214 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 214 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 214 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 215 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 215 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 215 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 216 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 216 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 217 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 217 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 217 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 218 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 218 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 218 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 219 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 219 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 220 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 220 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 220 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 221 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 221 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 221 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 222 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 222 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 222 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 223 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 223 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 223 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 224 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 224 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 224 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 225 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 225 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 226 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 226 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 227 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 227 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 231 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 232 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 233 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 233 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 233 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 234 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 234 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 234 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 235 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 235 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 236 "src/analyzer/types/Type.pv"
        default: {
            #line 236 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 239 "src/analyzer/types/Type.pv"
    return false;
}

#line 242 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 243 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 244 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 244 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 244 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 245 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 245 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 245 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 246 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 246 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 247 "src/analyzer/types/Type.pv"
        default: {
            #line 247 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 250 "src/analyzer/types/Type.pv"
    return false;
}

#line 253 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 272 "src/analyzer/types/Type.pv"
    return true;
}

#line 275 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 276 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 277 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 277 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 278 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__eq(primitive_info->name, other->name));
        } break;
        #line 280 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 280 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 281 "src/analyzer/types/Type.pv"
        default: {
            #line 281 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 285 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 286 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 287 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 287 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 287 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 288 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 288 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 289 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 289 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 290 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 291 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 291 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 293 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 295 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 295 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 295 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 296 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 296 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 297 "src/analyzer/types/Type.pv"
        default: {
            #line 297 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 300 "src/analyzer/types/Type.pv"
    return false;
}

#line 303 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 304 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 305 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 305 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 305 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 306 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 306 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 307 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 307 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 308 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 309 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 309 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 311 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 313 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 313 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 314 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 315 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 317 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 317 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 318 "src/analyzer/types/Type.pv"
        default: {
            #line 318 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 321 "src/analyzer/types/Type.pv"
    return false;
}

#line 324 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 325 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 326 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 326 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 326 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 327 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 327 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 328 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 328 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 329 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 330 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 330 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 332 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 334 "src/analyzer/types/Type.pv"
        default: {
            #line 334 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 337 "src/analyzer/types/Type.pv"
    return false;
}

#line 340 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 341 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 342 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 342 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 342 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 343 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 343 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 344 "src/analyzer/types/Type.pv"
        default: {
            #line 344 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 347 "src/analyzer/types/Type.pv"
    return false;
}

#line 350 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 351 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 352 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 352 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 353 "src/analyzer/types/Type.pv"
        default: {
            #line 353 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 356 "src/analyzer/types/Type.pv"
    return false;
}

#line 359 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 360 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 361 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 361 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 362 "src/analyzer/types/Type.pv"
        default: {
            #line 362 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 365 "src/analyzer/types/Type.pv"
    return false;
}

#line 368 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 369 "src/analyzer/types/Type.pv"
    return true;
}

#line 380 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 381 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 382 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 382 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 382 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 383 "src/analyzer/types/Type.pv"
        default: {
            #line 383 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 386 "src/analyzer/types/Type.pv"
    return false;
}

#line 389 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 390 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 391 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 391 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 391 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 392 "src/analyzer/types/Type.pv"
        default: {
            #line 392 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 395 "src/analyzer/types/Type.pv"
    return false;
}

#line 398 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 399 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 400 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 400 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 400 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 401 "src/analyzer/types/Type.pv"
        default: {
            #line 401 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 404 "src/analyzer/types/Type.pv"
    return false;
}

#line 407 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 408 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 409 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 409 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 409 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
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
        default: {
            #line 428 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 431 "src/analyzer/types/Type.pv"
    return false;
}

#line 434 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 435 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 436 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 436 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 436 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 437 "src/analyzer/types/Type.pv"
        default: {
            #line 437 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 440 "src/analyzer/types/Type.pv"
    return false;
}

#line 443 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 444 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 445 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 445 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 446 "src/analyzer/types/Type.pv"
        default: {
            #line 446 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 450 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 451 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 452 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 452 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 452 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 453 "src/analyzer/types/Type.pv"
        default: {
            #line 453 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 457 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 458 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 459 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
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
bool Type__is_enum(struct Type* self) {
    #line 465 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 466 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 466 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 467 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 467 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 468 "src/analyzer/types/Type.pv"
        default: {
            #line 468 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 472 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 473 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 474 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 474 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 475 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 475 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 476 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 476 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 477 "src/analyzer/types/Type.pv"
        default: {
            #line 477 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 481 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 482 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 483 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 483 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 484 "src/analyzer/types/Type.pv"
        default: {
            #line 484 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 488 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 489 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 490 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 490 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 491 "src/analyzer/types/Type.pv"
        default: {
            #line 491 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 495 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 496 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 497 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 497 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 498 "src/analyzer/types/Type.pv"
        default: {
            #line 498 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 502 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 503 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 504 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 504 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 505 "src/analyzer/types/Type.pv"
        default: {
            #line 505 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 509 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 510 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 511 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 511 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 511 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 512 "src/analyzer/types/Type.pv"
        default: {
            #line 512 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 516 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 517 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 518 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 518 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 518 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 519 "src/analyzer/types/Type.pv"
        default: {
            #line 519 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 523 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 524 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 525 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 525 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 527 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 528 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 528 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 528 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 529 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 529 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 530 "src/analyzer/types/Type.pv"
        default: {
            #line 530 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 534 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 535 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 536 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 536 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 538 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 539 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 539 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 539 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 540 "src/analyzer/types/Type.pv"
        default: {
            #line 540 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 544 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 545 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 546 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 546 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 547 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 549 "src/analyzer/types/Type.pv"
        default: {
            #line 549 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 553 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 554 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 555 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 557 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 558 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 558 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 559 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 560 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 560 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 562 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 562 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 563 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 564 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 564 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 565 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 566 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 566 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 568 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 569 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 569 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 569 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 570 "src/analyzer/types/Type.pv"
                default: {
                    #line 570 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        default: {
            #line 573 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 576 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 577 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 578 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 578 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 579 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 580 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 580 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 581 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 583 "src/analyzer/types/Type.pv"
                    default: {
                        #line 583 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 586 "src/analyzer/types/Type.pv"
            default: {
                #line 586 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 590 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 591 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 591 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 592 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 593 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 593 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 594 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 594 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 594 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 595 "src/analyzer/types/Type.pv"
                default: {
                    #line 595 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 598 "src/analyzer/types/Type.pv"
        default: {
            #line 598 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 601 "src/analyzer/types/Type.pv"
    return false;
}

#line 604 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 605 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 605 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 607 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 608 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 608 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 609 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 609 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 610 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 610 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 611 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 612 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 612 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 613 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 614 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 615 "src/analyzer/types/Type.pv"
        default: {
            #line 615 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 619 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 620 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 621 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 622 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 622 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 623 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 623 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 624 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 624 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 625 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 625 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 625 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 626 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 626 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 626 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 627 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 627 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 627 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 628 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 629 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 630 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 630 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 630 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 630 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 630 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 631 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 631 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 631 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 632 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 632 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 633 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 633 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 634 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 634 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 635 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 635 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 636 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 636 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 637 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 637 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 638 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 638 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 639 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 639 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 640 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 640 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 640 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
    }
}
