cmake_minimum_required(VERSION 3.8)

project(router C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0")

add_executable(
        test main.c
        pf_packet.c
)