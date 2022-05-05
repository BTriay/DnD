export module Ranger;

import enumeration;
import IClass;

export class Ranger : public IClass
{
public:
	Ranger() : IClass(HitDice::ten)
	{
		std::vector<Ability> saving_throw{ Ability::strength, Ability::dexterity};
		set_saving_throw(saving_throw);
	}

private:
	;
};