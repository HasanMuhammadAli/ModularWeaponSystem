cmake_minimum_required(VERSION 3.16)
project(ModularWeaponSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Pick up every .cpp under src/ automatically, so later branches
# only add files and never need to touch this list.
file(GLOB_RECURSE SHOOTER_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(game main.cpp ${SHOOTER_SOURCES})
target_include_directories(game PRIVATE include)

if(MSVC)
    target_compile_options(game PRIVATE /W4)
else()
    target_compile_options(game PRIVATE -Wall -Wextra)
endif()