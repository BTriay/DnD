module Spellcaster;

/*! 2nd-level evocation. Casting time: 1 bonus action
* Concentration, up to 10mn
* Use an action to make a melee spell attack. On a hit: 3d6 fire damage
* Higher levels: 1d6 per every 2 slot levels above level 2.
*/
int Spellcaster::flame_blade(SpellAction spell_action,
	int spell_level, bool critical_hit)
{
	
	switch (spell_action)
	{
	case SpellAction::StartConcentration:
		m_spell_slots[spell_level] = m_spell_slots[spell_level] - 1;
		return 0;

	case SpellAction::Attack:
	{
		auto number_die = 3 + (4 - spell_level) / 2;
		if (critical_hit)
			number_die *= 2;

		return Die::roll_normal(number_die, HitDice::six);
	}
	default:
		throw std::invalid_argument("not implemented");
	}

}
