#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>

import <string>;
import <iostream>;
import <fstream>;
import <sstream>;

import Logger;
import io;

import Hero;
import Armor;
import Weapon;
import enumeration;

import Cleric;
import Dwarf;

int main()
{
    [[maybe_unused]] const auto filename = "dnd_serialization.xml";

    Hero helgret{ "Helgret", new HillDwarf, new Cleric };
    helgret.set_ability_score(Ability::charisma, 10);
    helgret.add_skill(Skill::medicine);
    helgret.set_ability_score(Ability::constitution, 13);
    helgret.set_ability_score(Ability::dexterity, 8);
    helgret.set_ability_score(Ability::intelligence, 12);
    helgret.set_ability_score(Ability::strength, 14);
    helgret.set_ability_score(Ability::wisdom, 15);

    //auto armor = armor_creator(ArmorType::chain_mail);
    //helgret.don_armor(armor);

//    std::cout << helgret << '\n';
    
    //hero::serialize(helgret, filename);

    io::xml::serialize(helgret, filename);
    
    Hero h2{ "hero", new HillDwarf, new Cleric };
    {
        std::ifstream fs2{ filename };
        boost::archive::xml_iarchive ia{ fs2 };
        ia >> BOOST_SERIALIZATION_NVP(h2);
    }
    
    
    /*
    auto race = io::xml::get_class_name(filename, "m_race_name");
    auto dnd_class = io::xml::get_class_name(filename, "m_class_name");

    std::cout << "race: " << race << '\n';
    std::cout << "class: " << dnd_class << '\n';
    */

    //helgret.add_weapon_one(weapon_creator(WeaponType::warhammer));
    //helgret.don_shield();
    //std::cout << helgret << '\n';    
        

}