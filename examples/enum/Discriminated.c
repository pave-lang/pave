#include <stdio.h>

#include <stdio.h>
#include <enum/Discriminated.h>
#include <enum/Discriminated.h>

#include <enum/Discriminated.h>

void Discriminated__print(struct Discriminated* self) {
    switch (self->type) {
        case DISCRIMINATED__NONE: {
            printf("none\n");
        } break;
        case DISCRIMINATED__SINGLE: {
            int32_t value = self->single_value;
            printf("single: %d\n", value);
        } break;
        case DISCRIMINATED__DUAL: {
            int32_t left = self->dual_value._0;
            int32_t right = self->dual_value._1;
            printf("dual: %d %d\n", left, right);
        } break;
    }
}
