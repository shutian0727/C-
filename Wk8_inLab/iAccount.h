// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the iAccount interface
///////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {
		double amount;
		double balance_;
		const char* types_;
	public:
		// TODO: credit adds +ve amount to the balance
		virtual  bool credit(double credit_) = 0;

		// TODO: debit subtracts a +ve amount from the balance
		virtual  bool debit(double debit_) = 0;

		// TODO: month end adds month end costs
		virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
		virtual void display(std::ostream& ostr) const = 0;
	};

		// TODO: add prototype for Helper function to identify type account and starting balance
		iAccount* CreateAccount(const char* types, double balance);
	
}
#endif
