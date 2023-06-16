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

#include "convangvel.h"  // NOLINT
#include "constants.h"  // NOLINT

namespace bfs {

float convangvel(const float val, const AngVelUnit input,
                 const AngVelUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case AngVelUnit::DEGPS: {
      in_val = val * BFS_PI_FLOAT / 180.0f;
      break;
    }
    case AngVelUnit::RADPS: {
      in_val = val;
      break;
    }
    case AngVelUnit::RPM: {
      in_val = val * BFS_2PI_FLOAT / 60.0f;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case AngVelUnit::DEGPS: {
      out_val = in_val * 180.0f / BFS_PI_FLOAT;
      break;
    }
    case AngVelUnit::RADPS: {
      out_val = in_val;
      break;
    }
    case AngVelUnit::RPM: {
      out_val = in_val / BFS_2PI_FLOAT * 60.0f;
      break;
    }
  }
  return out_val;
}

}  // namespace bfs
