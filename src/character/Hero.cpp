module Hero;

Hero::Hero(Hero&& rhs)
{
    m_hero_name = rhs.m_hero_name;
    m_class_name = rhs.m_class_name;
    m_race_creature = rhs.m_race_creature;
    rhs.m_race_creature = nullptr;
    m_class = rhs.m_class;
    rhs.m_class = nullptr;
}

Hero::~Hero()
{
	if (m_race_creature) delete m_race_creature;
	if (m_class) delete m_class;
}


void Hero::set_race_creature(HeroicCreature* race_creature)
{
    m_race_creature = race_creature;
}

void Hero::set_class(IClass* cclass)
{
    m_class = cclass;
}

void Hero::set_ability_score(Ability ability, int score)
{
    m_race_creature->set_ability_score(ability, score);
}

const std::string Hero::name() const
{ 
    return m_hero_name;
}

const std::string Hero::class_name() const
{
    return "some class \\o/";
}

const std::string Hero::race_name() const
{
    return m_race_creature->race();
}


int Hero::ability_modifier(Ability ability) const
{
    return (m_race_creature->ability_score_increase(ability)
        + m_race_creature->ability_score(ability)
        - 10) / 2;
}

void Hero::restore_current_hp_to_max()
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

    m_race_creature->set_hit_points_max(m_race_creature->hit_points_max()
        + extra_hp);
}