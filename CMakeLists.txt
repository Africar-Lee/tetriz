cmake_minimum_required(VERSION 3.26)
project(tetriz)

set(CXX_STANDARD 20)

aux_source_directory(. src)
add_executable(tetriz ${src})
