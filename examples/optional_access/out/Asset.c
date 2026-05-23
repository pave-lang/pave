#include <stdio.h>
#include <stdlib.h>

#include <optional_access/Asset.h>

#include <optional_access/Asset.h>

int32_t* Asset__data(struct Asset* self) {
    static int32_t DATA = 42;
    return &DATA;
}
