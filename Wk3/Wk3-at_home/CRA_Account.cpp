/*
Name: Minghan Xu
Student number: 126725175
Email: mxu57@myseneca.ca
Workshop: 03
Section: OOP224SEF
Date: 2018-02-05
*/
#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include "CRA_Account.h"
using namespace std;
using namespace sict;
void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	if (sin < min_sin || sin > max_sin || strlen(familyName) == 0 || strlen(givenName) == 0) {
		CRA_Account::sin_number = 0;
		return;
	}
	else {
		int sin_num[10];
		int sin_temp = sin;
		int sum = 0;
		for (int i = 9; i > 0; i--) {
			sin_num[i] = sin_temp % 10;
			sin_temp = sin_temp / 10;
		}
		for (int i = 1; i < 10; i++) {
			if (i % 2 == 0) {
				if (sin_num[i] > 5) {
					sum += sin_num[i] * 2 % 10 + 1;
				}
				else {
					sum += sin_num[i] * 2;
				}
			}
			else {
				sum += sin_num[i];
			}
		}
		if (sum % 10 != 0) {
			CRA_Account::sin_number = 0;
			return;
		}
		strcpy(CRA_Account::family_name, familyName);
		strcpy(CRA_Account::given_name, givenName);
		CRA_Account::year = 0;
		CRA_Account::sin_number = sin;
		return;
	}
}
void sict::CRA_Account::set(int year, double balance) {
	CRA_Account::taxes[CRA_Account::year] = year;
	CRA_Account::balance[CRA_Account::year] = balance;
	CRA_Account::year++;
}
bool CRA_Account::isEmpty() const {
	if (CRA_Account::sin_number == 0) {
		return true;
	}
	else {
		return false;
	}
}
void CRA_Account::display() const{
	cout << "Family Name: " << CRA_Account::family_name << endl;
	cout << "Given Name : " << CRA_Account::given_name << endl;
	cout << "CRA Account: " << CRA_Account::sin_number << endl;
	for (int i = 0; i < CRA_Account::year; i++) {
		if (fabs(CRA_Account::balance[i]) > 2) {
			if (CRA_Account::balance[i] > 0) {
				cout << "Year (" << CRA_Account::taxes[i] << ") balance owing: " << fixed << setprecision(2) << fabs(CRA_Account::balance[i]) << endl;
			}
			else {
				cout << "Year (" << CRA_Account::taxes[i] << ") refund due: " << fixed << setprecision(2) << fabs(CRA_Account::balance[i]) << endl;
			}
		}
		else {
			cout << "Year (" << CRA_Account::taxes[i] << ") No balance owing or refund due!" << endl;
		}
	}
}
