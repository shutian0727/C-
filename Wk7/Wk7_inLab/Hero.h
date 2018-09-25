#define _CRT_SECURE_WARNINGS
#ifndef HERO_H
#define HERO_H
#include<iostream>

namespace sict {

	const int max_round = 100;
	const int max_name = 40;
	class Hero {
		char Hname[41];
		int healthNum;
		int Hattack;


	public:
		void operator-=(int attack);
		bool isAlive() const;
		int AttackStrength() const;
		int getHealth() const;
		void setHealthNum(int health_num);
		// two constructors
		Hero();
		Hero(const char* name, int maximumHealth, int attack);
		~Hero();
		// friend helper function to insert name into ostream
		friend std::ostream& operator<<(std::ostream& ostr, const Hero& h);
	};
	//helper functions
	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif

