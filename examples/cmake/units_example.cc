/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "units.h"
#include <iostream>

int main() {
  /* convlength */
  std::cout << "100 feet to meters: " << bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::M) << std::endl;
  std::cout << "100 feet to kilometers: " << bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::KM) << std::endl;
  std::cout << "100 feet to inches: " << bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::IN) << std::endl;
  std::cout << "100 feet to miles: " << bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::MI) << std::endl;
  std::cout << "100 feet to nautical miles: " << bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::NAUT_MI) << std::endl;
  /* convvel */
  std::cout << "100 ft/s to m/s: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPS) << std::endl;
  std::cout << "100 ft/s to km/s: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPS) << std::endl;
  std::cout << "100 ft/s to in/s: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::IPS) << std::endl;
  std::cout << "100 ft/s to km/h: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPH) << std::endl;
  std::cout << "100 ft/s to mph: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPH) << std::endl;
  std::cout << "100 ft/s to kts: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KTS) << std::endl;
  std::cout << "100 ft/s to ft/m: " << bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::FPM) << std::endl;
  /* convacc */
  std::cout << "100 ft/s/s to m/s/s: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPS2) << std::endl;
  std::cout << "100 ft/s/s to km/s/s: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPS2) << std::endl;
  std::cout << "100 ft/s/s to in/s/s: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::IPS2) << std::endl;
  std::cout << "100 ft/s/s to km/h/s: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPHPS) << std::endl;
  std::cout << "100 ft/s/s to mph/s: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPHPS) << std::endl;
  std::cout << "100 ft/s/s to Gs: " << bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::G) << std::endl;
  /* convang */
  std::cout << "10 deg to rad: " << bfs::convang(10.0, bfs::AngPosUnit::DEG, bfs::AngPosUnit::RAD) << std::endl;
  std::cout << "10 deg to rev: " << bfs::convang(10.0, bfs::AngPosUnit::DEG, bfs::AngPosUnit::REV) << std::endl;
  /* convangvel */
  std::cout << "10 deg/s to rad/s: " << bfs::convangvel(10.0, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RADPS) << std::endl;
  std::cout << "10 deg/s to rpm: " << bfs::convangvel(10.0, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RPM) << std::endl;
  /* convangacc */
  std::cout << "10 deg/s/s to rad/s/s: " << bfs::convangacc(10.0, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RADPS2) << std::endl;
  std::cout << "10 deg/s/s to rpm/s: " << bfs::convangacc(10.0, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RPMPS) << std::endl;
  /* convforce */
  std::cout << "10 lbf to N: " << bfs::convforce(10.0f, bfs::ForceUnit::LBF, bfs::ForceUnit::N) << std::endl;
  /* convmass */
  std::cout << "10 lbm to kg: " << bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::KG) << std::endl;
  std::cout << "10 lbm to slug: " << bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::SLUG) << std::endl;
  /* convdensity */
  std::cout << "10 lb/ft^3 to kg/m^3: " << bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::KGPM3) << std::endl;
  std::cout << "10 lb/ft^3 to slug/ft^3: " << bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::SLUGPFT3) << std::endl;
  std::cout << "10 lb/ft^3 to lb/in^3: " << bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::LBMPIN3) << std::endl;
  /* convpres */
  std::cout << "10 psi to Pa: " << bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PA) << std::endl;
  std::cout << "10 psi to hPa: " << bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::HPA) << std::endl;
  std::cout << "10 psi to psf: " << bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PSF) << std::endl;
  std::cout << "10 psi to atm: " << bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::ATM) << std::endl;
  /* convtemp */
  std::cout << "300K to F: " << bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::F) << std::endl;
  std::cout << "300K to C: " << bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::C) << std::endl;
  std::cout << "300K to R: " << bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::R) << std::endl;
}
