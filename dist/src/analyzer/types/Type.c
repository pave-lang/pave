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
        case TYPE__ENUM: {
            #line 193 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 193 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 193 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 194 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 194 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 194 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 194 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
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
            return enum_info == other_enum;
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 268 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 268 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 269 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 269 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 270 "src/analyzer/types/Type.pv"
        default: {
            #line 270 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 273 "src/analyzer/types/Type.pv"
    return false;
}

#line 276 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 277 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 278 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 278 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 278 "src/analyzer/types/Type.pv"
            return struct_info == other_struct;
        } break;
        #line 279 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 279 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 280 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 281 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 283 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 283 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 283 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 284 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 284 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 285 "src/analyzer/types/Type.pv"
        default: {
            #line 285 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 288 "src/analyzer/types/Type.pv"
    return false;
}

#line 291 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 292 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 293 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 293 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 293 "src/analyzer/types/Type.pv"
            return trait_info == other_trait;
        } break;
        #line 294 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 294 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 294 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 295 "src/analyzer/types/Type.pv"
        default: {
            #line 295 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 298 "src/analyzer/types/Type.pv"
    return false;
}

#line 301 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 302 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 303 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 303 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 303 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 304 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 304 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 304 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 305 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 305 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 306 "src/analyzer/types/Type.pv"
        default: {
            #line 306 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 309 "src/analyzer/types/Type.pv"
    return false;
}

#line 312 "src/analyzer/types/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 313 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 314 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 314 "src/analyzer/types/Type.pv"
            struct str name = self->unknown_value._0;
            #line 314 "src/analyzer/types/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 315 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 315 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 316 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 316 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 317 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 325 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 326 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 334 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
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
bool Type__eq_self(struct Type* self) {
    #line 343 "src/analyzer/types/Type.pv"
    return true;
}

#line 354 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 355 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 356 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 356 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 356 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 357 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 357 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 357 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 358 "src/analyzer/types/Type.pv"
        default: {
            #line 358 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 361 "src/analyzer/types/Type.pv"
    return false;
}

#line 364 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 365 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 366 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 366 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 366 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 367 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 367 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 367 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 368 "src/analyzer/types/Type.pv"
        default: {
            #line 368 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 371 "src/analyzer/types/Type.pv"
    return false;
}

#line 374 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 375 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 376 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 376 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 376 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 377 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 377 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 377 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 378 "src/analyzer/types/Type.pv"
        default: {
            #line 378 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 381 "src/analyzer/types/Type.pv"
    return false;
}

#line 384 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 385 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 386 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 386 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 386 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 387 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 387 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 387 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 388 "src/analyzer/types/Type.pv"
        default: {
            #line 388 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 391 "src/analyzer/types/Type.pv"
    return false;
}

#line 394 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 395 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 396 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 396 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 396 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 397 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 397 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 397 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 398 "src/analyzer/types/Type.pv"
        default: {
            #line 398 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 401 "src/analyzer/types/Type.pv"
    return false;
}

#line 404 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 405 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 406 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 406 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 406 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 407 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 407 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 407 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 408 "src/analyzer/types/Type.pv"
        default: {
            #line 408 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 411 "src/analyzer/types/Type.pv"
    return false;
}

#line 414 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 415 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 416 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 416 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 416 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 417 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 417 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 417 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 418 "src/analyzer/types/Type.pv"
        default: {
            #line 418 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 421 "src/analyzer/types/Type.pv"
    return false;
}

#line 424 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 425 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 425 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 427 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 428 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 428 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || Primitive__is_void(primitive_info);
        } break;
        #line 429 "src/analyzer/types/Type.pv"
        default: {
            #line 429 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 433 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 434 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 435 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 435 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 436 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 436 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 437 "src/analyzer/types/Type.pv"
        default: {
            #line 437 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 441 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 442 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 443 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 443 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 444 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 444 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 445 "src/analyzer/types/Type.pv"
        default: {
            #line 445 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 449 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 450 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 451 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
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
bool Type__is_trait(struct Type* self) {
    #line 457 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 458 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 458 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 459 "src/analyzer/types/Type.pv"
        default: {
            #line 459 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 463 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 464 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 465 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
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
bool Type__is_sequence(struct Type* self) {
    #line 471 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 472 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
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
struct Type* Type__deref_1(struct Type* self) {
    #line 478 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 479 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 479 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 479 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 480 "src/analyzer/types/Type.pv"
        default: {
            #line 480 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 484 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 485 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 486 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 486 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 488 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 489 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 489 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 489 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
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
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 496 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 497 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 497 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 499 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 500 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 500 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 500 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 501 "src/analyzer/types/Type.pv"
        default: {
            #line 501 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 505 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 506 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 507 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 507 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 508 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 510 "src/analyzer/types/Type.pv"
        default: {
            #line 510 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 514 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 515 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 516 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 518 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 519 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 519 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 520 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 521 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 521 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 523 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 523 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 524 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 525 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 525 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 526 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 527 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 527 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 529 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 530 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 530 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 530 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 531 "src/analyzer/types/Type.pv"
                default: {
                    #line 531 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 534 "src/analyzer/types/Type.pv"
        default: {
            #line 534 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 537 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 538 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 539 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 539 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 540 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 541 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 541 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 542 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 544 "src/analyzer/types/Type.pv"
                    default: {
                        #line 544 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 547 "src/analyzer/types/Type.pv"
            default: {
                #line 547 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 551 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 552 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 552 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 553 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 554 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 554 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 555 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 555 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 555 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 556 "src/analyzer/types/Type.pv"
                default: {
                    #line 556 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 559 "src/analyzer/types/Type.pv"
        default: {
            #line 559 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 562 "src/analyzer/types/Type.pv"
    return false;
}

#line 565 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 566 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 566 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 568 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 569 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 569 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 570 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 570 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 571 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 571 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 572 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 572 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 573 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 574 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 574 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 575 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 575 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 576 "src/analyzer/types/Type.pv"
        default: {
            #line 576 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 580 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 581 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 582 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 582 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 583 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 583 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 584 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 584 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 585 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 585 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 586 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 586 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 586 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 587 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 587 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 587 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 588 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 588 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 588 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 589 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 589 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 590 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 590 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 591 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 591 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 591 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 591 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 591 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 592 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 592 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 592 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 593 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 593 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 594 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 594 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 595 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 595 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 596 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 596 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 597 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 597 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 598 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 598 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 599 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 599 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 600 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
