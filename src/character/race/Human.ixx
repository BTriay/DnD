export module Human;

import enumeration;
import RaceCreature;

export class Human : public RaceCreature
{
public:
	Human() : RaceCreature(1, 0, Size::medium, 30)
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
