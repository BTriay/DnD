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
            Hero.cpp
            Hero.ixx
            ICreature.cpp
            ICreature.ixx

            ./race/IRace.cpp
            ./race/IRace.ixx
            ./race/Dragonborn.cpp
            ./race/Dragonborn.ixx
            ./race/Dwarf.cpp
            ./race/Dwarf.ixx
            ./race/Elf.cpp
            ./race/Elf.ixx
            ./race/Gnome.cpp
            ./race/Gnome.ixx
            ./race/HalfElf.cpp
            ./race/HalfElf.ixx
            ./race/Halfling.cpp
            ./race/Halfling.ixx
            ./race/HalfOrc.cpp
            ./race/HalfOrc.ixx
            ./race/Human.cpp
            ./race/Human.ixx
            ./race/Tiefling.cpp
            ./race/Tiefling.ixx

            ./class/IClass.cpp
            ./class/IClass.ixx
            ./class/Barbarian.cpp
            ./class/Barbarian.ixx
            ./class/Bard.cpp
            ./class/Bard.ixx
            ./class/Cleric.cpp
            ./class/Cleric.ixx
            ./class/Druid.cpp
            ./class/Druid.ixx
            ./class/Fighter.cpp
            ./class/Fighter.ixx
            ./class/Monk.cpp
            ./class/Monk.ixx
            ./class/Paladin.cpp
            ./class/Paladin.ixx
            ./class/Ranger.cpp
            ./class/Ranger.ixx
            ./class/Rogue.cpp
            ./class/Rogue.ixx
            ./class/Sorcerer.cpp
            ./class/Sorcerer.ixx
            ./class/Warlock.cpp
            ./class/Warlock.ixx
            ./class/Wizard.cpp
            ./class/Wizard.ixx
            )

target_link_libraries(character PRIVATE common equipment)

target_include_directories(character PUBLIC
            ${include_directory}
            "${PROJECT_SOURCE_DIR}/common"
            "${PROJECT_SOURCE_DIR}/equipment"
            )
