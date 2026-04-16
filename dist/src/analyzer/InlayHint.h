#ifndef PAVE_INLAY_HINT
#define PAVE_INLAY_HINT

#include <stdbool.h>

#include <analyzer/Position.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>

#line 27 "src/analyzer/Analysis.pv"
struct InlayHint {
    struct Position position;
    struct str label;
    enum InlayHintKind kind;
    bool padding_left;
    bool padding_right;
};

#endif
