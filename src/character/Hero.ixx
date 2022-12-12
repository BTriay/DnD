module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Hero;

import <stdexcept>;
import <string>;
import <fstream>;
import <iostream>;

import RaceCreature;
import IClass;
import Die;
import enumeration;

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


export class Hero
{
public:
    /*! Build a hero! */
    Hero(const std::string& name) : Hero(name, nullptr, nullptr) {}

    Hero(const std::string& name, RaceCreature* race_creature, IClass* cclass) : 
        m_hero_name(name), m_race_creature(race_creature), m_class(cclass) {}

    Hero(const std::string& name, Race race) :
        m_hero_name(name), m_class(nullptr)
    {
        m_race_creature = new RaceCreature{ race };
    }

    ~Hero()
    {
        if (m_race_creature) delete m_race_creature;
        if (m_class) delete m_class;
    }

    void set_race_creature(RaceCreature* race_creature)
    {
        m_race_creature = race_creature;
    }

    void set_class(IClass* cclass)
    {
        m_class = cclass;
    }

    void set_ability_score(Ability ability, int score)
    {
        m_race_creature->set_ability_score(ability, score);
    }

    /*! Get the name of the hero */
    const std::string& name() const { return m_hero_name; }

    /*! Get the ability modifier of the hero */
    int ability_modifier(Ability ability) const
    {
        return (m_race_creature->ability_score_increase(ability) + m_race_creature->ability_score(ability)
            - 10) / 2;
    }

    /*! Override ICreature's set_hit_points_max to include the constitution bonus */
    void restore_current_hp_to_max()
    {        
        //auto hilldwarf_additional_hp =
        //    //std::is_same_v< HillDwarf, R> ? 1 : 0;
        //    dynamic_cast<HillDwarf*>(m_race) ? 1 : 0;

        //R::set_current_hp(R::hit_points_max()
        //    + C::level() * (hilldwarf_additional_hp

        //dynamic_cast<ICreature*>(m_race)->set_current_hp(dynamic_cast<ICreature*>(m_race)->hit_points_max()
        //    + m_class->level() * (hilldwarf_additional_hp
        //        + ability_modifier(Ability::constitution)));
    }

    /* functions pointing to IClass */
    HitDice hit_dice() const { return m_class->hit_dice(); }
    void add_skill(Skill skill) { m_class->add_skill(skill); } /*!< Give a skill to the hero */
    int level() const { return m_class->level(); } /*!< Get the hero's level */

    void gain_level(bool add_default_hp)
    {
        m_class->gain_level();

        auto extra_hp = add_default_hp ? 
            (static_cast<int>(m_class->hit_dice()) + 2) / 2 :
            Die::gen(1, m_class->hit_dice());

        m_race_creature->set_hit_points_max(m_race_creature->hit_points_max() 
            + extra_hp);
    }
    
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
    {
        if (!m_race_creature || !m_class)
        {
            throw std::invalid_argument("uninitialized m_race_creature or m_class");
        }

        ar& BOOST_SERIALIZATION_NVP(m_hero_name);
        ar& BOOST_SERIALIZATION_NVP(m_race_creature);

        if (auto dp = dynamic_cast<Cleric*>(m_class))
        {
            m_class_name = "Cleric";
            ar& boost::serialization::make_nvp("Cleric", dp);
        }

        ar& BOOST_SERIALIZATION_NVP(m_class_name);
    }

    std::string m_hero_name;
    std::string m_class_name;
    RaceCreature* m_race_creature;
    IClass* m_class;
};

BOOST_CLASS_VERSION(Item, serialization_versions::hero)

//export template <typename C, typename R>
//    requires std::is_base_of_v<IClass, C> && std::is_base_of_v<IRace, R>
//std::ostream& operator<<(std::ostream& os, const Hero<C, R>& hero)
//{
//    os << hero.name() << " is a " << hero.class_name() << " "
//        << hero.race_name() << " of level " << hero.level() 
//        << " and has the following abilities:\n";
//    os << "\tcharisma: " << hero.ability_modifier(Ability::charisma) << '\n';
//    os << "\tconstitution: " << hero.ability_modifier(Ability::constitution) << '\n';
//    os << "\tdexterity: " << hero.ability_modifier(Ability::dexterity) << '\n';
//    os << "\tintelligence: " << hero.ability_modifier(Ability::intelligence) << '\n';
//    os << "\tstrength: " << hero.ability_modifier(Ability::strength) << '\n';
//    os << "\twisdom: " << hero.ability_modifier(Ability::wisdom) << '\n';
//    os << hero.name() << " has an AC of " << hero.armor_class();
//    os << " and " << hero.current_hit_points() << " hit points" << '\n';
//
//    return os;
//}

