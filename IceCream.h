#pragma once
#include "Frozen.h"

using namespace sizesAndKinds;

class IceCream : public Frozen
{
private:
	flavorOption flavor;
public:
	IceCream();
	IceCream(IceCream& ic);
	IceCream(CString _name, sizeOption _cupSize, flavorOption _flavor);
	flavorOption getFlavor();
	virtual double getPrice();
};

