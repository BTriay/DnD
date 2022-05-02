export module Cleric;

import enumeration;
import IClass;

export class Cleric : public IClass
{
public:
	Cleric() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::wisdom, Ability::charisma };
		set_saving_throw(saving_throw);
	}

private:
	;
};