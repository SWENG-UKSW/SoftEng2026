#include <gtest/gtest.h>
#include <memory>
#include <chrono> // Biblioteka do mierzenia czasu (STOPER)
#include "ShapeFactory.h"
#include "Cone.h" // Pod³¹czamy nasz nowy Sto¿ek

// 1. Twój stary test - odkomentowa³em w nim liczenie, ¿eby dzia³a³ poprawnie
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

    // USUNIÊTO #if 0 - teraz test faktycznie liczy pole ko³a
    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    ASSERT_NE(area, 0.f);

    shape.reset(nullptr);
    ASSERT_EQ(shape.get(), nullptr);
}

// 2. NOWY TEST: Wydajnoœæ + Sto¿ek + Typ Double (Zaliczamy 3 punkty z
// prezentacji naraz!)
TEST(PerformanceTest, Cone100IterationsUnder1ms)
{
    // U¿ywamy double (inny typ danych)
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 5.0);
    param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 10.0);

    // U¿ywamy std::make_unique (bezpieczne wskaŸniki = zero wycieków pamiêci)
    auto cone = std::make_unique<Cone<double>>(param);

    // Odpalamy stoper!
    auto start_time = std::chrono::high_resolution_clock::now();

    // Pêtla 100 iteracji (wymóg prowadz¹cego)
    for (int i = 0; i < 100; ++i)
    {
        auto result = cone->compute();
    }

    // Zatrzymujemy stoper!
    auto end_time = std::chrono::high_resolution_clock::now();

    // Liczymy ile mikrosekund to zajê³o
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
                        end_time - start_time)
                        .count();

    // 1 milisekunda to 1000 mikrosekund. Sprawdzamy, czy zmieœciliœmy siê w
    // czasie.
    EXPECT_LT(duration, 1000) << "Obliczenia 100 iteracji przekroczy³y 1 ms!";
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}