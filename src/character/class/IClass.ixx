module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/vector.hpp>

export module IClass;

import <vector>;
import enumeration;

export class IClass
{
public:
	IClass(HitDice hit_dice, int level = 1) : 
		m_hit_dice(hit_dice), m_level(level) {}

	HitDice hit_dice() const;
	void add_skill(Skill skill); /*!< Give a skill to the hero */
	int level() const; /*!< Get the hero's level */
	virtual void gain_level();
	int proficiency_bonus() const;

	//virtual int proficiency_bonus();

protected:
	IClass() = default; // for serialization
	void set_saving_throw(std::vector<Ability> saving_throw);

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_level);
		ar& BOOST_SERIALIZATION_NVP(m_used_hit_die);
		ar& BOOST_SERIALIZATION_NVP(m_hit_dice);
		ar& BOOST_SERIALIZATION_NVP(m_eligible_skill);
		ar& BOOST_SERIALIZATION_NVP(m_skill);
		ar& BOOST_SERIALIZATION_NVP(m_saving_throw);
	}

	int m_level;
	int m_used_hit_die = 0;

	HitDice m_hit_dice;
	std::vector<Skill> m_eligible_skill;
	std::vector<Skill> m_skill;
	std::vector<Ability> m_saving_throw;
};

BOOST_CLASS_VERSION(IClass, serialization_versions::iclass)