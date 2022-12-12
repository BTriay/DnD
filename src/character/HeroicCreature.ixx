module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module HeroicCreature;

import ICreature;
import enumeration;

export class HeroicCreature : public ICreature
{
public:

	HeroicCreature(Race race = Race::HillDwarf);

	Race race() const { return m_race; }

private:
	HeroicCreature(int hit_points_max, int darkvision, Size size,
		int speed_land, int speed_climb = 0,
		int speed_air = 0, int speed_water = 0) :
		ICreature(hit_points_max, darkvision, size, speed_land,
			speed_climb, speed_air, speed_water)
	{}

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