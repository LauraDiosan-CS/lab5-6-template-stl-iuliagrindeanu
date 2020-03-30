#include "Test.h"
#include <assert.h>
using namespace std;

void test() {
	list<Booking> lista;
	lista.clear();
	Booking b1(13, "iulia", 3);
	Booking b2(20, "alex", 7);
	lista.push_back(b1);
	lista.push_back(b2);
	assert(lista.size() == 2);
	assert(lista.front() == b1);
	assert(lista.back() == b2);

}
void testRepo() {
	Repo r;
	Booking b1(13, "iulia", 3);
	Booking b2(20, "alex", 7);
	r.addElem(b1);
	r.addElem(b2);
	list<Booking> all_bookings = r.getAll();
	assert(all_bookings.front() == b1);
	assert(all_bookings.back() == b2);
}

void testService() {
	Service s;
	Booking b1(13, "iulia", 3);
	Booking b2(20, "alex", 7);
	s.addElem(b1);
	s.addElem(b2);
	list<Booking> all_bookings = s.getAll();
	assert(all_bookings.front() == b1);
	assert(all_bookings.back() == b2);
}