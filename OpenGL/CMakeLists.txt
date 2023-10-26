cmake_minimum_required (VERSION 3.0)
project (OpenGL_Project)

find_package(OpenGL REQUIRED)

add_subdirectory (Libraries)


cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Libraries/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile)


include_directories(
	Libraries/glfw-3.3.8/include
	Libraries/glew-2.1.0/include/
	Libraries/glm-master
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_210
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

### Triangle ###
add_executable(Triangle 
	Projects/Triangle/Triangle.cpp
	Common/Shader/Shader.h
	Common/Shader/Shader.cpp

	Projects/Triangle/Shader.fs
	Projects/Triangle/Shader.vs
)
target_link_libraries(Triangle
	${ALL_LIBS}
)

set_target_properties(Triangle PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Projects/Triangle/")
create_target_launcher(Triangle WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Projects/Triangle/")
create_default_target_launcher(Triangle WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Projects/Triangle/")

################