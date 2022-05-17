module Weapon;


Weapon& Weapon::operator=(const Weapon& rhs)
{
	m_weapon_proficiency = rhs.m_weapon_proficiency;
	m_weapon_reach = rhs.m_weapon_reach;
	m_damage = rhs.m_damage;
	m_die = rhs.m_die;
	m_weapon_property = rhs.m_weapon_property;

	return *this;
}

void Weapon::add_property(WeaponProperty weapon_property)
{
	m_weapon_property.insert(weapon_property);
}

Weapon weapon_creator(WeaponType model)
{
	switch (model)
	{
	case WeaponType::none:
		return Weapon();

	case WeaponType::club:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::four, 0), WeaponProperty::light);

	case WeaponType::dagger:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::four, 0) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}		

	case WeaponType::great_club:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::eight, 0), WeaponProperty::two_handed);

	case WeaponType::handaxe:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::javelin:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::six, 0), WeaponProperty::thrown);

	case WeaponType::light_hammer:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::four, 0) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::mace:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::six, 0));

	case WeaponType::quarterstaff: // missing versatile property
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::six, 0));

	case WeaponType::sickle:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::four, 0), WeaponProperty::light);

	case WeaponType::spear: // missing versatile property
		return Weapon(model, WeaponProficiency::simple, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::six, 0), WeaponProperty::thrown);
	

	case WeaponType::light_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::eight, 0) };
		weapon.add_property(WeaponProperty::loading);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::dart:
	{
		Weapon weapon{ model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::four, 0) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::thrown);
		return weapon;
	}

	case WeaponType::shortbow:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::six, 0), WeaponProperty::two_handed);

	case WeaponType::sling:
		return Weapon(model, WeaponProficiency::simple, WeaponReach::ranged,
			Damage::bludgeoning, Die::Die(1, DieFaces::four, 0));


	case WeaponType::battleaxe: // missing versatile property
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::flail:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::glaive:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::ten, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::greataxe:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::twelve, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::greatsword:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(2, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::halberd:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::ten, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::lance:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::twelve, 0), WeaponProperty::reach);

	case WeaponType::longsword: // missing versatile property
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::maul:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(2, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}	

	case WeaponType::morningstar:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::pike:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::ten, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::reach);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::rapier:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::eight, 0), WeaponProperty::finesse);

	case WeaponType::scimitar:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		return weapon;
	}

	case WeaponType::shortsword:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::light);
		return weapon;
	}

	case WeaponType::trident: // missing versatile property
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::six, 0), WeaponProperty::thrown);

	case WeaponType::war_pick:
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::piercing, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::warhammer: // missing versatile property
		return Weapon(model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::bludgeoning, Die::Die(1, DieFaces::eight, 0));

	case WeaponType::whip:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::melee,
			Damage::slashing, Die::Die(1, DieFaces::four, 0) };
		weapon.add_property(WeaponProperty::finesse);
		weapon.add_property(WeaponProperty::reach);
		return weapon;
	}


	case WeaponType::blowgun:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(0, DieFaces::four, 1) };
		weapon.add_property(WeaponProperty::loading);
		return weapon;
	}

	case WeaponType::hand_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::six, 0) };
		weapon.add_property(WeaponProperty::light);
		weapon.add_property(WeaponProperty::loading);
		return weapon;
	}

	case WeaponType::heavy_crossbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::ten, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::loading);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	case WeaponType::longbow:
	{
		Weapon weapon{ model, WeaponProficiency::martial, WeaponReach::ranged,
			Damage::piercing, Die::Die(1, DieFaces::eight, 0) };
		weapon.add_property(WeaponProperty::heavy);
		weapon.add_property(WeaponProperty::two_handed);
		return weapon;
	}

	default:
		throw std::invalid_argument("Unknown type");
		break;
	}
}