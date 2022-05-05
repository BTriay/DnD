export module Monk;

import enumeration;
import IClass;

export class Monk : public IClass
{
public:
	Monk() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::dexterity, Ability::strength};
		set_saving_throw(saving_throw);
	}

private:
	;
};