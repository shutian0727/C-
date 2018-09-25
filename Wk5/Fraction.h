// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		int numerator;
		int denominator;
		int gcd() const;//returns the greatest common divisor of the numerator and denominator
		int max() const;//returns the greater of the numerator and denominator
		int min() const;//returns the greater of the numerator and denominator
		void reduce();//reduces the numerator and denominator by dividing each by their greatest common divisor

	public:
		// TODO: declare public member functions
		bool isEmpty() const;
		void display() const;
		Fraction();
		Fraction(int num, int den);

		// TODO: declare the + operator overload
		friend Fraction operator+(const Fraction& rhs,const Fraction& lhs);
	};

}
#endif
