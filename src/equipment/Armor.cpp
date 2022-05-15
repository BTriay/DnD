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
		break;
	case ArmorProtection::light:
		return m_base_armor_class + dexterity_modifier;
		break;
	case ArmorProtection::medium:
		return m_base_armor_class + min(dexterity_modifier, 2);
		break;
	case ArmorProtection::heavy:
		return m_base_armor_class;
		break;
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
