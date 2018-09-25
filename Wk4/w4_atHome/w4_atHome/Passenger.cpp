// TODO: add file header comments here
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
// TODO: continue your namespace here
using namespace std;
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		destination[0] = '\0';
		passengerName[0] = '\0';
		int depYr = 0;
		int depMonth = 0;
		int depDay = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *Name, const char *Destination)
	{
		if (Name != nullptr && Name[0] != '\0' && Destination[0] != '\0' && Destination != nullptr)
		{
			strcpy(passengerName, Name);
			strcpy(destination, Destination);
			depYr = 2017;
			depMonth = 7;
			depDay = 1;
		}
		else
		{
			destination[0] = '\0';
			passengerName[0] = '\0';
			depYr = 0;
			depMonth = 0;
			depDay = 0;
		}
	}
	Passenger::Passenger(const char *Name, const char *Destination, int years, int months, int days)
	{

		bool valid = false;

		if (Name != nullptr && Name[0] != '\0' && Destination[0] != '\0' && Destination != nullptr)
			valid = true;
		else
			valid = false;

		if ((years >= 2017 && years <= 2020) && valid)
			valid = true;
		else
			valid = false;

		if (months >= 1 && months <= 12 && valid)
			valid = true;
		else
			valid = false;

		if (days >= 1 && days <= 31 && valid)
			valid = true;
		else
			valid = false;

		if (valid) {
			strcpy(passengerName, Name);
			strcpy(destination, Destination);
			depYr = years;
			depMonth = months;
			depDay = days;
		}
		else {
			strcpy(passengerName, " ");
			strcpy(destination, " ");
			depYr = 0;
			depMonth = 0;
			depDay = 0;
		}
	}


	const char* Passenger::name() const
	{
		return passengerName;
	}

	bool Passenger::canTravelWith(const Passenger& r) const
	{
		bool rv;
		if (!strcmp(destination, r.destination) && depYr == r.depYr && depMonth == r.depMonth && depDay == r.depDay)
			rv = true;
		else
			rv = false;

		return rv;

	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		bool rv;

		if (passengerName[0] == '\0' || destination[0] == '\0')
			rv = true;
		else
			rv = false;

		return rv;
	}
	// TODO: implement display query here
	void Passenger::display() const
	{

		cout << passengerName << " - " << destination << "on";
		cout.fill('0');
		cout.width(4);
		cout << depYr << "/";
		cout.width(2);
		cout << depMonth << "/";
		cout.width(2);
		cout << depDay << endl;
		cout.fill(' ');


	}




}