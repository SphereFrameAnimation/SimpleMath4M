#Environment config
cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)

#Project
set(PROJECT_NAME SimpleMath4M)
project(${PROJECT_NAME})

#Source and lib
set(SOURCE_FILES src/PluginMain.cpp src/PluginMain.hpp src/Add1FNode.cpp src/Add1FNode.hpp)
set(LIBRARIES OpenMaya Foundation)

#Build
build_plugin()