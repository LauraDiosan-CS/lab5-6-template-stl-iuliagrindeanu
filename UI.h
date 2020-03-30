#pragma once
#include "Service.h"

class UI {
private:
	Service ser;
public:
	UI();
	~UI();
	void addElem();
	void showAll();
	void showUI();
};