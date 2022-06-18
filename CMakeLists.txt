cmake_minimum_required(VERSION 3.10)
project(AttractUI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES *.h *.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
add_executable(AttractUI ${SOURCE_FILES})
