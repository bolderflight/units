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

#ifndef SRC_CONVACC_H_
#define SRC_CONVACC_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring linear acceleration */
enum class LinAccUnit {
  FPS2,   // feet per second per second, ft/s/s
  MPS2,   // meters per second per second, m/s/s
  KPS2,   // kilometers per second per second, km/s/s
  IPS2,   // inches per second per second, in/s/s
  KPHPS,  // kilometers per hour per second, km/h/s
  MPHPS,  // miles per hour per second, mi/h/s
  G,      // G force acceleration, G
};
/* 
* Utility to convert between linear acceleration units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convacc(1, LinAccUnit::G, LinAccUnit::MPS2)'
* converts 1 G to m/s/s.
*/
template<typename T>
T convacc(const T val, const LinAccUnit input, const LinAccUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case LinAccUnit::FPS2: {
      in_val = val * static_cast<T>(0.3048);
      break;
    }
    case LinAccUnit::MPS2: {
      in_val = val;
      break;
    }
    case LinAccUnit::KPS2: {
      in_val = val * static_cast<T>(1000);
      break;
    }
    case LinAccUnit::IPS2: {
      in_val = val * static_cast<T>(0.0254);
      break;
    }
    case LinAccUnit::KPHPS: {
      in_val = val * static_cast<T>(1000) / static_cast<T>(3600);
      break;
    }
    case LinAccUnit::MPHPS: {
      in_val = val * static_cast<T>(1609.344) / static_cast<T>(3600);
      break;
    }
    case LinAccUnit::G: {
      in_val = val * static_cast<T>(9.80665);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case LinAccUnit::FPS2: {
      out_val = in_val / static_cast<T>(0.3048);
      break;
    }
    case LinAccUnit::MPS2: {
      out_val = in_val;
      break;
    }
    case LinAccUnit::KPS2: {
      out_val = in_val / static_cast<T>(1000);
      break;
    }
    case LinAccUnit::IPS2: {
      out_val = in_val / static_cast<T>(0.0254);
      break;
    }
    case LinAccUnit::KPHPS: {
      out_val = in_val / static_cast<T>(1000) * static_cast<T>(3600);
      break;
    }
    case LinAccUnit::MPHPS: {
      out_val = in_val / static_cast<T>(1609.344) * static_cast<T>(3600);
      break;
    }
    case LinAccUnit::G: {
      out_val = in_val / static_cast<T>(9.80665);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVACC_H_
