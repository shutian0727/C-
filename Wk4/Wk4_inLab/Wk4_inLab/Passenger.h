// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// SICT_PASSENGER_H
// TODO: declare your namespace here
     namespace sict {
	    class Passenger {
		char passengerName[32];
		char destination[32];
	
    public:
		int size;
	     Passenger();
	     Passenger(const char *Name, const char *Destination);
	     bool isEmpty() const;
	     void display() const;
};

}
#endif