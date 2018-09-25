#include "Account.h"
#include "SavingsAccount.h"
#include<cstring>

using namespace std;

namespace sict {
	// Constructor
	Account::Account()
	{
		balance_ = 0.0; // safe empty state
	}

	Account::Account(double balance) 
	{
		if (balance >= 0)
			balance_ = balance;
		else
			balance = 0.0;
	}
	// Credit adds + ve amount to the balance
	bool Account::credit(double credit_)
	{
		bool rv = true;
		if (credit_ >= 0)
			balance_ += credit_;
		else
			rv = false;

		return rv;
	}
	// Debit subtracts a +ve amount from the balance
	bool Account::debit(double debit_)
	{
		bool rv = true;
		if (debit_ >= 0)
			balance_ -= debit_;
		else
			rv = false;

		return rv;
	}
	// protected memeber function to return current balance of account
	double Account::balance() const
	{
		return balance_;
	}
	
	
























}





