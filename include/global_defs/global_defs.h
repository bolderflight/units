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
static constexpr float G_MPS2f = 9.80665f;
static constexpr double G_MPS2 = 9.80665;
static constexpr float PIf = 3.14159265358979323846f;
static constexpr double PI = 3.14159265358979323846;
}  // namespace constants

/* Conversions */
namespace conversions {
/* m to ft */
float M_to_Ft(float m);
double M_to_Ft(double m);
/* ft to m */
float Ft_to_M(float ft);
double Ft_to_M(double ft);
/* Deg to Rad */
float Deg_to_Rad(float deg);
double Deg_to_Rad(double deg);
/* Rad to Deg */
float Rad_to_Deg(float rad);
double Rad_to_Deg(double rad);
/* G to m/s/s */
float G_to_Mps2(float g);
double G_to_Mps2(double g);
/* m/s/s to G */
float Mps2_to_G(float mps2);
double Mps2_to_G(double mps2);
/* PSI to Pa */
float Psi_to_Pa(float psi);
double Psi_to_Pa(double psi);
/* Pa to PSI */
float Pa_to_Psi(float pa);
double Pa_to_Psi(double pa);
/* atm to Pa */
float Atm_to_Pa(float atm);
double Atm_to_Pa(double atm);
/* Pa to atm */
float Pa_to_Atm(float pa);
double Pa_to_Atm(double pa);
/* mbar to Pa */
float Mbar_to_Pa(float mbar);
double Mbar_to_Pa(double mbar);
/* Pa to mbar */
float Pa_to_Mbar(float pa);
double Pa_to_Mbar(double pa);
/* inHg to Pa */
float InHg_to_Pa(float inhg);
double InHg_to_Pa(double inhg);
/* Pa to inHg */
float Pa_to_InHg(float pa);
double Pa_to_InHg(double pa);
/* C to F */
float C_to_F(float c);
double C_to_F(double c);
/* F to C */
float F_to_C(float f);
double F_to_C(double f);
/* C to K */
float C_to_K(float c);
double C_to_K(double c);
/* K to C */
float K_to_C(float k);
double K_to_C(double k);
/* F to R */
float F_to_R(float f);
double F_to_R(double f);
/* R to F */
float R_to_F(float r);
double R_to_F(double r);
}  // namespace conversions

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
