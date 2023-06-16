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

#ifndef UNITS_SRC_CONVDENSITY_H_  // NOLINT
#define UNITS_SRC_CONVDENSITY_H_

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cstddef>
#include <cstdint>
#endif

namespace bfs {
/* Units for measuring density */
enum class DensityUnit : int8_t {
  LBMPFT3,    // pound mass per feet cubed
  KGPM3,      // kilogram per meters cubed
  SLUGPFT3,   // slug per feet cubed
  LBMPIN3     // pound mass per inch cubed
};
/* 
* Utility to convert between density units
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to,
* i.e. 'convdensity(1, DensityUnit::LBMPFT3, DensityUnit::KGPM3)'
* converts 1 lb/ft^3 to kg/m^3.
*/
float convdensity(const float val, const DensityUnit input,
                  const DensityUnit output);

}  // namespace bfs

#endif  // UNITS_SRC_CONVDENSITY_H_ NOLINT
