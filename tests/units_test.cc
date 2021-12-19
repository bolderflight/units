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
#include "gtest/gtest.h"

/*** convlength ***/
/* feet */
TEST(convlength, feet) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(30.48f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(0.03048f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(1200.0f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(0.0189393939393939f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(0.0164578833693305f, bfs::convlength(100.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::NAUT_MI));
}
/* meters */
TEST(convlength, meters) {
  EXPECT_FLOAT_EQ(328.083989501312f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(100.0f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(0.1f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(3937.00787401575f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(0.0621371192237334f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(0.0539956803455724f, bfs::convlength(100.0f, bfs::LinPosUnit::M, bfs::LinPosUnit::NAUT_MI));
}
/* kilometers */
TEST(convlength, kilometers) {
  EXPECT_FLOAT_EQ(3280.83989501312f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(1.0f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(39370.0787401575f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(0.621371192237334f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(0.539956803455723f, bfs::convlength(1.0f, bfs::LinPosUnit::KM, bfs::LinPosUnit::NAUT_MI));
}
/* inches */
TEST(convlength, inches) {
  EXPECT_FLOAT_EQ(83.3333333333333f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(25.4f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(0.0254f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(0.0157828282828283f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(0.0137149028077754f, bfs::convlength(1000.0f, bfs::LinPosUnit::IN, bfs::LinPosUnit::NAUT_MI));
}
/* miles */
TEST(convlength, miles) {
  EXPECT_FLOAT_EQ(5280.0f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(1609.344f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(1.609344f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(63360.0f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(1.0f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(0.868976241900648f, bfs::convlength(1.0f, bfs::LinPosUnit::MI, bfs::LinPosUnit::NAUT_MI));
}
/* nautical miles */
TEST(convlength, naut_mi) {
  EXPECT_FLOAT_EQ(6076.1154855643f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::FT));
  EXPECT_FLOAT_EQ(1852.0f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::M));
  EXPECT_FLOAT_EQ(1.852f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::KM));
  EXPECT_FLOAT_EQ(72913.3858267717f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::IN));
  EXPECT_FLOAT_EQ(1.15077944802354f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::MI));
  EXPECT_FLOAT_EQ(1.0f, bfs::convlength(1.0f, bfs::LinPosUnit::NAUT_MI, bfs::LinPosUnit::NAUT_MI));
}
/*** convvel ***/
/* ft/s */
TEST(convvel, fps) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(30.48f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.03048f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(1200.0f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(109.728f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(68.1818181818182f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(59.2483801295896f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(6000.0f, bfs::convvel(100.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::FPM));
}
/* m/s */
TEST(convvel, mps) {
  EXPECT_FLOAT_EQ(328.083989501312f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.1f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(3937.00787401575f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(360.0f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(223.69362920544f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(194.38444924406f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(19685.0393700787f, bfs::convvel(100.0f, bfs::LinVelUnit::MPS, bfs::LinVelUnit::FPM));
}
/* km/s */
TEST(convvel, kps) {
  EXPECT_FLOAT_EQ(3280.83989501312f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(1.0f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(39370.0787401575f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(3600.0f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(2236.9362920544f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(1943.8444924406f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(196850.393700787f, bfs::convvel(1.0f, bfs::LinVelUnit::KPS, bfs::LinVelUnit::FPM));
}
/* in/s */
TEST(convvel, ips) {
  EXPECT_FLOAT_EQ(83.3333333333333f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(25.4f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.0254f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(91.44f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(56.8181818181818f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(49.3736501079914f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(5000.0f, bfs::convvel(1000.0f, bfs::LinVelUnit::IPS, bfs::LinVelUnit::FPM));
}
/* km/h */
TEST(convvel, kpm) {
  EXPECT_FLOAT_EQ(91.1344415281423f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(27.7777777777778f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.0277777777777778f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(1093.61329833771f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(62.1371192237334f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(53.9956803455724f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(5468.06649168854f, bfs::convvel(100.0f, bfs::LinVelUnit::KPH, bfs::LinVelUnit::FPM));
}
/* mph */
TEST(convvel, mph) {
  EXPECT_FLOAT_EQ(146.666666666667f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(44.704f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.044704f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(1760.0f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(160.9344f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(86.8976241900648f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(8800.0f, bfs::convvel(100.0f, bfs::LinVelUnit::MPH, bfs::LinVelUnit::FPM));
}
/* kts */
TEST(convvel, kts) {
  EXPECT_FLOAT_EQ(168.78098571012f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(51.4444444444444f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.0514444444444444f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(2025.37182852144f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(185.2f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(115.077944802354f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(10126.8591426072f, bfs::convvel(100.0f, bfs::LinVelUnit::KTS, bfs::LinVelUnit::FPM));
}
/* ft/min */
TEST(convvel, fpm) {
  EXPECT_FLOAT_EQ(1.66666666666667f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::FPS));
  EXPECT_FLOAT_EQ(0.508f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::MPS));
  EXPECT_FLOAT_EQ(0.000508f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::KPS));
  EXPECT_FLOAT_EQ(20.0f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::IPS));
  EXPECT_FLOAT_EQ(1.8288f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::KPH));
  EXPECT_FLOAT_EQ(1.13636363636364f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::MPH));
  EXPECT_FLOAT_EQ(0.987473002159827f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::KTS));
  EXPECT_FLOAT_EQ(100.0f, bfs::convvel(100.0f, bfs::LinVelUnit::FPM, bfs::LinVelUnit::FPM));
}
/*** convacc ***/
/* ft/s/s */
TEST(convacc, fps2) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(30.48f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.03048f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(1200.0f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(109.728f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(68.1818181818182f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(3.10809501715673f, bfs::convacc(100.0f, bfs::LinAccUnit::FPS2, bfs::LinAccUnit::G));
}
/* m/s/s */
TEST(convacc, mps2) {
  EXPECT_FLOAT_EQ(328.083989501312f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(100.0f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.1f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(3937.00787401575f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(360.0f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(223.69362920544f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(10.1971621297793f, bfs::convacc(100.0f, bfs::LinAccUnit::MPS2, bfs::LinAccUnit::G));
}
/* km/s/s */
TEST(convacc, kps2) {
  EXPECT_FLOAT_EQ(3280.83989501312f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(1.0f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(39370.0787401575f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(3600.0f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(2236.9362920544f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(101.971621297793f, bfs::convacc(1.0f, bfs::LinAccUnit::KPS2, bfs::LinAccUnit::G));
}
/* in/s/s */
TEST(convacc, ips2) {
  EXPECT_FLOAT_EQ(8.33333333333333f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(2.54f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.00254f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(100.0f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(9.144f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(5.68181818181818f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(0.259007918096394f, bfs::convacc(100.0f, bfs::LinAccUnit::IPS2, bfs::LinAccUnit::G));
}
/* km/h/s */
TEST(convacc, kphps) {
  EXPECT_FLOAT_EQ(9.11344415281423f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(2.77777777777778f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.00277777777777778f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(109.361329833771f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(10.0f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(6.21371192237334f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(0.28325450360498f, bfs::convacc(10.0f, bfs::LinAccUnit::KPHPS, bfs::LinAccUnit::G));
}
/* mph/s */
TEST(convacc, mphps) {
  EXPECT_FLOAT_EQ(14.6666666666667f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(4.4704f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.0044704f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(176.0f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(16.09344f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(10.0f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(0.455853935849653f, bfs::convacc(10.0f, bfs::LinAccUnit::MPHPS, bfs::LinAccUnit::G));
}
/* Gs */
TEST(convacc, g) {
  EXPECT_FLOAT_EQ(32.1740485564304f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::FPS2));
  EXPECT_FLOAT_EQ(9.80665f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::MPS2));
  EXPECT_FLOAT_EQ(0.00980665f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::KPS2));
  EXPECT_FLOAT_EQ(386.088582677165f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::IPS2));
  EXPECT_FLOAT_EQ(35.30394f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::KPHPS));
  EXPECT_FLOAT_EQ(21.9368512884753f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::MPHPS));
  EXPECT_FLOAT_EQ(1.0f, bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::G));
}
/*** convang ***/
/* deg */
TEST(convang, deg) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convang(100.0f, bfs::AngPosUnit::DEG, bfs::AngPosUnit::DEG));
  EXPECT_FLOAT_EQ(1.74532925199433f, bfs::convang(100.0f, bfs::AngPosUnit::DEG, bfs::AngPosUnit::RAD));
  EXPECT_FLOAT_EQ(0.277777777777778f, bfs::convang(100.0f, bfs::AngPosUnit::DEG, bfs::AngPosUnit::REV));
  EXPECT_FLOAT_EQ(1.74532925199433f, bfs::deg2rad(100.0f));
}
/* rad */
TEST(convang, rad) {
  EXPECT_FLOAT_EQ(572.957795130823f, bfs::convang(10.0f, bfs::AngPosUnit::RAD, bfs::AngPosUnit::DEG));
  EXPECT_FLOAT_EQ(10.0f, bfs::convang(10.0f, bfs::AngPosUnit::RAD, bfs::AngPosUnit::RAD));
  EXPECT_FLOAT_EQ(1.59154943091895f, bfs::convang(10.0f, bfs::AngPosUnit::RAD, bfs::AngPosUnit::REV));
  EXPECT_FLOAT_EQ(572.957795130823f, bfs::rad2deg(10.0f));
}
/* rev */
TEST(convang, rev) {
  EXPECT_FLOAT_EQ(180.0f, bfs::convang(0.5f, bfs::AngPosUnit::REV, bfs::AngPosUnit::DEG));
  EXPECT_FLOAT_EQ(3.14159265358979f, bfs::convang(0.5f, bfs::AngPosUnit::REV, bfs::AngPosUnit::RAD));
  EXPECT_FLOAT_EQ(0.5f, bfs::convang(0.5f, bfs::AngPosUnit::REV, bfs::AngPosUnit::REV));
}
/*** convangvel ***/
/* deg/s */
TEST(convangvel, degps) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convangvel(100.0f, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::DEGPS));
  EXPECT_FLOAT_EQ(1.74532925199433f, bfs::convangvel(100.0f, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RADPS));
  EXPECT_FLOAT_EQ(16.6666666666667f, bfs::convangvel(100.0f, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RPM));
}
/* rad/s */
TEST(convangvel, radps) {
  EXPECT_FLOAT_EQ(572.957795130823f, bfs::convangvel(10.0f, bfs::AngVelUnit::RADPS, bfs::AngVelUnit::DEGPS));
  EXPECT_FLOAT_EQ(10.0f, bfs::convangvel(10.0f, bfs::AngVelUnit::RADPS, bfs::AngVelUnit::RADPS));
  EXPECT_FLOAT_EQ(95.4929658551372f, bfs::convangvel(10.0f, bfs::AngVelUnit::RADPS, bfs::AngVelUnit::RPM));
}
/* rpm */
TEST(convangvel, rpm) {
  EXPECT_FLOAT_EQ(600.0f, bfs::convangvel(100.0f, bfs::AngVelUnit::RPM, bfs::AngVelUnit::DEGPS));
  EXPECT_FLOAT_EQ(10.471975511966f, bfs::convangvel(100.0f, bfs::AngVelUnit::RPM, bfs::AngVelUnit::RADPS));
  EXPECT_FLOAT_EQ(100.0f, bfs::convangvel(100.0f, bfs::AngVelUnit::RPM, bfs::AngVelUnit::RPM));
}
/*** convangacc ***/
/* deg/s/s */
TEST(convangacc, degps2) {
  EXPECT_FLOAT_EQ(100.0f, bfs::convangacc(100.0f, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::DEGPS2));
  EXPECT_FLOAT_EQ(1.74532925199433f, bfs::convangacc(100.0f, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RADPS2));
  EXPECT_FLOAT_EQ(16.6666666666667f, bfs::convangacc(100.0f, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RPMPS));
}
/* rad/s/s */
TEST(convangacc, radps2) {
  EXPECT_FLOAT_EQ(572.957795130823f, bfs::convangacc(10.0f, bfs::AngAccUnit::RADPS2, bfs::AngAccUnit::DEGPS2));
  EXPECT_FLOAT_EQ(10.0f, bfs::convangacc(10.0f, bfs::AngAccUnit::RADPS2, bfs::AngAccUnit::RADPS2));
  EXPECT_FLOAT_EQ(95.4929658551372f, bfs::convangacc(10.0f, bfs::AngAccUnit::RADPS2, bfs::AngAccUnit::RPMPS));
}
/* rpm/s */
TEST(convangacc, rpmps) {
  EXPECT_FLOAT_EQ(600.0f, bfs::convangacc(100.0f, bfs::AngAccUnit::RPMPS, bfs::AngAccUnit::DEGPS2));
  EXPECT_FLOAT_EQ(10.471975511966f, bfs::convangacc(100.0f, bfs::AngAccUnit::RPMPS, bfs::AngAccUnit::RADPS2));
  EXPECT_FLOAT_EQ(100.0f, bfs::convangacc(100.0f, bfs::AngAccUnit::RPMPS, bfs::AngAccUnit::RPMPS));
}
/*** convforce ***/
/* LBF */
TEST(convforce, lbf) {
  EXPECT_FLOAT_EQ(10.0f, bfs::convforce(10.0f, bfs::ForceUnit::LBF, bfs::ForceUnit::LBF));
  EXPECT_FLOAT_EQ(44.482216152605f, bfs::convforce(10.0f, bfs::ForceUnit::LBF, bfs::ForceUnit::N));
}
/* N */
TEST(convforce, n) {
  EXPECT_FLOAT_EQ(2.2480894309971f, bfs::convforce(10.0f, bfs::ForceUnit::N, bfs::ForceUnit::LBF));
  EXPECT_FLOAT_EQ(10.0f, bfs::convforce(10.0f, bfs::ForceUnit::N, bfs::ForceUnit::N));
}
/*** convmass ***/
/* lbm */
TEST(convmass, lbm) {
  EXPECT_FLOAT_EQ(10.0f, bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::LBM));
  EXPECT_FLOAT_EQ(4.5359237f, bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::KG));
  EXPECT_FLOAT_EQ(0.310809501715673f, bfs::convmass(10.0f, bfs::MassUnit::LBM, bfs::MassUnit::SLUG));
}
/* kg */
TEST(convmass, kg) {
  EXPECT_FLOAT_EQ(22.0462262184878f, bfs::convmass(10.0f, bfs::MassUnit::KG, bfs::MassUnit::LBM));
  EXPECT_FLOAT_EQ(10.0f, bfs::convmass(10.0f, bfs::MassUnit::KG, bfs::MassUnit::KG));
  EXPECT_FLOAT_EQ(0.685217658567918f, bfs::convmass(10.0f, bfs::MassUnit::KG, bfs::MassUnit::SLUG));
}
/* slug */
TEST(convmass, slug) {
  EXPECT_FLOAT_EQ(321.740485564304f, bfs::convmass(10.0f, bfs::MassUnit::SLUG, bfs::MassUnit::LBM));
  EXPECT_FLOAT_EQ(145.939029372064f, bfs::convmass(10.0f, bfs::MassUnit::SLUG, bfs::MassUnit::KG));
  EXPECT_FLOAT_EQ(10.0f, bfs::convmass(10.0f, bfs::MassUnit::SLUG, bfs::MassUnit::SLUG));
}
/*** convdensity ***/
/* lb/ft^3 */
TEST(convdensity, lbmpft3) {
  EXPECT_FLOAT_EQ(10.0f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::LBMPFT3));
  EXPECT_FLOAT_EQ(160.184633739601f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::KGPM3));
  EXPECT_FLOAT_EQ(0.310809501715673f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::SLUGPFT3));
  EXPECT_FLOAT_EQ(0.00578703703703704f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::LBMPIN3));
}
/* kg/m^3 */
TEST(convdensity, kgpm3) {
  EXPECT_FLOAT_EQ(0.624279605761446f, bfs::convdensity(10.0f, bfs::DensityUnit::KGPM3, bfs::DensityUnit::LBMPFT3));
  EXPECT_FLOAT_EQ(10.0f, bfs::convdensity(10.0f, bfs::DensityUnit::KGPM3, bfs::DensityUnit::KGPM3));
  EXPECT_FLOAT_EQ(0.0194032033197972f, bfs::convdensity(10.0f, bfs::DensityUnit::KGPM3, bfs::DensityUnit::SLUGPFT3));
  EXPECT_FLOAT_EQ(0.000361272920000837f, bfs::convdensity(10.0f, bfs::DensityUnit::KGPM3, bfs::DensityUnit::LBMPIN3));
}
/* slug/ft^3 */
TEST(convdensity, slugpft3) {
  EXPECT_FLOAT_EQ(321.740485564304f, bfs::convdensity(10.0f, bfs::DensityUnit::SLUGPFT3, bfs::DensityUnit::LBMPFT3));
  EXPECT_FLOAT_EQ(5153.78818393196f, bfs::convdensity(10.0f, bfs::DensityUnit::SLUGPFT3, bfs::DensityUnit::KGPM3));
  EXPECT_FLOAT_EQ(10.0f, bfs::convdensity(10.0f, bfs::DensityUnit::SLUGPFT3, bfs::DensityUnit::SLUGPFT3));
  EXPECT_FLOAT_EQ(0.186192410627491f, bfs::convdensity(10.0f, bfs::DensityUnit::SLUGPFT3, bfs::DensityUnit::LBMPIN3));
}
/* lb/in^3 */
TEST(convdensity, lbmpin3) {
  EXPECT_FLOAT_EQ(17280.0f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPIN3, bfs::DensityUnit::LBMPFT3));
  EXPECT_FLOAT_EQ(276799.047102031f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPIN3, bfs::DensityUnit::KGPM3));
  EXPECT_FLOAT_EQ(537.078818964682f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPIN3, bfs::DensityUnit::SLUGPFT3));
  EXPECT_FLOAT_EQ(10.0f, bfs::convdensity(10.0f, bfs::DensityUnit::LBMPIN3, bfs::DensityUnit::LBMPIN3));
}
/*** convpres ***/
/* psi */
TEST(convpres, psi) {
  EXPECT_FLOAT_EQ(10.0f, bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PSI));
  EXPECT_FLOAT_EQ(68947.5729316836f, bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PA));
  EXPECT_FLOAT_EQ(689.475729316836f, bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::HPA));
  EXPECT_FLOAT_EQ(1440.0f, bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::PSF));
  EXPECT_FLOAT_EQ(0.680459639098777f, bfs::convpres(10.0f, bfs::PresUnit::PSI, bfs::PresUnit::ATM));
}
/* pa */
TEST(convpres, pa) {
  EXPECT_FLOAT_EQ(0.00145037737730209f, bfs::convpres(10.0f, bfs::PresUnit::PA, bfs::PresUnit::PSI));
  EXPECT_FLOAT_EQ(10.0f, bfs::convpres(10.0f, bfs::PresUnit::PA, bfs::PresUnit::PA));
  EXPECT_FLOAT_EQ(0.208854342331501f, bfs::convpres(10.0f, bfs::PresUnit::PA, bfs::PresUnit::PSF));
  EXPECT_FLOAT_EQ(0.00986923266716013f, bfs::convpres(1000.0f, bfs::PresUnit::PA, bfs::PresUnit::ATM));
}
/* hpa */
TEST(convpres, hpa) {
  EXPECT_FLOAT_EQ(0.145037737730209f, bfs::convpres(10.0f, bfs::PresUnit::HPA, bfs::PresUnit::PSI));
  EXPECT_FLOAT_EQ(1000.0f, bfs::convpres(10.0f, bfs::PresUnit::HPA, bfs::PresUnit::PA));
  EXPECT_FLOAT_EQ(10.0f, bfs::convpres(10.0f, bfs::PresUnit::HPA, bfs::PresUnit::HPA));
  EXPECT_FLOAT_EQ(20.8854342331501f, bfs::convpres(10.0f, bfs::PresUnit::HPA, bfs::PresUnit::PSF));
  EXPECT_FLOAT_EQ(0.00986923266716013f, bfs::convpres(10.0f, bfs::PresUnit::HPA, bfs::PresUnit::ATM));
}
/* psf */
TEST(convpres, psf) {
  EXPECT_FLOAT_EQ(0.0694444444444444f, bfs::convpres(10.0f, bfs::PresUnit::PSF, bfs::PresUnit::PSI));
  EXPECT_FLOAT_EQ(478.802589803358f, bfs::convpres(10.0f, bfs::PresUnit::PSF, bfs::PresUnit::PA));
  EXPECT_FLOAT_EQ(4.78802589803358f, bfs::convpres(10.0f, bfs::PresUnit::PSF, bfs::PresUnit::HPA));
  EXPECT_FLOAT_EQ(10.0f, bfs::convpres(10.0f, bfs::PresUnit::PSF, bfs::PresUnit::PSF));
  EXPECT_FLOAT_EQ(0.00472541416040818f, bfs::convpres(10.0f, bfs::PresUnit::PSF, bfs::PresUnit::ATM));
}
/* atm */
TEST(convpres, atm) {
  EXPECT_FLOAT_EQ(14.6959487755135f, bfs::convpres(1.0f, bfs::PresUnit::ATM, bfs::PresUnit::PSI));
  EXPECT_FLOAT_EQ(101325.0f, bfs::convpres(1.0f, bfs::PresUnit::ATM, bfs::PresUnit::PA));
  EXPECT_FLOAT_EQ(1013.250f, bfs::convpres(1.0f, bfs::PresUnit::ATM, bfs::PresUnit::HPA));
  EXPECT_FLOAT_EQ(2116.21662367394f, bfs::convpres(1.0f, bfs::PresUnit::ATM, bfs::PresUnit::PSF));
  EXPECT_FLOAT_EQ(1.0f, bfs::convpres(1.0f, bfs::PresUnit::ATM, bfs::PresUnit::ATM));
}
/* mbar */
TEST(convpres, mbar) {
  EXPECT_FLOAT_EQ(1.0f, bfs::convpres(100.0f, bfs::PresUnit::PA, bfs::PresUnit::MBAR));
  EXPECT_FLOAT_EQ(10000.0f, bfs::convpres(100.0f, bfs::PresUnit::MBAR, bfs::PresUnit::PA));
}
/*** convtemp ***/
/* k */
TEST(convtemp, k) {
  EXPECT_FLOAT_EQ(300.0f, bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::K));
  EXPECT_FLOAT_EQ(80.33f, bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::F));
  EXPECT_FLOAT_EQ(26.85f, bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::C));
  EXPECT_FLOAT_EQ(540.0f, bfs::convtemp(300.0f, bfs::TempUnit::K, bfs::TempUnit::R));
}
/* f */
TEST(convtemp, f) {
  EXPECT_FLOAT_EQ(260.927777777778f, bfs::convtemp(10.0f, bfs::TempUnit::F, bfs::TempUnit::K));
  EXPECT_FLOAT_EQ(10.0f, bfs::convtemp(10.0f, bfs::TempUnit::F, bfs::TempUnit::F));
  EXPECT_FLOAT_EQ(-12.2222222222222f, bfs::convtemp(10.0f, bfs::TempUnit::F, bfs::TempUnit::C));
  EXPECT_FLOAT_EQ(469.67f, bfs::convtemp(10.0f, bfs::TempUnit::F, bfs::TempUnit::R));
}
/* c */
TEST(convtemp, c) {
  EXPECT_FLOAT_EQ(283.15f, bfs::convtemp(10.0f, bfs::TempUnit::C, bfs::TempUnit::K));
  EXPECT_FLOAT_EQ(50.0f, bfs::convtemp(10.0f, bfs::TempUnit::C, bfs::TempUnit::F));
  EXPECT_FLOAT_EQ(10.0f, bfs::convtemp(10.0f, bfs::TempUnit::C, bfs::TempUnit::C));
  EXPECT_FLOAT_EQ(509.67f, bfs::convtemp(10.0f, bfs::TempUnit::C, bfs::TempUnit::R));
}
/* r */
TEST(convtemp, r) {
  EXPECT_FLOAT_EQ(277.777777777778f, bfs::convtemp(500.0f, bfs::TempUnit::R, bfs::TempUnit::K));
  EXPECT_FLOAT_EQ(40.33f, bfs::convtemp(500.0f, bfs::TempUnit::R, bfs::TempUnit::F));
  EXPECT_FLOAT_EQ(4.6277704f, bfs::convtemp(500.0f, bfs::TempUnit::R, bfs::TempUnit::C));
  EXPECT_FLOAT_EQ(500.0f, bfs::convtemp(500.0f, bfs::TempUnit::R, bfs::TempUnit::R));
}
