#include <analyzer/c/ParentCpp.h>
#include <analyzer/c/ParentCpp.h>

#include <analyzer/c/ParentCpp.h>

#line 8 "src/analyzer/c/ParentCpp.pv"
bool ParentCpp__is_none(struct ParentCpp* self) {
    #line 9 "src/analyzer/c/ParentCpp.pv"
    switch (self->type) {
        #line 10 "src/analyzer/c/ParentCpp.pv"
        case PARENT_CPP__NONE: {
            #line 10 "src/analyzer/c/ParentCpp.pv"
            return true;
        } break;
        #line 11 "src/analyzer/c/ParentCpp.pv"
        default: {
            #line 11 "src/analyzer/c/ParentCpp.pv"
            return false;
        } break;
    }
}
