module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Rogue;

import enumeration;
import IClass;

export class Rogue : public IClass
{
public:
	Rogue() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::dexterity, Ability::intelligence };
		set_saving_throw(saving_throw);
	}

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(IClass);
	}
};