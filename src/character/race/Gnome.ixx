export module Gnome;

import enumeration;
import RaceCreature;

class Gnome : public RaceCreature
{
public:
	Gnome() : RaceCreature(1, 60, Size::small, 25)
	{
		set_ability_score_increase(Ability::intelligence, 2);
	}

private:

};


export class ForestGnome : public Gnome
{
public:
	ForestGnome() { set_ability_score_increase(Ability::dexterity, 1); }

private:

};


export class RockGnome : public Gnome
{
public:
	RockGnome() { set_ability_score_increase(Ability::constitution, 1); }

private:
};