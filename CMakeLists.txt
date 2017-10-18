cmake_minimum_required (VERSION 2.6)
project (ZombieArena)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set (SFML_DIR /home/tomek/projects/SFML)
set (SOURCES_DIR /home/tomek/projects/ZombieArena)
set (SOURCE_FILES ${SOURCES_DIR}/main.cpp ${SOURCES_DIR}/Player.cpp)

add_compile_options(-std=c++14)



# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
#include_directories ("${PROJECT_SOURCE_DIR}/SFML/include")
include_directories ("${SFML_DIR}/include")

add_subdirectory (/home/tomek/projects/SFML subproject/SFML)

# add the executable
add_executable(ZombieArena ${SOURCE_FILES})
target_link_libraries (ZombieArena sfml-graphics)
target_link_libraries (ZombieArena sfml-window)
target_link_libraries (ZombieArena sfml-system)
target_link_libraries (ZombieArena sfml-audio)
