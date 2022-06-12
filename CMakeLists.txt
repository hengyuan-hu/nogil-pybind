CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
project(bug)
# add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0) #

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Wno-register -fPIC -march=native -Wfatal-errors")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pybind11)
pybind11_add_module(hle ${CMAKE_CURRENT_SOURCE_DIR}/pybind.cc)
