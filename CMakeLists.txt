cmake_minimum_required(VERSION 3.27)
project(DungeonQuad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        src/KeyboardInput.hpp
        src/Window.hpp
        src/KeyboardInput.cpp
        src/Window.cpp)
add_executable(DungeonQuad ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(DungeonQuad sfml-system sfml-window sfml-graphics sfml-audio sfml-network)