if (MSVC)
    # had to remove /WX because of spurious warnings
	add_compile_options(/std:c++latest /W4 /MDd /EHsc /experimental:module)
	set(link_directory "C:\\Users\\benoit\\dev\\boost_1_79_0\\stage\\lib")
	set(include_directory "C:\\Users\\benoit\\dev\\boost_1_79_0")
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
    target_compile_features(utilities PUBLIC cxx_std_20)
endif()

link_directories(${link_directory})

add_library(utilities
            io.cpp
            io.ixx
            Logger.cpp
            Logger.ixx
            )

target_link_libraries(utilities PRIVATE character)

target_include_directories(utilities PUBLIC
            ${include_directory}
            "${PROJECT_SOURCE_DIR}/character")
