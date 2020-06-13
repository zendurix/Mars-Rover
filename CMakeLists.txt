cmake_minimum_required(VERSION 3.16)

project(Rover)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Rover src/main.cpp
                    src/math.cpp 
                    src/Object3d.cpp
                    src/Renderer.cpp
                    src/primitives3d.cpp
                    src/Map.cpp
                    )


target_precompile_headers(Rover PRIVATE src/pch.hpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(Rover ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )