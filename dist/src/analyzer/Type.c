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

#line 96 "src/analyzer/Type.pv"
char const* Type__name(struct Type* self) {
    #line 97 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 98 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 98 "src/analyzer/Type.pv"
            return "Type::Primitive";
        } break;
        #line 99 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 99 "src/analyzer/Type.pv"
            return "Type::Indirect";
        } break;
        #line 100 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 100 "src/analyzer/Type.pv"
            return "Type::Sequence";
        } break;
        #line 101 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 101 "src/analyzer/Type.pv"
            return "Type::Tuple";
        } break;
        #line 102 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 102 "src/analyzer/Type.pv"
            return "Type::Enum";
        } break;
        #line 103 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 103 "src/analyzer/Type.pv"
            return "Type::Struct";
        } break;
        #line 104 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 104 "src/analyzer/Type.pv"
            return "Type::Trait";
        } break;
        #line 105 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 105 "src/analyzer/Type.pv"
            return "Type::Generic";
        } break;
        #line 106 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 106 "src/analyzer/Type.pv"
            return "Type::Unknown";
        } break;
        #line 107 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 107 "src/analyzer/Type.pv"
            return "Type::Function";
        } break;
        #line 108 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 108 "src/analyzer/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 109 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 109 "src/analyzer/Type.pv"
            return "Type::Self";
        } break;
        #line 110 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 110 "src/analyzer/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 111 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 111 "src/analyzer/Type.pv"
            return "Type::EnumC";
        } break;
        #line 112 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 112 "src/analyzer/Type.pv"
            return "Type::StructC";
        } break;
        #line 113 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 113 "src/analyzer/Type.pv"
            return "Type::UnionC";
        } break;
        #line 114 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 114 "src/analyzer/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 115 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 115 "src/analyzer/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 116 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 116 "src/analyzer/Type.pv"
            return "Type::NamespaceCpp";
        } break;
    }
}

#line 120 "src/analyzer/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 121 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 122 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 122 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 122 "src/analyzer/Type.pv"
            return &indirect->to;
        } break;
        #line 123 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 126 "src/analyzer/Type.pv"
    return self;
}

#line 129 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 130 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 131 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 131 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 131 "src/analyzer/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 132 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 135 "src/analyzer/Type.pv"
    return self;
}

#line 138 "src/analyzer/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 139 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 140 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 140 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 141 "src/analyzer/Type.pv"
            switch (info->type->type) {
                #line 142 "src/analyzer/Type.pv"
                case TYPE__INDIRECT: {
                    #line 142 "src/analyzer/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 143 "src/analyzer/Type.pv"
                    switch (indirect->to.type) {
                        #line 144 "src/analyzer/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 144 "src/analyzer/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 145 "src/analyzer/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 145 "src/analyzer/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 146 "src/analyzer/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 149 "src/analyzer/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 152 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 155 "src/analyzer/Type.pv"
    return self;
}

#line 158 "src/analyzer/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 159 "src/analyzer/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 160 "src/analyzer/Type.pv"
    if (type == 0) {
        #line 160 "src/analyzer/Type.pv"
        return 0;
    }

    #line 162 "src/analyzer/Type.pv"
    *type = *self;
    #line 163 "src/analyzer/Type.pv"
    return type;
}

#line 166 "src/analyzer/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 167 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 168 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 168 "src/analyzer/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 168 "src/analyzer/Type.pv"
            return generics;
        } break;
        #line 169 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 169 "src/analyzer/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 169 "src/analyzer/Type.pv"
            return generics;
        } break;
        #line 170 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 170 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 170 "src/analyzer/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 171 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 171 "src/analyzer/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 172 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 175 "src/analyzer/Type.pv"
    return 0;
}

#line 178 "src/analyzer/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 179 "src/analyzer/Type.pv"
    switch (other->type) {
        #line 180 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 180 "src/analyzer/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 180 "src/analyzer/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 181 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 181 "src/analyzer/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 181 "src/analyzer/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 182 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 182 "src/analyzer/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 182 "src/analyzer/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 183 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 183 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 183 "src/analyzer/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 184 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 184 "src/analyzer/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 184 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 184 "src/analyzer/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 185 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 185 "src/analyzer/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 185 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 185 "src/analyzer/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 186 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 186 "src/analyzer/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 186 "src/analyzer/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 186 "src/analyzer/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 187 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 187 "src/analyzer/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 187 "src/analyzer/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 188 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 188 "src/analyzer/Type.pv"
            struct str name = other->unknown_value._0;
            #line 188 "src/analyzer/Type.pv"
            struct Array_Type* generics = &other->unknown_value._1;
            #line 188 "src/analyzer/Type.pv"
            return Type__eq_unknown(self, name, generics);
        } break;
        #line 189 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 189 "src/analyzer/Type.pv"
            struct Function* function = other->function_value._0;
            #line 189 "src/analyzer/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 190 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 190 "src/analyzer/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 190 "src/analyzer/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 191 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 191 "src/analyzer/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 192 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 192 "src/analyzer/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 192 "src/analyzer/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 193 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 193 "src/analyzer/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 193 "src/analyzer/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 194 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 194 "src/analyzer/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 194 "src/analyzer/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 195 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 195 "src/analyzer/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 195 "src/analyzer/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 196 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 196 "src/analyzer/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 196 "src/analyzer/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 197 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 197 "src/analyzer/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 197 "src/analyzer/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 198 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 198 "src/analyzer/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 198 "src/analyzer/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
    }
}

#line 202 "src/analyzer/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 203 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 204 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 204 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 204 "src/analyzer/Type.pv"
            return Type__eq(&indirect->to, &other->to);
        } break;
        #line 205 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 205 "src/analyzer/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 205 "src/analyzer/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 206 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 206 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 207 "src/analyzer/Type.pv"
        default: {
            #line 207 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 210 "src/analyzer/Type.pv"
    return false;
}

#line 213 "src/analyzer/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 214 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 215 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 215 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 215 "src/analyzer/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 216 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 216 "src/analyzer/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 216 "src/analyzer/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 217 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 217 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 218 "src/analyzer/Type.pv"
        default: {
            #line 218 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 221 "src/analyzer/Type.pv"
    return false;
}

#line 224 "src/analyzer/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 243 "src/analyzer/Type.pv"
    return true;
}

#line 246 "src/analyzer/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 247 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 248 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 248 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 249 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 249 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 250 "src/analyzer/Type.pv"
        default: {
        } break;
    }

    #line 253 "src/analyzer/Type.pv"
    return other == 0 || str__eq(other->name, (struct str){ .ptr = "void", .length = strlen("void") });
}

#line 256 "src/analyzer/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 257 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 258 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 258 "src/analyzer/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 258 "src/analyzer/Type.pv"
            return enum_info == other_enum;
        } break;
        #line 259 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 259 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 259 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 260 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 260 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 261 "src/analyzer/Type.pv"
        default: {
            #line 261 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 264 "src/analyzer/Type.pv"
    return false;
}

#line 267 "src/analyzer/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 268 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 269 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 269 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 269 "src/analyzer/Type.pv"
            return struct_info == other_struct;
        } break;
        #line 270 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 270 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 271 "src/analyzer/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 272 "src/analyzer/Type.pv"
            return HashMap_str_ref_Trait__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 274 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 274 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 274 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 275 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 275 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 276 "src/analyzer/Type.pv"
        default: {
            #line 276 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 279 "src/analyzer/Type.pv"
    return false;
}

#line 282 "src/analyzer/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 283 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 284 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 284 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 284 "src/analyzer/Type.pv"
            return trait_info == other_trait;
        } break;
        #line 285 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 285 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 285 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 286 "src/analyzer/Type.pv"
        default: {
            #line 286 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 289 "src/analyzer/Type.pv"
    return false;
}

#line 292 "src/analyzer/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 293 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 294 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 294 "src/analyzer/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 294 "src/analyzer/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 295 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 295 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 295 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 296 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 296 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 297 "src/analyzer/Type.pv"
        default: {
            #line 297 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 300 "src/analyzer/Type.pv"
    return false;
}

#line 303 "src/analyzer/Type.pv"
bool Type__eq_unknown(struct Type* self, struct str other_name, struct Array_Type* generics) {
    #line 304 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 305 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 305 "src/analyzer/Type.pv"
            struct str name = self->unknown_value._0;
            #line 305 "src/analyzer/Type.pv"
            return str__eq(name, other_name);
        } break;
        #line 306 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 306 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 306 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 307 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 307 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 308 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 308 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 309 "src/analyzer/Type.pv"
        default: {
            #line 309 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 312 "src/analyzer/Type.pv"
    return false;
}

#line 315 "src/analyzer/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 316 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 317 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 317 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 318 "src/analyzer/Type.pv"
        default: {
            #line 318 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 321 "src/analyzer/Type.pv"
    return false;
}

#line 324 "src/analyzer/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 325 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 326 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 326 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 327 "src/analyzer/Type.pv"
        default: {
            #line 327 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 330 "src/analyzer/Type.pv"
    return false;
}

#line 333 "src/analyzer/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 334 "src/analyzer/Type.pv"
    return true;
}

#line 345 "src/analyzer/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 346 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 347 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 347 "src/analyzer/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 347 "src/analyzer/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 348 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 348 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 348 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 349 "src/analyzer/Type.pv"
        default: {
            #line 349 "src/analyzer/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 352 "src/analyzer/Type.pv"
    return false;
}

#line 355 "src/analyzer/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 356 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 357 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 357 "src/analyzer/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 357 "src/analyzer/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
        } break;
        #line 358 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 358 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 358 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 359 "src/analyzer/Type.pv"
        default: {
            #line 359 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 362 "src/analyzer/Type.pv"
    return false;
}

#line 365 "src/analyzer/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 366 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 367 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 367 "src/analyzer/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 367 "src/analyzer/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
        } break;
        #line 368 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 368 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 368 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 369 "src/analyzer/Type.pv"
        default: {
            #line 369 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 372 "src/analyzer/Type.pv"
    return false;
}

#line 375 "src/analyzer/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 376 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 377 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 377 "src/analyzer/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 377 "src/analyzer/Type.pv"
            return str__eq(union_info->name, other_union->name);
        } break;
        #line 378 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 378 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 378 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 379 "src/analyzer/Type.pv"
        default: {
            #line 379 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 382 "src/analyzer/Type.pv"
    return false;
}

#line 385 "src/analyzer/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 386 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 387 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 387 "src/analyzer/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 387 "src/analyzer/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 388 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 388 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 388 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 389 "src/analyzer/Type.pv"
        default: {
            #line 389 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 392 "src/analyzer/Type.pv"
    return false;
}

#line 395 "src/analyzer/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 396 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 397 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 397 "src/analyzer/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 397 "src/analyzer/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 398 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 398 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 398 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 399 "src/analyzer/Type.pv"
        default: {
            #line 399 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 402 "src/analyzer/Type.pv"
    return false;
}

#line 405 "src/analyzer/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 406 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 407 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 407 "src/analyzer/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 407 "src/analyzer/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 408 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 408 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 408 "src/analyzer/Type.pv"
            return str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 409 "src/analyzer/Type.pv"
        default: {
            #line 409 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 412 "src/analyzer/Type.pv"
    return false;
}

#line 415 "src/analyzer/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 416 "src/analyzer/Type.pv"
    if (self == 0) {
        #line 416 "src/analyzer/Type.pv"
        return true;
    }

    #line 418 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 419 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 419 "src/analyzer/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 419 "src/analyzer/Type.pv"
            return primitive_info == 0 || str__eq(primitive_info->name, (struct str){ .ptr = "void", .length = strlen("void") });
        } break;
        #line 420 "src/analyzer/Type.pv"
        default: {
            #line 420 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 424 "src/analyzer/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 425 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 426 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 426 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 427 "src/analyzer/Type.pv"
        default: {
            #line 427 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 431 "src/analyzer/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 432 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 433 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 433 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 434 "src/analyzer/Type.pv"
        default: {
            #line 434 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 438 "src/analyzer/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 439 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 440 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 440 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 441 "src/analyzer/Type.pv"
        default: {
            #line 441 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 445 "src/analyzer/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 446 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 447 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 447 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 448 "src/analyzer/Type.pv"
        default: {
            #line 448 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 452 "src/analyzer/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 453 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 454 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 454 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 454 "src/analyzer/Type.pv"
            return &indirect->to;
        } break;
        #line 455 "src/analyzer/Type.pv"
        default: {
            #line 455 "src/analyzer/Type.pv"
            return 0;
        } break;
    }
}

#line 459 "src/analyzer/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 460 "src/analyzer/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 461 "src/analyzer/Type.pv"
    if (referenced_type == 0) {
        #line 461 "src/analyzer/Type.pv"
        return false;
    }

    #line 463 "src/analyzer/Type.pv"
    switch (referenced_type->type) {
        #line 464 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 464 "src/analyzer/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 464 "src/analyzer/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 465 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 465 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 466 "src/analyzer/Type.pv"
        default: {
            #line 466 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 470 "src/analyzer/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 471 "src/analyzer/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 472 "src/analyzer/Type.pv"
    if (referenced_type == 0) {
        #line 472 "src/analyzer/Type.pv"
        return false;
    }

    #line 474 "src/analyzer/Type.pv"
    switch (referenced_type->type) {
        #line 475 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 475 "src/analyzer/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 475 "src/analyzer/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 476 "src/analyzer/Type.pv"
        default: {
            #line 476 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 480 "src/analyzer/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 481 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 482 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 482 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 483 "src/analyzer/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 485 "src/analyzer/Type.pv"
        default: {
            #line 485 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 489 "src/analyzer/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 490 "src/analyzer/Type.pv"
    bool sequence_is_slice = false;
    #line 491 "src/analyzer/Type.pv"
    bool str_cast = false;

    #line 493 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 494 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 494 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 495 "src/analyzer/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 496 "src/analyzer/Type.pv"
            if (!str_cast) {
                #line 496 "src/analyzer/Type.pv"
                return false;
            }
        } break;
        #line 498 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 498 "src/analyzer/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 499 "src/analyzer/Type.pv"
            switch (indirect->to.type) {
                #line 500 "src/analyzer/Type.pv"
                case TYPE__STRUCT: {
                    #line 500 "src/analyzer/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 501 "src/analyzer/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 502 "src/analyzer/Type.pv"
                    if (!str_cast) {
                        #line 502 "src/analyzer/Type.pv"
                        return false;
                    }
                } break;
                #line 504 "src/analyzer/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 505 "src/analyzer/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 505 "src/analyzer/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 505 "src/analyzer/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 506 "src/analyzer/Type.pv"
                default: {
                    #line 506 "src/analyzer/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 509 "src/analyzer/Type.pv"
        default: {
            #line 509 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 512 "src/analyzer/Type.pv"
    if (str_cast) {
        #line 513 "src/analyzer/Type.pv"
        switch (other->type) {
            #line 514 "src/analyzer/Type.pv"
            case TYPE__INDIRECT: {
                #line 514 "src/analyzer/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 515 "src/analyzer/Type.pv"
                switch (indirect->to.type) {
                    #line 516 "src/analyzer/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 516 "src/analyzer/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 517 "src/analyzer/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 519 "src/analyzer/Type.pv"
                    default: {
                        #line 519 "src/analyzer/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 522 "src/analyzer/Type.pv"
            default: {
                #line 522 "src/analyzer/Type.pv"
                return false;
            } break;
        }
    }

    #line 526 "src/analyzer/Type.pv"
    switch (other->type) {
        #line 527 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 527 "src/analyzer/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 528 "src/analyzer/Type.pv"
            switch (indirect->to.type) {
                #line 529 "src/analyzer/Type.pv"
                case TYPE__TRAIT: {
                    #line 529 "src/analyzer/Type.pv"
                    return false;
                } break;
                #line 530 "src/analyzer/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 530 "src/analyzer/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 530 "src/analyzer/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 531 "src/analyzer/Type.pv"
                default: {
                    #line 531 "src/analyzer/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 534 "src/analyzer/Type.pv"
        default: {
            #line 534 "src/analyzer/Type.pv"
            return false;
        } break;
    }

    #line 537 "src/analyzer/Type.pv"
    return false;
}

#line 540 "src/analyzer/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 541 "src/analyzer/Type.pv"
    if (self == 0) {
        #line 541 "src/analyzer/Type.pv"
        return false;
    }

    #line 543 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 544 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 544 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 545 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 545 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 546 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 546 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 547 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 547 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 548 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 548 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 549 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 549 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 550 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 550 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 551 "src/analyzer/Type.pv"
        default: {
            #line 551 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 555 "src/analyzer/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 556 "src/analyzer/Type.pv"
    switch (self->type) {
        #line 557 "src/analyzer/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 557 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 558 "src/analyzer/Type.pv"
        case TYPE__INDIRECT: {
            #line 558 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 559 "src/analyzer/Type.pv"
        case TYPE__SEQUENCE: {
            #line 559 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 560 "src/analyzer/Type.pv"
        case TYPE__TUPLE: {
            #line 560 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 561 "src/analyzer/Type.pv"
        case TYPE__ENUM: {
            #line 561 "src/analyzer/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 561 "src/analyzer/Type.pv"
            return enum_info->context->module;
        } break;
        #line 562 "src/analyzer/Type.pv"
        case TYPE__STRUCT: {
            #line 562 "src/analyzer/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 562 "src/analyzer/Type.pv"
            return struct_info->module;
        } break;
        #line 563 "src/analyzer/Type.pv"
        case TYPE__TRAIT: {
            #line 563 "src/analyzer/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 563 "src/analyzer/Type.pv"
            return trait_info->module;
        } break;
        #line 564 "src/analyzer/Type.pv"
        case TYPE__GENERIC: {
            #line 564 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 565 "src/analyzer/Type.pv"
        case TYPE__UNKNOWN: {
            #line 565 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 566 "src/analyzer/Type.pv"
        case TYPE__FUNCTION: {
            #line 566 "src/analyzer/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 566 "src/analyzer/Type.pv"
            if (func_info->context != 0) {
                #line 566 "src/analyzer/Type.pv"
                return func_info->context->module;
            } else {
                #line 566 "src/analyzer/Type.pv"
                return 0;
            }
        } break;
        #line 567 "src/analyzer/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 567 "src/analyzer/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 567 "src/analyzer/Type.pv"
            return func_info->context->module;
        } break;
        #line 568 "src/analyzer/Type.pv"
        case TYPE__SELF: {
            #line 568 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 569 "src/analyzer/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 569 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 570 "src/analyzer/Type.pv"
        case TYPE__ENUM_C: {
            #line 570 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 571 "src/analyzer/Type.pv"
        case TYPE__STRUCT_C: {
            #line 571 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 572 "src/analyzer/Type.pv"
        case TYPE__UNION_C: {
            #line 572 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 573 "src/analyzer/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 573 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 574 "src/analyzer/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 574 "src/analyzer/Type.pv"
            return 0;
        } break;
        #line 575 "src/analyzer/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 575 "src/analyzer/Type.pv"
            return 0;
        } break;
    }
}
