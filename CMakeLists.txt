cmake_minimum_required(VERSION 3.14)
# Project information
project(Units
  VERSION 4.1.0
  DESCRIPTION "Constants and unit conversions."
  LANGUAGES CXX
)
# Add the library target
add_library(units INTERFACE)
# Setup include directories 
target_include_directories(units INTERFACE src/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(units_example examples/cmake/units_example.cc)
	# Add the includes
	target_include_directories(units_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(units_example
		PRIVATE
			units
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(units_test tests/units_test.cc)
	# Add the includes
	target_include_directories(units_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(units_test
		PRIVATE 
			units
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(units_test)
endif()
