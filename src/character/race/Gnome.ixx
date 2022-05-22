export module Gnome;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

class Gnome : public ICreature, public IRace
{
public:
	Gnome() : ICreature(1, 60, Size::small, 25), IRace()
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