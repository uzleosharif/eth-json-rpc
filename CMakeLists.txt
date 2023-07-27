
cmake_minimum_required(VERSION 3.26)

project(eth LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -fmodules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wpedantic -Wconversion")

find_package(cpr REQUIRED)
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED)

add_executable(eth src/main.cpp src/types.cpp src/utils.cpp)
target_link_libraries(eth PRIVATE 
  cpr::cpr fmt::fmt nlohmann_json::nlohmann_json Boost::headers)
target_include_directories(eth PUBLIC include/)
