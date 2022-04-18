cmake_minimum_required(VERSION 3.21)

project(DnD	VERSION 0.1
				DESCRIPTION "DnD"
				LANGUAGES CXX)
				
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/character")
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/item")
# add_subdirectory("${PROJECT_SOURCE_DIR}/src/spell")

add_executable(DnD
				src/main.cpp)

if (MSVC)
	add_compile_options(/W4 /WX /MDd /EHsc /experimental:module)
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

target_compile_features(DnD PUBLIC cxx_std_20)
