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
#include <analyzer/Token.h>
#include <analyzer/types/Generic.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Tuple.h>
#include <std/Iter_ref_Type.h>
#include <analyzer/types/GenericTypedef.h>
#include <analyzer/types/Global.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/types/Function.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/NamespaceCpp.h>
#include <std/Range_usize.h>
#include <std/trait_Allocator.h>
#include <analyzer/Module.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
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
bool Type__contains_generic_name(struct Type* self, struct str name) {
    #line 240 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 241 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 241 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 242 "src/analyzer/types/Type.pv"
            struct Token* generic_name = generic->name;
            #line 243 "src/analyzer/types/Type.pv"
            return generic_name != 0 && str__Eq_str__eq(&generic_name->value, name);
        } break;
        #line 245 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 245 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 246 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&indirect->to, name);
        } break;
        #line 248 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 248 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 249 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&sequence->element, name);
        } break;
        #line 251 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 251 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 252 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
            #line 252 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 252 "src/analyzer/types/Type.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 253 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(element, name)) {
                    #line 253 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 256 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 256 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 257 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 257 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 258 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 258 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 258 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 259 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 259 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 262 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 262 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 263 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 263 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 264 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 264 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 264 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 265 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 265 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 268 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 268 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 269 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 269 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 270 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 270 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 270 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 271 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 271 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 274 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 274 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->function_value._1;
            #line 275 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 275 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 276 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 276 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 276 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 277 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 277 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 280 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 280 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->coroutineinstance_value._1;
            #line 281 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 281 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 282 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 282 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 282 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 283 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 283 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 286 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 286 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 287 "src/analyzer/types/Type.pv"
            struct Token* generic_name = gt->generic->name;
            #line 288 "src/analyzer/types/Type.pv"
            return generic_name != 0 && str__Eq_str__eq(&generic_name->value, name);
        } break;
        #line 290 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 290 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 291 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(info->type, name);
        } break;
        #line 293 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 293 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 294 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&g->type, name);
        } break;
        #line 296 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 299 "src/analyzer/types/Type.pv"
    return false;
}

#line 302 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 303 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 303 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 305 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 306 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 306 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 306 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 307 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 310 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 311 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 311 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 311 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 312 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 312 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 312 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 313 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 313 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 313 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 314 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 314 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 314 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 315 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 315 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 316 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 316 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 317 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 319 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 319 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 319 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 320 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 320 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 321 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 323 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 323 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 323 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 324 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 324 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 325 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 327 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 327 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 327 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 328 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 328 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 328 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 329 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 329 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 330 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 330 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 330 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 331 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 331 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 331 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 332 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 332 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 333 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 333 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 333 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 334 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 334 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 334 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 335 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 335 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 336 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 336 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 336 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 337 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 337 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 337 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 338 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 338 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 338 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 339 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 339 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 339 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 340 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 340 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 340 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 344 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 345 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 346 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 346 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 346 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 347 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 347 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 347 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 348 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 348 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 349 "src/analyzer/types/Type.pv"
        default: {
            #line 349 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 352 "src/analyzer/types/Type.pv"
    return false;
}

#line 355 "src/analyzer/types/Type.pv"
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 356 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 357 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 357 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 357 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 358 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 358 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 358 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 359 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 359 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 360 "src/analyzer/types/Type.pv"
        default: {
            #line 360 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 363 "src/analyzer/types/Type.pv"
    return false;
}

#line 366 "src/analyzer/types/Type.pv"
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 367 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 368 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 368 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 368 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(&indirect->to, other_tuple);
        } break;
        #line 369 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 369 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 370 "src/analyzer/types/Type.pv"
            if (tuple->elements.length != other_tuple->elements.length) {
                #line 370 "src/analyzer/types/Type.pv"
                return false;
            }

            #line 372 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < tuple->elements.length; i++) {
                #line 373 "src/analyzer/types/Type.pv"
                if (!Type__eq(&tuple->elements.data[i], &other_tuple->elements.data[i])) {
                    #line 373 "src/analyzer/types/Type.pv"
                    return false;
                }
            }

            #line 376 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 378 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 378 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 379 "src/analyzer/types/Type.pv"
        default: {
            #line 379 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 382 "src/analyzer/types/Type.pv"
    return false;
}

#line 385 "src/analyzer/types/Type.pv"
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 386 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 387 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 387 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 388 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 388 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 389 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(&primitive_info->name, other->name));
        } break;
        #line 392 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 392 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 393 "src/analyzer/types/Type.pv"
        default: {
            #line 393 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 397 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 398 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 399 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 399 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 399 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 400 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 400 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 401 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 401 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 402 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 402 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 403 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 404 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 404 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 406 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 408 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 408 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 409 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 409 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 410 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 412 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 412 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 413 "src/analyzer/types/Type.pv"
        default: {
            #line 413 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 416 "src/analyzer/types/Type.pv"
    return false;
}

#line 419 "src/analyzer/types/Type.pv"
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 420 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 421 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 421 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 421 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 422 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 422 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 423 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 423 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 424 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 424 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 425 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 426 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 426 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 428 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 430 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 430 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 431 "src/analyzer/types/Type.pv"
            struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });
            #line 432 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_key) != 0;
        } break;
        #line 434 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 434 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 435 "src/analyzer/types/Type.pv"
        default: {
            #line 435 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 438 "src/analyzer/types/Type.pv"
    return false;
}

#line 441 "src/analyzer/types/Type.pv"
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 442 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 443 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 443 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 443 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 444 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 444 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 445 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 445 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 446 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 446 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 447 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i < self_generics->array.length; i++) {
                #line 448 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 448 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 450 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 459 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 460 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 460 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 461 "src/analyzer/types/Type.pv"
            if (generic->name == 0) {
                #line 461 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 462 "src/analyzer/types/Type.pv"
            if (other_generic->name == 0) {
                #line 462 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 463 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&generic->name->value, other_generic->name->value);
        } break;
        #line 465 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 465 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 466 "src/analyzer/types/Type.pv"
        default: {
            #line 466 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 469 "src/analyzer/types/Type.pv"
    return false;
}

#line 472 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 473 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 474 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 474 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 475 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(&gt->typedef_name, other->typedef_name);
        } break;
        #line 477 "src/analyzer/types/Type.pv"
        default: {
            #line 477 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 480 "src/analyzer/types/Type.pv"
    return false;
}

#line 483 "src/analyzer/types/Type.pv"
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 484 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 485 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 485 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 486 "src/analyzer/types/Type.pv"
        default: {
            #line 486 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 489 "src/analyzer/types/Type.pv"
    return false;
}

#line 492 "src/analyzer/types/Type.pv"
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 493 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 494 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 494 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 495 "src/analyzer/types/Type.pv"
        default: {
            #line 495 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 498 "src/analyzer/types/Type.pv"
    return false;
}

#line 501 "src/analyzer/types/Type.pv"
bool Type__eq_self(struct Type* self) {
    #line 502 "src/analyzer/types/Type.pv"
    return true;
}

#line 513 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 514 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 515 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 515 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 515 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 516 "src/analyzer/types/Type.pv"
        default: {
            #line 516 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 519 "src/analyzer/types/Type.pv"
    return false;
}

#line 522 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 523 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 524 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 524 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 524 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&enum_info->name, other_enum->name);
        } break;
        #line 525 "src/analyzer/types/Type.pv"
        default: {
            #line 525 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 528 "src/analyzer/types/Type.pv"
    return false;
}

#line 531 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 532 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 533 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 533 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 533 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&struct_info->name, other_struct->name);
        } break;
        #line 534 "src/analyzer/types/Type.pv"
        default: {
            #line 534 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 537 "src/analyzer/types/Type.pv"
    return false;
}

#line 540 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 541 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 542 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 542 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 542 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&union_info->name, other_union->name);
        } break;
        #line 543 "src/analyzer/types/Type.pv"
        default: {
            #line 543 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 546 "src/analyzer/types/Type.pv"
    return false;
}

#line 549 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 550 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 551 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 551 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 551 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&class_info->name, other_class->name);
        } break;
        #line 552 "src/analyzer/types/Type.pv"
        default: {
            #line 552 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 555 "src/analyzer/types/Type.pv"
    return false;
}

#line 558 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 559 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 560 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 560 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 560 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&namespace_info->name, other_namespace->name);
        } break;
        #line 561 "src/analyzer/types/Type.pv"
        default: {
            #line 561 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 564 "src/analyzer/types/Type.pv"
    return false;
}

#line 567 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 568 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 569 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 569 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 569 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&function->name, other_function->name);
        } break;
        #line 570 "src/analyzer/types/Type.pv"
        default: {
            #line 570 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 573 "src/analyzer/types/Type.pv"
    return false;
}

#line 576 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 583 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 586 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 587 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 587 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 588 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 588 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 589 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 592 "src/analyzer/types/Type.pv"
    return false;
}

#line 595 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 596 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 597 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 599 "src/analyzer/types/Type.pv"
    return false;
}

#line 602 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 603 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 604 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 604 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 605 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 605 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 606 "src/analyzer/types/Type.pv"
        default: {
            #line 606 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 610 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self) {
    #line 611 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 612 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 612 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 612 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 613 "src/analyzer/types/Type.pv"
        default: {
            #line 613 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 617 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 618 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 619 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 619 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 620 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 620 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 621 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 621 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 622 "src/analyzer/types/Type.pv"
        default: {
            #line 622 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 626 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 627 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 628 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 628 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 629 "src/analyzer/types/Type.pv"
        default: {
            #line 629 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 633 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 634 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 635 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 635 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 635 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER || indirect->type == INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER;
        } break;
        #line 636 "src/analyzer/types/Type.pv"
        default: {
            #line 636 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 640 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 641 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 642 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 642 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 643 "src/analyzer/types/Type.pv"
        default: {
            #line 643 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 647 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 648 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 649 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 649 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 650 "src/analyzer/types/Type.pv"
        default: {
            #line 650 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 654 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 655 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 656 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 656 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 657 "src/analyzer/types/Type.pv"
        default: {
            #line 657 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 661 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 662 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 663 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 663 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 663 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 664 "src/analyzer/types/Type.pv"
        default: {
            #line 664 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 668 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 669 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 670 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 670 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 670 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 671 "src/analyzer/types/Type.pv"
        default: {
            #line 671 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 675 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 676 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 677 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 677 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 679 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 680 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 680 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 680 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 681 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 681 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 682 "src/analyzer/types/Type.pv"
        default: {
            #line 682 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 686 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 687 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 688 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 688 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 690 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 691 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 691 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 691 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 692 "src/analyzer/types/Type.pv"
        default: {
            #line 692 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 696 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 697 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 698 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 698 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 699 "src/analyzer/types/Type.pv"
            if (trait_info->name == 0) {
                #line 699 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 700 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(&trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 702 "src/analyzer/types/Type.pv"
        default: {
            #line 702 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 706 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 707 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 708 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 710 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 711 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 711 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 712 "src/analyzer/types/Type.pv"
            struct Token* struct_name = struct_info->name;
            #line 713 "src/analyzer/types/Type.pv"
            if (struct_name == 0) {
                #line 713 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 714 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 715 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 715 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 717 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 717 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 718 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 719 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 719 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 720 "src/analyzer/types/Type.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 721 "src/analyzer/types/Type.pv"
                    if (struct_name == 0) {
                        #line 721 "src/analyzer/types/Type.pv"
                        return false;
                    }
                    #line 722 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(&struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 723 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 723 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 725 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 726 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 726 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 726 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 727 "src/analyzer/types/Type.pv"
                default: {
                    #line 727 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 730 "src/analyzer/types/Type.pv"
        default: {
            #line 730 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 733 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 734 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 735 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 735 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 736 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 737 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 737 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 738 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(&primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 740 "src/analyzer/types/Type.pv"
                    default: {
                        #line 740 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 743 "src/analyzer/types/Type.pv"
            default: {
                #line 743 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 747 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 748 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 748 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 749 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 750 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 750 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 751 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 751 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 751 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 752 "src/analyzer/types/Type.pv"
                default: {
                    #line 752 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 755 "src/analyzer/types/Type.pv"
        default: {
            #line 755 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 758 "src/analyzer/types/Type.pv"
    return false;
}

#line 761 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 762 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 762 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 763 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 763 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 764 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 767 "src/analyzer/types/Type.pv"
    return false;
}

#line 770 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 771 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 772 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 772 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 773 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 773 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 774 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 774 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 775 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 775 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 776 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 776 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 777 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 777 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 778 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 778 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 779 "src/analyzer/types/Type.pv"
        default: {
            #line 779 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 783 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 784 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 785 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 785 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 786 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 786 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 787 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 787 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 788 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 788 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 789 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 789 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 789 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 790 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 790 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 790 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 791 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 791 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 791 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 792 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 792 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 793 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 793 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 794 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 794 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 794 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 794 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 794 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 795 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 795 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 796 "src/analyzer/types/Type.pv"
            if (func_info->context == 0) {
                #line 796 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 797 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 799 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 799 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 800 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 800 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 801 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 801 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 802 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 802 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 803 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 803 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 804 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 804 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 805 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 805 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 806 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 806 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 807 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 807 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 807 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 808 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 808 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
