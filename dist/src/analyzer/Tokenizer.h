#ifndef PAVE_TOKENIZER
#define PAVE_TOKENIZER

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/str.h>
#include <std/Array_ptrc_char.h>

#line 7 "src/analyzer/Tokenizer.pv"
struct Tokenizer {
    struct str data;
    uintptr_t pos;
    uintptr_t line;
    uintptr_t column;
    struct Array_ptrc_char keywords;
    struct Array_ptrc_char symbols;
};

struct Tokenizer;
struct Array_ptrc_char;
struct ArenaAllocator;
#include <std/Array_ptrc_char.h>
#include <std/str.h>
#include <std/Array_Token.h>

#line 17 "src/analyzer/Tokenizer.pv"
void Tokenizer__increase_pos(struct Tokenizer* self);

#line 36 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_letter(struct Tokenizer* self);

#line 42 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_digit(struct Tokenizer* self, uintptr_t offset);

#line 48 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_symbol(struct Tokenizer* self);

#line 54 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_quote(struct Tokenizer* self);

#line 60 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_comment_line(struct Tokenizer* self);

#line 67 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_comment_line(struct Tokenizer* self);

#line 76 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_comment_block(struct Tokenizer* self);

#line 90 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_comment_block(struct Tokenizer* self);

#line 97 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_whitespace(struct Tokenizer* self);

#line 103 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_alphanumeric(struct Tokenizer* self);

#line 109 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_digits(struct Tokenizer* self);

#line 115 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_string(struct Tokenizer* self);

#line 132 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_in_array(struct Array_ptrc_char* array, char const* s, uintptr_t len);

#line 146 "src/analyzer/Tokenizer.pv"
struct Array_ptrc_char Tokenizer__make_keywords(struct ArenaAllocator* allocator);

#line 184 "src/analyzer/Tokenizer.pv"
struct Array_ptrc_char Tokenizer__make_symbols(struct ArenaAllocator* allocator);

#line 207 "src/analyzer/Tokenizer.pv"
struct str Tokenizer__read_file_into_string(struct ArenaAllocator* allocator, char const* filename);

#line 244 "src/analyzer/Tokenizer.pv"
struct Array_Token Tokenizer__tokenize(struct ArenaAllocator* allocator, char const* path);

#endif
