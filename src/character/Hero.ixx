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
    Hero(const std::string& name, Race race, const std::string& cclass) :
        m_hero_name(name)
    {        
        m_heroic_creature = new HeroicCreature{ race };

        m_class_name = cclass;
        if (!cclass.compare("Cleric"))
            m_class = new Cleric;
        else if (!cclass.compare("Druid"))
            m_class = new Druid;
        else if (!cclass.compare("Fighter"))
            m_class = new Fighter;
        else if (!cclass.compare("Monk"))
            m_class = new Monk;
        else if (!cclass.compare("Paladin"))
            m_class = new Paladin;
        else if (!cclass.compare("Ranger"))
            m_class = new Ranger;
        else if (!cclass.compare("Rogue"))
            m_class = new Rogue;
        else if (!cclass.compare("Sorcerer"))
            m_class = new Sorcerer;
        else if (!cclass.compare("Warlock"))
            m_class = new Warlock;
        else if (!cclass.compare("Wizard"))
            m_class = new Wizard;

        restore_current_hp_to_max();
    }

    Hero(const Hero& rhs) = delete;
    Hero(Hero&& rhs);
    Hero& operator=(const Hero&) = delete;
    //Hero& operator=(Hero&&) = delete;

    ~Hero();

    void set_race_creature(HeroicCreature* race_creature);

    void set_ability_score(Ability ability, int score);

    /*! Get the name of the hero */
    const std::string name() const;

    std::string class_name() const;
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
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Druid*>(m_class))
        {
            m_class_name = "Druid";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Fighter*>(m_class))
        {
            m_class_name = "Fighter";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Monk*>(m_class))
        {
            m_class_name = "Monk";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Paladin*>(m_class))
        {
            m_class_name = "Paladin";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Ranger*>(m_class))
        {
            m_class_name = "Ranger";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Rogue*>(m_class))
        {
            m_class_name = "Rogue";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Sorcerer*>(m_class))
        {
            m_class_name = "Sorcerer";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Warlock*>(m_class))
        {
            m_class_name = "Warlock";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }
        else if (auto dp = dynamic_cast<Wizard*>(m_class))
        {
            m_class_name = "Wizard";
            ar& boost::serialization::make_nvp(m_class_name.c_str(), dp);
        }

        ar& BOOST_SERIALIZATION_NVP(m_class_name);
    }

    std::string m_hero_name;
    mutable std::string m_class_name;
    HeroicCreature* m_heroic_creature;
    IClass* m_class;
};

BOOST_CLASS_VERSION(Item, serialization_versions::hero)

export std::ostream& operator<<(std::ostream& os, const Hero& hero)
{
    os << hero.name() << " is a " << hero.class_name() << " "
        << hero.race_name() << " of level " << hero.level() 
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

