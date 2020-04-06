#pragma once
#include "Booking.h"
#include <list>
#include <fstream>
using namespace std;
template <class T>
class Repo {
protected:
	list<T> lista;
public:
	Repo();
	~Repo();
	void addElem(const T b);
	list<T>& getAll();
	int getSize();
	int delElem(const T b);
	void updateElem(const T b, int f_nr, char* c_n, int s_nr);
	int findElem(const T b);
	//void load_from_file(const char* fileName);
	void save_to_file(const char* fileName);
};

template <class T> Repo<T>::Repo() {};

template <class T> Repo<T>::~Repo() {};

template <class T> void Repo<T>::addElem(const T b) {

	lista.push_back(b);
}

template <class T> list<T>& Repo<T>::getAll() {

	return lista;
}

template <class T> int Repo<T>::getSize() {

	return (int)lista.size();
}

template <class T> int Repo<T>::delElem(const T b) {

	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), b);
	if (it != lista.end()) {
		lista.erase(it);
		return 0;
	}
	return -1;
}

template <class T> void Repo<T>::updateElem(const T b, int f_nr, char* c_n, int s_nr)
{
	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), b);
	if (it != lista.end()) {
		(*it).setFlightNumber(f_nr);
		(*it).setClientName(c_n);
		(*it).setSeatNumber(s_nr);
	}
}

template <class T> int Repo<T>::findElem(const T b) 
{
	list<T>::iterator it;
	it = find(lista.begin(), lista.end(), b);
	if (it != lista.end()) {
		return distance(lista.begin(), it);
	}
	return -1;
}

/*template <class T> void Repo<T>::load_from_file(const char* fileName) {
	lista.clear();
	//fis = fileName;
	ifstream f(fileName);
	if (f.is_open()) {
		while (!f.eof()) {
			T elem;
			load_from_file_elem(f, elem);
			//f >> elem;
			lista.push_back(elem);
		}
		f.close();
	}
	//char* nume = new char[10];
	//int varsta;
	
}*/
template <class T> void Repo<T>::save_to_file(const char* fileName) {
	ofstream f(fileName);
	list<T>::iterator it;
	for (it = lista.begin(); it != lista.end(); it++) {
		f << *it;
	}
	f.close();
}
