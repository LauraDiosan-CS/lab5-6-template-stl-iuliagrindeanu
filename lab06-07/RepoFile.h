#pragma once
#include "Repo.h"
template <typename T>
class RepoFile :
	public Repo<Booking>
{
public:
	RepoFile();
	~RepoFile();
	void load_from_file(const char* fileName);

};

template <typename T> 
RepoFile<T>::RepoFile() {

}

template <typename T>
RepoFile<T>::~RepoFile() {

}

template <typename T>
void RepoFile<T>::load_from_file(const char* fileName) {
	lista.clear();
	ifstream f(fileName);
	if (f.is_open()) {
		while (!f.eof()) {
			T elem;
			load_from_file_elem(f, elem);
			lista.push_back(elem);
		}
		f.close();
	}
}