/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"

namespace conversions {

float M_to_Ft(float m) {
  return m / 0.3048f;
}
double M_to_Ft(double m) {
  return m / 0.3048;
}
float Ft_to_M(float ft) {
  return ft * 0.3048f;
}
double Ft_to_M(double ft) {
  return ft * 0.3048;
}
float Deg_to_Rad(float deg) {
  return deg * constants::PIf / 180.0f;
}
double Deg_to_Rad(double deg) {
  return deg * constants::PI / 180.0;
}
float Rad_to_Deg(float rad) {
  return rad * 180.0f / constants::PIf;
}
double Rad_to_Deg(double rad) {
  return rad * 180.0 / constants::PI;
}
float G_to_Mps2(float g) {
  return constants::G_MPS2f * g;
}
double G_to_Mps2(double g) {
  return constants::G_MPS2 * g;
}
float Mps2_to_G(float mps2) {
  return mps2 / constants::G_MPS2f;
}
double Mps2_to_G(double mps2) {
  return mps2 / constants::G_MPS2;
}
float Psi_to_Pa(float psi) {
  /* lb to kg*/
  float lb2kg = 0.45359237f;
  /* in to m */
  float in2m = 0.0254f;
  return psi * (lb2kg * constants::G_MPS2f) / (in2m * in2m);
}
double Psi_to_Pa(double psi) {
  /* lb to kg*/
  double lb2kg = 0.45359237;
  /* in to m */
  double in2m = 0.0254;
  return psi * (lb2kg * constants::G_MPS2) / (in2m * in2m);
}
float Pa_to_Psi(float pa) {
  /* lb to kg*/
  float lb2kg = 0.45359237f;
  /* in to m */
  float in2m = 0.0254f;
  return pa * (in2m * in2m) / (lb2kg * constants::G_MPS2f);
}
double Pa_to_Psi(double pa) {
  /* lb to kg*/
  double lb2kg = 0.45359237;
  /* in to m */
  double in2m = 0.0254;
  return pa * (in2m * in2m) / (lb2kg * constants::G_MPS2);
}
float Atm_to_Pa(float atm) {
  return atm * 101325.0f;
}
double Atm_to_Pa(double atm) {
  return atm * 101325.0;
}
float Pa_to_Atm(float pa) {
  return pa / 101325.0f;
}
double Pa_to_Atm(double pa) {
  return pa / 101325.0;
}
float Mbar_to_Pa(float mbar) {
  return mbar * 100.0f;
}
double Mbar_to_Pa(double mbar) {
  return mbar * 100.0;
}
float Pa_to_Mbar(float pa) {
  return pa / 100.0f;
}
double Pa_to_Mbar(double pa) {
  return pa / 100.0;
}
float InHg_to_Pa(float inhg) {
  /* mmHg is defined as 133.322387415 Pa */
  static const float inhg2pa = 25.4f * 133.322387415f;
  return inhg * inhg2pa;
}
double InHg_to_Pa(double inhg) {
  /* mmHg is defined as 133.322387415 Pa */
  static const double inhg2pa = 25.4 * 133.322387415;
  return inhg * inhg2pa;
}
float Pa_to_InHg(float pa) {
  /* mmHg is defined as 133.322387415 Pa */
  static const float inhg2pa = 25.4f * 133.322387415f;
  return pa / inhg2pa;
}
double Pa_to_InHg(double pa) {
  /* mmHg is defined as 133.322387415 Pa */
  static const double inhg2pa = 25.4 * 133.322387415;
  return pa / inhg2pa;
}
float C_to_F(float c) {
  return c * (9.0f / 5.0f) + 32.0f;
}
double C_to_F(double c) {
  return c * (9.0 / 5.0) + 32.0;
}
float F_to_C(float f) {
  return (f - 32.0f) * (5.0f / 9.0f);
}
double F_to_C(double f) {
  return (f - 32.0) * (5.0 / 9.0);
}
float C_to_K(float c) {
  return c + 273.15f;
}
double C_to_K(double c) {
  return c + 273.15;
}
float K_to_C(float k) {
  return k - 273.15f;
}
double K_to_C(double k) {
  return k - 273.15;
}
float F_to_R(float f) {
  return f + 459.67f;
}
double F_to_R(double f) {
  return f + 459.67;
}
float R_to_F(float r) {
  return r - 459.67f;
}
double R_to_F(double r) {
  return r - 459.67;
}
float Mps_to_Kt(float mps) {
  /* 1852m in a nm */
  return mps * 3600.0f / 1852.0f;
}
double Mps_to_Kt(double mps) {
  /* 1852m in a nm */
  return mps * 3600.0 / 1852.0;
}
float Kt_to_Mps(float kt) {
  /* 1852m in a nm */
  return kt * 1852.0f / 3600.0f;
}
double Kt_to_Mps(double kt) {
  /* 1852m in a nm */
  return kt * 1852.0 / 3600.0;
}
float Kg_to_Slug(float kg) {
  return kg / 14.59390f;
}
double Kg_to_Slug(double kg) {
  return kg / 14.59390;
}
float Slug_to_Kg(float slug) {
  return slug * 14.59390f;
}
double Slug_to_Kg(double slug) {
  return slug * 14.59390;
}

}  // namespace conversions
