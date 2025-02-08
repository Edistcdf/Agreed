cmake_minimum_required(VERSION 3.10)
project(agreed)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Not quite sure which are needed
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS REQUIRED Widgets)

add_library(TCPServer STATIC ${CMAKE_SOURCE_DIR}/src/TCPServer.cpp)
add_library(TCPClient STATIC ${CMAKE_SOURCE_DIR}/src/TCPClient.cpp)

target_include_directories(TCPServer PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(TCPClient PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Create the QtWindow application

# Link the libraries to the QtWindow application

add_executable(
	QtWindow
	src/gui.cpp
	src/chatwindow.cpp
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
	TCPServer
	TCPClient
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
