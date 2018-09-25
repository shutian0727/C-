#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{

		bool flag = false;
		bool rv;
		int digit[9];
		int temp1, temp2, sum1 = 0, sum2, sum3, diff;
		sin_No = sin;

		if (sin_No >= min_sin && sin_No <= max_sin) {
			// Convert the integer number to digits

			for (int i = 0; i < 9; i++) {
				digit[i] = sin_No % 10;
				sin_No = sin_No / 10;
			}

			// Determine the digits satisfy the rule
			for (int i = 1; i < 9; i += 2) {
				if (i % 2 != 0)
					temp1 = digit[i] * 2 % 10;
				temp2 = digit[i] * 2 / 10;
				sum1 = temp1 + temp2 + sum1;
			}

			sum2 = digit[0] + digit[2] + digit[4] + digit[6];
			sum3 = sum1 + sum2;

			if (sum3 % 10 == 0) {
				diff = 0;
			}
			else
			{
				diff = 10 - sum3 % 10;
			}

			if (diff == digit[8]) {
				rv = true;
			}
			else
			{
				rv = false;
			}

			if (rv == true && familyName[0] != '\0'&& givenName[0] != '\0') {

				strncpy(family_Name, familyName, max_name_length);
				family_Name[max_name_length] = '\0';
				strncpy(given_Name, givenName, max_name_length);
				given_Name[max_name_length] = '\0';
				m_years = 0;
				sin_No = sin;
			}

			else {

				strncpy(family_Name, "", max_name_length);
				strncpy(given_Name, "", max_name_length);
				sin_No = 0;

			}

		}
	}
	bool CRA_Account::isEmpty() const {
		
		if (sin_No == 0) {
			return true;
		}
		else{
		
			return false;
		}
	}
	void CRA_Account::display() const
	{


		if (!isEmpty()) {
			cout << "Family Name: " << family_Name << endl;
			cout << "Given Name : " << given_Name << endl;
			cout << "CRA Account: " << sin_No << endl;

			cout.setf(ios::fixed);
			cout.precision(2);

			for (int i = 0; i < m_years; i++) {
				if (m_balance[i] > 2)
					cout << "Year (" << m_year[i] << ") balance owing: " << m_balance[i] << endl;
				else if (m_balance[i] < -2)
					cout << "Year (" << m_year[i] << ") refund due: " << -m_balance[i] << endl;
				else
					cout << "Year (" << m_year[i] << ") No balance owing or refund due!" << endl;
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}


	

		void CRA_Account::set(int year, double balance) {
			
			if (m_years < max_yrs) {
				m_year[m_years] = year;
				m_balance[m_years] = balance;
				m_years++;
			}

		}

	}