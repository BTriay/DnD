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
import RaceCreature;

int main()
{
    [[maybe_unused]] const auto filename = "dnd_serialization.xml";

    //Hero helgret{ "Helgret", new HillDwarf, new Cleric };
    Hero helgret{ "Helgret", Race::HillDwarf };
    helgret.set_class(new Cleric);
    
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
    
    io::xml::serialize(helgret, filename);
    std::cout << "serialized\n";

    auto helgret_reborn = io::xml::deserialize(filename);
    std::cout << "deserialized\n";
    std::cout << helgret_reborn.name() << '\n';

    /*
    RaceCreature rc{Race::HillDwarf}, rc2;
    rc.set_ability_score(Ability::wisdom, 15);
    {
        std::ofstream fs1{ filename };
        boost::archive::xml_oarchive oa(fs1);
        oa << BOOST_SERIALIZATION_NVP(rc);
    }

    {
        std::ifstream fs2{ filename };
        boost::archive::xml_iarchive ia{ fs2 };
        ia >> BOOST_SERIALIZATION_NVP(rc2);
    }
    std::cout << "rc2 ability_score(wisdom): " 
        << rc2.ability_score(Ability::wisdom) << '\n';
    */

    //helgret.add_weapon_one(weapon_creator(WeaponType::warhammer));
    //helgret.don_shield();
    //std::cout << helgret << '\n';

}