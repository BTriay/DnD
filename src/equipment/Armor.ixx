module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Armor;

import <stdexcept>;
import enumeration;
import Item;

export class Armor : public Item
{
public:
	/*! Armor's default constructor, for serialization */ // TODO: move to protected?
	Armor() : Armor(ArmorProtection::none, 10) {}

	/*! Armor's fully fledged constructor */ // TODO: move to protected, and make creator a friend?
	Armor(ArmorProtection type, int base_armor_class, 
		bool stealth_disadvantage = false, int strength_required = 0): 
		Item(), m_type(type), m_base_armor_class(base_armor_class),
		m_stealth_disadvantage(stealth_disadvantage),
		m_strength_required(strength_required) {}

	virtual ~Armor() = default;

	int armor_class(int dexterity_modifier) const;
	ArmorProtection armor_type() const;
	bool stealth_disadvantage() const;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_type);
		ar& BOOST_SERIALIZATION_NVP(m_base_armor_class);
		ar& BOOST_SERIALIZATION_NVP(m_strength_required);
		ar& BOOST_SERIALIZATION_NVP(m_stealth_disadvantage);
	}

	ArmorProtection m_type;
	int m_base_armor_class;
	int m_strength_required;
	bool m_stealth_disadvantage;
};

BOOST_CLASS_VERSION(Armor, serialization_versions::armor)

export Armor armor_creator(ArmorType model);