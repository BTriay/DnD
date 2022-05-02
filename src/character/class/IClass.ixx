export module IClass;

import <vector>;
import enumeration;

export class IClass
{
public:
	IClass(HitDice hit_dice) : m_hit_dice(hit_dice) {}

	void add_skill(Skill skill); /*!< Give a skill to the hero */
	int level() const; /*!< Get the hero's level */

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