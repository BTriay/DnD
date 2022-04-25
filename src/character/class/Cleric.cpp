module Cleric;

import enumeration;

Cleric::Cleric()
{
	set_hit_dice(HitDice::eight);
	
	std::vector<Ability> saving_throw{ Ability::wisdom, Ability::charisma };
	set_saving_throw(saving_throw);
}