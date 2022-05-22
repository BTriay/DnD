export module Halfling;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

class Halfling : public ICreature, public IRace
{
public:
	Halfling() : ICreature(1, 0, Size::small, 25), IRace()
	{
		set_ability_score_increase(Ability::dexterity, 2);		
	}

private:

};


export class Lightfoot : public Halfling
{
public:
	Lightfoot() { set_ability_score_increase(Ability::charisma, 1); }

private:

};


export class Stout : public Halfling
{
public:
	Stout()
	{ 
		set_ability_score_increase(Ability::constitution, 2);
		add_resistance(Damage::poison);
	}

private:
};