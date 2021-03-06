import <string>;
import <iostream>;
import <sstream>;

import Logger;

import Hero;
import Armor;
import Weapon;
import enumeration;

int main()
{
    Hero<Cleric, HillDwarf> helgret{"Helgret"};
    helgret.set_ability_score(Ability::charisma, 10);
    helgret.set_ability_score(Ability::constitution, 13);
    helgret.set_ability_score(Ability::dexterity, 8);
    helgret.set_ability_score(Ability::intelligence, 12);
    helgret.set_ability_score(Ability::strength, 14);
    helgret.set_ability_score(Ability::wisdom, 15);
    
    std::cout << helgret << '\n';


    auto armor = armor_creator(ArmorType::chain_mail);
    helgret.don_armor(armor);
    std::cout << helgret << '\n';

    auto warhammer = weapon_creator(WeaponType::warhammer);
    helgret.add_weapon_one(warhammer);

    helgret.don_shield();
    std::cout << helgret << '\n';

}