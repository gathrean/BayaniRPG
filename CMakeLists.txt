cmake_minimum_required(VERSION 3.27)
project(BayaniRPG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp
        src/Input/KeyboardInput.hpp
        src/Window/Window.hpp
        src/Input/KeyboardInput.cpp
        src/Entities/Player/Player.hpp
        src/Entities/Projectile/Projectile.hpp
        src/Entities/Projectile/Projectile.cpp
        src/Entities/Player/Player.cpp
        src/Window/Window.cpp
        src/Entities/Enemy/Enemy.hpp
        src/Entities/Enemy/Enemy.cpp
        src/Game/Game.hpp
        src/Game/Game.cpp
        src/Entities/Entity.hpp
        src/Entities/HealthBar/HealthBar.hpp
        src/Entities/HealthBar/HealthBar.cpp
)
add_executable(BayaniRPG ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(BayaniRPG sfml-system sfml-window sfml-graphics sfml-audio sfml-network)