module Weapon;

/*! Weapon's copy constructor */
Weapon& Weapon::operator=(const Weapon& rhs)
{
	m_weapon_proficiency = rhs.m_weapon_proficiency;
	m_weapon_reach = rhs.m_weapon_reach;
	m_damage = rhs.m_damage;
	m_die = rhs.m_die;
	m_weapon_property = rhs.m_weapon_property;

	return *this;
}

/*! Add a property to the weapon */
void Weapon::add_property(WeaponProperty weapon_property)
{
	m_weapon_property.insert(weapon_property);
}

/*! Add the die of the weapon in case of versatile use */
void Weapon::add_versatile_die(Die die)
{
	m_versatile_die = die;
}

/*! Melee or ranged weapon */
WeaponReach Weapon::weapon_reach() const
{
	return m_weapon_reach;
}

/*! Simple or martial */
WeaponProficiency Weapon::weapon_proficiency() const
{
	return m_weapon_proficiency;
}

/*! club, dagger, etc */
WeaponType Weapon::weapon_type() const
{
	return m_model;
}

/*! True if the weapon has the property */
bool Weapon::has_property(WeaponProperty weapon_property) const
{
	return m_weapon_property.find(weapon_property) != std::end(m_weapon_property);
}

/*! Damage roll of the weapon */
std::tuple<int, Damage> Weapon::damage_roll(bool critical_hit,
	bool use_as_versatile_weapon) const
{
	if (use_as_versatile_weapon)
		return std::tuple<int, Damage> { m_versatile_die.roll(critical_hit), m_damage };

	return std::tuple<int, Damage> { m_die.roll(critical_hit), m_damage } ;
}

/*! Create a non-magical weapon */
Weapon weapon_creator(WeaponType model)
{
	switch (model)
	{
	case WeaponType::none:
		return Weapon();

	case WeaponType::club:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::four), WeaponProperty::light);

	case WeaponType::dagger:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::four) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::great_club:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::eight), WeaponProperty::two_handed);

	case WeaponType::handaxe:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::six) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::javelin:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::six), WeaponProperty::thrown);

	case WeaponType::light_hammer:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::four) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::mace:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::six));

	case WeaponType::quarterstaff:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::six) };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::eight, 0));
		return weapon;
	}

	case WeaponType::sickle:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::four), WeaponProperty::light);

	case WeaponType::spear:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::six), WeaponProperty::thrown };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::eight, 0));
		return weapon;
	}

	case WeaponType::light_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::eight) };
		weapon.add_property(WeaponProperty::loading);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::dart:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::four) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::shortbow:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::six), WeaponProperty::two_handed);

	case WeaponType::sling:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::bludgeoning, Die::Die(1, HitDice::four));


	case WeaponType::battleaxe:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::eight) };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::ten, 0));
		return weapon;
	}

	case WeaponType::flail:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::eight));

	case WeaponType::glaive:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::ten) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::greataxe:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::twelve) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::greatsword:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(2, HitDice::six) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::halberd:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::ten) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::lance:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::twelve), WeaponProperty::reach);

	case WeaponType::longsword:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::eight) };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::ten, 0));
		return weapon;
	}

	case WeaponType::maul:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(2, HitDice::six) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::morningstar:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::eight));

	case WeaponType::pike:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::ten) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::rapier:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::eight), WeaponProperty::finesse);

	case WeaponType::scimitar:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::six) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		return weapon;
	}

	case WeaponType::shortsword:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::six) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		return weapon;
	}

	case WeaponType::trident:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::six), WeaponProperty::thrown };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::eight, 0));
		return weapon;
	}

	case WeaponType::war_pick:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, HitDice::eight));

	case WeaponType::warhammer:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, HitDice::eight) };
		weapon.add_property(WeaponProperty::versatile);
		weapon.add_versatile_die(Die::Die(1, HitDice::ten, 0));
		return weapon;
	}

	case WeaponType::whip:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, HitDice::four) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::reach);
		return weapon;
	}


	case WeaponType::blowgun:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(0, HitDice::four, 1) };
		weapon.add_property(WeaponProperty::loading);
		return weapon;
	}

	case WeaponType::hand_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::six) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::loading);
		return weapon;
	}

	case WeaponType::heavy_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::ten) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::loading);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::longbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, HitDice::eight) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	default:
		throw std::invalid_argument("Unknown type");
		break;
	}
}