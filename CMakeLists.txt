cmake_minimum_required(VERSION 3.9)

project(minimesh
	LANGUAGES CXX
	VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/includes
    ${PROJECT_SOURCE_DIR}/external/toml11
    ${PROJECT_SOURCE_DIR}/external/cxxopts/include
    ${PROJECT_SOURCE_DIR}/tests
)

set(EXE_SOURCES
  src/options.cpp
  # Add other source files here, one by line
)

add_executable(${PROJECT_NAME} src/main.cpp ${EXE_SOURCES})

set(VTK_DIR "${VTK_INSTALL_DIR}/lib/cmake/vtk-8.2")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

target_link_libraries(${PROJECT_NAME} ${VTK_LIBRARIES})

install(TARGETS minimesh DESTINATION bin)

set(GTEST_ROOT "${GOOGLETEST_INSTALL_DIR}")
find_package(GTest REQUIRED)

add_executable(test_minimesh tests/unit_tests.cpp tests/test_suite.hpp ${EXE_SOURCES})
target_link_libraries(test_minimesh ${VTK_LIBRARIES} GTest::GTest pthread)

add_test(
  NAME merge
  COMMAND test_minimesh
)
