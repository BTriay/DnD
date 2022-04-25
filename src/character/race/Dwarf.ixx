export module Dwarf;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

class Dwarf : public ICreature, public IRace
{
public:
	Dwarf() : ICreature(25, 0, 0, 0, 60), IRace()
	{
		ability_score_increase(Ability::constitution, 2);
		add_resistance(Damage::poison);
	}

private:

};


export class HillDwarf : public Dwarf
{
public:
	HillDwarf() { ability_score_increase(Ability::wisdom, 1); }

private:

};


export class MountainDwarf : public Dwarf
{
public:
	MountainDwarf() { ability_score_increase(Ability::strength, 2); }

private:
};