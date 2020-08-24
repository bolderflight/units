cmake_minimum_required(VERSION 3.13)
# Project information
project(GlobalDefs
  VERSION 1.0.0
  DESCRIPTION "Global definitions, constants, and unit conversions."
  LANGUAGES CXX
)
# Add the library target
add_library(global_defs INTERFACE)
# Setup include directories 
target_include_directories(global_defs INTERFACE include/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(global_defs_example examples/global_defs_example.cc)
	# Add the includes
	target_include_directories(global_defs_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(global_defs_example
		PRIVATE 
			global_defs
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY 	https://github.com/google/googletest.git
		GIT_TAG 				release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(global_defs_test tests/global_defs_test.cc)
	# Add the includes
	target_include_directories(global_defs_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(global_defs_test
		PRIVATE 
			global_defs
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(global_defs_test)
endif()
