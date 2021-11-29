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

#ifndef SRC_CONVTEMP_H_
#define SRC_CONVTEMP_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring temperature */
enum class TempUnit {
  K,  // Kelvin
  F,  // Fahrenheit
  C,  // Celsius
  R   // Rankine
};
/* 
* Utility to convert between temperature units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convtemp(1, TempUnit::F, TempUnit::C)'
* converts 1 F to C.
*/
template<typename T>
T convtemp(const T val, const TempUnit input, const TempUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case TempUnit::K: {
      in_val = val - static_cast<T>(273.15);
      break;
    }
    case TempUnit::F: {
      in_val = (val - static_cast<T>(32)) * static_cast<T>(5) /
               static_cast<T>(9);
      break;
    }
    case TempUnit::C: {
      in_val = val;
      break;
    }
    case TempUnit::R: {
      in_val = (val - static_cast<T>(491.67)) *
               static_cast<T>(5) / static_cast<T>(9);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case TempUnit::K: {
      out_val = in_val + static_cast<T>(273.15);
      break;
    }
    case TempUnit::F: {
      out_val = in_val * static_cast<T>(9) / static_cast<T>(5) +
                static_cast<T>(32);
      break;
    }
    case TempUnit::C: {
      out_val = in_val;
      break;
    }
    case TempUnit::R: {
      out_val = in_val * static_cast<T>(9) / static_cast<T>(5) +
                static_cast<T>(491.67);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVTEMP_H_
