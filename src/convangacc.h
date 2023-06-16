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

#ifndef UNITS_SRC_CONVANGACC_H_  // NOLINT
#define UNITS_SRC_CONVANGACC_H_

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <cstddef>
#include <cstdint>
#endif

#include "constants.h"  // NOLINT

namespace bfs {
/* Units for measuring angular acceleration */
enum class AngAccUnit : int8_t {
  DEGPS2,  // degrees per second per second, deg/s/s
  RADPS2,  // radians per second per second, rad/s/s
  RPMPS    // revolutions per minute per second, rpm/s
};
/* 
* Utility to convert between angular acceleration units:
* Input the value to convert, the unit the value is currently in, and the unit
* you are converting to, i.e.
* 'convangacc(1, AngAccUnit::DEGPS2, AngAccUnit::RADPS2)'
* converts 1 deg/s/s to rad/s/s.
*/
float convangacc(const float val, const AngAccUnit input,
                 const AngAccUnit output);

}  // namespace bfs

#endif  // UNITS_SRC_CONVANGACC_H_ NOLINT
