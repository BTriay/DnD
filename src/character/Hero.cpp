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

void Hero::set_race_creature(HeroicCreature* race_creature)
{
    m_heroic_creature = race_creature;
}

//void Hero::set_class(IClass* cclass)
//{
//    m_class = cclass;
//    restore_current_hp_to_max();
//}

void Hero::set_ability_score(Ability ability, int score)
{
    m_heroic_creature->set_ability_score(ability, score);
}

const std::string Hero::name() const
{ 
    return m_hero_name;
}

std::string Hero::class_name() const
{
    return m_class_name;
}

const std::string Hero::race_name() const
{
    return m_heroic_creature->race();
}

int Hero::ability_modifier(Ability ability) const
{
    return m_heroic_creature->ability_modifier(ability);
}

void Hero::restore_current_hp_to_max()
{
    auto hilldwarf_additional_hp =
        m_heroic_creature->race().compare("HillDwarf") ? 0 : 1;

    m_heroic_creature->set_current_hp(m_heroic_creature->hit_points_max()
        + m_class->level() * (hilldwarf_additional_hp
        + ability_modifier(Ability::constitution)));

}

int Hero::current_hit_points() const
{
    return m_heroic_creature->current_hit_points();
}

HitDice Hero::hit_dice() const
{
    return m_class->hit_dice(); 
}

void Hero::add_skill(Skill skill)
{
    m_class->add_skill(skill);
}

int Hero::level() const
{
    return m_class->level();
}

void Hero::gain_level(bool add_default_hp)
{
    m_class->gain_level();

    auto extra_hp = add_default_hp ?
        (static_cast<int>(m_class->hit_dice()) + 2) / 2 :
        Die::gen(1, m_class->hit_dice());

    m_heroic_creature->set_hit_points_max(m_heroic_creature->hit_points_max()
        + extra_hp);
}