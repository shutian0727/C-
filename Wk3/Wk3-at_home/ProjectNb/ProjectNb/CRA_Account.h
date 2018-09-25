/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
//
// Name : Shutian Xu
// Date: 02/05/2018
//
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	class CRA_Account {

		char family_Name[max_name_length];
		char given_Name[max_name_length];
		int sin_No = 0;
		int m_year[max_yrs];
		double m_balance[max_yrs];
		int m_years;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty()const;
		void display() const;
	};
}

#endif

