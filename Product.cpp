#include "pch.h"
#include "Product.h"

Product::Product(CString _name)
{
	name = _name;
	id = rand() % 1000000;
}

Product::Product()
{
	name = "";
	id = rand() % 1000000;
}

void Product::setName(CString _name)
{
	name = _name;
}

int Product::getId()
{
	return id;
}

CString Product::getName()
{
	return name;
}