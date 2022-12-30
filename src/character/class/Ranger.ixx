module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Ranger;

import enumeration;
import IClass;

export class Ranger : public IClass
{
public:
	Ranger() : IClass(HitDice::eight)
	{
		std::vector<Ability> saving_throw{ Ability::dexterity, Ability::strength };
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