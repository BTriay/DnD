export module Rogue;

import enumeration;
import IClass;

export class Rogue : public IClass
{
public:
	Rogue() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::dexterity, Ability::intelligence };
		set_saving_throw(saving_throw);
	}

private:
	;
};