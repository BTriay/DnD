module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Elf;

import enumeration;
import IRace;
import ICreature;

class Elf : public ICreature, public IRace
{
public:
	Elf() : ICreature(1, 60, Size::medium, 30), IRace()
	{
		set_ability_score_increase(Ability::dexterity, 2);
	}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(ICreature);
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(IRace);
	}

};


export class HighElf: public Elf
{
public:
	HighElf() { set_ability_score_increase(Ability::intelligence, 1); }

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Elf);
	}

};


export class WoodElf: public Elf
{
public:
	WoodElf()
	{
		set_speed_land(35);
		set_ability_score_increase(Ability::wisdom, 1); 
	}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Elf);
	}
};


export class DarkElf : public Elf
{
public:
	DarkElf()
	{
		set_darkvision(120);
		set_ability_score_increase(Ability::charisma, 1);
	}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Elf);
	}
};