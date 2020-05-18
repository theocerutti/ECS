cmake_minimum_required(VERSION 3.11)

project(IndieStudio)

include_directories(include)

# Set sources
set(SRCS
    main.cpp
    src/ecs/engine/Engine.cpp
    src/ecs/entities/Entity.cpp
    src/ecs/systems/System.cpp
    src/systems/TestSystem.cpp
    )

add_executable(myecs ${SRCS})