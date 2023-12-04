#Environment config
cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)
include_directories(./include)

#Variables
set(PROJECT_NAME SimpleMath4M)
set(PLUGIN_VERSION 1.0.0)
set(PLUGIN_VENDOR "SPHEREFRAME ANIMATION")

#Project and Compile definitions
project(${PROJECT_NAME} VERSION ${PLUGIN_VERSION})
add_compile_definitions(PLUGIN_VENDOR="${PLUGIN_VENDOR}")
add_compile_definitions(PLUGIN_VERSION="${PLUGIN_VERSION}")

#Source and lib
set(SOURCE_FILES
	src/PluginMain.cpp
	src/Arith1FNode.cpp
	src/Cond1FNode.cpp
	src/Exp1FNode.cpp
	src/Arith2FNode.cpp
	src/Dot2FNode.cpp
	src/Arith3FNode.cpp
	src/Dot3FNode.cpp
	src/Cross3FNode.cpp
	src/ScalarProduct2FNode.cpp
	src/ScalarProduct3FNode.cpp
	src/Vec2FNode.cpp
	src/Vec3FNode.cpp
)
set(LIBRARIES OpenMaya Foundation)

#Build
build_plugin()
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
	set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "SM4M-${PROJECT_VERSION}-WIN")
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
	set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "SM4M-${PROJECT_VERSION}-MAC")
endif()