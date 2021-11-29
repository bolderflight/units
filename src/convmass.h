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

#ifndef SRC_CONVMASS_H_
#define SRC_CONVMASS_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring mass */
enum class MassUnit {
  LBM,  // pound mass
  KG,   // kilograms
  SLUG  // slugs
};
/* 
* Utility to convert between mass units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convmass(1, MassUnit::LBM, MassUnit::KG)'
* converts 1 lbm to kg.
*/
template<typename T>
T convmass(const T val, const MassUnit input, const MassUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case MassUnit::LBM: {
      in_val = val * static_cast<T>(0.45359237);
      break;
    }
    case MassUnit::KG: {
      in_val = val;
      break;
    }
    case MassUnit::SLUG: {
      in_val = val * static_cast<T>(14.59390);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case MassUnit::LBM: {
      out_val = in_val / static_cast<T>(0.45359237);
      break;
    }
    case MassUnit::KG: {
      out_val = in_val;
      break;
    }
    case MassUnit::SLUG: {
      out_val = in_val / static_cast<T>(14.59390);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVMASS_H_
