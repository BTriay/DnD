module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Spellcaster;

import <array>;
import <stdexcept>;
import enumeration;
import Die;
import ICreature;

export class Spellcaster
{
public:
	Spellcaster(Ability spellcasting_ability, std::array<int, 10> spell_slots) :
		m_spellcasting_ability(spellcasting_ability), 
		m_spell_slots(spell_slots) {}

	// ****** cantrips ******
	
	// [int, Damage, int] /* attack_roll, damage_roll, damage_type*/ 
	//		firebolt(int hero_level)
	/*
		range spell attack
		if hit, 1d10 fire damage
		increased to 2d10 at 5th level, etc
	*/
	
	// ******* level 1 ******


	// ******* level 2 ******
	int flame_blade(SpellAction spell_action = SpellAction::Attack,
		int level = 2, bool critial_hit = false);

protected:
	Spellcaster() = default; // for serialization

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_spellcasting_ability);
		ar& BOOST_SERIALIZATION_NVP(m_spell_slots);
	}

	Ability m_spellcasting_ability;
	std::array<int, 10> m_spell_slots;
};

BOOST_CLASS_VERSION(Spellcaster, serialization_versions::spellcaster)