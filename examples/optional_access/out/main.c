#include <stdio.h>
#include <stdlib.h>

#include <optional_access/Asset.h>
#include <optional_access/main.h>

int32_t main(int32_t argc, char const** argv) {
    struct Asset* asset = 0;

    int32_t* next_asset = (asset == 0 ? 0 : Asset__data(asset));

    return 0;
}
