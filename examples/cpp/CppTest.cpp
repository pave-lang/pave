#include <cpp.hpp>

#include <cpp.hpp>
#include <cpp/CppTest.h>

#include <cpp/CppTest.h>

void CppTest__run() {
    TestCpp::Vec4 a = TestCpp::Vec4 { };
    TestCpp::Vec4 b = TestCpp::Vec4(1.0f, 1.0f, 1.0f, 1.0f);

    TestCpp::print_vec(a);
    TestCpp::print_vec(b);

    b.x = 0.0f;

    TestCpp::print_vec(b);
}
