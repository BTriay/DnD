export module Weapon;

import <stdexcept>;
import <set>;

import enumeration;
import Item;
import Die;

export class Weapon : public Item
{
public:
	Weapon() : Weapon(WeaponType::none, WeaponProficiency::simple, WeaponReach::melee,
		Damage::bludgeoning, Die::Die(0, DieFaces::four, 3)) {}
	
	Weapon(WeaponType model, WeaponProficiency weapon_proficiency, WeaponReach weapon_reach,
		Damage damage, Die die, WeaponProperty weapon_property = WeaponProperty::none):

		Item(), m_model(model), m_weapon_proficiency(weapon_proficiency), 
		m_weapon_reach(weapon_reach), m_damage(damage), m_die(die)
	{
		m_weapon_property.insert(weapon_property);
	}

	Weapon& operator=(const Weapon& rhs);

	void add_property(WeaponProperty weapon_property);

private:
	
	WeaponType m_model;
	WeaponProficiency m_weapon_proficiency;
	WeaponReach m_weapon_reach;
	Damage m_damage;
	Die m_die;
	std::set<WeaponProperty> m_weapon_property;
};

export Weapon weapon_creator(WeaponType model);