#include <stdint.h>

#include <compiler/FileWriter.h>
#include <std/str.h>
#include <analyzer/Token.h>
#include <compiler/FileWriter.h>

#include <compiler/FileWriter.h>

#line 12 "src/compiler/FileWriter.pv"
struct FileWriter FileWriter__new(FILE* file) {
    #line 13 "src/compiler/FileWriter.pv"
    return (struct FileWriter) { .file = file };
}

#line 16 "src/compiler/FileWriter.pv"
void FileWriter__add_indent(struct FileWriter* self) {
    #line 17 "src/compiler/FileWriter.pv"
    self->indent += 1;
}

#line 20 "src/compiler/FileWriter.pv"
bool FileWriter__remove_indent(struct FileWriter* self) {
    #line 21 "src/compiler/FileWriter.pv"
    if (self->indent == 0) {
        #line 22 "src/compiler/FileWriter.pv"
        return false;
    }

    #line 25 "src/compiler/FileWriter.pv"
    self->indent -= 1;

    #line 27 "src/compiler/FileWriter.pv"
    return true;
}

#line 30 "src/compiler/FileWriter.pv"
void FileWriter__write_indent(struct FileWriter* self) {
    #line 31 "src/compiler/FileWriter.pv"
    int32_t i = 0;

    #line 33 "src/compiler/FileWriter.pv"
    while (i < self->indent) {
        #line 34 "src/compiler/FileWriter.pv"
        fprintf(self->file, "    ");
        #line 35 "src/compiler/FileWriter.pv"
        i += 1;
    }
}

#line 39 "src/compiler/FileWriter.pv"
bool FileWriter__write(struct FileWriter* self, char const* s) {
    #line 40 "src/compiler/FileWriter.pv"
    fprintf(self->file, "%s", s);
    #line 41 "src/compiler/FileWriter.pv"
    return true;
}

#line 44 "src/compiler/FileWriter.pv"
bool FileWriter__write_str(struct FileWriter* self, struct str s) {
    #line 45 "src/compiler/FileWriter.pv"
    int32_t length = s.length;
    #line 46 "src/compiler/FileWriter.pv"
    fprintf(self->file, "%.*s", length, s.ptr);
    #line 47 "src/compiler/FileWriter.pv"
    return true;
}

#line 50 "src/compiler/FileWriter.pv"
bool FileWriter__write_str_title(struct FileWriter* self, struct str s) {
    #line 51 "src/compiler/FileWriter.pv"
    uintptr_t i = 0;
    #line 52 "src/compiler/FileWriter.pv"
    uintptr_t length = s.length;
    #line 53 "src/compiler/FileWriter.pv"
    bool was_lowercase = false;

    #line 55 "src/compiler/FileWriter.pv"
    while (i < length) {
        #line 56 "src/compiler/FileWriter.pv"
        char c = s.ptr[i];

        #line 58 "src/compiler/FileWriter.pv"
        if (c >= 'a' && c <= 'z') {
            #line 59 "src/compiler/FileWriter.pv"
            fprintf(self->file, "%c", c - 32);
            #line 60 "src/compiler/FileWriter.pv"
            was_lowercase = true;
        } else {
            #line 62 "src/compiler/FileWriter.pv"
            if (was_lowercase && c >= 'A' && c <= 'Z') {
                #line 63 "src/compiler/FileWriter.pv"
                fprintf(self->file, "_");
            }

            #line 66 "src/compiler/FileWriter.pv"
            fprintf(self->file, "%c", c);
            #line 67 "src/compiler/FileWriter.pv"
            was_lowercase = false;
        }

        #line 70 "src/compiler/FileWriter.pv"
        i += 1;
    }

    #line 73 "src/compiler/FileWriter.pv"
    return true;
}

#line 76 "src/compiler/FileWriter.pv"
bool FileWriter__write_str_lowercase(struct FileWriter* self, struct str s) {
    #line 77 "src/compiler/FileWriter.pv"
    uintptr_t i = 0;
    #line 78 "src/compiler/FileWriter.pv"
    uintptr_t length = s.length;

    #line 80 "src/compiler/FileWriter.pv"
    while (i < length) {
        #line 81 "src/compiler/FileWriter.pv"
        char c = s.ptr[i];

        #line 83 "src/compiler/FileWriter.pv"
        if (c >= 'A' && c <= 'Z') {
            #line 84 "src/compiler/FileWriter.pv"
            fprintf(self->file, "%c", c + 32);
        } else {
            #line 86 "src/compiler/FileWriter.pv"
            fprintf(self->file, "%c", c);
        }

        #line 89 "src/compiler/FileWriter.pv"
        i += 1;
    }

    #line 92 "src/compiler/FileWriter.pv"
    return true;
}

#line 95 "src/compiler/FileWriter.pv"
bool FileWriter__write_token(struct FileWriter* self, struct Token* token) {
    #line 96 "src/compiler/FileWriter.pv"
    return FileWriter__write_str(self, token->value);
}
