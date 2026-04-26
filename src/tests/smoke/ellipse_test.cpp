#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <limits>
#include <chrono> // Dodane do pomiaru czasu

// Konfiguracja testów dla wielu typów danych (float i double)
template <typename T> class test_ellipse : public ::testing::Test {};

using MyTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(test_ellipse, MyTypes);

// Test Happy Path z użyciem unique_ptr
TYPED_TEST(test_ellipse, AreaHappyPath)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS,
                     static_cast<TypeParam>(2.0));
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2,
                     static_cast<TypeParam>(3.0));
    param.type = ShapeType::PT_ELLIPSE;

    ASSERT_TRUE(param.validate());

    auto shape = std::unique_ptr<IShape<TypeParam>>(
        ShapeFactory<TypeParam>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<TypeParam> data = shape->compute();
    TypeParam area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    ASSERT_NEAR(area, static_cast<TypeParam>(18.8495),
                static_cast<TypeParam>(0.001));
}

// Test ujemnego promienia - teraz musi współpracować z nowym validate()
TYPED_TEST(test_ellipse, NegativeRadius)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS,
                     static_cast<TypeParam>(-4.0));
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2,
                     static_cast<TypeParam>(5.0));
    param.type = ShapeType::PT_ELLIPSE;

    // To powinno teraz zwrócić false dzięki poprawce w ShapeParam.h
    ASSERT_FALSE(param.validate());
}

// NOWOŚĆ: Test wydajnościowy - 100 iteracji, czas < 1ms
TYPED_TEST(test_ellipse, PerformanceTest)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS,
                     static_cast<TypeParam>(5.0));
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2,
                     static_cast<TypeParam>(10.0));
    param.type = ShapeType::PT_ELLIPSE;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100; ++i)
    {
        auto shape = std::unique_ptr<IShape<TypeParam>>(
            ShapeFactory<TypeParam>::create(param));
        shape->compute();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();

    // 1ms = 1000 mikrosekund
    EXPECT_LT(duration, 1000);
}