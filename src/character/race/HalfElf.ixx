export module HalfElf;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class HalfElf : public ICreature, public IRace
{
public:
	HalfElf() : ICreature(1, 60, Size::medium, 30), IRace()
	{
		set_ability_score_increase(Ability::charisma, 2);
		
		// set_ability_score_increase(Ability::, 1);
		// two other at the choice of the player
	}

private:

};
