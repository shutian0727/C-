

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict 
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char m_fName[max_name_length + 1];
		char m_gName[max_name_length + 1];
		int m_sin;
		int m_years[max_yrs];
		double m_balances[max_yrs];
		int m_noYear;
		

	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;	
		void display() const;
	};

}



#endif // !SICT_CRA_ACCOUNT_H

