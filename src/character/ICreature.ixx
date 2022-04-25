module;

#include <stdint.h>

export module ICreature;

import <map>;
import enumeration;

export class ICreature
{
public:
	template <Ability T>
	int modifier();

	template <> virtual int modifier<Ability::charisma>();
	template <> virtual int modifier<Ability::constitution>();
	template <> virtual int modifier<Ability::dexterity>();
	template <> virtual int modifier<Ability::intelligence>();
	template <> virtual int modifier<Ability::strength>();
	template <> virtual int modifier<Ability::wisdom>();

	virtual int proficiency_bonus() = 0;
	virtual int armor_class() = 0;
	virtual int difficulty_class() = 0;

private:
	int m_level;
	int m_used_hit_die;

	std::map<Ability, int> m_ability_score;

	int m_speed_land;
	int m_speed_air;
	int m_speed_water;

	int m_darkvision;

	int m_hit_points_max_without_constit; // i.e. exclude constitution bonus
	int m_hit_points_current;

	// TODO:
	// armor
	// vector<Weapon> weapons; // how to know which weapon(s) is being used, vs which is in pack?
	// Item& shield;
	// vector<Item&> m_rings;
	// vector<Item&> m_amulets;
	// vector<item> // magical items: gloves, helmet, belt, etc.
};