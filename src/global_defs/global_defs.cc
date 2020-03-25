/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"

namespace conversions {

float Deg2Rad(float deg) {
  return deg * constants::PIf / 180.0f;
}
double Deg2Rad(double deg) {
  return deg * constants::PI / 180.0;
}
float Rad2Deg(float rad) {
  return rad * 180.0f / constants::PIf;
}
double Rad2Deg(double rad) {
  return rad * 180.0 / constants::PI;
}
float G2Mss(float g) {
  return constants::G_MSSf * g;
}
double G2Mss(double g) {
  return constants::G_MSS * g;
}
float Mss2G(float mss) {
  return mss / constants::G_MSSf;
}
double Mss2G(double mss) {
  return mss / constants::G_MSS;
}
float Psi2Pa(float psi) {
  /* lb to kg*/
  float lb2kg = 0.45359237f;
  /* in to m */
  float in2m = 0.0254f;
  return psi * (lb2kg * constants::G_MSSf) / (in2m * in2m);
}
double Psi2Pa(double psi) {
  /* lb to kg*/
  double lb2kg = 0.45359237;
  /* in to m */
  double in2m = 0.0254;
  return psi * (lb2kg * constants::G_MSS) / (in2m * in2m);
}
float Pa2Psi(float pa) {
  /* lb to kg*/
  float lb2kg = 0.45359237f;
  /* in to m */
  float in2m = 0.0254f;
  return pa * (in2m * in2m) / (lb2kg * constants::G_MSSf);
}
double Pa2Psi(double pa) {
  /* lb to kg*/
  double lb2kg = 0.45359237;
  /* in to m */
  double in2m = 0.0254;
  return pa * (in2m * in2m) / (lb2kg * constants::G_MSS);
}
float Atm2Pa(float atm) {
  return atm * 101325.0f;
}
double Atm2Pa(double atm) {
  return atm * 101325.0;
}
float Pa2Atm(float pa) {
  return pa / 101325.0f;
}
double Pa2Atm(double pa) {
  return pa / 101325.0;
}
float Mbar2Pa(float mbar) {
  return mbar * 100.0f;
}
double Mbar2Pa(double mbar) {
  return mbar * 100.0;
}
float Pa2Mbar(float pa) {
  return pa / 100.0f;
}
double Pa2Mbar(double pa) {
  return pa / 100.0;
}
float InHg2Pa(float inhg) {
  /* mmHg is defined as 133.322387415 Pa */
  static const float inhg2pa = 25.4f * 133.322387415f;
  return inhg * inhg2pa;
}
double InHg2Pa(double inhg) {
  /* mmHg is defined as 133.322387415 Pa */
  static const double inhg2pa = 25.4 * 133.322387415;
  return inhg * inhg2pa;
}
float Pa2InHg(float pa) {
  /* mmHg is defined as 133.322387415 Pa */
  static const float inhg2pa = 25.4f * 133.322387415f;
  return pa / inhg2pa;
}
double Pa2InHg(double pa) {
  /* mmHg is defined as 133.322387415 Pa */
  static const double inhg2pa = 25.4 * 133.322387415;
  return pa / inhg2pa;
}
float C2F(float c) {
  return c * (9.0f / 5.0f) + 32.0f;
}
double C2F(double c) {
  return c * (9.0 / 5.0) + 32.0;
}
float F2C(float f) {
  return (f - 32.0f) * (5.0f / 9.0f);
}
double F2C(double f) {
  return (f - 32.0) * (5.0 / 9.0);
}
float C2K(float c) {
  return c + 273.15f;
}
double C2K(double c) {
  return c + 273.15;
}
float K2C(float k) {
  return k - 273.15f;
}
double K2C(double k) {
  return k - 273.15;
}
float F2R(float f) {
  return f + 459.67f;
}
double F2R(double f) {
  return f + 459.67;
}
float R2F(float r) {
  return r - 459.67f;
}
double R2F(double r) {
  return r - 459.67;
}

}  // namespace conversions
