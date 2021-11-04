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

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  /* convlength */
  Serial.print("100 feet to meters: ");
  Serial.println(bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::M));
  Serial.print("100 feet to kilometers: ");
  Serial.println(bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::KM));
  Serial.print("100 feet to inches: ");
  Serial.println(bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::IN));
  Serial.print("100 feet to miles: ");
  Serial.println(bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::MI));
  Serial.print("100 feet to nautical miles: ");
  Serial.println(bfs::convlength(100.0, bfs::LinPosUnit::FT, bfs::LinPosUnit::NAUT_MI));
  /* convvel */
  Serial.print("100 ft/s to m/s: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPS));
  Serial.print("100 ft/s to km/s: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPS));
  Serial.print("100 ft/s to in/s: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::IPS));
  Serial.print("100 ft/s to km/h: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPH));
  Serial.print("100 ft/s to mph: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPH));
  Serial.print("100 ft/s to kts: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KTS));
  Serial.print("100 ft/s to ft/m: ");
  Serial.println(bfs::convvel(100.0, bfs::LinVelUnit::FPS, bfs::LinVelUnit::FPM));
  /* convacc */
  Serial.print("100 ft/s/s to m/s/s: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPS2));
  Serial.print("100 ft/s/s to km/s/s: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPS2));
  Serial.print("100 ft/s/s to in/s/s: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::IPS2));
  Serial.print("100 ft/s/s to km/h/s: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPHPS));
  Serial.print("100 ft/s/s to mph/s: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPHPS));
  Serial.print("100 ft/s/s to Gs: ");
  Serial.println(bfs::convacc(100.0, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::G));
  /* convang */
  Serial.print("10 deg to rad: ");
  Serial.println(bfs::convang(10.0, bfs::AngPosUnit::DEG, bfs::AngPosUnit::RAD));
  Serial.print("10 deg to rev: ");
  Serial.println(bfs::convang(10.0, bfs::AngPosUnit::DEG, bfs::AngPosUnit::REV));
  /* convangvel */
  Serial.print("10 deg/s to rad/s: ");
  Serial.println(bfs::convangvel(10.0, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RADPS));
  Serial.print("10 deg/s to rpm: ");
  Serial.println(bfs::convangvel(10.0, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RPM));
  /* convangacc */
  Serial.print("10 deg/s/s to rad/s/s: ");
  Serial.println(bfs::convangacc(10.0, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RADPS2));
  Serial.print("10 deg/s/s to rpm/s: ");
  Serial.println(bfs::convangacc(10.0, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RPMPS));
  /* convforce */
  Serial.print("10 lbf to N: ");
  Serial.println(bfs::convforce(10.0f, bfs::ForceUnit::LBF, bfs::ForceUnit::N));
  /* convmass */
  Serial.print("10 lbm to kg: ");
  Serial.println(bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::KG));
  Serial.print("10 lbm to slug: ");
  Serial.println(bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::SLUG));
  /* convdensity */
  Serial.print("10 lb/ft^3 to kg/m^3: ");
  Serial.println(bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::KGPM3));
  Serial.print("10 lb/ft^3 to slug/ft^3: ");
  Serial.println(bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::SLUGPFT3));
  Serial.print("10 lb/ft^3 to lb/in^3: ");
  Serial.println(bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::LBMPIN3));
  /* convpres */
  Serial.print("10 psi to Pa: ");
  Serial.println(bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PA));
  Serial.print("10 psi to hPa: ");
  Serial.println(bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::HPA));
  Serial.print("10 psi to psf: ");
  Serial.println(bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PSF));
  Serial.print("10 psi to atm: ");
  Serial.println(bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::ATM));
  /* convtemp */
  Serial.print("300K to F: ");
  Serial.println(bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::F));
  Serial.print("300K to C: ");
  Serial.println(bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::C));
  Serial.print("300K to R: ");
  Serial.println(bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::R));
}

void loop() {}
