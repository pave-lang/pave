#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Type.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <stdbool.h>
#include <analyzer/FunctionC.h>
#include <analyzer/Include.h>
#include <analyzer/Root.h>
#include <stdint.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/StructC.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/EnumC.h>
#include <analyzer/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <std/ArenaAllocator.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/TypedefC.h>
#include <analyzer/Indirect.h>
#include <std/Allocator.h>
#include <analyzer/IncludeObjectContext.h>
#include <analyzer/Primitive.h>

#include <analyzer/IncludeContext.h>

#line 297 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type) {
    #line 298 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->types, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 301 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type) {
    #line 302 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 305 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type) {
    #line 306 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(self->include, name);
    #line 307 "src/analyzer/Include.pv"
    func_info->return_type = *return_type;

    #line 309 "src/analyzer/Include.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 310 "src/analyzer/Include.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 313 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 314 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 316 "src/analyzer/Include.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 317 "src/analyzer/Include.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 318 "src/analyzer/Include.pv"
    if (return_type == 0) {
        #line 318 "src/analyzer/Include.pv"
        return_type = &include->root->type_void;
    }

    #line 320 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 323 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 324 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, &self->include->root->type_void);
}

#line 327 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 328 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 329 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 330 "src/analyzer/Include.pv"
    return struct_info;
}

#line 333 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 334 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 335 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 336 "src/analyzer/Include.pv"
    return struct_info;
}

#line 339 "src/analyzer/Include.pv"
struct ClassCpp* IncludeContext__add_class(struct IncludeContext* self, char const* name, bool is_struct) {
    #line 340 "src/analyzer/Include.pv"
    struct ClassCpp* class_info = ClassCpp__new(self->include, name, is_struct);
    #line 341 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
    #line 342 "src/analyzer/Include.pv"
    return class_info;
}

#line 345 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 346 "src/analyzer/Include.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name);
    #line 347 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 348 "src/analyzer/Include.pv"
    return enum_info;
}

#line 351 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name) {
    #line 352 "src/analyzer/Include.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .name = (struct str){ .ptr = value_name, .length = strlen(value_name) } });
    #line 353 "src/analyzer/Include.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 356 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 357 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 358 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;
    #line 361 "src/analyzer/Include.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 362 "src/analyzer/Include.pv"
    if (existing != 0) {
        #line 363 "src/analyzer/Include.pv"
        switch (existing->type) {
            #line 364 "src/analyzer/Include.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 364 "src/analyzer/Include.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 365 "src/analyzer/Include.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
                    .include = include,
                    .parent = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                });
            } break;
            #line 372 "src/analyzer/Include.pv"
            default: {
            } break;
        }
    }

    #line 376 "src/analyzer/Include.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name);
    #line 377 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 379 "src/analyzer/Include.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
        .include = include,
        .parent = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
    });
}

#line 387 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 388 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 390 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 390 "src/analyzer/Include.pv"
        return;
    }

    #line 392 "src/analyzer/Include.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 393 "src/analyzer/Include.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 395 "src/analyzer/Include.pv"
    if (type == 0) {
        #line 396 "src/analyzer/Include.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 397 "src/analyzer/Include.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 398 "src/analyzer/Include.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 400 "src/analyzer/Include.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 402 "src/analyzer/Include.pv"
        clang_disposeString(underlying_name);

        #line 404 "src/analyzer/Include.pv"
        return;
    }

    #line 407 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, name, type) });
}

#line 410 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 411 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 412 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 413 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 415 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 416 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 417 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 420 "src/analyzer/Include.pv"
    return struct_info;
}

#line 423 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 424 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 425 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 426 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 428 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 429 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 430 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 433 "src/analyzer/Include.pv"
    return struct_info;
}

#line 436 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 437 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 438 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 439 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 441 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 442 "src/analyzer/Include.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 443 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 444 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 447 "src/analyzer/Include.pv"
    return struct_info;
}

#line 450 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 451 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 452 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(include, name);
    #line 453 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 454 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 456 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 457 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 458 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 461 "src/analyzer/Include.pv"
    return func_info;
}

#line 464 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 465 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 467 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 467 "src/analyzer/Include.pv"
        return;
    }

    #line 469 "src/analyzer/Include.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 470 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 471 "src/analyzer/Include.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 473 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 476 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 477 "src/analyzer/Include.pv"
    struct IncludeContext* self = client_data;
    #line 478 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 480 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 481 "src/analyzer/Include.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 483 "src/analyzer/Include.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 484 "src/analyzer/Include.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 485 "src/analyzer/Include.pv"
    clang_disposeString(cursor_spelling);

    #line 487 "src/analyzer/Include.pv"
    if (kind == CXCursor_Namespace) {
        #line 488 "src/analyzer/Include.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 489 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 490 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 492 "src/analyzer/Include.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 493 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 495 "src/analyzer/Include.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 496 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, &(struct IncludeObjectContext) { .context = self, .object = enum_info });
        #line 497 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_StructDecl || kind == CXCursor_ClassDecl) {
        #line 499 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 500 "src/analyzer/Include.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 501 "src/analyzer/Include.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 502 "src/analyzer/Include.pv"
        clang_disposeString(type_spelling);

        #line 505 "src/analyzer/Include.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 506 "src/analyzer/Include.pv"
            struct ClassCpp* class_info = IncludeContext__add_class(self, name, kind == CXCursor_StructDecl);

            #line 508 "src/analyzer/Include.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            });

            #line 513 "src/analyzer/Include.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 515 "src/analyzer/Include.pv"
            if (strncmp(type_name, "struct ", 7) == 0) {
                #line 516 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 518 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });

                #line 523 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 526 "src/analyzer/Include.pv"
            if (strncmp(type_name, "union ", 7) == 0) {
                #line 527 "src/analyzer/Include.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 529 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                });

                #line 534 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 538 "src/analyzer/Include.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 539 "src/analyzer/Include.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 540 "src/analyzer/Include.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 541 "src/analyzer/Include.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);

        #line 543 "src/analyzer/Include.pv"
        if (canonical_kind == CXCursor_StructDecl || canonical_kind == CXCursor_ClassDecl) {
            #line 544 "src/analyzer/Include.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 546 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            });
            #line 550 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 552 "src/analyzer/Include.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 554 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            });
            #line 558 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 560 "src/analyzer/Include.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 561 "src/analyzer/Include.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 562 "src/analyzer/Include.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 564 "src/analyzer/Include.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 565 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 567 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 569 "src/analyzer/Include.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 574 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 581 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else {
            #line 590 "src/analyzer/Include.pv"
            IncludeContext__add_typedef(self, name, cursor);
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 593 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 594 "src/analyzer/Include.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 595 "src/analyzer/Include.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 597 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 599 "src/analyzer/Include.pv"
        if (HashMap_str_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 599 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        }

        #line 601 "src/analyzer/Include.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 602 "src/analyzer/Include.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 604 "src/analyzer/Include.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = include->root->primitive_void });
        }

        #line 607 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    }

    #line 610 "src/analyzer/Include.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 612 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
