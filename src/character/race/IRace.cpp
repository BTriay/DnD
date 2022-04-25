module IRace;

void IRace::ability_score_increase(Ability ability, int increase)
{
	m_ability_score_increase[ability] = increase;
}