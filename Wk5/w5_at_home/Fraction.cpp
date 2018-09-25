// TODO: insert header files
#include<iostream>
#include"Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int den) {

		if (num >= 0 && den > 0)
		{
			numerator = num;
			denominator = den;
			reduce();// call reduce function to simplify the numerator and denominator
		}
		else
		{
			numerator = 0;
			denominator = 0;
		}

	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		int max_num;
		if (numerator >= denominator)
		{
			max_num = numerator;
		}
		else
		{
			max_num = denominator;
		}

		return max_num;
	}


	// TODO: implement the min query
	int Fraction::min() const
	{
		int min_num;
		if (numerator <= denominator)
		{
			min_num = numerator;
		}
		else
		{
			min_num = denominator;
		}

		return min_num;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier

	void Fraction::reduce()
	{
		int modifier = gcd();
		numerator /= modifier;
		denominator /= modifier;
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		bool valid;
		if (numerator == 0 && denominator == 0)
			return valid = true;
		else
			return valid = false;

		return valid;
	}

	// TODO: implement the display query

	void Fraction::display() const
	{
		bool valid = numerator >= 0 && denominator > 0;
		if (valid && denominator != 1)
			cout << numerator << "/" << denominator;
		else if (valid && denominator == 1)
			cout << numerator;
		else if (isEmpty())
			cout << "no fraction stored";
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction&  rhs)
	{
		Fraction fraction_sum; // create a current object

		if (rhs.numerator >= 0 && rhs.denominator > 0 && numerator >= 0 && denominator > 0)
		{
			fraction_sum.numerator = numerator * rhs.denominator + denominator * rhs.numerator;
			fraction_sum.denominator = denominator * rhs.denominator;
			fraction_sum.reduce();
		}
		else if (isEmpty() || rhs.isEmpty()) {
			fraction_sum = Fraction();
		}

		return fraction_sum;
	}

	Fraction Fraction::operator*(const Fraction& rhs) {
		Fraction fraction_mul;
		bool valid = rhs.numerator >= 0 && rhs.denominator > 0 && numerator >= 0 && denominator > 0;

		if (valid) {
			fraction_mul.numerator = numerator * rhs.numerator;
			fraction_mul.denominator = denominator * rhs.denominator;
			fraction_mul.reduce();
		}
		else if (isEmpty() || rhs.isEmpty()) {
			fraction_mul = Fraction();
		}

		return fraction_mul;
	}
	bool operator==(const Fraction& rhs, const Fraction& lhs)
	{
		bool rv = false;
		bool valid = rhs.numerator >= 0 && rhs.denominator > 0 && lhs.numerator >= 0 && lhs.denominator > 0;
		bool isEqual = lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;

		if (valid && isEqual)
			rv = true;
		else if (lhs.isEmpty() || rhs.isEmpty())
			rv = false;
		else
			rv = false;

		return rv;

	}
	bool operator!=(const Fraction& rhs, const Fraction& lhs) {
		bool rv;
		bool valid = rhs.numerator >= 0 && rhs.denominator > 0 && lhs.numerator >= 0 && lhs.denominator > 0;
		bool notEqual = lhs.numerator != rhs.numerator && lhs.denominator != rhs.denominator;

		if (valid && notEqual)
			rv = true;
		else if (lhs.isEmpty() || rhs.isEmpty())
			rv = false;
		else
			rv = false;

		return rv;
	}

	Fraction& Fraction::operator+=(const Fraction& rhs) {
		bool valid = rhs.numerator >= 0 && rhs.denominator > 0 && numerator >= 0 && denominator > 0;


		if (valid) {
			*this = *this + rhs;
		}
		else if (isEmpty() || rhs.isEmpty()) {
			*this = Fraction();
		}

		return *this;
	}





}






























