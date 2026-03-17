#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <analyzer/ParentCpp.h>

#include <analyzer/ParentCpp.h>

#line 865 "src/analyzer/Include.pv"
bool ParentCpp__is_none(struct ParentCpp* self) {
    #line 866 "src/analyzer/Include.pv"
    switch (self->type) {
        #line 867 "src/analyzer/Include.pv"
        case PARENT_CPP__NONE: {
            #line 867 "src/analyzer/Include.pv"
            return true;
        } break;
        #line 868 "src/analyzer/Include.pv"
        default: {
            #line 868 "src/analyzer/Include.pv"
            return false;
        } break;
    }
}
