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

#ifndef SRC_CONVANG_H_
#define SRC_CONVANG_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>
#include "constants.h"  // NOLINT

namespace bfs {
/* Units for measuring angular positions */
enum class AngPosUnit {
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
template<typename T>
T convang(const T val, const AngPosUnit input, const AngPosUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case AngPosUnit::DEG: {
      in_val = val * BFS_PI<T> / static_cast<T>(180);
      break;
    }
    case AngPosUnit::RAD: {
      in_val = val;
      break;
    }
    case AngPosUnit::REV: {
      in_val = val * BFS_2PI<T>;
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case AngPosUnit::DEG: {
      out_val = in_val * static_cast<T>(180) / BFS_PI<T>;
      break;
    }
    case AngPosUnit::RAD: {
      out_val = in_val;
      break;
    }
    case AngPosUnit::REV: {
      out_val = in_val / BFS_2PI<T>;
      break;
    }
  }
  return out_val;
}

/* rad to deg conversion */
template<typename T>
T rad2deg(const T val) {
  return convang(val, AngPosUnit::RAD, AngPosUnit::DEG);
}

/* deg to rad conversion */
template<typename T>
T deg2rad(const T val) {
  return convang(val, AngPosUnit::DEG, AngPosUnit::RAD);
}

}  // namespace bfs

#endif  // SRC_CONVANG_H_
