#pragma once
#include "Repo.h"
class Service {
private:
	Repo repo;
public:
	Service();
	Service(const Repo& r);
	~Service();
	void addElem(Booking& b);
	list<Booking> getAll();
};