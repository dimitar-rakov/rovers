cmake_minimum_required(VERSION 3.5)

project(Rovers_tests)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

file(GLOB SOURCES "./src/*.cpp")

add_executable(${PROJECT_NAME} unit_tests.cpp ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GTEST_INCLUDE_DIR} ../include)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest pthread rov_lib)
