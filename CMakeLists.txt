cmake_minimum_required(VERSION 3.26)
project(tetriz)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tetriz.map DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

aux_source_directory(. src)
add_executable(tetriz ${src})
