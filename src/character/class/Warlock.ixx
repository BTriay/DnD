export module Warlock;

import enumeration;
import IClass;

export class Warlock : public IClass
{
public:
	Warlock() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::wisdom, Ability::charisma };
		set_saving_throw(saving_throw);
	}

private:
	;
};