module Weapon;


Weapon& Weapon::operator=(const Weapon& rhs)
{
	m_weapon_proficiency = rhs.m_weapon_proficiency;
	m_weapon_reach = rhs.m_weapon_reach;
	m_damage = rhs.m_damage;
	m_die = rhs.m_die;
	m_weapon_property = rhs.m_weapon_property;

	return *this;
}