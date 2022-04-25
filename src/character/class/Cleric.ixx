export module Cleric;

import enumeration;
import IClass;

export class Cleric : protected IClass
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