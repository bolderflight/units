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

#ifndef SRC_CONVANGACC_H_
#define SRC_CONVANGACC_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>
#include "constants.h"  // NOLINT

namespace bfs {
/* Units for measuring angular acceleration */
enum class AngAccUnit {
  DEGPS2,  // degrees per second per second, deg/s/s
  RADPS2,  // radians per second per second, rad/s/s
  RPMPS    // revolutions per minute per second, rpm/s
};
/* 
* Utility to convert between angular acceleration units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e.
* 'convangacc(1, AngAccUnit::DEGPS2, AngAccUnit::RADPS2)'
* converts 1 deg/s/s to rad/s/s.
*/
template<typename T>
T convangacc(const T val, const AngAccUnit input, const AngAccUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case AngAccUnit::DEGPS2: {
      in_val = val * BFS_PI<T> / static_cast<T>(180);
      break;
    }
    case AngAccUnit::RADPS2: {
      in_val = val;
      break;
    }
    case AngAccUnit::RPMPS: {
      in_val = val * BFS_2PI<T> / static_cast<T>(60);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case AngAccUnit::DEGPS2: {
      out_val = in_val * static_cast<T>(180) / BFS_PI<T>;
      break;
    }
    case AngAccUnit::RADPS2: {
      out_val = in_val;
      break;
    }
    case AngAccUnit::RPMPS: {
      out_val = in_val / BFS_2PI<T> * static_cast<T>(60);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVANGACC_H_
