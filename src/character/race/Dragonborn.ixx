export module Dragonborn;

import enumeration;
import RaceCreature;

export class Dragonborn : public RaceCreature
{
public:
	Dragonborn() : RaceCreature(1, 0, Size::medium, 30)
	{
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::strength, 2);
	}

private:

};

