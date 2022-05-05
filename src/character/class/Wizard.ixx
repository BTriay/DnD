export module Wizard;

import enumeration;
import IClass;

export class Wizard : public IClass
{
public:
	Wizard() : IClass(HitDice::six)
	{
		std::vector<Ability> saving_throw{ Ability::wisdom, Ability::intelligence };
		set_saving_throw(saving_throw);
	}

private:
	;
};