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
#include <analyzer/EnumC.h>
#include <analyzer/ParentCpp.h>
#include <analyzer/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <std/ArenaAllocator.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/TypedefC.h>
#include <analyzer/Indirect.h>
#include <std/Allocator.h>
#include <analyzer/IncludeObjectContext.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/Primitive.h>

#include <analyzer/IncludeContext.h>

#line 340 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type) {
    #line 341 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->types, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 344 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type) {
    #line 345 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 348 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type) {
    #line 349 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(self->include, name);
    #line 350 "src/analyzer/Include.pv"
    func_info->return_type = *return_type;

    #line 352 "src/analyzer/Include.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 353 "src/analyzer/Include.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 356 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 357 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 359 "src/analyzer/Include.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 360 "src/analyzer/Include.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 361 "src/analyzer/Include.pv"
    if (return_type == 0) {
        #line 361 "src/analyzer/Include.pv"
        return_type = &include->root->type_void;
    }

    #line 363 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 366 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 367 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, &self->include->root->type_void);
}

#line 370 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 371 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 372 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 373 "src/analyzer/Include.pv"
    return struct_info;
}

#line 376 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 377 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 378 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 379 "src/analyzer/Include.pv"
    return struct_info;
}

#line 382 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 383 "src/analyzer/Include.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name, self->parent);
    #line 384 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 385 "src/analyzer/Include.pv"
    return enum_info;
}

#line 388 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name) {
    #line 389 "src/analyzer/Include.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .parent = enum_info, .name = (struct str){ .ptr = value_name, .length = strlen(value_name) } });
    #line 390 "src/analyzer/Include.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 393 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 394 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 395 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 397 "src/analyzer/Include.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 398 "src/analyzer/Include.pv"
    if (existing != 0) {
        #line 399 "src/analyzer/Include.pv"
        switch (existing->type) {
            #line 400 "src/analyzer/Include.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 400 "src/analyzer/Include.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 401 "src/analyzer/Include.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
                    .include = include,
                    .parent_context = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                    .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
                });
            } break;
            #line 409 "src/analyzer/Include.pv"
            default: {
            } break;
        }
    }

    #line 413 "src/analyzer/Include.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name, self->parent);
    #line 414 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 416 "src/analyzer/Include.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
        .include = include,
        .parent_context = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
        .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
    });
}

#line 425 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 426 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 428 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 428 "src/analyzer/Include.pv"
        return;
    }

    #line 430 "src/analyzer/Include.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 431 "src/analyzer/Include.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 433 "src/analyzer/Include.pv"
    if (type == 0) {
        #line 434 "src/analyzer/Include.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 435 "src/analyzer/Include.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 436 "src/analyzer/Include.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 438 "src/analyzer/Include.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 440 "src/analyzer/Include.pv"
        clang_disposeString(underlying_name);

        #line 442 "src/analyzer/Include.pv"
        return;
    }

    #line 445 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, name, type) });
}

#line 448 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 449 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 450 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 451 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 453 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 454 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 455 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 458 "src/analyzer/Include.pv"
    return struct_info;
}

#line 461 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 462 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 463 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 464 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 466 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 467 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 468 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 471 "src/analyzer/Include.pv"
    return struct_info;
}

#line 474 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 475 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 476 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 477 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 479 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 480 "src/analyzer/Include.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 481 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 482 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 485 "src/analyzer/Include.pv"
    return struct_info;
}

#line 488 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 489 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 490 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(include, name);
    #line 491 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 492 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 494 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 495 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 496 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 499 "src/analyzer/Include.pv"
    return func_info;
}

#line 502 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 503 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 505 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 505 "src/analyzer/Include.pv"
        return;
    }

    #line 507 "src/analyzer/Include.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 508 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 509 "src/analyzer/Include.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 511 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 514 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 515 "src/analyzer/Include.pv"
    struct IncludeContext* self = client_data;
    #line 516 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 518 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 519 "src/analyzer/Include.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 521 "src/analyzer/Include.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 522 "src/analyzer/Include.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 523 "src/analyzer/Include.pv"
    clang_disposeString(cursor_spelling);

    #line 525 "src/analyzer/Include.pv"
    if (kind == CXCursor_Namespace) {
        #line 526 "src/analyzer/Include.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 527 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 528 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 530 "src/analyzer/Include.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 531 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 533 "src/analyzer/Include.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 534 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, &(struct IncludeObjectContext) { .context = self, .object = enum_info });
        #line 535 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if ((kind == CXCursor_StructDecl) || (kind == CXCursor_ClassDecl)) {
        #line 537 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 538 "src/analyzer/Include.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 539 "src/analyzer/Include.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 540 "src/analyzer/Include.pv"
        clang_disposeString(type_spelling);

        #line 543 "src/analyzer/Include.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 544 "src/analyzer/Include.pv"
            struct ClassCpp* class_info = 0;
            #line 545 "src/analyzer/Include.pv"
            struct Type* class_type = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });

            #line 547 "src/analyzer/Include.pv"
            if (class_type != 0) {
                #line 548 "src/analyzer/Include.pv"
                switch (class_type->type) {
                    #line 549 "src/analyzer/Include.pv"
                    case TYPE__CLASS_CPP: {
                        #line 549 "src/analyzer/Include.pv"
                        struct ClassCpp* class_info2 = class_type->classcpp_value;
                        #line 550 "src/analyzer/Include.pv"
                        class_info = class_info2;
                    } break;
                    #line 552 "src/analyzer/Include.pv"
                    default: {
                    } break;
                }
            }

            #line 556 "src/analyzer/Include.pv"
            if (class_info == 0) {
                #line 557 "src/analyzer/Include.pv"
                class_info = ClassCpp__new(include, name, self->parent, kind == CXCursor_StructDecl);
                #line 558 "src/analyzer/Include.pv"
                IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
            }

            #line 561 "src/analyzer/Include.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            });

            #line 566 "src/analyzer/Include.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 568 "src/analyzer/Include.pv"
            if (strncmp(type_name, "struct ", 7) == 0) {
                #line 569 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 571 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });

                #line 576 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 579 "src/analyzer/Include.pv"
            if (strncmp(type_name, "union ", 7) == 0) {
                #line 580 "src/analyzer/Include.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 582 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                });

                #line 587 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 591 "src/analyzer/Include.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 592 "src/analyzer/Include.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 593 "src/analyzer/Include.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 594 "src/analyzer/Include.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);

        #line 596 "src/analyzer/Include.pv"
        if ((canonical_kind == CXCursor_StructDecl) || (canonical_kind == CXCursor_ClassDecl)) {
            #line 597 "src/analyzer/Include.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 599 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            });
            #line 603 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 605 "src/analyzer/Include.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 607 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            });
            #line 611 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 613 "src/analyzer/Include.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 614 "src/analyzer/Include.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 615 "src/analyzer/Include.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 617 "src/analyzer/Include.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 618 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 620 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 622 "src/analyzer/Include.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 627 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 634 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else {
            #line 643 "src/analyzer/Include.pv"
            IncludeContext__add_typedef(self, name, cursor);
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 646 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 647 "src/analyzer/Include.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 648 "src/analyzer/Include.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 650 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 652 "src/analyzer/Include.pv"
        if (HashMap_str_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 652 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        }

        #line 654 "src/analyzer/Include.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 655 "src/analyzer/Include.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 657 "src/analyzer/Include.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = include->root->primitive_void });
        }

        #line 660 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    }

    #line 663 "src/analyzer/Include.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 665 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
