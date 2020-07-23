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

This will build the library, an example executable called *global_defs_example*, and an executable for testing using the Google Test framework, called *global_defs_test*. The example executable source file is located at *examples/global_defs_example.cc*. This code is built and tested on AARCH64 and AMD64 system running Linux and AMD64 systems running the Windows Subsystem for Linux (WSL).

## Namespace
Constants and Conversions are within the namespace *global*.

## Constants

### Namespace
Constants are within the namespace *constants*.

### Values
The following constants are templated, use a template parameter to specify the native type to return the constant in.

**PI** pi.

```C++
double my_pi = constants::PI<double>;
```

**G_MPS2** Gravitional acceleration in units of m/s/s.

```C++
int my_grav = constants::G_MPS2<int>;
```

## Conversions

### Namespace
Conversions are within the namepsace *conversions*.

### Functions
The following functions are available to convert between units. All functions are templated based off the input type - for example, if a single precision float is input, a single precision output is returned. Similarly if an int is input, an int is returned.

**M_to_Ft(m)** Converts meters to feet.

```C++
std::cout << conversions::M_to_Ft(0.3048) << std::endl; // 1.0
```

**Ft_to_M(ft)** Converts feet to meters.

```C++
std::cout << conversions::Ft_to_M(1.0) << std::endl; // 0.3048
```

**Rad_to_Deg(rad)** Converts radians to degrees.

```C++
std::cout << conversions::Rad_to_Deg(constants::PI<double>) << std::endl; // 180.0
```

**Deg_to_Rad(deg)** Converts degrees to radians.

```C++
std::cout << conversions::Deg_to_Rad(180.0) << std::endl; // 3.14
```

**G_to_Mps2(g)** Converts acceleration in g's to m/s/s.

```C++
std::cout << conversions::G_to_Mps2(1.0) << std::endl; // 9.80665
```

**Mps2_to_G(mss)** Converts acceleration in m/s/s to g's.

```C++
std::cout << conversions::Mps2_to_G(9.80665) << std::endl; // 1.0
```

**Psi_to_Pa(psi)** Converts pressure in PSI to Pascal, Pa.

```C++
std::cout << conversions::Psi_to_Pa(1.0f) << std::endl; // 6894.757293168361
```

**Pa_to_Psi(pa)** Converts pressure in Pascal to PSI.

```C++
std::cout << conversions::Pa_to_Psi(1.0f) << std::endl; // 0.0001450377377302092f
```

**Atm_to_Pa(atm)** Converts pressure to Standard Atmospheres to Pascal.

```C++
std::cout << conversions::Atm_to_Pa(1.0f) << std::endl; // 101325.0f
```

**Pa_to_Atm(pa)** Converts pressure in Pascal to Standard Atmospheres.

```C++
std::cout << conversions::Pa_to_Atm(101325.0) << std::endl; // 1.0
```

**Mbar_to_Pa(mbar)** Converts pressure in millibars to Pascal.

```C++
std::cout << conversions::Mbar_to_Pa(1.0) << std::endl; // 100.0
```

**Pa_to_Mbar(pa)** Converts pressure in Pascal to millibar.

```C++
std::cout << conversions::Pa_to_Mbar(1.0) << std::endl; // 0.01
```

**InHg_to_Pa(inhg)** Converts pressure in inches of mercury to Pascal.

```C++
std::cout << conversions::InHg_to_Pa(1.0f) << std::endl; // 3386.388640341f
```

**Pa_to_InHg(pa)** Converts pressure in Pascal to inches of mercury.

```C++
std::cout << conversions::Pa_to_InHg(1.0f) << std::endl; // 0.0002952998330101009f
```

**C_to_F(c)** Converts temperature in Celsius to Fahrenheit.

```C++
std::cout << conversions::C_to_F(10.0f) << std::endl; // 50.0f
```

**F_to_C(f)** Converts temperature in Fahrenheit to Celsius.

```C++
std::cout << conversions::F_to_C(50.0f) << std::endl; // 10.0f
```

**C_to_K(c)** Converts temperature in Celsius to Kelvin.

```C++
std::cout << conversions::C_to_K(10.0) << std::endl; // 283.15
```

**K_to_C(k)** Converts temperature in Kelvin to Celsius.

```C++
std::cout << conversions::K_to_C(50.0) << std::endl; // -223.15
```

**Mps_to_Kt(mps)** Converts speed in m/s to knots.

```C++
std::cout << conversions::Mps_to_Kt(30.0) << std::endl; // 58.3153
```

**Kt_to_Mps(kt)** Converts speed in knots to m/s.

```C++
std::cout << conversions::Kt_to_Mps(120.0) << std::endl; // 61.7333
```

**Kg_to_Slug(kg)** Converts mass in kilograms to slugs.

```C++
std::cout << conversions::Kg_to_Slug(120.0) << std::endl;  // 8.22261
```

**Slug_to_Kg(slug)** Converts mass in slugs to kilograms.

```C++
std::cout << conversions::Slug_to_Kg(120.0) << std::endl;  // 1751.27
```
