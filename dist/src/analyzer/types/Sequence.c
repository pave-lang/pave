#include <analyzer/types/Sequence.h>
#include <analyzer/types/Sequence.h>

#include <analyzer/types/Sequence.h>

#line 57 "src/analyzer/types/Type.pv"
bool Sequence__is_slice(struct Sequence* self) {
    #line 58 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 59 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__SLICE: {
            #line 59 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 60 "src/analyzer/types/Type.pv"
        default: {
            #line 60 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}

#line 64 "src/analyzer/types/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self) {
    #line 65 "src/analyzer/types/Type.pv"
    switch (self->type.type) {
        #line 66 "src/analyzer/types/Type.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 66 "src/analyzer/types/Type.pv"
            return true;
        } break;
        #line 67 "src/analyzer/types/Type.pv"
        default: {
            #line 67 "src/analyzer/types/Type.pv"
            return false;
        } break;
    }
}
