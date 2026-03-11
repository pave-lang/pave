#include <stdio.h>

#include <analyzer/Type.h>
#include <analyzer/Indirect.h>
#include <analyzer/TypedefC.h>
#include <std/ArenaAllocator.h>
#include <stdint.h>
#include <stdbool.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Context.h>
#include <analyzer/Sequence.h>
#include <analyzer/Tuple.h>
#include <analyzer/Primitive.h>
#include <analyzer/Enum.h>
#include <std/Array_Type.h>
#include <analyzer/Struct.h>
#include <analyzer/Trait.h>
#include <analyzer/Generic.h>
#include <std/str.h>
#include <analyzer/Function.h>
#include <analyzer/EnumC.h>
#include <analyzer/StructC.h>
#include <analyzer/FunctionC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/Token.h>
#include <std/HashMap_str_ref_Trait.h>
#include <analyzer/Module.h>

#include <analyzer/Type.h>

#line 103 "src/analyzer/Type.pv"
char const* Type__name(struct Type* self) {
    #line 104 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 105 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 105 "src/analyzer/Type.pv"
            return "Type::Primitive";
        } break;
        #line 106 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 106 "src/analyzer/Type.pv"
            return "Type::Indirect";
        } break;
        #line 107 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 107 "src/analyzer/Type.pv"
            return "Type::Sequence";
        } break;
        #line 108 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 108 "src/analyzer/Type.pv"
            return "Type::Tuple";
        } break;
        #line 109 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 109 "src/analyzer/Type.pv"
            return "Type::Enum";
        } break;
        #line 110 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 110 "src/analyzer/Type.pv"
            return "Type::Struct";
        } break;
        #line 111 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 111 "src/analyzer/Type.pv"
            return "Type::Trait";
        } break;
        #line 112 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 112 "src/analyzer/Type.pv"
            return "Type::Generic";
        } break;
        #line 113 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 113 "src/analyzer/Type.pv"
            return "Type::Unknown";
        } break;
        #line 114 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 114 "src/analyzer/Type.pv"
            return "Type::Function";
        } break;
        #line 115 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 115 "src/analyzer/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 116 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 116 "src/analyzer/Type.pv"
            return "Type::Self";
        } break;
        #line 117 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 117 "src/analyzer/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 118 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 118 "src/analyzer/Type.pv"
            return "Type::EnumC";
        } break;
        #line 119 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 119 "src/analyzer/Type.pv"
            return "Type::StructC";
        } break;
        #line 120 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 120 "src/analyzer/Type.pv"
            return "Type::UnionC";
        } break;
        #line 121 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 121 "src/analyzer/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 122 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 122 "src/analyzer/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 123 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 123 "src/analyzer/Type.pv"
            return "Type::NamespaceCpp";
        } break;
    }
}

#line 127 "src/analyzer/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 128 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 129 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 129 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 129 "src/analyzer/Type.pv"
            return &indirect->to;
        } break;
        #line 130 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 133 "src/analyzer/Type.pv"
    return self;
}

#line 136 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 137 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 138 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 138 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 138 "src/analyzer/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 139 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 142 "src/analyzer/Type.pv"
    return self;
}

#line 145 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 146 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 147 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 147 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 148 "src/analyzer/Type.pv"
            switch (info->type->type) {
                #line 149 "src/analyzer/Type.pv"
                case TYPE__INDIRECT: {
                    #line 149 "src/analyzer/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 150 "src/analyzer/Type.pv"
                    switch (indirect->to.type) {
                        #line 151 "src/analyzer/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 151 "src/analyzer/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 152 "src/analyzer/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 152 "src/analyzer/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 153 "src/analyzer/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 156 "src/analyzer/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 159 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 162 "src/analyzer/Type.pv"
    return self;
}

#line 165 "src/analyzer/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 166 "src/analyzer/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 167 "src/analyzer/Type.pv"
    if (type == 0) {
        #line 167 "src/analyzer/Type.pv"
        return 0;
    }

    #line 169 "src/analyzer/Type.pv"
    *type = *self;
    #line 170 "src/analyzer/Type.pv"
    return type;
}

#line 173 "src/analyzer/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 174 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 175 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 175 "src/analyzer/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 175 "src/analyzer/Type.pv"
            return generics;
        } break;
        #line 176 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 176 "src/analyzer/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 176 "src/analyzer/Type.pv"
            return generics;
        } break;
        #line 177 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 177 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 177 "src/analyzer/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 178 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 178 "src/analyzer/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 179 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 182 "src/analyzer/Type.pv"
    return 0;
}

#line 185 "src/analyzer/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 186 "src/analyzer/Type.pv"
    switch (other->type) {
        #line 187 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 187 "src/analyzer/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 187 "src/analyzer/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 188 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 188 "src/analyzer/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 188 "src/analyzer/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 189 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 189 "src/analyzer/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 189 "src/analyzer/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 190 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 190 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 190 "src/analyzer/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 191 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 191 "src/analyzer/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 191 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 191 "src/analyzer/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 192 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 192 "src/analyzer/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 192 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 192 "src/analyzer/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 193 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 193 "src/analyzer/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 193 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 193 "src/analyzer/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 194 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 194 "src/analyzer/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 194 "src/analyzer/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 195 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 195 "src/analyzer/Type.pv"
            struct str name = other->unknown_value._0;
            #line 195 "src/analyzer/Type.pv"
            struct Array_Type* generics = &other->unknown_value._1;
            #line 195 "src/analyzer/Type.pv"
            return Type__eq_unknown(self, name, generics);
        } break;
        #line 196 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 196 "src/analyzer/Type.pv"
            struct Function* function = other->function_value._0;
            #line 196 "src/analyzer/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 197 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 197 "src/analyzer/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 197 "src/analyzer/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 198 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 198 "src/analyzer/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 199 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 199 "src/analyzer/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 199 "src/analyzer/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 200 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 200 "src/analyzer/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 200 "src/analyzer/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 201 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 201 "src/analyzer/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 201 "src/analyzer/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 202 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 202 "src/analyzer/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 202 "src/analyzer/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 203 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 203 "src/analyzer/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 203 "src/analyzer/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 204 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 204 "src/analyzer/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 204 "src/analyzer/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 205 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 205 "src/analyzer/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 205 "src/analyzer/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 209 "src/analyzer/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 210 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 211 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 211 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 211 "src/analyzer/Type.pv"
            return Type__eq(&indirect->to, &other->to);
        } break;
        #line 212 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 212 "src/analyzer/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 212 "src/analyzer/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 213 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 213 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 214 "src/analyzer/Type.pv"
        default: {
            #line 214 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 217 "src/analyzer/Type.pv"
    return false;
}

#line 220 "src/analyzer/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 221 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 222 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 222 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 222 "src/analyzer/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 223 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 223 "src/analyzer/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 223 "src/analyzer/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 224 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 224 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 225 "src/analyzer/Type.pv"
        default: {
            #line 225 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 228 "src/analyzer/Type.pv"
    return false;
}

#line 231 "src/analyzer/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 250 "src/analyzer/Type.pv"
    return true;
}

#line 253 "src/analyzer/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 254 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 255 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 255 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 256 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 256 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 257 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 260 "src/analyzer/Type.pv"
    return other == 0 || str__eq(other->name, (struct str){ .ptr = "void", .length = strlen("void") });
}

#line 263 "src/analyzer/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 264 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 265 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 265 "src/analyzer/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 265 "src/analyzer/Type.pv"
            return enum_info == other_enum;
        } break;
        #line 266 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 266 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 266 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 267 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 267 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 268 "src/analyzer/Type.pv"
        default: {
            #line 268 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 271 "src/analyzer/Type.pv"
    return false;
}

#line 274 "src/analyzer/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 275 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 276 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 276 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 276 "src/analyzer/Type.pv"
            return struct_info == other_struct;
        } break;
        #line 277 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 277 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 278 "src/analyzer/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 279 "src/analyzer/Type.pv"
            return HashMap_str_ref_Trait__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 281 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 281 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 281 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 282 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 282 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 283 "src/analyzer/Type.pv"
        default: {
            #line 283 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 286 "src/analyzer/Type.pv"
    return false;
}

#line 289 "src/analyzer/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 290 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 291 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 291 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 291 "src/analyzer/Type.pv"
            return trait_info == other_trait;
        } break;
        #line 292 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 292 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 292 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 293 "src/analyzer/Type.pv"
        default: {
            #line 293 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 296 "src/analyzer/Type.pv"
    return false;
}

#line 299 "src/analyzer/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 300 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 301 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 301 "src/analyzer/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 301 "src/analyzer/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 302 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 302 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 302 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 303 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 303 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 304 "src/analyzer/Type.pv"
        default: {
            #line 304 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 307 "src/analyzer/Type.pv"
    return false;
}

#line 310 "src/analyzer/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 311 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 312 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 312 "src/analyzer/Type.pv"
            struct str name = self->unknown_value._0;
            #line 312 "src/analyzer/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 313 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 313 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 313 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 314 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 314 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 315 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 315 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 316 "src/analyzer/Type.pv"
        default: {
            #line 316 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 319 "src/analyzer/Type.pv"
    return false;
}

#line 322 "src/analyzer/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 323 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 324 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 324 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 325 "src/analyzer/Type.pv"
        default: {
            #line 325 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 328 "src/analyzer/Type.pv"
    return false;
}

#line 331 "src/analyzer/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 332 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 333 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 333 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 334 "src/analyzer/Type.pv"
        default: {
            #line 334 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 337 "src/analyzer/Type.pv"
    return false;
}

#line 340 "src/analyzer/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 341 "src/analyzer/Type.pv"
    return true;
}

#line 352 "src/analyzer/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 353 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 354 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 354 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 354 "src/analyzer/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 355 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 355 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 355 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 356 "src/analyzer/Type.pv"
        default: {
            #line 356 "src/analyzer/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 359 "src/analyzer/Type.pv"
    return false;
}

#line 362 "src/analyzer/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 363 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 364 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 364 "src/analyzer/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 364 "src/analyzer/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 365 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 365 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 365 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 366 "src/analyzer/Type.pv"
        default: {
            #line 366 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 369 "src/analyzer/Type.pv"
    return false;
}

#line 372 "src/analyzer/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 373 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 374 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 374 "src/analyzer/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 374 "src/analyzer/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 375 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 375 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 375 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 376 "src/analyzer/Type.pv"
        default: {
            #line 376 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 379 "src/analyzer/Type.pv"
    return false;
}

#line 382 "src/analyzer/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 383 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 384 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 384 "src/analyzer/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 384 "src/analyzer/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 385 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 385 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 385 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 386 "src/analyzer/Type.pv"
        default: {
            #line 386 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 389 "src/analyzer/Type.pv"
    return false;
}

#line 392 "src/analyzer/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 393 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 394 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 394 "src/analyzer/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 394 "src/analyzer/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 395 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 395 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 395 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 396 "src/analyzer/Type.pv"
        default: {
            #line 396 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 399 "src/analyzer/Type.pv"
    return false;
}

#line 402 "src/analyzer/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 403 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 404 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 404 "src/analyzer/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 404 "src/analyzer/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 405 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 405 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 405 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 406 "src/analyzer/Type.pv"
        default: {
            #line 406 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 409 "src/analyzer/Type.pv"
    return false;
}

#line 412 "src/analyzer/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 413 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 414 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 414 "src/analyzer/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 414 "src/analyzer/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 415 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 415 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 415 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 416 "src/analyzer/Type.pv"
        default: {
            #line 416 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 419 "src/analyzer/Type.pv"
    return false;
}

#line 422 "src/analyzer/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 423 "src/analyzer/Type.pv"
    if (self == 0) {
        #line 423 "src/analyzer/Type.pv"
        return true;
    }

    #line 425 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 426 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 426 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 426 "src/analyzer/Type.pv"
            return primitive_info == 0 || str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 427 "src/analyzer/Type.pv"
        default: {
            #line 427 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 431 "src/analyzer/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 432 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 433 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 433 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 434 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 434 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 435 "src/analyzer/Type.pv"
        default: {
            #line 435 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 439 "src/analyzer/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 440 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 441 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 441 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 442 "src/analyzer/Type.pv"
        default: {
            #line 442 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 446 "src/analyzer/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 447 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 448 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 448 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 449 "src/analyzer/Type.pv"
        default: {
            #line 449 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 453 "src/analyzer/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 454 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 455 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 455 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 456 "src/analyzer/Type.pv"
        default: {
            #line 456 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 460 "src/analyzer/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 461 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 462 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 462 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 462 "src/analyzer/Type.pv"
            return &indirect->to;
        } break;
        #line 463 "src/analyzer/Type.pv"
        default: {
            #line 463 "src/analyzer/Type.pv"
            return 0;
        } break;
    }
}

#line 467 "src/analyzer/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 468 "src/analyzer/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 469 "src/analyzer/Type.pv"
    if (referenced_type == 0) {
        #line 469 "src/analyzer/Type.pv"
        return false;
    }

    #line 471 "src/analyzer/Type.pv"
    switch (referenced_type->type) {
        #line 472 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 472 "src/analyzer/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 472 "src/analyzer/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 473 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 473 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 474 "src/analyzer/Type.pv"
        default: {
            #line 474 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 478 "src/analyzer/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 479 "src/analyzer/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 480 "src/analyzer/Type.pv"
    if (referenced_type == 0) {
        #line 480 "src/analyzer/Type.pv"
        return false;
    }

    #line 482 "src/analyzer/Type.pv"
    switch (referenced_type->type) {
        #line 483 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 483 "src/analyzer/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 483 "src/analyzer/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 484 "src/analyzer/Type.pv"
        default: {
            #line 484 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 488 "src/analyzer/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 489 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 490 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 490 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 491 "src/analyzer/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 493 "src/analyzer/Type.pv"
        default: {
            #line 493 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 497 "src/analyzer/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 498 "src/analyzer/Type.pv"
    bool sequence_is_slice = false;
    #line 499 "src/analyzer/Type.pv"
    bool str_cast = false;

    #line 501 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 502 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 502 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 503 "src/analyzer/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 504 "src/analyzer/Type.pv"
            if (!str_cast) {
                #line 504 "src/analyzer/Type.pv"
                return false;
            }
        } break;
        #line 506 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 506 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 507 "src/analyzer/Type.pv"
            switch (indirect->to.type) {
                #line 508 "src/analyzer/Type.pv"
                case TYPE__STRUCT: {
                    #line 508 "src/analyzer/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 509 "src/analyzer/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 510 "src/analyzer/Type.pv"
                    if (!str_cast) {
                        #line 510 "src/analyzer/Type.pv"
                        return false;
                    }
                } break;
                #line 512 "src/analyzer/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 513 "src/analyzer/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 513 "src/analyzer/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 513 "src/analyzer/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 514 "src/analyzer/Type.pv"
                default: {
                    #line 514 "src/analyzer/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 517 "src/analyzer/Type.pv"
        default: {
            #line 517 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 520 "src/analyzer/Type.pv"
    if (str_cast) {
        #line 521 "src/analyzer/Type.pv"
        switch (other->type) {
            #line 522 "src/analyzer/Type.pv"
            case TYPE__INDIRECT: {
                #line 522 "src/analyzer/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 523 "src/analyzer/Type.pv"
                switch (indirect->to.type) {
                    #line 524 "src/analyzer/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 524 "src/analyzer/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 525 "src/analyzer/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 527 "src/analyzer/Type.pv"
                    default: {
                        #line 527 "src/analyzer/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 530 "src/analyzer/Type.pv"
            default: {
                #line 530 "src/analyzer/Type.pv"
                return false;
            } break;
        }
    }

    #line 534 "src/analyzer/Type.pv"
    switch (other->type) {
        #line 535 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 535 "src/analyzer/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 536 "src/analyzer/Type.pv"
            switch (indirect->to.type) {
                #line 537 "src/analyzer/Type.pv"
                case TYPE__TRAIT: {
                    #line 537 "src/analyzer/Type.pv"
                    return false;
                } break;
                #line 538 "src/analyzer/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 538 "src/analyzer/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 538 "src/analyzer/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 539 "src/analyzer/Type.pv"
                default: {
                    #line 539 "src/analyzer/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 542 "src/analyzer/Type.pv"
        default: {
            #line 542 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 545 "src/analyzer/Type.pv"
    return false;
}

#line 548 "src/analyzer/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 549 "src/analyzer/Type.pv"
    if (self == 0) {
        #line 549 "src/analyzer/Type.pv"
        return false;
    }

    #line 551 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 552 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 552 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 553 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 553 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 554 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 554 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 555 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 555 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 556 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 556 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 557 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 557 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 558 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 558 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 559 "src/analyzer/Type.pv"
        default: {
            #line 559 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 563 "src/analyzer/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 564 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 565 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 565 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 566 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 566 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 567 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 567 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 568 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 568 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 569 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 569 "src/analyzer/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 569 "src/analyzer/Type.pv"
            return enum_info->context->module;
        } break;
        #line 570 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 570 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 570 "src/analyzer/Type.pv"
            return struct_info->module;
        } break;
        #line 571 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 571 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 571 "src/analyzer/Type.pv"
            return trait_info->module;
        } break;
        #line 572 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 572 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 573 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 573 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 574 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 574 "src/analyzer/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 574 "src/analyzer/Type.pv"
            if (func_info->context != 0) {
                #line 574 "src/analyzer/Type.pv"
                return func_info->context->module;
            } else {
                #line 574 "src/analyzer/Type.pv"
                return 0;
            }
        } break;
        #line 575 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 575 "src/analyzer/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 575 "src/analyzer/Type.pv"
            return func_info->context->module;
        } break;
        #line 576 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 576 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 577 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 577 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 578 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 578 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 579 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 579 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 580 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 580 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 581 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 581 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 582 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 582 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 583 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 583 "src/analyzer/Type.pv"
            return 0;
        } break;
    }
}
