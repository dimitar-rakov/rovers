cmake_minimum_required(VERSION 3.5)

project(Rovers)

add_definitions (-fpermissive -std=c++14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


file(GLOB SOURCES "src/*.cpp")

include_directories(include)
add_library(rov_lib ${SOURCES})
add_executable(${PROJECT_NAME} "main.cpp" ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include rov_lib)
add_subdirectory(tests)
