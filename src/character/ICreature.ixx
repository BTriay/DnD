module;

#include <stdint.h>

export module ICreature;

import enumeration;

export enum class Size { tiny, small, medium, large, huge, gargantuan };
export enum class Skill { acrobatics, animal_handling /* etc */ };
export enum class ToolProficiency { artisan, disguise  /* etc */ };

export class ICreature
{
public:
	template <Ability T>
	uint8_t modifier();

	template <> virtual uint8_t modifier<Ability::charisma>();
	template <> virtual uint8_t modifier<Ability::constitution>();
	template <> virtual uint8_t modifier<Ability::dexterity>();
	template <> virtual uint8_t modifier<Ability::intelligence>();
	template <> virtual uint8_t modifier<Ability::strength>();
	template <> virtual uint8_t modifier<Ability::wisdom>();

	virtual uint8_t proficiency_bonus() = 0;
	virtual uint8_t armor_class() = 0;
	virtual uint8_t difficulty_class() = 0;

private:
	uint8_t m_level;
	uint8_t m_used_hit_die;

	uint8_t m_score_strength;
	uint8_t m_score_dexterity;
	uint8_t m_score_constitution;
	uint8_t m_score_intelligence;
	uint8_t m_score_wisdom;
	uint8_t m_score_charisma;

	uint16_t m_speed_land;
	uint16_t m_speed_air;
	uint16_t m_speed_water;

	uint16_t m_dark_vision;

	uint16_t m_hit_points_max_without_constit; // i.e. exclude constitution bonus
	uint16_t m_hit_points_current;

	// TODO:
	// armor
	// vector<Weapon> weapons; // how to know which weapon(s) is being used, vs which is in pack?
	// Item& shield;
	// vector<Item&> m_rings;
	// vector<Item&> m_amulets;
	// vector<item> // magical items: gloves, helmet, belt, etc.
};