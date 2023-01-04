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
int Die::roll() const
{
	return gen(m_number_dice, m_hit_dice, m_bonus);
}