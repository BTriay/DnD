module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/map.hpp>

export module Item;

import <map>;
import enumeration;

/*!
This class should be inherited by Weapon, Armor, etc.
This is to attach extra abilities to these items
(e.g. a magic mace with extra strength)
*/
export class Item
{
public:
	Item() = default;
	Item& operator=(const Item&) = default;

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

BOOST_CLASS_VERSION(Item, serialization_versions::item)