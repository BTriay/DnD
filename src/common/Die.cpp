module Die;

/*! Die copy constructor */
Die& Die::operator=(const Die& rhs)
{
	m_number_dice = rhs.m_number_dice;
	m_hit_dice = rhs.m_hit_dice;
	m_bonus = rhs.m_bonus;

	return *this;
}

/*! Roll the die */
int Die::roll(bool critical_hit) const
{
	return roll_normal(m_number_dice * (1 + 1 * critical_hit), m_hit_dice, m_bonus);
}