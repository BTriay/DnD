module Druid;

/*! Reset the spell slots to their maximum given the level */
void Druid::reset_spell_slots(int level)
{
	switch (level)
	{
	case 1:
		set_spell_slots({ 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 }); return;
	case 2:
		set_spell_slots({ 2, 3, 0, 0, 0, 0, 0, 0, 0, 0 }); return;
	case 3:
		set_spell_slots({ 2, 4, 2, 0, 0, 0, 0, 0, 0, 0 }); return;
	case 4:
		set_spell_slots({ 3, 4, 3, 0, 0, 0, 0, 0, 0, 0 }); return;
	case 5:
		set_spell_slots({ 3, 4, 3, 2, 0, 0, 0, 0, 0, 0 }); return;
	case 6:
		set_spell_slots({ 3, 4, 3, 3, 0, 0, 0, 0, 0, 0 }); return;
	case 7:
		set_spell_slots({ 3, 4, 3, 3, 1, 0, 0, 0, 0, 0 }); return;
	case 8:
		set_spell_slots({ 3, 4, 3, 3, 2, 0, 0, 0, 0, 0 }); return;
	case 9:
		set_spell_slots({ 3, 4, 3, 3, 3, 1, 0, 0, 0, 0 }); return;
	case 10:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 0, 0, 0, 0 }); return;
	case 11:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 0, 0, 0 }); return;
	case 12:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 0, 0, 0 }); return;
	case 13:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 1, 0, 0 }); return;
	case 14:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 1, 0, 0 }); return;
	case 15:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 1, 1, 0 }); return;
	case 16:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 1, 1, 0 }); return;
	case 17:
		set_spell_slots({ 4, 4, 3, 3, 3, 2, 1, 1, 1, 1 }); return;
	case 18:
		set_spell_slots({ 4, 4, 3, 3, 3, 3, 1, 1, 1, 1 }); return;
	case 19:
		set_spell_slots({ 4, 4, 3, 3, 3, 3, 2, 1, 1, 1 }); return;
	case 20:
		set_spell_slots({ 4, 4, 3, 3, 3, 3, 2, 2, 1, 1 });
	}
}
