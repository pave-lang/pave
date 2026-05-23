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
    int32_t* next_next_data; {
        struct Asset* __optional_1;
        struct Asset* __optional_2 = (asset == 0 ? 0 : Asset__next(asset));
        __optional_1 = (__optional_2 == 0 ? 0 : Asset__next(__optional_2));
        next_next_data = (__optional_1 == 0 ? 0 : Asset__data(__optional_1));
    }

    return 0;
}
