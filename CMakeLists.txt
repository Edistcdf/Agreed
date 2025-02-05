cmake_minimum_required(VERSION 3.10)
project(agreed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Not quite sure which are needed
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS REQUIRED Widgets)

add_executable(
  QtWindow
  src/gui.cpp
  src/mainwindow.cpp
)

target_include_directories(
  QtWindow
  PRIVATE
  include
)

target_link_libraries(
  QtWindow
  PRIVATE
  Qt5::Widgets
)

add_executable(
  agreed
  src/main.cpp
  src/client.cpp
)

target_include_directories(
  agreed
  PRIVATE
  include
)

enable_testing()
add_executable(gogo_gadget test/test.cpp)
target_link_libraries(gogo_gadget gtest gtest_main)
add_test(NAME dagsMeTest COMMAND gogo_gadget)
