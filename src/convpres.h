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

#ifndef SRC_CONVPRES_H_
#define SRC_CONVPRES_H_

#if defined(ARDUINO)
#include <Arduino.h>
#endif
#include <type_traits>

namespace bfs {
/* Units for measuring force */
enum class PresUnit {
  PSI,  // pound force per square inch
  PA,   // Pascal
  HPA,  // Hectopascal
  PSF,  // pound force per square foot
  ATM,  // atmosphere
  MBAR  // millibar
};
/* 
* Utility to convert between pressure units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convpres(1, PresUnit::PSI, PresUnit::PA)'
* converts 1 psf to Pa.
*/
template<typename T>
T convpres(const T val, const PresUnit input, const PresUnit output) {
  static_assert(std::is_floating_point<T>::value,
              "Only floating point types supported");
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  T in_val;
  switch (input) {
    case PresUnit::PSI: {
      in_val = val * static_cast<T>(0.45359237) * static_cast<T>(9.80665) /
               static_cast<T>(0.0254) / static_cast<T>(0.0254);
      break;
    }
    case PresUnit::PA: {
      in_val = val;
      break;
    }
    case PresUnit::HPA: {
      in_val = val * static_cast<T>(100.0);
      break;
    }
    case PresUnit::PSF: {
      in_val = val * static_cast<T>(0.45359237) * static_cast<T>(9.80665) /
               static_cast<T>(0.3048) / static_cast<T>(0.3048);
      break;
    }
    case PresUnit::ATM: {
      in_val = val * static_cast<T>(101325.0);
      break;
    }
    case PresUnit::MBAR: {
      in_val = val * static_cast<T>(100.0);
      break;
    }
  }
  /* Convert to output */
  T out_val;
  switch (output) {
    case PresUnit::PSI: {
      out_val = in_val / static_cast<T>(0.45359237) / static_cast<T>(9.80665) *
                static_cast<T>(0.0254) * static_cast<T>(0.0254);
      break;
    }
    case PresUnit::PA: {
      out_val = in_val;
      break;
    }
    case PresUnit::HPA: {
      out_val = in_val / static_cast<T>(100.0);
      break;
    }
    case PresUnit::PSF: {
      out_val = in_val / static_cast<T>(0.45359237) / static_cast<T>(9.80665) *
                static_cast<T>(0.3048) * static_cast<T>(0.3048);
      break;
    }
    case PresUnit::ATM: {
      out_val = in_val / static_cast<T>(101325.0);
      break;
    }
    case PresUnit::MBAR: {
      out_val = in_val / static_cast<T>(100.0);
      break;
    }
  }
  return out_val;
}

}  // namespace bfs

#endif  // SRC_CONVPRES_H_
