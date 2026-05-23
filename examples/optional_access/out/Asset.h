#ifndef PAVE_ASSET
#define PAVE_ASSET

#include <stdint.h>

struct Asset {
    int32_t value;
};

struct Asset;

int32_t* Asset__data(struct Asset* self);

struct Asset* Asset__next(struct Asset* self);

#endif
