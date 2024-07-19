cmake_minimum_required(VERSION 3.22)

project(DenoiseEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#resource dir configuration
add_definitions(-DDE_DEFINE_RES_ROOT_DIR=\"${CMAKE_SOURCE_DIR}/Resource/\")
set(DE_DEFINE_RES_ROOT_DIR "${CMAKE_SOURCE_DIR}/Resource/")



list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(Engine)
include_directories(Sandbox)

# ThirdParty
include_directories(Engine/ThirdParty/glfw/include)
include_directories(Engine/ThirdParty/glad/include)
include_directories(Engine/ThirdParty/spdlog/include)



add_subdirectory(Engine)
add_subdirectory(Sandbox)
