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

#include "convlength.h"  // NOLINT

namespace bfs {

float convlength(const float val, const LinPosUnit input,
                 const LinPosUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case LinPosUnit::FT: {
      in_val = val * 0.3048f;
      break;
    }
    case LinPosUnit::M: {
      in_val = val;
      break;
    }
    case LinPosUnit::KM: {
      in_val = val * 1000.0f;
      break;
    }
    case LinPosUnit::IN: {
      in_val = val * 0.0254f;
      break;
    }
    case LinPosUnit::MI: {
      in_val = val * 1609.344f;
      break;
    }
    case LinPosUnit::NAUT_MI: {
      in_val = val * 1852.0f;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case LinPosUnit::FT: {
      out_val = in_val / 0.3048f;
      break;
    }
    case LinPosUnit::M: {
      out_val = in_val;
      break;
    }
    case LinPosUnit::KM: {
      out_val = in_val / 1000.0f;
      break;
    }
    case LinPosUnit::IN: {
      out_val = in_val / 0.0254f;
      break;
    }
    case LinPosUnit::MI: {
      out_val = in_val / 1609.344f;
      break;
    }
    case LinPosUnit::NAUT_MI: {
      out_val = in_val / 1852.0f;
      break;
    }
  }
  return out_val;
}

double convlength(const double val, const LinPosUnit input,
                 const LinPosUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  double in_val;
  switch (input) {
    case LinPosUnit::FT: {
      in_val = val * 0.3048;
      break;
    }
    case LinPosUnit::M: {
      in_val = val;
      break;
    }
    case LinPosUnit::KM: {
      in_val = val * 1000.0;
      break;
    }
    case LinPosUnit::IN: {
      in_val = val * 0.0254;
      break;
    }
    case LinPosUnit::MI: {
      in_val = val * 1609.344;
      break;
    }
    case LinPosUnit::NAUT_MI: {
      in_val = val * 1852.0;
      break;
    }
  }
  /* Convert to output */
  double out_val;
  switch (output) {
    case LinPosUnit::FT: {
      out_val = in_val / 0.3048;
      break;
    }
    case LinPosUnit::M: {
      out_val = in_val;
      break;
    }
    case LinPosUnit::KM: {
      out_val = in_val / 1000.0;
      break;
    }
    case LinPosUnit::IN: {
      out_val = in_val / 0.0254;
      break;
    }
    case LinPosUnit::MI: {
      out_val = in_val / 1609.344;
      break;
    }
    case LinPosUnit::NAUT_MI: {
      out_val = in_val / 1852.0;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs
