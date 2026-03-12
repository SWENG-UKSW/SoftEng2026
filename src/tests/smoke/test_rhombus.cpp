#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>

#include "ShapeFactory.h"
#include <limits>
TEST(test_rhombus, AreaHappyPath)
{
    bool res = true;

    ShapeParam<float> param;

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, 6.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_RHOMBUS;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));

    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    ASSERT_NEAR(area, 24.f, 0.001f);
}
TEST(test_rhombus, ZeroDiagonal)
{
    bool res = true;

    ShapeParam<float> param;

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, 0.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_RHOMBUS;

    res = param.validate();

    ASSERT_EQ(res, true);
}
TEST(test_rhombus, MaxFloat)
{
    ShapeParam<float> param;

    float max = std::numeric_limits<float>::max();

    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, max);
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, max);

    param.type = ShapeType::PT_RHOMBUS;

    bool res = param.validate();
    ASSERT_EQ(res, true);
}
TEST(test_rhombus, NegativeDiagonal)
{
    bool res = true;

    ShapeParam<float> param;

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, -5.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_RHOMBUS;

    res = param.validate();

    ASSERT_EQ(res, true);
}
