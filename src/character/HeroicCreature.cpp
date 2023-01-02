module HeroicCreature;

/* PUBLIC MEMBER FUNCTIONS */

HeroicCreature::HeroicCreature(Race race, AbilityScore ability_scores) : m_race(race)
{
	set_ability_score(Ability::charisma, ability_scores.charisma);
	set_ability_score(Ability::constitution, ability_scores.constitution);
	set_ability_score(Ability::dexterity, ability_scores.dexterity);
	set_ability_score(Ability::intelligence, ability_scores.intelligence);
	set_ability_score(Ability::strength, ability_scores.strength);
	set_ability_score(Ability::wisdom, ability_scores.wisdom);

	// main races
	switch (race)
	{
	case (Race::HillDwarf):
	case (Race::MountainDwarf):
		init(1, 60, Size::medium, 25);
		set_ability_score_increase(Ability::constitution, 2);
		add_resistance(Damage::poison);
		break;

	case (Race::Dragonborn):
		init(1, 0, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::strength, 2);
		break;

	case (Race::HighElf):
	case (Race::WoodElf):
	case (Race::DarkElf):
		init(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::dexterity, 2);
		break;

	case (Race::ForestGnome):
	case (Race::RockGnome):
		init(1, 60, Size::small, 25);
		set_ability_score_increase(Ability::intelligence, 2);
		break;

	case (Race::HalfElf):
		init(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 2);
		// + 2 abilities chosen by the player (+1 each)
		break;

	case (Race::Lightfoot):
	case (Race::Stout):
		init(1, 0, Size::small, 25);
		set_ability_score_increase(Ability::dexterity, 2);
		break;

	case (Race::HalfOrc):
		init(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::constitution, 1);
		set_ability_score_increase(Ability::strength, 2);
		break;

	case (Race::Human):
		init(1, 0, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::constitution, 1);
		set_ability_score_increase(Ability::dexterity, 1);
		set_ability_score_increase(Ability::intelligence, 1);
		set_ability_score_increase(Ability::strength, 1);
		set_ability_score_increase(Ability::wisdom, 1);
		break;

	case (Race::Tiefling):
		init(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 2);
		set_ability_score_increase(Ability::intelligence, 1);
		break;
	}

	// sub-races specifics
	switch (race)
	{
	case (Race::HillDwarf):
		set_ability_score_increase(Ability::wisdom, 1);
		break;

	case (Race::MountainDwarf):
		set_ability_score_increase(Ability::strength, 2);
		break;

	case (Race::HighElf):
		set_ability_score_increase(Ability::intelligence, 1);
		break;

	case (Race::WoodElf):
		set_ability_score_increase(Ability::wisdom, 1);
		break;

	case (Race::DarkElf):
		set_ability_score_increase(Ability::charisma, 1);
		break;

	case (Race::ForestGnome):
		set_ability_score_increase(Ability::dexterity, 1);
		break;

	case (Race::RockGnome):
		set_ability_score_increase(Ability::constitution, 1);
		break;

	case (Race::Lightfoot):
		set_ability_score_increase(Ability::charisma, 2);
		break;

	case (Race::Stout):
		set_ability_score_increase(Ability::constitution, 2);
		break;
	}

}

const std::string HeroicCreature::race() const
{
	switch (m_race)
	{
	case (Race::HillDwarf):
		return "HillDwarf";
	case (Race::MountainDwarf):
		return "MountainDwarf";
	case (Race::Dragonborn):
		return "Dragonborn";
	case (Race::HighElf):
		return "HighElf";
	case (Race::WoodElf):
		return "WoodElf";
	case (Race::DarkElf):
		return "DarkElf";
	case (Race::ForestGnome):
		return "ForestGnome";
	case (Race::RockGnome):
		return "RockGnome";
	case (Race::HalfElf):
		return "HalfElf";
	case (Race::Lightfoot):
		return "Lightfoot";
	case (Race::Stout):
		return "Stout";
	case (Race::HalfOrc):
		return "HalfOrc";
	case (Race::Human):
		return "Human";
	case (Race::Tiefling):
		return "Tiefling";
	default:
		return "problem, unknown race";
	}
}

/* END OF PUBLIC MEMBER FUNCTIONS */


/* PRIVATE MEMBER FUNCTIONS */

void HeroicCreature::init(int hit_points_max, int darkvision, Size size,
	int speed_land, int speed_climb, int speed_air, int speed_water)
{
	set_hit_points_max(hit_points_max);
	set_darkvision(darkvision);
	
	set_size(size);
	set_speed_land(speed_land);
	set_speed_climb(speed_climb);
	set_speed_air(speed_air);
	set_speed_water(speed_water);

	restore_current_hp_to_max();
}


/* END OF PRIVATE MEMBER FUNCTIONS */
