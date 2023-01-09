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
import <array>;

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

    AbilityScore helgret_ability_scores{
        .charisma = 10, .constitution = 13, .dexterity = 8,
        .intelligence = 12, .strength = 14, .wisdom = 15 };

    if (!helgret_ability_scores.check_scores())
        //throw std::invalid_argument("invalid ability scores total");
        std::cerr << "invalid ability scores total\n";

    Hero helgret{ "Helgret", Race::HillDwarf, "Druid", helgret_ability_scores };
    
    helgret.add_skill(Skill::medicine);
    
    auto hp = helgret.gain_level(true);
    //std::cout << "Gained " << hp << " hp when levelling up\n";   
    hp = helgret.gain_level(false);
    //std::cout << "Gained " << hp << " hp when levelling up\n";
    
    /*
    auto slots = helgret.available_spell_slots();    
    std::cout << "slots: ";
    for (auto& s : slots)
        std::cout << s << "  ";
    std::cout << '\n';
    */

    helgret.restore_current_hp_to_max();

    auto armor = armor_creator(ArmorType::chain_mail);
    helgret.don_armor(armor);

    {
        AbilityScore voldemort_ability_scores{
            .charisma = 14, .constitution = 8, .dexterity = 8,
            .intelligence = 16, .strength = 8, .wisdom = 15 };

        Hero voldemort{ "Voldemort", Race::HillDwarf, "Wizard", voldemort_ability_scores };
        std::cout << "Voldemort before being attacked\n" << voldemort << '\n';
        helgret.invoke_spell("fire_bolt", voldemort);
        std::cout << "Voldemort after being attacked\n" << voldemort << '\n';
    }

    /*
    {
        std::cout << "helgret before:\n";
        std::cout << helgret << '\n';
        io::xml::serialize(helgret, filename);

        auto helgret_reborn = io::xml::deserialize(filename);
        std::cout << "helgret reborn:\n";
        std::cout << helgret_reborn << '\n';
        io::xml::serialize(helgret_reborn, filename2);
    }
    */

    //helgret.add_weapon_one(weapon_creator(WeaponType::warhammer));
    //helgret.don_shield();
    //std::cout << helgret << '\n';

}