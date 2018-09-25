#include <iostream>
#include <fstream>
#include <iomanip>
#include "Data.h"


namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//
	
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double val = population[n-1] - population[0];
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "Population change from 2000 to 2004 is " << val /1000000 << " million" << std::endl;
		




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		int vag = violentCrime[n - 1] - violentCrime[0];
		if (vag > 0)
			std::cout << "Violent Crime trend is up" << std::endl;
		else
			std::cout << "Violent Crime trend is down" << std::endl;


		// Q3 print the GTA number accurate to 0 decimal places
		double vak = average(grandTheftAuto, n);
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << "There are " << vak/ 1000000 << " million Grand Theft incidents on average a year" << std::endl;



		// Q4. Print the min and max violentCrime rates 
		int a = min(violentCrimeRate, n);
		std::cout << "The minimum Violent Crime rate was " << a << std::endl;
		
		int b = max(violentCrimeRate, n);
		std::cout << "The maximum Violent Crime rate was " << b << std::endl;
	}
}