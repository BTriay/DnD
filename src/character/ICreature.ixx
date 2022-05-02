export module ICreature;

import <map>;
import <vector>;
import enumeration;

/*!
Class common to all the creatures of the DnD world:
heroes, NPC, monsters
*/
export class ICreature
{
public:
	ICreature(int darkvision, Size size, int speed_land, int speed_climb, int speed_air,
		int speed_water) : 
		m_darkvision(darkvision), m_size(size), m_speed_land(speed_land), m_speed_climb(speed_climb),
		m_speed_air(speed_air), m_speed_water(speed_water)
	{
		set_default_ability_scores();
	}

	int ability_score(Ability ability) const; /*!< Get the ability score of the creature */
	virtual int ability_modifier(Ability ability) const; /*!< Get the ability modifier of the creature */
	void set_ability_score(Ability ability, int score); /*!< Set the ability score of the creature */
	void set_skill_score(Skill skill, int score); /*!< Get the ability score of the creature */
	void add_resistance(Damage resistance); /*!< Add resistance to the creature */
	virtual void set_hit_points_max(int hp);
	
	void set_darkvision(int darkvision_distance);
	void set_speed_land(int speed_land);
	void set_speed_climb(int speed_climb);
	void set_speed_air(int speed_air);
	void set_speed_water(int speed_water);

	//virtual int armor_class() = 0;
	//virtual int difficulty_class() = 0;

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

	// TODO:
	//	armor
	//	vector<Weapon> weapons; // how to know which weapon(s) is being used, vs which is in pack?
	//	Item& shield;
	//	vector<Item&> m_rings;
	//	vector<Item&> m_amulets;
	//	vector<item> // magical items: gloves, helmet, belt, etc.
};