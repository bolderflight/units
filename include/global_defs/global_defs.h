/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#ifndef INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
#define INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_

#include <cstdint>
#include <type_traits>

/* Constants */
namespace constants {
template<typename T>
static constexpr T G_MPS2 = static_cast<T>(9.80665);
template<typename T>
static constexpr T PI = static_cast<T>(3.14159265358979323846);
}  // namespace constants

/* Conversions */
namespace conversions {
/* m to ft */
template<typename T>
T M_to_Ft(T m) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return m / static_cast<T>(0.3048);}
/* ft to m */
template<typename T>
T Ft_to_M(T ft) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return ft * static_cast<T>(0.3048);}
/* Deg to Rad */
template<typename T>
T Deg_to_Rad(T deg) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return deg * constants::PI<T> / static_cast<T>(180);}
/* Rad to Deg */
template<typename T>
T Rad_to_Deg(T rad) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return rad * static_cast<T>(180) / constants::PI<T>;}
/* G to m/s/s */
template<typename T>
T G_to_Mps2(T g) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return constants::G_MPS2<T> * g;}
/* m/s/s to G */
template<typename T>
T Mps2_to_G(T mps2) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return mps2 / constants::G_MPS2<T>;}
/* PSI to Pa */
template<typename T>
T Psi_to_Pa(T psi) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* lb to kg*/
  T lb2kg = static_cast<T>(0.45359237);
  /* in to m */
  T in2m = static_cast<T>(0.0254);
  return psi * (lb2kg * constants::G_MPS2<T>) / (in2m * in2m);
}
/* Pa to PSI */
template<typename T>
T Pa_to_Psi(T pa) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* lb to kg*/
  T lb2kg = static_cast<T>(0.45359237);
  /* in to m */
  T in2m = static_cast<T>(0.0254);
  return pa * (in2m * in2m) / (lb2kg * constants::G_MPS2<T>);
}
/* atm to Pa */
template<typename T>
T Atm_to_Pa(T atm) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return atm * static_cast<T>(101325.0);}
/* Pa to atm */
template<typename T>
T Pa_to_Atm(T pa) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return pa / static_cast<T>(101325.0);}
/* mbar to Pa */
template<typename T>
T Mbar_to_Pa(T mbar) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return mbar * static_cast<T>(100.0);}
/* Pa to mbar */
template<typename T>
T Pa_to_Mbar(T pa) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return pa / static_cast<T>(100.0);}
/* inHg to Pa */
template<typename T>
T InHg_to_Pa(T inhg) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* mmHg is defined as 133.322387415 Pa */
  static constexpr T inhg2pa = static_cast<T>(25.4) * static_cast<T>(133.322387415);
  return inhg * inhg2pa;
}
/* Pa to inHg */
template<typename T>
T Pa_to_InHg(T pa) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* mmHg is defined as 133.322387415 Pa */
  static constexpr T inhg2pa = static_cast<T>(25.4) * static_cast<T>(133.322387415);
  return pa / inhg2pa;
}
/* C to F */
template<typename T>
T C_to_F(T c) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return c * static_cast<T>(9) / static_cast<T>(5) + static_cast<T>(32);}
/* F to C */
template<typename T>
T F_to_C(T f) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return (f - static_cast<T>(32)) * static_cast<T>(5) / static_cast<T>(9);}
/* C to K */
template<typename T>
T C_to_K(T c) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return c + static_cast<T>(273.15);}
/* K to C */
template<typename T>
T K_to_C(T k) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return k - static_cast<T>(273.15);}
/* F to R */
template<typename T>
T F_to_R(T f) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return f + static_cast<T>(459.67);}
/* R to F */
template<typename T>
T R_to_F(T r) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return r - static_cast<T>(459.67);}
/* Mps to Kt */
template<typename T>
T Mps_to_Kt(T mps) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* 1852m in a nm */
  return mps * static_cast<T>(3600) / static_cast<T>(1852);
}
/* Kt to Mps */
template<typename T>
T Kt_to_Mps(T kt) {
  static_assert(std::is_floating_point<T>::value, "Only floating point types supported");
  /* 1852m in a nm */
  return kt * static_cast<T>(1852) / static_cast<T>(3600);
}
/* Kg to Slug */
template<typename T>
T Kg_to_Slug(T kg) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return kg / static_cast<T>(14.59390);}
/* Slug to Kg */
template<typename T>
T Slug_to_Kg(T slug) {static_assert(std::is_floating_point<T>::value, "Only floating point types supported"); return slug * static_cast<T>(14.59390);}
}  // namespace conversions

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
