#ifndef PAVE_SHAPE
#define PAVE_SHAPE

struct Shape {
    enum {
        SHAPE__CIRCLE,
        SHAPE__RECT,
        SHAPE__POINT,
    } type;

    union {
        struct { float radius; } circle_value;
        struct { float width; float height; } rect_value;
    };
};

struct Shape;

float Shape__area(struct Shape* self);

void Shape__print(struct Shape* self);

#endif
