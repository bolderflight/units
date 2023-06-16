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

#include "convacc.h"  // NOLINT

namespace bfs {

/* 
* Utility to convert between linear acceleration units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e. 'convacc(1, LinAccUnit::G, LinAccUnit::MPS2)'
* converts 1 G to m/s/s.
*/
float convacc(const float val, const LinAccUnit input,
              const LinAccUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case LinAccUnit::FPS2: {
      in_val = val * 0.3048f;
      break;
    }
    case LinAccUnit::MPS2: {
      in_val = val;
      break;
    }
    case LinAccUnit::KPS2: {
      in_val = val * 1000.0f;
      break;
    }
    case LinAccUnit::IPS2: {
      in_val = val * 0.0254f;
      break;
    }
    case LinAccUnit::KPHPS: {
      in_val = val * 1000.0f / 3600.0f;
      break;
    }
    case LinAccUnit::MPHPS: {
      in_val = val * 1609.344f / 3600.0f;
      break;
    }
    case LinAccUnit::G: {
      in_val = val * 9.80665f;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case LinAccUnit::FPS2: {
      out_val = in_val / 0.3048f;
      break;
    }
    case LinAccUnit::MPS2: {
      out_val = in_val;
      break;
    }
    case LinAccUnit::KPS2: {
      out_val = in_val / 1000.0f;
      break;
    }
    case LinAccUnit::IPS2: {
      out_val = in_val / 0.0254f;
      break;
    }
    case LinAccUnit::KPHPS: {
      out_val = in_val / 1000.0f * 3600.0f;
      break;
    }
    case LinAccUnit::MPHPS: {
      out_val = in_val / 1609.344f * 3600.0f;
      break;
    }
    case LinAccUnit::G: {
      out_val = in_val / 9.80665f;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs
