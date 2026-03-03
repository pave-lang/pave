#include <stdio.h>

#include <stdbool.h>
#include <analyzer/SequenceType.h>

#include <analyzer/Sequence.h>

#line 55 "src/analyzer/Type.pv"
bool Sequence__is_slice(struct Sequence* self) {
    #line 56 "src/analyzer/Type.pv"
    switch (self->type.type) {
        #line 57 "src/analyzer/Type.pv"
        case SEQUENCE_TYPE__SLICE: {
            #line 57 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 58 "src/analyzer/Type.pv"
        default: {
            #line 58 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 62 "src/analyzer/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self) {
    #line 63 "src/analyzer/Type.pv"
    switch (self->type.type) {
        #line 64 "src/analyzer/Type.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 64 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 65 "src/analyzer/Type.pv"
        default: {
            #line 65 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}
