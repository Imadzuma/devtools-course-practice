// Copyright 2018 Mezina Margarita

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Mezina_Margarita_ComplexNumber, Can_Create_Complex_Number) {
    EXPECT_NO_THROW(ComplexNumber cn(3, 4));
}

TEST(Mezina_Margarita_ComplexNumber, Can_Get_Real_Number) {
    ComplexNumber cn(3, 4);
    EXPECT_EQ(cn.getRe(), 3);
}

TEST(Mezina_Margarita_ComplexNumber, Can_Get_Imaginary_Number) {
    ComplexNumber cn(3, 4);
    EXPECT_EQ(cn.getIm(), 4);
}

TEST(Mezina_Margarita_ComplexNumber, Can_Plus_Number) {
    ComplexNumber cn1(3, 4);
    ComplexNumber cn2(-1, -2);
    ComplexNumber cn3(2, 2);
    EXPECT_EQ(cn3, cn1+cn2);
}

TEST(Mezina_Margarita_ComplexNumber, Can_Minus_Number) {
    ComplexNumber cn1(3, 4);
    ComplexNumber cn2(-1, -2);
    ComplexNumber cn3(4, 6);
    EXPECT_EQ(cn3, cn1 - cn2);
}
