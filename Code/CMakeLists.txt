cmake_minimum_required(VERSION 3.16)
project(Proj)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proj main.cpp Engine.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


add_subdirectory(glfw-3.3.2)
target_link_libraries(Proj glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Proj OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(Proj GLEW::GLEW)

