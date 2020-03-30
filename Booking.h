#pragma once
#include <iostream>
#include <string>
using namespace std;

class Booking {
private:
	int flight_number;
	char* client_name;
	int seat_number;

public:
	Booking();
	Booking(int, char*, int);
	Booking(const Booking&);
	~Booking();
	int getFlightNumber();
	char* getClientName();
	int getSeatNumber();
	void setFlightNumber(int);
	void setClientName(char*);
	void setSeatNumber(int);
	Booking& operator=(const Booking& b);
	bool operator==(const Booking& b);
	friend ostream& operator<<(ostream& os, Booking b);

};