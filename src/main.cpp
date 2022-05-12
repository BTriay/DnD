import <string>;
import <iostream>;
import <sstream>;

import Logger;

import Hero;
import Armor;
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
    armor.set_ability_score_increase(Ability::constitution, 1);
    armor.set_ability_score_increase(Ability::wisdom, 4);
    helgret.don_armor(armor);
    std::cout << helgret << '\n';

    helgret.don_shield();
    std::cout << helgret << '\n';
    helgret.doff_armor();
    std::cout << helgret << '\n';
}