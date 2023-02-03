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

#ifndef UNITS_SRC_CONVDENSITY_H_  // NOLINT
#define UNITS_SRC_CONVDENSITY_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring density */
enum class DensityUnit {
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
template<typename T>
T convdensity(const T val, const DensityUnit input,
                        const DensityUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case DensityUnit::LBMPFT3: {
      in_val = val * static_cast<T>(0.45359237) / static_cast<T>(0.3048) /
               static_cast<T>(0.3048) / static_cast<T>(0.3048);
      break;
    }
    case DensityUnit::KGPM3: {
      in_val = val;
      break;
    }
    case DensityUnit::SLUGPFT3: {
      in_val = val * static_cast<T>(14.59390) / static_cast<T>(0.3048) /
               static_cast<T>(0.3048) / static_cast<T>(0.3048);
      break;
    }
    case DensityUnit::LBMPIN3: {
      in_val = val * static_cast<T>(0.45359237) / static_cast<T>(0.0254) /
               static_cast<T>(0.0254) / static_cast<T>(0.0254);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case DensityUnit::LBMPFT3: {
      out_val = in_val / static_cast<T>(0.45359237) * static_cast<T>(0.3048) *
                static_cast<T>(0.3048) * static_cast<T>(0.3048);
      break;
    }
    case DensityUnit::KGPM3: {
      out_val = in_val;
      break;
    }
    case DensityUnit::SLUGPFT3: {
      out_val = in_val / static_cast<T>(14.59390) * static_cast<T>(0.3048) *
                static_cast<T>(0.3048) * static_cast<T>(0.3048);
      break;
    }
    case DensityUnit::LBMPIN3: {
      out_val = in_val / static_cast<T>(0.45359237) * static_cast<T>(0.0254) *
                static_cast<T>(0.0254) * static_cast<T>(0.0254);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // UNITS_SRC_CONVDENSITY_H_ NOLINT
