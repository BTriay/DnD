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
            Logger.cpp
            Logger.ixx
            )

target_include_directories(utilities PUBLIC
            ${include_directory})
