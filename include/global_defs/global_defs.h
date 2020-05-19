/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
#define INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_

#include <stdlib.h>
#include <inttypes.h>

/* Constants */
namespace constants {
static constexpr float G_MSSf = 9.80665f;
static constexpr double G_MSS = 9.80665;
static constexpr float PIf = 3.14159265358979323846f;
static constexpr double PI = 3.14159265358979323846;
}  // namespace constants

/* Conversions */
namespace conversions {
/* m to ft */
float M2Ft(float m);
double M2Ft(double m);
/* ft to m */
float Ft2M(float ft);
double Ft2M(double ft);
/* Deg to Rad */
float Deg2Rad(float deg);
double Deg2Rad(double deg);
/* Rad to Deg */
float Rad2Deg(float rad);
double Rad2Deg(double rad);
/* G to m/s/s */
float G2Mss(float g);
double G2Mss(double g);
/* m/s/s to G */
float Mss2G(float mss);
double Mss2G(double mss);
/* PSI to Pa */
float Psi2Pa(float psi);
double Psi2Pa(double psi);
/* Pa to PSI */
float Pa2Psi(float pa);
double Pa2Psi(double pa);
/* atm to Pa */
float Atm2Pa(float atm);
double Atm2Pa(double atm);
/* Pa to atm */
float Pa2Atm(float pa);
double Pa2Atm(double pa);
/* mbar to Pa */
float Mbar2Pa(float mbar);
double Mbar2Pa(double mbar);
/* Pa to mbar */
float Pa2Mbar(float pa);
double Pa2Mbar(double pa);
/* inHg to Pa */
float InHg2Pa(float inhg);
double InHg2Pa(double inhg);
/* Pa to inHg */
float Pa2InHg(float pa);
double Pa2InHg(double pa);
/* C to F */
float C2F(float c);
double C2F(double c);
/* F to C */
float F2C(float f);
double F2C(double f);
/* C to K */
float C2K(float c);
double C2K(double c);
/* K to C */
float K2C(float k);
double K2C(double k);
/* F to R */
float F2R(float f);
double F2R(double f);
/* R to F */
float R2F(float r);
double R2F(double r);
}  // namespace conversions

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
