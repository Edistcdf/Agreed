cmake_minimum_required(VERSION 3.10)
project(agreed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
include_directories(include)

add_executable(
    agreed
    src/main.cpp
    src/client.cpp
)

target_link_libraries(agreed Qt5::Core Qt5::Gui Qt5::Widgets)

enable_testing()
add_executable(gogo_gadget test/test.cpp)
target_link_libraries(gogo_gadget gtest gtest_main)
add_test(NAME dagsMeTest COMMAND gogo_gadget)
