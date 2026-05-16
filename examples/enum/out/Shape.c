#include <stdint.h>

#include <stdio.h>

#include <stdio.h>
#include <enum/Shape.h>
#include <enum/Shape.h>

#include <enum/Shape.h>

float Shape__area(struct Shape* self) {
    switch (self->type) {
        case SHAPE__CIRCLE: {
            float radius = self->circle_value.radius;
            return radius * radius * 3.14159f;
        } break;
        case SHAPE__RECT: {
            float width = self->rect_value.width;
            float height = self->rect_value.height;
            return width * height;
        } break;
        case SHAPE__POINT: {
            return 0.0f;
        } break;
    }
}

void Shape__print(struct Shape* self) {
    switch (self->type) {
        case SHAPE__CIRCLE: {
            float radius = self->circle_value.radius;
            printf("Circle(r=%f)\n", radius);
        } break;
        case SHAPE__RECT: {
            float width = self->rect_value.width;
            float height = self->rect_value.height;
            printf("Rect(%f x %f)\n", width, height);
        } break;
        case SHAPE__POINT: {
            printf("Point\n");
        } break;
    }
}
