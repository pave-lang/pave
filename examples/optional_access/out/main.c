#include <stdio.h>
#include <stdlib.h>

#include <optional_access/Asset.h>
#include <optional_access/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Asset* asset = 0;

    int32_t* data = (asset == 0 ? 0 : Asset__data(asset));
    int32_t* next_data; {
        struct Asset* __optional_0 = (asset == 0 ? 0 : Asset__next(asset));
        next_data = (__optional_0 == 0 ? 0 : Asset__data(__optional_0));
    }
    int32_t* next_next2_data; {
        struct Asset* __optional_0 = (asset == 0 ? 0 : Asset__next(asset));
        struct Asset* __optional_1 = (__optional_0 == 0 ? 0 : Asset__next2(__optional_0));
        next_next2_data = (__optional_1 == 0 ? 0 : Asset__data(__optional_1));
    }

    return 0;
}
