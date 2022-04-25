export module Dwarf;

import <vector>;
import <map>;
import enumeration;
import IRace;

class Dwarf : public IRace
{
public:
	

private:

	int m_speed_land = 25;
	int m_darkvision = 60;
	std::vector<Damage> resistances{ Damage::poison };
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