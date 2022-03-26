cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

project(cpp-algorithms)

include_directories(include)
add_library(singly_linked_list SHARED src/linked_list/node.cpp src/linked_list/singly_linked_list.cpp)

add_executable(cpp-algorithms src/main.cpp)
target_link_libraries(cpp-algorithms singly_linked_list)

add_subdirectory(test)
