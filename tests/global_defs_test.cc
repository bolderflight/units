/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"
#include "gtest/gtest.h"
#include <math.h>

/* M2Ft */
TEST(M2Ft, M2Ft) {
  EXPECT_FLOAT_EQ(1.0f, conversions::M2Ft(0.3048f));
  EXPECT_DOUBLE_EQ(1.0, conversions::M2Ft(0.3048));
}
/* Ft2M */
TEST(Ft2M, Ft2M) {
  EXPECT_FLOAT_EQ(0.3048f, conversions::Ft2M(1.0f));
  EXPECT_DOUBLE_EQ(0.3048, conversions::Ft2M(1.0));
}
/* Deg2Rad */
TEST(Deg2Rad, Deg2Rad) {
  EXPECT_FLOAT_EQ(constants::PIf, conversions::Deg2Rad(180.0f));
  EXPECT_DOUBLE_EQ(constants::PI, conversions::Deg2Rad(180.0));
}
/* Rad2Deg */
TEST(Rad2Deg, Rad2Deg) {
  EXPECT_FLOAT_EQ(180.0f, conversions::Rad2Deg(constants::PIf));
  EXPECT_DOUBLE_EQ(180.0, conversions::Rad2Deg(constants::PI));
}
/* G2Mss */
TEST(G2Mss, G2Mss) {
  EXPECT_FLOAT_EQ(constants::G_MSSf, conversions::G2Mss(1.0f));
  EXPECT_DOUBLE_EQ(constants::G_MSS, conversions::G2Mss(1.0));
}
/* Mss2G */
TEST(Mss2G, Mss2G) {
  EXPECT_FLOAT_EQ(1.0f, conversions::Mss2G(constants::G_MSSf));
  EXPECT_DOUBLE_EQ(1.0, conversions::Mss2G(constants::G_MSS));
}
/* PSI to Pa */
TEST(Psi2Pa, Psi2Pa) {
  EXPECT_FLOAT_EQ(6894.757293168361f, conversions::Psi2Pa(1.0f));
  EXPECT_DOUBLE_EQ(6894.757293168361, conversions::Psi2Pa(1.0));
}
/* Pa to PSI */
TEST(Pa2Psi, Pa2Psi) {
  EXPECT_FLOAT_EQ(0.0001450377377302092f, conversions::Pa2Psi(1.0f));
  EXPECT_DOUBLE_EQ(0.0001450377377302092, conversions::Pa2Psi(1.0));
}
/* ATM to Pa */
TEST(Atm2Pa, Atm2Pa) {
  EXPECT_FLOAT_EQ(101325.0f, conversions::Atm2Pa(1.0f));
  EXPECT_DOUBLE_EQ(101325.0, conversions::Atm2Pa(1.0));
}
/* Pa to ATM */
TEST(Pa2Atm, Pa2Atm) {
  EXPECT_FLOAT_EQ(1.0f, conversions::Pa2Atm(101325.0f));
  EXPECT_DOUBLE_EQ(1.0, conversions::Pa2Atm(101325.0));
}
/* mbar to Pa */
TEST(Mbar2Pa, Mbar2Pa) {
  EXPECT_FLOAT_EQ(100.0f, conversions::Mbar2Pa(1.0f));
  EXPECT_DOUBLE_EQ(100.0, conversions::Mbar2Pa(1.0));
}
/* Pa to mbar */
TEST(Pa2Mbar, Pa2Mbar) {
  EXPECT_FLOAT_EQ(0.01f, conversions::Pa2Mbar(1.0f));
  EXPECT_DOUBLE_EQ(0.01, conversions::Pa2Mbar(1.0));
}
/* inHg to Pa */
TEST(InHg2Pa, InHg2Pa) {
  EXPECT_FLOAT_EQ(3386.388640341f, conversions::InHg2Pa(1.0f));
  EXPECT_DOUBLE_EQ(3386.388640341, conversions::InHg2Pa(1.0));
}
/* Pa to inHg */
TEST(Pa2InHg, Pa2InHg) {
  EXPECT_FLOAT_EQ(0.0002952998330101009f, conversions::Pa2InHg(1.0f));
  EXPECT_DOUBLE_EQ(0.0002952998330101009, conversions::Pa2InHg(1.0));
}
/* C to F */
TEST(C2F, C2F) {
  EXPECT_FLOAT_EQ(50.0f, conversions::C2F(10.0f));
  EXPECT_DOUBLE_EQ(50.0, conversions::C2F(10.0));
}
/* F to C */
TEST(F2C, F2C) {
  EXPECT_FLOAT_EQ(10.0f, conversions::F2C(50.0f));
  EXPECT_DOUBLE_EQ(10.0, conversions::F2C(50.0));
}
/* C to K */
TEST(C2K, C2K) {
  EXPECT_FLOAT_EQ(283.15f, conversions::C2K(10.0f));
  EXPECT_DOUBLE_EQ(283.15, conversions::C2K(10.0));
}
/* K to C */
TEST(K2C, K2C) {
  EXPECT_FLOAT_EQ(-223.15f, conversions::K2C(50.0f));
  EXPECT_DOUBLE_EQ(-223.15, conversions::K2C(50.0));
}
/* F to R */
TEST(F2R, F2R) {
  EXPECT_FLOAT_EQ(509.67f, conversions::F2R(50.0f));
  EXPECT_DOUBLE_EQ(509.67, conversions::F2R(50.0));
}
/* R to F */
TEST(R2F, R2F) {
  EXPECT_FLOAT_EQ(-409.67f, conversions::R2F(50.0f));
  EXPECT_DOUBLE_EQ(-409.67, conversions::R2F(50.0));
}
