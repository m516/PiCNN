cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

project(Net)

#The version number
set(Net_VERSION_MAJOR 0)
set(Net_VERSION_MINOR 0)

#Include libraries
include_directories("${PROJECT_SOURCE_DIR}/lib")

#Add neural network directory
add_subdirectory(lib/NeuralNetwork)

#Create the executable
add_executable(
	Net
	tests/Hello_NeuralNet/main.cpp
)

#Link the neural network to the Net project
target_link_libraries (Net NeuralNetwork)
