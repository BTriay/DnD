 module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Wizard;

import enumeration;
import IClass;

export class Wizard : public IClass
{
public:
	Wizard() : IClass(HitDice::six)
	{
		std::vector<Ability> saving_throw{ Ability::intelligence, Ability::wisdom };
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