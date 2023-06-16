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

#include "convang.h"  // NOLINT
#include "constants.h"  // NOLINT

namespace bfs {

float convang(const float val, const AngPosUnit input,
              const AngPosUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  float in_val;
  switch (input) {
    case AngPosUnit::DEG: {
      in_val = val * BFS_PI_FLOAT / 180.0f;
      break;
    }
    case AngPosUnit::RAD: {
      in_val = val;
      break;
    }
    case AngPosUnit::REV: {
      in_val = val * BFS_2PI_FLOAT;
      break;
    }
  }
  /* Convert to output */
  float out_val;
  switch (output) {
    case AngPosUnit::DEG: {
      out_val = in_val * 180.0f / BFS_PI_FLOAT;
      break;
    }
    case AngPosUnit::RAD: {
      out_val = in_val;
      break;
    }
    case AngPosUnit::REV: {
      out_val = in_val / BFS_2PI_FLOAT;
      break;
    }
  }
  return out_val;
}

double convang(const double val, const AngPosUnit input,
               const AngPosUnit output) {
  /* Trivial case where input and output units are the same */
  if (input == output) {return val;}
  /* Convert input to SI */
  double in_val;
  switch (input) {
    case AngPosUnit::DEG: {
      in_val = val * BFS_PI_DOUBLE / 180.0;
      break;
    }
    case AngPosUnit::RAD: {
      in_val = val;
      break;
    }
    case AngPosUnit::REV: {
      in_val = val * BFS_2PI_DOUBLE;
      break;
    }
  }
  /* Convert to output */
  double out_val;
  switch (output) {
    case AngPosUnit::DEG: {
      out_val = in_val * 180.0 / BFS_PI_DOUBLE;
      break;
    }
    case AngPosUnit::RAD: {
      out_val = in_val;
      break;
    }
    case AngPosUnit::REV: {
      out_val = in_val / BFS_2PI_DOUBLE;
      break;
    }
  }
  return out_val;
}

float rad2deg(const float val) {
  return convang(val, AngPosUnit::RAD, AngPosUnit::DEG);
}

double rad2deg(const double val) {
  return convang(val, AngPosUnit::RAD, AngPosUnit::DEG);
}

float deg2rad(const float val) {
  return convang(val, AngPosUnit::DEG, AngPosUnit::RAD);
}

double deg2rad(const double val) {
  return convang(val, AngPosUnit::DEG, AngPosUnit::RAD);
}

}  // namespace bfs
