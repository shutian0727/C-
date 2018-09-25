#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring> 

#include "CRA_Account.h"

using namespace std;



namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin > min_sin && sin < max_sin) {
			strncpy(family_Name, familyName, max_name_length + 1);
			strncpy(given_Name, givenName, max_name_length + 1);
			sin_No = sin;
		}

		else {


			sin_No = 0;

		}

	}



	bool CRA_Account::isEmpty() const {

		return sin_No == 0;

	}



	void CRA_Account::display() const {

		if (CRA_Account::isEmpty())

			cout << "Account object is empty!" << endl;

		else {

			cout << "Family Name: " << family_Name << endl;

			cout << "Given Name : " << given_Name << endl;

			cout << "CRA Account: " << sin_No << endl;

		}

	}

}