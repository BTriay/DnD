module Die;


Die& Die::operator=(const Die& rhs)
{
	m_number_dice = rhs.m_number_dice;
	m_df = rhs.m_df;
	m_bonus = rhs.m_bonus;

	return *this;
}