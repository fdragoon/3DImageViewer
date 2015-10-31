cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)
if(POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW) # CMake 3.0
endif()
if(POLICY CMP0053)
  cmake_policy(SET CMP0053 NEW) # CMake 3.1
endif()

project (Homework)

find_package(VTK REQUIRED)

include(${VTK_USE_FILE})

set(Homework_SRCS 
source.cpp
vtkImageViewer3.cpp
vtkImagePlaneWidget3.cpp
)

add_executable(Homework MACOSX_BUNDLE ${Homework_SRCS})

target_link_libraries(Homework ${VTK_LIBRARIES})
