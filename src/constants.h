/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2022 Bolder Flight Systems Inc
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

#ifndef UNITS_SRC_CONSTANTS_H_  // NOLINT
#define UNITS_SRC_CONSTANTS_H_

namespace bfs {
/*
* PI and 2*PI constants. Normally M_PI would be used, but this is not
* available on all targets (i.e. Cortex M). Arduino defined PI for use in
* their ecosystem. We're using BFS_PI and BFS_2PI to avoid naming conflicts
* and provide a consistent source for PI across targets.
*/
template<typename T>
static constexpr T BFS_PI =
  static_cast<T>(3.14159265358979323846264338327950288);
template<typename T>
static constexpr T BFS_2PI = static_cast<T>(2) *
  static_cast<T>(3.14159265358979323846264338327950288);
/* Gravitational Acceleration */
template<typename T>
static constexpr T G_MPS2 = static_cast<T>(9.80665);

}  // namespace bfs

#endif  // UNITS_SRC_CONSTANTS_H_ NOLINT
