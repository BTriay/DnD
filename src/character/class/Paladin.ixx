export module Paladin;

import enumeration;
import IClass;

export class Paladin : public IClass
{
public:
	Paladin() : IClass(HitDice::ten)
	{
		std::vector<Ability> saving_throw{ Ability::wisdom, Ability::charisma };
		set_saving_throw(saving_throw);
	}

private:
	;
};