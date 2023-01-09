module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Druid;

import enumeration;
import IClass;
import Spellcaster;

export class Druid : public IClass, public Spellcaster
{
public:
	Druid() : IClass(HitDice::eight), Spellcaster(Ability::wisdom)
	{
		std::vector<Ability> saving_throw{ Ability::intelligence, Ability::wisdom };
		set_saving_throw(saving_throw);
	}

	virtual ~Druid() = default;

	void reset_spell_slots(int level) override;

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(IClass);
		ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(Spellcaster);
	}
};