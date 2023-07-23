
cmake_minimum_required(VERSION 3.26)

project(eth LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fmodules")

find_package(cpr REQUIRED)

add_executable(eth main.cpp)
target_link_libraries(eth PRIVATE cpr::cpr)
