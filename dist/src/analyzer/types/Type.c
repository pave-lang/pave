#include <stdio.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/TypedefC.h>
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
#include <analyzer/EnumC.h>
#include <analyzer/StructC.h>
#include <analyzer/FunctionC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/Token.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Module.h>

#include <analyzer/types/Type.h>

#line 104 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 105 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 106 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 106 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 107 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 107 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 108 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 108 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 109 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 109 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 110 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 110 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 111 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 111 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 112 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 112 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 113 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 113 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 114 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 114 "src/analyzer/types/Type.pv"
            return "Type::Unknown";
        } break;
        #line 115 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 116 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 116 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 117 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 117 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 118 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 118 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 119 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 119 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 120 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 120 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 121 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 121 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
    }
}

#line 128 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 129 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 130 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 130 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 130 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 131 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 134 "src/analyzer/types/Type.pv"
    return self;
}

#line 137 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 138 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 139 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 139 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 139 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 140 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 143 "src/analyzer/types/Type.pv"
    return self;
}

#line 146 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 147 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 148 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 148 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 149 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 150 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 150 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 151 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 152 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 152 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 153 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 153 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 154 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 157 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 160 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 163 "src/analyzer/types/Type.pv"
    return self;
}

#line 166 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 167 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 168 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 168 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 170 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 171 "src/analyzer/types/Type.pv"
    return type;
}

#line 174 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 175 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 176 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 176 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 176 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 177 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 177 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 177 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 178 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 178 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 178 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 179 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 179 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 180 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 183 "src/analyzer/types/Type.pv"
    return 0;
}

#line 186 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 187 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 188 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 188 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 188 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 189 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 189 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 189 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 190 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 190 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 191 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 191 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 192 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 192 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 192 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 192 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
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
        case TYPE__TRAIT: {
            #line 194 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 194 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 194 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 195 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 195 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 195 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 196 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 196 "src/analyzer/types/Type.pv"
            struct str name = other->unknown_value._0;
            #line 196 "src/analyzer/types/Type.pv"
            struct Array_Type* generics = &other->unknown_value._1;
            #line 196 "src/analyzer/types/Type.pv"
            return Type__eq_unknown(self, name, generics);
        } break;
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 197 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 197 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 198 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 198 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 198 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 199 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 200 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 200 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 200 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 201 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 201 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 201 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 202 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 202 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 203 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 203 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 203 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 204 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 204 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 204 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 205 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 205 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 205 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 206 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 206 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 206 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 210 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 211 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 212 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 212 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 212 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 213 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 213 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 213 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 214 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 214 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 215 "src/analyzer/types/Type.pv"
        default: {
            #line 215 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 218 "src/analyzer/types/Type.pv"
    return false;
}

#line 221 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 222 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 223 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 223 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 223 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 224 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 224 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 224 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 225 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        default: {
            #line 226 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 229 "src/analyzer/types/Type.pv"
    return false;
}

#line 232 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 251 "src/analyzer/types/Type.pv"
    return true;
}

#line 254 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 255 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 256 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 256 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 257 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || other == 0 || str__eq(primitive_info->name, other->name) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || Primitive__is_void(other);
        } break;
        #line 259 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 259 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 260 "src/analyzer/types/Type.pv"
        default: {
            #line 260 "src/analyzer/types/Type.pv"
            return Primitive__is_void(other);
        } break;
    }
}

#line 264 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 265 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 266 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 266 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 266 "src/analyzer/types/Type.pv"
            return enum_info == other_enum;
        } break;
        #line 267 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 267 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 267 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 268 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 269 "src/analyzer/types/Type.pv"
        default: {
            #line 269 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 272 "src/analyzer/types/Type.pv"
    return false;
}

#line 275 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 276 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 277 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 277 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 277 "src/analyzer/types/Type.pv"
            return struct_info == other_struct;
        } break;
        #line 278 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 278 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 279 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 280 "src/analyzer/types/Type.pv"
            return HashMap_str_ref_Trait__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 282 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 282 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 282 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 283 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 283 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 284 "src/analyzer/types/Type.pv"
        default: {
            #line 284 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 287 "src/analyzer/types/Type.pv"
    return false;
}

#line 290 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 291 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 292 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 292 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 292 "src/analyzer/types/Type.pv"
            return trait_info == other_trait;
        } break;
        #line 293 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 293 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 293 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 294 "src/analyzer/types/Type.pv"
        default: {
            #line 294 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 297 "src/analyzer/types/Type.pv"
    return false;
}

#line 300 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 301 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 302 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 302 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 302 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 303 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 303 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 303 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 304 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 304 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 305 "src/analyzer/types/Type.pv"
        default: {
            #line 305 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 308 "src/analyzer/types/Type.pv"
    return false;
}

#line 311 "src/analyzer/types/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 312 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 313 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 313 "src/analyzer/types/Type.pv"
            struct str name = self->unknown_value._0;
            #line 313 "src/analyzer/types/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 314 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 314 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 314 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 315 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 316 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 316 "src/analyzer/types/Type.pv"
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 324 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 325 "src/analyzer/types/Type.pv"
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 333 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 334 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 334 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 335 "src/analyzer/types/Type.pv"
        default: {
            #line 335 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 338 "src/analyzer/types/Type.pv"
    return false;
}

#line 341 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 342 "src/analyzer/types/Type.pv"
    return true;
}

#line 353 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 354 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 355 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 355 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 355 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 356 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 356 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 356 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 357 "src/analyzer/types/Type.pv"
        default: {
            #line 357 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 360 "src/analyzer/types/Type.pv"
    return false;
}

#line 363 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 364 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 365 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 365 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 365 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 366 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 366 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 366 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 367 "src/analyzer/types/Type.pv"
        default: {
            #line 367 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 370 "src/analyzer/types/Type.pv"
    return false;
}

#line 373 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 374 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 375 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 375 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 375 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 376 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 376 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 376 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 377 "src/analyzer/types/Type.pv"
        default: {
            #line 377 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 380 "src/analyzer/types/Type.pv"
    return false;
}

#line 383 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 384 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 385 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 385 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 385 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 386 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 386 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 386 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 387 "src/analyzer/types/Type.pv"
        default: {
            #line 387 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 390 "src/analyzer/types/Type.pv"
    return false;
}

#line 393 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 394 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 395 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 395 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 395 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 396 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 396 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 396 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 397 "src/analyzer/types/Type.pv"
        default: {
            #line 397 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 400 "src/analyzer/types/Type.pv"
    return false;
}

#line 403 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 404 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 405 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 405 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 405 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 406 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 406 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 406 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 407 "src/analyzer/types/Type.pv"
        default: {
            #line 407 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 410 "src/analyzer/types/Type.pv"
    return false;
}

#line 413 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 414 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 415 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 415 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 415 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 416 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 416 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 416 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 417 "src/analyzer/types/Type.pv"
        default: {
            #line 417 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 420 "src/analyzer/types/Type.pv"
    return false;
}

#line 423 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 424 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 424 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 426 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 427 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 427 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 427 "src/analyzer/types/Type.pv"
            return primitive_info == 0 || Primitive__is_void(primitive_info);
        } break;
        #line 428 "src/analyzer/types/Type.pv"
        default: {
            #line 428 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 432 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 433 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 434 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 434 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 435 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 435 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 436 "src/analyzer/types/Type.pv"
        default: {
            #line 436 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 440 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 441 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 442 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 442 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 443 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 443 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 444 "src/analyzer/types/Type.pv"
        default: {
            #line 444 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 448 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 449 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 450 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
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
bool Type__is_trait(struct Type* self) {
    #line 456 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 457 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_tuple(struct Type* self) {
    #line 463 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 464 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 464 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 465 "src/analyzer/types/Type.pv"
        default: {
            #line 465 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 469 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 470 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 471 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 471 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 472 "src/analyzer/types/Type.pv"
        default: {
            #line 472 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 476 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 477 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 478 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 478 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 478 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 479 "src/analyzer/types/Type.pv"
        default: {
            #line 479 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 483 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 484 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 485 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 485 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 487 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 488 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 488 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 488 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 489 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 495 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 496 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 496 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 498 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 499 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 499 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 499 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 500 "src/analyzer/types/Type.pv"
        default: {
            #line 500 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 504 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 505 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 506 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 506 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 507 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 509 "src/analyzer/types/Type.pv"
        default: {
            #line 509 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 513 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 514 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 515 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 517 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 518 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 518 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 519 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 520 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 520 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 522 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 522 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 523 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 524 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 524 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 525 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 526 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 526 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 528 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 529 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 529 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 529 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 530 "src/analyzer/types/Type.pv"
                default: {
                    #line 530 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 533 "src/analyzer/types/Type.pv"
        default: {
            #line 533 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 536 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 537 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 538 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 538 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 539 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 540 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 540 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 541 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 543 "src/analyzer/types/Type.pv"
                    default: {
                        #line 543 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 546 "src/analyzer/types/Type.pv"
            default: {
                #line 546 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 550 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 551 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 551 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 552 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 553 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 553 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 554 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 554 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 554 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 555 "src/analyzer/types/Type.pv"
                default: {
                    #line 555 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 558 "src/analyzer/types/Type.pv"
        default: {
            #line 558 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 561 "src/analyzer/types/Type.pv"
    return false;
}

#line 564 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 565 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 565 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 567 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 568 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 568 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 569 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 569 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 570 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 570 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 571 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 571 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 572 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 572 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 573 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 574 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 574 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 575 "src/analyzer/types/Type.pv"
        default: {
            #line 575 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 579 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 580 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 581 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 581 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 582 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 582 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 583 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 583 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 584 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 584 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 585 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 585 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 585 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 586 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 586 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 586 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 587 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 587 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 587 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 588 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 588 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 589 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN: {
            #line 589 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 590 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 590 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 590 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 590 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 590 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 591 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 591 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 591 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 592 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 592 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 593 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 593 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 594 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 594 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 595 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 595 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 596 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 596 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 597 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 597 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 598 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 598 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 599 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 599 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
