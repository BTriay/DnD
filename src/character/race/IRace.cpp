module IRace;

/* PUBLIC MEMBER FUNCTIONS */

int IRace::ability_score_increase(Ability ability) const
{
	return m_ability_score_increase.at(ability);
}

void IRace::set_ability_score_increase(Ability ability, int increase)
{
	m_ability_score_increase[ability] = increase;
}

/* END OF PUBLIC MEMBER FUNCTIONS */

/* PROTECTED MEMBER FUNCTIONS */
/* END OF PROTECTED MEMBER FUNCTIONS */


/* PRIVATE MEMBER FUNCTIONS */
/* END OF PRIVATE MEMBER FUNCTIONS */
