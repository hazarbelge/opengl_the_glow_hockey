cmake_minimum_required(VERSION 3.24)
project(co-op-ball-game)

set(CMAKE_CXX_STANDARD 17)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(co-op-ball-game main.cpp Texture.cpp button.h mouse.h)

target_link_libraries(co-op-ball-game PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)

