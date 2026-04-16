#ifndef PAVE_FILE_WRITER
#define PAVE_FILE_WRITER

#include <stdint.h>
#include <stdbool.h>


#line 6 "src/compiler/FileWriter.pv"
struct FileWriter {
    FILE* file;
    uintptr_t indent;
};

#include <compiler/FileWriter.h>
#include <std/str.h>
struct FileWriter;
struct Token;

#line 12 "src/compiler/FileWriter.pv"
struct FileWriter FileWriter__new(FILE* file);

#line 16 "src/compiler/FileWriter.pv"
void FileWriter__add_indent(struct FileWriter* self);

#line 20 "src/compiler/FileWriter.pv"
bool FileWriter__remove_indent(struct FileWriter* self);

#line 30 "src/compiler/FileWriter.pv"
void FileWriter__write_indent(struct FileWriter* self);

#line 39 "src/compiler/FileWriter.pv"
bool FileWriter__write(struct FileWriter* self, char const* s);

#line 44 "src/compiler/FileWriter.pv"
bool FileWriter__write_str(struct FileWriter* self, struct str s);

#line 50 "src/compiler/FileWriter.pv"
bool FileWriter__write_str_title(struct FileWriter* self, struct str s);

#line 76 "src/compiler/FileWriter.pv"
bool FileWriter__write_str_lowercase(struct FileWriter* self, struct str s);

#line 95 "src/compiler/FileWriter.pv"
bool FileWriter__write_token(struct FileWriter* self, struct Token* token);

#endif
