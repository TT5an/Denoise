cmake_minimum_required(VERSION 3.22)

project(DenoiseEngine)

# generate lib in windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(DenoiseEngine STATIC "")

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)

add_subdirectory(Runtime)
add_subdirectory(ThirdParty/glfw)

target_link_libraries(DenoiseEngine PRIVATE glfw)
