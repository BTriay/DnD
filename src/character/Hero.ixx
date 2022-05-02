export module Hero;

import IClass;
import IRace;

export template <typename C, typename R>
    requires std::is_base_of_v<IClass, C>&& std::is_base_of_v<IRace, R>
class Hero : public C, public R
{
public:
    Hero() : C(), R() {}

private:

};

// is this really the best way to do this?
import Cleric;
import Dwarf;

template class Hero<Cleric, HillDwarf>;
template class Hero<Cleric, MountainDwarf>;