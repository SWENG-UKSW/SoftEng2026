#include <gtest/gtest.h>
#include "Hexagon.h"
#include "ShapeParam.h"
#include "ShapeResultIndex.h"
#include "ShapeParamIndex.h"
#include <cmath>
#include <stdexcept>

TEST(HexagonTest, HexagonBasic)
{
    ShapeParam<double> param;
    // Ustawiamy bok a = 10.0
    param.set_attrib(PARAM_WIDTH, 10.0);

    Hexagon<double> hex(param);
    auto result = hex.compute();

    // Obliczenia:
    // Pole: (3 * sqrt(3) / 2) * 10^2 = 1.5 * 1.73205 * 100 = 259.807621...
    // Obwód: 6 * 10 = 60.0

    // WA¯NE: Dla double u¿ywamy EXPECT_NEAR z tolerancj¹ (np. 0.0001)
    EXPECT_NEAR(result.get_attrib(RESULT_AREA), 259.8076, 0.001);
    EXPECT_NEAR(result.get_attrib(RESULT_PERIMETER), 60.0, 0.001);
}

// Test dla wartoœci zero
TEST(HexagonTest, HexagonZero)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_WIDTH, 0.0);

    Hexagon<double> hex(param);
    auto result = hex.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_AREA), 0.0);
    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_PERIMETER), 0.0);
}

// Test dla wartoœci ujemnych (sprawdzenie czy rzuca wyj¹tek)
TEST(HexagonTest, HexagonNegative)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_WIDTH, -5.0);

    Hexagon<double> hex(param);

    // Jeœli w Hexagon.h doda³eœ rzucanie wyj¹tku, ten test to sprawdzi
    EXPECT_THROW(hex.compute(), std::invalid_argument);
}