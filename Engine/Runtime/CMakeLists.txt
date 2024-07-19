cmake_minimum_required(VERSION 3.22)

project(DenoiseEngine)

target_sources(DenoiseEngine PRIVATE
	 "Core/Private/Log.cpp"
	 "Core/Private/Application.cpp" 
)



add_subdirectory(Core)
add_subdirectory(Events)
add_subdirectory(Debug)