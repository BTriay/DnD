import <string>;
import <iostream>;
import <fstream>;

import Logger;

import Hero;
import enumeration;

int main()
{
    //Logger logger{ "dnd.logs" };
    //logger.info("this is a log");
    
    Hero<Cleric, HillDwarf> helgret{"Helgret"};
    std::cout << helgret.ability_modifier(Ability::wisdom) << '\n';
}