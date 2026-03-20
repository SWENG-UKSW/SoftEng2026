#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"

TEST(test_shape1, AddFunction)
{
    bool res = true;
    ShapeParam<float> param;
    res = param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 1.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_CIRCLE;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

#if 0
    ShapeResult<float> data=shape->compute();
    float area=data.get_attrib(ShapeResultIndex::RESULT_AREA);
    ASSERT_NE(area, 0.f);
#endif

    shape.reset(nullptr);
    ASSERT_EQ(shape.get(), nullptr);
}

TEST(test_shape1, HexagonBasic)
{
    bool res = true;
    ShapeParam<float> param;

    res = param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 5.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_HEXAGON;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    auto data = shape->compute();

    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    float perimeter = data.get_attrib(ShapeResultIndex::RESULT_PERIMETER);

    ASSERT_NEAR(area, 64.95f, 0.1f);
    ASSERT_NEAR(perimeter, 30.0f, 0.01f);
}


TEST(test_shape1, HexagonZero)
{
    bool res = true;
    ShapeParam<float> param;

    res = param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_HEXAGON;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    auto data = shape->compute();

    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    float perimeter = data.get_attrib(ShapeResultIndex::RESULT_PERIMETER);

    ASSERT_EQ(area, 0.f);
    ASSERT_EQ(perimeter, 0.f);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}