cmake_minimum_required(VERSION 3.10)

project(TextovaHra)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/*.cpp")

add_executable(TextovaHra ${SOURCES})
