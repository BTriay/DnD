export module Halfling;

import enumeration;
import RaceCreature;

class Halfling : public RaceCreature
{
public:
	//Halfling() : RaceCreature(1, 0, Size::small, 25)
	//{
	//	set_ability_score_increase(Ability::dexterity, 2);		
	//}

private:

};


export class Lightfoot : public Halfling
{
public:
	//Lightfoot() { set_ability_score_increase(Ability::charisma, 1); }

private:

};


export class Stout : public Halfling
{
public:
	//Stout()
	//{ 
	//	set_ability_score_increase(Ability::constitution, 2);
	//	add_resistance(Damage::poison);
	//}

private:
};