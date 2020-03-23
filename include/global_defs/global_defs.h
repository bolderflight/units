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
static constexpr float G_MSSf = 9.80665f;
static constexpr double G_MSS = 9.80665;
static constexpr float PIf = 3.14159265358979323846f;
static constexpr double PI = 3.14159265358979323846;

/* Conversions */
static constexpr float DEG2RADf = PIf / 180.0f;
static constexpr double DEG2RAD = PI / 180.0;
static constexpr float RAD2DEGf = 180.0f / PIf;
static constexpr double RAD2DEG = 180.0 / PI;
static constexpr float G2MSSf = G_MSSf;
static constexpr double G2MSS = G_MSS;
static constexpr float MSS2Gf = 1.0f / G_MSSf;
static constexpr double MSS2G = 1.0 / G_MSS;
static constexpr float LB2KGf = 0.45359237f; // lb to kg, defined
static constexpr float IN2M = 0.0254; // inch to meter, defined
static constexpr float PSI2PAf = (LB2KGf * G_MSSf) / (IN2M * IN2M);
static constexpr float PA2PSIf = (IN2M * IN2M) / (LB2KGf * G_MSSf);
static constexpr float ATM2PAf = 101325.0f;
static constexpr float PA2ATMf = 1.0f / 101325.0f;
static constexpr float MBAR2PAf = 100.0f;
static constexpr float PA2MBARf = 1.0f / 100.0f;
static constexpr float INHG2PAf = 3386.389f;
static constexpr float PA2INHGf = 1.0f / 3386.389f;

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
