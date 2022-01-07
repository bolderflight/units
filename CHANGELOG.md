# Changelog

## v4.1.0
- Moved airdata specific constants to the airdata library

## v4.0.4
- Added millibar

## v4.0.3
- Updated minimum CMake version to 3.14 to support FetchContent_MakeAvailable

## v4.0.2
- Improved resolution of PI

## v4.0.1
- Updated preprocessor directives to more easily define when Arduino IDE is used
- Updated README to better detail the Arduino support
- Fixed Arduino keywords.txt

## v4.0.0
- Updated directory structure to support Arduino in addition to CMake builds
- Added an Arduino example
- Updated README

## v3.3.0
- Added hectopascals unit to convpres

## v3.2.0
- Added atmospheric constants

## v3.1.0
- Added gravitational acceleration constant

## v3.0.0
- Switched to namespace bfs
- Switched to MATLAB equivalent conversion functions: convlength, convvel, convacc, convang, convangvel, convangacc, convforce, convmass, convdensity, convpres, convtemp
- Added rad2deg and deg2rad

## v2.0.0
- renamed from global_defs to units, which more appropriately describes the library function
- updated contributing
- updated CI/CD to include line length limits
- modified units.h to remove "global" namespace
- updated example, test, and readme

## v1.1.2
- Updated contributing

## v1.1.1
- Updated license to MIT

## v1.1.0
- Added Gauss to uT and uT to Gauss conversion

## v1.0.0
- Initial baseline
