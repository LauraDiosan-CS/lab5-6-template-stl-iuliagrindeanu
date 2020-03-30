#include "Repo.h"
using namespace std;

Repo::Repo(){
}
void Repo::addElem(Booking b)
{
	lista.push_back(b);
}
list<Booking> Repo::getAll() {
	return lista;
}
Repo::~Repo() {

}