module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/set.hpp>

export module Weapon;

import <stdexcept>;
import <set>;
import <tuple>;

import enumeration;
import Item;
import Die;

export class Weapon : public Item
{
public:
	/*! Weapon's default constructor, for serialization */ // TODO: move to protected?
	Weapon() : Weapon(WeaponType::none, WeaponProficiency::simple, WeaponReach::melee,
		Damage::bludgeoning, Die::Die(0, HitDice::four, 1)) {}
	
	/*! Weapon's fully fledged constructor */ // TODO: move to protected, and make creator a friend?
	Weapon(WeaponType model, WeaponProficiency weapon_proficiency, WeaponReach weapon_reach,
		Damage damage, Die die, WeaponProperty weapon_property = WeaponProperty::none):

		Item(), m_model(model), m_weapon_proficiency(weapon_proficiency), 
		m_weapon_reach(weapon_reach), m_damage(damage), m_die(die),
		m_versatile_die(die)
	{
		m_weapon_property.insert(weapon_property);
	}
	
	Weapon& operator=(const Weapon& rhs);

	void add_property(WeaponProperty weapon_property);
	void add_versatile_die(Die die);
	WeaponReach weapon_reach() const;
	WeaponProficiency weapon_proficiency() const;
	bool has_property(WeaponProperty weapon_property) const;

	std::tuple<int, Damage> damage_roll(bool critical_hit = false) const;

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
		ar& BOOST_SERIALIZATION_NVP(m_versatile_die);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_property);
	}

	WeaponType m_model; /*!< Weapon type: club, dagger, bow, etc. */
	WeaponProficiency m_weapon_proficiency; /*!< Simple or martial */
	WeaponReach m_weapon_reach; /*!< Melee or ranged */
	Damage m_damage; /*!< Type of damage inflicted by the weapon: bludgeoning, etc */
	Die m_die; /*!< The base damage of the weapon */
	Die m_versatile_die; /*!< The base damage of the weapon if used as a dual weapon */
	std::set<WeaponProperty> m_weapon_property; /*!< Finesse, heavy, etc */
};

export Weapon weapon_creator(WeaponType model);

BOOST_CLASS_VERSION(Weapon, serialization_versions::weapon)