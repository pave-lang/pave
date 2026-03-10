#ifndef PAVE_INCLUDE_OBJECT_CONTEXT
#define PAVE_INCLUDE_OBJECT_CONTEXT

struct IncludeContext;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 326 "src/analyzer/Include.pv"
struct IncludeObjectContext {
    struct IncludeContext* context;
    void* object;
};

#line 649 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 669 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 726 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
