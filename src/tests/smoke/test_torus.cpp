#include <gtest/gtest.h>
#include "Torus.h"

#define PARAM_RADIUS_2 PARAM_WIDTH

TEST(TorusTest, BasicCase)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 10);
    param.set_attrib(PARAM_RADIUS_2, 5);

    Torus<float> torus(param);
    ShapeResult<float> result = torus.compute();

    float PI = 3.141592653589793;

    float expectedSurface = 4 * PI * PI * 10 * 5;
    float expectedVolume = 2 * PI * PI * 10 * 5 * 5;

    EXPECT_NEAR(result.get_attrib(RESULT_SURFACE), expectedSurface, 0.001);
    EXPECT_NEAR(result.get_attrib(RESULT_VOLUME), expectedVolume, 0.001);
}

TEST(TorusTest, ZeroRadius)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 0);
    param.set_attrib(PARAM_RADIUS_2, 5);

    Torus<float> torus(param);
    ShapeResult<float> result = torus.compute();

    EXPECT_EQ(result.get_attrib(RESULT_SURFACE), 0);
    EXPECT_EQ(result.get_attrib(RESULT_VOLUME), 0);
}

TEST(TorusTest, ZeroTubeRadius)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 10);
    param.set_attrib(PARAM_RADIUS_2, 0);

    Torus<float> torus(param);
    ShapeResult<float> result = torus.compute();

    EXPECT_EQ(result.get_attrib(RESULT_SURFACE), 0);
    EXPECT_EQ(result.get_attrib(RESULT_VOLUME), 0);
}

TEST(TorusTest, LargeValues)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 10000);
    param.set_attrib(PARAM_RADIUS_2, 5000);

    Torus<float> torus(param);
    ShapeResult<float> result = torus.compute();

    EXPECT_GT(result.get_attrib(RESULT_SURFACE), 0);
    EXPECT_GT(result.get_attrib(RESULT_VOLUME), 0);
}

TEST(TorusTest, PrintCheck)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 7);
    param.set_attrib(PARAM_RADIUS_2, 3);

    Torus<float> torus(param);

    EXPECT_EQ(torus.print(), "");
}