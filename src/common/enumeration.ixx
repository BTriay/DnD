export module enumeration;

import <array>;

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
	six = 4, eight = 5, ten = 6, twelve = 7
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