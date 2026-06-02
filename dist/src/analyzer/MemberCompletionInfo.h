#ifndef PAVE_MEMBER_COMPLETION_INFO
#define PAVE_MEMBER_COMPLETION_INFO

#include <stdbool.h>

#include <analyzer/Position.h>
#include <analyzer/types/Type.h>

#line 59 "src/analyzer/Analysis.pv"
struct MemberCompletionInfo {
    struct Position dot_position;
    struct Type receiver_type;
    bool is_static;
};

#endif
