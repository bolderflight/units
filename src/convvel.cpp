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

#include "convvel.h"  // NOLINT

namespace bfs {

float convvel(const float val, const LinVelUnit input,
              const LinVelUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case LinVelUnit::FPS: {
      in_val = val * 0.3048f;
      break;
    }
    case LinVelUnit::MPS: {
      in_val = val;
      break;
    }
    case LinVelUnit::KPS: {
      in_val = val * 1000.0f;
      break;
    }
    case LinVelUnit::IPS: {
      in_val = val * 0.0254f;
      break;
    }
    case LinVelUnit::KPH: {
      in_val = val * 1000.0f / 3600.0f;
      break;
    }
    case LinVelUnit::MPH: {
      in_val = val * 1609.344f / 3600.0f;
      break;
    }
    case LinVelUnit::KTS: {
      in_val = val * 1852.0f / 3600.0f;
      break;
    }
    case LinVelUnit::FPM: {
      in_val = val * 0.3048f / 60.0f;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case LinVelUnit::FPS: {
      out_val = in_val / 0.3048f;
      break;
    }
    case LinVelUnit::MPS: {
      out_val = in_val;
      break;
    }
    case LinVelUnit::KPS: {
      out_val = in_val / 1000.0f;
      break;
    }
    case LinVelUnit::IPS: {
      out_val = in_val / 0.0254f;
      break;
    }
    case LinVelUnit::KPH: {
      out_val = in_val / 1000.0f * 3600.0f;
      break;
    }
    case LinVelUnit::MPH: {
      out_val = in_val / 1609.344f * 3600.0f;
      break;
    }
    case LinVelUnit::KTS: {
      out_val = in_val / 1852.0f * 3600.0f;
      break;
    }
    case LinVelUnit::FPM: {
      out_val = in_val / 0.3048f * 60.0f;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs
