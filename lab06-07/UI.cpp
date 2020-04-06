#include "UI.h"

UI::UI() {};
UI::~UI() {};
void UI::addElem() {
	Booking booking;
	cin >> booking;
	list<int> locuri_disponibile_zbor;
	bool succes = ser.addElem(booking, locuri_disponibile_zbor);
	if (succes)
		cout << "Added!" << endl;
	else
		if (locuri_disponibile_zbor.empty())
			cout << "Nu exista locuri disponibile!" << endl;
		else {
			cout << "Locuri disponibile la zbor: " << endl;
			for (int loc : locuri_disponibile_zbor)
				cout << loc << endl;
		}
		
			
}

void UI::delElem()
{
	Booking booking;
	cout << "Dati rezervarea de sters: " << endl;
	cin >> booking;
	ser.delElem(booking);
}

void UI::updateElem()
{
	Booking booking;
	cout << "Dati rezervarea de zbor: "<<endl;
	cin >> booking;
	cout << "Dati noul nr de zbor: ";
	int new_flight_number;
	cin >> new_flight_number;
	cout << "Modificati numele: ";
	char new_client_name[20];
	cin >> new_client_name;
	cout << "Dati noul numar de loc: ";
	int new_seat_number;
	cin >> new_seat_number;
	ser.updateElem(booking, new_flight_number, new_client_name, new_seat_number);
}

void UI::findElem()
{
	Booking booking;
	cin >> booking;
	int i = ser.findElem(booking);
	cout << "indexul este: " << i << endl;
}

void UI::getSize()
{
	int dim=ser.getSize();
	cout << "Dimensiunea este: " << dim << endl;
}

void UI::showAll() {
	list<Booking> all_elem = ser.getAll();
	for (Booking b : all_elem)
		cout << b;
}

void UI::read_from_file() {
	cout << "Introduceti numele fisierului: ";
	char fileName[100];
	cin >> fileName;
	ser.load_from_file(fileName);
}

/*void UI::save_to_file() {
	cout << "Introduceti numele fisierului: ";
	char fileName[100];
	cin >> fileName;
	ser.save_to_file(fileName);
}*/

void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga element." << endl;
		cout << "	2. Show all. " << endl;
		cout << "	3. Sterge element." << endl;
		cout << "	4. Modifica element." << endl;
		cout << "	5. Cautare element." << endl;
		cout << "	6. Dimensiunea listei." << endl;
		cout << "	7. Citire din fisier." << endl;
		cout << "	8.Rezervarea unui loc." << endl;
		//cout << "	8. Salvare in fisier. " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): ";
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addElem(); break; }
		case 2: {showAll(); break; }
		case 3: {delElem(); break; }
		case 4: {updateElem(); break; }
		case 5: {findElem(); break; }
		case 6: {getSize(); break; }
		case 7: {read_from_file(); break; }
		//case 8: {rezervarea_unui_loc(); break; }
		case 0: {gata = true; cout << "Bye Bye!" << endl; }
		}
	}
}