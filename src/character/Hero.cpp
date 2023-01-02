module Hero;

Hero::Hero(Hero&& rhs)
{
    m_hero_name = rhs.m_hero_name;
    m_class_name = rhs.m_class_name;
    m_heroic_creature = rhs.m_heroic_creature;
    rhs.m_heroic_creature = nullptr;
    m_class = rhs.m_class;
    rhs.m_class = nullptr;
}

Hero::~Hero()
{
	if (m_heroic_creature) delete m_heroic_creature;
	if (m_class) delete m_class;
}

void Hero::set_ability_score(Ability ability, int score)
{
    m_heroic_creature->set_ability_score(ability, score);
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

void Hero::restore_current_hp_to_max()
{
    // bonus specific to HillDwarf: double constitution point per level
    auto hilldwarf_additional_hp =
        m_heroic_creature->race().compare("HillDwarf") ? 0 : 1;

    m_heroic_creature->set_current_hp(m_heroic_creature->hit_points_max()
        + m_class->level() * (hilldwarf_additional_hp
        + ability_modifier(Ability::constitution)));

}

/*! Get the current hit points of the hero */
int Hero::current_hit_points() const
{
    return m_heroic_creature->current_hit_points();
}

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

    auto extra_hp = add_default_hp ?
        (static_cast<int>(m_class->hit_dice()) + 2) / 2 :
        Die::gen(1, m_class->hit_dice());

    m_heroic_creature->set_hit_points_max(m_heroic_creature->hit_points_max()
        + extra_hp);

    return extra_hp;
}

void Hero::don_armor(Armor& armor)
{
    m_heroic_creature->don_armor(armor);
}

void Hero::don_armor(ArmorType armor_type)
{
    m_heroic_creature->don_armor(armor_type);
}