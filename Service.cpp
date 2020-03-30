#include "Service.h"

Service::Service()
{
}

Service::Service(const Repo& r)
{
	repo = r;
}
void Service::addElem(Booking& b)
{
	repo.addElem(b);
}
list<Booking> Service::getAll()
{
	return repo.getAll();
}
Service::~Service() {

}