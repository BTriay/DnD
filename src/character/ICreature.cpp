module ICreature;

/* PUBLIC MEMBER FUNCTIONS */

/*! Get the ability score of the creature.
This includes bonuses from magical items (armor, weapon, rings, etc).
*/
int ICreature::ability_score(Ability ability) const
{ 
	return m_ability_score.at(ability) 
		+ m_armor.ability_score_increase(ability)
		+ m_weapon_1.ability_score_increase(ability)
		+ m_weapon_2.ability_score_increase(ability);
}

/*! Get the ability modifier of the creature.
This includes bonuses from magical items (armor, weapon, rings, etc).
*/
int ICreature::ability_modifier(Ability ability) const
{
	return (m_ability_score.at(ability) + m_armor.ability_score_increase(ability) - 10) / 2;
}

/*! Set the ability score of the creature.
This does not affect the magical items worn by the creature.
*/
void ICreature::set_ability_score(Ability ability, int score)
{
	m_ability_score[ability] = score;
}

/*! Set the skill score of the creature */
void ICreature::set_skill_score(Skill skill, int score)
{
	m_skill_score[skill] = score;
}

void ICreature::set_hit_points_max(int hp)
{
	m_hit_points_max_without_constit = hp;
}

int ICreature::hit_points_max() const
{
	return m_hit_points_max_without_constit;
}

void ICreature::restore_current_hp_to_max()
{
	m_hit_points_current = m_hit_points_max_without_constit;
}

void ICreature::set_current_hp(int hp)
{
	m_hit_points_current = hp;
}

/*! Add resistance to the creature */
void ICreature::add_resistance(Damage resistance)
{
	m_resistance.push_back(resistance);
}

void ICreature::set_darkvision(int darkvision_distance)
{
	m_darkvision = darkvision_distance;
}

void ICreature::set_speed_land(int speed_land)
{
	m_speed_land = speed_land;
}

void ICreature::set_speed_climb(int speed_climb)
{
	m_speed_climb = speed_climb;
}

void ICreature::set_speed_air(int speed_air)
{
	m_speed_air = speed_air;
}

void ICreature::set_speed_water(int speed_water)
{
	m_speed_water = speed_water;
}

/* END OF PUBLIC MEMBER FUNCTIONS */


/* PROTECTED MEMBER FUNCTIONS */
/* END OF PROTECTED MEMBER FUNCTIONS */


/* PRIVATE MEMBER FUNCTIONS */

void ICreature::set_default_ability_scores()
{
	for (auto& ability : abilities)
	{
		set_ability_score(ability, 10);
	}	
}

/* END OF PRIVATE MEMBER FUNCTIONS */