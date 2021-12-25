cmake_minimum_required(VERSION 3.20)
project(ZombieArena)


set(SOURCE_FILES
        includes/bullet.h
        includes/healthyAI.h
        includes/player.h
        includes/textureHolder.h
        includes/Virus.h
        includes/virusArena.h
        includes/zombieHorder.h
        includes/ResourcePath.hpp
        src/createBackground.cpp
        src/healthyAI.cpp
        src/Infection.cpp
        src/player.cpp
        src/textureHolder.cpp
        src/virus.cpp
        src/virusHorde.cpp
        src/resourcePath.cpp)

include_directories(includes)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "D:/SFML/lib/cmake/SFML")

find_package(SFML 2.5
        COMPONENTS
        system window network audio REQUIRED)


add_executable(ZombieArena ${SOURCE_FILES})
target_link_libraries(ZombieArena PRIVATE
        sfml-system sfml-window sfml-graphics sfml-network sfml-audio)