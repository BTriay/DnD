module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/set.hpp>

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
		Damage::bludgeoning, Die::Die(0, HitDice::four, 3)) {}
	
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
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Item);
		ar& BOOST_SERIALIZATION_NVP(m_model);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_proficiency);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_reach);
		ar& BOOST_SERIALIZATION_NVP(m_die);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_property);
	}

	WeaponType m_model;
	WeaponProficiency m_weapon_proficiency;
	WeaponReach m_weapon_reach;
	Damage m_damage;
	Die m_die;
	std::set<WeaponProperty> m_weapon_property;
};

export Weapon weapon_creator(WeaponType model);

BOOST_CLASS_VERSION(Weapon, serialization_versions::weapon)