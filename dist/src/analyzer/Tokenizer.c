#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>
#include <stdbool.h>
#include <std/str.h>
#include <analyzer/TokenType.h>
#include <std/Array_ptrc_char.h>
#include <std/ArenaAllocator.h>
#include <std/Allocator.h>
#include <std/Array_Token.h>
#include <analyzer/Token.h>

#include <analyzer/Tokenizer.h>

#line 17 "src/analyzer/Tokenizer.pv"
void Tokenizer__increase_pos(struct Tokenizer* self) {
    #line 18 "src/analyzer/Tokenizer.pv"
    if (self->data.ptr[self->pos] == '\r' && self->data.ptr[self->pos + 1] == '\n') {
        #line 19 "src/analyzer/Tokenizer.pv"
        self->pos += 2;
        #line 20 "src/analyzer/Tokenizer.pv"
        self->line += 1;
        #line 21 "src/analyzer/Tokenizer.pv"
        self->column = 0;
        #line 22 "src/analyzer/Tokenizer.pv"
        return;
    }

    #line 25 "src/analyzer/Tokenizer.pv"
    if (self->data.ptr[self->pos] == '\r' || self->data.ptr[self->pos] == '\n') {
        #line 26 "src/analyzer/Tokenizer.pv"
        self->pos += 1;
        #line 27 "src/analyzer/Tokenizer.pv"
        self->line += 1;
        #line 28 "src/analyzer/Tokenizer.pv"
        self->column = 0;
        #line 29 "src/analyzer/Tokenizer.pv"
        return;
    }

    #line 32 "src/analyzer/Tokenizer.pv"
    self->pos += 1;
    #line 33 "src/analyzer/Tokenizer.pv"
    self->column += 1;
}

#line 36 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_letter(struct Tokenizer* self) {
    #line 37 "src/analyzer/Tokenizer.pv"
    char c = self->data.ptr[self->pos];

    #line 39 "src/analyzer/Tokenizer.pv"
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

#line 42 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_digit(struct Tokenizer* self, uintptr_t offset) {
    #line 43 "src/analyzer/Tokenizer.pv"
    char c = self->data.ptr[self->pos + offset];

    #line 45 "src/analyzer/Tokenizer.pv"
    return c >= '0' && c <= '9';
}

#line 48 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_symbol(struct Tokenizer* self) {
    #line 49 "src/analyzer/Tokenizer.pv"
    char c = self->data.ptr[self->pos];

    #line 51 "src/analyzer/Tokenizer.pv"
    return c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']' || c == '<' || c == '>' || c == '.' || c == ',' || c == ';' || c == ':' || c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '&' || c == '!' || c == '|' || c == '^' || c == '~';
}

#line 54 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_quote(struct Tokenizer* self) {
    #line 55 "src/analyzer/Tokenizer.pv"
    char c = self->data.ptr[self->pos];

    #line 57 "src/analyzer/Tokenizer.pv"
    return c == '\"' || c == '\'';
}

#line 60 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_comment_line(struct Tokenizer* self) {
    #line 61 "src/analyzer/Tokenizer.pv"
    char c1 = self->data.ptr[self->pos];
    #line 62 "src/analyzer/Tokenizer.pv"
    char c2 = self->data.ptr[self->pos + 1];

    #line 64 "src/analyzer/Tokenizer.pv"
    return c1 == '/' && c2 == '/';
}

#line 67 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_comment_line(struct Tokenizer* self) {
    #line 68 "src/analyzer/Tokenizer.pv"
    Tokenizer__increase_pos(self);
    #line 69 "src/analyzer/Tokenizer.pv"
    Tokenizer__increase_pos(self);

    #line 71 "src/analyzer/Tokenizer.pv"
    while (self->pos < self->data.length && self->data.ptr[self->pos] != '\r' && self->data.ptr[self->pos] != '\n') {
        #line 72 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 76 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_comment_block(struct Tokenizer* self) {
    #line 77 "src/analyzer/Tokenizer.pv"
    Tokenizer__increase_pos(self);
    #line 78 "src/analyzer/Tokenizer.pv"
    Tokenizer__increase_pos(self);

    #line 80 "src/analyzer/Tokenizer.pv"
    while (self->pos < self->data.length && (self->data.ptr[self->pos] == '*' && self->data.ptr[self->pos + 1] == '/') == 0) {
        #line 81 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }

    #line 84 "src/analyzer/Tokenizer.pv"
    if (self->data.ptr[self->pos] == '*' && self->data.ptr[self->pos + 1] == '/') {
        #line 85 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
        #line 86 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 90 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_comment_block(struct Tokenizer* self) {
    #line 91 "src/analyzer/Tokenizer.pv"
    char c1 = self->data.ptr[self->pos];
    #line 92 "src/analyzer/Tokenizer.pv"
    char c2 = self->data.ptr[self->pos + 1];

    #line 94 "src/analyzer/Tokenizer.pv"
    return c1 == '/' && c2 == '*';
}

#line 97 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_whitespace(struct Tokenizer* self) {
    #line 98 "src/analyzer/Tokenizer.pv"
    while (self->pos < self->data.length && (self->data.ptr[self->pos] == ' ' || self->data.ptr[self->pos] == '\t' || self->data.ptr[self->pos] == '\r' || self->data.ptr[self->pos] == '\n')) {
        #line 99 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 103 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_alphanumeric(struct Tokenizer* self) {
    #line 104 "src/analyzer/Tokenizer.pv"
    while (Tokenizer__is_letter(self) || Tokenizer__is_digit(self, 0)) {
        #line 105 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 109 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_digits(struct Tokenizer* self) {
    #line 110 "src/analyzer/Tokenizer.pv"
    while (Tokenizer__is_digit(self, 0)) {
        #line 111 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 115 "src/analyzer/Tokenizer.pv"
void Tokenizer__skip_string(struct Tokenizer* self) {
    #line 116 "src/analyzer/Tokenizer.pv"
    char delimiter = self->data.ptr[self->pos];
    #line 117 "src/analyzer/Tokenizer.pv"
    Tokenizer__increase_pos(self);

    #line 119 "src/analyzer/Tokenizer.pv"
    while (self->pos < self->data.length && self->data.ptr[self->pos] != delimiter) {
        #line 120 "src/analyzer/Tokenizer.pv"
        if (self->data.ptr[self->pos] == '\\') {
            #line 121 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(self);
        }

        #line 124 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }

    #line 127 "src/analyzer/Tokenizer.pv"
    if (self->data.ptr[self->pos] == delimiter) {
        #line 128 "src/analyzer/Tokenizer.pv"
        Tokenizer__increase_pos(self);
    }
}

#line 132 "src/analyzer/Tokenizer.pv"
bool Tokenizer__is_in_array(struct Array_ptrc_char* array, char const* s, uintptr_t len) {
    #line 133 "src/analyzer/Tokenizer.pv"
    uintptr_t i = 0;

    #line 135 "src/analyzer/Tokenizer.pv"
    while (i < array->length) {
        #line 136 "src/analyzer/Tokenizer.pv"
        if (strlen(array->data[i]) == len && strncmp(array->data[i], s, len) == 0) {
            #line 137 "src/analyzer/Tokenizer.pv"
            return 1;
        }

        #line 140 "src/analyzer/Tokenizer.pv"
        i += 1;
    }

    #line 143 "src/analyzer/Tokenizer.pv"
    return 0;
}

#line 146 "src/analyzer/Tokenizer.pv"
struct Array_ptrc_char Tokenizer__make_keywords(struct ArenaAllocator* allocator) {
    #line 147 "src/analyzer/Tokenizer.pv"
    struct Array_ptrc_char keywords = Array_ptrc_char__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 149 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "struct");
    #line 150 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "trait");
    #line 151 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "enum");
    #line 152 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "impl");
    #line 153 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "fn");
    #line 154 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "co");
    #line 155 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "let");
    #line 156 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "return");
    #line 157 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "yield");
    #line 158 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "for");
    #line 159 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "in");
    #line 160 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "while");
    #line 161 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "continue");
    #line 162 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "break");
    #line 163 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "if");
    #line 164 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "else");
    #line 165 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "match");
    #line 166 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "defer");
    #line 167 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "const");
    #line 168 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "true");
    #line 169 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "false");
    #line 170 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "ns");
    #line 171 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "mod");
    #line 172 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "use");
    #line 173 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "static");

    #line 176 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "export");
    #line 177 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "pub");
    #line 178 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&keywords, "mut");

    #line 180 "src/analyzer/Tokenizer.pv"
    return keywords;
}

#line 183 "src/analyzer/Tokenizer.pv"
struct Array_ptrc_char Tokenizer__make_symbols(struct ArenaAllocator* allocator) {
    #line 184 "src/analyzer/Tokenizer.pv"
    struct Array_ptrc_char symbols = Array_ptrc_char__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 186 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "::");
    #line 187 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "->");
    #line 188 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "=>");
    #line 189 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "||");
    #line 190 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "&&");
    #line 191 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "<<");
    #line 192 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "==");
    #line 193 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, ">=");
    #line 194 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "<=");
    #line 195 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "!=");
    #line 196 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "+=");
    #line 197 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "-=");
    #line 198 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "*=");
    #line 199 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "/=");
    #line 200 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "|=");
    #line 201 "src/analyzer/Tokenizer.pv"
    Array_ptrc_char__append(&symbols, "..");

    #line 203 "src/analyzer/Tokenizer.pv"
    return symbols;
}

#line 206 "src/analyzer/Tokenizer.pv"
struct str Tokenizer__read_file_into_string(struct ArenaAllocator* allocator, char const* filename) {
    #line 207 "src/analyzer/Tokenizer.pv"
    FILE* file = fopen(filename, "rb");

    #line 209 "src/analyzer/Tokenizer.pv"
    if (file == 0) {
        #line 210 "src/analyzer/Tokenizer.pv"
        fprintf(stderr, "Unable to open file: %s\n", filename);
        #line 211 "src/analyzer/Tokenizer.pv"
        perror("fopen");
        #line 212 "src/analyzer/Tokenizer.pv"
        return (struct str) {};
    }

    #line 215 "src/analyzer/Tokenizer.pv"
    fseek(file, 0, SEEK_END);
    #line 216 "src/analyzer/Tokenizer.pv"
    int32_t length = ftell(file);
    #line 217 "src/analyzer/Tokenizer.pv"
    rewind(file);

    #line 219 "src/analyzer/Tokenizer.pv"
    char* buffer = ArenaAllocator__Allocator__alloc(allocator, length + 1);

    #line 221 "src/analyzer/Tokenizer.pv"
    if (buffer == 0) {
        #line 222 "src/analyzer/Tokenizer.pv"
        perror("Memory allocation failed");
        #line 223 "src/analyzer/Tokenizer.pv"
        fclose(file);
        #line 224 "src/analyzer/Tokenizer.pv"
        return (struct str) {};
    }

    #line 227 "src/analyzer/Tokenizer.pv"
    uintptr_t read_length = fread(buffer, 1, length, file);

    #line 229 "src/analyzer/Tokenizer.pv"
    if (read_length != length) {
        #line 230 "src/analyzer/Tokenizer.pv"
        perror("Error reading file");
        #line 231 "src/analyzer/Tokenizer.pv"
        ArenaAllocator__Allocator__free(allocator, buffer);
        #line 232 "src/analyzer/Tokenizer.pv"
        fclose(file);
        #line 233 "src/analyzer/Tokenizer.pv"
        return (struct str) {};
    }

    #line 236 "src/analyzer/Tokenizer.pv"
    buffer[length] = '\0';

    #line 238 "src/analyzer/Tokenizer.pv"
    fclose(file);

    #line 240 "src/analyzer/Tokenizer.pv"
    return (struct str) { .ptr = buffer, .length = length };
}

#line 243 "src/analyzer/Tokenizer.pv"
struct Array_Token Tokenizer__tokenize(struct ArenaAllocator* allocator, char const* path) {
    #line 244 "src/analyzer/Tokenizer.pv"
    struct str data = Tokenizer__read_file_into_string(allocator, path);

    #line 246 "src/analyzer/Tokenizer.pv"
    if (data.length == 0) {
        #line 247 "src/analyzer/Tokenizer.pv"
        return (struct Array_Token) {};
    }

    #line 250 "src/analyzer/Tokenizer.pv"
    struct Tokenizer tokenizer = (struct Tokenizer) {
        .data = data,
        .keywords = Tokenizer__make_keywords(allocator),
        .symbols = Tokenizer__make_symbols(allocator),
    };

    #line 256 "src/analyzer/Tokenizer.pv"
    struct Array_Token tokens = Array_Token__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 258 "src/analyzer/Tokenizer.pv"
    Tokenizer__skip_whitespace(&tokenizer);

    #line 260 "src/analyzer/Tokenizer.pv"
    while (tokenizer.pos < tokenizer.data.length) {
        #line 261 "src/analyzer/Tokenizer.pv"
        bool is_raw_identifier = tokenizer.data.ptr[tokenizer.pos] == 'r' && tokenizer.data.ptr[tokenizer.pos + 1] == '#';
        #line 262 "src/analyzer/Tokenizer.pv"
        if (is_raw_identifier) {
            #line 263 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(&tokenizer);
            #line 264 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(&tokenizer);
        }

        #line 267 "src/analyzer/Tokenizer.pv"
        uintptr_t start_pos = tokenizer.pos;

        #line 269 "src/analyzer/Tokenizer.pv"
        struct Token token = (struct Token) {
            .value = (struct str) { .ptr = tokenizer.data.ptr + start_pos },
            .start_line = tokenizer.line,
            .start_column = tokenizer.column,
        };

        #line 277 "src/analyzer/Tokenizer.pv"
        if (is_raw_identifier || Tokenizer__is_letter(&tokenizer) || tokenizer.data.ptr[tokenizer.pos] == '#') {
            #line 278 "src/analyzer/Tokenizer.pv"
            bool is_hash_keyword = !is_raw_identifier && tokenizer.data.ptr[tokenizer.pos] == '#';
            #line 279 "src/analyzer/Tokenizer.pv"
            if (is_hash_keyword) {
                #line 279 "src/analyzer/Tokenizer.pv"
                Tokenizer__increase_pos(&tokenizer);
            }

            #line 281 "src/analyzer/Tokenizer.pv"
            Tokenizer__skip_alphanumeric(&tokenizer);

            #line 283 "src/analyzer/Tokenizer.pv"
            if (!is_raw_identifier && (is_hash_keyword || Tokenizer__is_in_array(&tokenizer.keywords, token.value.ptr, tokenizer.pos - start_pos))) {
                #line 284 "src/analyzer/Tokenizer.pv"
                token.type = TOKEN_TYPE__KEYWORD;
            } else {
                #line 286 "src/analyzer/Tokenizer.pv"
                token.type = TOKEN_TYPE__IDENTIFIER;
            }
        } else if (Tokenizer__is_digit(&tokenizer, 0)) {
            #line 289 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(&tokenizer);

            #line 291 "src/analyzer/Tokenizer.pv"
            if (tokenizer.data.ptr[start_pos] == '0' && (tokenizer.data.ptr[tokenizer.pos] == 'x' || tokenizer.data.ptr[tokenizer.pos] == 'X')) {
                #line 292 "src/analyzer/Tokenizer.pv"
                Tokenizer__increase_pos(&tokenizer);
                #line 293 "src/analyzer/Tokenizer.pv"
                while (Tokenizer__is_digit(&tokenizer, 0) || (tokenizer.data.ptr[tokenizer.pos] >= 'a' && tokenizer.data.ptr[tokenizer.pos] <= 'f') || (tokenizer.data.ptr[tokenizer.pos] >= 'A' && tokenizer.data.ptr[tokenizer.pos] <= 'F')) {
                    #line 294 "src/analyzer/Tokenizer.pv"
                    Tokenizer__increase_pos(&tokenizer);
                }
            } else {
                #line 297 "src/analyzer/Tokenizer.pv"
                Tokenizer__skip_digits(&tokenizer);

                #line 299 "src/analyzer/Tokenizer.pv"
                if (tokenizer.data.ptr[tokenizer.pos] == '.' && Tokenizer__is_digit(&tokenizer, 1)) {
                    #line 300 "src/analyzer/Tokenizer.pv"
                    Tokenizer__increase_pos(&tokenizer);
                    #line 301 "src/analyzer/Tokenizer.pv"
                    Tokenizer__increase_pos(&tokenizer);
                    #line 302 "src/analyzer/Tokenizer.pv"
                    Tokenizer__skip_digits(&tokenizer);
                }

                #line 305 "src/analyzer/Tokenizer.pv"
                if (tokenizer.data.ptr[tokenizer.pos] == 'f' || tokenizer.data.ptr[tokenizer.pos] == 'F') {
                    #line 306 "src/analyzer/Tokenizer.pv"
                    Tokenizer__increase_pos(&tokenizer);
                }
            }

            #line 310 "src/analyzer/Tokenizer.pv"
            token.type = TOKEN_TYPE__NUMBER;
        } else if (Tokenizer__is_quote(&tokenizer)) {
            #line 312 "src/analyzer/Tokenizer.pv"
            Tokenizer__skip_string(&tokenizer);

            #line 314 "src/analyzer/Tokenizer.pv"
            token.type = TOKEN_TYPE__STRING;
        } else if (Tokenizer__is_comment_line(&tokenizer)) {
            #line 316 "src/analyzer/Tokenizer.pv"
            Tokenizer__skip_comment_line(&tokenizer);

            #line 318 "src/analyzer/Tokenizer.pv"
            token.type = TOKEN_TYPE__COMMENT;
        } else if (Tokenizer__is_comment_block(&tokenizer)) {
            #line 320 "src/analyzer/Tokenizer.pv"
            Tokenizer__skip_comment_block(&tokenizer);

            #line 322 "src/analyzer/Tokenizer.pv"
            token.type = TOKEN_TYPE__COMMENT;
        } else if (Tokenizer__is_symbol(&tokenizer)) {
            #line 324 "src/analyzer/Tokenizer.pv"
            if (Tokenizer__is_in_array(&tokenizer.symbols, token.value.ptr, 2)) {
                #line 325 "src/analyzer/Tokenizer.pv"
                Tokenizer__increase_pos(&tokenizer);
            }

            #line 328 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(&tokenizer);

            #line 330 "src/analyzer/Tokenizer.pv"
            token.type = TOKEN_TYPE__SYMBOL;
        } else {
            #line 332 "src/analyzer/Tokenizer.pv"
            fprintf(stderr, "Tokenizer: Unknown token type: %.*s\n", 10, tokenizer.data.ptr + tokenizer.pos);
            #line 333 "src/analyzer/Tokenizer.pv"
            Tokenizer__increase_pos(&tokenizer);
        }

        #line 336 "src/analyzer/Tokenizer.pv"
        token.value.length = tokenizer.pos - start_pos;
        #line 337 "src/analyzer/Tokenizer.pv"
        token.end_line = tokenizer.line;
        #line 338 "src/analyzer/Tokenizer.pv"
        token.end_column = tokenizer.column;

        #line 340 "src/analyzer/Tokenizer.pv"
        Array_Token__append(&tokens, token);

        #line 342 "src/analyzer/Tokenizer.pv"
        Tokenizer__skip_whitespace(&tokenizer);
    }

    #line 345 "src/analyzer/Tokenizer.pv"
    return tokens;
}
