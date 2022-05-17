export module Tiefling;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class Tiefling : public ICreature, public IRace
{
public:
	Tiefling() : ICreature(60, Size::medium, 25), IRace()
	{
		set_ability_score_increase(Ability::intelligence, 1);
		set_ability_score_increase(Ability::charisma, 2);

		add_resistance(Damage::fire);
	}

private:

};

