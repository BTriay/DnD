export module enumeration;

export enum class Ability
{	
	strength, dexterity, constitution, intelligence, wisdom, charisma 
};

export template <typename T>
concept is_ability = requires (T t)
{
	t == Ability::strength ||
		t == Ability::dexterity ||
		t == Ability::constitution ||
		t == Ability::intelligence ||
		t == Ability::wisdom ||
		t == Ability::charisma;
};

export enum class Damage
{
	acid, bludgeoning, cold, fire, force, lighting, necrotic,
	piercing, poison, psychic, radiant, slashing, thunder
};