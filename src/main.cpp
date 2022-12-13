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

int main()
{
    [[maybe_unused]] const auto filename = "dnd_serialization.xml";
    [[maybe_unused]] const auto filename2 = "dnd_serialization2.xml";

    
    Hero helgret{ "Helgret", Race::Dragonborn, "Warlock"};

    helgret.set_ability_score(Ability::charisma, 10);
    helgret.set_ability_score(Ability::constitution, 13);
    helgret.set_ability_score(Ability::dexterity, 8);
    helgret.set_ability_score(Ability::intelligence, 12);
    helgret.set_ability_score(Ability::strength, 14);
    helgret.set_ability_score(Ability::wisdom, 15);
    helgret.add_skill(Skill::medicine);
    helgret.restore_current_hp_to_max();

    //auto armor = armor_creator(ArmorType::chain_mail);
    //helgret.don_armor(armor);

    std::cout << "helgret before:\n";
    std::cout << helgret<< '\n';

    io::xml::serialize(helgret, filename);
    auto helgret_reborn = io::xml::deserialize(filename);

    std::cout << "helgret reborn:\n";
    std::cout << helgret_reborn << '\n';

    io::xml::serialize(helgret_reborn, filename2);

    //helgret.add_weapon_one(weapon_creator(WeaponType::warhammer));
    //helgret.don_shield();
    //std::cout << helgret << '\n';

}