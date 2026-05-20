#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
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
#include <analyzer/types/GenericTypedef.h>
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

#line 112 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 113 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 114 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 114 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 115 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 116 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 116 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 117 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 117 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 118 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 118 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 119 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 119 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 120 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 120 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 121 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 121 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::GenericTypedef";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 126 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 126 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 127 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 127 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 128 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 128 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 129 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 129 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 130 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 130 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 131 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 131 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 132 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 132 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 133 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 133 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
        #line 134 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 134 "src/analyzer/types/Type.pv"
            return "Type::Global";
        } break;
    }
}

#line 138 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 139 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 140 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 140 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 140 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 141 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 144 "src/analyzer/types/Type.pv"
    return self;
}

#line 147 "src/analyzer/types/Type.pv"
struct Type* Type__deref_reference(struct Type* self) {
    #line 148 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 149 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 149 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 150 "src/analyzer/types/Type.pv"
            if (indirect->type == INDIRECT_TYPE__REFERENCE) {
                #line 151 "src/analyzer/types/Type.pv"
                return &indirect->to;
            }
        } break;
        #line 154 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 157 "src/analyzer/types/Type.pv"
    return self;
}

#line 160 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self) {
    #line 161 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 162 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 162 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 162 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 163 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 166 "src/analyzer/types/Type.pv"
    return self;
}

#line 169 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 170 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 171 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 171 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 171 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 172 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 175 "src/analyzer/types/Type.pv"
    return self;
}

#line 178 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 179 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 180 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 180 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 181 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 182 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 182 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 183 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 184 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 184 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 185 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 185 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 186 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 189 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 192 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 195 "src/analyzer/types/Type.pv"
    return self;
}

#line 198 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 199 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 200 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 200 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 202 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 203 "src/analyzer/types/Type.pv"
    return type;
}

#line 206 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 207 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 208 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 208 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 208 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 209 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 209 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 209 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 210 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 210 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 210 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 211 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 211 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 211 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 212 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 212 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 213 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 216 "src/analyzer/types/Type.pv"
    return 0;
}

#line 219 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 220 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 220 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 222 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 223 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 223 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 223 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 224 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 227 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 228 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 228 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 228 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 229 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 229 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 229 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 230 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 230 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 230 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 231 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 231 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 231 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 232 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 232 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 232 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 232 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 233 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 233 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 233 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 233 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 234 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 234 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 234 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 234 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 235 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 235 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 235 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 236 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 236 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 236 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 237 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 237 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 238 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 238 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 238 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 239 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 239 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 239 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 240 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 240 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 241 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 241 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 241 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 242 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 242 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 242 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 243 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 243 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 243 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 244 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 244 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 244 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 245 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 245 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 245 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 246 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 246 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 246 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 247 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 247 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 247 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 248 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 248 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 248 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 252 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 253 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 254 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 254 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 254 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 255 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 255 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 255 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 256 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 256 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 257 "src/analyzer/types/Type.pv"
        default: {
            #line 257 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 260 "src/analyzer/types/Type.pv"
    return false;
}

#line 263 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 264 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 265 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 265 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 265 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 266 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 266 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 266 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 267 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 267 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        default: {
            #line 268 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 271 "src/analyzer/types/Type.pv"
    return false;
}

#line 274 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 293 "src/analyzer/types/Type.pv"
    return true;
}

#line 296 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 297 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 298 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 298 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 299 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(&primitive_info->name, other->name));
        } break;
        #line 302 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 302 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 303 "src/analyzer/types/Type.pv"
        default: {
            #line 303 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 307 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 308 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 309 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 309 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 309 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 310 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
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
        case TYPE__PRIMITIVE: {
            #line 317 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 317 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 318 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 318 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 319 "src/analyzer/types/Type.pv"
        default: {
            #line 319 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 322 "src/analyzer/types/Type.pv"
    return false;
}

#line 325 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 326 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 327 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 327 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 327 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 328 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 328 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 329 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 329 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 330 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 331 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 331 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 333 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 335 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 336 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 337 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 339 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
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
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 347 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 348 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 348 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 348 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 349 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 349 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 350 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 350 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 351 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 352 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 352 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 354 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 356 "src/analyzer/types/Type.pv"
        default: {
            #line 356 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 359 "src/analyzer/types/Type.pv"
    return false;
}

#line 362 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 363 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 364 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 364 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 364 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&generic->name->value, other_generic->name->value);
        } break;
        #line 365 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 365 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 366 "src/analyzer/types/Type.pv"
        default: {
            #line 366 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 369 "src/analyzer/types/Type.pv"
    return false;
}

#line 372 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 373 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 374 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 374 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 375 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(&gt->typedef_name, other->typedef_name);
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 384 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 385 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 385 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 386 "src/analyzer/types/Type.pv"
        default: {
            #line 386 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 389 "src/analyzer/types/Type.pv"
    return false;
}

#line 392 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 393 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 394 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 394 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 395 "src/analyzer/types/Type.pv"
        default: {
            #line 395 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 398 "src/analyzer/types/Type.pv"
    return false;
}

#line 401 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 402 "src/analyzer/types/Type.pv"
    return true;
}

#line 413 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 414 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 415 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 415 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 415 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 416 "src/analyzer/types/Type.pv"
        default: {
            #line 416 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 419 "src/analyzer/types/Type.pv"
    return false;
}

#line 422 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 423 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 424 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 424 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 424 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&enum_info->name, other_enum->name);
        } break;
        #line 425 "src/analyzer/types/Type.pv"
        default: {
            #line 425 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 428 "src/analyzer/types/Type.pv"
    return false;
}

#line 431 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 432 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 433 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 433 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 433 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&struct_info->name, other_struct->name);
        } break;
        #line 434 "src/analyzer/types/Type.pv"
        default: {
            #line 434 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 437 "src/analyzer/types/Type.pv"
    return false;
}

#line 440 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 441 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 442 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 442 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 442 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&union_info->name, other_union->name);
        } break;
        #line 443 "src/analyzer/types/Type.pv"
        default: {
            #line 443 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 446 "src/analyzer/types/Type.pv"
    return false;
}

#line 449 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 450 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 451 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 451 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 451 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&class_info->name, other_class->name);
        } break;
        #line 452 "src/analyzer/types/Type.pv"
        default: {
            #line 452 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 455 "src/analyzer/types/Type.pv"
    return false;
}

#line 458 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 459 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 460 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 460 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 460 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&namespace_info->name, other_namespace->name);
        } break;
        #line 461 "src/analyzer/types/Type.pv"
        default: {
            #line 461 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 464 "src/analyzer/types/Type.pv"
    return false;
}

#line 467 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 468 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 469 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 469 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 469 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&function->name, other_function->name);
        } break;
        #line 470 "src/analyzer/types/Type.pv"
        default: {
            #line 470 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 473 "src/analyzer/types/Type.pv"
    return false;
}

#line 476 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 483 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 486 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 487 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 487 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 488 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 491 "src/analyzer/types/Type.pv"
    return false;
}

#line 494 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 495 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 496 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 498 "src/analyzer/types/Type.pv"
    return false;
}

#line 501 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 502 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 503 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 503 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 504 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
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
bool Type__is_discriminated_union(struct Type* self) {
    #line 510 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 511 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 511 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 511 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 512 "src/analyzer/types/Type.pv"
        default: {
            #line 512 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 516 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 517 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 518 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 518 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 519 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 519 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 520 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 520 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 521 "src/analyzer/types/Type.pv"
        default: {
            #line 521 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 525 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 526 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 527 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 527 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 528 "src/analyzer/types/Type.pv"
        default: {
            #line 528 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 532 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 533 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 534 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 534 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 534 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER;
        } break;
        #line 535 "src/analyzer/types/Type.pv"
        default: {
            #line 535 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 539 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 540 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 541 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 541 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 542 "src/analyzer/types/Type.pv"
        default: {
            #line 542 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 546 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 547 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 548 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 548 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 549 "src/analyzer/types/Type.pv"
        default: {
            #line 549 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 553 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 554 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 555 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 555 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 556 "src/analyzer/types/Type.pv"
        default: {
            #line 556 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 560 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 561 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 562 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 562 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 562 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 563 "src/analyzer/types/Type.pv"
        default: {
            #line 563 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 567 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 568 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 569 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 569 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 569 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 570 "src/analyzer/types/Type.pv"
        default: {
            #line 570 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 574 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 575 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 576 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 576 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 578 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 579 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 579 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 579 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 580 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 580 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 581 "src/analyzer/types/Type.pv"
        default: {
            #line 581 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 585 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 586 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 587 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 587 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 589 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 590 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 590 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 590 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 591 "src/analyzer/types/Type.pv"
        default: {
            #line 591 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 595 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 596 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 597 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 597 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 598 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 600 "src/analyzer/types/Type.pv"
        default: {
            #line 600 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 604 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 605 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 606 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 608 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 609 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 609 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 610 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 611 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 611 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 613 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 614 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 615 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 615 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 616 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 617 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 617 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 619 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 620 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 620 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 620 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 621 "src/analyzer/types/Type.pv"
                default: {
                    #line 621 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 624 "src/analyzer/types/Type.pv"
        default: {
            #line 624 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 627 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 628 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 629 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 629 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 630 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 631 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 631 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 632 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(&primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 634 "src/analyzer/types/Type.pv"
                    default: {
                        #line 634 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 637 "src/analyzer/types/Type.pv"
            default: {
                #line 637 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 641 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 642 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 642 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 643 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 644 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 644 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 645 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 645 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 645 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 646 "src/analyzer/types/Type.pv"
                default: {
                    #line 646 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 649 "src/analyzer/types/Type.pv"
        default: {
            #line 649 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 652 "src/analyzer/types/Type.pv"
    return false;
}

#line 655 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 656 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 656 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 657 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 660 "src/analyzer/types/Type.pv"
    return false;
}

#line 663 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 664 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 665 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 665 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 666 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 666 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 667 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 667 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 668 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 668 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 669 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 669 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 670 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 670 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 671 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 671 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 672 "src/analyzer/types/Type.pv"
        default: {
            #line 672 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 676 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 677 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 678 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 678 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 679 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 679 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 680 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 680 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 681 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 681 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 682 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 682 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 682 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 683 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 683 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 683 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 684 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 684 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 684 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 685 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 685 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 686 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 686 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 687 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 687 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 687 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 687 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 687 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 688 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 688 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 688 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 689 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 689 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 690 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 690 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 691 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 691 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 692 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 692 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 693 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 693 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 694 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 694 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 695 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 695 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 696 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 696 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 697 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 697 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 697 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 698 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 698 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
