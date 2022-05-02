import <string>;
import <iostream>;
import <sstream>;

import Logger;

import Hero;
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
}