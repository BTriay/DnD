module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>

export module HeroicCreature;

import ICreature;
import enumeration;

export class HeroicCreature : public ICreature
{
public:
	/*
	HillDwarf, MountainDwarf,
	Dragonborn,
	HighElf, WoodElf, DarkElf,
	ForestGnome, RockGnome,
	HalfElf,
	Lightfoot, Stout,
	HalfOrc,
	Human,
	Tiefling
	*/

	HeroicCreature(Race race = Race::HillDwarf) : m_race(race)
	{
		// main races
		switch (race)
		{
		case (Race::HillDwarf):
		case (Race::MountainDwarf):
			HeroicCreature(1, 60, Size::medium, 25);
			set_ability_score_increase(Ability::constitution, 2);
			add_resistance(Damage::poison);
			break;

		case (Race::Dragonborn):
			HeroicCreature(1, 0, Size::medium, 30);
			set_ability_score_increase(Ability::charisma, 1);
			set_ability_score_increase(Ability::strength, 2);

		default:
			throw std::invalid_argument("Unknown race");
		}

		// sub-races specifics
		switch (race)
		{
		case (Race::HillDwarf):
			set_ability_score_increase(Ability::wisdom, 1);
			break;

		case (Race::MountainDwarf):
			set_ability_score_increase(Ability::strength, 2);
			break;
		}



	}

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

BOOST_CLASS_VERSION(HeroicCreature, serialization_versions::race_creature)