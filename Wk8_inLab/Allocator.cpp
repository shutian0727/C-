#include "iAccount.h"
#include "SavingsAccount.h"


using namespace std;

namespace sict {

	double interest_ = 0.05;
	// Allocator function,it returns the address to calling function
	iAccount* CreateAccount(const char* types, double balance)
	{
		if (types[0] == 'S') {
			iAccount* Saving = nullptr;
			Saving = new SavingsAccount(balance, interest_);// allocate memory of 
			return Saving;
		}

		else
		{
			return nullptr;
		}
	}
}







