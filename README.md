# global_defs
This library defines common constants and unit conversions.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *global_defs*. The header is added as:

```
#include "global_defs/global_defs.h"
```
Note that you'll need CMake version 3.13 or above; it is recommended to build and install CMake from source, directions are located in the [CMake GitLab repository](https://github.com/Kitware/CMake).

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *global_defs_example*, and an executable for testing using the Google Test framework, called *global_defs_test*. The example executable source file is located at *examples/global_defs_example.cc*. This code is built and tested on an AMD64 system running Linux and is likely to build on AMD64 systems running the Windows Subsystem for Linux (WSL). As an alternative, a Docker container has been [built](https://hub.docker.com/r/flybrianfly/gcc-cmake) which extends the gcc container to include CMake support and supports building this library.

## Constants

### Namespace
Constants are within the namespace *constants*.

### Values
The following constants are defined as both single and double precision floats. An appended lower case *f* is used to specify a single precision float. For example *PI* defines pi as a double precision float whereas *PIf* is pi as a single precision float.

**PI** pi.

**G_MSS** Gravitional acceleration in units of m/s/s.

## Conversions

### Namespace
Conversions are within the namepsace *conversions*.

### Functions
The following functions are available to convert between units. All functions are overloaded between single and double precision floating point - if a single precision float is input, a single precision output is returned. Similarly if a double precision float is input, a double precision output is returned.

**M2Ft(m)** Converts meters to feet.

```C++
std::cout << conversions::M2Ft(0.3048) << std::endl; // 1.0
```

**Ft2M(ft)** Converts feet to meters.

```C++
std::cout << conversions::Ft2M(1.0) << std::endl; // 0.3048
```

**Rad2Deg(rad)** Converts radians to degrees.

```C++
std::cout << conversions::Rad2Deg(constants::PI) << std::endl; // 180.0
```

**Deg2Rad(deg)** Converts degrees to radians.

```C++
std::cout << conversions::Deg2Rad(180.0) << std::endl; // 3.14
```

**G2Mss(g)** Converts acceleration in g's to m/s/s.

```C++
std::cout << conversions::G2Mss(1.0) << std::endl; // 9.80665
```

**Mss2G(mss)** Converts acceleration in m/s/s to g's.

```C++
std::cout << conversions::Mss2G(9.80665) << std::endl; // 1.0
```

**Psi2Pa(psi)** Converts pressure in PSI to Pascal, Pa.

```C++
std::cout << conversions::Psi2Pa(1.0f) << std::endl; // 6894.757293168361
```

**Pa2Psi(pa)** Converts pressure in Pascal to PSI.

```C++
std::cout << conversions::Pa2Psi(1.0f) << std::endl; // 0.0001450377377302092f
```

**Atm2Pa(atm)** Converts pressure to Standard Atmospheres to Pascal.

```C++
std::cout << conversions::Atm2Pa(1.0f) << std::endl; // 101325.0f
```

**Pa2Atm(pa)** Converts pressure in Pascal to Standard Atmospheres.

```C++
std::cout << conversions::Pa2Atm(101325.0) << std::endl; // 1.0
```

**Mbar2Pa(mbar)** Converts pressure in millibars to Pascal.

```C++
std::cout << conversions::Mbar2Pa(1.0) << std::endl; // 100.0
```

**Pa2Mbar(pa)** Converts pressure in Pascal to millibar.

```C++
std::cout << conversions::Pa2Mbar(1.0) << std::endl; // 0.01
```

**InHg2Pa(inhg)** Converts pressure in inches of mercury to Pascal.

```C++
std::cout << conversions::InHg2Pa(1.0f) << std::endl; // 3386.388640341f
```

**Pa2InHg(pa)** Converts pressure in Pascal to inches of mercury.

```C++
std::cout << conversions::Pa2InHg(1.0f) << std::endl; // 0.0002952998330101009f
```

**C2F(c)** Converts temperature in Celsius to Fahrenheit.

```C++
std::cout << conversions::C2F(10.0f) << std::endl; // 50.0f
```

**F2C(f)** Converts temperature in Fahrenheit to Celsius.

```C++
std::cout << conversions::F2C(50.0f) << std::endl; // 10.0f
```

**C2K(c)** Converts temperature in Celsius to Kelvin.

```C++
std::cout << conversions::C2K(10.0) << std::endl; // 283.15
```

**K2C(k)** Converts temperature in Kelvin to Celsius.

```C++
std::cout << conversions::K2C(50.0) << std::endl; // -223.15
```

**F2R(f)** Converts temperature in Fahrenheit to Rankine.

```C++
std::cout << conversions::F2R(50.0) << std::endl; // 509.67
```

**R2F(r)** Converts temperature in Rankine to Fahrenheit.

```C++
std::cout << conversions::R2F(50.0) << std::endl; // -409.67
```