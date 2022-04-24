module;

#include <stdint.h>

export module Weapon;

import <string>;
import Item;

export enum class Proficiency { Simple, Martial };
export enum class Reach { Melee, Ranged };
export enum class Property { Finesse, Heavy, Light, Loading, Range,
	Reach, Thrown, TwoHanded, Versatile};


export class Weapon : public Item
{
public:



private:
	Proficiency m_proficiency;
	Reach m_reach;
	Property m_property;
};