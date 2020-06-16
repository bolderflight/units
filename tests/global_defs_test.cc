/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) _to_0_to_0 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"
#include "gtest/gtest.h"
#include <math.h>

/* M_to_Ft */
TEST(M_to_Ft, M_to_Ft) {
  EXPECT_FLOAT_EQ(1.0f, conversions::M_to_Ft(0.3048f));
  EXPECT_DOUBLE_EQ(1.0, conversions::M_to_Ft(0.3048));
}
/* Ft_to_M */
TEST(Ft_to_M, Ft_to_M) {
  EXPECT_FLOAT_EQ(0.3048f, conversions::Ft_to_M(1.0f));
  EXPECT_DOUBLE_EQ(0.3048, conversions::Ft_to_M(1.0));
}
/* Deg_to_Rad */
TEST(Deg_to_Rad, Deg_to_Rad) {
  EXPECT_FLOAT_EQ(constants::PIf, conversions::Deg_to_Rad(180.0f));
  EXPECT_DOUBLE_EQ(constants::PI, conversions::Deg_to_Rad(180.0));
}
/* Rad_to_Deg */
TEST(Rad_to_Deg, Rad_to_Deg) {
  EXPECT_FLOAT_EQ(180.0f, conversions::Rad_to_Deg(constants::PIf));
  EXPECT_DOUBLE_EQ(180.0, conversions::Rad_to_Deg(constants::PI));
}
/* G_to_Mps2 */
TEST(G_to_Mps2, G_to_Mps2) {
  EXPECT_FLOAT_EQ(constants::G_MPS2f, conversions::G_to_Mps2(1.0f));
  EXPECT_DOUBLE_EQ(constants::G_MPS2, conversions::G_to_Mps2(1.0));
}
/* Mps2_to_G */
TEST(Mps2_to_G, Mps2_to_G) {
  EXPECT_FLOAT_EQ(1.0f, conversions::Mps2_to_G(constants::G_MPS2f));
  EXPECT_DOUBLE_EQ(1.0, conversions::Mps2_to_G(constants::G_MPS2));
}
/* PSI to Pa */
TEST(Psi_to_Pa, Psi_to_Pa) {
  EXPECT_FLOAT_EQ(6894.757293168361f, conversions::Psi_to_Pa(1.0f));
  EXPECT_DOUBLE_EQ(6894.757293168361, conversions::Psi_to_Pa(1.0));
}
/* Pa to PSI */
TEST(Pa_to_Psi, Pa_to_Psi) {
  EXPECT_FLOAT_EQ(0.0001450377377302092f, conversions::Pa_to_Psi(1.0f));
  EXPECT_DOUBLE_EQ(0.0001450377377302092, conversions::Pa_to_Psi(1.0));
}
/* ATM to Pa */
TEST(Atm_to_Pa, Atm_to_Pa) {
  EXPECT_FLOAT_EQ(101325.0f, conversions::Atm_to_Pa(1.0f));
  EXPECT_DOUBLE_EQ(101325.0, conversions::Atm_to_Pa(1.0));
}
/* Pa to ATM */
TEST(Pa_to_Atm, Pa_to_Atm) {
  EXPECT_FLOAT_EQ(1.0f, conversions::Pa_to_Atm(101325.0f));
  EXPECT_DOUBLE_EQ(1.0, conversions::Pa_to_Atm(101325.0));
}
/* mbar to Pa */
TEST(Mbar_to_Pa, Mbar_to_Pa) {
  EXPECT_FLOAT_EQ(100.0f, conversions::Mbar_to_Pa(1.0f));
  EXPECT_DOUBLE_EQ(100.0, conversions::Mbar_to_Pa(1.0));
}
/* Pa to mbar */
TEST(Pa_to_Mbar, Pa_to_Mbar) {
  EXPECT_FLOAT_EQ(0.01f, conversions::Pa_to_Mbar(1.0f));
  EXPECT_DOUBLE_EQ(0.01, conversions::Pa_to_Mbar(1.0));
}
/* inHg to Pa */
TEST(InHg_to_Pa, InHg_to_Pa) {
  EXPECT_FLOAT_EQ(3386.388640341f, conversions::InHg_to_Pa(1.0f));
  EXPECT_DOUBLE_EQ(3386.388640341, conversions::InHg_to_Pa(1.0));
}
/* Pa to inHg */
TEST(Pa_to_InHg, Pa_to_InHg) {
  EXPECT_FLOAT_EQ(0.0002952998330101009f, conversions::Pa_to_InHg(1.0f));
  EXPECT_DOUBLE_EQ(0.0002952998330101009, conversions::Pa_to_InHg(1.0));
}
/* C to F */
TEST(C_to_F, C_to_F) {
  EXPECT_FLOAT_EQ(50.0f, conversions::C_to_F(10.0f));
  EXPECT_DOUBLE_EQ(50.0, conversions::C_to_F(10.0));
}
/* F to C */
TEST(F_to_C, F_to_C) {
  EXPECT_FLOAT_EQ(10.0f, conversions::F_to_C(50.0f));
  EXPECT_DOUBLE_EQ(10.0, conversions::F_to_C(50.0));
}
/* C to K */
TEST(C_to_K, C_to_K) {
  EXPECT_FLOAT_EQ(283.15f, conversions::C_to_K(10.0f));
  EXPECT_DOUBLE_EQ(283.15, conversions::C_to_K(10.0));
}
/* K to C */
TEST(K_to_C, K_to_C) {
  EXPECT_FLOAT_EQ(-223.15f, conversions::K_to_C(50.0f));
  EXPECT_DOUBLE_EQ(-223.15, conversions::K_to_C(50.0));
}
/* F to R */
TEST(F_to_R, F_to_R) {
  EXPECT_FLOAT_EQ(509.67f, conversions::F_to_R(50.0f));
  EXPECT_DOUBLE_EQ(509.67, conversions::F_to_R(50.0));
}
/* R to F */
TEST(R_to_F, R_to_F) {
  EXPECT_FLOAT_EQ(-409.67f, conversions::R_to_F(50.0f));
  EXPECT_DOUBLE_EQ(-409.67, conversions::R_to_F(50.0));
}
