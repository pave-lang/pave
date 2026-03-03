#include <stdio.h>

namespace TestCpp {
    class Vec4 {
    public:
        float x, y, z, w;

        Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
        Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    };

    void print_vec(const Vec4 v) {
        printf("%.2f %.2f %.2f %.2f\n", v.x, v.y, v.z, v.w);
    }
}
