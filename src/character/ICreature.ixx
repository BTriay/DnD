export module ICreature;

import <map>;
import <vector>;
import enumeration;
import Armor;
import Weapon;

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

	int ability_score(Ability ability) const;
	virtual int ability_modifier(Ability ability) const;
	void set_ability_score(Ability ability, int score);
	void set_skill_score(Skill skill, int score);

	void set_hit_points_max(int hp);
	int hit_points_max() const; 
	virtual void restore_current_hp_to_max();
	void set_current_hp(int hp);
	int current_hit_points() const;

	virtual void short_rest();
	virtual void long_rest();

	void add_resistance(Damage resistance);
	
	void set_darkvision(int darkvision_distance);
	void set_speed_land(int speed_land);
	void set_speed_climb(int speed_climb);
	void set_speed_air(int speed_air);
	void set_speed_water(int speed_water);

	void don_armor(Armor& armor) { m_armor = armor; }
	void don_armor(ArmorType armor_type) { m_armor = armor_creator(armor_type); }
	void doff_armor() { m_armor = armor_creator(ArmorType::none); }

	virtual int armor_class() const
	{
		return m_armor.armor_class(ability_modifier(Ability::dexterity))
			+ (m_has_shield ? 2 : 0);
	}

	void don_shield() { m_has_shield = true; }
	void doff_shield() { m_has_shield = false; }

	void add_weapon_one(const Weapon& weapon) { m_weapon_1 = weapon; }
	void drop_weapon_one() { m_weapon_1 = {}; }
	void add_weapon_two(Weapon& weapon) { m_weapon_2 = weapon; }
	void drop_weapon_two() { m_weapon_2 = {}; }

private:
	
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

	std::map<Ability, int> m_ability_score;
	std::map<Skill, int> m_skill_score; // if different from the ability-implied score
	std::vector<Damage> m_resistance;

	void set_default_ability_scores();

	bool m_has_shield;
	Armor m_armor;
	Weapon m_weapon_1;
	Weapon m_weapon_2;
};