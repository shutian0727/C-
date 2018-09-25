
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount{
		double balance_;//data member that stores the balance
		

     protected:
		 double balance() const;// return current acount balance

public:
	// TODO: default constructor
	Account();
	// TODO: constructor initializes account balance, defaults to 0.0 
	Account(double balance);

	// TODO: credit adds +ve amount to the balance 
	bool credit(double credit_);

	// TODO: debit subtracts a +ve amount from the balance
	bool debit(double debit_);

	// TODO: add prototype for Allocator function
	
	};
	iAccount* CreateAccount(const char* types, double balance);
}
#endif

