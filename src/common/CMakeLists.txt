if (MSVC)
	add_compile_options(/std:c++latest /W4 /WX /MDd /EHsc /experimental:module)
	set(link_directory "C:\\Users\\benoit\\dev\\boost_1_79_0\\stage\\lib")
	set(include_directory "C:\\Users\\benoit\\dev\\boost_1_79_0")
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
    target_compile_features(common PUBLIC cxx_std_20)
endif()

link_directories(${link_directory})

add_library(common
            Die.cpp
            Die.ixx
            enumeration.cpp
            enumeration.ixx
            )

target_include_directories(common PUBLIC
            ${include_directory})
