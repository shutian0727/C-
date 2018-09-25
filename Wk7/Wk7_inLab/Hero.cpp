#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Hero.h"
using namespace std;

namespace sict {

	Hero::Hero() {
		
		Hname[0] = '\0';
		healthNum = 0;
		Hattack = 0;

	}
	Hero::~Hero() {
	
	}
	Hero::Hero(const char* name, int maximumHealth, int attack) {

		strcpy(Hname, name);
		healthNum = maximumHealth;
		Hattack = attack;
	}
	int Hero::getHealth() const
	{
		return healthNum;
	}

	void Hero::setHealthNum(int health_num) {
		healthNum = health_num;
	}

	const Hero & operator*(const Hero & first, const Hero & second)
	{

		// Display the names of the people fighting

		cout << "AncientBattle! " << first << " vs " << second << " : ";

		Hero A = first;
		Hero B = second;
		const Hero *winner = nullptr;

		// Now A will fight B, and winner will point to the winner.
		// Main fight loop
		unsigned int rounds = 0;
		// loop while both are still alive
		// fight for 100 rounds
		while (A.isAlive() && B.isAlive() && rounds < 100)
		{
			rounds++;

			A.setHealthNum(A.getHealth() - B.AttackStrength());
			B.setHealthNum(B.getHealth() - A.AttackStrength());
		}

		// if we got here, then one Hero is dead, or if both are alive then it was a draw.
		bool draw;

		if (A.isAlive() && B.isAlive()) {
			draw = true;
		}
		else
		{
			draw = false;
		}

		// if it was a draw, then we decide by tossing an unfair coin and always
		// declare that A was the winner.
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

		// print out the winner
		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		// return a reference to the winner
		return *winner;

	}

	std::ostream& operator<<(std::ostream& ostr, const Hero& h)
	{
		if (strcmp(h.Hname, "") != 0)
			ostr << h.Hname;
		else
			ostr << "No hero";
		return ostr;
	}
	void Hero::operator -= (int attack) {

		if (attack > 0)
			healthNum -= attack;
	}
	bool Hero::isAlive() const
	{
		return healthNum > 0;
	}
	int Hero::AttackStrength() const
	{
		if (Hattack == 0) {
			return 0;
		}
		else
		{
			return Hattack;
		}
	}


}