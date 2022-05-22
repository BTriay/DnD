export module Dragonborn;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class Dragonborn : public ICreature, public IRace
{
public:
	Dragonborn() : ICreature(1, 0, Size::medium, 30), IRace()
	{
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::strength, 2);
	}

private:

};

