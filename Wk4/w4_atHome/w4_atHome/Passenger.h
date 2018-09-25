// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
	class Passenger {
		char passengerName[32];
		char destination[32];
		int depYr;
		int depMonth;
		int depDay;
	public:
		Passenger();
		Passenger(const char *Name, const char *Destination);
		Passenger(const char *Name, const char *Destination, int days, int months, int years);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};

}
#endif

