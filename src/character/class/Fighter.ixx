export module Fighter;

import enumeration;
import IClass;

export class Fighter : public IClass
{
public:
	Fighter() : IClass(HitDice::ten)
	{
		std::vector<Ability> saving_throw{ Ability::constitution, Ability::strength};
		set_saving_throw(saving_throw);
	}

private:
	;
};