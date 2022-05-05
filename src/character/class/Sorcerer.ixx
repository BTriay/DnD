export module Sorcerer;

import enumeration;
import IClass;

export class Sorcerer : public IClass
{
public:
	Sorcerer() : IClass(HitDice::six)
	{
		std::vector<Ability> saving_throw{ Ability::constitution, Ability::charisma};
		set_saving_throw(saving_throw);
	}

private:
	;
};