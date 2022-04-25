export module enumeration;

export enum class Ability
{	
	strength, dexterity, constitution, intelligence, wisdom, charisma 
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