export module Dragonborn;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class Dragonborn : public ICreature, public IRace
{
public:
	Dragonborn() : ICreature(0, Size::medium, 30, 0, 0, 0), IRace()
	{
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::strength, 2);
	}

private:

};

