export module Die;

import <random>;
import enumeration;

export class Die
{
public:
	Die(int number_dice, HitDice hit_dice, int bonus = 0):
		m_number_dice(number_dice), m_hit_dice(hit_dice), m_bonus(bonus) {}
	
	Die& operator=(const Die& rhs);

	int roll() const
	{
		return gen(m_number_dice, m_hit_dice, m_bonus);
	}
	
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

private:
	int m_number_dice;
	HitDice m_hit_dice;
	int m_bonus;
};