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

#ifndef SRC_CONVFORCE_H_
#define SRC_CONVFORCE_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring force */
enum class ForceUnit {
  LBF,  // pound force
  N     // Newton
};
/* 
* Utility to convert between force units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convforce(1, ForceUnit::LBF, ForceUnit::Newton)'
* converts 1 lbf to N.
*/
template<typename T>
T convforce(const T val, const ForceUnit input, const ForceUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case ForceUnit::LBF: {
      in_val = val * static_cast<T>(0.45359237) * static_cast<T>(9.80665);
      break;
    }
    case ForceUnit::N: {
      in_val = val;
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case ForceUnit::LBF: {
      out_val = in_val / static_cast<T>(0.45359237) / static_cast<T>(9.80665);
      break;
    }
    case ForceUnit::N: {
      out_val = in_val;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVFORCE_H_
