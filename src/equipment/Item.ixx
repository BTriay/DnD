export module Item;

import <map>;
import enumeration;

/*!
This class should be inherited by Weapon, Armor, etc.
This is to attach extra abilities to these items
(e.g. a magic mace with extra strength)
*/
export class Item
{
public:
	
	int ability_score_increase(Ability ability) const;
	void set_ability_score_increase(Ability ability, int increase);

private:
	std::map<Ability, int> m_ability_score_increase;
};