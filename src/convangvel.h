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

#ifndef SRC_CONVANGVEL_H_
#define SRC_CONVANGVEL_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>
#include "constants.h"  // NOLINT

namespace bfs {
/* Units for measuring angular velocity */
enum class AngVelUnit {
  DEGPS,  // degrees per second, deg/s
  RADPS,  // radians per second, rad/s
  RPM     // revolutions per minute, rpm
};
/* 
* Utility to convert between angular velocity units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e.
* 'convangvel(1, AngVelUnit::DEGPS, AngVelUnit::RADPS)'
* converts 1 deg/s to rad/s.
*/
template<typename T>
T convangvel(const T val, const AngVelUnit input, const AngVelUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case AngVelUnit::DEGPS: {
      in_val = val * BFS_PI<T> / static_cast<T>(180);
      break;
    }
    case AngVelUnit::RADPS: {
      in_val = val;
      break;
    }
    case AngVelUnit::RPM: {
      in_val = val * BFS_2PI<T> / static_cast<T>(60);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case AngVelUnit::DEGPS: {
      out_val = in_val * static_cast<T>(180) / BFS_PI<T>;
      break;
    }
    case AngVelUnit::RADPS: {
      out_val = in_val;
      break;
    }
    case AngVelUnit::RPM: {
      out_val = in_val / BFS_2PI<T> * static_cast<T>(60);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVANGVEL_H_
