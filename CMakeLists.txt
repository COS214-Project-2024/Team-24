cmake_minimum_required(VERSION 3.10)
project(CitySimulation)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add source files
file(GLOB SOURCES "src/*.cpp")
add_library(CityLib ${SOURCES})

# Add test executable
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(city_tests ${TEST_SOURCES})

# Link against Google Test and your library
target_link_libraries(city_tests
    GTest::gtest_main
    CityLib
)

# Include directories
target_include_directories(CityLib PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(city_tests PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Add tests to CTest
include(GoogleTest)
gtest_discover_tests(city_tests)