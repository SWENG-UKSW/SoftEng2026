#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include <chrono>

#include "Trapeze.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"

TEST(test_trapeze, ComputeArea)
{
    bool res = true;

    ShapeParam<float> param;

    res = param.set_attrib(PARAM_WIDTH, 4.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(PARAM_DEPTH, 6.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(PARAM_HEIGHT, 2.f);
    ASSERT_NE(res, false);

    res = param.validate();
    ASSERT_NE(res, false);

    Trapeze<float> trapeze(param);

    ShapeResult<float> data = trapeze.compute();

    float area = data.get_attrib(RESULT_AREA);

    ASSERT_FLOAT_EQ(area, 10.f);
}

TEST(test_trapeze, NegativeValues)
{
    bool res = true;
    ShapeParam<float> param;
    param.set_attrib(PARAM_WIDTH, -4.f);
    param.set_attrib(PARAM_DEPTH, 5.f);
    param.set_attrib(PARAM_HEIGHT, 2.f);

    ASSERT_FALSE(param.validate());
}

TEST(test_trapeze, ValuesEqualZero)
{
    bool res = true;
    ShapeParam<float> param;
    param.set_attrib(PARAM_WIDTH, 0.f);
    param.set_attrib(PARAM_DEPTH, 5.f);
    param.set_attrib(PARAM_HEIGHT, 2.f);

    ASSERT_FALSE(param.validate());
}


TEST(test_trapeze, PerformanceUnder1ms)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_WIDTH, 4.f);
    param.set_attrib(PARAM_DEPTH, 6.f);
    param.set_attrib(PARAM_HEIGHT, 2.f);

    Trapeze<float> trapeze(param);

    // Warm-up (important!)
    for (int i = 0; i < 1000; ++i)
    {
        trapeze.compute();
    }

    const int iterations = 100;

    volatile float sink = 0; // prevents optimization

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i)
    {
        sink += trapeze.compute().get_attrib(RESULT_AREA);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // 1 ms = 1000 microseconds
    ASSERT_LT(duration.count(), 1000);

}