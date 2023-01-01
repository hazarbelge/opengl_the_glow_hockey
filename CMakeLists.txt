cmake_minimum_required(VERSION 3.23)
project(the_glow_hockey)

set(CMAKE_CXX_STANDARD 17)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(the_glow_hockey main.cpp Texture.cpp)
file(COPY textures DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(the_glow_hockey PRIVATE OpenGL::GL OpenGL::GLU GLUT::GLUT)

