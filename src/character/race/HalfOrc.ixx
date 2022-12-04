export module HalfOrc;

import enumeration;
import RaceCreature;

export class HalfOrc : public RaceCreature
{
public:
	HalfOrc() : RaceCreature(1, 60, Size::medium, 30)
	{
		set_ability_score_increase(Ability::strength, 2);
		set_ability_score_increase(Ability::constitution, 1);
	}

private:

};
