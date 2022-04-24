module;

#include <stdint.h>

export module Item;

import <string>;

export class Item
{
public:
	Item(std::string name, uint16_t weight, uint32_t value) :
		m_name(name), m_weight(weight), m_value(value) {}


private:
	uint8_t m_strength_score_bonus;
	uint8_t m_dexterity_score_bonus;
	uint8_t m_constitution_score_bonus;
	uint8_t m_intelligence_score_bonus;
	uint8_t m_wisdom_score_bonus;
	uint8_t m_charisma_score_bonus;

	uint16_t m_weight;
	uint16_t m_extra_hit_points;
	uint32_t m_value;

	std::string m_name;
};