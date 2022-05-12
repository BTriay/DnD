module Item;

int Item::ability_score_increase(Ability ability) const
{
	if (m_ability_score_increase.find(ability) != std::end(m_ability_score_increase))
		return m_ability_score_increase.at(ability);

	return 0;
}

void Item::set_ability_score_increase(Ability ability, int increase)
{
	m_ability_score_increase[ability] = increase;
}