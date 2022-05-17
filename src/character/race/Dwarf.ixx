export module Dwarf;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

class Dwarf : public ICreature, public IRace
{
public:
	Dwarf() : ICreature(60, Size::medium, 25), IRace()
	{
		set_ability_score_increase(Ability::constitution, 2);

		add_resistance(Damage::poison);
	}

private:

};


export class HillDwarf : public Dwarf
{
public:
	HillDwarf() { set_ability_score_increase(Ability::wisdom, 1); }

private:

};


export class MountainDwarf : public Dwarf
{
public:
	MountainDwarf() { set_ability_score_increase(Ability::strength, 2); }

private:
};