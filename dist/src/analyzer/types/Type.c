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
struct Type* Type__deref_all(struct Type* self) {
    #line 148 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 149 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 149 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 149 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 150 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 153 "src/analyzer/types/Type.pv"
    return self;
}

#line 156 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 157 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 158 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 158 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 158 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 159 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 162 "src/analyzer/types/Type.pv"
    return self;
}

#line 165 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 166 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 167 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 167 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 168 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 169 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 169 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 170 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 171 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 171 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 172 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 172 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 173 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 176 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 179 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 182 "src/analyzer/types/Type.pv"
    return self;
}

#line 185 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 186 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 187 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 187 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 189 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 190 "src/analyzer/types/Type.pv"
    return type;
}

#line 193 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 194 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 195 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 195 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 195 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 196 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 196 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 196 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 197 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 197 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 197 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 198 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 198 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 198 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 199 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 200 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 203 "src/analyzer/types/Type.pv"
    return 0;
}

#line 206 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 207 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 207 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 209 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 210 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 210 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 210 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 211 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 214 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 215 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 215 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 215 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 216 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 216 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 216 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 217 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 217 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 217 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 218 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 218 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 218 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 219 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 219 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 219 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 219 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 220 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 220 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 220 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 220 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 221 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 221 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 221 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 221 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 222 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 222 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 222 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 223 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 223 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 223 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 224 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 224 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 225 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 225 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 225 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 226 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 226 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 226 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 227 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 228 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 228 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 228 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 229 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 229 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 229 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 230 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 230 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 230 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 231 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 231 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 231 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 232 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 232 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 232 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 233 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 233 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 233 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 234 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 234 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 234 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 235 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 235 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 235 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 239 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 240 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 241 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 241 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 241 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 242 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 242 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 242 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 243 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 243 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 244 "src/analyzer/types/Type.pv"
        default: {
            #line 244 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 247 "src/analyzer/types/Type.pv"
    return false;
}

#line 250 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 251 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 252 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 252 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 252 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 253 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 253 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 253 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 254 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 254 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 255 "src/analyzer/types/Type.pv"
        default: {
            #line 255 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 258 "src/analyzer/types/Type.pv"
    return false;
}

#line 261 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 280 "src/analyzer/types/Type.pv"
    return true;
}

#line 283 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 284 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 285 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 285 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 286 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__eq(primitive_info->name, other->name));
        } break;
        #line 288 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 288 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 289 "src/analyzer/types/Type.pv"
        default: {
            #line 289 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 293 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 294 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 295 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 295 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 295 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 296 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 296 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 297 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 297 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 298 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 299 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 299 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 301 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 312 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 313 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 313 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 313 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 314 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 314 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 315 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 315 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 316 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 317 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 317 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 319 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 321 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 321 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 322 "src/analyzer/types/Type.pv"
            struct Token* trait_name = trait_info->name;
            #line 323 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_name->value) != 0;
        } break;
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
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
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 333 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 334 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 334 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 334 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 335 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 335 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 336 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 336 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 337 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 338 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 338 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 340 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 342 "src/analyzer/types/Type.pv"
        default: {
            #line 342 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 345 "src/analyzer/types/Type.pv"
    return false;
}

#line 348 "src/analyzer/types/Type.pv"
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 349 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 350 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 350 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 350 "src/analyzer/types/Type.pv"
            return str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 351 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 351 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 352 "src/analyzer/types/Type.pv"
        default: {
            #line 352 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 355 "src/analyzer/types/Type.pv"
    return false;
}

#line 358 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 359 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 360 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 360 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 361 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__eq(gt->typedef_name, other->typedef_name);
        } break;
        #line 363 "src/analyzer/types/Type.pv"
        default: {
            #line 363 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 366 "src/analyzer/types/Type.pv"
    return false;
}

#line 369 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 370 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 371 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 379 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 380 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 380 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 381 "src/analyzer/types/Type.pv"
        default: {
            #line 381 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 384 "src/analyzer/types/Type.pv"
    return false;
}

#line 387 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 388 "src/analyzer/types/Type.pv"
    return true;
}

#line 399 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 400 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 401 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 401 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 401 "src/analyzer/types/Type.pv"
            return str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 402 "src/analyzer/types/Type.pv"
        default: {
            #line 402 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 405 "src/analyzer/types/Type.pv"
    return false;
}

#line 408 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 409 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 410 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 410 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 410 "src/analyzer/types/Type.pv"
            return str__eq(enum_info->name, other_enum->name);
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
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 418 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 419 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 419 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 419 "src/analyzer/types/Type.pv"
            return str__eq(struct_info->name, other_struct->name);
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
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 427 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 428 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 428 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 428 "src/analyzer/types/Type.pv"
            return str__eq(union_info->name, other_union->name);
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
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 436 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 437 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 437 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 437 "src/analyzer/types/Type.pv"
            return str__eq(class_info->name, other_class->name);
        } break;
        #line 438 "src/analyzer/types/Type.pv"
        default: {
            #line 438 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 441 "src/analyzer/types/Type.pv"
    return false;
}

#line 444 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 445 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 446 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 446 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 446 "src/analyzer/types/Type.pv"
            return str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 447 "src/analyzer/types/Type.pv"
        default: {
            #line 447 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 450 "src/analyzer/types/Type.pv"
    return false;
}

#line 453 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 454 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 455 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 455 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 455 "src/analyzer/types/Type.pv"
            return str__eq(function->name, other_function->name);
        } break;
        #line 456 "src/analyzer/types/Type.pv"
        default: {
            #line 456 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 459 "src/analyzer/types/Type.pv"
    return false;
}

#line 462 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 463 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 464 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
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
bool Type__is_void(struct Type* self) {
    #line 470 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 470 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 471 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 474 "src/analyzer/types/Type.pv"
    return false;
}

#line 477 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 478 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 479 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 479 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 480 "src/analyzer/types/Type.pv"
        default: {
            #line 480 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 484 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 485 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 486 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 486 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 487 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 487 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 488 "src/analyzer/types/Type.pv"
        default: {
            #line 488 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 492 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 493 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 494 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 494 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 495 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 495 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 496 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
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
bool Type__is_indirect(struct Type* self) {
    #line 502 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 503 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 503 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 504 "src/analyzer/types/Type.pv"
        default: {
            #line 504 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 508 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 509 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 510 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 510 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 511 "src/analyzer/types/Type.pv"
        default: {
            #line 511 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 515 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 516 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 517 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 517 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 518 "src/analyzer/types/Type.pv"
        default: {
            #line 518 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 522 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 523 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 524 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 524 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 525 "src/analyzer/types/Type.pv"
        default: {
            #line 525 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 529 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 530 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 531 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 531 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 531 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 532 "src/analyzer/types/Type.pv"
        default: {
            #line 532 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 536 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 537 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 538 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 538 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 538 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 539 "src/analyzer/types/Type.pv"
        default: {
            #line 539 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 543 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 544 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 545 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 545 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 547 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 548 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 548 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 548 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 549 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 549 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 550 "src/analyzer/types/Type.pv"
        default: {
            #line 550 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 554 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 555 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 556 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 556 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 558 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 559 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 559 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 559 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 560 "src/analyzer/types/Type.pv"
        default: {
            #line 560 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 564 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 565 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 566 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 566 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 567 "src/analyzer/types/Type.pv"
            return str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 569 "src/analyzer/types/Type.pv"
        default: {
            #line 569 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 573 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 574 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 575 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 577 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 578 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 578 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 579 "src/analyzer/types/Type.pv"
            str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 580 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 580 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 582 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 582 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 583 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 584 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 584 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 585 "src/analyzer/types/Type.pv"
                    str_cast = str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 586 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 586 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 588 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 589 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 589 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 589 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 590 "src/analyzer/types/Type.pv"
                default: {
                    #line 590 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 593 "src/analyzer/types/Type.pv"
        default: {
            #line 593 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 596 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 597 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 598 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 598 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 599 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 600 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 600 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 601 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 603 "src/analyzer/types/Type.pv"
                    default: {
                        #line 603 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 606 "src/analyzer/types/Type.pv"
            default: {
                #line 606 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 610 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 611 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 611 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 612 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 613 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 613 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 614 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 614 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 614 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 615 "src/analyzer/types/Type.pv"
                default: {
                    #line 615 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        default: {
            #line 618 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 621 "src/analyzer/types/Type.pv"
    return false;
}

#line 624 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 625 "src/analyzer/types/Type.pv"
    if (self == 0) {
        #line 625 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 627 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 628 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 629 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 630 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 630 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 631 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 631 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 632 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 632 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 633 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 633 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 634 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 634 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 635 "src/analyzer/types/Type.pv"
        default: {
            #line 635 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 639 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 640 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 641 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 641 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 642 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 642 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 643 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 643 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 644 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 644 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 645 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 645 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 645 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 646 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 646 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 646 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 647 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 647 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 647 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 648 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 648 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 649 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 649 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 650 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 650 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 650 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 650 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 650 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 651 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 651 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 651 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 652 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 652 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 653 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 653 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 654 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 654 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 655 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 655 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 656 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 656 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 657 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 657 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 658 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 658 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 659 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 659 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 660 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 660 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 660 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
    }
}
