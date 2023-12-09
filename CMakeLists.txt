cmake_minimum_required(VERSION 3.25)
project(algorithm-team-6 C)

set(CMAKE_C_STANDARD 11)

#if (CMAKE_BUILD_TYPE MATCHES Debug)
#    add_definitions(-DDEBUG)
#endif()

add_executable(algorithm-team-6 index.c timer/timer.c timer/timer.h)
