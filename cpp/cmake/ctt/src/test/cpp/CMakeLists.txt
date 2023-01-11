cmake_minimum_required(VERSION 3.20)
project(test)
add_executable(test main.cpp)
target_link_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/../../libDemo/cpp/build/)
target_link_libraries(test mearlymath)

