#ifndef PAVE_INCLUDE_OBJECT_CONTEXT
#define PAVE_INCLUDE_OBJECT_CONTEXT

#include <clang-c/Index.h>
#include <string.h>

struct IncludeContext;

#line 7 "src/analyzer/c/IncludeObjectContext.pv"
struct IncludeObjectContext {
    struct IncludeContext* context;
    void* object;
};

#line 13 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 33 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 165 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data);

#line 181 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum_into_class(CXCursor cursor, CXCursor parent, CXClientData client_data);

#endif
