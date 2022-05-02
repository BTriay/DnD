export module Hero;

import <string>;
import <iostream>;

import IClass;
import IRace;
import enumeration;

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
class Hero : public C, public R
{
public:
    Hero(const std::string& name) : m_name(name), C(), R() {}

    const std::string& name() const { return m_name; }
    int ability_modifier(Ability ability) const override
    {
        return (R::ability_score_increase(ability) + R::ability_score(ability) - 10) / 2;
    }

private:
    const std::string m_name;
};

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
std::ostream& operator<<(std::ostream& os, const Hero<C, R>& hero)
{
    os << hero.name() << " has the following abilities:\n";
    os << "\tcharisma: " << hero.ability_modifier(Ability::charisma) << '\n';
    os << "\tconstitution: " << hero.ability_modifier(Ability::constitution) << '\n';
    os << "\tdexterity: " << hero.ability_modifier(Ability::dexterity) << '\n';
    os << "\tintelligence: " << hero.ability_modifier(Ability::intelligence) << '\n';
    os << "\tstrength: " << hero.ability_modifier(Ability::strength) << '\n';
    os << "\twisdom: " << hero.ability_modifier(Ability::wisdom) << '\n';

    return os;
}


// is this really the best way to do this?
import Cleric;
import Dwarf;

template class Hero<Cleric, HillDwarf>;
template class Hero<Cleric, MountainDwarf>;