#include <stdio.h>

#include <stdio.h>
#include <enum/Standard.h>
#include <enum/Discriminated.h>
#include <enum/Shape.h>
#include <enum/main.h>

int32_t main() {
    enum Standard one = STANDARD__ONE;
    enum Standard two = STANDARD__TWO;
    Standard__print(&one);
    Standard__print(&two);

    struct Discriminated none = (struct Discriminated) { .type = DISCRIMINATED__NONE };
    struct Discriminated single = (struct Discriminated) { .type = DISCRIMINATED__SINGLE, .single_value = 42 };
    struct Discriminated dual = (struct Discriminated) { .type = DISCRIMINATED__DUAL, .dual_value = { ._0 = 1, ._1 = 2} };
    Discriminated__print(&none);
    Discriminated__print(&single);
    Discriminated__print(&dual);

    struct Shape c = (struct Shape) { .type = SHAPE__CIRCLE, .circle_value = { .radius = 2.0f } };
    struct Shape r = (struct Shape) { .type = SHAPE__RECT, .rect_value = { .width = 3.0f, .height = 4.0f } };
    struct Shape p = (struct Shape) { .type = SHAPE__POINT };
    Shape__print(&c);
    Shape__print(&r);
    Shape__print(&p);
    printf("circle area: %f\n", Shape__area(&c));
    printf("rect area: %f\n", Shape__area(&r));

    if (c.type == SHAPE__CIRCLE) {
        float radius = c.circle_value.radius;
        printf("circle radius via if-let: %f\n", radius);
    }

    if (r.type == SHAPE__RECT) {
        float w = r.rect_value.width;
        float h = r.rect_value.height;
        printf("rect via if-let: %f x %f\n", w, h);
    }

    return 0;
}
