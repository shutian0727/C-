#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"


using namespace std;

namespace sict {

	double interest_ = 0.05;
	double tranFees_ = 0.50;
	double monFees_ = 2.00;
	// Allocator function,it returns the address to calling function
	iAccount* CreateAccount(const char* types, double balance)
	{
		
		if (types[0] == 'S') 
		{
			SavingsAccount* Saving = nullptr;
			Saving = new SavingsAccount(balance, interest_);// allocate memory of 
			return Saving;
		}
		else if(types[0] == 'C')
		{
			ChequingAccount* Chequing = nullptr;
			Chequing = new ChequingAccount(balance,tranFees_,monFees_);// allocate memory of 
			return Chequing;
		}
		else {
			return nullptr;
		}
	}
}







