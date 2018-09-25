  
#include <iostream>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"



using namespace std;

namespace sict
{

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		bool valid = false;
		int total = 0,testsin=sin;
		short digits[9];
		if (testsin >= min_sin && testsin <= max_sin) {
			for (int i = 1; i < 9; ++i) {
				digits[i] = testsin % 10;
				testsin /= 10;
			}
			for (int i = 1; i < 9; ++i) {
				if (i % 2 != 0) {
					digits[i] *= 2;
					total += digits[i] / 10 + digits[i] % 10;
				}
				else
					total += digits[i];			 
			}
			
			valid = (total + digits[0]) % 10 == 0;
			
		}

		if (valid && familyName[0] != '\0'&& givenName[0] != '\0') {
			strncpy(m_fName, familyName, max_name_length);
			m_fName[max_name_length] = '\0';
			strncpy(m_gName, givenName, max_name_length);
			m_gName[max_name_length] = '\0';
			m_sin = sin;
			m_noYear = 0;
		}
		else {
			m_sin = 0;
			m_fName[0] = '\0';
			m_fName[0] = '\0';
			m_noYear = 0;
		}
	}

	//function to set the year and balance
	void CRA_Account::set(int year, double balance)
	{
		if ( m_noYear < max_yrs) {
			m_years[m_noYear] = year;
			m_balances[m_noYear] = balance;
			m_noYear++;
		}
	}



	bool CRA_Account::isEmpty() const
	{
		return m_sin == 0;
	}

	void CRA_Account::display() const
	{
		if (isEmpty() == false) {
			cout << "Family Name: " << m_fName << endl;
			cout << "Given Name : " << m_gName << endl;
			cout << "CRA Account: " << m_sin << endl;

			cout.setf(ios::fixed);
			cout.precision(2);

			for (int i = 0; i < m_noYear; i++) {
				cout << "Year (" << m_years[i];

				if (m_balances[i] > 2.0)
					cout << ") balance owing: " << m_balances[i] << endl;
				else if (m_balances[i] < -2.0)
					cout << ") refund due: " << fabs(m_balances[i]) << endl;
				else
					cout << ") No balance owing or refund due!" << endl;
			}

		}
		else
			cout << "Account object is empty!" << endl;

	}

}