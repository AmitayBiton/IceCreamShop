#include "pch.h"
#include "Yogurt.h"


Yogurt::Yogurt() :Frozen()
{
	addons = {};
}
Yogurt::Yogurt(Yogurt& yr) : Frozen(yr.getName(), yr.getCupSize())
{
	this->addons = addons;
}

Yogurt::Yogurt(CString _name, sizeOption _cupSize, vector<CString> _addons) : Frozen(_name, _cupSize)
{
	addons = _addons;
}

vector<CString> Yogurt::getAddons()
{
	return addons;
}

void Yogurt::setAddons(vector<CString> _addons)
{
	addons = _addons;
}

double Yogurt::getPrice() {

	/*
	_________________________________
	|                   |           |
	|		Size		|  Price	|
	|___________________|___________|
	|                   |           |
	|		Small		|	15		|
	|                   |           |
	|		Medium		|	20		|
	|                   |           |
	|		Large		|	25		|
	|___________________|___________|

	*/
	int size = getCupSize();

	return (15 + (size - 1) * 5);
}

void Yogurt::addAddons(CString add)
{
	addons.push_back(add);
}

void Yogurt::removeAddons(CString add)
{
	addons.erase(remove(addons.begin(), addons.end(), add), addons.end());
}

BOOL Yogurt::hasAddon(CString _addon)
{
	if (find(addons.begin(), addons.end(), _addon) != addons.end()) {
		return true;
	}
	return false;
}
