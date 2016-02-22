cmake_minimum_required(VERSION 2.8)

project(game)

include_directories(cgl/include)
add_subdirectory(cgl)

SET(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra")

file(
	GLOB_RECURSE
	source_files
	src/*.c
)

file(
	GLOB_RECURSE
	header_files
	include/*
)

add_executable(game ${headers_files} ${source_files})

target_link_libraries(game cgl SDL2 SDL2main GL GLEW)