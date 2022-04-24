if (MSVC)
	add_compile_options(/std:c++latest /W4 /WX /MDd /EHsc /experimental:module)
	set(link_directory "C:\\Users\\benoit\\dev\\boost_1_79_0\\stage\\lib")
	set(include_directory "C:\\Users\\benoit\\dev\\boost_1_79_0")
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
    target_compile_features(equipment PUBLIC cxx_std_20)
endif()

link_directories(${link_directory})

add_library(equipment
            Item.cpp
            Item.ixx
            Armor.cpp
            Armor.ixx
            Weapon.cpp
            Weapon.ixx
            SpecialItem.cpp
            SpecialItem.ixx
            )

target_link_libraries(equipment PRIVATE common)

target_include_directories(equipment PUBLIC common
            ${include_directory}
            "${PROJECT_SOURCE_DIR}/src/common"
            )
