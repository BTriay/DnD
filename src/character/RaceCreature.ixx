module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>

export module RaceCreature;

import ICreature;
import IRace;

export class RaceCreature : public IRace, public ICreature
{
public:
	RaceCreature(int hit_points_max, int darkvision, Size size,
		int speed_land, int speed_climb = 0,
		int speed_air = 0, int speed_water = 0) :
		ICreature(hit_points_max, darkvision, size, speed_land,
			speed_climb, speed_air, speed_water),
		IRace()
	{}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(IRace);
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(ICreature);
	}
};

//BOOST_CLASS_VERSION(RaceCreature, serialization_versions::race_creature)