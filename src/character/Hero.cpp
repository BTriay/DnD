module Hero;

Hero::Hero(Hero&& rhs)
{
    m_hero_name = rhs.m_hero_name;
    m_class_name = rhs.m_class_name;
    m_heroic_creature = rhs.m_heroic_creature;
    rhs.m_heroic_creature = nullptr;
    m_class = rhs.m_class;
    rhs.m_class = nullptr;
    m_hit_points_current = rhs.m_hit_points_current;
}

Hero::~Hero()
{
	if (m_heroic_creature) delete m_heroic_creature;
	if (m_class) delete m_class;
}

/*! Get the name of the hero */
const std::string Hero::name() const
{ 
    return m_hero_name;
}

/*! Get the class of the hero */
const std::string Hero::class_name() const
{
    return m_class_name;
}

/*! Get the race of the hero */
const std::string Hero::race_name() const
{
    return m_heroic_creature->race();
}

/*! Get the ability modifier of the hero */
int Hero::ability_modifier(Ability ability) const
{
    return m_heroic_creature->ability_modifier(ability);
}

/*! Restore the hit points to their max,
including the constitution modifier and HillDwarf bonus */
void Hero::restore_current_hp_to_max()
{
    // bonus specific to HillDwarf: double constitution point per level
    auto hilldwarf_additional_hp =
        m_heroic_creature->race().compare("HillDwarf") ? 0 : 1;

    set_current_hp(        
        m_heroic_creature->hit_points_without_constit()
        + (hilldwarf_additional_hp
        + ability_modifier(Ability::constitution)) * m_class->level()    
        // /* TODO */ + bonuses from the items
    );

}

/*! Set the current hit points */
void Hero::set_current_hp(int hp)
{
    m_hit_points_current = hp;
}

/*! Get the current hit points of the hero */
int Hero::current_hit_points() const
{
    return m_hit_points_current;
}

/*! Lose hit points */
void Hero::lose_hit_points(int hit_points)
{
    m_hit_points_current -= hit_points;
}

/*! The hero's hit dice */
HitDice Hero::hit_dice() const
{
    return m_class->hit_dice(); 
}

/*! Give a skill to the hero */
void Hero::add_skill(Skill skill)
{
    m_class->add_skill(skill);
}

/*! Get the hero's level */
int Hero::level() const
{
    return m_class->level();
}

/*! Gain a level, and return the extra hp gained */
int Hero::gain_level(bool add_default_hp)
{
    m_class->gain_level();

    if (auto sc = dynamic_cast<Spellcaster*>(m_class))
        sc->reset_spell_slots(m_class->level());

    auto extra_hp = add_default_hp ?
        hit_dice_average(m_class->hit_dice()) :
        Die::roll_normal(1, m_class->hit_dice());

    m_heroic_creature->set_hit_points_without_constit(
        m_heroic_creature->hit_points_without_constit() + extra_hp);

    return extra_hp;
}

/*! Don an armor */
void Hero::don_armor(Armor& armor)
{
    m_heroic_creature->don_armor(armor);
}

/*! Don a regular armor of a given type */
void Hero::don_armor(ArmorType armor_type)
{
    m_heroic_creature->don_armor(armor_type);
}

/*! Drop off the armor */
void Hero::doff_armor()
{
    m_heroic_creature->doff_armor();
}

std::array<int, 10> Hero::available_spell_slots() const
{
    if (auto sc = dynamic_cast<Spellcaster*>(m_class))
        return sc->available_spell_slots();
    return {};
}

/*! Invoke a spell, given its name */
void Hero::invoke_spell([[maybe_unused]] const std::string& spell,
    [[maybe_unused]] ICreature& enemy,
    [[maybe_unused]] DieThrowAdvantage throw_advantage,
    [[maybe_unused]] int level)
{
    fire_bolt(enemy, throw_advantage);
}

/*! Fire bolt spell */
void Hero::fire_bolt(ICreature& enemy, DieThrowAdvantage throw_advantage)
{
    auto sc = dynamic_cast<Spellcaster*>(m_class);

    // attack roll
    auto attack_result =
        m_heroic_creature->attack_roll_vs_armor_class(
            sc->spellcasting_ability(),
            throw_advantage,
            m_class->proficiency_bonus(),
            enemy.armor_class());

    // damage roll
    if (attack_result != AttackResult::Miss)
    {
        auto [damage, damage_type] = sc->fire_bolt_damage(level(),
            attack_result == AttackResult::CriticalHit);

        std::cout << "damage inflicted by fire bolt: " << damage << '\n';

        enemy.lose_hit_points(damage);
    }
}

/*! Flame blade spell */
//void Hero::flame_blade(ICreature& enemy, SpellAction spell_action, int level)
//{
//    // attack roll
//
//
//    // damage roll
//    // auto [damage, damage_type] =
//
//}
