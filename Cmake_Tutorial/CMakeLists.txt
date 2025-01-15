cmake_minimum_required(VERSION 3.5.0)
project(CMake_Testing VERSION 0.1.0 LANGUAGES C CXX)



include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CPack)

add_executable(CMake_Testing main.cpp NFL_Players.cpp)