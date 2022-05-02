export module Hero;

import <string>;

import IClass;
import IRace;
import enumeration;

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
class Hero : public C, public R
{
public:
    Hero(const std::string& name) : m_name(name), C(), R() {}

    int ability_modifier(Ability ability) const
    {
        return (R::ability_score_increase(ability) + R::ability_score(ability)) / 2;
    }

private:
    const std::string m_name;
};

// is this really the best way to do this?
import Cleric;
import Dwarf;

template class Hero<Cleric, HillDwarf>;
template class Hero<Cleric, MountainDwarf>;