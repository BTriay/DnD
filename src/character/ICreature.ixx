export module ICreature;

import <map>;
import enumeration;

export class ICreature // attributes common to players, NPC, monsters
{
public:
	ICreature(int speed_land, int speed_climb, int speed_air,
		int speed_water, int darkvision) : 
		m_speed_land(speed_land), m_speed_climb(speed_climb), m_speed_air(speed_air),
		m_speed_water(speed_water), m_darkvision(darkvision) {}

	template <Ability T>
	int modifier();

	void set_ability_score(Ability ability, int score);
	void set_skill_score(Skill skill, int score);
	virtual void set_hit_points_max(int hp);

	virtual int armor_class() = 0;
	virtual int difficulty_class() = 0;

private:
	std::map<Ability, int> m_ability_score;
	std::map<Skill, int> m_skill_score; // if different from teh ability-implied score

	int m_speed_land;
	int m_speed_climb;
	int m_speed_air;
	int m_speed_water;
	int m_darkvision;

	int m_hit_points_max_without_constit; // i.e. exclude constitution bonus
	int m_hit_points_current;

	// TODO:
	//	armor
	//	vector<Weapon> weapons; // how to know which weapon(s) is being used, vs which is in pack?
	//	Item& shield;
	//	vector<Item&> m_rings;
	//	vector<Item&> m_amulets;
	//	vector<item> // magical items: gloves, helmet, belt, etc.
};