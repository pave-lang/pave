#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/c/TypedefC.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Context.h>
#include <analyzer/types/Global.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <analyzer/types/Primitive.h>
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
#include <std/trait_Allocator.h>
#include <analyzer/Module.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>

#include <analyzer/types/Type.h>

#line 113 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 114 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 115 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 115 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 116 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 116 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 117 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 117 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 118 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 118 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 119 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 119 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 120 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 120 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 121 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 121 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::GenericTypedef";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 126 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 126 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 127 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 127 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 128 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 128 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 129 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 129 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 130 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 130 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 131 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 131 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 132 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 132 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 133 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 133 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 134 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 134 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
        #line 135 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 135 "src/analyzer/types/Type.pv"
            return "Type::Global";
        } break;
    }
}

#line 139 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 140 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 141 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 141 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 141 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 142 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 145 "src/analyzer/types/Type.pv"
    return self;
}

#line 148 "src/analyzer/types/Type.pv"
uintptr_t Type__get_arity(struct Type* self) {
    #line 149 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 150 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 150 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 150 "src/analyzer/types/Type.pv"
            return struct_info->generic_arity;
        } break;
        #line 151 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 151 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 151 "src/analyzer/types/Type.pv"
            return enum_info->generic_arity;
        } break;
        #line 152 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 152 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 152 "src/analyzer/types/Type.pv"
            return trait_info->generic_arity;
        } break;
        #line 153 "src/analyzer/types/Type.pv"
        default: {
            #line 153 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 157 "src/analyzer/types/Type.pv"
struct Type* Type__deref_reference(struct Type* self) {
    #line 158 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 159 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 159 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 160 "src/analyzer/types/Type.pv"
            if (indirect->type == INDIRECT_TYPE__REFERENCE) {
                #line 161 "src/analyzer/types/Type.pv"
                return &indirect->to;
            }
        } break;
        #line 164 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 167 "src/analyzer/types/Type.pv"
    return self;
}

#line 170 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self) {
    #line 171 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 172 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 172 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 172 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 173 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 176 "src/analyzer/types/Type.pv"
    return self;
}

#line 179 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 180 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 181 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 181 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 181 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 182 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 185 "src/analyzer/types/Type.pv"
    return self;
}

#line 188 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 189 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 190 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 191 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 192 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 192 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 193 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 194 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 194 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 195 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 195 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 196 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 199 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 202 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 205 "src/analyzer/types/Type.pv"
    return self;
}

#line 208 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 209 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 210 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 210 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 212 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 213 "src/analyzer/types/Type.pv"
    return type;
}

#line 216 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 217 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 218 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 218 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 218 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 219 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 219 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 219 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 220 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 220 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 220 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 221 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 221 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 221 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 222 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 223 "src/analyzer/types/Type.pv"
            if (context->type_self == 0) {
                #line 223 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 224 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 229 "src/analyzer/types/Type.pv"
    return 0;
}

#line 232 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 233 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 233 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 235 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 236 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 236 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 236 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 237 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 240 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 241 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 241 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 241 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 242 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 242 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 242 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 243 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 243 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 243 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 244 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 244 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 244 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 245 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 245 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 245 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 246 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 246 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 247 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 249 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 249 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 249 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 250 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 250 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 251 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 253 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 253 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 253 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 254 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 254 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 255 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 257 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 257 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 257 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 258 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 258 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 258 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 259 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 259 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 260 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 260 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 260 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 261 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 261 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 261 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 262 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 262 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 263 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 263 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 263 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 264 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 264 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 264 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 265 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 265 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 265 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 266 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 266 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 266 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 267 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 267 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 267 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 268 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 268 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 269 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 269 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 269 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 270 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 270 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 270 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 274 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 275 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 276 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 276 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 276 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 277 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 277 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 277 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 278 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 278 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 279 "src/analyzer/types/Type.pv"
        default: {
            #line 279 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 282 "src/analyzer/types/Type.pv"
    return false;
}

#line 285 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 286 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 287 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 287 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 287 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 288 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 288 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 288 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 289 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 289 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 290 "src/analyzer/types/Type.pv"
        default: {
            #line 290 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 293 "src/analyzer/types/Type.pv"
    return false;
}

#line 296 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 315 "src/analyzer/types/Type.pv"
    return true;
}

#line 318 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 319 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 320 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 320 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 321 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 321 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 322 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(&primitive_info->name, other->name));
        } break;
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 325 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 326 "src/analyzer/types/Type.pv"
        default: {
            #line 326 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 330 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 331 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 332 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 332 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 332 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 333 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 333 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 334 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 334 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 335 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 335 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 336 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 337 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 337 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 339 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 341 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 341 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 342 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 342 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 343 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 345 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 345 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 346 "src/analyzer/types/Type.pv"
        default: {
            #line 346 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 349 "src/analyzer/types/Type.pv"
    return false;
}

#line 352 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 353 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 354 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 354 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 354 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 355 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 355 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 356 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 356 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 357 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 357 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 358 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 359 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 359 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 361 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 363 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 363 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 364 "src/analyzer/types/Type.pv"
            struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });
            #line 365 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_key) != 0;
        } break;
        #line 367 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 367 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 375 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 376 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 376 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 376 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 377 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 377 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 378 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 378 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 379 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 379 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 380 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 381 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 381 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 383 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 385 "src/analyzer/types/Type.pv"
        default: {
            #line 385 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 388 "src/analyzer/types/Type.pv"
    return false;
}

#line 391 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 392 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 393 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 393 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 394 "src/analyzer/types/Type.pv"
            if (generic->name == 0) {
                #line 394 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 395 "src/analyzer/types/Type.pv"
            if (other_generic->name == 0) {
                #line 395 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 396 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&generic->name->value, other_generic->name->value);
        } break;
        #line 398 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 398 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 406 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 407 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 407 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 408 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(&gt->typedef_name, other->typedef_name);
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 417 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 418 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 418 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 426 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 427 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 427 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_self(struct Type* self) {
    #line 435 "src/analyzer/types/Type.pv"
    return true;
}

#line 446 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 447 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 448 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 448 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 448 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 449 "src/analyzer/types/Type.pv"
        default: {
            #line 449 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 452 "src/analyzer/types/Type.pv"
    return false;
}

#line 455 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 456 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 457 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 457 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 457 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&enum_info->name, other_enum->name);
        } break;
        #line 458 "src/analyzer/types/Type.pv"
        default: {
            #line 458 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 461 "src/analyzer/types/Type.pv"
    return false;
}

#line 464 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 465 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 466 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 466 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 466 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&struct_info->name, other_struct->name);
        } break;
        #line 467 "src/analyzer/types/Type.pv"
        default: {
            #line 467 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 470 "src/analyzer/types/Type.pv"
    return false;
}

#line 473 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 474 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 475 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 475 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 475 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&union_info->name, other_union->name);
        } break;
        #line 476 "src/analyzer/types/Type.pv"
        default: {
            #line 476 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 479 "src/analyzer/types/Type.pv"
    return false;
}

#line 482 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 483 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 484 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 484 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 484 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&class_info->name, other_class->name);
        } break;
        #line 485 "src/analyzer/types/Type.pv"
        default: {
            #line 485 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 488 "src/analyzer/types/Type.pv"
    return false;
}

#line 491 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 492 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 493 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 493 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 493 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&namespace_info->name, other_namespace->name);
        } break;
        #line 494 "src/analyzer/types/Type.pv"
        default: {
            #line 494 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 497 "src/analyzer/types/Type.pv"
    return false;
}

#line 500 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 501 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 502 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 502 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 502 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&function->name, other_function->name);
        } break;
        #line 503 "src/analyzer/types/Type.pv"
        default: {
            #line 503 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 506 "src/analyzer/types/Type.pv"
    return false;
}

#line 509 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 516 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 519 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 520 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 520 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 521 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 521 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 522 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 525 "src/analyzer/types/Type.pv"
    return false;
}

#line 528 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 529 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 530 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 532 "src/analyzer/types/Type.pv"
    return false;
}

#line 535 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 536 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 537 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 537 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 538 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 538 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 539 "src/analyzer/types/Type.pv"
        default: {
            #line 539 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 543 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self) {
    #line 544 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 545 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 545 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 545 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 546 "src/analyzer/types/Type.pv"
        default: {
            #line 546 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 550 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 551 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 552 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 552 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 553 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 553 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 554 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 554 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 555 "src/analyzer/types/Type.pv"
        default: {
            #line 555 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 559 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 560 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 561 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 561 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 562 "src/analyzer/types/Type.pv"
        default: {
            #line 562 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 566 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 567 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 568 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 568 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 568 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER;
        } break;
        #line 569 "src/analyzer/types/Type.pv"
        default: {
            #line 569 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 573 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 574 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 575 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_tuple(struct Type* self) {
    #line 581 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 582 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 582 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 583 "src/analyzer/types/Type.pv"
        default: {
            #line 583 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 587 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 588 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 589 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 589 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 590 "src/analyzer/types/Type.pv"
        default: {
            #line 590 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 594 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 595 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 596 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 596 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 596 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 597 "src/analyzer/types/Type.pv"
        default: {
            #line 597 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 601 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 602 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 603 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 603 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 603 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 604 "src/analyzer/types/Type.pv"
        default: {
            #line 604 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 608 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 609 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 610 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 610 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 612 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 613 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 613 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 613 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 614 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 620 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 621 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 621 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 623 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 624 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 624 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 624 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 625 "src/analyzer/types/Type.pv"
        default: {
            #line 625 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 629 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 630 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 631 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 631 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 632 "src/analyzer/types/Type.pv"
            if (trait_info->name == 0) {
                #line 632 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 633 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 635 "src/analyzer/types/Type.pv"
        default: {
            #line 635 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 639 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 640 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 641 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 643 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 644 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 644 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 645 "src/analyzer/types/Type.pv"
            struct Token* struct_name = struct_info->name;
            #line 646 "src/analyzer/types/Type.pv"
            if (struct_name == 0) {
                #line 646 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 647 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 648 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 648 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 650 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 650 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 651 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 652 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 652 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 653 "src/analyzer/types/Type.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 654 "src/analyzer/types/Type.pv"
                    if (struct_name == 0) {
                        #line 654 "src/analyzer/types/Type.pv"
                        return false;
                    }
                    #line 655 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 656 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 656 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 658 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 659 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 659 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 659 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 660 "src/analyzer/types/Type.pv"
                default: {
                    #line 660 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 663 "src/analyzer/types/Type.pv"
        default: {
            #line 663 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 666 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 667 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 668 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 668 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 669 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 670 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 670 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 671 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(&primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 673 "src/analyzer/types/Type.pv"
                    default: {
                        #line 673 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 676 "src/analyzer/types/Type.pv"
            default: {
                #line 676 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 680 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 681 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 681 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 682 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 683 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 683 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 684 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 684 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 684 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 685 "src/analyzer/types/Type.pv"
                default: {
                    #line 685 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 688 "src/analyzer/types/Type.pv"
        default: {
            #line 688 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 691 "src/analyzer/types/Type.pv"
    return false;
}

#line 694 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 695 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 695 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 696 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 696 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 697 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 700 "src/analyzer/types/Type.pv"
    return false;
}

#line 703 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 704 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 705 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 705 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 706 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 706 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 707 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 707 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 708 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 708 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 709 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 709 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 710 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 710 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 711 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 711 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 712 "src/analyzer/types/Type.pv"
        default: {
            #line 712 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 716 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 717 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 718 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 718 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 719 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 719 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 720 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 720 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 721 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 721 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 722 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 722 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 722 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 723 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 723 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 723 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 724 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 724 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 724 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 725 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 725 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 726 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 726 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 727 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 727 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 727 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 727 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 727 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 728 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 728 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 729 "src/analyzer/types/Type.pv"
            if (func_info->context == 0) {
                #line 729 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 730 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 732 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 732 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 733 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 733 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 734 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 734 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 735 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 735 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 736 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 736 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 737 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 737 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 738 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 738 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 739 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 739 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 740 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 740 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 740 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 741 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 741 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
