cmake_minimum_required(VERSION 3.25)

project(qruncat)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set (SRCS main.cpp mainwindow.cpp)
set (HEADERS mainwindow.h)
# set (UIS )
set (QRC resources.qrc)

add_executable(qruncat ${SRCS} ${QRC})
target_link_libraries(qruncat Qt5::Core Qt5::Gui Qt5::Widgets)
