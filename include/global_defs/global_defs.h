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

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
