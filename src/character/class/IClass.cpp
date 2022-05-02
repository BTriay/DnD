module IClass;

import enumeration;

/* PUBLIC MEMBER FUNCTIONS */

void IClass::add_skill(Skill skill)
{
	m_skill.push_back(skill);
}

int IClass::level() const
{
	return m_level;
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

