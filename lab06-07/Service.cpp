#include "Service.h"
#include <set>
Service::Service()
{
}

Service::Service(const RepoFile<Booking>& r)
{
	repo = r;
}
bool Service::addElem(Booking& b, list<int> &locuri_disponibile_zbor)
{
	if (locul_este_disponibil(b)) {
		repo.addElem(b);
		return true;
	}
	else
	{
		locuri_disponibile_zbor = locuri_disponibile(b.getFlightNumber());
		return false;
	}
}
list<Booking> Service::getAll()
{
	return repo.getAll();
}
int Service::getSize()
{
	return repo.getSize();
}
int Service::delElem(Booking& b)
{
	return repo.delElem(b);
}
void Service::updateElem(Booking& b, int f_nr, char* c_n, int s_nr)
{
	repo.updateElem(b, f_nr, c_n, s_nr);
}
int Service::findElem(Booking& b)
{
	return repo.findElem(b);
}


Service::~Service() {

}
void Service::load_from_file(const char* fileName) {
	repo.load_from_file(fileName);
}
/*void Service::save_to_file(const char* fileName){
	repo.save_to_file(fileName);
}*/
list<int> Service::locuri_disponibile(int flight_number) {
	list<Booking> lista = repo.getAll();
	set<int> locuri_ocupate_zbor;
	for (Booking bb : lista) {
		int fl_nr = bb.getFlightNumber();
		if (fl_nr == flight_number) {
			locuri_ocupate_zbor.insert(bb.getSeatNumber());
		}
	}
	list<int> lista_locuri_libere;
	for (int loc = 1; loc <= X; loc++) {
		if (locuri_ocupate_zbor.find(loc) == locuri_ocupate_zbor.end())
			lista_locuri_libere.push_back(loc);
	}
	return lista_locuri_libere;
}

bool Service::locul_este_disponibil(Booking& b) {
	list<Booking> lista = repo.getAll();
	int loc = b.getSeatNumber();
	int flight = b.getFlightNumber();
	for (Booking bb : lista)
	{
		if (bb.getFlightNumber() == flight && bb.getSeatNumber() == loc) {
			return false;
		}
	}
	return true;
}


