module Armor;

int min(int a, int b)
{
	return a < b ? a : b;
}

int Armor::armor_class(int dexterity_modifier) const
{
	switch (m_type)
	{
	case ArmorProtection::none:
		return m_base_armor_class + dexterity_modifier;
	case ArmorProtection::light:
		return m_base_armor_class + dexterity_modifier;
	case ArmorProtection::medium:
		return m_base_armor_class + min(dexterity_modifier, 2);
	case ArmorProtection::heavy:
		return m_base_armor_class;
	default:
		throw std::invalid_argument("Unknown type");
		break;
	}
}

Armor armor_creator(ArmorType model)
{
	switch (model)
	{
	case ArmorType::none:
		return Armor(ArmorProtection::light, 10);
	case ArmorType::padded:
		return Armor(ArmorProtection::light, 11, true);
	case ArmorType::leather:
		return Armor(ArmorProtection::light, 11);
	case ArmorType::studded_leather:
		return Armor(ArmorProtection::light, 12);
	case ArmorType::hide:
		return Armor(ArmorProtection::medium, 12);
	case ArmorType::chain_shirt:
		return Armor(ArmorProtection::medium, 13);
	case ArmorType::scale_mail:
		return Armor(ArmorProtection::medium, 14, true);
	case ArmorType::breastplate:
		return Armor(ArmorProtection::medium, 14);
	case ArmorType::half_plate:
		return Armor(ArmorProtection::medium, 15, true);
	case ArmorType::ring_mail:
		return Armor(ArmorProtection::heavy, 14, true);
	case ArmorType::chain_mail:
		return Armor(ArmorProtection::heavy, 16, true, 13);
	case ArmorType::splint:
		return Armor(ArmorProtection::heavy, 17, true, 15);
	case ArmorType::plate:
		return Armor(ArmorProtection::heavy, 18, true, 15);
	default:
		throw std::invalid_argument("Unknown model");
		break;
	}
}
