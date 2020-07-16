/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) _to_0_to_0 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"
#include <iostream>

int main() {
  std::cout << conversions::M_to_Ft(0.3048) << std::endl;  // 1.0
  std::cout << conversions::Ft_to_M(1.0) << std::endl;  // 0.3048
  std::cout << conversions::Rad_to_Deg(constants::PI<float>) << std::endl;  // 180.0
  std::cout << conversions::Deg_to_Rad(180.0) << std::endl;  // 3.14
  std::cout << conversions::G_to_Mps2(1.0) << std::endl;  // 9.80665
  std::cout << conversions::Mps2_to_G(9.80665) << std::endl;  // 1.0
  std::cout << conversions::Psi_to_Pa(1.0f) << std::endl;  // 6894.757293168361
  std::cout << conversions::Pa_to_Psi(1.0f) << std::endl;
    // 0.0001450377377302092f
  std::cout << conversions::Atm_to_Pa(1.0f) << std::endl;  // 101325.0f
  std::cout << conversions::Pa_to_Atm(101325.0) << std::endl;  // 1.0
  std::cout << conversions::Mbar_to_Pa(1.0) << std::endl;  // 100.0
  std::cout << conversions::Pa_to_Mbar(1.0) << std::endl;  // 0.01
  std::cout << conversions::InHg_to_Pa(1.0f) << std::endl;  // 3386.388640341f
  std::cout << conversions::Pa_to_InHg(1.0f) << std::endl;
    // 0.0002952998330101009f
  std::cout << conversions::C_to_F(10.0f) << std::endl;  // 50.0f
  std::cout << conversions::F_to_C(50.0f) << std::endl;  // 10.0f
  std::cout << conversions::C_to_K(10.0) << std::endl;  // 283.15
  std::cout << conversions::K_to_C(50.0) << std::endl;  // -223.15
  std::cout << conversions::F_to_R(50.0) << std::endl;  // 509.67
  std::cout << conversions::R_to_F(50.0) << std::endl;  // -409.67
  std::cout << conversions::Mps_to_Kt(30.0) << std::endl;  // 58.3153
  std::cout << conversions::Kt_to_Mps(120.0) << std::endl;  // 61.7333
  std::cout << conversions::Kg_to_Slug(120.0) << std::endl;  // 8.22261
  std::cout << conversions::Slug_to_Kg(120.0) << std::endl;  // 1751.27
}
