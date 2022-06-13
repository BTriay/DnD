module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/map.hpp>

export module IRace;

import <map>;
import enumeration;

export class IRace
{
public:
	IRace() = default;
	
	int ability_score_increase(Ability ability) const;
	void set_ability_score_increase(Ability ability, int increase);
	
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_ability_score_increase);
	}

	std::map<Ability, int> m_ability_score_increase;
};

BOOST_CLASS_VERSION(IRace, serialization_versions::irace)