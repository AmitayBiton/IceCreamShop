#include "pch.h"
#include "IceCream.h"


IceCream::IceCream() :Frozen()
{
	flavor = chocolate;
}

IceCream::IceCream(IceCream& ic) : Frozen(ic.getName(), ic.getCupSize())
{
	this->flavor = ic.flavor;
}

IceCream::IceCream(CString _name, sizeOption _cupSize, flavorOption _flavor) : Frozen(_name, _cupSize)
{
	flavor = _flavor;
}

flavorOption IceCream::getFlavor()
{
	return flavor;
}

double IceCream::getPrice()
{

	/*
	_________________________________
	|                   |           |
	|		Size		|  Price	|
	|___________________|___________|
	|                   |           |
	|		Small		|	10		|
	|                   |           |
	|		Medium		|	15		|
	|                   |           |
	|		Large		|	20		|
	|___________________|___________|

	*/
	sizeOption size = getCupSize();

	switch (size) {
	case S:
		return 10.0;
		break;
	case M:
		return 15.0;
		break;
	case L:
		return 20.0;
		break;
	}
}

void IceCream::setFlavor(flavorOption _flavor)
{
	flavor = _flavor;
}
