module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Hero;

import <stdexcept>;
import <string>;
import <fstream>;
import <iostream>;

import HeroicCreature;
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
    Hero(const std::string& name, Race race) :
        m_hero_name(name), m_class(nullptr)
    {
        m_heroic_creature = new HeroicCreature{ race };
    }

    Hero(const Hero& rhs) = delete;
    Hero(Hero&& rhs);
    Hero& operator=(const Hero&) = delete;
    //Hero& operator=(Hero&&) = delete;

    ~Hero();

    void set_race_creature(HeroicCreature* race_creature);
    void set_class(IClass* cclass);

    void set_ability_score(Ability ability, int score);

    /*! Get the name of the hero */
    const std::string name() const;

    const std::string class_name() const;
    const std::string race_name() const;

    /*! Get the ability modifier of the hero */
    int ability_modifier(Ability ability) const;

    /*! Override ICreature's set_hit_points_max to include the constitution bonus */
    void restore_current_hp_to_max();
    int current_hit_points() const;

    /* functions pointing to IClass */
    HitDice hit_dice() const;
    void add_skill(Skill skill); /*!< Give a skill to the hero */
    int level() const; /*!< Get the hero's level */

    void gain_level(bool add_default_hp);
    
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
    {
        if (!m_heroic_creature || !m_class)
        {
            throw std::invalid_argument("uninitialized m_heroic_creature or m_class");
        }

        ar& BOOST_SERIALIZATION_NVP(m_hero_name);
        ar& BOOST_SERIALIZATION_NVP(m_heroic_creature);

        if (auto dp = dynamic_cast<Cleric*>(m_class))
        {
            m_class_name = "Cleric";
            ar& boost::serialization::make_nvp("Cleric", dp);
        }

        ar& BOOST_SERIALIZATION_NVP(m_class_name);
    }

    std::string m_hero_name;
    std::string m_class_name;
    HeroicCreature* m_heroic_creature;
    IClass* m_class;
};

BOOST_CLASS_VERSION(Item, serialization_versions::hero)

export std::ostream& operator<<(std::ostream& os, const Hero& hero)
{
    os << hero.name() << " is a '" << hero.class_name() << "' '"
        << hero.race_name() << "' of level " << hero.level() 
        << " and has the following abilities:\n";
    os << "\tcharisma: " << hero.ability_modifier(Ability::charisma) << '\n';
    os << "\tconstitution: " << hero.ability_modifier(Ability::constitution) << '\n';
    os << "\tdexterity: " << hero.ability_modifier(Ability::dexterity) << '\n';
    os << "\tintelligence: " << hero.ability_modifier(Ability::intelligence) << '\n';
    os << "\tstrength: " << hero.ability_modifier(Ability::strength) << '\n';
    os << "\twisdom: " << hero.ability_modifier(Ability::wisdom) << '\n';
    //os << hero.name() << " has an AC of " << hero.armor_class();
    os << " and " << hero.current_hit_points() << " hit points" << '\n';

    return os;
}

