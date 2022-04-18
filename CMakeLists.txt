cmake_minimum_required(VERSION 3.21)

project(DnD	VERSION 0.1
				DESCRIPTION "DnD"
				LANGUAGES CXX)
				
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/character")
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/item")
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/spell")

if (MSVC)
	add_compile_options(/W4 /WX /MDd /EHsc /experimental:module)
	set(link_directory "C:\\Users\\benoit\\dev\\boost_1_79_0\\stage\\lib")
	set(include_directory "C:\\Users\\benoit\\dev\\boost_1_79_0")
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

link_directories(${link_directory})

add_executable(DnD
				src/main.cpp)

target_include_directories(DnD PUBLIC ${include_directory})

target_compile_features(DnD PUBLIC cxx_std_20)
