export module IRace;

import <map>;
import enumeration;

export class IRace
{
public:
	void ability_score_increase(Ability ability, int increase);

private:
	std::map<Ability, int> m_ability_score_increase;
};