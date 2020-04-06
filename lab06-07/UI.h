#pragma once
#include "Service.h"

class UI {
private:
	Service ser;
public:
	UI();
	~UI();
	void addElem();
	void delElem();
	void updateElem();
	void findElem();
	void getSize();
	void showAll();
	void showUI();
	void read_from_file();
	//void save_to_file();
};