#include "SavingsAccount.h"

using namespace std;

namespace sict {

	// TODO: Implement SavingsAccount constructor here
	//SavingsAccount::SavingsAccount() : Account(balance) {
		//interest_ = 0.0; // safe empty state
	//}

	SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance)
	{ 
		if (interest > 0) {
			interest_ = interest;
		}
		else
		{
			interest_ = 0.0;
		}
	}
	void SavingsAccount::monthEnd() {
		double ir;
		ir = interest_ * balance();
		credit(ir);
	}
	void SavingsAccount::display(std::ostream& ostr) const
	{
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Account type: Saving" << endl;
		ostr << "Balance: $ " << balance() << endl;
		ostr << "Interest Rate (%): " << interest_ * 100 << endl;

	}
}





























