module IRace;

void IRace::set_ability_score_increase(Ability ability, int increase)
{
	m_ability_score_increase[ability] = increase;
}