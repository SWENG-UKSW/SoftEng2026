#define _USE_MATH_DEFINES
#include <cmath>
#include <memory>
#include <gtest/gtest.h>
#include "ShapeFactory.h"

TEST(SphereTest, HappyPath)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 1.f);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    auto data = shape->compute();

    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    float volume = data.get_attrib(ShapeResultIndex::RESULT_VOLUME);

    ASSERT_NEAR(area, 4 * M_PI, 0.001);
    ASSERT_NEAR(volume, (4.0f / 3.0f) * M_PI, 0.001);
}

TEST(SphereTest, ZeroRadius)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.f);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));

    auto data = shape->compute();

    ASSERT_EQ(data.get_attrib(ShapeResultIndex::RESULT_AREA), 0.f);
    ASSERT_EQ(data.get_attrib(ShapeResultIndex::RESULT_VOLUME), 0.f);
}

TEST(SphereTest, NegativeRadius)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, -1.f);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_FALSE(param.validate());
}

TEST(SphereTest, LargeRadius)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 1000.f);
    param.type = ShapeType::PT_SPHERE;

    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));

    auto data = shape->compute();

    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    float volume = data.get_attrib(ShapeResultIndex::RESULT_VOLUME);

    ASSERT_NEAR(area, 4 * M_PI * 1000000.f, 1.0f);
    ASSERT_NEAR(volume, (4.0f / 3.0f) * M_PI * 1000000000.f, 10.0f);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}