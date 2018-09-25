// TODO: add file header comments here
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"
// TODO: continue your namespace here
using namespace std;
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger(){
	 destination[0] = '\0';
	passengerName[0] = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *Name, const char *Destination) 
	{
		if (Name != nullptr && Name[0] != '\0' && Destination != '\0' && Destination != nullptr)
		{
			strcpy(passengerName, Name);
			strcpy(destination, Destination);
		}
		else
		{
			
			destination[0] = '\0';
			passengerName[0] = '\0';
		}

		
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const
	{
		bool rv;

		if ( passengerName[0] == '\0' || destination[0] == '\0')
			rv = true;
		else
			rv = false;

		return rv;
	}
	// TODO: implement display query here
	void Passenger::display() const
	{
		if ( passengerName[0] == '\0' || destination[0] == '\0')
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << passengerName << " - " << destination << endl;
		}
			
	}




}