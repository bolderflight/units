/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "global_defs/global_defs.h"
#include <iostream>

int main() {
  std::cout << conversions::M2Ft(0.3048) << std::endl; // 1.0
  std::cout << conversions::Ft2M(1.0) << std::endl; // 0.3048
  std::cout << conversions::Rad2Deg(constants::PI) << std::endl; // 180.0
  std::cout << conversions::Deg2Rad(180.0) << std::endl; // 3.14
  std::cout << conversions::G2Mss(1.0) << std::endl; // 9.80665
  std::cout << conversions::Mss2G(9.80665) << std::endl; // 1.0
  std::cout << conversions::Psi2Pa(1.0f) << std::endl; // 6894.757293168361
  std::cout << conversions::Pa2Psi(1.0f) << std::endl; // 0.0001450377377302092f
  std::cout << conversions::Atm2Pa(1.0f) << std::endl; // 101325.0f
  std::cout << conversions::Pa2Atm(101325.0) << std::endl; // 1.0
  std::cout << conversions::Mbar2Pa(1.0) << std::endl; // 100.0
  std::cout << conversions::Pa2Mbar(1.0) << std::endl; // 0.01
  std::cout << conversions::InHg2Pa(1.0f) << std::endl; // 3386.388640341f
  std::cout << conversions::Pa2InHg(1.0f) << std::endl; // 0.0002952998330101009f
  std::cout << conversions::C2F(10.0f) << std::endl; // 50.0f
  std::cout << conversions::F2C(50.0f) << std::endl; // 10.0f
  std::cout << conversions::C2K(10.0) << std::endl; // 283.15
  std::cout << conversions::K2C(50.0) << std::endl; // -223.15
  std::cout << conversions::F2R(50.0) << std::endl; // 509.67
  std::cout << conversions::R2F(50.0) << std::endl; // -409.67
}