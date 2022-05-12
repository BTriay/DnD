export module Weapon;

import Item;


export class Weapon : public Item
{
public:
	Weapon(WeaponProficiency weapon_proficiency, WeaponReach weapon_reach,
		Damage damage, WeaponProperty weapon_property = WeaponProperty::none):
		m_weapon_proficiency(weapon_proficiency), m_weapon_reach(weapon_reach),
		m_damage(damage), m_weapon_property(weapon_property) {}


private:
	WeaponProficiency m_weapon_proficiency;
	WeaponReach m_weapon_reach;
	Damage m_damage;
	WeaponProperty m_weapon_property;
};