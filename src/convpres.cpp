/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2023 Bolder Flight Systems Inc
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

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cstddef>
#include <cstdint>
#endif

#include "convpres.h"  // NOLINT
#include "constants.h"  // NOLINT

namespace bfs {

float convpres(const float val, const PresUnit input, const PresUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case PresUnit::PSI: {
      in_val = val * 0.45359237f * G_MPS2 / 0.0254f / 0.0254f;
      break;
    }
    case PresUnit::PA: {
      in_val = val;
      break;
    }
    case PresUnit::HPA: {
      in_val = val * 100.0f;
      break;
    }
    case PresUnit::PSF: {
      in_val = val * 0.45359237f * G_MPS2 / 0.3048f / 0.3048f;
      break;
    }
    case PresUnit::ATM: {
      in_val = val * 101325.0f;
      break;
    }
    case PresUnit::MBAR: {
      in_val = val * 100.0f;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case PresUnit::PSI: {
      out_val = in_val / 0.45359237f / G_MPS2 * 0.0254f * 0.0254f;
      break;
    }
    case PresUnit::PA: {
      out_val = in_val;
      break;
    }
    case PresUnit::HPA: {
      out_val = in_val / 100.0f;
      break;
    }
    case PresUnit::PSF: {
      out_val = in_val / 0.45359237f / G_MPS2 * 0.3048f * 0.3048f;
      break;
    }
    case PresUnit::ATM: {
      out_val = in_val / 101325.0f;
      break;
    }
    case PresUnit::MBAR: {
      out_val = in_val / 100.0f;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs
