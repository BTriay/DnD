module IClass;

import enumeration;

/* PUBLIC MEMBER FUNCTIONS */

HitDice IClass::hit_dice() const
{
	return m_hit_dice;
}

void IClass::add_skill(Skill skill)
{
	m_skill.push_back(skill);
}

int IClass::level() const
{
	return m_level;
}

void IClass::gain_level()
{
	++m_level;
}

int IClass::proficiency_bonus() const
{
	if (m_level <= 4)
		return 2;
	else if (m_level <= 8)
		return 3;
	else if (m_level <= 12)
		return 4;
	else if (m_level <= 16)
		return 5;
	else
		return 6;
}


/* END OF PUBLIC MEMBER FUNCTIONS */

/* PROTECTED MEMBER FUNCTIONS */

void IClass::set_saving_throw(std::vector<Ability> saving_throw)
{
	m_saving_throw = saving_throw;
}

/* END OF PROTECTED MEMBER FUNCTIONS */


/* PRIVATE MEMBER FUNCTIONS */


/* END OF PRIVATE MEMBER FUNCTIONS */

