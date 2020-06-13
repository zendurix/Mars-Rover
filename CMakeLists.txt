cmake_minimum_required(VERSION 3.16)

project(GRAFIKA_PROJ)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Main src/main.cpp
                    src/math.cpp 
                    src/mesh.cpp
                    src/Object3d.cpp
                    src/Renderer.cpp
                    src/primitives3d.cpp
                    src/Map.cpp
                    )


target_precompile_headers(Main PRIVATE src/pch.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(Main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )