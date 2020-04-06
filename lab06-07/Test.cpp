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
	Repo<Booking> r;
	Booking b1(13, "iulia", 3);
	Booking b2(20, "alex", 7);
	r.addElem(b1);
	r.addElem(b2);
	list<Booking> all_bookings = r.getAll();
	assert(all_bookings.front() == b1);
	assert(all_bookings.back() == b2);
	int dim = r.getSize();
	assert(dim == 2);
	r.delElem(b1);
	assert(r.getSize() == 1);
	int i0 = r.findElem(b2);
	assert(i0 == 0);
	r.updateElem(b2, 20, "iulian", 7);
	assert(i0 == 0);
	
}

void testService() {
	Service s;
	Booking b1(13, "iulia", 3);
	Booking b2(20, "alex", 7);
	list<int> locuri_disponibile;
	s.addElem(b1, locuri_disponibile);
	s.addElem(b2, locuri_disponibile);
	list<Booking> all_bookings = s.getAll();
	assert(all_bookings.front() == b1);
	assert(all_bookings.back() == b2);
}

void testFile() {
	//Repo<Booking> r;
	RepoFile<Booking> r;
	r.load_from_file("Bookings_test1.txt");
	int dim = r.getSize();
	assert(dim == 4);
}

/*void test_save_file() {
	Repo<Booking> r;
	r.load_from_file("Bookings_test1.txt");
	r.save_to_file("Bookings_write.txt");
}*/