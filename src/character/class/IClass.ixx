export module IClass;

import <vector>;
import enumeration;

export class IClass
{
public:
	IClass();

	void add_skill(Skill skill);

	virtual int proficiency_bonus() = 0;

protected:
	void set_hit_dice(HitDice hit_dice);
	void set_saving_throw(std::vector<Ability> saving_throw);

private:
	int m_level;
	int m_used_hit_die;

	HitDice m_hit_dice;
	std::vector<Skill> m_eligible_skill;
	std::vector<Skill> m_skill;
	std::vector<Ability> m_saving_throw;
};