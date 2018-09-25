#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"
namespace sict {
	
	class ChequingAccount : public Account {
		double tranFees_;
		double monFees_;
	public:
		// TODO: constructor initializes balance and transaction fee
		ChequingAccount();
		ChequingAccount(double balance, double tranFees, double monFees);
		// TODO: Write a function prototype to override credit function
		bool credit(double amt);
		// TODO: Write a function prototype to override debit function
		bool debit(double amt);
		// TODO: Write a function prototype to debit monthly fees from balance
		void monthEnd();
		// TODO: Write a function prototype to  override display function
		void display(std::ostream& ostr) const;
};
}
#endif



























