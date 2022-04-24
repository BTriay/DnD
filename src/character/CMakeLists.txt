if (MSVC)
	add_compile_options(/std:c++latest /W4 /WX /MDd /EHsc /experimental:module)
	set(link_directory "C:\\Users\\benoit\\dev\\boost_1_79_0\\stage\\lib")
	set(include_directory "C:\\Users\\benoit\\dev\\boost_1_79_0")
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
    target_compile_features(character PUBLIC cxx_std_20)
endif()

link_directories(${link_directory})

add_library(character
            ICreature.cpp
            ICreature.ixx
            )

target_link_libraries(character PRIVATE common)

target_include_directories(character PUBLIC
            ${include_directory}
            "${PROJECT_SOURCE_DIR}/common"
            )
