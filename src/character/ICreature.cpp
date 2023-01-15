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
void ICreature::lose_hit_points(int hit_points, Damage damage_type)
{
	// the creature has resistance to this type of damage
	if (std::find(std::begin(m_resistance), std::end(m_resistance), damage_type)
		!= std::end(m_resistance))
		hit_points /= 2;

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
int ICreature::attack_roll(Ability ability, int proficiency_bonus, 
	DieThrowAdvantage throw_advantage) const
{
	return Die::roll(1, HitDice::twenty, 0, throw_advantage) + ability_modifier(ability)
		+ proficiency_bonus;
}

/*! Roll the die for the attack and compare to the armor class */
AttackResult ICreature::attack_roll_vs_armor_class(Ability ability,
	DieThrowAdvantage throw_advantage, int proficiency_bonus, int armor_class) const
{
	auto attack_roll_res = attack_roll(ability, proficiency_bonus, throw_advantage);

	if (attack_roll_res == 20 || attack_roll_res >= armor_class + 10)
		return AttackResult::critical_hit;
	else if (attack_roll_res >= armor_class)
		return AttackResult::hit;

	return AttackResult::miss;
}

/*! Attack with the 1st weapon */
void ICreature::attack_weapon_one(ICreature& enemy, DieThrowAdvantage throw_advantage,
	int proficiency_bonus, bool add_ability_modifier_to_damage)
{
	auto use_as_versatile = (m_weapon_2.weapon_type() == WeaponType::none && !m_has_shield);

	attack_weapon(enemy, m_weapon_1, throw_advantage, proficiency_bonus, 
		use_as_versatile, add_ability_modifier_to_damage);
}

/*! Attack with the 2nd weapon */
void ICreature::attack_weapon_two(ICreature& enemy, DieThrowAdvantage throw_advantage,
	int proficiency_bonus, bool add_ability_modifier_to_damage)
{
	auto use_as_versatile = (m_weapon_1.weapon_type() == WeaponType::none && !m_has_shield);

	attack_weapon(enemy, m_weapon_2, throw_advantage, proficiency_bonus, 
		use_as_versatile, add_ability_modifier_to_damage);
}

/*! Two light weapons in hands, let's go violent */
void ICreature::two_weapons_attack(ICreature& enemy, DieThrowAdvantage throw_advantage,
	int proficiency_bonus)
{
	if (m_weapon_1.weapon_type() == WeaponType::none
		|| m_weapon_2.weapon_type() == WeaponType::none
		|| m_has_shield)
	{
		std::cout << "One none weapon or shield. Cannot yield dual attack\n";
		return;
	}

	if (!m_weapon_1.has_property(WeaponProperty::light)
		|| !m_weapon_2.has_property(WeaponProperty::light))
	{
		std::cout << "One weapon is not light. Cannot yield dual attack\n";
		return;
	}

	attack_weapon_one(enemy, throw_advantage, proficiency_bonus, true);
	attack_weapon_two(enemy, throw_advantage, proficiency_bonus, false);
}

/*! Unarmed attack. You better have strong fists */
void ICreature::attack_unarmed(ICreature& enemy, DieThrowAdvantage throw_advantage,
	int proficiency_bonus)
{
	auto ability = Ability::strength;

	auto attack_result = attack_roll_vs_armor_class(ability, throw_advantage,
		proficiency_bonus, enemy.armor_class());

	if (attack_result != AttackResult::miss)
	{
		auto damage = 1 + ability_modifier(ability);

		std::cout << "Damage inflicted by an unarmed attack: " << damage << '\n';

		enemy.lose_hit_points(damage, Damage::bludgeoning);
	}
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
void ICreature::add_weapon_two(const Weapon& weapon)
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

void ICreature::set_default_ability_scores()
{
	for (auto& ability : abilities)
	{
		set_ability_score(ability, 10);
	}
}

/* END OF PROTECTED MEMBER FUNCTIONS */

/* PRIVATE MEMBER FUNCTIONS */

/*! Return the ability to use for that weapon */
Ability ICreature::weapon_ability_selector(const Weapon& weapon)
{
	// no choice for ranged weapon, use dexterity
	if (weapon.weapon_reach() == WeaponReach::ranged)
		return Ability::dexterity;

	// in case it's a melee weapon, but also has finesse:
	if (weapon.has_property(WeaponProperty::finesse)
		&& (ability_modifier(Ability::dexterity) > ability_modifier(Ability::strength)))
	{
		return Ability::dexterity;
	}

	return Ability::strength;
}

/*! Attack with the weapon passed as parameter */
void ICreature::attack_weapon(ICreature& enemy, const Weapon& weapon,
	DieThrowAdvantage throw_advantage, int proficiency_bonus,
	bool use_as_versatile, bool add_ability_modifier_to_damage)
{
	if (weapon.weapon_type() == WeaponType::none) return;

	auto ability = weapon_ability_selector(weapon);

	auto attack_result = attack_roll_vs_armor_class(ability, throw_advantage,
		proficiency_bonus, enemy.armor_class());

	if (attack_result != AttackResult::miss)
	{
		auto [damage, damage_type] =
			weapon.damage_roll(attack_result == AttackResult::critical_hit,
				use_as_versatile);

		std::cout << "Damage inflicted by the weapon: " << damage << '\n';

		if (add_ability_modifier_to_damage || ability_modifier(ability) < 0)
			damage += ability_modifier(ability);

		enemy.lose_hit_points(damage, damage_type);
	}
}

/* END OF PRIVATE MEMBER FUNCTIONS */