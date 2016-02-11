cmake_minimum_required(VERSION 2.8)

project(game)

include_directories(include)

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

target_link_libraries(game SDL2 SDL2main)