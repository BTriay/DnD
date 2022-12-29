export module Tiefling;

import enumeration;
import RaceCreature;

export class Tiefling : public RaceCreature
{
public:
	Tiefling() : RaceCreature(1, 60, Size::medium, 25)
	{
		set_ability_score_increase(Ability::intelligence, 1);
		set_ability_score_increase(Ability::charisma, 2);

		add_resistance(Damage::fire);
	}

private:

};

