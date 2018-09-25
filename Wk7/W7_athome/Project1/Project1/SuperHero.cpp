#include <iostream>
#include "SuperHero.h"
using namespace std;

namespace sict {

	// Default constructor
	//
	SuperHero::SuperHero() : Hero()
	{
		m_superPowerAttackBonus = 0;
		m_superPowerDefendBonus = 0;
	}

	// Constructor
	SuperHero::SuperHero(const char* name,
		int maximumHealth,
		int attack,
		int superPowerAttackBonus,
		int superPowerDefend) : Hero(name, maximumHealth, attack)
	{
		m_superPowerAttackBonus = superPowerAttackBonus;
		m_superPowerDefendBonus = superPowerDefend;

	}
	int SuperHero::attackStrength() const {

		return Hero::AttackStrength() + m_superPowerAttackBonus;
	}

	int SuperHero::defend() const {
		return m_superPowerDefendBonus;

	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{

		
		cout << "SuperFight! " << first << " vs " << second << " : ";

	
		// a and b are unmodified, so we make a local copy of the objects

		SuperHero A = first;
		SuperHero B = second;
		const SuperHero *winner = nullptr;

		unsigned int rounds = 0;
		// loop while both are still alive
		while (A.isAlive() && B.isAlive() && rounds< 100)
		{
			rounds++;
			int damage_A = B.attackStrength() - A.defend();
			int damage_B = A.attackStrength() - B.defend();

			if (damage_A < 1)
			{
				damage_A = 1;
			}
			if (damage_B < 1)
			{
				damage_B = 1;
			}
			A.operator -= (damage_A);
			B.operator -= (damage_B);
		}

		// if we got here, then one Hero is dead, or it was a draw.
		bool draw = A.isAlive() && B.isAlive();

		// if it was a draw, then we always declare that First won.
		
		if (draw)
		{
			winner = &first;
		}
		else if (A.isAlive())
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}

		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;






	}



}











