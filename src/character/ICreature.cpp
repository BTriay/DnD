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
	return (m_ability_score.at(ability) 
		+ ability_score_increase(ability)
		+ m_armor.ability_score_increase(ability) - 10) / 2;
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

/*! Get the ability score of the creature */
int ICreature::ability_score_increase(Ability ability) const
{
	if (m_ability_score_increase.find(ability) != std::end(m_ability_score_increase))
		return m_ability_score_increase.at(ability);

	return 0;
}

void ICreature::set_ability_score_increase(Ability ability, int increase)
{
	m_ability_score_increase[ability] = increase;
}

/*! Set the size of the creature */
void ICreature::set_size(Size size)
{
	m_size = size;
}

/*! Get the size of the creature */
Size ICreature::size() const
{
	return m_size;
}

/*! Set the maximum hit points, excluding the hp from the constitution modifier */
void ICreature::set_hit_points_without_constit(int hp)
{
	m_hit_points_max_without_constit = hp;
}

/*! Get the maximum hit points, excluding the hp from the constitution modifier */
int ICreature::hit_points_without_constit() const
{
	return m_hit_points_max_without_constit;
}

/*! Restore the hit points to their max, excluding the hp from the constitution modifier */
void ICreature::restore_current_hp_to_max()
{
	m_hit_points_current = m_hit_points_max_without_constit;
}

/*! Set the current hit points */
void ICreature::set_current_hp(int hp)
{
	m_hit_points_current = hp;
}

/*! Set the current hit points */
int ICreature::current_hit_points() const
{
	return m_hit_points_current;
}

/*! Lose hit points */
void ICreature::lose_hit_points(int hit_points)
{
	m_hit_points_current -= hit_points;
}

/*! Take a short rest */
void ICreature::short_rest()
{

}

/*! Take a long rest */
void ICreature::long_rest()
{
	restore_current_hp_to_max();
}

/*! Roll the die for the attack */
int attack_roll(Ability ability, DieThrowAdvantage throw_advantage) const
{
	return Die::roll(1, HitDice::twenty, 0, throw_advantage) + ability_modifier(ability);
}

/*! Add resistance to the creature */
void ICreature::add_resistance(Damage resistance)
{
	m_resistance.push_back(resistance);
}

/*! Get the creature's darkvision (in feet) */
int ICreature::darkvision() const
{
	return m_darkvision;
}

/*! Set the creature's darkvision (in feet) */
void ICreature::set_darkvision(int darkvision_distance)
{
	m_darkvision = darkvision_distance;
}

/*! Set the creature's speed on land (in feet per turn) */
void ICreature::set_speed_land(int speed_land)
{
	m_speed_land = speed_land;
}

/*! Set the creature's climbing (in feet per turn) */
void ICreature::set_speed_climb(int speed_climb)
{
	m_speed_climb = speed_climb;
}

/*! Set the creature's flying speed (in feet per turn) */
void ICreature::set_speed_air(int speed_air)
{
	m_speed_air = speed_air;
}

/*! Set the creature's swimming speed (in feet per turn) */
void ICreature::set_speed_water(int speed_water)
{
	m_speed_water = speed_water;
}

/*! Don an armor */
void ICreature::don_armor(Armor& armor)
{
	m_armor = armor;
}

/*! Don an armor */
void ICreature::don_armor(ArmorType armor_type)
{
	m_armor = armor_creator(armor_type);
}

/*! Take-off the armor */
void ICreature::doff_armor()
{
	m_armor = armor_creator(ArmorType::none);
}

/*! AC calculator */
int ICreature::armor_class() const
{
	return m_armor.armor_class(ability_modifier(Ability::dexterity))
		+ (m_has_shield ? 2 : 0);
}

/*! Grab a shield */
void ICreature::don_shield()
{
	m_has_shield = true;
}

/*! Drop the shield */
void ICreature::doff_shield()
{
	m_has_shield = false;
}

/*! Add the 1st weapon */
void ICreature::add_weapon_one(const Weapon& weapon)
{
	m_weapon_1 = weapon;
}

/*! Drop the 1st weapon */
void ICreature::drop_weapon_one()
{
	m_weapon_1 = {};
}

/*! Add the 2nd weapon */
void ICreature::add_weapon_two(Weapon& weapon)
{
	m_weapon_2 = weapon;
}

/*! Drop the 2nd weapon */
void ICreature::drop_weapon_two()
{
	m_weapon_2 = {};
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