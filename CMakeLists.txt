cmake_minimum_required(VERSION 3.30)

project(capscalate)

set(CMAKE_CXX_STANDARD 23)

add_executable(capscalate
        src/main.cpp
        src/exploits.cpp
        src/exploits.h
        src/helpers.cpp
        src/helpers.h)

target_link_libraries(capscalate cap)

project(evillib)

add_library(evillib SHARED
        libsrc/evillib.c
        libsrc/injected.c
        libsrc/injected.h
)

project(rooter)

add_executable(rooter
        rootersrc/main.cpp
        rootersrc/main.cpp
)