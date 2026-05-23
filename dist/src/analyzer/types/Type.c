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
#include <std/Range_usize.h>
#include <std/str.h>
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
    #line 297 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 298 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 298 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 298 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(&indirect->to, other_tuple);
        } break;
        #line 299 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 299 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 300 "src/analyzer/types/Type.pv"
            if (tuple->elements.length != other_tuple->elements.length) {
                #line 300 "src/analyzer/types/Type.pv"
                return false;
            }

            #line 302 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < tuple->elements.length; i++) {
                #line 303 "src/analyzer/types/Type.pv"
                if (!Type__eq(&tuple->elements.data[i], &other_tuple->elements.data[i])) {
                    #line 303 "src/analyzer/types/Type.pv"
                    return false;
                }
            }

            #line 306 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 308 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 308 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 309 "src/analyzer/types/Type.pv"
        default: {
            #line 309 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 312 "src/analyzer/types/Type.pv"
    return false;
}

#line 315 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 316 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 317 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 317 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 318 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 318 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 319 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(&primitive_info->name, other->name));
        } break;
        #line 322 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 322 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 323 "src/analyzer/types/Type.pv"
        default: {
            #line 323 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 327 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 328 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 329 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 329 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 329 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 330 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 330 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 331 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 331 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 332 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 332 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 333 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 334 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 334 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 336 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 338 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 338 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 339 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 339 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 340 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 342 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 342 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 343 "src/analyzer/types/Type.pv"
        default: {
            #line 343 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 346 "src/analyzer/types/Type.pv"
    return false;
}

#line 349 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 350 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 351 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 351 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 351 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 352 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 352 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 353 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 353 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 354 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 354 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 355 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 356 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 356 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 358 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 360 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 360 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 361 "src/analyzer/types/Type.pv"
            struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });
            #line 362 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_key) != 0;
        } break;
        #line 364 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 364 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 365 "src/analyzer/types/Type.pv"
        default: {
            #line 365 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 368 "src/analyzer/types/Type.pv"
    return false;
}

#line 371 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 372 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 373 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 373 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 373 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 374 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 374 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 375 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 375 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 376 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 376 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 377 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 378 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 378 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 380 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 382 "src/analyzer/types/Type.pv"
        default: {
            #line 382 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 385 "src/analyzer/types/Type.pv"
    return false;
}

#line 388 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 389 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 390 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 390 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 391 "src/analyzer/types/Type.pv"
            if (generic->name == 0) {
                #line 391 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 392 "src/analyzer/types/Type.pv"
            if (other_generic->name == 0) {
                #line 392 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 393 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&generic->name->value, other_generic->name->value);
        } break;
        #line 395 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 395 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 396 "src/analyzer/types/Type.pv"
        default: {
            #line 396 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 399 "src/analyzer/types/Type.pv"
    return false;
}

#line 402 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 403 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 404 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 404 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 405 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(&gt->typedef_name, other->typedef_name);
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 414 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 415 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 415 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 416 "src/analyzer/types/Type.pv"
        default: {
            #line 416 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 419 "src/analyzer/types/Type.pv"
    return false;
}

#line 422 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 423 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 424 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 424 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_self(struct Type* self) {
    #line 432 "src/analyzer/types/Type.pv"
    return true;
}

#line 443 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 444 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 445 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 445 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 445 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 446 "src/analyzer/types/Type.pv"
        default: {
            #line 446 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 449 "src/analyzer/types/Type.pv"
    return false;
}

#line 452 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 453 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 454 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 454 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 454 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&enum_info->name, other_enum->name);
        } break;
        #line 455 "src/analyzer/types/Type.pv"
        default: {
            #line 455 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 458 "src/analyzer/types/Type.pv"
    return false;
}

#line 461 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 462 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 463 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 463 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 463 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&struct_info->name, other_struct->name);
        } break;
        #line 464 "src/analyzer/types/Type.pv"
        default: {
            #line 464 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 467 "src/analyzer/types/Type.pv"
    return false;
}

#line 470 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 471 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 472 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 472 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 472 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&union_info->name, other_union->name);
        } break;
        #line 473 "src/analyzer/types/Type.pv"
        default: {
            #line 473 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 476 "src/analyzer/types/Type.pv"
    return false;
}

#line 479 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 480 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 481 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 481 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 481 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&class_info->name, other_class->name);
        } break;
        #line 482 "src/analyzer/types/Type.pv"
        default: {
            #line 482 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 485 "src/analyzer/types/Type.pv"
    return false;
}

#line 488 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 489 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 490 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 490 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 490 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&namespace_info->name, other_namespace->name);
        } break;
        #line 491 "src/analyzer/types/Type.pv"
        default: {
            #line 491 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 494 "src/analyzer/types/Type.pv"
    return false;
}

#line 497 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 498 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 499 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 499 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 499 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&function->name, other_function->name);
        } break;
        #line 500 "src/analyzer/types/Type.pv"
        default: {
            #line 500 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 503 "src/analyzer/types/Type.pv"
    return false;
}

#line 506 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 513 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 516 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 517 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 517 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 518 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 518 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 519 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 522 "src/analyzer/types/Type.pv"
    return false;
}

#line 525 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 526 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 527 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 529 "src/analyzer/types/Type.pv"
    return false;
}

#line 532 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 533 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 534 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 534 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 535 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 535 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 536 "src/analyzer/types/Type.pv"
        default: {
            #line 536 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 540 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self) {
    #line 541 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 542 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 542 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 542 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 543 "src/analyzer/types/Type.pv"
        default: {
            #line 543 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 547 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 548 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 549 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 549 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 550 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 550 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 551 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 551 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 552 "src/analyzer/types/Type.pv"
        default: {
            #line 552 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 556 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 557 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 558 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 558 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 559 "src/analyzer/types/Type.pv"
        default: {
            #line 559 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 563 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 564 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 565 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 565 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 565 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER;
        } break;
        #line 566 "src/analyzer/types/Type.pv"
        default: {
            #line 566 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 570 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 571 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 572 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 572 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        default: {
            #line 573 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 577 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 578 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 579 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 579 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 580 "src/analyzer/types/Type.pv"
        default: {
            #line 580 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 584 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 585 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 586 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 586 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 587 "src/analyzer/types/Type.pv"
        default: {
            #line 587 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 591 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 592 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 593 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 593 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 593 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 594 "src/analyzer/types/Type.pv"
        default: {
            #line 594 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 598 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 599 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 600 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 600 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 601 "src/analyzer/types/Type.pv"
        default: {
            #line 601 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 605 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 606 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 607 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 607 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 609 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 610 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 610 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 610 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 611 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 612 "src/analyzer/types/Type.pv"
        default: {
            #line 612 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 616 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 617 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 618 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 618 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 620 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 621 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 621 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 622 "src/analyzer/types/Type.pv"
        default: {
            #line 622 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 626 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 627 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 628 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 629 "src/analyzer/types/Type.pv"
            if (trait_info->name == 0) {
                #line 629 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 630 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 632 "src/analyzer/types/Type.pv"
        default: {
            #line 632 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 636 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 637 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 638 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 640 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 641 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 641 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 642 "src/analyzer/types/Type.pv"
            struct Token* struct_name = struct_info->name;
            #line 643 "src/analyzer/types/Type.pv"
            if (struct_name == 0) {
                #line 643 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 644 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 645 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 645 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 647 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 647 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 648 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 649 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 649 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 650 "src/analyzer/types/Type.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 651 "src/analyzer/types/Type.pv"
                    if (struct_name == 0) {
                        #line 651 "src/analyzer/types/Type.pv"
                        return false;
                    }
                    #line 652 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 653 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 653 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 655 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 656 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 656 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 656 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 657 "src/analyzer/types/Type.pv"
                default: {
                    #line 657 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 660 "src/analyzer/types/Type.pv"
        default: {
            #line 660 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 663 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 664 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 665 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 665 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 666 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 667 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 667 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 668 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(&primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 670 "src/analyzer/types/Type.pv"
                    default: {
                        #line 670 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 673 "src/analyzer/types/Type.pv"
            default: {
                #line 673 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 677 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 678 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 678 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 679 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 680 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 680 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 681 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 681 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 681 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 682 "src/analyzer/types/Type.pv"
                default: {
                    #line 682 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 685 "src/analyzer/types/Type.pv"
        default: {
            #line 685 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 688 "src/analyzer/types/Type.pv"
    return false;
}

#line 691 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 692 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 692 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 693 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 693 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 694 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 697 "src/analyzer/types/Type.pv"
    return false;
}

#line 700 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 701 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 702 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 702 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 703 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 703 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 704 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 704 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 705 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 705 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 706 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 706 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 707 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 707 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 708 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 708 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 709 "src/analyzer/types/Type.pv"
        default: {
            #line 709 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 713 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 714 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 715 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 715 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 716 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 716 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 717 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 717 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 718 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 718 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 719 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 719 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 719 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 720 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 720 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 720 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 721 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 721 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 721 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 722 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 722 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 723 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 723 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 724 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 724 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 724 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 724 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 724 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 725 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 725 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 726 "src/analyzer/types/Type.pv"
            if (func_info->context == 0) {
                #line 726 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 727 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 729 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 729 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 730 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 730 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 731 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 731 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 732 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 732 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 733 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 733 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 734 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 734 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 735 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 735 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 736 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 736 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 737 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 737 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 737 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 738 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 738 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
