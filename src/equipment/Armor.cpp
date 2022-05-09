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
