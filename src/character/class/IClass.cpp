module IClass;

import enumeration;

/* PUBLIC MEMBER FUNCTIONS */

void IClass::add_skill(Skill skill)
{
	m_skill.push_back(skill);
}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* PROTECTED MEMBER FUNCTIONS */

void IClass::set_hit_dice(HitDice hit_dice)
{
	m_hit_dice = hit_dice;
}

void IClass::set_saving_throw(std::vector<Ability> saving_throw)
{
	m_saving_throw = saving_throw;
}

/* END OF PROTECTED MEMBER FUNCTIONS */


/* PRIVATE MEMBER FUNCTIONS */


/* END OF PRIVATE MEMBER FUNCTIONS */

