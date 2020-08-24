/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) _to_0_to_0 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"
#include <iostream>

int main() {
  std::cout << global::conversions::M_to_Ft(0.3048) << std::endl;  // 1.0
  std::cout << global::conversions::Ft_to_M(1.0) << std::endl;  // 0.3048
  std::cout << global::conversions::Rad_to_Deg(global::constants::PI<float>) << std::endl;  // 180.0
  std::cout << global::conversions::Deg_to_Rad(180.0) << std::endl;  // 3.14
  std::cout << global::conversions::G_to_Mps2(1.0) << std::endl;  // 9.80665
  std::cout << global::conversions::Mps2_to_G(9.80665) << std::endl;  // 1.0
  std::cout << global::conversions::Psi_to_Pa(1.0f) << std::endl;  // 6894.757293168361
  std::cout << global::conversions::Pa_to_Psi(1.0f) << std::endl;  // 0.0001450377377302092f
  std::cout << global::conversions::Atm_to_Pa(1.0f) << std::endl;  // 101325.0f
  std::cout << global::conversions::Pa_to_Atm(101325.0) << std::endl;  // 1.0
  std::cout << global::conversions::Mbar_to_Pa(1.0) << std::endl;  // 100.0
  std::cout << global::conversions::Pa_to_Mbar(1.0) << std::endl;  // 0.01
  std::cout << global::conversions::InHg_to_Pa(1.0f) << std::endl;  // 3386.388640341f
  std::cout << global::conversions::Pa_to_InHg(1.0f) << std::endl;  // 0.0002952998330101009f
  std::cout << global::conversions::C_to_F(10.0f) << std::endl;  // 50.0f
  std::cout << global::conversions::F_to_C(50.0f) << std::endl;  // 10.0f
  std::cout << global::conversions::C_to_K(10.0) << std::endl;  // 283.15
  std::cout << global::conversions::K_to_C(50.0) << std::endl;  // -223.15
  std::cout << global::conversions::F_to_R(50.0) << std::endl;  // 509.67
  std::cout << global::conversions::R_to_F(50.0) << std::endl;  // -409.67
  std::cout << global::conversions::Mps_to_Kt(30.0) << std::endl;  // 58.3153
  std::cout << global::conversions::Kt_to_Mps(120.0) << std::endl;  // 61.7333
  std::cout << global::conversions::Kg_to_Slug(120.0) << std::endl;  // 8.22261
  std::cout << global::conversions::Slug_to_Kg(120.0) << std::endl;  // 1751.27
}
