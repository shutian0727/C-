/*
Name: Minghan Xu
Student number: 126725175
Email: mxu57@myseneca.ca
Workshop: 03
Section: OOP224SEF
Date: 2018-02-05
*/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	// The maximum number of characters for any name of the account holder 
	const int max_name_length = 40;
	// The smallest social insurance number that is acceptable
	const int min_sin = 100000000;
	// The smallest social insurance number that is acceptable
	const int max_sin = 999999999;
	// This value represents the maximum number of tax years that a CRA_Account object can remember
	const int max_yrs = 4;

	class CRA_Account {

		char family_name[max_name_length + 1];
		char given_name[max_name_length + 1];
		int sin_number;
		int taxes[max_yrs];
		double balance[max_yrs];
		int year;

	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
}
#endif