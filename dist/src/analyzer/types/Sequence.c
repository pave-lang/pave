#include <stdio.h>

#include <analyzer/types/Sequence.h>

#include <analyzer/types/Sequence.h>

#line 65 "src/analyzer/types/Type.pv"
bool Sequence__is_slice(struct Sequence* self) {
    #line 66 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 67 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__SLICE: {
            #line 67 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 68 "src/analyzer/types/Type.pv"
        default: {
            #line 68 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 72 "src/analyzer/types/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self) {
    #line 73 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 74 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 74 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 75 "src/analyzer/types/Type.pv"
        default: {
            #line 75 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}
