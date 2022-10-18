# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Client")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		Networking
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Networking
)