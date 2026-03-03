#include <stdio.h>

#include <enum/Standard.h>
#include <stdint.h>

#include <enum/Standard.h>

void Standard__print(enum Standard* self) {
    switch (*self) {
        case STANDARD__ONE: {
            printf("one\n");
        } break;
        case STANDARD__TWO: {
            printf("two\n");
        } break;
    }
}
