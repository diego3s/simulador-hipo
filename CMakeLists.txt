cmake_minimum_required(VERSION 3.25.1)
project(simulador-hipo)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML COMPONENTS graphics window system)

add_executable(simulador-hipo src/main.cpp
        include/hipo.h
        include/cpu.h
        include/memory.h
        include/instructions.h
        src/hipo.cpp
        include/errorHandler.h
        src/instructions.cpp
        src/errorHandler.cpp
        src/memory.cpp
        src/cpu.cpp
        src/UIHipo.cpp
        include/UIHipo.h
)

target_link_libraries(simulador-hipo sfml-graphics sfml-window sfml-system)