cmake_minimum_required(VERSION 3.21.4)
project(Test)
set(CMAKE_CPP_STANDARD 11)
set(CMAKE_CPP_STANDARD_REQUIRED True)

add_subdirectory(Elevator)
add_subdirectory(States)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Elevator States)
