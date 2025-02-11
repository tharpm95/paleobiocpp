cmake_minimum_required(VERSION 3.5)

project(SimpleQtApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(SimpleQtApp main.cpp)

target_link_libraries(SimpleQtApp Qt5::Widgets)