module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module HeroicCreature;

import <string>;

import ICreature;
import enumeration;

export class HeroicCreature : public ICreature
{
public:

	HeroicCreature(Race race = Race::HillDwarf, 
		AbilityScore ability_scores = 
		{ .charisma = 8, .constitution = 8, .dexterity = 8,
			.intelligence = 15, .strength = 15, .wisdom = 15 });

	const std::string race() const;

private:
	void init(int hit_points_without_constit, int darkvision, Size size,
		int speed_land, int speed_climb = 0,
		int speed_air = 0, int speed_water = 0);

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(ICreature);
		
		ar& BOOST_SERIALIZATION_NVP(m_race);
	}

	Race m_race;
};

BOOST_CLASS_VERSION(HeroicCreature, serialization_versions::heroic_creature)

/*
std::ostream& operator<<(ostream& os, const HeroicCreature& hc)
{
	os << hc.

	return os;
}
*/