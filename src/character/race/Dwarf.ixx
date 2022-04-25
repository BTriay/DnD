export module Dwarf;

import <vector>;
import <map>;
import enumeration;

export class Dwarf
{
public:
	void ability_score_increase(Ability ability, int increase);

private:
	std::map<Ability, int> m_ability_score_increase { { Ability::constitution, 2} };

	constexpr int m_speed_land = 25;
	constexpr int m_darkvision = 60;
	std::vector<Damage> resistances{ Damage::poison };
};


export class HillDwarf : Dwarf
{
public:
	HillDwarf() { ability_score_increase(Ability::wisdom, 1); }

private:

};


export class MountainDwarf : Dwarf
{
public:
	MountainDwarf() { ability_score_increase(Ability::strength, 2); }

private:
};