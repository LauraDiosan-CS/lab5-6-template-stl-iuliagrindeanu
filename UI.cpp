#include "UI.h"

UI::UI() {};
UI::~UI() {};
void UI::addElem() {
	int flight_number;
	char client_name[100];
	int seat_number;
	cout << "Introduceti nr de zbor: ";
	cin >> flight_number;
	cout << endl;
	cout << "Introduceti numele: ";
	cin >> client_name;
	cout << endl;
	cout << "Introduceti nr locului: ";
	cin >> seat_number;
	cout << endl;
	Booking newBooking(flight_number, client_name, seat_number);
	ser.addElem(newBooking);
	cout << "Added!" << endl;
}

void UI::showAll() {
	list<Booking> all_elem = ser.getAll();
	for (Booking b : all_elem)
		cout << b << endl;
}
void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga element." << endl;
		cout << "	2. Show all. " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addElem(); break; }
		case 2: {showAll(); break; }
		case 0: {gata = true; cout << "Bye Bye!" << endl; }
		}
	}
}