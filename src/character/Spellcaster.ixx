module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Spellcaster;

import enumeration;

export class Spellcaster
{
public:
	
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{

	}

};

BOOST_CLASS_VERSION(Spellcaster, serialization_versions::spellcaster)