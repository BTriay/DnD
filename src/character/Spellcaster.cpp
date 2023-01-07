module Spellcaster;

void Spellcaster::set_spell_slots(std::array<int, 10> spell_slots)
{
	m_spell_slots = spell_slots;
}

/*! 2nd-level evocation. Casting time: 1 bonus action
* Concentration, up to 10mn
* Use an action to make a melee spell attack. On a hit: 3d6 fire damage
* Higher levels: 1d6 per every 2 slot levels above level 2.
*/
std::tuple<int, Damage> Spellcaster::flame_blade(SpellAction spell_action,
	int spell_level, bool critical_hit)
{
	switch (spell_action)
	{
	case SpellAction::StartConcentration:
		m_spell_slots[spell_level] = m_spell_slots[spell_level] - 1;
		return std::tuple<int, Damage>{0, Damage::fire};

	case SpellAction::Attack:
	{
		auto number_die = 3 + (4 - spell_level) / 2;
		if (critical_hit)
			number_die *= 2;

		auto res = Die::roll_normal(number_die, HitDice::six);
		return std::tuple<int, Damage>{res, Damage::fire};
	}
	default:
		throw std::invalid_argument("not implemented");
	}
}

