#pragma once
#include "RepoFile.h"
class Service {
private:
	RepoFile<Booking> repo;
	const int X = 100;
public:
	Service();
	Service(const RepoFile<Booking>& r);
	~Service();
	bool addElem(Booking& b, list<int> &l_d);
	list<Booking> getAll();
	int getSize();
	int delElem(Booking& b);
	void updateElem(Booking& b, int f_nr, char* c_n, int s_nr);
	int findElem(Booking& b);
	void load_from_file(const char* fileName);
	bool locul_este_disponibil(Booking& b);
	list<int> locuri_disponibile(int flight_number);
	//void save_to_file(const char* fileName);
	//void save_to_file(const char* fileName);
};