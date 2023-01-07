module;

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/version.hpp>

export module Die;

import <random>;
import <algorithm>;
import enumeration;

export class Die
{
public:
	/*! Die constructor */
	Die(int number_dice, HitDice hit_dice, int bonus = 0):
		m_number_dice(number_dice), m_hit_dice(hit_dice), m_bonus(bonus) {}
		
	Die& operator=(const Die& rhs);
		
	int roll() const;
	
	/*! Roll a combination of dice */
	static int gen(int number_dice, HitDice hit_dice, const int bonus = 0)
	{
		std::random_device dev;
		std::mt19937 rng(dev());

		int upper_limit = static_cast<int>(hit_dice);

		auto sum = bonus;
		while (number_dice-- > 0)
		{
			std::uniform_int_distribution<std::mt19937::result_type> dist6(1, upper_limit);
			sum += dist6(rng);
		}
		return sum;
	}

	/*! Roll a combination of dice (normal / with _dis_advantage) */
	static int gen(int number_dice, HitDice hit_dice, const int bonus = 0,
		DieThrowAdvantage throw_advantage = DieThrowAdvantage::Normal)
	{
		auto res1 = gen(number_dice, hit_dice, bonus);
		if (throw_advantage == DieThrowAdvantage::Normal)
			return res1;

		auto res2 = gen(number_dice, hit_dice, bonus);

		if (throw_advantage == DieThrowAdvantage::Advantage)
			return std::max(res1, res2);

		return std::min(res1, res2);
	}

protected:
	Die() : Die(0, HitDice::six) {} // necessary for serialization

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
	{
		ar& BOOST_SERIALIZATION_NVP(m_number_dice);
		ar& BOOST_SERIALIZATION_NVP(m_hit_dice);
		ar& BOOST_SERIALIZATION_NVP(m_bonus);
	}

	int m_number_dice; /*!< Number of dice to roll */
	HitDice m_hit_dice; /*!< The type of dice to roll */
	int m_bonus; /*!< The bonus of the dice */
};

BOOST_CLASS_VERSION(Die, serialization_versions::die)
