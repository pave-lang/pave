#ifndef PAVE_SIGNATURE_INFO
#define PAVE_SIGNATURE_INFO

#include <analyzer/Position.h>
#include <std/Array_Position.h>
#include <std/str.h>
#include <std/Array_str.h>

#line 43 "src/analyzer/Analysis.pv"
struct SignatureInfo {
    struct Position open_paren;
    struct Position close_paren;
    struct Array_Position comma_positions;
    struct str label;
    struct Array_str parameters;
};

#endif
