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

#line 120 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 121 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 122 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 122 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 126 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 126 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 127 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 127 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 128 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 128 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 129 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 129 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 130 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 130 "src/analyzer/types/Type.pv"
            return "Type::GenericTypedef";
        } break;
        #line 131 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 131 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
        } break;
        #line 132 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 132 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 133 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 133 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 134 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 134 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 135 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 135 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 136 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 136 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 137 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 137 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 138 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 138 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 139 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 139 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 140 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 140 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 141 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 141 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
        #line 142 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 142 "src/analyzer/types/Type.pv"
            return "Type::Global";
        } break;
    }
}

#line 146 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 147 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 148 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 148 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 148 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 149 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 152 "src/analyzer/types/Type.pv"
    return self;
}

#line 155 "src/analyzer/types/Type.pv"
uintptr_t Type__get_arity(struct Type* self) {
    #line 156 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 157 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 157 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 157 "src/analyzer/types/Type.pv"
            return struct_info->generic_arity;
        } break;
        #line 158 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 158 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 158 "src/analyzer/types/Type.pv"
            return enum_info->generic_arity;
        } break;
        #line 159 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 159 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 159 "src/analyzer/types/Type.pv"
            return trait_info->generic_arity;
        } break;
        #line 160 "src/analyzer/types/Type.pv"
        default: {
            #line 160 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 164 "src/analyzer/types/Type.pv"
struct Type* Type__deref_reference(struct Type* self) {
    #line 165 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 166 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 166 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 167 "src/analyzer/types/Type.pv"
            if (indirect->type == INDIRECT_TYPE__REFERENCE) {
                #line 168 "src/analyzer/types/Type.pv"
                return &indirect->to;
            }
        } break;
        #line 171 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 174 "src/analyzer/types/Type.pv"
    return self;
}

#line 177 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self) {
    #line 178 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 179 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 179 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 179 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 180 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 183 "src/analyzer/types/Type.pv"
    return self;
}

#line 186 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 187 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 188 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 188 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 188 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 189 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 192 "src/analyzer/types/Type.pv"
    return self;
}

#line 195 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 196 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 197 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 198 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 199 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 199 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 200 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 201 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 201 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 202 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 202 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 203 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 206 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 209 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 212 "src/analyzer/types/Type.pv"
    return self;
}

#line 215 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 216 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 217 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 217 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 219 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 220 "src/analyzer/types/Type.pv"
    return type;
}

#line 223 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 224 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 225 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 225 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 226 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 226 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 227 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 227 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 228 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 228 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 228 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 229 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 230 "src/analyzer/types/Type.pv"
            if (context->type_self == 0) {
                #line 230 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 231 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 233 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 236 "src/analyzer/types/Type.pv"
    return 0;
}

#line 239 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 240 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 240 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 242 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 243 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 243 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 243 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 244 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 247 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 248 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 248 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 248 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 249 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 249 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 249 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 250 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 250 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 250 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 251 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 251 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 251 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 252 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 252 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 252 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 253 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 253 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 254 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 256 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 256 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 256 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 257 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 257 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 258 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 260 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 260 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 260 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 261 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 261 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 262 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 264 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 264 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 264 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 265 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 265 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 265 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 266 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 266 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 267 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 267 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 267 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 268 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 268 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 269 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 269 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 270 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 270 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 270 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 271 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 271 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 271 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 272 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 272 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 272 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 273 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 273 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 273 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 274 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 274 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 274 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 275 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 275 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 275 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 276 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 276 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 276 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 277 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 277 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 277 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 281 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 282 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 283 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 283 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 283 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 284 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 284 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 284 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 285 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 285 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 286 "src/analyzer/types/Type.pv"
        default: {
            #line 286 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 289 "src/analyzer/types/Type.pv"
    return false;
}

#line 292 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 293 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 294 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 294 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 294 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 295 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 295 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 295 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 296 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
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
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 304 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 305 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 305 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 305 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(&indirect->to, other_tuple);
        } break;
        #line 306 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 306 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 307 "src/analyzer/types/Type.pv"
            if (tuple->elements.length != other_tuple->elements.length) {
                #line 307 "src/analyzer/types/Type.pv"
                return false;
            }

            #line 309 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < tuple->elements.length; i++) {
                #line 310 "src/analyzer/types/Type.pv"
                if (!Type__eq(&tuple->elements.data[i], &other_tuple->elements.data[i])) {
                    #line 310 "src/analyzer/types/Type.pv"
                    return false;
                }
            }

            #line 313 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 315 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 323 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 324 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 324 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 325 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 325 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 326 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(&primitive_info->name, other->name));
        } break;
        #line 329 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 329 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 330 "src/analyzer/types/Type.pv"
        default: {
            #line 330 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 334 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 335 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 336 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 336 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 336 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 337 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 337 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 338 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 338 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 339 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 339 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 340 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 341 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 341 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 343 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 345 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 345 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 346 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 346 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 347 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 349 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 349 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 350 "src/analyzer/types/Type.pv"
        default: {
            #line 350 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 353 "src/analyzer/types/Type.pv"
    return false;
}

#line 356 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 357 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 358 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 358 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 358 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 359 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 359 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 360 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 360 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 361 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 361 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 362 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 363 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 363 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 365 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 367 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 367 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 368 "src/analyzer/types/Type.pv"
            struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });
            #line 369 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_key) != 0;
        } break;
        #line 371 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 371 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 372 "src/analyzer/types/Type.pv"
        default: {
            #line 372 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 375 "src/analyzer/types/Type.pv"
    return false;
}

#line 378 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 379 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 380 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 380 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 380 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 381 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 381 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 382 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 382 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 383 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 383 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 384 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 385 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 385 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 387 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 396 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 397 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 397 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 398 "src/analyzer/types/Type.pv"
            if (generic->name == 0) {
                #line 398 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 399 "src/analyzer/types/Type.pv"
            if (other_generic->name == 0) {
                #line 399 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 400 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&generic->name->value, other_generic->name->value);
        } break;
        #line 402 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 402 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 403 "src/analyzer/types/Type.pv"
        default: {
            #line 403 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 406 "src/analyzer/types/Type.pv"
    return false;
}

#line 409 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 410 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 411 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 411 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 412 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(&gt->typedef_name, other->typedef_name);
        } break;
        #line 414 "src/analyzer/types/Type.pv"
        default: {
            #line 414 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 417 "src/analyzer/types/Type.pv"
    return false;
}

#line 420 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 421 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 422 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 422 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 423 "src/analyzer/types/Type.pv"
        default: {
            #line 423 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 426 "src/analyzer/types/Type.pv"
    return false;
}

#line 429 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 430 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 431 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 431 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 432 "src/analyzer/types/Type.pv"
        default: {
            #line 432 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 435 "src/analyzer/types/Type.pv"
    return false;
}

#line 438 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 439 "src/analyzer/types/Type.pv"
    return true;
}

#line 450 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 451 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 452 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 452 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 452 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 453 "src/analyzer/types/Type.pv"
        default: {
            #line 453 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 456 "src/analyzer/types/Type.pv"
    return false;
}

#line 459 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 460 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 461 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 461 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 461 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&enum_info->name, other_enum->name);
        } break;
        #line 462 "src/analyzer/types/Type.pv"
        default: {
            #line 462 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 465 "src/analyzer/types/Type.pv"
    return false;
}

#line 468 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 469 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 470 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 470 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 470 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&struct_info->name, other_struct->name);
        } break;
        #line 471 "src/analyzer/types/Type.pv"
        default: {
            #line 471 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 474 "src/analyzer/types/Type.pv"
    return false;
}

#line 477 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 478 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 479 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 479 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 479 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&union_info->name, other_union->name);
        } break;
        #line 480 "src/analyzer/types/Type.pv"
        default: {
            #line 480 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 483 "src/analyzer/types/Type.pv"
    return false;
}

#line 486 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 487 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 488 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 488 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 488 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&class_info->name, other_class->name);
        } break;
        #line 489 "src/analyzer/types/Type.pv"
        default: {
            #line 489 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 492 "src/analyzer/types/Type.pv"
    return false;
}

#line 495 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 496 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 497 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 497 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 497 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&namespace_info->name, other_namespace->name);
        } break;
        #line 498 "src/analyzer/types/Type.pv"
        default: {
            #line 498 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 501 "src/analyzer/types/Type.pv"
    return false;
}

#line 504 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 505 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 506 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 506 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 506 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&function->name, other_function->name);
        } break;
        #line 507 "src/analyzer/types/Type.pv"
        default: {
            #line 507 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 510 "src/analyzer/types/Type.pv"
    return false;
}

#line 513 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 520 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 523 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 524 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 524 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 525 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 525 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 526 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 529 "src/analyzer/types/Type.pv"
    return false;
}

#line 532 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 533 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 534 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 536 "src/analyzer/types/Type.pv"
    return false;
}

#line 539 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 540 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 541 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 541 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 542 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 542 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 543 "src/analyzer/types/Type.pv"
        default: {
            #line 543 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 547 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self) {
    #line 548 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 549 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 549 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 549 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 550 "src/analyzer/types/Type.pv"
        default: {
            #line 550 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 554 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 555 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 556 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 556 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 557 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 557 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 558 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
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
bool Type__is_indirect(struct Type* self) {
    #line 564 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 565 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 565 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 566 "src/analyzer/types/Type.pv"
        default: {
            #line 566 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 570 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 571 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 572 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 572 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 572 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER || indirect->type == INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER;
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        default: {
            #line 573 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 577 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 578 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 579 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
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
bool Type__is_tuple(struct Type* self) {
    #line 585 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 586 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
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
bool Type__is_sequence(struct Type* self) {
    #line 592 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 593 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 593 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 594 "src/analyzer/types/Type.pv"
        default: {
            #line 594 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 598 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 599 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 600 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 600 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 600 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 601 "src/analyzer/types/Type.pv"
        default: {
            #line 601 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 605 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 606 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 607 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 607 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 607 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 608 "src/analyzer/types/Type.pv"
        default: {
            #line 608 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 612 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 613 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 614 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 614 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 616 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 617 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 617 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 617 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 618 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 619 "src/analyzer/types/Type.pv"
        default: {
            #line 619 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 623 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 624 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 625 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 625 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 627 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 628 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 628 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        default: {
            #line 629 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 633 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 634 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 635 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 635 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 636 "src/analyzer/types/Type.pv"
            if (trait_info->name == 0) {
                #line 636 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 637 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 639 "src/analyzer/types/Type.pv"
        default: {
            #line 639 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 643 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 644 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 645 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 647 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 648 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 648 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 649 "src/analyzer/types/Type.pv"
            struct Token* struct_name = struct_info->name;
            #line 650 "src/analyzer/types/Type.pv"
            if (struct_name == 0) {
                #line 650 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 651 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 652 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 652 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 654 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 654 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 655 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 656 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 656 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 657 "src/analyzer/types/Type.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 658 "src/analyzer/types/Type.pv"
                    if (struct_name == 0) {
                        #line 658 "src/analyzer/types/Type.pv"
                        return false;
                    }
                    #line 659 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 660 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 660 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 662 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 663 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 663 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 663 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 664 "src/analyzer/types/Type.pv"
                default: {
                    #line 664 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 667 "src/analyzer/types/Type.pv"
        default: {
            #line 667 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 670 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 671 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 672 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 672 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 673 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 674 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 674 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 675 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(&primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 677 "src/analyzer/types/Type.pv"
                    default: {
                        #line 677 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 680 "src/analyzer/types/Type.pv"
            default: {
                #line 680 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 684 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 685 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 685 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 686 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 687 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 687 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 688 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 688 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 688 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 689 "src/analyzer/types/Type.pv"
                default: {
                    #line 689 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 692 "src/analyzer/types/Type.pv"
        default: {
            #line 692 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 695 "src/analyzer/types/Type.pv"
    return false;
}

#line 698 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 699 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 699 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 700 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 700 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 701 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 704 "src/analyzer/types/Type.pv"
    return false;
}

#line 707 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 708 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 709 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 709 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 710 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 710 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 711 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 711 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 712 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 712 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 713 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 713 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 714 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 714 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 715 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 715 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 716 "src/analyzer/types/Type.pv"
        default: {
            #line 716 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 720 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 721 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 722 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 722 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 723 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 723 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 724 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 724 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 725 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 725 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 726 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 726 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 726 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 727 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 727 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 727 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 728 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 728 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 728 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 729 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 729 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 730 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 730 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 731 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 731 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 731 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 731 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 731 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 732 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 732 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 733 "src/analyzer/types/Type.pv"
            if (func_info->context == 0) {
                #line 733 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 734 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 736 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 736 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 737 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 737 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 738 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 738 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 739 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 739 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 740 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 740 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 741 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 741 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 742 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 742 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 743 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 743 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 744 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 744 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 744 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 745 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 745 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
