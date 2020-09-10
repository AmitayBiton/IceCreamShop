#include "pch.h"
#include "Dessert.h"

using namespace sizesAndKinds;

Dessert::Dessert()
{
	kind = waffle;
	size = S;
}

Dessert::Dessert(Dessert& ds) :Product(ds.getName())
{
	this->size = ds.size;
	this->kind = ds.kind;
}

Dessert::Dessert(CString _name, dessertOption _kind, sizeOption _size) :Product(_name)
{
	size = _size;
	kind = _kind;
}

sizeOption Dessert::getSize()
{
	return size;
}

void Dessert::setSize(sizeOption _size)
{
	size = _size;
}

double Dessert::getPrice()
{
	/*
	_____________________________________________________________
	|                   |           |           |               |
	|	Size \ Product	|  Waffle	|	Pancake	|	CheeseCake	|
	|___________________|___________|___________|_______________|
	|                   |           |           |               |
	|		Small		|	10		|	15		|		5		|
	|                   |           |           |               |
	|		Medium		|	15		|	20		|		10		|
	|                   |           |           |               |
	|		Large		|	20		|	25		|		15		|
	|___________________|___________|___________|_______________|

	*/

	switch (kind) {
	case waffle:
		return (10 + (5 * (size - 1)));
		break;
	case pancake:
		return (15 + (5 * (size - 1)));
		break;
	case cheesecake:
		return (5 + (5 * (size - 1)));
		break;
	}
}