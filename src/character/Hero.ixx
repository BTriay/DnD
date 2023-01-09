module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Hero;

import <string>;
import <fstream>;
import <iostream>;
import <stdexcept>;

import ICreature;
import HeroicCreature;
import IClass;
import Die;
import enumeration;

import Armor;

// classes
import Barbarian;
import Bard;
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

import Spellcaster;

export class Hero : public HeroicCreature
{
public:
    /*! Build a hero! */
    Hero(const std::string& name, Race race, const std::string& cclass, 
        AbilityScore ability_scores) : HeroicCreature(race, ability_scores),
        m_hero_name(name)
    {        

        m_class_name = cclass;
        if (!cclass.compare("Cleric"))
            m_class = new Cleric;
        else if (!cclass.compare("Barbarian"))
            m_class = new Barbarian;
        else if (!cclass.compare("Bard"))
            m_class = new Bard;
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

        set_hit_points_without_constit(static_cast<int>(m_class->hit_dice()));
        restore_current_hp_to_max();
    }

    Hero(const Hero& rhs) = delete; /*!< A hero shall not be copied */
    Hero(Hero&& rhs); /*!< But a hero may be moved */
    Hero& operator=(const Hero&) = delete; /*!< A hero shall not be copied */
    //Hero& operator=(Hero&&) = delete;

    ~Hero();    
    
    const std::string name() const;
    const std::string class_name() const;

    void restore_current_hp_to_max();
    void set_current_hp(int hp);
    int current_hit_points() const;
    void lose_hit_points(int hit_points);

    HitDice hit_dice() const;
    void add_skill(Skill skill);

    int level() const;
    int gain_level(bool add_default_hp);

    std::array<int, 10> available_spell_slots() const;

    void invoke_spell(const std::string& spell, ICreature& enemy, 
        DieThrowAdvantage throw_advantage = DieThrowAdvantage::Normal, 
        int level = 1);
    
private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
    {        
        ar.template register_type<Barbarian>();
        ar.template register_type<Bard>();
        ar.template register_type<Cleric>();
        ar.template register_type<Druid>();
        ar.template register_type<Fighter>();
        ar.template register_type<Monk>();
        ar.template register_type<Paladin>();
        ar.template register_type<Ranger>();
        ar.template register_type<Rogue>();
        ar.template register_type<Sorcerer>();
        ar.template register_type<Warlock>();
        ar.template register_type<Wizard>();

        ar& BOOST_SERIALIZATION_BASE_OBJECT_NVP(HeroicCreature);
        ar& BOOST_SERIALIZATION_NVP(m_hero_name);
        ar& BOOST_SERIALIZATION_NVP(m_class_name);
        ar& BOOST_SERIALIZATION_NVP(m_class);
        ar& BOOST_SERIALIZATION_NVP(m_hit_points_current);
    }

    std::string m_hero_name; /*!< The name of the hero */
    std::string m_class_name; /*!< The class name, e.g. Cleric. Necessary for deserialization */
    IClass* m_class; /*!< Base pointer to the class */
    int m_hit_points_current; /*!< Current hit points. This "overrides" the same parameter from ICreature */

    void fire_bolt(ICreature& enemy, DieThrowAdvantage throw_advantage);
    //void flame_blade(ICreature& enemy, SpellAction spell_action = SpellAction::attack, int level = 2);
};

BOOST_CLASS_VERSION(Item, serialization_versions::hero)

export std::ostream& operator<<(std::ostream& os, const Hero& hero)
{
    os << hero.name() << " is a " << hero.class_name() << " "
        << hero.race() << " of level " << hero.level() 
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

