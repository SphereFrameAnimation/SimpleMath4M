#Environment config
cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)
include_directories(./include)

#Project
set(PROJECT_NAME SimpleMath4M)
project(${PROJECT_NAME})

#Source and lib
set(SOURCE_FILES src/PluginMain.cpp src/Arith1FNode.cpp src/Cond1FNode.cpp src/Exp1FNode.cpp src/Arith2FNode.cpp src/Dot2FNode.cpp)
set(LIBRARIES OpenMaya Foundation)

#Build
build_plugin()