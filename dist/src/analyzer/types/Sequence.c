#include <stdio.h>

#include <stdbool.h>
#include <analyzer/types/SequenceType.h>

#include <analyzer/types/Sequence.h>

#line 56 "src/analyzer/types/Type.pv"
bool Sequence__is_slice(struct Sequence* self) {
    #line 57 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 58 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__SLICE: {
            #line 58 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 59 "src/analyzer/types/Type.pv"
        default: {
            #line 59 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 63 "src/analyzer/types/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self) {
    #line 64 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 65 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 65 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 66 "src/analyzer/types/Type.pv"
        default: {
            #line 66 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}
