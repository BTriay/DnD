export module Die;

import <random>;

export enum class DieFaces
{
	four, six, eight, ten, twelve, twenty, hundred
};

export class Die
{
public:
	static int gen(int number_dice, DieFaces df, const int bonus)
	{
		std::random_device dev;
		std::mt19937 rng(dev());

		int upper_limit {};
		switch (df)
		{
		case DieFaces::four:
			upper_limit = 4;
			break;
		case DieFaces::six:
			upper_limit = 6;
			break;
		case DieFaces::eight:
			upper_limit = 8;
			break;
		case DieFaces::ten:
			upper_limit = 10;
			break;
		case DieFaces::twelve:
			upper_limit = 12;
			break;
		case DieFaces::twenty:
			upper_limit = 20;
			break;
		}

		auto sum = bonus;
		while (number_dice-- > 0)
		{
			std::uniform_int_distribution<std::mt19937::result_type> dist6(1, upper_limit);
			sum += dist6(rng);
		}
		return sum;
	}

};