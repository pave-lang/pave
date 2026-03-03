#include <stdio.h>

#include <stdbool.h>
#include <analyzer/SequenceType.h>

#include <analyzer/Sequence.h>

#line 48 "src/analyzer/Type.pv"
bool Sequence__is_slice(struct Sequence* self) {
    #line 49 "src/analyzer/Type.pv"
    switch (self->type.type) {
        #line 50 "src/analyzer/Type.pv"
        case SEQUENCE_TYPE__SLICE: {
            #line 50 "src/analyzer/Type.pv"
            return true;
        } break;
        #line 51 "src/analyzer/Type.pv"
        default: {
            #line 51 "src/analyzer/Type.pv"
            return false;
        } break;
    }
}

#line 55 "src/analyzer/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self) {
    #line 56 "src/analyzer/Type.pv"
    switch (self->type.type) {
        #line 57 "src/analyzer/Type.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
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
