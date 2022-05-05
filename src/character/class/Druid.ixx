export module Druid;

import enumeration;
import IClass;

export class Druid : public IClass
{
public:
	Druid() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::wisdom, Ability::intelligence };
		set_saving_throw(saving_throw);
	}

private:
	;
};