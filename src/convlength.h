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

#ifndef SRC_CONVLENGTH_H_
#define SRC_CONVLENGTH_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring linear positions and length */
enum class LinPosUnit {
  FT,       // feet
  M,        // meters
  KM,       // kilometers
  IN,       // inches
  MI,       // miles
  NAUT_MI   // nautical miles
};
/* 
* Utility to convert between linear position units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convlength(1, LinPosUnit::FT, LinPosUnit::M)'
* converts 1 foot to meters.
*/
template<typename T>
T convlength(const T val, const LinPosUnit input, const LinPosUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case LinPosUnit::FT: {
      in_val = val * static_cast<T>(0.3048);
      break;
    }
    case LinPosUnit::M: {
      in_val = val;
      break;
    }
    case LinPosUnit::KM: {
      in_val = val * static_cast<T>(1000);
      break;
    }
    case LinPosUnit::IN: {
      in_val = val * static_cast<T>(0.0254);
      break;
    }
    case LinPosUnit::MI: {
      in_val = val * static_cast<T>(1609.344);
      break;
    }
    case LinPosUnit::NAUT_MI: {
      in_val = val * static_cast<T>(1852);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case LinPosUnit::FT: {
      out_val = in_val / static_cast<T>(0.3048);
      break;
    }
    case LinPosUnit::M: {
      out_val = in_val;
      break;
    }
    case LinPosUnit::KM: {
      out_val = in_val / static_cast<T>(1000);
      break;
    }
    case LinPosUnit::IN: {
      out_val = in_val / static_cast<T>(0.0254);
      break;
    }
    case LinPosUnit::MI: {
      out_val = in_val / static_cast<T>(1609.344);
      break;
    }
    case LinPosUnit::NAUT_MI: {
      out_val = in_val / static_cast<T>(1852);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVLENGTH_H_
