#include "Booking.h"
#include <string.h>

Booking::Booking() {
	flight_number = 0;
	seat_number = 0;
	client_name = NULL;
}
Booking::~Booking(){
	flight_number = 0;
	seat_number = 0;
	if (client_name){ 
		delete[] client_name;
		client_name = NULL;
	}
		
}

Booking::Booking(int f_nr, char* c_n, int s_nr) {
	flight_number = f_nr;
	seat_number = s_nr;
	client_name = new char[strlen(c_n) + 1];
	strcpy_s(client_name, strlen(c_n) + 1, c_n);

}
Booking::Booking(const Booking& b) {
	flight_number = b.flight_number;
	seat_number = b.seat_number;
	client_name = new char[strlen(b.client_name) + 1];
	strcpy_s(client_name, strlen(b.client_name) + 1, b.client_name);
}
int Booking::getFlightNumber() {
	return flight_number;
}
char* Booking::getClientName() {
	return client_name;
}
int Booking::getSeatNumber() {
	return seat_number;
}
void Booking::setFlightNumber(int f_nr) {
	flight_number = f_nr;
}
void Booking::setClientName(char* c_n) {
	if (client_name) {
		delete[] client_name;
		client_name = NULL;
	}
	client_name = new char[strlen(c_n) + 1];
	strcpy_s(client_name, strlen(c_n) + 1, c_n);
}
void Booking::setSeatNumber(int s_nr) {
	seat_number = s_nr;
}
Booking& Booking::operator=(const Booking& b) {
	if (this == &b) return *this;
	flight_number = b.flight_number;
	seat_number = b.seat_number;
	if (client_name) {
		delete[] client_name;
		client_name = NULL;
	}
	client_name = new char[strlen(b.client_name) + 1];
	strcpy_s(client_name, strlen(b.client_name) + 1, b.client_name);
	return *this;
}
bool Booking::operator==(const Booking& b) {
	return (strcmp(client_name, b.client_name) == 0) && (flight_number == b.flight_number) && (seat_number==b.seat_number);
}
ostream& operator<<(ostream& os, Booking b) {
	os << b.flight_number << " " << b.client_name << " " << b.seat_number << endl;
	return os;
}
istream& operator>>(istream& is, Booking& b)
{
	cout << "Introduceti nr de zbor: ";
	int flight_number;
	is >> flight_number;
	cout << "Introduceti numele clientului: ";
	char* client_name = new char[10];
	is >> client_name;
	cout << "Introduceti numarul locului: ";
	int seat_number;
	is >> seat_number;
	b.setFlightNumber(flight_number);
	b.setClientName(client_name);
	b.setSeatNumber(seat_number);
	delete[] client_name;
	return is;

}
void load_from_file_elem(istream& f, Booking& b) {
	int flight_number;
	f >> flight_number;
	char* client_name = new char[10];
	f >> client_name;
	int seat_number;
	f >> seat_number;
	b.setFlightNumber(flight_number);
	b.setClientName(client_name);
	b.setSeatNumber(seat_number);
	delete[] client_name;
	return;
}