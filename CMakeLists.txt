cmake_minimum_required(VERSION 3.24)
project(PJC)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googleTest)