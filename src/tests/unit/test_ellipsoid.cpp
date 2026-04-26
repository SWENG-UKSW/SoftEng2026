#include <gtest/gtest.h>
#include "Ellipsoid.h"
#include <chrono>
#include <memory>

template <typename T> void runPerformanceTest()
{
    ShapeParam<T> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), static_cast<T>(2.0));
    param.set_attrib(static_cast<ShapeParamIndex>(1), static_cast<T>(3.0));
    param.set_attrib(static_cast<ShapeParamIndex>(2), static_cast<T>(4.0));

    auto e = std::make_unique<Ellipsoid<T>>(param);

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; ++i)
    {
        e->compute();
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    EXPECT_LT(elapsed.count(), 1.0);
}

TEST(EllipsoidPR, PerformanceTestDouble) { runPerformanceTest<double>(); }

TEST(EllipsoidPR, PerformanceTestFloat) { runPerformanceTest<float>(); }

TEST(EllipsoidPR, MemoryManagement)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), 2.0);
    param.set_attrib(static_cast<ShapeParamIndex>(1), 2.0);
    param.set_attrib(static_cast<ShapeParamIndex>(2), 2.0);

    auto e = std::make_unique<Ellipsoid<double>>(param);
    EXPECT_NO_THROW(e->compute());
}

TEST(EllipsoidPR, NegativeValueValidation)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), -1.0);

    EXPECT_THROW(
        { auto e = std::make_unique<Ellipsoid<double>>(param); },
        std::invalid_argument);
}