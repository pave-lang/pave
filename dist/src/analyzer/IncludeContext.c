#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/types/Type.h>
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
#include <analyzer/types/Indirect.h>
#include <std/Allocator.h>
#include <analyzer/IncludeObjectContext.h>
#include <analyzer/ClassCpp.h>
#include <analyzer/types/Primitive.h>

#include <analyzer/IncludeContext.h>

#line 342 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type) {
    #line 343 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->types, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 346 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type) {
    #line 347 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 350 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type) {
    #line 351 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(self->include, name);
    #line 352 "src/analyzer/Include.pv"
    func_info->return_type = *return_type;

    #line 354 "src/analyzer/Include.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 355 "src/analyzer/Include.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 358 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 359 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 361 "src/analyzer/Include.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 362 "src/analyzer/Include.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 363 "src/analyzer/Include.pv"
    if (return_type == 0) {
        #line 363 "src/analyzer/Include.pv"
        return_type = &include->root->type_void;
    }

    #line 365 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 368 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 369 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, &self->include->root->type_void);
}

#line 372 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 373 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 374 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 375 "src/analyzer/Include.pv"
    return struct_info;
}

#line 378 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 379 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 380 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 381 "src/analyzer/Include.pv"
    return struct_info;
}

#line 384 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 385 "src/analyzer/Include.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name, self->parent);
    #line 386 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 387 "src/analyzer/Include.pv"
    return enum_info;
}

#line 390 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name) {
    #line 391 "src/analyzer/Include.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .parent = enum_info, .name = (struct str){ .ptr = value_name, .length = strlen(value_name) } });
    #line 392 "src/analyzer/Include.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 395 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 396 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 397 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 399 "src/analyzer/Include.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 400 "src/analyzer/Include.pv"
    if (existing != 0) {
        #line 401 "src/analyzer/Include.pv"
        switch (existing->type) {
            #line 402 "src/analyzer/Include.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 402 "src/analyzer/Include.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 403 "src/analyzer/Include.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
                    .include = include,
                    .parent_context = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                    .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
                });
            } break;
            #line 411 "src/analyzer/Include.pv"
            default: {
            } break;
        }
    }

    #line 415 "src/analyzer/Include.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name, self->parent);
    #line 416 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 418 "src/analyzer/Include.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
        .include = include,
        .parent_context = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
        .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
    });
}

#line 427 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 428 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 430 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 430 "src/analyzer/Include.pv"
        return;
    }

    #line 432 "src/analyzer/Include.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 433 "src/analyzer/Include.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 435 "src/analyzer/Include.pv"
    if (type == 0) {
        #line 436 "src/analyzer/Include.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 437 "src/analyzer/Include.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 438 "src/analyzer/Include.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 440 "src/analyzer/Include.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 442 "src/analyzer/Include.pv"
        clang_disposeString(underlying_name);

        #line 444 "src/analyzer/Include.pv"
        return;
    }

    #line 447 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, name, type) });
}

#line 450 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 451 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 452 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 453 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 455 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 456 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 457 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 460 "src/analyzer/Include.pv"
    return struct_info;
}

#line 463 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 464 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 465 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 466 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 468 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 469 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 470 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 473 "src/analyzer/Include.pv"
    return struct_info;
}

#line 476 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 477 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 478 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 479 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 481 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 482 "src/analyzer/Include.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 483 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 484 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 487 "src/analyzer/Include.pv"
    return struct_info;
}

#line 490 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 491 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 492 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(include, name);
    #line 493 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 494 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 496 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 497 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 498 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 501 "src/analyzer/Include.pv"
    return func_info;
}

#line 504 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 505 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 507 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 507 "src/analyzer/Include.pv"
        return;
    }

    #line 509 "src/analyzer/Include.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 510 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 511 "src/analyzer/Include.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 513 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 516 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 517 "src/analyzer/Include.pv"
    struct IncludeContext* self = client_data;
    #line 518 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 520 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 521 "src/analyzer/Include.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 523 "src/analyzer/Include.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 524 "src/analyzer/Include.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 525 "src/analyzer/Include.pv"
    clang_disposeString(cursor_spelling);

    #line 527 "src/analyzer/Include.pv"
    if (kind == CXCursor_Namespace) {
        #line 528 "src/analyzer/Include.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 529 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 530 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 532 "src/analyzer/Include.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 533 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 535 "src/analyzer/Include.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 536 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, &(struct IncludeObjectContext) { .context = self, .object = enum_info });
        #line 537 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if ((kind == CXCursor_StructDecl) || (kind == CXCursor_ClassDecl)) {
        #line 539 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 540 "src/analyzer/Include.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 541 "src/analyzer/Include.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 542 "src/analyzer/Include.pv"
        clang_disposeString(type_spelling);

        #line 545 "src/analyzer/Include.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 546 "src/analyzer/Include.pv"
            struct ClassCpp* class_info = 0;
            #line 547 "src/analyzer/Include.pv"
            struct Type* class_type = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });

            #line 549 "src/analyzer/Include.pv"
            if (class_type != 0) {
                #line 550 "src/analyzer/Include.pv"
                switch (class_type->type) {
                    #line 551 "src/analyzer/Include.pv"
                    case TYPE__CLASS_CPP: {
                        #line 551 "src/analyzer/Include.pv"
                        struct ClassCpp* class_info2 = class_type->classcpp_value;
                        #line 552 "src/analyzer/Include.pv"
                        class_info = class_info2;
                    } break;
                    #line 554 "src/analyzer/Include.pv"
                    default: {
                    } break;
                }
            }

            #line 558 "src/analyzer/Include.pv"
            if (class_info == 0) {
                #line 559 "src/analyzer/Include.pv"
                class_info = ClassCpp__new(include, name, self->parent, kind == CXCursor_StructDecl);
                #line 560 "src/analyzer/Include.pv"
                IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
            }

            #line 563 "src/analyzer/Include.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            });

            #line 568 "src/analyzer/Include.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 570 "src/analyzer/Include.pv"
            if (strncmp(type_name, "struct ", 7) == 0) {
                #line 571 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 573 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });

                #line 578 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 581 "src/analyzer/Include.pv"
            if (strncmp(type_name, "union ", 7) == 0) {
                #line 582 "src/analyzer/Include.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 584 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                });

                #line 589 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 593 "src/analyzer/Include.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 594 "src/analyzer/Include.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 595 "src/analyzer/Include.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 596 "src/analyzer/Include.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);

        #line 598 "src/analyzer/Include.pv"
        if ((canonical_kind == CXCursor_StructDecl) || (canonical_kind == CXCursor_ClassDecl)) {
            #line 599 "src/analyzer/Include.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 601 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            });
            #line 605 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 607 "src/analyzer/Include.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 609 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            });
            #line 613 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 615 "src/analyzer/Include.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 616 "src/analyzer/Include.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 617 "src/analyzer/Include.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 619 "src/analyzer/Include.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 620 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 622 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 624 "src/analyzer/Include.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 629 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 636 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else {
            #line 645 "src/analyzer/Include.pv"
            IncludeContext__add_typedef(self, name, cursor);
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 648 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 649 "src/analyzer/Include.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 650 "src/analyzer/Include.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 652 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 654 "src/analyzer/Include.pv"
        if (HashMap_str_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 654 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        }

        #line 656 "src/analyzer/Include.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 657 "src/analyzer/Include.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 659 "src/analyzer/Include.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = include->root->primitive_void });
        }

        #line 662 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    }

    #line 665 "src/analyzer/Include.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 667 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
