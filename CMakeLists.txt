cmake_minimum_required(VERSION 3.26)
project(mirom)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp
        App.h
        App.cpp
        Point.h
        Mirror.cpp
        Mirror.h
        math_vector.h
        math_vector.cpp
)
add_executable(mirom ${SOURCE_FILES}
        main.cpp)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(mirom sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
