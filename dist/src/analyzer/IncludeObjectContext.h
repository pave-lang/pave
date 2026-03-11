#ifndef PAVE_INCLUDE_OBJECT_CONTEXT
#define PAVE_INCLUDE_OBJECT_CONTEXT

struct IncludeContext;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 334 "src/analyzer/Include.pv"
struct IncludeObjectContext {
    struct IncludeContext* context;
    void* object;
};

#line 670 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 690 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 822 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 838 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum_into_class(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
