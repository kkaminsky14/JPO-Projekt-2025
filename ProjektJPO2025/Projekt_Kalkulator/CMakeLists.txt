cmake_minimum_required(VERSION 3.15)

project(Projekt_Kalkulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

set(SOURCES
    src/Kalkulator.cpp
    src/Konwersja.cpp
    src/Matematyka.cpp
)

add_library(KalkulatorLib ${SOURCES})

add_executable(Projekt_Kalkulator src/main.cpp)
target_link_libraries(Projekt_Kalkulator KalkulatorLib)

add_subdirectory(tests)
