#define _USE_MATH_DEFINES
#include <cmath>
#include <memory>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <limits>

TEST(test_sphere, HappyPath)
{
    ShapeParam<float> param;

    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 1.f));
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    float surface = data.get_attrib(ShapeResultIndex(0));
    float volume  = data.get_attrib(ShapeResultIndex(1));

    ASSERT_NEAR(surface, 4 * M_PI, 0.001f);
    ASSERT_NEAR(volume, (4.0f / 3.0f) * M_PI, 0.001f);
}

TEST(test_sphere, ZeroRadius)
{
    ShapeParam<float> param;

    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.f);
    param.type = ShapeType::PT_SPHERE;

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    ASSERT_EQ(data.get_attrib(ShapeResultIndex(0)), 0.f);
    ASSERT_EQ(data.get_attrib(ShapeResultIndex(1)), 0.f);
}

TEST(test_sphere, NegativeRadius)
{
    ShapeParam<float> param;

    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, -5.f);
    param.type = ShapeType::PT_SPHERE;

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    ASSERT_EQ(data.get_attrib(ShapeResultIndex(0)), 0.f);
    ASSERT_EQ(data.get_attrib(ShapeResultIndex(1)), 0.f);
}

TEST(test_sphere, MaxFloat)
{
    ShapeParam<float> param;

    float max = std::numeric_limits<float>::max();

    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, max);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    float surface = data.get_attrib(ShapeResultIndex(0));
    float volume  = data.get_attrib(ShapeResultIndex(1));

    ASSERT_TRUE(std::isinf(surface) || std::isfinite(surface));
    ASSERT_TRUE(std::isinf(volume) || std::isfinite(volume));
}

TEST(test_sphere, SmallRadiusPrecision)
{
    ShapeParam<float> param;

    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.001f);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape = std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    float surface = data.get_attrib(ShapeResultIndex(0));

    ASSERT_NEAR(surface, 4 * M_PI * 0.000001f, 0.000001f);
}