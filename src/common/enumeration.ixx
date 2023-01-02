export module enumeration;

import <array>;

export namespace serialization_versions
{
	const auto die = 1;
	const auto item = 1;
	const auto weapon = 1;
	const auto armor = 1;
	const auto icreature = 1;
	const auto iclass = 1;
	const auto heroic_creature = 1;
	const auto hero = 1;
}

export enum class Ability
{	
	charisma, constitution, dexterity, intelligence, strength, wisdom
};

export constexpr std::array<Ability, 6> abilities =
{
	Ability::charisma, Ability::constitution,
	Ability::dexterity,	Ability::intelligence,
	Ability::strength, Ability::wisdom
};

export struct AbilityScore
{
	bool check_scores()
	{
		auto res = (charisma >= 8 && charisma <= 15)
			&& (constitution >= 8 && constitution <= 15)
			&& (dexterity >= 8 && dexterity <= 15)
			&& (intelligence >= 8 && intelligence <= 15)
			&& (strength >= 8 && strength <= 15)
			&& (wisdom >= 8 && wisdom <= 15);

		auto total_cost = score_to_point(charisma)+ score_to_point(constitution)
			+ score_to_point(dexterity)+ score_to_point(intelligence)
			+ score_to_point(strength)+ score_to_point(wisdom);

		return res && (total_cost == 27);
	}

	int score_to_point(int score)
	{
		if (score == 15)
			return 9;
		if (score == 14)
			return 7;
		return score - 8;
	}

	int charisma;
	int constitution;
	int dexterity;
	int intelligence;
	int strength;
	int wisdom ;
};

export enum class Damage
{
	acid, bludgeoning, cold, fire, force, lighting, necrotic,
	piercing, poison, psychic, radiant, slashing, thunder
};

export enum class Size
{
	tiny, small, medium, large, huge, gargantuan
};

export enum class Skill
{
	athletics, // strength
	acrobatics, sleight_of_hand, stealth, // dexterity
	arcana, history, investigation, nature, religtion, // intelligence
	animal_handling, insight, medicine, perception, survival, // wisdom
	deception, intimidation, performance, persuasion // charisma
};

export enum class ToolProficiency
{
	artisan, disguise  /* etc */
};

export enum class HitDice
{
	four = 4, six = 6, eight = 8, ten = 10, 
	twelve = 12, twenty = 20, hundred = 100
};

export enum class ArmorProtection
{
	none, light, medium, heavy
};

export enum class ArmorType
{
	none,
	padded, leather, studded_leather,
	hide, chain_shirt, scale_mail, breastplate, half_plate,
	ring_mail, chain_mail, splint, plate
};

export enum class WeaponProficiency
{
	simple, martial
};

export enum class WeaponReach
{
	melee, ranged
};

export enum class WeaponProperty
{
	none, finesse, heavy, light, loading, range,
	reach, thrown, two_handed, versatile
};

export enum class WeaponType
{
	none,
	club, dagger, great_club, handaxe, javelin, light_hammer, 
	mace, quarterstaff, sickle, spear,
	light_crossbow, dart, shortbow, sling,
	battleaxe, flail, glaive, greataxe, greatsword, halberd,
	lance, longsword, maul, morningstar, pike, rapier, scimitar,
	shortsword, trident, war_pick, warhammer, whip,
	blowgun, hand_crossbow, heavy_crossbow, longbow
};

export enum class Race
{
	HillDwarf, MountainDwarf,
	Dragonborn,
	HighElf, WoodElf, DarkElf,
	ForestGnome, RockGnome,
	HalfElf,
	Lightfoot, Stout,
	HalfOrc,
	Human,
	Tiefling
};