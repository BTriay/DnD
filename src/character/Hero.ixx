export module Hero;

import <string>;
import <iostream>;

import IClass;
import IRace;
import enumeration;
import Armor;

// classes
import Cleric;
import Druid;
import Fighter;
import Monk;
import Paladin;
import Ranger;
import Rogue;
import Sorcerer;
import Warlock;
import Wizard;

// races
import Dwarf;
import Elf;
import Halfling;
import Human;
import Dragonborn;
import Gnome;
import HalfElf;
import HalfOrc;
import Tiefling;


export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C> && std::is_base_of_v<IRace, R>
class Hero : public C, public R
{
public:
    /*! Build a hero! */
    Hero(const std::string& name) : 
        m_name(name), m_has_shield(false), C(), R() {}

    /*! Get the name of the hero */
    const std::string& name() const { return m_name; }

    /*! Get the ability modifier of the hero */
    int ability_modifier(Ability ability) const override
    {
        return (R::ability_score_increase(ability) + R::ability_score(ability) 
            + m_armor.ability_score_increase(ability) - 10) / 2;
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

    void don_armor(Armor& armor) { m_armor = armor; }
    void don_armor(ArmorType armor_type) { m_armor = armor_creator(armor_type); }
    void doff_armor()
    {
        m_armor = armor_creator(ArmorType::none);
    }

    int armor_class() const
    { 
        return m_armor.armor_class(ability_modifier(Ability::dexterity))
            + (m_has_shield ? 2 : 0);
    }

    void don_shield() { m_has_shield = true; }
    void doff_shield() { m_has_shield = false; }

private:
    bool m_has_shield;
    const std::string m_name;
    Armor m_armor;
};

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C> && std::is_base_of_v<IRace, R>
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
    os << hero.name() << " has an AC of " << hero.armor_class() << '\n';

    return os;
}


template class Hero<Cleric, HillDwarf>;
template class Hero<Cleric, MountainDwarf>;
template class Hero<Cleric, HighElf>;
template class Hero<Cleric, WoodElf>;
template class Hero<Cleric, DarkElf>;
template class Hero<Cleric, Lightfoot>;
template class Hero<Cleric, Stout>;
template class Hero<Cleric, Human>;
template class Hero<Cleric, Dragonborn>;
template class Hero<Cleric, ForestGnome>;
template class Hero<Cleric, RockGnome>;
template class Hero<Cleric, HalfElf>;
template class Hero<Cleric, HalfOrc>;
template class Hero<Cleric, Tiefling>;

template class Hero<Druid, HillDwarf>;
template class Hero<Druid, MountainDwarf>;
template class Hero<Druid, HighElf>;
template class Hero<Druid, WoodElf>;
template class Hero<Druid, DarkElf>;
template class Hero<Druid, Lightfoot>;
template class Hero<Druid, Stout>;
template class Hero<Druid, Human>;
template class Hero<Druid, Dragonborn>;
template class Hero<Druid, ForestGnome>;
template class Hero<Druid, RockGnome>;
template class Hero<Druid, HalfElf>;
template class Hero<Druid, HalfOrc>;
template class Hero<Druid, Tiefling>;

template class Hero<Fighter, HillDwarf>;
template class Hero<Fighter, MountainDwarf>;
template class Hero<Fighter, HighElf>;
template class Hero<Fighter, WoodElf>;
template class Hero<Fighter, DarkElf>;
template class Hero<Fighter, Lightfoot>;
template class Hero<Fighter, Stout>;
template class Hero<Fighter, Human>;
template class Hero<Fighter, Dragonborn>;
template class Hero<Fighter, ForestGnome>;
template class Hero<Fighter, RockGnome>;
template class Hero<Fighter, HalfElf>;
template class Hero<Fighter, HalfOrc>;
template class Hero<Fighter, Tiefling>;

template class Hero<Monk, HillDwarf>;
template class Hero<Monk, MountainDwarf>;
template class Hero<Monk, HighElf>;
template class Hero<Monk, WoodElf>;
template class Hero<Monk, DarkElf>;
template class Hero<Monk, Lightfoot>;
template class Hero<Monk, Stout>;
template class Hero<Monk, Human>;
template class Hero<Monk, Dragonborn>;
template class Hero<Monk, ForestGnome>;
template class Hero<Monk, RockGnome>;
template class Hero<Monk, HalfElf>;
template class Hero<Monk, HalfOrc>;
template class Hero<Monk, Tiefling>;

template class Hero<Paladin, HillDwarf>;
template class Hero<Paladin, MountainDwarf>;
template class Hero<Paladin, HighElf>;
template class Hero<Paladin, WoodElf>;
template class Hero<Paladin, DarkElf>;
template class Hero<Paladin, Lightfoot>;
template class Hero<Paladin, Stout>;
template class Hero<Paladin, Human>;
template class Hero<Paladin, Dragonborn>;
template class Hero<Paladin, ForestGnome>;
template class Hero<Paladin, RockGnome>;
template class Hero<Paladin, HalfElf>;
template class Hero<Paladin, HalfOrc>;
template class Hero<Paladin, Tiefling>;

template class Hero<Ranger, HillDwarf>;
template class Hero<Ranger, MountainDwarf>;
template class Hero<Ranger, HighElf>;
template class Hero<Ranger, WoodElf>;
template class Hero<Ranger, DarkElf>;
template class Hero<Ranger, Lightfoot>;
template class Hero<Ranger, Stout>;
template class Hero<Ranger, Human>;
template class Hero<Ranger, Dragonborn>;
template class Hero<Ranger, ForestGnome>;
template class Hero<Ranger, RockGnome>;
template class Hero<Ranger, HalfElf>;
template class Hero<Ranger, HalfOrc>;
template class Hero<Ranger, Tiefling>;

template class Hero<Rogue, HillDwarf>;
template class Hero<Rogue, MountainDwarf>;
template class Hero<Rogue, HighElf>;
template class Hero<Rogue, WoodElf>;
template class Hero<Rogue, DarkElf>;
template class Hero<Rogue, Lightfoot>;
template class Hero<Rogue, Stout>;
template class Hero<Rogue, Human>;
template class Hero<Rogue, Dragonborn>;
template class Hero<Rogue, ForestGnome>;
template class Hero<Rogue, RockGnome>;
template class Hero<Rogue, HalfElf>;
template class Hero<Rogue, HalfOrc>;
template class Hero<Rogue, Tiefling>;

template class Hero<Sorcerer, HillDwarf>;
template class Hero<Sorcerer, MountainDwarf>;
template class Hero<Sorcerer, HighElf>;
template class Hero<Sorcerer, WoodElf>;
template class Hero<Sorcerer, DarkElf>;
template class Hero<Sorcerer, Lightfoot>;
template class Hero<Sorcerer, Stout>;
template class Hero<Sorcerer, Human>;
template class Hero<Sorcerer, Dragonborn>;
template class Hero<Sorcerer, ForestGnome>;
template class Hero<Sorcerer, RockGnome>;
template class Hero<Sorcerer, HalfElf>;
template class Hero<Sorcerer, HalfOrc>;
template class Hero<Sorcerer, Tiefling>;

template class Hero<Warlock, HillDwarf>;
template class Hero<Warlock, MountainDwarf>;
template class Hero<Warlock, HighElf>;
template class Hero<Warlock, WoodElf>;
template class Hero<Warlock, DarkElf>;
template class Hero<Warlock, Lightfoot>;
template class Hero<Warlock, Stout>;
template class Hero<Warlock, Human>;
template class Hero<Warlock, Dragonborn>;
template class Hero<Warlock, ForestGnome>;
template class Hero<Warlock, RockGnome>;
template class Hero<Warlock, HalfElf>;
template class Hero<Warlock, HalfOrc>;
template class Hero<Warlock, Tiefling>;

template class Hero<Wizard, HillDwarf>;
template class Hero<Wizard, MountainDwarf>;
template class Hero<Wizard, HighElf>;
template class Hero<Wizard, WoodElf>;
template class Hero<Wizard, DarkElf>;
template class Hero<Wizard, Lightfoot>;
template class Hero<Wizard, Stout>;
template class Hero<Wizard, Human>;
template class Hero<Wizard, Dragonborn>;
template class Hero<Wizard, ForestGnome>;
template class Hero<Wizard, RockGnome>;
template class Hero<Wizard, HalfElf>;
template class Hero<Wizard, HalfOrc>;
template class Hero<Wizard, Tiefling>;