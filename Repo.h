#pragma once
#include "Booking.h"
#include <list>
using namespace std;
class Repo {
private:
	list<Booking> lista;
public:
	Repo();
	~Repo();
	void addElem(Booking b);
	list<Booking> getAll();
};