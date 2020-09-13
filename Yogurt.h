#pragma once
#include "Frozen.h"
#include <vector>

using namespace std;
using namespace sizesAndKinds;

class Yogurt : public Frozen
{
private:
	vector<CString>	addons;
public:
	Yogurt();
	Yogurt(Yogurt& yr);
	Yogurt(CString _name, sizeOption _cupSize, vector<CString> _addons);
	vector<CString> getAddons();
	void setAddons(vector<CString> _addons);
	virtual double getPrice();
	void addAddons(CString add);
	void removeAddons(CString add);
	BOOL hasAddon(CString _addon);
};