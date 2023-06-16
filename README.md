[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Units
This library defines common unit conversions, including:
   * Linear acceleration, velocity, and position
   * Rotational acceleration, velocity, and position
   * Force
   * Density
   * Mass
   * Pressure
   * Temperature

Included constants are: 
   * Pi
   * Gravitational acceleration
   * Standard day sea level temperature
   * Standard day sea level pressure
   * Standard day sea level speed of sound
   * Standard day lapse rate
   * Gas constant
   * Molecular mass of air

This library is compatible with Arduino and with CMake build systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. This library is added as:

```C++
#include "units.h"
```

An example Arduino executable is located at *examples/arduino/units_example/units_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other devices.

## CMake
CMake is used to build this library, which is exported as a library target called *units*. The header is added as:

```C++
#include "units.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *units_example*, and an executable for testing using the Google Test framework, called *units_test*. The example executable source file is located at *examples/cmake/units_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Constants
pi and 2pi are defined as constants *BFS_PI_FLOAT* and *BFS_2PI_FLOAT* for single precision floats and *BFS_PI_DOUBLE* and *BFS_2PI_DOUBLE* for double precision.

Gravitational acceleration (m/s/s) is defined as constant *G_MPS2* as a single precision float

# Conversions

**float convlength(const float val, const LinPosUnit input, const LinPosUnit output)** converts *val* between *input* and *output* linear position units. This function is equivalent to the [MATLAB convlength](https://www.mathworks.com/help/aerotbx/ug/convlength.html) for scalar inputs. Available units are:

| Enum      | Unit            |
| ---       | ---             |
| FT        | feet            |
| M         | meters          |
| KM        | kilometers      |
| IN        | inches          |
| MI        | miles           |
| NAUT_MI   | nautical miles  |

```C++
/* Convert 10 feet to meters */
float dist_m = bfs::convlength(10.0f, bfs::LinPosUnit::FT, bfs::LinPosUnit::M);
```

**double convlength(const double val, const LinPosUnit input, const LinPosUnit output)** same as above, but with double precision.

**float convvel(const float val, const LinVelUnit input, const LinVelUnit output)** converts *val* between *input* and *output* linear velocity units. This function is equivalent to the [MATLAB convvel](https://www.mathworks.com/help/aerotbx/ug/convvel.html) for scalar inputs. Available units are:

| Enum   | Unit                         |
| ---    | ---                          |
| FPS    | feet per second, ft/s        |
| MPS    | meters per second, m/s       |
| KPS    | kilometers per second, km/s  |
| IPS    | inches per second, in/s      |
| KPH    | kilometers per hour, km/h    |
| MPH    | miles per hour, mi/h         |
| KTS    | knots                        |
| FPM    | feet per minute, ft/min      |

```C++
/* Convert 10 ft/s to m/s */
float vel_mps = bfs::convvel(10.0f, bfs::LinVelUnit::FPS, bfs::LinVelUnit::MPS);
```

**float convacc(const float val, const LinAccUnit input, const LinAccUnit output)** converts *val* between *input* and *output* linear acceleration units. This function is equivalent to the [MATLAB convacc](https://www.mathworks.com/help/aerotbx/ug/convacc.html) for scalar inputs. Available units are:

| Enum   | Unit                                      |
| ---    | ---                                       |
| FPS2   | feet per second per second, ft/s/s        |
| MPS2   | meters per second per second, m/s/s       |
| KPS2   | kilometers per second per second, km/s/s  |
| IPS2   | inches per second per second, in/s/s      |
| KPHPS  | kilometers per hour per second, km/h/s    |
| MPHPS  | miles per hour per second, mi/h/s         |
| G      | G force acceleration, G                   |

```C++
/* Convert 1 G to m/s/s */
float acc_mps2 = bfs::convacc(1.0f, bfs::LinAccUnit::G, bfs::LinAccUnit::MPS2);
```

**float convang(const float val, const AngPosUnit input, const AngPosUnit output)** converts *val* between *input* and *output* angle units. This function is equivalent to the [MATLAB convang](https://www.mathworks.com/help/aerotbx/ug/convang.html) for scalar inputs. Available units are:

| Enum  | Unit         |
| ---   | ---          |
| DEG   | degrees      |
| RAD   | radians      |
| REV   | revolutions  |

```C++
/* Convert 1 deg to rad */
float ang_rad = bfs::convang(1.0f, bfs::AngPosUnit::DEG, bfs::AngPosUnit::RAD);
```

**double convang(const double val, const AngPosUnit input, const AngPosUnit output)** same as above, but with double precision.

**float rad2deg(const float val)** converts the input from radians to degrees. This function is equivalent to the [MATLAB rad2deg](https://www.mathworks.com/help/matlab/ref/rad2deg.html) for scalar inputs.

```C++
/* Convert 1 rad to deg */
float ang_deg = bfs::rad2deg(1.0f);
```

**double rad2deg(const double val)** same as above, but with double precision.

**float deg2rad(const float val)** converts the input from degrees to radians. This function is equivalent to the [MATLAB deg2rad](https://www.mathworks.com/help/matlab/ref/deg2rad.html) for scalar inputs.

```C++
/* Convert 1 deg to rad */
float ang_rad = bfs::deg2rad(1.0f);
```

**double deg2rad(const double val)** same as above, but with double precision.

**float convangvel(const float val, const AngVelUnit input, const AngVelUnit output)** converts *val* between *input* and *output* angular velocity units. This function is equivalent to the [MATLAB convangvel](https://www.mathworks.com/help/aerotbx/ug/convangvel.html) for scalar inputs. Available units are:

| Enum   | Unit                        |
| ---    | ---                         |
| DEGPS  | degrees per second, deg/s   |
| RADPS  | radians per second, rad/s   |
| RPM    | revolutions per minute, rpm |

```C++
/* Convert 1 deg/s to rad/s */
float w_radps = bfs::convangvel(1.0f, bfs::AngVelUnit::DEGPS, bfs::AngVelUnit::RADPS);
```

**float convangacc(const float val, const AngAccUnit input, const AngAccUnit output)** converts *val* between *input* and *output* angular acceleration units. This function is equivalent to the [MATLAB convangacc](https://www.mathworks.com/help/aerotbx/ug/convangacc.html) for scalar inputs. Available units are:

| Enum    | Unit                                     |
| ---     | ---                                      |
| DEGPS2  | degrees per second per second, deg/s/s   |
| RADPS2  | radians per second per second, rad/s/s   |
| RPMPS   | revolutions per minute per second, rpm/s |

```C++
/* Convert 1 deg/s/s to rad/s/s */
float a_radps2 = bfs::convangacc(1.0f, bfs::AngAccUnit::DEGPS2, bfs::AngAccUnit::RADPS2);
```

**float convforce(const float val, const ForceUnit input, const ForceUnit output)** converts *val* between *input* and *output* force units. This function is equivalent to the [MATLAB convforce](https://www.mathworks.com/help/aerotbx/ug/convforce.html) for scalar inputs. Available units are:

| Enum | Unit        |
| ---  | ---         |
| LBF  | pound force |
| N    | Newton      |

```C++
/* Convert 1 lbf to N */
float f_n = bfs::convforce(1.0f, bfs::ForceUnit::LBF, bfs::ForceUnit::N);
```

**float convmass(const float val, const MassUnit input, const MassUnit output)** converts *val* between *input* and *output* mass units. This function is equivalent to the [MATLAB convmass](https://www.mathworks.com/help/aerotbx/ug/convmass.html) for scalar inputs. Available units are:

| Enum | Unit        |
| ---  | ---         |
| LBM  | pound mass  |
| KG   | kilograms   |
| SLUG | slugs       |

```C++
/* Convert 1 kg to slug */
float m_slug = bfs::convmass(1.0f, bfs::MassUnit::KG, bfs::MassUnit::SLUG);
```

**float convdensity(const float val, const DensityUnit input, const DensityUnit output)** converts *val* between *input* and *output* density units. This function is equivalent to the [MATLAB convdensity](https://www.mathworks.com/help/aerotbx/ug/convdensity.html) for scalar inputs. Available units are:

| Enum      | Unit                                |
| ---       | ---                                 |
| LBMPFT3   | pound mass per feet cubed, lbm/ft^3 |
| KGPM3     | kilogram per meters cubed, kg/m^3   |
| SLUGPFT3  | slug per feet cubed, slug/ft^3      |
| LBMPIN3   | pound mass per inch cubed, lbm/in^3 |

```C++
/* Convert 1 lbm/ft^3 to kg/m^3 */
float dens_kgpm3 = bfs::convdensity(1.0f, bfs::DensityUnit::LBMPFT3, bfs::DensityUnit::KGPM3);
```

**float convpres(const float val, const PresUnit input, const PresUnit output)** converts *val* between *input* and *output* pressure units. This function is equivalent to the [MATLAB convpres](https://www.mathworks.com/help/aerotbx/ug/convpres.html) for scalar inputs. Available units are:

| Enum  | Unit                        |
| ---   | ---                         |
| PSI   | pound force per square inch |
| PA    | Pascal                      |
| HPA   | Hectopascal                 |
| PSF   | pound force per square foot |
| ATM   | atmosphere                  |
| MBAR  | millibar                    |

```C++
/* Convert 1 psi to pa */
float p_pa = bfs::convpres(1.0f, bfs::PresUnit::PSI, bfs::PresUnit::PA);
```

**float convtemp(const float val, const TempUnit input, const TempUnit output)** converts *val* between *input* and *output* temperature units. This function is equivalent to the [MATLAB convtemp](https://www.mathworks.com/help/aerotbx/ug/convtemp.html) for scalar inputs. The function is templated to output using the same native type as the input - only floating point types are supported. Available units are:

| Enum  | Unit       |
| ---   | ---        |
| K     | Kelvin     |
| F     | Fahrenheit |
| C     | Celsius    |
| R     | Rankine    |

```C++
/* Convert 1 C to F */
float temp_f = bfs::convtemp(1.0f, bfs::TempUnit::C, bfs::TempUnit::F);
```
