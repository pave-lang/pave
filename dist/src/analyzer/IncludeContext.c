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

#line 299 "src/analyzer/Include.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type) {
    #line 300 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->types, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 303 "src/analyzer/Include.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type) {
    #line 304 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 307 "src/analyzer/Include.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type) {
    #line 308 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(self->include, name);
    #line 309 "src/analyzer/Include.pv"
    func_info->return_type = *return_type;

    #line 311 "src/analyzer/Include.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 312 "src/analyzer/Include.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 315 "src/analyzer/Include.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 316 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 318 "src/analyzer/Include.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 319 "src/analyzer/Include.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 320 "src/analyzer/Include.pv"
    if (return_type == 0) {
        #line 320 "src/analyzer/Include.pv"
        return_type = &include->root->type_void;
    }

    #line 322 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 325 "src/analyzer/Include.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 326 "src/analyzer/Include.pv"
    IncludeContext__insert_function(self, name, &self->include->root->type_void);
}

#line 329 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 330 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 331 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 332 "src/analyzer/Include.pv"
    return struct_info;
}

#line 335 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 336 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 337 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 338 "src/analyzer/Include.pv"
    return struct_info;
}

#line 341 "src/analyzer/Include.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 342 "src/analyzer/Include.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name);
    #line 343 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 344 "src/analyzer/Include.pv"
    return enum_info;
}

#line 347 "src/analyzer/Include.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name) {
    #line 348 "src/analyzer/Include.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .name = (struct str){ .ptr = value_name, .length = strlen(value_name) } });
    #line 349 "src/analyzer/Include.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 352 "src/analyzer/Include.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 353 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 354 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;
    #line 357 "src/analyzer/Include.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 358 "src/analyzer/Include.pv"
    if (existing != 0) {
        #line 359 "src/analyzer/Include.pv"
        switch (existing->type) {
            #line 360 "src/analyzer/Include.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 360 "src/analyzer/Include.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 361 "src/analyzer/Include.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
                    .include = include,
                    .parent = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                    .namespace = ns_info,
                });
            } break;
            #line 369 "src/analyzer/Include.pv"
            default: {
            } break;
        }
    }

    #line 373 "src/analyzer/Include.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name, self->namespace);
    #line 374 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 376 "src/analyzer/Include.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
        .include = include,
        .parent = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
        .namespace = ns_info,
    });
}

#line 385 "src/analyzer/Include.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 386 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 388 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 388 "src/analyzer/Include.pv"
        return;
    }

    #line 390 "src/analyzer/Include.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 391 "src/analyzer/Include.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 393 "src/analyzer/Include.pv"
    if (type == 0) {
        #line 394 "src/analyzer/Include.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 395 "src/analyzer/Include.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 396 "src/analyzer/Include.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 398 "src/analyzer/Include.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 400 "src/analyzer/Include.pv"
        clang_disposeString(underlying_name);

        #line 402 "src/analyzer/Include.pv"
        return;
    }

    #line 405 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, name, type) });
}

#line 408 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 409 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 410 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 411 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 413 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 414 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 415 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 418 "src/analyzer/Include.pv"
    return struct_info;
}

#line 421 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 422 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 423 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 424 "src/analyzer/Include.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 426 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 427 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 428 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 431 "src/analyzer/Include.pv"
    return struct_info;
}

#line 434 "src/analyzer/Include.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 435 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 436 "src/analyzer/Include.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 437 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 439 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 440 "src/analyzer/Include.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 441 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 442 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 445 "src/analyzer/Include.pv"
    return struct_info;
}

#line 448 "src/analyzer/Include.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 449 "src/analyzer/Include.pv"
    struct Include* include = self->include;
    #line 450 "src/analyzer/Include.pv"
    struct FunctionC* func_info = FunctionC__new(include, name);
    #line 451 "src/analyzer/Include.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 452 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 454 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 455 "src/analyzer/Include.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 456 "src/analyzer/Include.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 459 "src/analyzer/Include.pv"
    return func_info;
}

#line 462 "src/analyzer/Include.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 463 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 465 "src/analyzer/Include.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 465 "src/analyzer/Include.pv"
        return;
    }

    #line 467 "src/analyzer/Include.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 468 "src/analyzer/Include.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 469 "src/analyzer/Include.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 471 "src/analyzer/Include.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 474 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 475 "src/analyzer/Include.pv"
    struct IncludeContext* self = client_data;
    #line 476 "src/analyzer/Include.pv"
    struct Include* include = self->include;

    #line 478 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 479 "src/analyzer/Include.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 481 "src/analyzer/Include.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 482 "src/analyzer/Include.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 483 "src/analyzer/Include.pv"
    clang_disposeString(cursor_spelling);

    #line 485 "src/analyzer/Include.pv"
    if (kind == CXCursor_Namespace) {
        #line 486 "src/analyzer/Include.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 487 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 488 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 490 "src/analyzer/Include.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 491 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 493 "src/analyzer/Include.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 494 "src/analyzer/Include.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, &(struct IncludeObjectContext) { .context = self, .object = enum_info });
        #line 495 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_StructDecl || kind == CXCursor_ClassDecl) {
        #line 497 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 498 "src/analyzer/Include.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 499 "src/analyzer/Include.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 500 "src/analyzer/Include.pv"
        clang_disposeString(type_spelling);

        #line 503 "src/analyzer/Include.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 504 "src/analyzer/Include.pv"
            struct ClassCpp* class_info = ClassCpp__new(include, name, self->namespace, kind == CXCursor_StructDecl);
            #line 505 "src/analyzer/Include.pv"
            IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });

            #line 507 "src/analyzer/Include.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            });

            #line 512 "src/analyzer/Include.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 514 "src/analyzer/Include.pv"
            if (strncmp(type_name, "struct ", 7) == 0) {
                #line 515 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 517 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });

                #line 522 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 525 "src/analyzer/Include.pv"
            if (strncmp(type_name, "union ", 7) == 0) {
                #line 526 "src/analyzer/Include.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 528 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                });

                #line 533 "src/analyzer/Include.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 537 "src/analyzer/Include.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 538 "src/analyzer/Include.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 539 "src/analyzer/Include.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 540 "src/analyzer/Include.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);

        #line 542 "src/analyzer/Include.pv"
        if (canonical_kind == CXCursor_StructDecl || canonical_kind == CXCursor_ClassDecl) {
            #line 543 "src/analyzer/Include.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 545 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            });
            #line 549 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 551 "src/analyzer/Include.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 553 "src/analyzer/Include.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            });
            #line 557 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 559 "src/analyzer/Include.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 560 "src/analyzer/Include.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 561 "src/analyzer/Include.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 563 "src/analyzer/Include.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 564 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 566 "src/analyzer/Include.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 568 "src/analyzer/Include.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 573 "src/analyzer/Include.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 580 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        } else {
            #line 589 "src/analyzer/Include.pv"
            IncludeContext__add_typedef(self, name, cursor);
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 592 "src/analyzer/Include.pv"
        CXType type = clang_getCursorType(cursor);
        #line 593 "src/analyzer/Include.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 594 "src/analyzer/Include.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 596 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 598 "src/analyzer/Include.pv"
        if (HashMap_str_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 598 "src/analyzer/Include.pv"
            return CXChildVisit_Continue;
        }

        #line 600 "src/analyzer/Include.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 601 "src/analyzer/Include.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 603 "src/analyzer/Include.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = include->root->primitive_void });
        }

        #line 606 "src/analyzer/Include.pv"
        return CXChildVisit_Continue;
    }

    #line 609 "src/analyzer/Include.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 611 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
