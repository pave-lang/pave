#include <stdint.h>
#include <string.h>

#include <stdio.h>

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
#include <analyzer/expression/Expression.h>
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

#line 121 "src/analyzer/types/Type.pv"
char const* Type__name(struct Type* self) {
    #line 122 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 123 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 123 "src/analyzer/types/Type.pv"
            return "Type::Primitive";
        } break;
        #line 124 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 124 "src/analyzer/types/Type.pv"
            return "Type::Indirect";
        } break;
        #line 125 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 125 "src/analyzer/types/Type.pv"
            return "Type::Sequence";
        } break;
        #line 126 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 126 "src/analyzer/types/Type.pv"
            return "Type::Tuple";
        } break;
        #line 127 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 127 "src/analyzer/types/Type.pv"
            return "Type::Enum";
        } break;
        #line 128 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 128 "src/analyzer/types/Type.pv"
            return "Type::Struct";
        } break;
        #line 129 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 129 "src/analyzer/types/Type.pv"
            return "Type::Trait";
        } break;
        #line 130 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 130 "src/analyzer/types/Type.pv"
            return "Type::Generic";
        } break;
        #line 131 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 131 "src/analyzer/types/Type.pv"
            return "Type::GenericTypedef";
        } break;
        #line 132 "src/analyzer/types/Type.pv"
        case TYPE__CONST: {
            #line 132 "src/analyzer/types/Type.pv"
            return "Type::Const";
        } break;
        #line 133 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 133 "src/analyzer/types/Type.pv"
            return "Type::UnknownC";
        } break;
        #line 134 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 134 "src/analyzer/types/Type.pv"
            return "Type::Function";
        } break;
        #line 135 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 135 "src/analyzer/types/Type.pv"
            return "Type::CoroutineInstance";
        } break;
        #line 136 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 136 "src/analyzer/types/Type.pv"
            return "Type::Self";
        } break;
        #line 137 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 137 "src/analyzer/types/Type.pv"
            return "Type::TypedefC";
        } break;
        #line 138 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 138 "src/analyzer/types/Type.pv"
            return "Type::EnumC";
        } break;
        #line 139 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 139 "src/analyzer/types/Type.pv"
            return "Type::StructC";
        } break;
        #line 140 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 140 "src/analyzer/types/Type.pv"
            return "Type::UnionC";
        } break;
        #line 141 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 141 "src/analyzer/types/Type.pv"
            return "Type::FunctionC";
        } break;
        #line 142 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 142 "src/analyzer/types/Type.pv"
            return "Type::ClassCpp";
        } break;
        #line 143 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 143 "src/analyzer/types/Type.pv"
            return "Type::NamespaceCpp";
        } break;
        #line 144 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 144 "src/analyzer/types/Type.pv"
            return "Type::Global";
        } break;
    }
}

#line 148 "src/analyzer/types/Type.pv"
struct Type* Type__deref(struct Type* self) {
    #line 149 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 150 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 150 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 150 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 151 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 154 "src/analyzer/types/Type.pv"
    return self;
}

#line 157 "src/analyzer/types/Type.pv"
uintptr_t Type__get_arity(struct Type* self) {
    #line 158 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 159 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 159 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 159 "src/analyzer/types/Type.pv"
            return struct_info->generic_arity;
        } break;
        #line 160 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 160 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 160 "src/analyzer/types/Type.pv"
            return enum_info->generic_arity;
        } break;
        #line 161 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 161 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 161 "src/analyzer/types/Type.pv"
            return trait_info->generic_arity;
        } break;
        #line 162 "src/analyzer/types/Type.pv"
        default: {
            #line 162 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 166 "src/analyzer/types/Type.pv"
struct Type* Type__deref_reference(struct Type* self) {
    #line 167 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 168 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 168 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 169 "src/analyzer/types/Type.pv"
            if (indirect->type == INDIRECT_TYPE__REFERENCE) {
                #line 170 "src/analyzer/types/Type.pv"
                return &indirect->to;
            }
        } break;
        #line 173 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 176 "src/analyzer/types/Type.pv"
    return self;
}

#line 179 "src/analyzer/types/Type.pv"
struct Type* Type__deref_all(struct Type* self) {
    #line 180 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 181 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 181 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 181 "src/analyzer/types/Type.pv"
            return Type__deref_all(&indirect->to);
        } break;
        #line 182 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 185 "src/analyzer/types/Type.pv"
    return self;
}

#line 188 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef(struct Type* self) {
    #line 189 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 190 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 190 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 190 "src/analyzer/types/Type.pv"
            return Type__resolve_typedef(info->type);
        } break;
        #line 191 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 194 "src/analyzer/types/Type.pv"
    return self;
}

#line 197 "src/analyzer/types/Type.pv"
struct Type* Type__resolve_typedef_function(struct Type* self) {
    #line 198 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 199 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 199 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 200 "src/analyzer/types/Type.pv"
            switch (info->type->type) {
                #line 201 "src/analyzer/types/Type.pv"
                case TYPE__INDIRECT: {
                    #line 201 "src/analyzer/types/Type.pv"
                    struct Indirect* indirect = info->type->indirect_value;
                    #line 202 "src/analyzer/types/Type.pv"
                    switch (indirect->to.type) {
                        #line 203 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION: {
                            #line 203 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 204 "src/analyzer/types/Type.pv"
                        case TYPE__FUNCTION_C: {
                            #line 204 "src/analyzer/types/Type.pv"
                            return &indirect->to;
                        } break;
                        #line 205 "src/analyzer/types/Type.pv"
                        default: {
                        } break;
                    }
                } break;
                #line 208 "src/analyzer/types/Type.pv"
                default: {
                } break;
            }
        } break;
        #line 211 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 214 "src/analyzer/types/Type.pv"
    return self;
}

#line 217 "src/analyzer/types/Type.pv"
struct Type* Type__to_ptr(struct Type* self, struct ArenaAllocator* allocator) {
    #line 218 "src/analyzer/types/Type.pv"
    struct Type* type = ArenaAllocator__Allocator__alloc(allocator, sizeof(struct Type));
    #line 219 "src/analyzer/types/Type.pv"
    if (type == 0) {
        #line 219 "src/analyzer/types/Type.pv"
        return 0;
    }

    #line 221 "src/analyzer/types/Type.pv"
    *type = *self;
    #line 222 "src/analyzer/types/Type.pv"
    return type;
}

#line 225 "src/analyzer/types/Type.pv"
struct GenericMap* Type__get_generic_map(struct Type* self, struct Context* context) {
    #line 226 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 227 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 227 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 227 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 228 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 228 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 228 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 229 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 229 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 229 "src/analyzer/types/Type.pv"
            return generics;
        } break;
        #line 230 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 230 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 230 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(&indirect->to, context);
        } break;
        #line 231 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 232 "src/analyzer/types/Type.pv"
            if (context->type_self == 0) {
                #line 232 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 233 "src/analyzer/types/Type.pv"
            return Type__get_generic_map(context->type_self, context);
        } break;
        #line 235 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 238 "src/analyzer/types/Type.pv"
    return 0;
}

#line 241 "src/analyzer/types/Type.pv"
bool Type__contains_generic_name(struct Type* self, struct str name) {
    #line 242 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 243 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 243 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 244 "src/analyzer/types/Type.pv"
            struct Token* generic_name = generic->name;
            #line 245 "src/analyzer/types/Type.pv"
            return generic_name != 0 && str__Eq_str__eq(generic_name->value, name);
        } break;
        #line 247 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 247 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 248 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&indirect->to, name);
        } break;
        #line 250 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 250 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 251 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&sequence->element, name);
        } break;
        #line 253 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 253 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 254 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
            #line 254 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 254 "src/analyzer/types/Type.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 255 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(element, name)) {
                    #line 255 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 258 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 258 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->enum_value._1;
            #line 259 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 259 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 260 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 260 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 260 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 261 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 261 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 264 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 264 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->struct_value._1;
            #line 265 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 265 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 266 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 266 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 266 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 267 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 267 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 270 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 270 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->trait_value._1;
            #line 271 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 271 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 272 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 272 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 272 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 273 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 273 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 276 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 276 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->function_value._1;
            #line 277 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 277 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 278 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 278 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 278 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 279 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 279 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 282 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 282 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = self->coroutineinstance_value._1;
            #line 283 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 283 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 284 "src/analyzer/types/Type.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&generics->array);
            #line 284 "src/analyzer/types/Type.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 284 "src/analyzer/types/Type.pv"
                struct Type* generic_type = Iter_ref_Type__value(&__iter);

                #line 285 "src/analyzer/types/Type.pv"
                if (Type__contains_generic_name(generic_type, name)) {
                    #line 285 "src/analyzer/types/Type.pv"
                    return true;
                }
            } }
        } break;
        #line 288 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 288 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 289 "src/analyzer/types/Type.pv"
            struct Token* generic_name = gt->generic->name;
            #line 290 "src/analyzer/types/Type.pv"
            return generic_name != 0 && str__Eq_str__eq(generic_name->value, name);
        } break;
        #line 292 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 292 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 293 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(info->type, name);
        } break;
        #line 295 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 295 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 296 "src/analyzer/types/Type.pv"
            return Type__contains_generic_name(&g->type, name);
        } break;
        #line 298 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 301 "src/analyzer/types/Type.pv"
    return false;
}

#line 304 "src/analyzer/types/Type.pv"
bool Type__eq(struct Type* self, struct Type* other) {
    #line 305 "src/analyzer/types/Type.pv"
    if (Type__is_unknown(self)) {
        #line 305 "src/analyzer/types/Type.pv"
        return true;
    }

    #line 307 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 308 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 308 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 308 "src/analyzer/types/Type.pv"
            return Type__eq(&g->type, other);
        } break;
        #line 309 "src/analyzer/types/Type.pv"
        default: {
        } break;
    }

    #line 312 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 313 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 313 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 313 "src/analyzer/types/Type.pv"
            return Type__eq_indirect(self, indirect);
        } break;
        #line 314 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 314 "src/analyzer/types/Type.pv"
            struct Sequence* seq_info = other->sequence_value;
            #line 314 "src/analyzer/types/Type.pv"
            return Type__eq_sequence(self, seq_info);
        } break;
        #line 315 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 315 "src/analyzer/types/Type.pv"
            struct Tuple* tuple_info = other->tuple_value;
            #line 315 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(self, tuple_info);
        } break;
        #line 316 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 316 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = other->primitive_value;
            #line 316 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(self, primitive_info);
        } break;
        #line 317 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 317 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = other->enum_value._0;
            #line 317 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->enum_value._1;
            #line 318 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 318 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 319 "src/analyzer/types/Type.pv"
            return Type__eq_enum(self, enum_info, generics->array);
        } break;
        #line 321 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 321 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = other->struct_value._0;
            #line 321 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->struct_value._1;
            #line 322 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 322 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 323 "src/analyzer/types/Type.pv"
            return Type__eq_struct(self, struct_info, generics->array);
        } break;
        #line 325 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 325 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = other->trait_value._0;
            #line 325 "src/analyzer/types/Type.pv"
            struct GenericMap* generics = other->trait_value._1;
            #line 326 "src/analyzer/types/Type.pv"
            if (generics == 0) {
                #line 326 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 327 "src/analyzer/types/Type.pv"
            return Type__eq_trait(self, trait_info, generics->array);
        } break;
        #line 329 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 329 "src/analyzer/types/Type.pv"
            struct Generic* generic = other->generic_value;
            #line 329 "src/analyzer/types/Type.pv"
            return Type__eq_generic(self, generic);
        } break;
        #line 330 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 330 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = other->generictypedef_value;
            #line 330 "src/analyzer/types/Type.pv"
            return Type__eq_generic_typedef(self, gt);
        } break;
        #line 331 "src/analyzer/types/Type.pv"
        case TYPE__CONST: {
            #line 331 "src/analyzer/types/Type.pv"
            struct Expression* expression = other->const_value;
            #line 331 "src/analyzer/types/Type.pv"
            return Type__eq_const(self, expression);
        } break;
        #line 332 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 332 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 333 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 333 "src/analyzer/types/Type.pv"
            struct Function* function = other->function_value._0;
            #line 333 "src/analyzer/types/Type.pv"
            return Type__eq_function(self, function);
        } break;
        #line 334 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 334 "src/analyzer/types/Type.pv"
            struct Function* function = other->coroutineinstance_value._0;
            #line 334 "src/analyzer/types/Type.pv"
            return Type__eq_coroutine_instance(self, function);
        } break;
        #line 335 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 335 "src/analyzer/types/Type.pv"
            return Type__eq_self(self);
        } break;
        #line 336 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 336 "src/analyzer/types/Type.pv"
            struct TypedefC* info = other->typedefc_value;
            #line 336 "src/analyzer/types/Type.pv"
            return Type__eq_typedef_c(self, info);
        } break;
        #line 337 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 337 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = other->enumc_value;
            #line 337 "src/analyzer/types/Type.pv"
            return Type__eq_enum_c(self, enum_info);
        } break;
        #line 338 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 338 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = other->structc_value;
            #line 338 "src/analyzer/types/Type.pv"
            return Type__eq_struct_c(self, struct_info);
        } break;
        #line 339 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 339 "src/analyzer/types/Type.pv"
            struct StructC* union_info = other->unionc_value;
            #line 339 "src/analyzer/types/Type.pv"
            return Type__eq_union_c(self, union_info);
        } break;
        #line 340 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 340 "src/analyzer/types/Type.pv"
            struct FunctionC* function = other->functionc_value;
            #line 340 "src/analyzer/types/Type.pv"
            return Type__eq_function_c(self, function);
        } break;
        #line 341 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 341 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = other->classcpp_value;
            #line 341 "src/analyzer/types/Type.pv"
            return Type__eq_class_cpp(self, class_info);
        } break;
        #line 342 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 342 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = other->namespacecpp_value;
            #line 342 "src/analyzer/types/Type.pv"
            return Type__eq_namespace_cpp(self, namespace_info);
        } break;
        #line 343 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 343 "src/analyzer/types/Type.pv"
            struct Global* g = other->global_value;
            #line 343 "src/analyzer/types/Type.pv"
            return Type__eq(self, &g->type);
        } break;
    }
}

#line 347 "src/analyzer/types/Type.pv"
bool Type__eq_indirect(struct Type* self, struct Indirect* other) {
    #line 348 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 349 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 349 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 349 "src/analyzer/types/Type.pv"
            return Type__is_void(&indirect->to) || Type__is_void(&other->to) || Type__eq(&indirect->to, &other->to);
        } break;
        #line 350 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 350 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 350 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other->to);
        } break;
        #line 351 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
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
bool Type__eq_sequence(struct Type* self, struct Sequence* other_seq) {
    #line 359 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 360 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 360 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 360 "src/analyzer/types/Type.pv"
            return Type__eq(&indirect->to, &other_seq->element);
        } break;
        #line 361 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 361 "src/analyzer/types/Type.pv"
            struct Sequence* seq = self->sequence_value;
            #line 361 "src/analyzer/types/Type.pv"
            return Type__eq(&seq->element, &other_seq->element);
        } break;
        #line 362 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 362 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_tuple(struct Type* self, struct Tuple* other_tuple) {
    #line 370 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 371 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 371 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 371 "src/analyzer/types/Type.pv"
            return Type__eq_tuple(&indirect->to, other_tuple);
        } break;
        #line 372 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 372 "src/analyzer/types/Type.pv"
            struct Tuple* tuple = self->tuple_value;
            #line 373 "src/analyzer/types/Type.pv"
            if (tuple->elements.length != other_tuple->elements.length) {
                #line 373 "src/analyzer/types/Type.pv"
                return false;
            }

            #line 375 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i != tuple->elements.length; i < tuple->elements.length ? i++ : i--) {
                #line 376 "src/analyzer/types/Type.pv"
                if (!Type__eq(&tuple->elements.data[i], &other_tuple->elements.data[i])) {
                    #line 376 "src/analyzer/types/Type.pv"
                    return false;
                }
            }

            #line 379 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 381 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 381 "src/analyzer/types/Type.pv"
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
bool Type__eq_primitive(struct Type* self, struct Primitive* other) {
    #line 389 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 390 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 390 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 391 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 391 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 392 "src/analyzer/types/Type.pv"
            return (Primitive__is_void(primitive_info) && Primitive__is_void(other)) || (Primitive__is_number(primitive_info) && Primitive__is_number(other)) || (primitive_info && other && str__Eq_str__eq(primitive_info->name, other->name));
        } break;
        #line 395 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 395 "src/analyzer/types/Type.pv"
            return Type__eq_primitive(Type__resolve_typedef(self), other);
        } break;
        #line 396 "src/analyzer/types/Type.pv"
        default: {
            #line 396 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 400 "src/analyzer/types/Type.pv"
bool Type__eq_enum(struct Type* self, struct Enum* other_enum, struct Array_Type generics) {
    #line 401 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 402 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 402 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 402 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->enum_value._1;
            #line 403 "src/analyzer/types/Type.pv"
            if (enum_info != other_enum) {
                #line 403 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 404 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 404 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 405 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 405 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 406 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i != self_generics->array.length; i < self_generics->array.length ? i++ : i--) {
                #line 407 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 407 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 409 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 411 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 411 "src/analyzer/types/Type.pv"
            struct Primitive* primitive_info = self->primitive_value;
            #line 412 "src/analyzer/types/Type.pv"
            if (primitive_info == 0) {
                #line 412 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 413 "src/analyzer/types/Type.pv"
            return Primitive__is_void(primitive_info);
        } break;
        #line 415 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
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
bool Type__eq_struct(struct Type* self, struct Struct* other_struct, struct Array_Type generics) {
    #line 423 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 424 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 424 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 424 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->struct_value._1;
            #line 425 "src/analyzer/types/Type.pv"
            if (struct_info != other_struct) {
                #line 425 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 426 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 426 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 427 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 427 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 428 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i != self_generics->array.length; i < self_generics->array.length ? i++ : i--) {
                #line 429 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 429 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 431 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 433 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 433 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 434 "src/analyzer/types/Type.pv"
            struct str trait_key = Trait__get_key(trait_info, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = trait_info->module->context.allocator });
            #line 435 "src/analyzer/types/Type.pv"
            return HashMap_str_tuple_ref_Trait_ref_Type__find(&other_struct->traits, &trait_key) != 0;
        } break;
        #line 437 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 437 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_trait(struct Type* self, struct Trait* other_trait, struct Array_Type generics) {
    #line 445 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 446 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 446 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 446 "src/analyzer/types/Type.pv"
            struct GenericMap* self_generics = self->trait_value._1;
            #line 447 "src/analyzer/types/Type.pv"
            if (trait_info != other_trait) {
                #line 447 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 448 "src/analyzer/types/Type.pv"
            if (self_generics == 0) {
                #line 448 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 449 "src/analyzer/types/Type.pv"
            if (self_generics->array.length != generics.length) {
                #line 449 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 450 "src/analyzer/types/Type.pv"
            for (uintptr_t i = 0; i != self_generics->array.length; i < self_generics->array.length ? i++ : i--) {
                #line 451 "src/analyzer/types/Type.pv"
                if (!Type__eq(&self_generics->array.data[i], &generics.data[i])) {
                    #line 451 "src/analyzer/types/Type.pv"
                    return false;
                }
            }
            #line 453 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_generic(struct Type* self, struct Generic* other_generic) {
    #line 462 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 463 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 463 "src/analyzer/types/Type.pv"
            struct Generic* generic = self->generic_value;
            #line 464 "src/analyzer/types/Type.pv"
            if (generic->name == 0) {
                #line 464 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 465 "src/analyzer/types/Type.pv"
            if (other_generic->name == 0) {
                #line 465 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 466 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(generic->name->value, other_generic->name->value);
        } break;
        #line 468 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 468 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 469 "src/analyzer/types/Type.pv"
        default: {
            #line 469 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 472 "src/analyzer/types/Type.pv"
    return false;
}

#line 475 "src/analyzer/types/Type.pv"
bool Type__eq_generic_typedef(struct Type* self, struct GenericTypedef* other) {
    #line 476 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 477 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 477 "src/analyzer/types/Type.pv"
            struct GenericTypedef* gt = self->generictypedef_value;
            #line 478 "src/analyzer/types/Type.pv"
            return gt->generic == other->generic && str__Eq_str__eq(gt->typedef_name, other->typedef_name);
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
bool Type__eq_const(struct Type* self, struct Expression* other) {
    #line 487 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 488 "src/analyzer/types/Type.pv"
        case TYPE__CONST: {
            #line 488 "src/analyzer/types/Type.pv"
            struct Expression* expression = self->const_value;
            #line 488 "src/analyzer/types/Type.pv"
            return Expression__eq_const_value(expression, other);
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
bool Type__eq_function(struct Type* self, struct Function* other) {
    #line 496 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 497 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 497 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_coroutine_instance(struct Type* self, struct Function* other) {
    #line 505 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 506 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 506 "src/analyzer/types/Type.pv"
            return true;
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
bool Type__eq_self(struct Type* self) {
    #line 514 "src/analyzer/types/Type.pv"
    return true;
}

#line 525 "src/analyzer/types/Type.pv"
bool Type__eq_typedef_c(struct Type* self, struct TypedefC* other) {
    #line 526 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 527 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 527 "src/analyzer/types/Type.pv"
            struct TypedefC* info = self->typedefc_value;
            #line 527 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(info->name, other->name) || Type__eq(Type__resolve_typedef(info->type), Type__resolve_typedef(other->type));
        } break;
        #line 528 "src/analyzer/types/Type.pv"
        default: {
            #line 528 "src/analyzer/types/Type.pv"
            return Type__eq(self, other->type);
        } break;
    }

    #line 531 "src/analyzer/types/Type.pv"
    return false;
}

#line 534 "src/analyzer/types/Type.pv"
bool Type__eq_enum_c(struct Type* self, struct EnumC* other_enum) {
    #line 535 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 536 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 536 "src/analyzer/types/Type.pv"
            struct EnumC* enum_info = self->enumc_value;
            #line 536 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(enum_info->name, other_enum->name);
        } break;
        #line 537 "src/analyzer/types/Type.pv"
        default: {
            #line 537 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 540 "src/analyzer/types/Type.pv"
    return false;
}

#line 543 "src/analyzer/types/Type.pv"
bool Type__eq_struct_c(struct Type* self, struct StructC* other_struct) {
    #line 544 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 545 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 545 "src/analyzer/types/Type.pv"
            struct StructC* struct_info = self->structc_value;
            #line 545 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(struct_info->name, other_struct->name);
        } break;
        #line 546 "src/analyzer/types/Type.pv"
        default: {
            #line 546 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 549 "src/analyzer/types/Type.pv"
    return false;
}

#line 552 "src/analyzer/types/Type.pv"
bool Type__eq_union_c(struct Type* self, struct StructC* other_union) {
    #line 553 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 554 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 554 "src/analyzer/types/Type.pv"
            struct StructC* union_info = self->unionc_value;
            #line 554 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(union_info->name, other_union->name);
        } break;
        #line 555 "src/analyzer/types/Type.pv"
        default: {
            #line 555 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 558 "src/analyzer/types/Type.pv"
    return false;
}

#line 561 "src/analyzer/types/Type.pv"
bool Type__eq_class_cpp(struct Type* self, struct ClassCpp* other_class) {
    #line 562 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 563 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 563 "src/analyzer/types/Type.pv"
            struct ClassCpp* class_info = self->classcpp_value;
            #line 563 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(class_info->name, other_class->name);
        } break;
        #line 564 "src/analyzer/types/Type.pv"
        default: {
            #line 564 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 567 "src/analyzer/types/Type.pv"
    return false;
}

#line 570 "src/analyzer/types/Type.pv"
bool Type__eq_namespace_cpp(struct Type* self, struct NamespaceCpp* other_namespace) {
    #line 571 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 572 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 572 "src/analyzer/types/Type.pv"
            struct NamespaceCpp* namespace_info = self->namespacecpp_value;
            #line 572 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(namespace_info->name, other_namespace->name);
        } break;
        #line 573 "src/analyzer/types/Type.pv"
        default: {
            #line 573 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 576 "src/analyzer/types/Type.pv"
    return false;
}

#line 579 "src/analyzer/types/Type.pv"
bool Type__eq_function_c(struct Type* self, struct FunctionC* other_function) {
    #line 580 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 581 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 581 "src/analyzer/types/Type.pv"
            struct FunctionC* function = self->functionc_value;
            #line 581 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(function->name, other_function->name);
        } break;
        #line 582 "src/analyzer/types/Type.pv"
        default: {
            #line 582 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 585 "src/analyzer/types/Type.pv"
    return false;
}

#line 588 "src/analyzer/types/Type.pv"
bool Type__is_self(struct Type* self) {
    #line 595 "src/analyzer/types/Type.pv"
    return ((struct Type) { .type = TYPE__SELF }).type == ((*self)).type;
}

#line 598 "src/analyzer/types/Type.pv"
bool Type__is_void(struct Type* self) {
    #line 599 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 599 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 600 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 600 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 601 "src/analyzer/types/Type.pv"
        return Primitive__is_void(primitive_info);
    }

    #line 604 "src/analyzer/types/Type.pv"
    return false;
}

#line 607 "src/analyzer/types/Type.pv"
bool Type__is_unknown(struct Type* self) {
    #line 608 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__UNKNOWN_C) {
        #line 609 "src/analyzer/types/Type.pv"
        return true;
    }
    #line 611 "src/analyzer/types/Type.pv"
    return false;
}

#line 614 "src/analyzer/types/Type.pv"
bool Type__is_enum(struct Type* self) {
    #line 615 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 616 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 616 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 617 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 617 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 618 "src/analyzer/types/Type.pv"
        default: {
            #line 618 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 622 "src/analyzer/types/Type.pv"
bool Type__is_discriminated_union(struct Type* self) {
    #line 623 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 624 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 624 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 624 "src/analyzer/types/Type.pv"
            return Enum__is_discriminated_union(enum_info);
        } break;
        #line 625 "src/analyzer/types/Type.pv"
        default: {
            #line 625 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 629 "src/analyzer/types/Type.pv"
bool Type__is_function(struct Type* self) {
    #line 630 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 631 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 631 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 632 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 632 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 633 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 633 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 634 "src/analyzer/types/Type.pv"
        default: {
            #line 634 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 638 "src/analyzer/types/Type.pv"
bool Type__is_indirect(struct Type* self) {
    #line 639 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 640 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 640 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 641 "src/analyzer/types/Type.pv"
        default: {
            #line 641 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 645 "src/analyzer/types/Type.pv"
bool Type__is_pointer(struct Type* self) {
    #line 646 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 647 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 647 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 647 "src/analyzer/types/Type.pv"
            return indirect->type == INDIRECT_TYPE__POINTER || indirect->type == INDIRECT_TYPE__CONST_POINTER || indirect->type == INDIRECT_TYPE__DYNAMIC_DISPATCH_POINTER;
        } break;
        #line 648 "src/analyzer/types/Type.pv"
        default: {
            #line 648 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 652 "src/analyzer/types/Type.pv"
bool Type__is_trait(struct Type* self) {
    #line 653 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 654 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 654 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 655 "src/analyzer/types/Type.pv"
        default: {
            #line 655 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 659 "src/analyzer/types/Type.pv"
bool Type__is_tuple(struct Type* self) {
    #line 660 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 661 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 661 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 662 "src/analyzer/types/Type.pv"
        default: {
            #line 662 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 666 "src/analyzer/types/Type.pv"
bool Type__is_sequence(struct Type* self) {
    #line 667 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 668 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 668 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 669 "src/analyzer/types/Type.pv"
        default: {
            #line 669 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 673 "src/analyzer/types/Type.pv"
bool Type__is_sequence_fixed_array(struct Type* self) {
    #line 674 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 675 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 675 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = self->sequence_value;
            #line 675 "src/analyzer/types/Type.pv"
            return Sequence__is_fixed_array(sequence);
        } break;
        #line 676 "src/analyzer/types/Type.pv"
        default: {
            #line 676 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 680 "src/analyzer/types/Type.pv"
struct Type* Type__deref_1(struct Type* self) {
    #line 681 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 682 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 682 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 682 "src/analyzer/types/Type.pv"
            return &indirect->to;
        } break;
        #line 683 "src/analyzer/types/Type.pv"
        default: {
            #line 683 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}

#line 687 "src/analyzer/types/Type.pv"
bool Type__is_fat_pointer(struct Type* self) {
    #line 688 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 689 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 689 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 691 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 692 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 692 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 692 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 693 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 693 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 694 "src/analyzer/types/Type.pv"
        default: {
            #line 694 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 698 "src/analyzer/types/Type.pv"
bool Type__is_reference_sequence_dynamic(struct Type* self) {
    #line 699 "src/analyzer/types/Type.pv"
    struct Type* referenced_type = Type__deref_1(self);
    #line 700 "src/analyzer/types/Type.pv"
    if (referenced_type == 0) {
        #line 700 "src/analyzer/types/Type.pv"
        return false;
    }

    #line 702 "src/analyzer/types/Type.pv"
    switch (referenced_type->type) {
        #line 703 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 703 "src/analyzer/types/Type.pv"
            struct Sequence* sequence = referenced_type->sequence_value;
            #line 703 "src/analyzer/types/Type.pv"
            return Sequence__is_slice(sequence);
        } break;
        #line 704 "src/analyzer/types/Type.pv"
        default: {
            #line 704 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 708 "src/analyzer/types/Type.pv"
bool Type__is_iterator(struct Type* self) {
    #line 709 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 710 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 710 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 711 "src/analyzer/types/Type.pv"
            if (trait_info->name == 0) {
                #line 711 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 712 "src/analyzer/types/Type.pv"
            return str__Eq_str__eq(trait_info->name->value, (struct str){ .ptr = "Iter", .length = strlen("Iter") });
        } break;
        #line 714 "src/analyzer/types/Type.pv"
        default: {
            #line 714 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 718 "src/analyzer/types/Type.pv"
bool Type__needs_implicit_cast(struct Type* self, struct Type* other) {
    #line 719 "src/analyzer/types/Type.pv"
    bool sequence_is_slice = false;
    #line 720 "src/analyzer/types/Type.pv"
    bool str_cast = false;

    #line 722 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 723 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 723 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 724 "src/analyzer/types/Type.pv"
            struct Token* struct_name = struct_info->name;
            #line 725 "src/analyzer/types/Type.pv"
            if (struct_name == 0) {
                #line 725 "src/analyzer/types/Type.pv"
                return false;
            }
            #line 726 "src/analyzer/types/Type.pv"
            str_cast = str__Eq_str__eq(struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
            #line 727 "src/analyzer/types/Type.pv"
            if (!str_cast) {
                #line 727 "src/analyzer/types/Type.pv"
                return false;
            }
        } break;
        #line 729 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 729 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = self->indirect_value;
            #line 730 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 731 "src/analyzer/types/Type.pv"
                case TYPE__STRUCT: {
                    #line 731 "src/analyzer/types/Type.pv"
                    struct Struct* struct_info = indirect->to.struct_value._0;
                    #line 732 "src/analyzer/types/Type.pv"
                    struct Token* struct_name = struct_info->name;
                    #line 733 "src/analyzer/types/Type.pv"
                    if (struct_name == 0) {
                        #line 733 "src/analyzer/types/Type.pv"
                        return false;
                    }
                    #line 734 "src/analyzer/types/Type.pv"
                    str_cast = str__Eq_str__eq(struct_name->value, (struct str){ .ptr = "str", .length = strlen("str") });
                    #line 735 "src/analyzer/types/Type.pv"
                    if (!str_cast) {
                        #line 735 "src/analyzer/types/Type.pv"
                        return false;
                    }
                } break;
                #line 737 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                } break;
                #line 738 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 738 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 738 "src/analyzer/types/Type.pv"
                    sequence_is_slice = Sequence__is_slice(sequence);
                } break;
                #line 739 "src/analyzer/types/Type.pv"
                default: {
                    #line 739 "src/analyzer/types/Type.pv"
                    return false;
                } break;
            }
        } break;
        #line 742 "src/analyzer/types/Type.pv"
        default: {
            #line 742 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 745 "src/analyzer/types/Type.pv"
    if (str_cast) {
        #line 746 "src/analyzer/types/Type.pv"
        switch (other->type) {
            #line 747 "src/analyzer/types/Type.pv"
            case TYPE__INDIRECT: {
                #line 747 "src/analyzer/types/Type.pv"
                struct Indirect* indirect = other->indirect_value;
                #line 748 "src/analyzer/types/Type.pv"
                switch (indirect->to.type) {
                    #line 749 "src/analyzer/types/Type.pv"
                    case TYPE__PRIMITIVE: {
                        #line 749 "src/analyzer/types/Type.pv"
                        struct Primitive* primitive = indirect->to.primitive_value;
                        #line 750 "src/analyzer/types/Type.pv"
                        return primitive != 0 && str__Eq_str__eq(primitive->name, (struct str){ .ptr = "char", .length = strlen("char") });
                    } break;
                    #line 752 "src/analyzer/types/Type.pv"
                    default: {
                        #line 752 "src/analyzer/types/Type.pv"
                        return false;
                    } break;
                }
            } break;
            #line 755 "src/analyzer/types/Type.pv"
            default: {
                #line 755 "src/analyzer/types/Type.pv"
                return false;
            } break;
        }
    }

    #line 759 "src/analyzer/types/Type.pv"
    switch (other->type) {
        #line 760 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 760 "src/analyzer/types/Type.pv"
            struct Indirect* indirect = other->indirect_value;
            #line 761 "src/analyzer/types/Type.pv"
            switch (indirect->to.type) {
                #line 762 "src/analyzer/types/Type.pv"
                case TYPE__TRAIT: {
                    #line 762 "src/analyzer/types/Type.pv"
                    return false;
                } break;
                #line 763 "src/analyzer/types/Type.pv"
                case TYPE__SEQUENCE: {
                    #line 763 "src/analyzer/types/Type.pv"
                    struct Sequence* sequence = indirect->to.sequence_value;
                    #line 763 "src/analyzer/types/Type.pv"
                    return !Sequence__is_slice(sequence) && sequence_is_slice;
                } break;
                #line 764 "src/analyzer/types/Type.pv"
                default: {
                    #line 764 "src/analyzer/types/Type.pv"
                    return true;
                } break;
            }
        } break;
        #line 767 "src/analyzer/types/Type.pv"
        default: {
            #line 767 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }

    #line 770 "src/analyzer/types/Type.pv"
    return false;
}

#line 773 "src/analyzer/types/Type.pv"
bool Type__is_number(struct Type* self) {
    #line 774 "src/analyzer/types/Type.pv"
    if (self->type == TYPE__PRIMITIVE) {
        #line 774 "src/analyzer/types/Type.pv"
        struct Primitive* primitive_info = self->primitive_value;
        #line 775 "src/analyzer/types/Type.pv"
        if (primitive_info == 0) {
            #line 775 "src/analyzer/types/Type.pv"
            return false;
        }
        #line 776 "src/analyzer/types/Type.pv"
        return Primitive__is_number(primitive_info);
    }

    #line 779 "src/analyzer/types/Type.pv"
    return false;
}

#line 782 "src/analyzer/types/Type.pv"
bool Type__is_primitive_or_c_type(struct Type* self) {
    #line 783 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 784 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 784 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 785 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 785 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 786 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 786 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 787 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 787 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 788 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 788 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 789 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 789 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 790 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 790 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 791 "src/analyzer/types/Type.pv"
        default: {
            #line 791 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 795 "src/analyzer/types/Type.pv"
struct Module* Type__get_module(struct Type* self) {
    #line 796 "src/analyzer/types/Type.pv"
    switch (self->type) {
        #line 797 "src/analyzer/types/Type.pv"
        case TYPE__PRIMITIVE: {
            #line 797 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 798 "src/analyzer/types/Type.pv"
        case TYPE__INDIRECT: {
            #line 798 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 799 "src/analyzer/types/Type.pv"
        case TYPE__SEQUENCE: {
            #line 799 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 800 "src/analyzer/types/Type.pv"
        case TYPE__TUPLE: {
            #line 800 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 801 "src/analyzer/types/Type.pv"
        case TYPE__ENUM: {
            #line 801 "src/analyzer/types/Type.pv"
            struct Enum* enum_info = self->enum_value._0;
            #line 801 "src/analyzer/types/Type.pv"
            return enum_info->context->module;
        } break;
        #line 802 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT: {
            #line 802 "src/analyzer/types/Type.pv"
            struct Struct* struct_info = self->struct_value._0;
            #line 802 "src/analyzer/types/Type.pv"
            return struct_info->module;
        } break;
        #line 803 "src/analyzer/types/Type.pv"
        case TYPE__TRAIT: {
            #line 803 "src/analyzer/types/Type.pv"
            struct Trait* trait_info = self->trait_value._0;
            #line 803 "src/analyzer/types/Type.pv"
            return trait_info->module;
        } break;
        #line 804 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC: {
            #line 804 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 805 "src/analyzer/types/Type.pv"
        case TYPE__UNKNOWN_C: {
            #line 805 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 806 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION: {
            #line 806 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->function_value._0;
            #line 806 "src/analyzer/types/Type.pv"
            if (func_info->context != 0) {
                #line 806 "src/analyzer/types/Type.pv"
                return func_info->context->module;
            } else {
                #line 806 "src/analyzer/types/Type.pv"
                return 0;
            }
        } break;
        #line 807 "src/analyzer/types/Type.pv"
        case TYPE__COROUTINE_INSTANCE: {
            #line 807 "src/analyzer/types/Type.pv"
            struct Function* func_info = self->coroutineinstance_value._0;
            #line 808 "src/analyzer/types/Type.pv"
            if (func_info->context == 0) {
                #line 808 "src/analyzer/types/Type.pv"
                return 0;
            }
            #line 809 "src/analyzer/types/Type.pv"
            return func_info->context->module;
        } break;
        #line 811 "src/analyzer/types/Type.pv"
        case TYPE__SELF: {
            #line 811 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 812 "src/analyzer/types/Type.pv"
        case TYPE__TYPEDEF_C: {
            #line 812 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 813 "src/analyzer/types/Type.pv"
        case TYPE__ENUM_C: {
            #line 813 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 814 "src/analyzer/types/Type.pv"
        case TYPE__STRUCT_C: {
            #line 814 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 815 "src/analyzer/types/Type.pv"
        case TYPE__UNION_C: {
            #line 815 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 816 "src/analyzer/types/Type.pv"
        case TYPE__FUNCTION_C: {
            #line 816 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 817 "src/analyzer/types/Type.pv"
        case TYPE__CLASS_CPP: {
            #line 817 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 818 "src/analyzer/types/Type.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 818 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 819 "src/analyzer/types/Type.pv"
        case TYPE__GLOBAL: {
            #line 819 "src/analyzer/types/Type.pv"
            struct Global* g = self->global_value;
            #line 819 "src/analyzer/types/Type.pv"
            return g->module;
        } break;
        #line 820 "src/analyzer/types/Type.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 820 "src/analyzer/types/Type.pv"
            return 0;
        } break;
        #line 821 "src/analyzer/types/Type.pv"
        case TYPE__CONST: {
            #line 821 "src/analyzer/types/Type.pv"
            return 0;
        } break;
    }
}
