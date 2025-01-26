#include <gtest/gtest.h>
#include "../src/Kalkulator.h" 
#include "../src/Matematyka.h"  
#include "../src/Konwersja.h"   

TEST(KonwersjaGTest, Binary) {
    Konwersja konwersja;
    EXPECT_EQ(konwersja.Binary(0), "0");
    EXPECT_EQ(konwersja.Binary(10), "1010");
    EXPECT_EQ(konwersja.Binary(255), "11111111");
}

TEST(KonwersjaGTest, Octal) {
    Konwersja konwersja;
    EXPECT_EQ(konwersja.Octal(0), "0");
    EXPECT_EQ(konwersja.Octal(10), "12");
    EXPECT_EQ(konwersja.Octal(255), "377");
}

TEST(KonwersjaGTest, Hexadecimal) {
    Konwersja konwersja;
    EXPECT_EQ(konwersja.Hexadecimal(0), "0");
    EXPECT_EQ(konwersja.Hexadecimal(10), "A");
    EXPECT_EQ(konwersja.Hexadecimal(255), "FF");
}

TEST(MatematykaGTest, Dodaj) {
    Matematyka matematyka;
    EXPECT_FLOAT_EQ(matematyka.dodaj(2.0, 3.0), 5.0);
    EXPECT_FLOAT_EQ(matematyka.dodaj(-1.0, 1.0), 0.0);
}

TEST(MatematykaGTest, Odejmij) {
    Matematyka matematyka;
    EXPECT_FLOAT_EQ(matematyka.odejmij(5.0, 3.0), -2.0);
    EXPECT_FLOAT_EQ(matematyka.odejmij(3.0, 5.0), 2.0);
}

TEST(MatematykaGTest, Pomnoz) {
    Matematyka matematyka;
    EXPECT_FLOAT_EQ(matematyka.pomnoz(2.0, 3.0), 6.0);
    EXPECT_FLOAT_EQ(matematyka.pomnoz(-1.0, 1.0), -1.0);
}

TEST(MatematykaGTest, Podziel) {
    Matematyka matematyka;
    EXPECT_FLOAT_EQ(matematyka.podziel(2.0, 6.0), 3.0);
    EXPECT_THROW(matematyka.podziel(0.0, 2.0), std::invalid_argument);
}

TEST(MatematykaGTest, Pierwiastek) {
    Matematyka matematyka;
    EXPECT_FLOAT_EQ(matematyka.pierwiastek(4.0), 2.0); 
    EXPECT_THROW(matematyka.pierwiastek(-1.0), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
