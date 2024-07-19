cmake_minimum_required(VERSION 3.22)
project(DenoiseEngine)

target_sources(DenoiseEngine PRIVATE
	 OpenGL/Private/OpenGLContext.cpp
)

add_subdirectory(OpenGl)
add_subdirectory(Windows)
