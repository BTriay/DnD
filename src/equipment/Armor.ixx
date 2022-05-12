export module Armor;

import <stdexcept>;
import enumeration;
import Item;

export class Armor : public Item
{
public:
	Armor() : Armor(ArmorProtection::none, 10) {}

	Armor(ArmorProtection type, int base_armor_class, 
		bool stealth_disadvantage = false, int strength_required = 0): 
		Item(), m_type(type), m_base_armor_class(base_armor_class),
		m_stealth_disadvantage(stealth_disadvantage),
		m_strength_required(strength_required) {}

	Armor& operator=(const Armor& armor) = default;
	Armor& operator=(Armor&& armor) = default;

	int armor_class(int dexterity_modifier) const;
	ArmorProtection armor_type() const { return m_type; }
	bool stealth_disadvantage() const { return m_stealth_disadvantage; }

	virtual ~Armor() = default;
private:
	ArmorProtection m_type;
	int m_base_armor_class;
	int m_strength_required;
	bool m_stealth_disadvantage;
};


export Armor armor_creator(ArmorType model)
{
	switch (model)
	{
	case ArmorType::none:
		return Armor(ArmorProtection::light, 10);
		break;
	case ArmorType::padded:
		return Armor(ArmorProtection::light, 11, true);
		break;
	case ArmorType::leather:
		return Armor(ArmorProtection::light, 11);
		break;
	case ArmorType::studded_leather:
		return Armor(ArmorProtection::light, 12);
		break;
	case ArmorType::hide:
		return Armor(ArmorProtection::medium, 12);
		break;
	case ArmorType::chain_shirt:
		return Armor(ArmorProtection::medium, 13);
		break;
	case ArmorType::scale_mail:
		return Armor(ArmorProtection::medium, 14, true);
		break;
	case ArmorType::breastplate:
		return Armor(ArmorProtection::medium, 14);
		break;
	case ArmorType::half_plate:
		return Armor(ArmorProtection::medium, 15, true);
		break;
	case ArmorType::ring_mail:
		return Armor(ArmorProtection::heavy, 14, true);
		break;
	case ArmorType::chain_mail:
		return Armor(ArmorProtection::heavy, 16, true, 13);
		break;
	case ArmorType::splint:
		return Armor(ArmorProtection::heavy, 17, true, 15);
		break;
	case ArmorType::plate:
		return Armor(ArmorProtection::heavy, 18, true, 15);
		break;
	default:
		throw std::invalid_argument("Unknown model");
		break;
	}
}
