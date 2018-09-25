#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int m_superPowerAttackBonus; // superpower:  attack bonus
		int m_superPowerDefendBonus; // superpower: defend strength
		int damage_A;
		int damage_B;

	public:
		// constructors  
		SuperHero();
		SuperHero(const char* name,
			int maximumHealth,
			int attack,
			int superPowerAttackBonus,
			int superPowerDefend);
		int attackStrength() const;
		int defend() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
	

	}
#endif // !SUPERHERO_H

