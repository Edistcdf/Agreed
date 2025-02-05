cmake_minimum_required(VERSION 3.10)
project(agreed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(
    agreed
    src/main.cpp
    src/client.cpp
)

enable_testing()
add_executable(gogo_gadget test/test.cpp)
target_link_libraries(gogo_gadget gtest gtest_main)
add_test(NAME dagsMeTest COMMAND gogo_gadget)
