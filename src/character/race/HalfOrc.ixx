export module HalfOrc;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class HalfOrc : public ICreature, public IRace
{
public:
	HalfOrc() : ICreature(60, Size::medium, 30), IRace()
	{
		set_ability_score_increase(Ability::strength, 2);
		set_ability_score_increase(Ability::constitution, 1);

	}

private:

};
