export module Hero;

import <string>;
import <iostream>;

import IClass;
import IRace;
import enumeration;

import Cleric;
import Dwarf;


export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
class Hero : public C, public R
{
public:
    /*! Build a hero! */
    Hero(const std::string& name) : m_name(name), C(), R() {}

    /*! Get the name of the hero */
    const std::string& name() const { return m_name; }
    /*! Get the ability modifier of the hero */
    int ability_modifier(Ability ability) const override
    {
        return (R::ability_score_increase(ability) + R::ability_score(ability) - 10) / 2;
    }

    /*! Override the ICreature's set_hit_points_max member function 
        to include the constitution bonus
    */
    void set_hit_points_max(int hp) override
    {
        auto hildwarf_additional_hp = 
            std::is_same_v< HillDwarf, R> ? 1 : 0;
        
        R::set_hit_points_max(hp + (C::level() + hildwarf_additional_hp)
            * ability_modifier(Ability::constitution));
    }

private:
    const std::string m_name;
};

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
std::ostream& operator<<(std::ostream& os, const Hero<C, R>& hero)
{
    os << hero.name() << " is level " << hero.level() 
        << " and has the following abilities:\n";
    os << "\tcharisma: " << hero.ability_modifier(Ability::charisma) << '\n';
    os << "\tconstitution: " << hero.ability_modifier(Ability::constitution) << '\n';
    os << "\tdexterity: " << hero.ability_modifier(Ability::dexterity) << '\n';
    os << "\tintelligence: " << hero.ability_modifier(Ability::intelligence) << '\n';
    os << "\tstrength: " << hero.ability_modifier(Ability::strength) << '\n';
    os << "\twisdom: " << hero.ability_modifier(Ability::wisdom) << '\n';

    return os;
}


template class Hero<Cleric, HillDwarf>;
template class Hero<Cleric, MountainDwarf>;