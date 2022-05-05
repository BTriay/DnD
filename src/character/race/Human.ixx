export module Human;

import <vector>;
import <map>;
import enumeration;
import IRace;
import ICreature;

export class Human : public ICreature, public IRace
{
public:
	Human() : ICreature(0, Size::medium, 30, 0, 0, 0), IRace()
	{
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::constitution, 1);
		set_ability_score_increase(Ability::dexterity, 1);
		set_ability_score_increase(Ability::intelligence, 1);
		set_ability_score_increase(Ability::strength, 1);
		set_ability_score_increase(Ability::wisdom, 1);
	}

private:

};
