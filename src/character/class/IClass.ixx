export module IClass;

import <vector>;
import enumeration;

export class IClass
{
public:
	IClass(HitDice hit_dice, int level = 1) : m_hit_dice(hit_dice), m_level(level) {}

	HitDice hit_dice() const;
	void add_skill(Skill skill); /*!< Give a skill to the hero */
	int level() const; /*!< Get the hero's level */
	void gain_level();

	//virtual int proficiency_bonus();

protected:
	void set_saving_throw(std::vector<Ability> saving_throw);

private:
	int m_level;
	int m_used_hit_die;

	HitDice m_hit_dice;
	std::vector<Skill> m_eligible_skill;
	std::vector<Skill> m_skill;
	std::vector<Ability> m_saving_throw;
};