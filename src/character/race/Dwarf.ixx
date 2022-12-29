module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Dwarf;

import enumeration;
import RaceCreature;

class Dwarf : public RaceCreature
{
public:
	Dwarf() : RaceCreature(1, 60, Size::medium, 25)
	{
		set_ability_score_increase(Ability::constitution, 2);

		add_resistance(Damage::poison);
	}
	
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(RaceCreature);
	}

};


export class HillDwarf : public Dwarf
{
public:
	HillDwarf() { set_ability_score_increase(Ability::wisdom, 1); }

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Dwarf);
	}

};


export class MountainDwarf : public Dwarf
{
public:
	MountainDwarf() { set_ability_score_increase(Ability::strength, 2); }

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Dwarf);
	}
};
