export module Weapon;

import Item;
import Die;

export class Weapon : public Item
{
public:
	Weapon() : Weapon(WeaponProficiency::Simple, WeaponReach::Melee,
		Damage::bludgeoning, Die::Die(0, DieFaces::four, 3)) {}
	
	Weapon(WeaponProficiency weapon_proficiency, WeaponReach weapon_reach,
		Damage damage, Die die, WeaponProperty weapon_property = WeaponProperty::none):

		Item(), m_weapon_proficiency(weapon_proficiency), m_weapon_reach(weapon_reach),
		m_damage(damage), m_die(die), m_weapon_property(weapon_property) {}

	Weapon& operator=(const Weapon& rhs);

private:
	WeaponProficiency m_weapon_proficiency;
	WeaponReach m_weapon_reach;
	Damage m_damage;
	Die m_die;
	WeaponProperty m_weapon_property;
};