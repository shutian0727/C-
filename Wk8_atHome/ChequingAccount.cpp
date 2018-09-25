#include "ChequingAccount.h"
using namespace std;

namespace sict {

ChequingAccount::ChequingAccount():Account()
{
	tranFees_ = 0.0;
}
	ChequingAccount::ChequingAccount(double balance, double tranFees, double monFees) : Account(balance)
	{
		if (tranFees > 0)
			tranFees_ = tranFees;
		else
			tranFees = 0.0;
		if (monFees > 0)
			monFees_ = monFees;
		else
			monFees_ = 0.0;
	}
	bool ChequingAccount::credit(double amt)
	{
		bool result = Account::credit(amt);

			if (result)
			{
				result = Account::debit(tranFees_);
			}
			else
			{
				result = false;
			}
		return result;
	}
	bool ChequingAccount::debit(double amt)
	{
		bool result = Account::debit(amt);

		if (result)
		{
			result = Account::debit(tranFees_);
			
		}
		else
		{
			result = false;
		}
		return result;
	}
	void ChequingAccount::monthEnd()
	{
		double monEnd = balance();
		 monEnd = Account::debit(tranFees_);
		 monEnd = Account::debit(monFees_);
	}
	void ChequingAccount::display(std::ostream& ostr_) const
	{
		ostr_.setf(ios::fixed);
		ostr_.precision(2);
		ostr_ << "Account type: Chequing " << endl;
		ostr_ << "Balance: $ " << balance() << endl;
		ostr_ << "Per Transaction Fee: " << tranFees_ << endl;
		ostr_ << "Monthly Fee: " << monFees_ << endl;

	}
}













