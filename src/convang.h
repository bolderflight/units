/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
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

#ifndef UNITS_SRC_CONVANG_H_  // NOLINT
#define UNITS_SRC_CONVANG_H_

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cstddef>
#include <cstdint>
#endif

namespace bfs {
/* Units for measuring angular positions */
enum class AngPosUnit : int8_t {
  DEG,  // degree
  RAD,  // radians
  REV   // revolutions
};
/* 
* Utility to convert between angle units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convang(1, AngPosUnit::DEG, AngPosUnit::RAD)'
* converts 1 deg to radians.
*/
float convang(const float val, const AngPosUnit input,
              const AngPosUnit output);
double convang(const double val, const AngPosUnit input,
               const AngPosUnit output);

/* rad to deg conversion */
float rad2deg(const float val);
double rad2deg(const double val);

/* deg to rad conversion */
float deg2rad(const float val);
double deg2rad(const double val);

}  // namespace bfs

#endif  // UNITS_SRC_CONVANG_H_ NOLINT
