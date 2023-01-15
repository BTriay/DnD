module Hero;

Hero::Hero(Hero&& rhs)
{
    HeroicCreature::operator=(std::move(rhs));
    m_hero_name = rhs.m_hero_name;
    m_class_name = rhs.m_class_name;
    m_class = rhs.m_class;
    rhs.m_class = nullptr;
}

Hero::~Hero()
{
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

/*! Restore the hit points to their max,
including the constitution modifier and HillDwarf bonus */
void Hero::restore_current_hp_to_max()
{
    // bonus specific to HillDwarf: double constitution point per level
    auto hilldwarf_additional_hp =
        race().compare("HillDwarf") ? 0 : 1;

    set_current_hp(        
        hit_points_without_constit()
        + (hilldwarf_additional_hp
        + ability_modifier(Ability::constitution)) * m_class->level()    
        // /* TODO */ + bonuses from the items
    );

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

    set_hit_points_without_constit(hit_points_without_constit() + extra_hp);

    return extra_hp;
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
        attack_roll_vs_armor_class(
            sc->spellcasting_ability(),
            throw_advantage,
            m_class->proficiency_bonus(),
            enemy.armor_class());

    // damage roll
    if (attack_result != AttackResult::miss)
    {
        auto [damage, damage_type] = sc->fire_bolt_damage(level(),
            attack_result == AttackResult::critical_hit);

        std::cout << "damage inflicted by fire bolt: " << damage << '\n';

        enemy.lose_hit_points(damage, damage_type);
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
