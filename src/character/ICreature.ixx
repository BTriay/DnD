module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>

export module ICreature;

import <map>;
import <vector>;
import enumeration;
import Armor;
import Weapon;
import Die;

/*!
Class common to all the creatures of the DnD world:
heroes, NPC, monsters
*/
export class ICreature
{
public:
	ICreature(int hit_points_max, int darkvision, Size size, int speed_land, int speed_climb = 0, 
		int speed_air = 0, int speed_water = 0) :
		m_hit_points_max_without_constit(hit_points_max),
		m_darkvision(darkvision), m_size(size), m_speed_land(speed_land), m_speed_climb(speed_climb),
		m_speed_air(speed_air), m_speed_water(speed_water), m_has_shield(false)
	{
		set_default_ability_scores();
		restore_current_hp_to_max();
	}

	// ICreature's setup and abilities
	int ability_score(Ability ability) const;
	virtual int ability_modifier(Ability ability) const;
	void set_ability_score(Ability ability, int score);
	void set_skill_score(Skill skill, int score);

	virtual int ability_score_increase(Ability ability) const;
	virtual void set_ability_score_increase(Ability ability, int increase);

	void set_size(Size size);
	Size size() const;

	void set_hit_points_without_constit(int hp);
	int hit_points_without_constit() const;
	virtual void restore_current_hp_to_max();
	virtual void set_current_hp(int hp);
	virtual int current_hit_points() const;
	virtual void lose_hit_points(int hit_points);

	void add_resistance(Damage resistance);
	
	int darkvision() const;
	void set_darkvision(int darkvision_distance);
	void set_speed_land(int speed_land);
	void set_speed_climb(int speed_climb);
	void set_speed_air(int speed_air);
	void set_speed_water(int speed_water);

	// Actions section
	virtual void short_rest();
	virtual void long_rest();

	virtual int attack_roll(Ability ability, DieThrowAdvantage throw_advantage
		= DieThrowAdvantage::Normal) const;

	// Gear section
	void don_armor(Armor& armor);
	void don_armor(ArmorType armor_type);
	void doff_armor();

	virtual int armor_class() const;

	void don_shield();
	void doff_shield();

	void add_weapon_one(const Weapon& weapon);
	void drop_weapon_one();
	void add_weapon_two(Weapon& weapon);
	void drop_weapon_two();

protected:
	ICreature() : ICreature(1, 0, Size::medium, 0) {} // for serialization
	void set_default_ability_scores();

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_darkvision);
		ar& BOOST_SERIALIZATION_NVP(m_size);
		ar& BOOST_SERIALIZATION_NVP(m_speed_land);
		ar& BOOST_SERIALIZATION_NVP(m_speed_climb);
		ar& BOOST_SERIALIZATION_NVP(m_speed_air);
		ar& BOOST_SERIALIZATION_NVP(m_speed_water);
		ar& BOOST_SERIALIZATION_NVP(m_hit_points_max_without_constit);
		ar& BOOST_SERIALIZATION_NVP(m_hit_points_current);
		ar& BOOST_SERIALIZATION_NVP(m_ability_score);
		ar& BOOST_SERIALIZATION_NVP(m_ability_score_increase);
		ar& BOOST_SERIALIZATION_NVP(m_skill_score);
		ar& BOOST_SERIALIZATION_NVP(m_resistance);
		ar& BOOST_SERIALIZATION_NVP(m_has_shield);
		ar& BOOST_SERIALIZATION_NVP(m_armor);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_1);
		ar& BOOST_SERIALIZATION_NVP(m_weapon_2);
	}

	int m_darkvision; /*!< Darkvision, in feet */
	Size m_size; /*!< Tiny, Small, etc */
	int m_speed_land; /*!< Walking speed, in feet per turn */
	int m_speed_climb; /*!< Climbing speed, in feet per turn */
	int m_speed_air; /*!< Flying speed, in feet per turn */
	int m_speed_water; /*!< Swimming speed, in feet per turn */

	/*!
	The maximum hit points, excluding the hp gained by the constitution modifier on each level
	*/
	int m_hit_points_max_without_constit;
	/*!
	Current hp. It includes the hp gained by the constitution modifier on each level,
	so it can be higher than m_hit_points_max_without_constit
	*/
	int m_hit_points_current;

	std::map<Ability, int> m_ability_score; /*!< Chosen by the player */
	std::map<Ability, int> m_ability_score_increase; /*!< From the race */
	std::map<Skill, int> m_skill_score; // if different from the ability-implied score
	std::vector<Damage> m_resistance;


	bool m_has_shield; /*!< The hero is carrying a shield if true */
	Armor m_armor; /*!< The armor carried by the hero */
	Weapon m_weapon_1; /*!< The first weapon carried by the hero */
	Weapon m_weapon_2; /*!< The second weapon carried by the hero */
};

BOOST_CLASS_VERSION(ICreature, serialization_versions::icreature)