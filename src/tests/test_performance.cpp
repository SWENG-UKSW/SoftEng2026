#include <gtest/gtest.h>
#include <chrono>
#include <memory>
#include <vector>
#include "Pyramid.h"
#include "Cone.h"

template <typename T>
class ShapePerformanceTest : public ::testing::Test {};

// Testowanie dla różnych typów danych
typedef ::testing::Types<float, double, long double> MyTypes;
TYPED_TEST_SUITE(ShapePerformanceTest, MyTypes);

TYPED_TEST(ShapePerformanceTest, PyramidAndConePerformance) {
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_WIDTH, 10.0);
    param.set_attrib(PARAM_HEIGHT, 15.0);
    param.set_attrib(PARAM_DEPTH, 20.0);
    param.set_attrib(PARAM_RADIUS, 5.0);

    // Wykorzystanie unique_ptr - brak wycieków
    std::unique_ptr<Shape3D<TypeParam>> pyramid = std::make_unique<Pyramid<TypeParam>>(param);
    std::unique_ptr<Shape3D<TypeParam>> cone = std::make_unique<Cone<TypeParam>>(param);

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 100; ++i) {
        pyramid->compute();
        cone->compute();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 1ms = 1000 mikrosekund
    EXPECT_LT(elapsed.count(), 1000) << "Test wydajnosci nie przeszedl: " << elapsed.count() << "us";
}
