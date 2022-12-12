module HeroicCreature;

HeroicCreature::HeroicCreature(Race race) : m_race(race)
{
	// main races
	switch (race)
	{
	case (Race::HillDwarf):
	case (Race::MountainDwarf):
		HeroicCreature(1, 60, Size::medium, 25);
		set_ability_score_increase(Ability::constitution, 2);
		add_resistance(Damage::poison);
		break;

	case (Race::Dragonborn):
		HeroicCreature(1, 0, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::strength, 2);

	case (Race::HighElf):
	case (Race::WoodElf):
	case (Race::DarkElf):
		HeroicCreature(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::dexterity, 2);
		break;

	case (Race::ForestGnome):
	case (Race::RockGnome):
		HeroicCreature(1, 60, Size::small, 25);
		set_ability_score_increase(Ability::intelligence, 2);
		break;

	case (Race::HalfElf):
		HeroicCreature(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 2);
		// + 2 abilities chosen by the player (+1 each)
		break;

	case (Race::Lightfoot):
	case (Race::Stout):
		HeroicCreature(1, 0, Size::small, 25);
		set_ability_score_increase(Ability::dexterity, 2);
		break;

	case (Race::HalfOrc):
		HeroicCreature(1, 60, Size::medium, 30);
		set_ability_score_increase(Ability::constitution, 1);
		set_ability_score_increase(Ability::strength, 2);
		break;

	case (Race::Human):
		HeroicCreature(1, 0, Size::medium, 30);
		set_ability_score_increase(Ability::charisma, 1);
		set_ability_score_increase(Ability::constitution, 1);
		set_ability_score_increase(Ability::dexterity, 1);
		set_ability_score_increase(Ability::intelligence, 1);
		set_ability_score_increase(Ability::strength, 1);
		set_ability_score_increase(Ability::wisdom, 1);
		break;

	case (Race::Tiefling):
		HeroicCreature(1, 60, Size::medium, 30);
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