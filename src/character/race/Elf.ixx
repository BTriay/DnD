export module Elf;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

class Elf : public ICreature, public IRace
{
public:
	Elf() : ICreature(1, 60, Size::medium, 30), IRace()
	{
		set_ability_score_increase(Ability::dexterity, 2);
	}

private:

};


export class HighElf: public Elf
{
public:
	HighElf() { set_ability_score_increase(Ability::intelligence, 1); }

private:

};


export class WoodElf: public Elf
{
public:
	WoodElf()
	{
		set_speed_land(35);
		set_ability_score_increase(Ability::wisdom, 1); 
	}

private:
};


export class DarkElf : public Elf
{
public:
	DarkElf()
	{
		set_darkvision(120);
		set_ability_score_increase(Ability::charisma, 1);
	}

private:
};